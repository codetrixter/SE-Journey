/**
 * Here we implement the server which will be accepting request via listening to a port,
 * which will receive request from the client.
 *
 * Protocol used will be TCP (Transmission Control Protocol)
 *
 * This implementation uses POSIX sockets (standard on Linux/Unix systems)
 * No external libraries needed - uses standard C++17 and system socket APIs
 *
 * SERVER SOCKET WORKFLOW:
 * ======================
 * 1. socket()  - Create a socket endpoint
 * 2. bind()    - Bind socket to an IP address and port
 * 3. listen()  - Mark socket as passive, ready to accept connections
 * 4. accept()  - Block and wait for incoming client connections
 * 5. recv()    - Receive data from connected client
 * 6. send()    - Send data back to client
 * 7. close()   - Close client and server sockets
 */

#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

constexpr int BUFFER_SIZE = 1024;
constexpr int BACKLOG = 5; // Maximum number of pending connections in the queue

int main()
{
    // Server configuration
    const int SERVER_PORT = 8080;
    const char *SERVER_IP = "127.0.0.1"; // Listen on all available network interfaces

    // Step 1: Create socket
    // AF_INET: IPv4, SOCK_STREAM: TCP protocol
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    std::cout << "Socket created successfully\n";

    // Step 2: Set socket options (optional but recommended)
    // SO_REUSEADDR allows reusing the address immediately after server restart
    // Prevents "Address already in use" error
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        std::cerr << "Failed to set socket options\n";
        close(server_socket);
        return 1;
    }

    // Step 3: Configure server address structure
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT); // Convert port to network byte order

    // Convert IP address from text to binary form
    // 0.0.0.0 means listen on all available network interfaces
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0)
    {
        std::cerr << "Invalid address or address not supported\n";
        close(server_socket);
        return 1;
    }

    // Step 4: Bind socket to the address and port
    // This associates the socket with a specific IP address and port number
    if (bind(server_socket, (sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        std::cerr << "Bind failed. Port may already be in use.\n";
        close(server_socket);
        return 1;
    }

    std::cout << "Socket bound to port " << SERVER_PORT << "\n";

    // Step 5: Listen for incoming connections
    // BACKLOG defines max number of pending connections in the queue
    if (listen(server_socket, BACKLOG) < 0)
    {
        std::cerr << "Listen failed\n";
        close(server_socket);
        return 1;
    }

    std::cout << "Server listening on port " << SERVER_PORT << "...\n";
    std::cout << "Waiting for client connections...\n\n";

    // Step 6: Accept incoming client connection
    sockaddr_in client_addr{};
    socklen_t client_addr_len = sizeof(client_addr);

    // accept() blocks until a client connects
    // Returns a new socket file descriptor for communicating with the client
    int client_socket = accept(server_socket, (sockaddr *)&client_addr, &client_addr_len);
    if (client_socket < 0)
    {
        std::cerr << "Accept failed\n";
        close(server_socket);
        return 1;
    }

    // Get client's IP address and port for logging
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
    int client_port = ntohs(client_addr.sin_port);

    std::cout << "Client connected from " << client_ip << ":" << client_port << "\n";

    // Step 7: Receive data from client
    char buffer[BUFFER_SIZE] = {0};
    ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);

    if (bytes_received > 0)
    {
        buffer[bytes_received] = '\0'; // Null-terminate the received data
        std::cout << "Received " << bytes_received << " bytes from client\n";
        std::cout << "Client message: " << buffer << "\n";
    }
    else if (bytes_received == 0)
    {
        std::cout << "Client closed the connection\n";
    }
    else
    {
        std::cerr << "Failed to receive data from client\n";
    }

    // Step 8: Send response back to client
    if (bytes_received > 0)
    {
        // Convert message to uppercase
        std::string message(buffer);
        for (char &c : message)
        {
            c = std::toupper(static_cast<unsigned char>(c));
        }

        ssize_t bytes_sent = send(client_socket, message.c_str(), message.length(), 0);

        if (bytes_sent > 0)
        {
            std::cout << "Sent " << bytes_sent << " bytes back to client (uppercased)\n";
        }
        else
        {
            std::cerr << "Failed to send response to client\n";
        }
    }

    // Step 9: Close sockets
    close(client_socket);
    std::cout << "Client connection closed\n";

    close(server_socket);
    std::cout << "Server socket closed\n";

    return 0;
}