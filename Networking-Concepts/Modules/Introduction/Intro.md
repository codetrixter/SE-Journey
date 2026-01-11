# Introduction to Computer Networks and the Internet

> **Reference:** *Computer Networking: A Top-Down Approach* by James F. Kurose and Keith W. Ross

---

## 1. What is the Internet?

### 1.1 A Nuts-and-Bolts Description

The Internet is a **computer network** that interconnects billions of computing devices worldwide.

- **End Systems (Hosts):** Devices connected to the Internet (PCs, smartphones, servers, IoT devices).
- **Communication Links:** Physical media connecting devices (fiber optics, copper wire, radio spectrum).
- **Packet Switches:** Forward packets (chunks of data) toward destinations.
  - **Routers:** Used in the network core.
  - **Link-layer Switches:** Used in access networks.

```
┌──────────┐      ┌──────────┐      ┌──────────┐
│   Host   │──────│  Router  │──────│   Host   │
└──────────┘      └──────────┘      └──────────┘
     │                  │                  │
     └──────────────────┴──────────────────┘
              Communication Links
```

- **ISPs (Internet Service Providers):** Provide access to end systems (residential, corporate, university ISPs).
- **Protocols:** Control sending/receiving of information (TCP, IP, HTTP, etc.).
- **Internet Standards:** Developed by IETF (Internet Engineering Task Force) as **RFCs** (Request for Comments).

### 1.2 A Services Description

The Internet as an **infrastructure providing services to applications**:

- **Distributed Applications:** Run on end systems, exchange data (email, web, streaming, gaming).
- **Socket Interface:** API that applications use to send/receive data over the Internet.

---

## 2. The Network Edge

### 2.1 End Systems and Access Networks

**End systems** connect to the Internet via **access networks**.

| Access Type | Description | Speed |
|-------------|-------------|-------|
| **DSL** | Uses existing telephone line | Up to 52 Mbps down, 16 Mbps up |
| **Cable** | Uses cable TV infrastructure | Up to 1 Gbps down |
| **FTTH** | Fiber to the Home | Up to 1 Gbps+ |
| **Ethernet** | Enterprise/Home LAN | 100 Mbps - 10 Gbps |
| **WiFi** | Wireless LAN (802.11) | Up to several Gbps |
| **Cellular** | 4G LTE / 5G | Up to several Gbps |

```
                    ┌─────────────────┐
                    │   Internet      │
                    └────────┬────────┘
                             │
              ┌──────────────┼──────────────┐
              │              │              │
        ┌─────┴─────┐  ┌─────┴─────┐  ┌─────┴─────┐
        │ Home Net  │  │Enterprise │  │  Mobile   │
        │  (WiFi)   │  │ (Ethernet)│  │   (5G)    │
        └───────────┘  └───────────┘  └───────────┘
```

### 2.2 Physical Media

| Media Type | Category | Characteristics |
|------------|----------|-----------------|
| Twisted-pair copper | Guided | Cheap, 10 Mbps - 10 Gbps |
| Coaxial cable | Guided | Shared medium, broadband |
| Fiber optics | Guided | High speed, low attenuation |
| Radio (WiFi, Cellular) | Unguided | No physical wire, broadcast |
| Satellite | Unguided | High latency, wide coverage |

---

## 3. The Network Core

The mesh of **packet switches** and **links** that interconnect end systems.

### 3.1 Packet Switching

Data is broken into **packets** that are sent independently through the network.

**Key Concepts:**
- **Store-and-Forward:** Entire packet must arrive at router before it can be transmitted to next link.
- **Queuing Delays:** Packets wait in output buffer if link is busy.
- **Packet Loss:** Occurs when buffer overflows.

```
┌────────┐    Packet 1    ┌────────┐    Packet 1    ┌────────┐
│ Source │ ────────────▶  │ Router │ ────────────▶  │  Dest  │
└────────┘    Packet 2    └────────┘    Packet 2    └────────┘
              ─────────▶   (Queue)     ─────────▶
```

### 3.2 Circuit Switching (Comparison)

| Feature | Packet Switching | Circuit Switching |
|---------|------------------|-------------------|
| Resource allocation | On-demand | Reserved |
| Efficiency | Better for bursty data | Guaranteed bandwidth |
| Delay | Variable | Constant |
| Example | Internet | Traditional telephone |

### 3.3 Network of Networks

The Internet is a **network of networks** with a hierarchical structure:

1. **Tier-1 ISPs:** Global coverage, peer with each other (e.g., AT&T, NTT).
2. **Regional ISPs:** Connect to Tier-1 ISPs.
3. **Access ISPs:** Provide end-user connectivity.
4. **IXPs (Internet Exchange Points):** Allow ISPs to peer directly.
5. **Content Provider Networks:** Private networks (e.g., Google, Netflix).

```
            ┌─────────────────────────────┐
            │       Tier-1 ISPs           │
            │    (Global Backbone)        │
            └──────────┬──────────────────┘
                       │
         ┌─────────────┼─────────────┐
         │             │             │
    ┌────┴────┐   ┌────┴────┐   ┌────┴────┐
    │Regional │   │Regional │   │ Content │
    │  ISP    │   │  ISP    │   │Provider │
    └────┬────┘   └────┬────┘   └─────────┘
         │             │
    ┌────┴────┐   ┌────┴────┐
    │ Access  │   │ Access  │
    │  ISP    │   │  ISP    │
    └─────────┘   └─────────┘
```

