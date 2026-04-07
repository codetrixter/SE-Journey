# Networking Concepts — Coverage Analysis

> **Last Analyzed:** April 7, 2026
> **Source Folder:** `Networking-Concepts/`
> **Reference:** `Networking-concepts-scope.md`

---

## 📊 Coverage Summary

| Section | Must Know | Should Know | Nice to Have | Status |
|---------|-----------|-------------|--------------|--------|
| Network Fundamentals & Models | 🟢 Done | 🟡 Partial | N/A | Mostly Complete |
| Physical & Data Link Layer | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Network Layer (IP) | 🟢 Done | 🟡 Partial | 🔴 Not Started | In Progress |
| Transport Layer | 🟢 Done | 🟡 Partial | 🔴 Not Started | Mostly Complete |
| Application Layer Protocols | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Socket Programming | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Network Security | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Network Performance & Debugging | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Network Architecture & Design | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Cloud Networking | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Distributed Systems Networking | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |

**Sources:**
- `TopDownApproach/` — Chapters 1, 2, 3, 4, 8 (Kurose & Ross textbook notes)
- `Beegs-concepts/` — Beej's guide notes with HTTP client implementation

---

## 1. Network Fundamentals & OSI/TCP-IP Models

### 1.1 OSI 7-Layer Model
- [x] **Must Know:** Layer responsibilities — *Covered in `TopDownApproach/chapter1/chapter1.md` (comprehensive overview of Internet architecture, protocols, layers)*
- [x] **Must Know:** Encapsulation & de-encapsulation — *Covered in Chapter 1 (packets, segments, datagrams, frames)*
- [x] **Must Know:** Protocol Data Units (PDUs) — *Covered in Chapter 1*
- [x] **Should Know:** Which protocols operate at which layer — *Covered in Chapter 1*

### 1.2 TCP/IP 4-Layer Model
- [x] **Must Know:** Link, Internet, Transport, Application — mapping to OSI — *Covered in Chapter 1*
- [x] **Must Know:** Practical relevance — *Covered in Chapter 1 (Internet architecture focus)*
- [x] **Should Know:** Where OSI vs TCP/IP models diverge — *Covered in Chapter 1*

### 1.3 Network Fundamentals
- [x] **Must Know:** Circuit switching vs packet switching — *Covered in Chapter 1 (detailed comparison)*
- [x] **Must Know:** Network topologies — *Covered in Chapter 1*
- [x] **Should Know:** Network devices — routers, switches, etc. — *Covered in Chapter 1*
- [ ] **Should Know:** NAT gateways

### ✅ Checklist – Network Fundamentals
- [x] OSI 7-layer model — responsibilities and PDUs at each layer
- [x] TCP/IP 4-layer model — mapping to OSI understood
- [x] Encapsulation / de-encapsulation explained
- [x] Circuit vs packet switching articulated
- [x] Network devices — roles and placement understood

---

## 2. Physical & Data Link Layer

### 2.1 Ethernet
- [x] **Must Know:** Ethernet frames — structure, MAC addressing — *Covered in `Beegs-concepts/` notes*
- [ ] **Must Know:** CSMA/CD, full-duplex switching
- [ ] **Should Know:** Frame size, MTU

### 2.2 VLANs & Switching
- [ ] **Should Know:** VLANs — **Not Started**
- [ ] **Should Know:** Trunking — **Not Started**
- [ ] **Should Know:** MAC address table — **Not Started**

### 2.3 ARP
- [ ] **Must Know:** Address Resolution Protocol — **Not Started**
- [ ] **Must Know:** ARP cache, ARP request/reply — **Not Started**
- [ ] **Should Know:** ARP spoofing — **Not Started**

### 2.4 Wireless
- [ ] **Nice to Have:** 802.11 standards — **Not Started**

### ✅ Checklist – Physical & Data Link Layer
- [x] Ethernet frame structure — basic understanding
- [ ] MAC addressing and switching mechanics
- [ ] ARP process understood
- [ ] VLANs concept
- [ ] MTU and fragmentation

---

## 3. Network Layer (IP)

### 3.1 IPv4
- [x] **Must Know:** IPv4 addressing — 32-bit, dotted decimal — *Covered in `TopDownApproach/chapter4/chapter4.md` (IPv4 datagram format, addressing, CIDR)*
- [x] **Must Know:** Subnetting — subnet masks, CIDR notation — *Covered in Chapter 4*
- [x] **Must Know:** Private vs public IP ranges — *Covered in Chapter 4*
- [x] **Should Know:** Classful addressing (A, B, C) — *Covered in Chapter 4 (legacy context)*
- [x] **Should Know:** VLSM — *Covered in Chapter 4*

