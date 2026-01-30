# Chapter 1: Computer Networks and the Internet

## 1.1 What Is the Internet?

### 1.1.1 A Nuts-and-Bolts Description

The Internet is a **computer network** that interconnects billions of computing devices throughout the world. These devices are called **hosts** or **end systems**.

- **End systems** are connected together by a network of **communication links** and **packet switches**
- Different links can transmit data at different rates (**transmission rate** measured in bits/second)
- **Packets**: When one end system sends data to another, it segments the data and adds header bytes to each segment
- **Packet switches**: Take a packet arriving on one of its incoming communication links and forward it on one of its outgoing communication links
  - Two most prominent types: **routers** and **link-layer switches**
- **Route/Path**: The sequence of communication links and packet switches traversed by a packet

**Key Components:**

| Component | Description |
|-----------|-------------|
| End Systems (Hosts) | Devices connected to the Internet (computers, smartphones, IoT devices) |
| Communication Links | Physical media (fiber optic, copper wire, radio spectrum) |
| Packet Switches | Forward packets toward destinations (routers, switches) |
| ISPs | Internet Service Providers - provide network access |
| Protocols | Rules governing data transmission (TCP, IP, HTTP) |

### 1.1.2 A Services Description

The Internet can also be described as an **infrastructure that provides services to applications**.

- **Distributed applications**: Applications that involve multiple end systems exchanging data (email, web browsing, streaming)
- End systems attached to the Internet provide a **socket interface**
- The **socket interface** specifies how a program running on one end system asks the Internet infrastructure to deliver data to a destination program

### 1.1.3 What Is a Protocol?

> *"A protocol defines the format and the order of messages exchanged between two or more communicating entities, as well as the actions taken on the transmission and/or receipt of a message or other event."*

**Human Analogy:**
1. "Hi" → Greeting initiates communication
2. "Hi" → Response acknowledges
3. "Got the time?" → Request for information
4. "2:00" → Response with information

**Network Protocol Example (TCP Connection):**
1. Client sends **TCP connection request**
2. Server responds with **TCP connection reply**
3. Client sends **GET request** for web page
4. Server sends the **file/response**

---

## 1.2 The Network Edge

The **network edge** consists of end systems (hosts) that sit at the "edge" of the Internet.

### 1.2.1 Access Networks

**Access network**: The network that physically connects an end system to the first router (edge router) on a path to another end system.

#### Home Access Networks

| Type | Technology | Downstream Speed | Upstream Speed |
|------|------------|------------------|----------------|
| **DSL** | Digital Subscriber Line (telephone line) | Up to 52 Mbps | Up to 16 Mbps |
| **Cable** | Hybrid Fiber Coax (HFC) | Up to 1 Gbps | Up to 100 Mbps |
| **FTTH** | Fiber to the Home | Up to 1 Gbps | Up to 1 Gbps |
| **5G Fixed Wireless** | Radio spectrum | Up to 1 Gbps | Varies |
| **Satellite** | Satellite links | Up to 100 Mbps | Limited |

**DSL (Digital Subscriber Line):**
- Uses existing telephone line to exchange data with **DSLAM** (DSL Access Multiplexer)
- Asymmetric access: downstream faster than upstream
- Uses **frequency-division multiplexing** to separate channels

**Cable Internet:**
- Uses cable television's existing infrastructure
- **Shared broadcast medium**: All packets sent by head end travel downstream on every link

**FTTH (Fiber to the Home):**
- Provides optical fiber path from CO (Central Office) directly to home
- Two competing architectures: **AON** (Active Optical Networks) and **PON** (Passive Optical Networks)

#### Enterprise and Home Networks

- **Ethernet**: Most prevalent LAN technology
  - Typically 100 Mbps to 10 Gbps
  - End systems connect to Ethernet switch
- **WiFi (802.11)**: Wireless LAN technology
  - Users transmit/receive packets to/from an **access point**
  - Connected to enterprise's wired network

### 1.2.2 Physical Media

**Physical media** fall into two categories:
1. **Guided media**: Signals propagate in a solid medium (fiber optic, copper wire)
2. **Unguided media**: Signals propagate freely (wireless, satellite)

| Medium | Type | Characteristics |
|--------|------|-----------------|
| **Twisted-Pair Copper Wire** | Guided | Cheapest, most common, used in LANs |
| **Coaxial Cable** | Guided | Shared medium, used in cable TV |
| **Fiber Optics** | Guided | High bandwidth, low attenuation, immune to EMI |
| **Terrestrial Radio** | Unguided | No physical wire needed, penetrates walls |
| **Satellite Radio** | Unguided | Geostationary (~280ms delay) or LEO |

---

## 1.3 The Network Core

The **network core** is the mesh of packet switches and links that interconnects the Internet's end systems.

### 1.3.1 Packet Switching

**Packet switching**: End systems exchange **messages** by breaking them into smaller chunks called **packets**.

#### Store-and-Forward Transmission

