# Networking Concepts — Mastery Scope for 10+ Years Experience

---

## 📊 Master Progress Tracker

| Section | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|----------------------------------|----------------|------------------|-------------------|---------------|-------|
| Network Fundamentals & Models | | | | | |
| Physical & Data Link Layer | | | | | |
| Network Layer (IP) | | | | | |
| Transport Layer | | | | | |
| Application Layer Protocols | | | | | |
| Socket Programming | | | | | |
| Network Security | | | | | |
| Network Performance & Debugging | | | | | |
| Network Architecture & Design | | | | | |
| Cloud Networking | | | | | |
| Distributed Systems Networking | | | | | |

---

## Table of Contents

1. [Network Fundamentals & OSI/TCP-IP Models](#1-network-fundamentals--ositcp-ip-models)
2. [Physical & Data Link Layer](#2-physical--data-link-layer)
3. [Network Layer (IP)](#3-network-layer-ip)
4. [Transport Layer](#4-transport-layer)
5. [Application Layer Protocols](#5-application-layer-protocols)
6. [Socket Programming](#6-socket-programming)
7. [Network Security](#7-network-security)
8. [Network Performance & Debugging](#8-network-performance--debugging)
9. [Network Architecture & Design](#9-network-architecture--design)
10. [Cloud Networking](#10-cloud-networking)
11. [Distributed Systems Networking](#11-distributed-systems-networking)

---

## 1. Network Fundamentals & OSI/TCP-IP Models

### 1.1 OSI 7-Layer Model
- **Must Know:** Layer responsibilities — Physical, Data Link, Network, Transport, Session, Presentation, Application
- **Must Know:** Encapsulation & de-encapsulation — headers added/removed at each layer
- **Must Know:** Protocol Data Units (PDUs) — bits, frames, packets, segments, data
- **Should Know:** Which protocols operate at which layer

### 1.2 TCP/IP 4-Layer Model
- **Must Know:** Link, Internet, Transport, Application — mapping to OSI
- **Must Know:** Practical relevance — TCP/IP is what the internet actually uses
- **Should Know:** Where OSI vs TCP/IP models diverge

### 1.3 Network Fundamentals
- **Must Know:** Circuit switching vs packet switching
- **Must Know:** Network topologies — star, mesh, ring, bus, hybrid
- **Should Know:** Network devices — routers, switches, hubs, bridges, firewalls, load balancers
- **Should Know:** NAT gateways — purpose, placement

### ✅ Checklist – Network Fundamentals
- [ ] OSI 7-layer model — responsibilities and PDUs at each layer
- [ ] TCP/IP 4-layer model — mapping to OSI understood
- [ ] Encapsulation / de-encapsulation explained
- [ ] Circuit vs packet switching articulated
- [ ] Network devices — roles and placement understood

---

## 2. Physical & Data Link Layer

### 2.1 Ethernet
- **Must Know:** Ethernet frames — structure, MAC addressing, EtherType
- **Must Know:** CSMA/CD (half-duplex), full-duplex switching
- **Should Know:** Frame size, MTU (1500 bytes default), jumbo frames (9000 bytes)

### 2.2 VLANs & Switching
- **Should Know:** VLANs — logical network segmentation, 802.1Q tagging
- **Should Know:** Trunking — carrying multiple VLANs on a single link
- **Should Know:** MAC address table, learning, forwarding, flooding
- **Nice to Have:** Spanning Tree Protocol (STP) — loop prevention
- **Nice to Have:** Link aggregation (LACP)

### 2.3 ARP
- **Must Know:** Address Resolution Protocol — IP to MAC resolution
- **Must Know:** ARP cache, ARP request/reply
- **Should Know:** ARP spoofing/poisoning — security implications
- **Should Know:** Gratuitous ARP

### 2.4 Wireless
- **Nice to Have:** 802.11 standards (a/b/g/n/ac/ax)
- **Nice to Have:** WPA2/WPA3 security
- **Nice to Have:** Channel interference, roaming

### ✅ Checklist – Physical & Data Link Layer
- [ ] Ethernet frame structure understood
- [ ] MAC addressing and switching mechanics clear
- [ ] ARP process understood and debuggable
- [ ] VLANs concept grasped
- [ ] MTU and fragmentation at link layer understood

---

## 3. Network Layer (IP)

### 3.1 IPv4
- **Must Know:** IPv4 addressing — 32-bit, dotted decimal notation
- **Must Know:** Subnetting — subnet masks, CIDR notation (/24, /16, etc.)
- **Must Know:** Private vs public IP ranges (10.0.0.0/8, 172.16.0.0/12, 192.168.0.0/16)
- **Should Know:** Classful addressing (A, B, C) — historical context
- **Should Know:** Variable-length subnet masking (VLSM)

### 3.2 IPv6
- **Should Know:** IPv6 addressing — 128-bit, hex notation, `::`  shorthand
- **Should Know:** Transition mechanisms — dual-stack, tunneling, NAT64/DNS64
- **Nice to Have:** IPv6 neighbor discovery, SLAAC

### 3.3 Routing
- **Must Know:** Routing tables — destination, next hop, interface, metric
- **Must Know:** Longest prefix match rule
- **Must Know:** Static routes vs dynamic routing
- **Should Know:** OSPF — link-state, area-based, Dijkstra's algorithm
- **Should Know:** BGP — path vector, AS relationships, peering, transit
- **Nice to Have:** RIP (distance vector, legacy)
- **Nice to Have:** BGP route selection process, BGP hijacking

### 3.4 ICMP
- **Must Know:** Ping — echo request/reply, RTT measurement
- **Must Know:** Traceroute — TTL expiry, hop-by-hop path discovery
- **Should Know:** ICMP error messages (destination unreachable, time exceeded)
- **Should Know:** Path MTU discovery (PMTUD)

### 3.5 NAT
- **Must Know:** Network Address Translation — SNAT, DNAT, PAT (port address translation)
- **Must Know:** Why NAT exists — IPv4 address exhaustion
- **Should Know:** NAT traversal — STUN, TURN, ICE (for P2P, WebRTC)
- **Should Know:** NAT types — full cone, restricted cone, port-restricted, symmetric

### 3.6 IP Fragmentation & Multicast
- **Should Know:** IP fragmentation — when MTU exceeded, reassembly at destination
- **Should Know:** Don't Fragment (DF) flag, PMTUD
- **Nice to Have:** Multicast — IGMP, multicast addressing (224.0.0.0/4), PIM

### ✅ Checklist – Network Layer
- [ ] IPv4 subnetting — calculate subnet, hosts, broadcast address
- [ ] CIDR notation fluent
- [ ] Routing table reading and longest prefix match understood
- [ ] OSPF & BGP concepts grasped
- [ ] ICMP tools (ping, traceroute) used for debugging
- [ ] NAT types and traversal mechanisms understood

---

## 4. Transport Layer

### 4.1 TCP Deep Dive
- **Must Know:** 3-way handshake — SYN, SYN-ACK, ACK
- **Must Know:** 4-way teardown — FIN, ACK, FIN, ACK
- **Must Know:** TCP state machine — LISTEN, SYN_SENT, ESTABLISHED, FIN_WAIT, TIME_WAIT, CLOSE_WAIT
- **Must Know:** TIME_WAIT — purpose (2×MSL), implications for server restarts

### 4.2 TCP Flow Control
- **Must Know:** Sliding window — advertised window, flow control mechanism
- **Should Know:** Window scaling option — for high-bandwidth networks
- **Should Know:** Receive buffer management, zero window probing

### 4.3 TCP Congestion Control
- **Must Know:** Slow start — exponential growth of congestion window (cwnd)
- **Must Know:** Congestion avoidance — linear growth after ssthresh
- **Must Know:** Fast retransmit — 3 duplicate ACKs trigger retransmission
- **Must Know:** Fast recovery — don't reset to slow start
- **Should Know:** Congestion algorithms — Reno, Cubic (Linux default), BBR (Google)
- **Should Know:** BBR — bandwidth-based, not loss-based; advantages for high-latency links

### 4.4 TCP Options
- **Should Know:** Timestamps — RTT measurement, PAWS
- **Should Know:** SACK (Selective Acknowledgment) — efficient retransmission
- **Should Know:** MSS (Maximum Segment Size) negotiation
- **Should Know:** Window scaling

### 4.5 UDP
- **Must Know:** Connectionless, unreliable, no flow control, no congestion control
- **Must Know:** Use cases — DNS, real-time streaming, gaming, VoIP
- **Must Know:** UDP header — source port, destination port, length, checksum

### 4.6 TCP vs UDP
- **Must Know:** Trade-offs — reliability vs latency, overhead, use cases
- **Must Know:** When to choose TCP vs UDP

### 4.7 QUIC Protocol
- **Should Know:** UDP-based, built-in TLS 1.3, multiplexed streams
- **Should Know:** 0-RTT connection establishment
- **Should Know:** Connection migration (IP change without reconnection)
- **Should Know:** No head-of-line blocking at transport layer

### 4.8 SCTP
- **Nice to Have:** Multi-homing, multi-streaming
- **Nice to Have:** SCTP vs TCP — features comparison

### ✅ Checklist – Transport Layer
- [ ] TCP 3-way handshake & 4-way teardown explained with state diagram
- [ ] TCP state machine — all states and transitions understood
- [ ] TIME_WAIT purpose and implications articulated
- [ ] Congestion control — slow start, congestion avoidance, fast retransmit
- [ ] TCP vs UDP trade-offs clear with real-world examples
- [ ] QUIC protocol fundamentals understood
- [ ] TCP tuning parameters identified

---

## 5. Application Layer Protocols

### 5.1 HTTP
- **Must Know:** HTTP/1.1 — persistent connections, chunked encoding, methods (GET/POST/PUT/DELETE/PATCH)
- **Must Know:** Status codes — 2xx (success), 3xx (redirect), 4xx (client error), 5xx (server error)
- **Must Know:** Headers — Content-Type, Authorization, Cache-Control, Accept, Host
- **Must Know:** HTTP/2 — multiplexing, header compression (HPACK), streams, server push
- **Should Know:** HTTP/3 — QUIC-based, advantages over HTTP/2
- **Should Know:** HTTP methods — idempotency, safety
- **Should Know:** Content negotiation, conditional requests (ETag, If-Modified-Since)

### 5.2 HTTPS & TLS
- **Must Know:** TLS handshake — certificate validation, key exchange, cipher negotiation
- **Must Know:** Certificate chain — server cert → intermediate CA → root CA
- **Must Know:** TLS 1.2 vs TLS 1.3 — differences (1-RTT vs 2-RTT handshake, cipher suite simplification)
- **Should Know:** SNI (Server Name Indication) — multiple certs on one IP
- **Should Know:** ALPN (Application-Layer Protocol Negotiation) — HTTP/2 negotiation
- **Should Know:** Certificate pinning — when and why

### 5.3 DNS
- **Must Know:** Recursive vs iterative resolution
- **Must Know:** Record types — A, AAAA, CNAME, MX, NS, TXT
- **Must Know:** DNS hierarchy — root → TLD → authoritative
- **Should Know:** SRV records — service discovery
- **Should Know:** TTL — caching, propagation delays
- **Should Know:** DNS-based load balancing, failover
- **Nice to Have:** DNSSEC, DNS over HTTPS (DoH), DNS over TLS (DoT)

### 5.4 WebSocket
- **Must Know:** Upgrade handshake (HTTP → WebSocket)
- **Must Know:** Full-duplex communication, persistent connection
- **Should Know:** Framing, opcodes (text, binary, ping, pong, close)
- **Should Know:** Heartbeat mechanisms, reconnection strategies
- **Should Know:** Use cases — real-time apps, chat, live updates

### 5.5 gRPC
- **Should Know:** HTTP/2-based, Protocol Buffers for serialization
- **Should Know:** Streaming modes — unary, server streaming, client streaming, bidirectional
- **Should Know:** Service contracts, code generation
- **Should Know:** Deadlines, metadata, interceptors

### 5.6 Other Protocols
- **Should Know:** SMTP, IMAP, POP3 — email protocol basics
- **Nice to Have:** FTP, SFTP, SCP — file transfer
- **Nice to Have:** MQTT — IoT publish-subscribe
- **Nice to Have:** AMQP — message broker protocol (RabbitMQ)

### ✅ Checklist – Application Layer Protocols
- [ ] HTTP/1.1 methods, status codes, headers mastered
- [ ] HTTP/2 multiplexing and HTTP/3 QUIC understood
- [ ] TLS handshake explained (1.2 and 1.3)
- [ ] DNS resolution process — recursive vs iterative
- [ ] DNS record types memorized
- [ ] WebSocket upgrade handshake and framing understood
- [ ] gRPC streaming modes and protobuf integration explored

---

## 6. Socket Programming

### 6.1 Berkeley Sockets API
- **Must Know:** `socket()`, `bind()`, `listen()`, `accept()` — server setup
- **Must Know:** `connect()`, `send()`, `recv()`, `close()` — client operations
- **Must Know:** `struct sockaddr_in`, `htons()`, `inet_pton()` — address structures

### 6.2 TCP Server/Client
- **Must Know:** Blocking TCP server — accept loop, per-client handling
- **Must Know:** Non-blocking I/O — `O_NONBLOCK`, `fcntl()`
- **Must Know:** `select()` — I/O multiplexing, fd_set, cross-platform
- **Should Know:** `poll()` — no FD_SETSIZE limit, pollfd array
- **Should Know:** `epoll` (Linux) — scalable I/O multiplexing, edge-triggered vs level-triggered
- **Nice to Have:** `io_uring` (Linux) — async I/O, submission/completion queues
- **Nice to Have:** `kqueue` (macOS/BSD)

### 6.3 UDP Sockets
- **Must Know:** `sendto()`, `recvfrom()` — connectionless communication
- **Should Know:** Multicast sockets — `IP_ADD_MEMBERSHIP`
- **Should Know:** Broadcast sockets

### 6.4 Socket Options
- **Must Know:** `SO_REUSEADDR` — bind to address in TIME_WAIT
- **Should Know:** `SO_REUSEPORT` — multiple sockets on same port
- **Should Know:** `TCP_NODELAY` — disable Nagle's algorithm for low latency
- **Should Know:** `SO_KEEPALIVE` — detect dead connections
- **Nice to Have:** `TCP_CORK` — coalesce small writes

### 6.5 Async I/O Libraries
- **Should Know:** Boost.Asio / standalone Asio — async I/O, io_context, handlers
- **Should Know:** libuv — event loop, cross-platform async I/O
- **Nice to Have:** `io_uring` patterns — high-performance async I/O

### 6.6 Advanced Socket Topics
- **Should Know:** Unix domain sockets — `AF_UNIX`, IPC, advantages over TCP loopback
- **Nice to Have:** Raw sockets — crafting packets, packet capture (libpcap)
- **Nice to Have:** Zero-copy I/O — `sendfile()`, `splice()`

### ✅ Checklist – Socket Programming
- [ ] TCP client/server implemented with blocking sockets
- [ ] Non-blocking I/O with `select()` or `poll()` implemented
- [ ] `epoll` server implemented (Linux)
- [ ] UDP client/server with `sendto()`/`recvfrom()` built
- [ ] Socket options (REUSEADDR, NODELAY, KEEPALIVE) applied
- [ ] Asio-based async server explored
- [ ] Unix domain sockets used for IPC

---

## 7. Network Security

### 7.1 TLS/SSL
- **Must Know:** TLS handshake — cipher negotiation, key exchange, certificate validation
- **Must Know:** X.509 certificates — structure, subject, issuer, validity, extensions
- **Must Know:** Certificate Authority (CA) chain — root CA, intermediate CA
- **Should Know:** Mutual TLS (mTLS) — client certificate authentication
- **Should Know:** Certificate pinning — protection against rogue CAs
- **Should Know:** Certificate revocation — CRL, OCSP, OCSP stapling

### 7.2 PKI (Public Key Infrastructure)
- **Should Know:** Certificate lifecycle — generation, signing, distribution, revocation
- **Should Know:** Self-signed certificates vs CA-signed
- **Should Know:** Let's Encrypt — automated certificate issuance (ACME protocol)

### 7.3 Common Attacks
- **Must Know:** SYN flood — TCP handshake exhaustion, SYN cookies defense
- **Must Know:** DDoS — volumetric, protocol, application layer attacks
- **Must Know:** MITM (Man-in-the-Middle) — TLS as defense
- **Should Know:** DNS poisoning / DNS spoofing
- **Should Know:** ARP spoofing — LAN-level attacks
- **Nice to Have:** BGP hijacking — route advertisements, RPKI

### 7.4 Firewalls & Access Control
- **Must Know:** Stateful vs stateless firewalls
- **Should Know:** `iptables` / `nftables` (Linux) — chains, rules, targets
- **Should Know:** Security groups (cloud) — instance-level firewall rules
- **Should Know:** Network ACLs — subnet-level rules

### 7.5 VPN & Tunneling
- **Should Know:** IPSec — transport mode, tunnel mode, IKE
- **Should Know:** WireGuard — modern, simple VPN protocol
- **Nice to Have:** OpenVPN — SSL/TLS-based VPN
- **Nice to Have:** SSH tunneling — port forwarding

### 7.6 Application-Layer Security
- **Must Know:** OAuth 2.0 — authorization framework, flows (authorization code, client credentials)
- **Must Know:** JWT — structure (header, payload, signature), validation
- **Should Know:** Zero trust architecture — micro-segmentation, identity-based access
- **Nice to Have:** Network IDS/IPS — Snort, Suricata (concepts)

### ✅ Checklist – Network Security
- [ ] TLS handshake explained with certificate chain validation
- [ ] mTLS concept and use case understood
- [ ] Common attacks identified and defenses articulated (SYN flood, DDoS, MITM)
- [ ] Firewall rules configured (iptables/security groups)
- [ ] VPN concepts (IPSec, WireGuard) understood
- [ ] OAuth 2.0 / JWT used for API security

---

## 8. Network Performance & Debugging

### 8.1 Latency Components
- **Must Know:** Propagation delay, transmission delay, queuing delay, processing delay
- **Must Know:** Round-trip time (RTT) — measurement, significance
- **Should Know:** Tail latency — p50, p95, p99 significance
- **Should Know:** Bandwidth-delay product — window sizing

### 8.2 Bandwidth & Throughput
- **Must Know:** Bandwidth vs throughput — capacity vs actual transfer rate
- **Should Know:** Bottleneck identification — is it bandwidth, latency, or processing?
- **Should Know:** TCP throughput formula — window size / RTT

### 8.3 Debugging Tools
- **Must Know:** `ping` — reachability, RTT measurement
- **Must Know:** `traceroute` / `mtr` — path discovery, hop-by-hop latency
- **Must Know:** `netstat` / `ss` — connection state, socket statistics
- **Must Know:** `tcpdump` — packet capture, filtering
- **Should Know:** Wireshark — graphical packet analysis, stream following
- **Should Know:** `nmap` — port scanning, service detection
- **Should Know:** `dig` / `nslookup` — DNS resolution debugging
- **Should Know:** `iperf` / `iperf3` — bandwidth measurement

### 8.4 Common Debugging Scenarios
- **Must Know:** Connection timeouts — firewall, routing, DNS issues
- **Must Know:** Connection refused — service not running, wrong port
- **Should Know:** RST packets — what causes them
- **Should Know:** Retransmissions — identifying via tcpdump/Wireshark
- **Should Know:** Window size issues — TCP zero window, window scaling

### 8.5 Performance Tuning
- **Should Know:** Socket buffer sizes — `SO_RCVBUF`, `SO_SNDBUF`
- **Should Know:** TCP tuning — `net.core.somaxconn`, `net.ipv4.tcp_max_syn_backlog`
- **Should Know:** Connection pooling — reducing handshake overhead
- **Should Know:** Keep-alive — HTTP and TCP level

### 8.6 CDN & Load Balancing
- **Must Know:** CDN — edge caching, reduced latency, global distribution
- **Must Know:** Load balancing — L4 (TCP/UDP) vs L7 (HTTP)
- **Must Know:** LB algorithms — round-robin, least connections, consistent hashing
- **Should Know:** Health checks — active vs passive, failover
- **Should Know:** Anycast — single IP, multiple locations

### ✅ Checklist – Network Performance & Debugging
- [ ] Latency components articulated (propagation, transmission, queuing, processing)
- [ ] tcpdump / Wireshark used to debug real network issues
- [ ] traceroute / mtr used for path analysis
- [ ] ss / netstat used for connection state inspection
- [ ] TCP tuning parameters known and applied
- [ ] CDN and load balancing strategies understood
- [ ] Connection pooling and keep-alive configured

---

## 9. Network Architecture & Design

### 9.1 Communication Models
- **Must Know:** Client-server architecture
- **Should Know:** Peer-to-peer architecture — DHT, gossip
- **Should Know:** Event-driven architecture — network implications

### 9.2 Microservices Networking
- **Must Know:** Service-to-service communication — sync (REST/gRPC) vs async (messaging)
- **Should Know:** Service mesh — Istio/Envoy, sidecar proxy pattern
- **Should Know:** Service discovery — DNS-based, registry-based (Consul, Eureka)
- **Should Know:** Circuit breaker, retry, timeout patterns

### 9.3 API Gateway
- **Must Know:** Routing, request transformation
- **Should Know:** Rate limiting, authentication, throttling at gateway
- **Should Know:** API gateway vs reverse proxy vs load balancer

### 9.4 Reverse Proxy
- **Must Know:** Nginx, HAProxy — connection handling, routing
- **Should Know:** SSL termination at proxy
- **Should Know:** Connection pooling between proxy and backend

### 9.5 Network Partitioning
- **Should Know:** CAP theorem implications — network partition handling
- **Should Know:** Split-brain scenarios — detection, fencing, resolution
- **Nice to Have:** Partition-tolerant system design

### ✅ Checklist – Network Architecture & Design
- [ ] Client-server vs P2P trade-offs articulated
- [ ] Service mesh concept understood (data plane, control plane)
- [ ] API gateway configured with rate limiting
- [ ] Reverse proxy (Nginx/HAProxy) set up
- [ ] Network partition handling strategies known

---

## 10. Cloud Networking

### 10.1 Virtual Networks
- **Must Know:** VPC — virtual private cloud, isolation
- **Must Know:** Subnets — public, private, availability zones
- **Should Know:** Route tables, internet gateways, NAT gateways
- **Should Know:** Security groups vs network ACLs

### 10.2 Cloud Load Balancers
- **Should Know:** ALB (L7) — HTTP routing, path-based, host-based
- **Should Know:** NLB (L4) — TCP/UDP, ultra-low latency
- **Should Know:** GLB — global, anycast-based
- **Should Know:** Trade-offs between ALB, NLB, GLB

### 10.3 Cloud DNS
- **Should Know:** Route 53, Cloud DNS — DNS-as-a-service
- **Should Know:** Failover routing, geolocation routing, weighted routing
- **Should Know:** Health checks for DNS failover

### 10.4 Private Connectivity
- **Nice to Have:** VPN (site-to-site) — connecting on-prem to cloud
- **Nice to Have:** Direct Connect / ExpressRoute / Cloud Interconnect
- **Nice to Have:** VPC peering, transit gateway

### 10.5 Container Networking
- **Should Know:** Docker networking — bridge, host, overlay, macvlan
- **Should Know:** Kubernetes networking — pod networking, CNI plugins
- **Should Know:** Kubernetes Services — ClusterIP, NodePort, LoadBalancer
- **Should Know:** Kubernetes Ingress — L7 routing, TLS termination
- **Nice to Have:** Service mesh in Kubernetes (Istio, Linkerd)

### ✅ Checklist – Cloud Networking
- [ ] VPC, subnets, route tables configured
- [ ] Security groups and NACLs set up
- [ ] Cloud load balancer deployed (ALB/NLB)
- [ ] DNS failover configured
- [ ] Kubernetes networking (Services, Ingress) understood
- [ ] Container networking modes grasped

---

## 11. Distributed Systems Networking

### 11.1 RPC Frameworks
- **Must Know:** gRPC — service definitions, protobuf, streaming, deadlines
- **Should Know:** Thrift — Facebook's RPC, multi-language
- **Nice to Have:** Cap'n Proto — zero-copy serialization

### 11.2 Serialization Formats
- **Must Know:** Protocol Buffers — schema-based, efficient binary encoding
- **Should Know:** FlatBuffers — zero-copy access, no unpacking
- **Should Know:** JSON — human-readable, widely supported, verbose
- **Nice to Have:** MessagePack — binary JSON
- **Nice to Have:** CBOR — Concise Binary Object Representation

### 11.3 Consensus & Coordination
- **Should Know:** Raft — leader election, log replication, safety
- **Should Know:** Paxos — classic consensus (conceptual)
- **Should Know:** Network assumptions — synchronous, asynchronous, partially synchronous
- **Nice to Have:** ZAB (ZooKeeper Atomic Broadcast)

### 11.4 Gossip Protocols
- **Should Know:** Epidemic broadcast — membership, failure detection
- **Should Know:** SWIM protocol — scalable membership
- **Nice to Have:** Crdt-based eventual consistency

### 11.5 Clock Synchronization
- **Should Know:** NTP — Network Time Protocol, accuracy limitations
- **Should Know:** Logical clocks — Lamport timestamps, happened-before relation
- **Should Know:** Vector clocks — causality tracking
- **Nice to Have:** PTP (Precision Time Protocol)
- **Nice to Have:** Hybrid logical clocks (HLC)

### 11.6 Network Partitions
- **Must Know:** Detection — heartbeats, timeouts, phi-accrual failure detector
- **Should Know:** Handling — quorum-based decisions, read/write availability trade-offs
- **Should Know:** Recovery — state reconciliation, anti-entropy protocols

### ✅ Checklist – Distributed Systems Networking
- [ ] gRPC service implemented with protobuf
- [ ] Serialization formats compared (protobuf vs JSON vs FlatBuffers)
- [ ] Raft consensus algorithm understood
- [ ] Gossip protocol concept grasped
- [ ] Lamport / vector clocks understood
- [ ] Network partition detection and handling strategies known