---

## 4. Delay, Loss, and Throughput

### 4.1 Types of Delay

**Total Nodal Delay = d_proc + d_queue + d_trans + d_prop**

| Delay Type | Description | Formula |
|------------|-------------|---------|
| **Processing (d_proc)** | Check bit errors, determine output link | Microseconds |
| **Queuing (d_queue)** | Wait in buffer for transmission | Variable |
| **Transmission (d_trans)** | Push all packet bits onto link | L/R (L = packet length, R = link rate) |
| **Propagation (d_prop)** | Signal travel time | d/s (d = distance, s = propagation speed) |

### 4.2 Queuing Delay and Packet Loss

- **Traffic Intensity = La/R** (L = packet size, a = arrival rate, R = link bandwidth)
  - La/R ≈ 0: Small queuing delay
  - La/R → 1: Large queuing delay
  - La/R > 1: Infinite delay (queue grows unbounded)

- **Packet Loss:** When queue (buffer) is full, arriving packets are dropped.

### 4.3 End-to-End Delay

```
d_end-to-end = N × (d_proc + d_trans + d_prop)
```
Where N = number of links between source and destination.

### 4.4 Throughput

- **Instantaneous Throughput:** Rate at a given instant.
- **Average Throughput:** F/T (F = file size, T = transfer time).
- **Bottleneck Link:** Link with minimum transmission rate limits end-to-end throughput.

```
Throughput = min{R1, R2, ..., Rn}
```

---

## 5. Protocol Layers and Service Models

### 5.0 ***Even though OCI and TCP/IP networking protocol models are present but in real wrold scenarios almost everywhere TCP/IP is used.***

### 5.1 Layered Architecture

Networking uses a **layered approach** to manage complexity.

#### Internet Protocol Stack (TCP/IP Model)

| Layer | Function | Protocols/Examples |
|-------|----------|-------------------|
| **Application** | Network applications | HTTP, SMTP, FTP, DNS |
| **Transport** | Process-to-process data transfer | TCP, UDP |
| **Network** | Routing datagrams from source to dest | IP, ICMP |
| **Link** | Data transfer between neighbors | Ethernet, WiFi |
| **Physical** | Bits on the wire | Signals, cables |

#### OSI Model (7 Layers)

| Layer | Function |
|-------|----------|
| 7. Application | User interface |
| 6. Presentation | Data formatting, encryption |
| 5. Session | Session management |
| 4. Transport | End-to-end communication |
| 3. Network | Routing |
| 2. Data Link | Node-to-node delivery |
| 1. Physical | Bit transmission |

### 5.2 Encapsulation

```
┌─────────────────────────────────────────────────────────┐
│ Application Layer: MESSAGE                              │
├─────────────────────────────────────────────────────────┤
│ Transport Layer: SEGMENT = [Header | MESSAGE]           │
├─────────────────────────────────────────────────────────┤
│ Network Layer: DATAGRAM = [Header | SEGMENT]            │
├─────────────────────────────────────────────────────────┤
│ Link Layer: FRAME = [Header | DATAGRAM | Trailer]       │
└─────────────────────────────────────────────────────────┘
```

Each layer adds its own **header** (and sometimes trailer) to the data from the layer above.

---

## 6. Networks Under Attack (Security)

### Types of Attacks

| Attack Type | Description |
|-------------|-------------|
| **Malware** | Viruses, worms, trojans infecting systems |
| **DoS (Denial of Service)** | Overwhelm target with traffic |
| **Packet Sniffing** | Intercept packets on shared medium |
| **IP Spoofing** | Inject packets with false source address |
| **Man-in-the-Middle** | Intercept and alter communication |

### Defense Mechanisms
- **Authentication:** Verify identity
- **Confidentiality:** Encryption
- **Integrity:** Detect tampering
- **Firewalls:** Filter traffic

---

## 7. History of Computer Networking

| Era | Key Developments |
|-----|------------------|
| **1960s** | Packet switching concept (Kleinrock), ARPAnet begins |
| **1970s** | ALOHAnet, Ethernet, TCP/IP development |
| **1980s** | DNS, TCP/IP adopted, NSFnet |
| **1990s** | World Wide Web (Tim Berners-Lee), commercial Internet |
| **2000s** | Broadband, WiFi, P2P, social networks |
| **2010s+** | Cloud computing, mobile Internet, IoT, 5G |

---

## Key Takeaways

1. The Internet is a **network of networks** connecting billions of devices.
2. Data is transmitted as **packets** through **packet switches** (routers, switches).
3. **Protocols** define the rules for communication (TCP/IP is the core).
4. **Layered architecture** simplifies design and implementation.
5. **Delay, loss, and throughput** are key performance metrics.
6. Security is a critical concern in modern networking.

---

## Quick Reference

```
End System ──► Access Network ──► Network Core ──► Access Network ──► End System
    │                                                                      │
    └──────────────────── Packet Switching ────────────────────────────────┘
```

**Key Formulas:**
- Transmission Delay: `d_trans = L / R`
- Propagation Delay: `d_prop = d / s`
- Traffic Intensity: `La / R`
- Throughput: `min{R1, R2, ..., Rn}`