### 3.2 IPv6
- [ ] **Should Know:** IPv6 addressing — **Not Started**
- [ ] **Should Know:** Transition mechanisms — **Not Started**

### 3.3 Routing
- [x] **Must Know:** Routing tables — *Covered in Chapter 4 (forwarding vs routing, router architecture)*
- [x] **Must Know:** Longest prefix match rule — *Covered in Chapter 4*
- [x] **Must Know:** Static routes vs dynamic routing — *Covered in Chapter 4*
- [ ] **Should Know:** OSPF
- [ ] **Should Know:** BGP

### 3.4 ICMP
- [ ] **Must Know:** Ping — echo request/reply
- [ ] **Must Know:** Traceroute — TTL expiry
- [ ] **Should Know:** ICMP error messages
- [ ] **Should Know:** PMTUD

### 3.5 NAT
- [x] **Must Know:** Network Address Translation — *Covered in Chapter 4 (NAT section)*
- [x] **Must Know:** Why NAT exists — IPv4 exhaustion — *Covered in Chapter 4*
- [ ] **Should Know:** NAT traversal — STUN, TURN, ICE
- [ ] **Should Know:** NAT types

### 3.6 IP Fragmentation & Multicast
- [x] **Should Know:** IP fragmentation — *Covered in Chapter 4 (fragmentation & reassembly)*
- [ ] **Should Know:** Don't Fragment (DF) flag
- [ ] **Nice to Have:** Multicast

### ✅ Checklist – Network Layer
- [x] IPv4 subnetting — calculate subnet, hosts, broadcast address
- [x] CIDR notation fluent
- [x] Routing table reading and longest prefix match understood
- [ ] OSPF & BGP concepts
- [ ] ICMP tools (ping, traceroute)
- [x] NAT types understood

---

## 4. Transport Layer

### 4.1 TCP Deep Dive
- [x] **Must Know:** 3-way handshake — SYN, SYN-ACK, ACK — *Covered in `TopDownApproach/chapter3/chapter3.md` (comprehensive TCP/UDP coverage)*
- [x] **Must Know:** 4-way teardown — *Covered in Chapter 3*
- [x] **Must Know:** TCP state machine — *Covered in Chapter 3*
- [ ] **Must Know:** TIME_WAIT — purpose (2×MSL)

### 4.2 TCP Flow Control
- [x] **Must Know:** Sliding window — *Covered in Chapter 3 (pipelined reliable data transfer, Go-Back-N, Selective Repeat)*
- [ ] **Should Know:** Window scaling option
- [ ] **Should Know:** Receive buffer management

### 4.3 TCP Congestion Control
- [x] **Must Know:** Slow start — *Covered in Chapter 3*
- [x] **Must Know:** Congestion avoidance — *Covered in Chapter 3*
- [x] **Must Know:** Fast retransmit — *Covered in Chapter 3*
- [x] **Must Know:** Fast recovery — *Covered in Chapter 3*
- [ ] **Should Know:** Congestion algorithms — Reno, Cubic, BBR

### 4.4 TCP Options
- [ ] **Should Know:** Timestamps — **Not Started**
- [ ] **Should Know:** SACK — **Not Started**
- [ ] **Should Know:** MSS negotiation — **Not Started**

### 4.5 UDP
- [x] **Must Know:** Connectionless, unreliable — *Covered in Chapter 3 (UDP segment structure, checksum)*
- [x] **Must Know:** Use cases — DNS, streaming, gaming — *Covered in Chapter 3*
- [x] **Must Know:** UDP header — *Covered in Chapter 3*

### 4.6 TCP vs UDP
- [x] **Must Know:** Trade-offs — *Covered in Chapter 3*
- [x] **Must Know:** When to choose TCP vs UDP — *Covered in Chapter 3*

### 4.7 QUIC Protocol
- [ ] **Should Know:** UDP-based, built-in TLS 1.3 — **Not Started**
- [ ] **Should Know:** 0-RTT connection establishment — **Not Started**

