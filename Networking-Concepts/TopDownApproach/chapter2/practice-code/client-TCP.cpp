/**
 * Here we implement the client which will be sending request to a port that server is listenening to,
 *
 * Protocol used will be TCP (Transmission Control Protocol)
 *
 * This implementation uses POSIX sockets (standard on Linux/Unix systems)
 * No external libraries needed - uses standard C++17 and system socket APIs
 *
 * SOCKET CREATION: socket(AF_INET, SOCK_STREAM, 0)
 * ================================================
 *
 * Parameter 1: AF_INET (Address Family)
 * - AF_INET = IPv4 Internet protocols
 * - Specifies that we're using IPv4 addressing (e.g., 192.168.1.1)
 * - Alternative: AF_INET6 for IPv6
 *
 * Parameter 2: SOCK_STREAM (Socket Type)
 * - SOCK_STREAM = Connection-oriented, reliable, two-way byte stream
 * - This is the socket type for TCP protocol
 * - Guarantees: ordered delivery, no data loss, no duplicates
 * - Data is read as a continuous stream (like reading from a file)
 * - Alternative: SOCK_DGRAM for UDP (connectionless, unreliable datagrams)
 *
 * Parameter 3: 0 (Protocol)
 * - 0 = Automatically select the appropriate protocol for the given socket type
 * - For SOCK_STREAM with AF_INET, this automatically selects TCP (IPPROTO_TCP)
 * - Could explicitly specify IPPROTO_TCP, but 0 is more portable
 *
 * Return Value:
 * - On success: Returns a non-negative integer (file descriptor) representing the socket
 * - On failure: Returns -1, and errno is set to indicate the error
 *
 * The socket file descriptor is used in subsequent calls like connect(), send(), recv(), close()
 */

#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

constexpr int BUFFER_SIZE = 1024;

int main()
{
    // Server configuration
    const char *SERVER_IP = "127.0.0.1"; // localhost
    const int SERVER_PORT = 8080;

    // Step 1: Create socket
    // AF_INET: IPv4, SOCK_STREAM: TCP protocol
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    std::cout << "Socket created successfully\n";

    // Step 2: Configure server address structure
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT); // Convert port to network byte order

    // Convert IP address from text to binary form
    // Why conversion is needed:
    // - Humans use dotted-decimal notation: "127.0.0.1" (string representation)
    // - Network stack uses 32-bit binary format: 0x7F000001 (4 bytes in network byte order)
    // - inet_pton() = "Internet Presentation to Network" - converts human-readable to network format
    // - This ensures the IP address is in the correct binary format for the socket API
    // - Return values: 1 = success, 0 = invalid format, -1 = address family not supported
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0)
    {
        std::cerr << "Invalid address or address not supported\n";
        close(client_socket);
        return 1;
    }

    // Step 3: Connect to server
    std::cout << "Attempting to connect to " << SERVER_IP << ":" << SERVER_PORT << "...\n";

    if (connect(client_socket, (sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        std::cerr << "Connection failed. Make sure server is running.\n";
        close(client_socket);
        return 1;
    }

    std::cout << "Successfully connected to server!\n";

    // Step 4: Send message to server
    std::string message;
    std::cout << "\nEnter message to send to server: ";
    std::getline(std::cin, message);

    ssize_t bytes_sent = send(client_socket, message.c_str(), message.length(), 0);
    if (bytes_sent < 0)
    {
        std::cerr << "Failed to send message\n";
        close(client_socket);
        return 1;
    }

    std::cout << "Sent " << bytes_sent << " bytes to server\n";

    // Step 5: Receive response from server
    char buffer[BUFFER_SIZE] = {0};
    ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);

    if (bytes_received > 0)
    {
        buffer[bytes_received] = '\0'; // Null-terminate the received data
        std::cout << "Received " << bytes_received << " bytes from server\n";
        std::cout << "Server response: " << buffer << "\n";
    }
    else if (bytes_received == 0)
    {
        std::cout << "Server closed the connection\n";
    }
    else
    {
        std::cerr << "Failed to receive data from server\n";
    }

    // Step 6: Close the socket
    close(client_socket);
    std::cout << "\nConnection closed\n";

    return 0;
}