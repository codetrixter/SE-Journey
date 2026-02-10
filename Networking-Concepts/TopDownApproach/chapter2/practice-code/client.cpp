/**
 * Here we implement the client which will be sending request to a port that server is listenening to,
 *
 * Protocol used will be UDP (User Datagram Protocol)
 *
 * This implementation uses POSIX sockets (standard on Linux/Unix systems)
 * No external libraries needed - uses standard C++17 and system socket APIs
 */

// Standard C++ headers
#include <iostream>   // For std::cout, std::cerr, std::cin - console I/O
#include <string>     // For std::string - string manipulation
#include <cstring>    // For memset() - memory operations
#include <array>      // For std::array - fixed-size buffer container

// POSIX socket headers (standard on Linux/Unix systems)
#include <sys/socket.h>  // For socket(), sendto(), recvfrom() - core socket operations
#include <netinet/in.h>  // For sockaddr_in, INADDR_ANY - Internet address structures
#include <arpa/inet.h>   // For inet_pton(), htons(), ntohs() - IP address conversion functions
#include <unistd.h>      // For close() - closing file descriptors/sockets

constexpr int BUFFER_SIZE = 1024;
constexpr int SERVER_PORT = 8080;
constexpr const char* SERVER_IP = "127.0.0.1";  // Localhost - change this to connect to remote server

int main()
{
    // Step 1: Create a UDP socket
    // AF_INET = IPv4, SOCK_DGRAM = UDP protocol
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket < 0)
    {
        std::cerr << "Error: Failed to create socket\n";
        return 1;
    }
    std::cout << "✓ UDP Socket created successfully\n";

    // Step 2: Configure server address structure
    // This specifies where we want to send our messages
    sockaddr_in serverAddr{};                 // Zero-initialize the structure
    serverAddr.sin_family = AF_INET;          // IPv4
    serverAddr.sin_port = htons(SERVER_PORT); // Convert port to network byte order

    // Convert IP address from string to binary form
    if (inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr) <= 0)
    {
        std::cerr << "Error: Invalid server IP address\n";
        close(clientSocket);
        return 1;
    }

    std::cout << "✓ Configured to send to server " << SERVER_IP << ":" << SERVER_PORT << "\n\n";

    // Step 3: Main client loop - send messages to server
    while (true)
    {
        // Get message from user
        std::cout << "Enter message to send (or 'quit' to exit): ";
        std::string message;
        std::getline(std::cin, message);

        // Check if user wants to quit
        if (message == "quit" || message == "exit")
        {
            std::cout << "Exiting client...\n";
            break;
        }

        // Skip empty messages
        if (message.empty())
        {
            continue;
        }

        std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        std::cout << "Sending message: \"" << message << "\"\n";

        // Step 4: Send message to server
        // UDP is connectionless, so we directly send to the server address
        ssize_t bytesSent = sendto(
            clientSocket,                              // Socket descriptor
            message.c_str(),                           // Data to send
            message.length(),                          // Number of bytes to send
            0,                                         // Flags (0 = default behavior)
            reinterpret_cast<sockaddr*>(&serverAddr), // Destination address (server)
            sizeof(serverAddr)                         // Size of destination address structure
        );

        if (bytesSent < 0)
        {
            std::cerr << "Error: Failed to send message\n";
            continue;
        }

        std::cout << "Sent: " << bytesSent << " bytes\n";

        // Step 5: Prepare to receive response from server
        std::array<char, BUFFER_SIZE> buffer{};
        sockaddr_in fromAddr{};
        socklen_t fromAddrLen = sizeof(fromAddr);

        // Step 6: Receive response from server
        // recvfrom() blocks until data is received or timeout occurs
        ssize_t bytesReceived = recvfrom(
            clientSocket,                            // Socket descriptor
            buffer.data(),                           // Buffer to store received data
            buffer.size() - 1,                       // Maximum bytes to receive
            0,                                       // Flags (0 = default behavior)
            reinterpret_cast<sockaddr*>(&fromAddr), // Source address (output)
            &fromAddrLen                             // Size of source address structure
        );

        if (bytesReceived < 0)
        {
            std::cerr << "Error: Failed to receive response\n";
            continue;
        }

        // Null-terminate the received string
        buffer[bytesReceived] = '\0';

        // Convert server IP address to readable format for verification
        char serverIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(fromAddr.sin_addr), serverIP, INET_ADDRSTRLEN);
        int serverPort = ntohs(fromAddr.sin_port);

        // Display the response
        std::cout << "Received response from " << serverIP << ":" << serverPort << "\n";
        std::cout << "Server response: \"" << buffer.data() << "\"\n";
        std::cout << "Bytes received: " << bytesReceived << "\n";
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
    }

    // Step 7: Clean up - close the socket
    close(clientSocket);
    std::cout << "Socket closed. Goodbye!\n";
    
    return 0;
}