- The packet switch must receive the **entire packet** before it can begin to transmit the first bit of the packet onto the outbound link
- **Store-and-forward delay**: L/R (packet length / transmission rate)

**End-to-End Delay (N links, no propagation delay):**
```
d_end-to-end = N × (L/R)
```

#### Queuing Delays and Packet Loss

- Each packet switch has an **output buffer** (output queue)
- **Queuing delay**: Time packets wait in the buffer
- **Packet loss**: Occurs when buffer is full and arriving packets are dropped

#### Forwarding Tables and Routing Protocols

- **Forwarding table**: Maps destination addresses to outbound links
- **Routing protocols**: Automatically set forwarding tables (e.g., BGP, OSPF)

### 1.3.2 Circuit Switching

**Circuit switching**: Resources along a path are **reserved** for the duration of the communication session.

**Key Characteristics:**
- Dedicated end-to-end connection
- Guaranteed constant rate
- Resources idle if not used by the connection

#### Multiplexing in Circuit-Switched Networks

| Technique | Description |
|-----------|-------------|
| **FDM** (Frequency-Division Multiplexing) | Frequency spectrum divided among connections |
| **TDM** (Time-Division Multiplexing) | Time divided into frames and slots |

### 1.3.3 Packet Switching vs. Circuit Switching

| Aspect | Packet Switching | Circuit Switching |
|--------|------------------|-------------------|
| **Resource Allocation** | On-demand | Reserved |
| **Efficiency** | Better for bursty data | Better for continuous streams |
| **Simplicity** | Simpler, no setup | Requires call setup |
| **Sharing** | Statistical multiplexing | Dedicated resources |
| **Delay** | Variable (queuing) | Constant |

**Why Packet Switching Wins:**
- More efficient for **bursty traffic** (typical of Internet applications)
- **Statistical multiplexing**: Allows more users to share resources
- Simpler and less costly to implement

---

## 1.4 Delay, Loss, and Throughput in Packet-Switched Networks

### 1.4.1 Overview of Delay in Packet-Switched Networks

**Total nodal delay** consists of four components:

```
d_nodal = d_proc + d_queue + d_trans + d_prop
```

| Delay Type | Symbol | Description | Formula |
|------------|--------|-------------|---------|
| **Processing Delay** | d_proc | Time to examine packet header, determine outbound link | Microseconds |
| **Queuing Delay** | d_queue | Time waiting in buffer | Variable |
| **Transmission Delay** | d_trans | Time to push all packet bits onto link | L/R |
| **Propagation Delay** | d_prop | Time for bit to travel from source to destination | d/s |

Where:
- `L` = Packet length (bits)
- `R` = Transmission rate (bits/sec)
- `d` = Distance between routers
- `s` = Propagation speed (~2×10⁸ m/s for fiber)

### 1.4.2 Queuing Delay and Packet Loss

**Traffic intensity**: `La/R`
- `a` = average packet arrival rate (packets/sec)
- `L` = packet length (bits)
- `R` = transmission rate (bits/sec)

**Rules of Thumb:**
- `La/R ≤ 1`: Average queuing delay is small
- `La/R → 1`: Queuing delay grows rapidly
- `La/R > 1`: Queue grows without bound (system unstable)

**Packet Loss:**
- Occurs when packets arrive to find a **full queue**
- Lost packet may be **retransmitted** by the source or not at all

### 1.4.3 End-to-End Delay

For N-1 routers between source and destination:
```
d_end-to-end = N × (d_proc + d_trans + d_prop)
```

**Traceroute**: Tool to measure delays along the path

### 1.4.4 Throughput in Computer Networks

**Throughput**: Rate (bits/sec) at which bits are transferred between sender and receiver.

- **Instantaneous throughput**: Rate at a given instant
- **Average throughput**: Rate over a longer period

**Bottleneck link**: The link with the minimum transmission rate on the end-to-end path.

```
Throughput = min{R₁, R₂, ..., Rₙ}
```

---

## 1.5 Protocol Layers and Their Service Models

### 1.5.1 Layered Architecture

**Protocol layering** provides:
- **Modularity**: Easier to update/change components
- **Structure**: Organized way to discuss network components

#### The Internet Protocol Stack (5 Layers)

| Layer | Name | Function | Protocols/Examples |
|-------|------|----------|-------------------|
| 5 | **Application** | Network applications and protocols | HTTP, SMTP, FTP, DNS |
| 4 | **Transport** | Transport app-layer messages between endpoints | TCP, UDP |
| 3 | **Network** | Move packets (datagrams) from host to host | IP, routing protocols |
| 2 | **Link** | Move frames from one node to adjacent node | Ethernet, WiFi, PPP |
| 1 | **Physical** | Move individual bits within a frame | Physical media |

#### The OSI Model (7 Layers)

The **OSI (Open Systems Interconnection)** model adds two layers between Application and Transport:

