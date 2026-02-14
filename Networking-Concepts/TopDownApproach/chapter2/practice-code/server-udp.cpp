/**
 * Here we implement the server which will be accepting request via listening to a port,
 * which will receive request from the client.
 *
 * Protocol used will be UDP (User Datagram Protocol)
 *
 * This implementation uses POSIX sockets (standard on Linux/Unix systems)
 * No external libraries needed - uses standard C++17 and system socket APIs
 */

// Standard C++ headers
#include <iostream>  // For std::cout, std::cerr - console I/O
#include <string>    // For std::string - string manipulation
#include <cstring>   // For C-style string operations (if needed)
#include <algorithm> // For std::transform - used in uppercase conversion
#include <cctype>    // For std::toupper - character case conversion
#include <array>     // For std::array - fixed-size buffer container

// POSIX socket headers (standard on Linux/Unix systems)
#include <sys/socket.h> // For socket(), bind(), sendto(), recvfrom() - core socket operations
#include <netinet/in.h> // For sockaddr_in, INADDR_ANY - Internet address structures
#include <arpa/inet.h>  // For inet_ntop(), htons(), ntohs() - IP address conversion functions
#include <unistd.h>     // For close() - closing file descriptors/sockets

constexpr int BUFFER_SIZE = 1024;
constexpr int SERVER_PORT = 8080;

/**
 * Converts a string to uppercase
 * @param str: The input string to convert
 * @return: Uppercase version of the input string
 */
std::string toUpperCase(const std::string &str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c)
                   { return std::toupper(c); });
    return result;
}

int main()
{
    // Step 1: Create a UDP socket
    // AF_INET = IPv4, SOCK_DGRAM = UDP protocol
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket < 0)
    {
        std::cerr << "Error: Failed to create socket\n";
        return 1;
    }
    std::cout << "✓ UDP Socket created successfully\n";

    // Step 2: Configure server address structure
    sockaddr_in serverAddr{};                 // Zero-initialize the structure
    serverAddr.sin_family = AF_INET;          // IPv4
    serverAddr.sin_port = htons(SERVER_PORT); // Convert port to network byte order
    serverAddr.sin_addr.s_addr = INADDR_ANY;  // Accept connections from any IP address

    // Step 3: Bind the socket to the specified port
    // This associates the socket with a specific port number
    if (bind(serverSocket, reinterpret_cast<sockaddr *>(&serverAddr),
             sizeof(serverAddr)) < 0)
    {
        std::cerr << "Error: Failed to bind socket to port " << SERVER_PORT << "\n";
        close(serverSocket);
        return 1;
    }
    std::cout << "✓ Socket bound to port " << SERVER_PORT << "\n";
    std::cout << "Server is listening for UDP messages...\n\n";

    // Step 4: Main server loop - continuously listen for incoming messages
    while (true)
    {
        // Buffer to store incoming data
        std::array<char, BUFFER_SIZE> buffer{};

        // Structure to store client address information
        sockaddr_in clientAddr{};
        socklen_t clientAddrLen = sizeof(clientAddr);

        // Step 5: Receive data from client
        // recvfrom() blocks until data is received
        // It returns the number of bytes received and fills clientAddr with sender info
        ssize_t bytesReceived = recvfrom(
            serverSocket,                              // Socket descriptor
            buffer.data(),                             // Buffer to store received data
            buffer.size() - 1,                         // Maximum bytes to receive
            0,                                         // Flags (0 = default behavior)
            reinterpret_cast<sockaddr *>(&clientAddr), // Client address (output)
            &clientAddrLen                             // Size of client address structure
        );

        if (bytesReceived < 0)
        {
            std::cerr << "Error: Failed to receive data\n";
            continue; // Continue listening for next message
        }

        // Null-terminate the received string
        buffer[bytesReceived] = '\0';

        // Convert client IP address to readable format
        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddr.sin_addr), clientIP, INET_ADDRSTRLEN);
        int clientPort = ntohs(clientAddr.sin_port);

        // Log the received message
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        std::cout << "Received from " << clientIP << ":" << clientPort << "\n";
        std::cout << "Original message: \"" << buffer.data() << "\"\n";
        std::cout << "Bytes received: " << bytesReceived << "\n";

        // Step 6: Convert the message to uppercase
        std::string receivedMessage(buffer.data());
        std::string upperCaseMessage = toUpperCase(receivedMessage);
        std::cout << "Converted message: \"" << upperCaseMessage << "\"\n";

        // Step 7: Send the uppercase message back to the client
        // UDP doesn't maintain a connection, so we send to the address we received from
        ssize_t bytesSent = sendto(
            serverSocket,                              // Socket descriptor
            upperCaseMessage.c_str(),                  // Data to send
            upperCaseMessage.length(),                 // Number of bytes to send
            0,                                         // Flags (0 = default behavior)
            reinterpret_cast<sockaddr *>(&clientAddr), // Destination address (client)
            clientAddrLen                              // Size of destination address
        );

        if (bytesSent < 0)
        {
            std::cerr << "Error: Failed to send response\n";
        }
        else
        {
            std::cout << "Response sent: " << bytesSent << " bytes\n";
        }
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
    }

    // Step 8: Clean up (this code won't be reached due to infinite loop)
    // In production, you'd want signal handling to gracefully shut down
    close(serverSocket);
    return 0;
}