### ✅ Checklist – Transport Layer
- [x] TCP 3-way handshake & 4-way teardown explained
- [x] TCP state machine understood
- [ ] TIME_WAIT purpose and implications
- [x] Congestion control — slow start, congestion avoidance, fast retransmit
- [x] TCP vs UDP trade-offs clear
- [ ] QUIC protocol fundamentals
- [ ] TCP tuning parameters

---

## 5. Application Layer Protocols

### 5.1 HTTP
- [x] **Must Know:** HTTP/1.1 — methods, persistent connections — *Covered in `TopDownApproach/chapter2/chapter2.md` and `Beegs-concepts/Notes/`*
- [x] **Must Know:** Status codes — *Covered in Chapter 2*
- [x] **Must Know:** Headers — *Covered in Chapter 2*
- [ ] **Must Know:** HTTP/2 — multiplexing, header compression
- [ ] **Should Know:** HTTP/3 — QUIC-based
- [ ] **Should Know:** Content negotiation, conditional requests

> **Practical:** HTTP client implementation in C exists: `Beegs-concepts/Notes/Chapter1_10/HTTP-client.c`

### 5.2 HTTPS & TLS
- [x] **Must Know:** TLS handshake — *Covered in `TopDownApproach/chapter8/chapter8.md` (SSL/TLS deep dive, handshake step-by-step)*
- [x] **Must Know:** Certificate chain — *Covered in Chapter 8 (PKI, CAs, X.509)*
- [ ] **Must Know:** TLS 1.2 vs TLS 1.3 differences
- [ ] **Should Know:** SNI, ALPN
- [ ] **Should Know:** Certificate pinning

### 5.3 DNS
- [x] **Must Know:** Recursive vs iterative resolution — *Covered in Chapter 2*
- [x] **Must Know:** Record types — *Covered in Chapter 2*
- [x] **Must Know:** DNS hierarchy — *Covered in Chapter 2*
- [ ] **Should Know:** SRV records
- [ ] **Should Know:** TTL, DNS-based load balancing
- [ ] **Nice to Have:** DNSSEC, DoH, DoT

### 5.4 WebSocket
- [ ] **Must Know:** Upgrade handshake — **Not Started**
- [ ] **Must Know:** Full-duplex communication — **Not Started**

### 5.5 gRPC
- [ ] **Should Know:** HTTP/2-based, Protocol Buffers — **Not Started**
- [ ] **Should Know:** Streaming modes — **Not Started**

### 5.6 Other Protocols
- [x] **Should Know:** SMTP, email protocols — *Covered in Chapter 2 (email protocols section)*
- [ ] **Nice to Have:** FTP, SFTP
- [ ] **Nice to Have:** MQTT, AMQP

### ✅ Checklist – Application Layer Protocols
- [x] HTTP/1.1 methods, status codes, headers covered
- [ ] HTTP/2 multiplexing and HTTP/3 QUIC
- [x] TLS handshake explained
- [x] DNS resolution process — recursive vs iterative
- [x] DNS record types known
- [ ] WebSocket upgrade handshake
- [ ] gRPC streaming modes

---

## 6. Socket Programming

