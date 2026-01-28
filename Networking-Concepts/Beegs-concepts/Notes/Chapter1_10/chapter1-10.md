# 📚 Beej's Guide to Network Concepts - Notes (Chapters 1-10)

> **Source**: Beej's Guide to Network Concepts by Brian "Beej Jorgensen" Hall  
> **Version**: v1.0.39, November 24, 2025  
> **Note**: All Python examples have been converted to C

---

## 📋 Table of Contents

1. [Foreword](#chapter-1-foreword)
2. [Networking Overview](#chapter-2-networking-overview)
3. [Introducing The Sockets API](#chapter-3-introducing-the-sockets-api)
4. [The Layered Network Model](#chapter-4-the-layered-network-model)
5. [Project: HTTP Client and Server](#chapter-5-project-http-client-and-server)
6. [The Internet Protocol (IP)](#chapter-6-the-internet-protocol-ip)
7. [The Internet Protocol version 4](#chapter-7-the-internet-protocol-version-4)
8. [The Internet Protocol version 6](#chapter-8-the-internet-protocol-version-6)
9. [Project: A Better Web Server](#chapter-9-project-a-better-web-server)
10. [Endianness and Integers](#chapter-10-endianness-and-integers)

---

# Chapter 1: Foreword

## 📌 Summary

This guide covers **networking concepts** and fundamentals, using programming as a vehicle for understanding. It's designed for people new to networking who want to understand terms like ISO-OSI, TCP/IP, ports, Ethernet, and LANs.

### 🎯 Key Takeaways
- The guide focuses on **concepts** rather than just programming syntax
- Original Unix sockets API was developed in C
- Understanding networking fundamentals is crucial before diving into network programming

---

# Chapter 2: Networking Overview

## 🎯 Learning Objectives
- Understand the difference between circuit-switched and packet-switched networks
- Learn client/server architecture basics
- Understand the role of protocols and network layers

---

## 2.1 Circuit Switched Networks

### **Definition**
> **Circuit Switching**: A dedicated communication path is established between two devices for the entire duration of communication.

### 📝 Key Points
- **Historical context**: Used by old telephone systems
- Physical connection maintained throughout call
- Operator would physically plug jumper wires to create connection

### ❌ Disadvantages
| Problem | Description |
|---------|-------------|
| **Scalability** | Scales very poorly |
| **Dedicated circuits** | One circuit per call required |
| **Wasted resources** | Silent periods still occupy the circuit |
| **Limited sharing** | Multiple people cannot use same line |
| **Infrastructure limits** | Limited number of physical wires |

---

## 2.2 Packet Switched Networks

### **Definition**
> **Packet Switching**: Data is split into individual packets that travel independently through the network and are reassembled at the destination.

### 📝 Key Characteristics
- Data split into **individual packets** (varying sizes)
- Each packet sent **independently** over the network
- Packets can take **different routes**
- Destination computer **reassembles** packets

### 🎯 Real-World Analogy
```
📬 SNAIL MAIL ANALOGY:
- Your letter (packet) enters the postal system
- Mixed with other mail going different places
- Routed through various facilities
- Eventually arrives at destination
- Multiple letters can share same transport
```

### ✅ Advantages
| Advantage | Explanation |
|-----------|-------------|
| **No dedicated circuits** | Billions of computers can communicate |
| **Resource sharing** | Multiple computers share the same wire |
| **Full utilization** | No "dead air" - wire always busy if needed |
| **Interleaved transmission** | Packets appear simultaneous |

### 💡 Memory Aid
> **"SIRI"** - **S**hared lines, **I**ndependent packets, **R**eassembly required, **I**nterleaved transmission

---

## 2.3 Client/Server Architecture

### **Definitions**
> **Server**: A program that listens for incoming connections, accepts them, and typically receives requests and sends responses.

> **Client**: A program that initiates connections to servers.

### 📊 Relationship Diagram
```
    ┌─────────────┐          ┌─────────────┐
    │   CLIENT    │  ──────► │   SERVER    │
    │  (initiates)│          │  (listens)  │
    └─────────────┘          └─────────────┘
           │                        │
           │      Request           │
           │  ─────────────────────►│
           │                        │
           │      Response          │
           │◄─────────────────────  │
```

### Key Points
- **One server** typically serves **many clients**
- **Server farms** exist for high-traffic services (e.g., Google)
- Both are network programs; server just waits for connections

---

## 2.4 The OS, Network Programming, and Sockets

### 🔑 Key Concept
> The **Operating System** controls all access to network hardware. To write network software, you must interface through the OS.

### **Sockets API**
- Originally developed for **Unix**
- Blend of **library calls** and **system calls**
- Other languages/OSes maintain "sockets" terminology as homage

---

## 2.5 Protocols

### **Definition**
> **Protocol**: A specifically defined set of rules determining what bytes get sent when, and from whom to whom.

### 🎯 Real-World Analogy
```
❌ BREAKING PROTOCOL:
Restaurant: "Thank you for calling The Pizza Restaurant. Can I help you?"
Customer: "Would you like fries with that?"

This is a protocol mismatch - communication fails!
```

### 📋 Common Protocols

| Protocol | Purpose | Layer |
|----------|---------|-------|
| **TCP** | Reliable data transmission | Transport |
| **UDP** | Fast, unreliable transmission | Transport |
| **IP** | Packet routing | Network |
| **HTTP** | Web page requests | Application |
| **Ethernet** | LAN data transfer | Link |

---

## 2.6 Network Layers and Abstraction

### 🔄 Data Flow (Sending)

```
┌─────────────────────────────────────────────────────────────┐
│  Application Layer                                          │
│  User: "Send 'GET / HTTP/1.1' to that web server"          │
└─────────────────────────────────────────────────────────────┘
                              ▼
┌─────────────────────────────────────────────────────────────┐
│  Transport Layer (TCP/UDP)                                  │
│  OS wraps data with header for error detection/ordering     │
└─────────────────────────────────────────────────────────────┘
                              ▼
┌─────────────────────────────────────────────────────────────┐
│  Network Layer (IP)                                         │
│  OS wraps everything with routing header                    │
└─────────────────────────────────────────────────────────────┘
                              ▼
┌─────────────────────────────────────────────────────────────┐
│  Link Layer (Ethernet)                                      │
│  NIC wraps everything with LAN delivery header              │
└─────────────────────────────────────────────────────────────┘
                              ▼
                     📡 ON THE WIRE 📡
```

### 🔑 Key Principle
> Each layer is **indifferent** to what the layers below it are doing. This allows **swapping protocols** at various layers while keeping the rest working.

### 💡 Example Protocol Stacks
- Web page: **HTTP/TCP/IP/Ethernet**
- File transfer: **TFTP/UDP/IP/Ethernet**

---

## 2.7 Wired vs. Wireless

### Key Insight
> Both wired and WiFi networks use the **Ethernet protocol** for low-level communication.

| Type | Medium | Protocol |
|------|--------|----------|
| Wired | Physical cables | Ethernet |
| Wireless | Radio waves | Ethernet (same!) |

### Definition
> **LAN (Local Area Network)**: Computers that are either wired together OR using the same WiFi access point.

---

## 📝 Chapter 2 Review Questions

1. **Q**: Is the Internet circuit-switched or packet-switched?
   > **A**: Packet-switched

2. **Q**: What role does the OS play in networked programs?
   > **A**: It controls all access to network hardware; programs must interface through the OS

3. **Q**: Why do we have protocol stacks and data encapsulation?
   > **A**: To separate responsibilities, allow protocol swapping, and enable layer independence

---

# Chapter 3: Introducing The Sockets API

## 🎯 Learning Objectives
- Understand the client connection process
- Learn the server listening process
- Grasp the purpose of ports and binding

---

## 3.1 Client Connection Process

### 📋 Step-by-Step Process

```c
// STEP 1: Create a socket
int sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0) {
    perror("socket");
    exit(1);
}

// STEP 2: Set up server address structure
struct sockaddr_in server_addr;
memset(&server_addr, 0, sizeof(server_addr));
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(80);  // HTTP port

// STEP 3: DNS lookup (convert hostname to IP)
struct hostent *he = gethostbyname("example.com");
if (he == NULL) {
    herror("gethostbyname");
    exit(1);
}
memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

// STEP 4: Connect to the server
if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
}

// STEP 5: Send and receive data
char *request = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
send(sockfd, request, strlen(request), 0);

char buffer[4096];
int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
buffer[bytes_received] = '\0';
printf("%s", buffer);

// STEP 6: Close the connection
close(sockfd);
```

### 🔑 Important Notes on Ports
| Port Range | Description |
|------------|-------------|
| **0-1023** | Well-known ports (require root/admin) |
| **1024-49151** | Registered ports |
| **49152-65535** | Dynamic/Private ports |

> **Common Port**: 80 is the standard HTTP port

---

## 3.2 Server Listening Process

### 📋 Step-by-Step Process

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    // STEP 1: Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    // STEP 2: Bind the socket to a port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Any local address
    server_addr.sin_port = htons(28333);        // Port 28333

    // Optional: Allow port reuse
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // STEP 3: Listen for incoming connections
    if (listen(server_fd, 10) < 0) {  // Backlog of 10
        perror("listen");
        exit(1);
    }

    printf("Server listening on port 28333...\n");

    // STEP 4: Accept incoming connections (in a loop)
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        
        // This blocks until a client connects
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // STEP 5: Receive request from client
        char buffer[4096];
        int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        buffer[bytes_received] = '\0';

        // STEP 6: Send response
        char *response = "HTTP/1.1 200 OK\r\n"
                         "Content-Type: text/plain\r\n"
                         "Content-Length: 6\r\n"
                         "Connection: close\r\n"
                         "\r\n"
                         "Hello!";
        send(client_fd, response, strlen(response), 0);

        // Close this client connection
        close(client_fd);

        // STEP 7: Loop back to accept() for next connection
    }

    close(server_fd);
    return 0;
}
```

### 🔑 Key Concepts

| Concept | Description |
|---------|-------------|
| **bind()** | Associates socket with specific port |
| **listen()** | Marks socket as passive (waiting for connections) |
| **accept()** | Returns a **NEW** socket for each client |
| **Original socket** | Continues listening after accept() |

### 💡 Why accept() Returns a New Socket
```
                    ┌───────────────┐
                    │ Listen Socket │ (Port 80)
                    │   (passive)   │
                    └───────┬───────┘
                            │
          ┌─────────────────┼─────────────────┐
          ▼                 ▼                 ▼
    ┌──────────┐      ┌──────────┐      ┌──────────┐
    │ Client 1 │      │ Client 2 │      │ Client 3 │
    │  Socket  │      │  Socket  │      │  Socket  │
    └──────────┘      └──────────┘      └──────────┘

Each client gets its OWN socket for communication!
```

---

## 📝 Chapter 3 Review Questions

1. **Q**: What role does `bind()` play on the server side?
   > **A**: Associates the socket with a specific port number so clients know where to connect

2. **Q**: Would a client ever call `bind()`?
   > **A**: Usually not needed - OS assigns an unused port automatically. But yes, if specific source port is required

3. **Q**: Why does `accept()` return a new socket?
   > **A**: So the server can handle multiple clients simultaneously while the original socket continues listening

4. **Q**: If one computer uses TCP port 3490, can another computer use port 3490?
   > **A**: Yes! Ports are per-computer, not global

5. **Q**: Why do ports exist?
   > **A**: They allow multiple programs on the same IP address to receive network data - IP addresses identify machines, ports identify programs

---

# Chapter 4: The Layered Network Model

## 🎯 Learning Objectives
- Understand key networking terms
- Learn the Internet Layer Model
- Understand the OSI Model and its relationship to the Internet Model

---

## 4.1 Essential Terminology

### 📚 Glossary

| Term | Definition |
|------|------------|
| **IP Address** | 4-byte (IPv4) or 16-byte (IPv6) number uniquely identifying a computer |
| **Port** | Number (0-65535) identifying specific programs on a host |
| **TCP** | Transmission Control Protocol - reliable, in-order delivery |
| **UDP** | User Datagram Protocol - fast but unreliable |
| **MAC Address** | 6-byte hardware address (format: `aa:bb:cc:dd:ee:ff`) |
| **Router** | Specialized computer that forwards packets based on destination IP |
| **LAN** | Local Area Network - computers directly connected (not via router) |
| **Interface** | Physical networking hardware (e.g., `eth0`, `wlan0`) |
| **Header** | Data prepended by a protocol containing control information |
| **NAT** | Network Address Translation - maps private to public addresses |

---

## 4.2 Example of Protocol Layering

### 🔄 HTTP Request Journey (Sending)

```
┌────────────────────────────────────────────────────────────────┐
│  Browser creates HTTP request:                                 │
│  "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n"                │
└────────────────────────────────────────────────────────────────┘
                              ▼
┌────────────────────────────────────────────────────────────────┐
│  TCP adds header: [Port info + Sequence # + Checksum]          │
│  ┌─────────┬─────────────────────────────────────┐            │
│  │TCP HDR  │  HTTP Request Data                   │            │
│  └─────────┴─────────────────────────────────────┘            │
└────────────────────────────────────────────────────────────────┘
                              ▼
┌────────────────────────────────────────────────────────────────┐
│  IP adds header: [Source IP + Destination IP + TTL]            │
│  ┌────────┬─────────┬───────────────────────────┐             │
│  │IP HDR  │TCP HDR  │  HTTP Request Data         │             │
│  └────────┴─────────┴───────────────────────────┘             │
└────────────────────────────────────────────────────────────────┘
                              ▼
┌────────────────────────────────────────────────────────────────┐
│  Ethernet adds header: [Source MAC + Destination MAC]          │
│  ┌──────────┬────────┬─────────┬─────────────────┐            │
│  │ETH HDR   │IP HDR  │TCP HDR  │  HTTP Data       │            │
│  └──────────┴────────┴─────────┴─────────────────┘            │
└────────────────────────────────────────────────────────────────┘
                              ▼
                     📡 Sent on the wire 📡
```

### 🔄 Receiving Process
The reverse happens at the destination:
1. Strip Ethernet header → Check MAC address
2. Strip IP header → Check IP address
3. Strip TCP header → Verify checksum, reassemble
4. Deliver HTTP data to web server process

---

## 4.3 The Internet Layer Model

### 📊 Layer Diagram

| Layer | Responsibility | Example Protocols |
|-------|----------------|-------------------|
| **Application** | Structured application data | HTTP, FTP, SSH, SMTP, POP |
| **Transport** | Data integrity, packet splitting/reassembly | TCP, UDP |
| **Internet** | Routing | IP, IPv6, ICMP |
| **Link** | Physical signals on wires | Ethernet, PPP, Token Ring |

### 💡 Memory Aid: "**A**ll **T**urtles **I**n **L**akes"
- **A**pplication
- **T**ransport
- **I**nternet
- **L**ink

---

## 4.4 The ISO OSI Model

### 📊 OSI to Internet Model Mapping

| OSI Layer | Internet Layer | Responsibility |
|-----------|----------------|----------------|
| Application | Application | User data formatting |
| Presentation | Application | Encoding, encryption |
| Session | Application | Connection management |
| Transport | Transport | Reliability |
| Network | Network | Routing |
| Data Link | Link | Frame encapsulation |
| Physical | Link | Electrical signals |

### 💡 Memory Aid: "**P**lease **D**o **N**ot **T**hrow **S**ausage **P**izza **A**way"
- **P**hysical
- **D**ata Link
- **N**etwork
- **T**ransport
- **S**ession
- **P**resentation
- **A**pplication

---

## 📝 Chapter 4 Review Questions

1. **Q**: When a router sees an IP address, how does it know where to forward it?
   > **A**: It consults its routing table to find the best path/interface

2. **Q**: How many IPv4 addresses are possible?
   > **A**: 2³² = 4,294,967,296 (roughly 4.3 billion)

3. **Q**: How many IPv6 addresses are possible?
   > **A**: 2¹²⁸ ≈ 3.4 × 10³⁸ (a virtually unlimited number)

4. **Q**: Why does IP wrap TCP (not the other way around)?
   > **A**: Routing (IP's job) must happen first to get the packet to the destination; then TCP handles integrity

---

# Chapter 5: Project - HTTP Client and Server

## 🎯 Project Goals
- Build a web client that can download files
- Build a simple web server
- Understand HTTP protocol fundamentals

---

## 5.1 HTTP Protocol Summary

### 📤 HTTP Request Format
```
GET /path/to/file.html HTTP/1.1\r\n
Host: example.com\r\n
Connection: close\r\n
\r\n
```

### 📥 HTTP Response Format
```
HTTP/1.1 200 OK\r\n
Content-Type: text/plain\r\n
Content-Length: 6\r\n
Connection: close\r\n
\r\n
Hello!
```

### 🔑 Key Components

| Component | Description |
|-----------|-------------|
| **Request Line** | Method + Path + Protocol |
| **Headers** | Key-value pairs (Host, Content-Type, etc.) |
| **Blank Line** | `\r\n\r\n` separates header from body |
| **Body/Payload** | Actual data being transferred |

---

## 5.2 HTTP Client in C

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname [port]\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = (argc > 2) ? atoi(argv[2]) : 80;

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // DNS lookup
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    // Set up server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Build and send HTTP request
    char request[1024];
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n",
             hostname);

    // Use sendall pattern for reliability
    int total_sent = 0;
    int request_len = strlen(request);
    while (total_sent < request_len) {
        int sent = send(sockfd, request + total_sent, request_len - total_sent, 0);
        if (sent < 0) {
            perror("send");
            exit(1);
        }
        total_sent += sent;
    }

    // Receive response
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}
```

---

## 5.3 HTTP Server in C

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define DEFAULT_PORT 28333

int main(int argc, char *argv[]) {
    int port = (argc > 1) ? atoi(argv[1]) : DEFAULT_PORT;

    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Allow port reuse (prevents "Address already in use" error)
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen
    if (listen(server_fd, 10) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %d...\n", port);

    // Main loop
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // Receive request (look for \r\n\r\n)
        char buffer[BUFFER_SIZE];
        int total_received = 0;
        int bytes;

        while ((bytes = recv(client_fd, buffer + total_received, 
                            BUFFER_SIZE - total_received - 1, 0)) > 0) {
            total_received += bytes;
            buffer[total_received] = '\0';
            
            // Check for end of header
            if (strstr(buffer, "\r\n\r\n") != NULL) {
                break;
            }
        }

        // Send response
        char *response = "HTTP/1.1 200 OK\r\n"
                         "Content-Type: text/plain\r\n"
                         "Content-Length: 6\r\n"
                         "Connection: close\r\n"
                         "\r\n"
                         "Hello!";
        send(client_fd, response, strlen(response), 0);

        close(client_fd);
    }

    close(server_fd);
    return 0;
}
```

---

## 5.4 Common HTTP Status Codes

| Code | Meaning | Description |
|------|---------|-------------|
| **200** | OK | Request succeeded |
| **301** | Moved Permanently | Resource has moved (check Location header) |
| **302** | Moved Temporarily | Temporary redirect |
| **400** | Bad Request | Malformed request |
| **404** | Not Found | Resource doesn't exist |
| **500** | Internal Server Error | Server-side error |

### ⚠️ Common Issues

| Error | Likely Cause |
|-------|--------------|
| "Address already in use" | Server crashed; wait or use `SO_REUSEADDR` |
| 400 Bad Request | Missing `\r\n` line endings |
| 404 Not Found | Wrong `Host:` header value |

---

# Chapter 6: The Internet Protocol (IP)

## 🎯 Learning Objectives
- Understand IP's role in routing
- Learn about IPv4 vs IPv6
- Understand subnets and private networks

---

## 6.1 IP Overview

### **Definition**
> **Internet Protocol (IP)**: Responsible for routing packets of data around the Internet using IP addresses.

### 🔑 Key Functions
- **Addressing**: Uniquely identifies computers
- **Routing**: Determines path packets take through network

---

## 6.2 IPv4 vs IPv6

| Feature | IPv4 | IPv6 |
|---------|------|------|
| **Address size** | 4 bytes (32 bits) | 16 bytes (128 bits) |
| **Format** | Dots-and-numbers (192.168.1.3) | Colons-and-hex (fe80::1) |
| **Total addresses** | ~4.3 billion | ~3.4 × 10³⁸ |
| **Example** | 198.51.100.12 | 2001:db8::8a2e:370:7334 |

---

## 6.3 Subnets

### **Concept**
Every IP address is split into two portions:
1. **Network portion** (identifies the subnet)
2. **Host portion** (identifies specific computer)

### 📊 Visual Example (8-bit simplified)
```
Address: 00010111

Network  Host
-------  ----
000101   11
   ↓      ↓
Network 5, Host 3
```

### 🔑 Key Points
- Network part **always comes first**
- More host bits = more hosts on network
- Host with all 0s or all 1s is **reserved**

---

## 6.4 Additional IP-Layer Protocols

| Protocol | Purpose |
|----------|---------|
| **ICMP** | Control messages (used by ping, traceroute) |
| **IPSec** | Encryption and authentication (VPNs) |

---

## 6.5 Private Networks

### **Reserved Private Ranges**
| Range | Class |
|-------|-------|
| `10.0.0.0/8` | Class A Private |
| `172.16.0.0/12` | Class B Private |
| `192.168.0.0/16` | Class C Private |

> These addresses are **not globally unique** - they're translated via **NAT** (Network Address Translation)

---

## 6.6 Static vs Dynamic IP (DHCP)

### **Static IP**
- **Fixed** address that never changes
- Required for servers
- More expensive

### **Dynamic IP (DHCP)**
- **Changes** when device reconnects
- Assigned by DHCP server
- Common for clients (laptops, phones)

### DHCP Process
```
┌─────────────┐                    ┌─────────────┐
│   Client    │ ──── "I'm here!"─► │   DHCP      │
│  (new)      │      (Broadcast)   │   Server    │
│             │ ◄── IP: 10.0.0.42 ─│             │
│             │    (Assignment)    │             │
└─────────────┘                    └─────────────┘
```

---

# Chapter 7: The Internet Protocol version 4

## 🎯 Learning Objectives
- Understand IPv4 address notation
- Master subnet masks and slash notation
- Know special addresses and subnets

---

## 7.1 IPv4 Addresses

### **Format**
- Four 8-bit numbers (0-255)
- Separated by dots
- Total: 32 bits

```
Example: 198.51.100.125

 198    .    51    .   100    .   125
┌──────┬──────────┬──────────┬────────┐
│ Byte │   Byte   │   Byte   │  Byte  │
└──────┴──────────┴──────────┴────────┘
```

---

## 7.2 Subnets and Slash Notation

### **Slash Notation**
```
198.51.100.0/24
            ↑
    24 bits for network (8 bits for host)
```

### Binary Breakdown
```
       24 network bits         | 8 host bits
-------------------------------+---------
11000110 . 00110011 . 01100100 . 00000000
     198         51        100          0
```

### 📊 Subnet Size Examples

| Slash | Network Bits | Host Bits | Usable Hosts |
|-------|--------------|-----------|--------------|
| /8 | 8 | 24 | 16,777,214 |
| /16 | 16 | 16 | 65,534 |
| /24 | 24 | 8 | 254 |
| /28 | 28 | 4 | 14 |

> **Formula**: Usable hosts = 2^(host bits) - 2 (minus reserved + broadcast)

---

## 7.3 Subnet Masks

### **Definition**
A subnet mask has all network bits set to 1.

### Example
```
Subnet: 198.51.100.0/24

Mask:   255.255.255.0
Binary: 11111111.11111111.11111111.00000000
```

### Using Mask to Find Subnet
```c
// C code to find subnet from IP and mask
#include <stdio.h>
#include <arpa/inet.h>

int main() {
    uint32_t ip = inet_addr("198.51.100.67");
    uint32_t mask = inet_addr("255.255.255.0");
    uint32_t subnet = ip & mask;
    
    struct in_addr addr;
    addr.s_addr = subnet;
    printf("Subnet: %s\n", inet_ntoa(addr));  // 198.51.100.0
    return 0;
}
```

---

## 7.4 Special Addresses

| Address | Purpose |
|---------|---------|
| `127.0.0.1` | Localhost (this computer) |
| `0.0.0.0` | Reserved (host 0) |
| `255.255.255.255` | Broadcast (all hosts) |
| `x.x.x.0` | Network address (reserved) |
| `x.x.x.255` | Subnet broadcast (for /24) |

---

## 7.5 Special Subnets

| Subnet | Purpose |
|--------|---------|
| `10.0.0.0/8` | Private network |
| `127.0.0.0/8` | Loopback |
| `172.16.0.0/12` | Private network |
| `192.168.0.0/16` | Private network |
| `192.0.2.0/24` | Documentation examples |
| `198.51.100.0/24` | Documentation examples |

---

## 📝 Chapter 7 Review Questions

1. **Q**: Why is 192.168.262.12 invalid?
   > **A**: 262 exceeds 255, the maximum value for a single byte

2. **Q**: In `10.37.129.212/17`, how many host bits?
   > **A**: 32 - 17 = 15 host bits

---

# Chapter 8: The Internet Protocol version 6

## 🎯 Learning Objectives
- Understand IPv6 representation
- Learn about link-local addresses
- Know special IPv6 addresses

---

## 8.1 IPv6 Representation

### **Format**
- 128 bits (16 bytes)
- 8 groups of 4 hex digits
- Separated by colons

```
Full:      2001:0db8:6ffa:8939:163b:4cab:98bf:070a
Shortened: 2001:db8:6ffa:8939:163b:4cab:98bf:70a
```

### Shortening Rules
1. **Leading zeros** can be removed from each group
2. **Consecutive zero groups** can be replaced with `::`

### Examples
```
Original:   2001:0db8:6ffa:0000:0000:00ab:98bf:070a
Rule 1:     2001:db8:6ffa:0:0:ab:98bf:70a
Rule 2:     2001:db8:6ffa::ab:98bf:70a
```

---

## 8.2 Link-Local Addresses

### **Definition**
> Automatically assigned addresses unique only within the LAN.

- Prefix: `fe80::/10`
- Auto-computed when interface comes up
- **Not routed** outside the LAN

---

## 8.3 Special IPv6 Addresses

| Address | Purpose |
|---------|---------|
| `::1` | Localhost (equivalent to 127.0.0.1) |
| `2001:db8::/32` | Documentation |
| `fe80::/10` | Link-local addresses |

---

## 8.4 IPv6 in URLs

Since `:` is used for ports, IPv6 addresses go in brackets:

```
http://[::1]:33490/
http://[2001:db8::1]:8080/page.html
```

---

# Chapter 9: Project - A Better Web Server

## 🎯 Project Goals
- Serve actual files from disk
- Parse HTTP request paths
- Handle different content types
- Implement 404 error handling

---

## 9.1 Enhanced Web Server in C

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>

#define BUFFER_SIZE 4096
#define DEFAULT_PORT 28333

// Get MIME type from file extension
const char* get_mime_type(const char *filename) {
    const char *ext = strrchr(filename, '.');
    if (ext == NULL) return "application/octet-stream";
    
    if (strcmp(ext, ".html") == 0) return "text/html";
    if (strcmp(ext, ".txt") == 0) return "text/plain";
    if (strcmp(ext, ".css") == 0) return "text/css";
    if (strcmp(ext, ".js") == 0) return "application/javascript";
    if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) return "image/jpeg";
    if (strcmp(ext, ".png") == 0) return "image/png";
    if (strcmp(ext, ".gif") == 0) return "image/gif";
    
    return "application/octet-stream";
}

// Extract filename from path (strips directory for security)
void get_filename(const char *path, char *filename, size_t size) {
    // Find last slash
    const char *last_slash = strrchr(path, '/');
    if (last_slash != NULL) {
        strncpy(filename, last_slash + 1, size - 1);
    } else {
        strncpy(filename, path, size - 1);
    }
    filename[size - 1] = '\0';
    
    // Default to index.html if empty
    if (strlen(filename) == 0) {
        strcpy(filename, "index.html");
    }
}

// Send 404 response
void send_404(int client_fd) {
    char *response = "HTTP/1.1 404 Not Found\r\n"
                     "Content-Type: text/plain\r\n"
                     "Content-Length: 13\r\n"
                     "Connection: close\r\n"
                     "\r\n"
                     "404 not found";
    send(client_fd, response, strlen(response), 0);
}

// Send file response
void send_file(int client_fd, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        send_404(client_fd);
        return;
    }
    
    // Get file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    // Read file content
    char *content = malloc(file_size);
    fread(content, 1, file_size, fp);
    fclose(fp);
    
    // Build and send response header
    char header[512];
    snprintf(header, sizeof(header),
             "HTTP/1.1 200 OK\r\n"
             "Content-Type: %s\r\n"
             "Content-Length: %ld\r\n"
             "Connection: close\r\n"
             "\r\n",
             get_mime_type(filename),
             file_size);
    
    send(client_fd, header, strlen(header), 0);
    send(client_fd, content, file_size, 0);
    
    free(content);
}

int main(int argc, char *argv[]) {
    int port = (argc > 1) ? atoi(argv[1]) : DEFAULT_PORT;
    
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(port)
    };
    
    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_fd, 10);
    
    printf("Server running on http://localhost:%d\n", port);
    
    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        
        char buffer[BUFFER_SIZE] = {0};
        recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        
        // Parse GET path
        char method[16], path[256];
        sscanf(buffer, "%s %s", method, path);
        
        // Extract and serve filename
        char filename[256];
        get_filename(path, filename, sizeof(filename));
        
        printf("Request: %s %s -> %s\n", method, path, filename);
        send_file(client_fd, filename);
        
        close(client_fd);
    }
    
    return 0;
}
```

---

## 9.2 MIME Types

| Extension | MIME Type |
|-----------|-----------|
| `.txt` | `text/plain` |
| `.html` | `text/html` |
| `.css` | `text/css` |
| `.js` | `application/javascript` |
| `.jpg/.jpeg` | `image/jpeg` |
| `.png` | `image/png` |
| `.pdf` | `application/pdf` |

---

## ⚠️ Security Considerations

### Path Traversal Attack Prevention
```
DANGER! Attacker could request:
GET /../../../../../etc/passwd HTTP/1.1

SOLUTION: Strip all path components, only keep filename
```

---

# Chapter 10: Endianness and Integers

## 🎯 Learning Objectives
- Understand how integers become byte sequences
- Learn Big-Endian vs Little-Endian
- Convert between integers and bytes in C

---

## 10.1 Integer Representation

### **Concept**
Numbers larger than 255 require multiple bytes.

### Example: 16-bit Number 4530
```
High byte: 17  (17 × 256 = 4352)
Low byte:  178
Total:     17 × 256 + 178 = 4530

Bytes: [17] [178]
Hex:   [11] [B2]
Binary: [00010001] [10110010]
```

---

## 10.2 Endianness

### **Definitions**

> **Big-Endian**: Most significant byte **first** (network byte order)
> 
> **Little-Endian**: Least significant byte **first** (most Intel/ARM CPUs)

### Visual Comparison
```
Number: 0x45F2 (17906 decimal)

BIG-ENDIAN (Network Order):
[45] [F2]  ← Most significant first
 ↑
First byte

LITTLE-ENDIAN (x86/ARM):
[F2] [45]  ← Least significant first
 ↑
First byte
```

### 💡 Memory Aid
> "**B**ig-Endian = **B**ig end first" - The "big" (most significant) byte comes first

---

## 10.3 Network Byte Order

> All network protocols use **Big-Endian** (called "Network Byte Order")

### Why This Matters
- Your CPU may be Little-Endian
- Network expects Big-Endian
- You must convert before sending!

---

## 10.4 C Conversion Functions

### Standard Network Byte Order Functions

```c
#include <arpa/inet.h>

// Host to Network (convert before sending)
uint16_t htons(uint16_t hostshort);   // Host TO Network Short
uint32_t htonl(uint32_t hostlong);    // Host TO Network Long

// Network to Host (convert after receiving)
uint16_t ntohs(uint16_t netshort);    // Network TO Host Short
uint32_t ntohl(uint32_t netlong);     // Network TO Host Long
```

### Example Usage

```c
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    // Converting integer to network byte order for sending
    uint16_t port = 3490;
    uint16_t network_port = htons(port);
    
    printf("Host port: %d\n", port);
    printf("Network port: %d (bytes swapped if little-endian)\n", network_port);
    
    // Manual byte extraction (Big-Endian)
    unsigned char bytes[2];
    bytes[0] = (port >> 8) & 0xFF;  // High byte first
    bytes[1] = port & 0xFF;         // Low byte second
    
    printf("As bytes: [%02X] [%02X]\n", bytes[0], bytes[1]);
    
    // Converting back
    uint16_t reconstructed = (bytes[0] << 8) | bytes[1];
    printf("Reconstructed: %d\n", reconstructed);
    
    return 0;
}
```

### Complete Byte Conversion Example

```c
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

// Convert 32-bit integer to byte array (Big-Endian)
void int_to_bytes(uint32_t value, unsigned char *bytes) {
    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8) & 0xFF;
    bytes[3] = value & 0xFF;
}

// Convert byte array to 32-bit integer (Big-Endian)
uint32_t bytes_to_int(unsigned char *bytes) {
    return ((uint32_t)bytes[0] << 24) |
           ((uint32_t)bytes[1] << 16) |
           ((uint32_t)bytes[2] << 8) |
           (uint32_t)bytes[3];
}

int main() {
    uint32_t original = 0x12345678;
    unsigned char bytes[4];
    
    // Convert to bytes
    int_to_bytes(original, bytes);
    printf("Original: 0x%08X\n", original);
    printf("As bytes: [%02X] [%02X] [%02X] [%02X]\n", 
           bytes[0], bytes[1], bytes[2], bytes[3]);
    
    // Convert back
    uint32_t restored = bytes_to_int(bytes);
    printf("Restored: 0x%08X\n", restored);
    
    // Verify using library function
    uint32_t network_order = htonl(original);
    printf("htonl result: 0x%08X\n", network_order);
    
    return 0;
}
```

---

## 10.5 Practical Application: Sending Integers Over Network

```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Send a 32-bit integer over a socket
int send_int32(int sockfd, uint32_t value) {
    // Convert to network byte order
    uint32_t network_value = htonl(value);
    
    // Send the 4 bytes
    return send(sockfd, &network_value, sizeof(network_value), 0);
}

// Receive a 32-bit integer from a socket
int recv_int32(int sockfd, uint32_t *value) {
    uint32_t network_value;
    
    // Receive 4 bytes
    int bytes = recv(sockfd, &network_value, sizeof(network_value), 0);
    
    if (bytes == sizeof(network_value)) {
        // Convert from network byte order to host
        *value = ntohl(network_value);
    }
    
    return bytes;
}
```

---

## 📝 Chapter 10 Review Questions

1. **Q**: What's the difference between Big-Endian and Little-Endian?
   > **A**: Big-Endian stores the most significant byte first; Little-Endian stores the least significant byte first

2. **Q**: What is Network Byte Order?
   > **A**: Big-Endian - the standard byte order for network protocols

3. **Q**: How would you swap byte order in a 16-bit number?
   > **A**: `swapped = ((value >> 8) & 0xFF) | ((value & 0xFF) << 8);` or use `htons()`/`ntohs()`

4. **Q**: Why not just send numbers directly?
   > **A**: Different CPUs have different byte orders; network protocols standardize on Big-Endian

---

# 📊 Mind Map: Networking Concepts Overview

```
                        ┌─────────────────────┐
                        │   NETWORKING        │
                        │   FUNDAMENTALS      │
                        └──────────┬──────────┘
                                   │
        ┌──────────────────────────┼──────────────────────────┐
        │                          │                          │
        ▼                          ▼                          ▼
┌───────────────┐        ┌─────────────────┐        ┌─────────────────┐
│   PROTOCOLS   │        │   ADDRESSING    │        │   DATA TRANSFER │
├───────────────┤        ├─────────────────┤        ├─────────────────┤
│ • TCP         │        │ • IPv4 (32-bit) │        │ • Endianness    │
│ • UDP         │        │ • IPv6 (128-bit)│        │ • Byte Order    │
│ • IP          │        │ • Ports (0-65535)│       │ • Packets       │
│ • HTTP        │        │ • Subnets       │        │ • Segments      │
│ • Ethernet    │        │ • Masks         │        │ • Frames        │
└───────────────┘        └─────────────────┘        └─────────────────┘
        │                          │                          │
        └──────────────────────────┼──────────────────────────┘
                                   │
                                   ▼
                        ┌─────────────────────┐
                        │   LAYER MODEL       │
                        ├─────────────────────┤
                        │ Application  (HTTP) │
                        │ Transport    (TCP)  │
                        │ Internet     (IP)   │
                        │ Link      (Ethernet)│
                        └─────────────────────┘
```

---

# 📚 Additional Resources

## Books
1. **TCP/IP Illustrated, Volume 1** by W. Richard Stevens - The definitive TCP/IP reference
2. **Beej's Guide to Network Programming** - For C network programming
3. **Computer Networking: A Top-Down Approach** by Kurose & Ross

## Online Resources
- [RFC 793 - TCP Specification](https://tools.ietf.org/html/rfc793)
- [RFC 791 - IP Specification](https://tools.ietf.org/html/rfc791)
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)

## Tools
- **Wireshark** - Network packet analyzer
- **netcat (nc)** - TCP/UDP testing utility
- **curl** - HTTP client
- **tcpdump** - Command-line packet capture

---

# ✅ Chapter 1-10 Summary

## Key Takeaways

1. **Networks** are packet-switched, not circuit-switched - enabling efficient sharing of resources

2. **Client-Server model** is fundamental - servers listen, clients connect

3. **Layered architecture** (Application → Transport → Network → Link) provides abstraction and modularity

4. **Sockets API** is the standard interface for network programming in C/Unix

5. **IP addresses** identify hosts; **ports** identify programs on those hosts

6. **IPv4** (32-bit) is limited; **IPv6** (128-bit) is the future

7. **Subnets** divide address space using network/host bit separation

8. **HTTP** follows request/response pattern with headers and body

9. **Endianness** matters when sending binary data - always use **network byte order** (Big-Endian)

10. **htonl/htons/ntohl/ntohs** are essential functions for byte order conversion

---

## 🎯 Potential Exam Questions

1. Explain the difference between circuit-switched and packet-switched networks.
2. What is the purpose of the TCP three-way handshake?
3. Convert the subnet 192.168.10.0/26 to binary and determine the number of usable host addresses.
4. Why do we need both IP addresses and port numbers?
5. Write C code to convert a 32-bit integer to network byte order and back.
6. Explain what happens when a web browser requests a page (trace through all layers).
7. What security vulnerability does path traversal exploit in web servers?
8. Compare and contrast the Internet Layer Model with the OSI Model.

---

*Notes compiled from Beej's Guide to Network Concepts, Chapters 1-10*
*All Python examples converted to C for systems programming context*