| Layer | Name | Function |
|-------|------|----------|
| 7 | Application | User interface |
| 6 | **Presentation** | Data compression, encryption, description |
| 5 | **Session** | Session management, synchronization |
| 4 | Transport | End-to-end communication |
| 3 | Network | Logical addressing, routing |
| 2 | Data Link | Physical addressing, framing |
| 1 | Physical | Bit transmission |

### 1.5.2 Encapsulation

As data moves down the protocol stack, each layer adds its own **header information**:

```
Application Layer: Message (M)
                      ↓
Transport Layer:  Segment = Transport Header + M (Ht | M)
                      ↓
Network Layer:    Datagram = Network Header + Segment (Hn | Ht | M)
                      ↓
Link Layer:       Frame = Link Header + Datagram (Hl | Hn | Ht | M)
                      ↓
Physical Layer:   Bits transmitted over physical medium
```

**Key Terms:**
- **Message**: Application-layer data unit
- **Segment**: Transport-layer data unit
- **Datagram**: Network-layer data unit
- **Frame**: Link-layer data unit

---

## 1.6 Networks Under Attack

### Types of Security Threats

#### 1. Malware
- **Viruses**: Require user interaction to infect device
- **Worms**: Self-replicating, can enter without user interaction
- **Botnet**: Network of compromised devices controlled by attackers

#### 2. Denial-of-Service (DoS) Attacks

Makes network, host, or infrastructure unusable by legitimate users.

| Attack Type | Description |
|-------------|-------------|
| **Vulnerability Attack** | Exploits software vulnerabilities |
| **Bandwidth Flooding** | Sends massive traffic to overwhelm target |
| **Connection Flooding** | Establishes many half-open TCP connections |

**Distributed DoS (DDoS)**: Attack from multiple coordinated sources (often botnets)

#### 3. Packet Sniffing
- Passive receiver captures copies of packets
- Particularly easy on **broadcast media** (WiFi, shared Ethernet)
- Defense: **Encryption**

#### 4. IP Spoofing
- Attacker injects packets with false source address
- Defense: **End-point authentication**

#### 5. Man-in-the-Middle Attack
- Attacker intercepts and potentially modifies communication between two parties

---

## 1.7 History of Computer Networking and the Internet

### Timeline of Key Developments

| Era | Development |
|-----|-------------|
| **1960s** | Packet switching concepts developed (Kleinrock, Baran, Davies) |
| **1969** | ARPAnet - first packet-switched network (4 nodes) |
| **1972** | First email program, ARPAnet demonstrated publicly |
| **1974** | TCP proposed by Cerf and Kahn |
| **1983** | TCP/IP deployed on ARPAnet |
| **1983** | DNS developed |
| **1989** | World Wide Web invented by Tim Berners-Lee |
| **1990s** | Commercialization of the Internet |
| **2000s** | Broadband access, wireless networks proliferate |
| **2010s** | Cloud computing, mobile Internet, IoT emergence |
| **2020s** | 5G, edge computing, increased cybersecurity focus |

### Key Principles Established

1. **End-to-end principle**: Intelligence at the edges, simple core
2. **Layered architecture**: Modularity through protocol layers
3. **Packet switching**: Efficient resource sharing
4. **Open standards**: Protocols developed through RFC process

---

## Key Terminology Glossary

| Term | Definition |
|------|------------|
| **Host/End System** | Device at the edge of the network |
| **Packet** | Unit of data transmitted over the network |
| **Router** | Packet switch operating at network layer |
| **Switch** | Packet switch operating at link layer |
| **Protocol** | Rules governing communication |
| **ISP** | Internet Service Provider |
| **Bandwidth** | Capacity of a communication link |
| **Throughput** | Actual rate of successful data delivery |
| **Latency** | Total delay from source to destination |
| **RTT** | Round-Trip Time |

---

## Summary

### Key Takeaways

1. **The Internet is a network of networks**: It consists of end systems connected through a hierarchy of ISPs, using packet switching to share communication links efficiently through statistical multiplexing.

2. **Protocols are essential**: Protocols define the rules for communication at each layer. The Internet protocol stack (Application, Transport, Network, Link, Physical) provides a layered architecture that enables modularity and interoperability.

3. **Delay has multiple components**: Total delay = processing + queuing + transmission + propagation. Understanding these components is crucial for network performance analysis.

4. **Packet switching vs. circuit switching**: Packet switching offers better efficiency for bursty Internet traffic through statistical multiplexing, while circuit switching guarantees dedicated resources but wastes capacity during idle periods.

5. **Security is a fundamental concern**: Networks face threats including malware, DoS attacks, packet sniffing, IP spoofing, and man-in-the-middle attacks. Defense mechanisms include encryption, authentication, and firewalls.

---

## Quick Reference Formulas

```
Transmission Delay:     d_trans = L/R
Propagation Delay:      d_prop = d/s
End-to-End Delay:       d_e2e = N × (d_proc + d_trans + d_prop)
Traffic Intensity:      ρ = La/R
Throughput:             min{R₁, R₂, ..., Rₙ} (bottleneck link)
```

---

*Notes compiled from "Computer Networking: A Top-Down Approach" by Kurose and Ross*