### 6.1 Berkeley Sockets API
- [x] **Must Know:** `socket()`, `bind()`, `listen()`, `accept()` — server setup — *Covered in `Beegs-concepts/` (Beej's guide notes + HTTP-client.c implementation)*
- [x] **Must Know:** `connect()`, `send()`, `recv()`, `close()` — client operations — *Covered in HTTP-client.c*
- [x] **Must Know:** `struct sockaddr_in`, `htons()`, `inet_pton()` — *Covered in HTTP-client.c*

### 6.2 TCP Server/Client
- [x] **Must Know:** Blocking TCP client — *HTTP-client.c implements a basic TCP client*
- [ ] **Must Know:** Non-blocking I/O
- [ ] **Must Know:** `select()` — I/O multiplexing
- [ ] **Should Know:** `poll()`, `epoll`
- [ ] **Nice to Have:** `io_uring`

### 6.3 UDP Sockets
- [ ] **Must Know:** `sendto()`, `recvfrom()` — **Not Started**

### 6.4-6.6 Socket Options & Advanced Topics
- [ ] Socket Options — **Not Started**
- [ ] Async I/O Libraries — **Not Started**
- [ ] Advanced Socket Topics — **Not Started**

### ✅ Checklist – Socket Programming
- [x] TCP client implemented with blocking sockets (HTTP-client.c)
- [ ] Non-blocking I/O with `select()` or `poll()`
- [ ] `epoll` server
- [ ] UDP client/server
- [ ] Socket options applied
- [ ] Asio-based async server
- [ ] Unix domain sockets

---

## 7. Network Security

### 7.1 TLS/SSL
- [x] **Must Know:** TLS handshake — *Covered in `TopDownApproach/chapter8/chapter8.md`*
- [x] **Must Know:** X.509 certificates — *Covered in Chapter 8 (public key certification, CAs)*
- [x] **Must Know:** Certificate Authority chain — *Covered in Chapter 8*
- [ ] **Should Know:** Mutual TLS (mTLS)
- [ ] **Should Know:** Certificate pinning
- [ ] **Should Know:** Certificate revocation

### 7.2 PKI
- [x] **Should Know:** Certificate lifecycle — *Covered in Chapter 8 (digital signatures, CAs)*
- [ ] **Should Know:** Self-signed vs CA-signed
- [ ] **Should Know:** Let's Encrypt (ACME protocol)

### 7.3 Common Attacks
- [ ] **Must Know:** SYN flood — **Not Started**
- [ ] **Must Know:** DDoS — **Not Started**
- [x] **Must Know:** MITM — TLS as defense — *Covered in Chapter 8 (intruder categories, attack types)*
- [ ] **Should Know:** DNS poisoning
- [ ] **Should Know:** ARP spoofing

### 7.4-7.6 Firewalls, VPN, Application Security
- [ ] Firewalls & Access Control — **Not Started**
- [ ] VPN & Tunneling — **Not Started**
- [ ] Application-Layer Security (OAuth, JWT) — **Not Started**

> **Additional Coverage in Chapter 8:** Symmetric/asymmetric cryptography, message integrity, digital signatures, MAC, hash functions, nonces/challenge-response, PGP, e-mail security, TLS record protocol.

### ✅ Checklist – Network Security
- [x] TLS handshake explained with certificate chain validation
- [ ] mTLS concept
- [ ] Common attacks and defenses (SYN flood, DDoS)
- [ ] Firewall rules configured
- [ ] VPN concepts
- [ ] OAuth 2.0 / JWT

---

## 8. Network Performance & Debugging
- [ ] Latency Components — **Not Started**
- [ ] Bandwidth & Throughput — **Not Started**
- [ ] Debugging Tools — **Not Started**
- [ ] Common Debugging Scenarios — **Not Started**
- [ ] Performance Tuning — **Not Started**
- [ ] CDN & Load Balancing — **Not Started**

---

## 9. Network Architecture & Design
- [ ] Communication Models — **Not Started**
- [ ] Microservices Networking — **Not Started**
- [ ] API Gateway — **Not Started**
- [ ] Reverse Proxy — **Not Started**
- [ ] Network Partitioning — **Not Started**

---

## 10. Cloud Networking
- [ ] Virtual Networks — **Not Started**
- [ ] Cloud Load Balancers — **Not Started**
- [ ] Cloud DNS — **Not Started**
- [ ] Private Connectivity — **Not Started**
- [ ] Container Networking — **Not Started**

---

## 11. Distributed Systems Networking
- [ ] RPC Frameworks — **Not Started**
- [ ] Serialization Formats — **Not Started**
- [ ] Consensus & Coordination — **Not Started**
- [ ] Gossip Protocols — **Not Started**
- [ ] Clock Synchronization — **Not Started**
- [ ] Network Partitions — **Not Started**

---

## 📈 Overall Progress Estimate

| Priority Level | Covered | Total (est.) | Percentage |
|---------------|---------|--------------|------------|
| Must Know | ~25 | ~55 | ~45% |
| Should Know | ~5 | ~55 | ~9% |
| Nice to Have | 0 | ~20 | 0% |
| **Overall** | **~30** | **~130** | **~23%** |

> **Key Gaps:** Physical/Data Link layer (ARP, VLANs), ICMP/debugging tools, WebSocket, gRPC, Socket programming (only basic TCP client), Performance/Debugging, Cloud Networking, Distributed Systems Networking, Firewalls, VPN. **Strengths:** Strong theoretical foundation from Kurose & Ross textbook — Chapters 1 (fundamentals), 2 (application layer: HTTP, DNS, SMTP), 3 (transport layer: TCP/UDP comprehensive), 4 (network layer: IPv4, routing, NAT), 8 (security: TLS, cryptography, PKI). Practical socket programming started with Beej's guide (HTTP-client.c).
