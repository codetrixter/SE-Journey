# 📘 Chapter 3 — The Transport Layer

### *Computer Networking: A Top‑Down Approach*

> **Goal:** Understand how the transport layer provides logical communication between
> application processes running on different hosts, and master the design principles
> behind UDP, reliable data transfer, TCP, flow control, and congestion control.

---

## 📑 Table of Contents

1. [Transport‑Layer Services & Overview](#1-transport-layer-services--overview)
   - 1.1 [Relationship Between Transport and Network Layers](#11-relationship-between-transport-and-network-layers)
   - 1.2 [Overview of the Transport Layer in the Internet](#12-overview-of-the-transport-layer-in-the-internet)
2. [Multiplexing and Demultiplexing](#2-multiplexing-and-demultiplexing)
   - 2.1 [How Demultiplexing Works](#21-how-demultiplexing-works)
   - 2.2 [Connectionless (UDP) Demultiplexing](#22-connectionless-udp-demultiplexing)
   - 2.3 [Connection‑Oriented (TCP) Demultiplexing](#23-connection-oriented-tcp-demultiplexing)
3. [Connectionless Transport: UDP](#3-connectionless-transport-udp)
   - 3.1 [Why Use UDP?](#31-why-use-udp)
   - 3.2 [UDP Segment Structure](#32-udp-segment-structure)
   - 3.3 [UDP Checksum](#33-udp-checksum)
4. [Principles of Reliable Data Transfer](#4-principles-of-reliable-data-transfer)
   - 4.1 [Building a Reliable Data Transfer Protocol](#41-building-a-reliable-data-transfer-protocol)
   - 4.2 [rdt 1.0 — Reliable Transfer over a Perfectly Reliable Channel](#42-rdt-10--reliable-transfer-over-a-perfectly-reliable-channel)
   - 4.3 [rdt 2.0 — Channel with Bit Errors (Stop‑and‑Wait with ACK/NAK)](#43-rdt-20--channel-with-bit-errors-stop-and-wait-with-acknak)
   - 4.4 [rdt 2.1 — Handling Garbled ACKs/NAKs](#44-rdt-21--handling-garbled-acknaks)
   - 4.5 [rdt 2.2 — NAK‑Free Protocol](#45-rdt-22--nak-free-protocol)
   - 4.6 [rdt 3.0 — Channels with Errors AND Loss (Timeouts)](#46-rdt-30--channels-with-errors-and-loss-timeouts)
   - 4.7 [Pipelined Reliable Data Transfer](#47-pipelined-reliable-data-transfer)
   - 4.8 [Go‑Back‑N (GBN)](#48-go-back-n-gbn)
   - 4.9 [Selective Repeat (SR)](#49-selective-repeat-sr)
5. [Connection‑Oriented Transport: TCP](#5-connection-oriented-transport-tcp)
   - 5.1 [The TCP Connection](#51-the-tcp-connection)
   - 5.2 [TCP Segment Structure](#52-tcp-segment-structure)
   - 5.3 [Sequence Numbers and Acknowledgment Numbers](#53-sequence-numbers-and-acknowledgment-numbers)
   - 5.4 [Round‑Trip Time Estimation and Timeout](#54-round-trip-time-estimation-and-timeout)
6. [Reliable Data Transfer in TCP](#6-reliable-data-transfer-in-tcp)
   - 6.1 [Simplified TCP Sender](#61-simplified-tcp-sender)
   - 6.2 [Doubling the Timeout Interval](#62-doubling-the-timeout-interval)
   - 6.3 [Fast Retransmit](#63-fast-retransmit)
7. [Flow Control](#7-flow-control)
   - 7.1 [How TCP Flow Control Works](#71-how-tcp-flow-control-works)
   - 7.2 [The Receive Window](#72-the-receive-window)
8. [TCP Connection Management](#8-tcp-connection-management)
   - 8.1 [Three‑Way Handshake](#81-three-way-handshake)
   - 8.2 [Connection Teardown (Four‑Way)](#82-connection-teardown-four-way)
   - 8.3 [TCP States (Lifecycle)](#83-tcp-states-lifecycle)
   - 8.4 [SYN Flood Attack](#84-syn-flood-attack)
9. [Congestion Control](#9-congestion-control)
   - 9.1 [Causes and Costs of Congestion](#91-causes-and-costs-of-congestion)
   - 9.2 [Approaches to Congestion Control](#92-approaches-to-congestion-control)
   - 9.3 [TCP Congestion Control — AIMD](#93-tcp-congestion-control--aimd)
   - 9.4 [Slow Start](#94-slow-start)
   - 9.5 [Congestion Avoidance](#95-congestion-avoidance)
   - 9.6 [Fast Recovery](#96-fast-recovery)
   - 9.7 [TCP Congestion Control — State Machine](#97-tcp-congestion-control--state-machine)
   - 9.8 [TCP Throughput](#98-tcp-throughput)
10. [Fairness](#10-fairness)
    - 10.1 [TCP Fairness](#101-tcp-fairness)
    - 10.2 [Fairness and UDP](#102-fairness-and-udp)
    - 10.3 [Fairness and Parallel TCP Connections](#103-fairness-and-parallel-tcp-connections)
11. [TCP vs UDP — Mind Map & Comparison](#11-tcp-vs-udp--mind-map--comparison)
12. [Chapter Summary & Quick Revision](#12-chapter-summary--quick-revision)
13. [Additional References for In‑Depth Study](#13-additional-references-for-in-depth-study)

---

# 1. Transport‑Layer Services & Overview

## 1.1 Relationship Between Transport and Network Layers

### Definition
> The **transport layer** provides **logical communication between processes** running on different hosts.
> The **network layer** provides **logical communication between hosts**.

### Key Analogy 🏠✉️
Imagine two houses (hosts) in different cities. The postal service (network layer) delivers
mail between the two houses. Inside each house, a person (transport layer) takes the mail
from the mailbox and hands each letter to the correct family member (process).

- **Network layer (IP)** = postal service — delivers to the *house*
- **Transport layer (TCP/UDP)** = person inside the house — delivers to the *right family member*

### Key Points
| Aspect | Network Layer | Transport Layer |
|---|---|---|
| Communication | Host ↔ Host | Process ↔ Process |
| Addressing | IP Addresses | Port Numbers |
| Protocol examples | IP | TCP, UDP |
| Analogy | Postal service between houses | Sorting mail to family members |

> **Exam Tip:** The transport layer can provide services **beyond** what the network layer offers (e.g., reliable delivery, ordering), but it **cannot** guarantee delay or bandwidth — those are network‑layer limitations.

## 1.2 Overview of the Transport Layer in the Internet

The Internet provides **two** transport‑layer protocols to the application layer:

| | **TCP** | **UDP** |
|---|---|---|
| Full name | Transmission Control Protocol | User Datagram Protocol |
| Connection | Connection‑oriented | Connectionless |
| Reliability | Reliable, ordered delivery | Best‑effort, no guarantee |
| Congestion control | Yes | No |
| Flow control | Yes | No |
| Overhead | Higher (20‑byte header min) | Lower (8‑byte header) |

### The IP Service Model
IP (Internet Protocol) is a **best‑effort delivery** service:
- No guarantee of segment delivery
- No guarantee of orderly delivery
- No guarantee of data integrity

> IP is **unreliable**. The transport layer builds reliability **on top of** IP.

### What Transport Layer Adds Over IP
- **Multiplexing / Demultiplexing** — extending host‑to‑host delivery to process‑to‑process
- **Integrity checking** — checksums (both UDP and TCP)
- **Reliable data transfer** — TCP only
- **Congestion control** — TCP only

---

# 2. Multiplexing and Demultiplexing

### Definition
> **Multiplexing (at sender):** Gathering data from multiple sockets, encapsulating each with transport header → passing to network layer.
>
> **Demultiplexing (at receiver):** Delivering received segments to the correct socket.

### Real‑World Analogy 🏢
Think of a large office building (host) with many offices (processes). The building has
one main entrance (IP address). The security guard (transport layer) reads the office number
(port number) on each package and delivers it to the right office.

```
                  MULTIPLEXING (Sender Side)
  ┌─────────┐  ┌─────────┐  ┌─────────┐
  │ Process  │  │ Process  │  │ Process  │
  │ (P1)     │  │ (P2)     │  │ (P3)     │
  └────┬─────┘  └────┬─────┘  └────┬─────┘
       │              │              │
       ▼              ▼              ▼
  ╔═══════════════════════════════════════╗
  ║     Transport Layer (MUX)            ║
  ║  Add src port + dest port headers    ║
  ╚══════════════════╤════════════════════╝
                     ▼
              Network Layer (IP)


                  DEMULTIPLEXING (Receiver Side)
              Network Layer (IP)
                     │
                     ▼
  ╔═══════════════════════════════════════╗
  ║     Transport Layer (DEMUX)          ║
  ║  Read dest port → route to socket    ║
  ╚══════════════════╤════════════════════╝
       │              │              │
       ▼              ▼              ▼
  ┌─────────┐  ┌─────────┐  ┌─────────┐
  │ Process  │  │ Process  │  │ Process  │
  │ (P1)     │  │ (P2)     │  │ (P3)     │
  └─────────┘  └─────────┘  └─────────┘
```

## 2.1 How Demultiplexing Works

Every transport‑layer segment has:
- **Source port number** (16 bits → 0–65535)
- **Destination port number** (16 bits → 0–65535)

**Well‑known ports:** 0–1023 (reserved for standard protocols like HTTP=80, DNS=53, HTTPS=443)

The host uses the **destination port** (and possibly more fields) to direct the segment to the appropriate socket.

## 2.2 Connectionless (UDP) Demultiplexing

A UDP socket is identified by a **2‑tuple**:
```
(destination IP address, destination port number)
```

> Two segments with the **same destination IP + destination port** but **different source IP/port** will be directed to the **same socket**.

### Example
```
Host A (IP: 10.0.0.1)          Host B (IP: 10.0.0.2)
  App sends to port 9876   ──►   UDP socket bound to port 9876
Host C (IP: 10.0.0.3)
  App sends to port 9876   ──►   SAME UDP socket on Host B
```

## 2.3 Connection‑Oriented (TCP) Demultiplexing

A TCP socket is identified by a **4‑tuple**:
```
(source IP, source port, destination IP, destination port)
```

> Two segments with the **same destination IP + port** but **different source IP or port**
> are directed to **different sockets**.

### Why the Difference?
TCP is connection‑oriented. Each connection is unique. A web server (e.g., port 80) may have
hundreds of simultaneous connections — each gets its own socket, identified by the full 4‑tuple.

> **Common Exam Mistake ⚠️:** Students often confuse UDP and TCP demultiplexing.
> Remember: **UDP = 2‑tuple, TCP = 4‑tuple**.

### Mnemonic: **"U‑2, T‑4"**
- **U**DP → **2**‑tuple
- **T**CP → **4**‑tuple

---

# 3. Connectionless Transport: UDP

## 3.1 Why Use UDP?

UDP is "bare bones" — it does almost nothing beyond multiplexing/demultiplexing and error checking. So why use it?

| Advantage | Explanation |
|---|---|
| **No connection setup** | No handshake delay → faster first byte |
| **No connection state** | Server can support more active clients |
| **Small header overhead** | 8 bytes vs TCP's 20+ bytes |
| **No congestion control** | App can blast data as fast as desired |
| **Finer application control** | App decides what/when to send |

### Applications that use UDP
| Application | Why UDP? |
|---|---|
| DNS | Quick query‑response, small messages |
| SNMP | Network management, simple exchanges |
| Streaming media | Tolerates some loss; low latency critical |
| Online gaming | Real‑time, low latency essential |
| VoIP | Real‑time voice, minor loss acceptable |
| DHCP | Bootstrap — no TCP connection possible yet |

> **Why this matters:** Understanding *when* to use UDP vs TCP is a common interview question. The key trade‑off is **speed/simplicity vs reliability**.

## 3.2 UDP Segment Structure

```
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          Source Port          |       Destination Port        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|            Length             |           Checksum            |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                                                               |
|                     Application Data                          |
|                         (payload)                             |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

| Field | Size | Description |
|---|---|---|
| Source Port | 16 bits | Sender's port |
| Destination Port | 16 bits | Receiver's port |
| Length | 16 bits | Total segment length (header + data) in bytes |
| Checksum | 16 bits | Error detection |

> **Header size = 8 bytes** (4 fields × 2 bytes each)

## 3.3 UDP Checksum

### Purpose
Detect errors (bit flips) in the transmitted segment.

### How It's Computed
1. Treat the segment (header + data + a pseudo‑header from IP) as a sequence of 16‑bit words.
2. Sum all 16‑bit words using **one's complement arithmetic**.
3. Take the **one's complement** of the sum → that's the checksum.

### Step‑by‑Step Example
```
Word 1:   0110 0110 0110 0000
Word 2:   0101 0101 0101 0101
Word 3:   1000 1111 0000 1100
────────────────────────────────
Sum:      carry bits are wrapped around
          → one's complement of sum = CHECKSUM
```

At the receiver:
- Add all words including the checksum
- If result = `1111 1111 1111 1111` → no error detected
- If any bit is 0 → error detected!

> **Exam Tip:** UDP checksum can detect errors but **cannot correct** them. Also, it's **not 100% reliable** — some errors can go undetected (e.g., two complementary bit flips).

> **Why does UDP have a checksum if it's "unreliable"?**
> Because the underlying link layer may not provide error checking on every link, and because errors can be introduced in router memory. This is an **end‑to‑end** design principle.

---

# 4. Principles of Reliable Data Transfer

This is one of the **most important** sections of the entire networking course.

> **Core Problem:** How do we build a reliable communication protocol on top of an unreliable channel?

```
  Application Layer
       │  rdt_send(data)         deliver_data(data)  │
       ▼                                              ▲
  ╔════════════════════════════════════════════════════════╗
  ║            Reliable Data Transfer Protocol            ║
  ╚════════════════════════╤═══════════════════════════════╝
       │  udt_send(packet)       rdt_rcv(packet)     │
       ▼                                              ▲
  ╔════════════════════════════════════════════════════════╗
  ║              Unreliable Channel                       ║
  ╚════════════════════════════════════════════════════════╝
```

- `rdt_send()` — called by app to hand data down
- `udt_send()` — called by rdt protocol to send packet over unreliable channel
- `rdt_rcv()` — called when packet arrives at receiver side
- `deliver_data()` — called by rdt to deliver data up to app

## 4.1 Building a Reliable Data Transfer Protocol

We build up incrementally through versions **rdt 1.0 → 2.0 → 2.1 → 2.2 → 3.0**.

### Mind Map: Building Reliable Data Transfer

```
Reliable Data Transfer
├── rdt 1.0: Perfect channel
│   └── Just send and receive (no mechanism needed)
│
├── rdt 2.0: Channel has BIT ERRORS
│   ├── Add: Checksum (to detect errors)
│   ├── Add: ACK / NAK (feedback)
│   └── Problem: What if ACK/NAK is corrupted?
│
├── rdt 2.1: Handle corrupted ACK/NAK
│   ├── Add: Sequence numbers (0 and 1)
│   └── Sender retransmits on garbled ACK/NAK
│
├── rdt 2.2: NAK-free
│   ├── Remove: NAK
│   └── Use: Duplicate ACK (ACK with seq# of last good packet)
│
├── rdt 3.0: Channel has ERRORS + LOSS
│   ├── Add: Timer (countdown for retransmission)
│   ├── Still uses: seq#, checksum, ACKs
│   └── Called: "Alternating‑bit protocol"
│
└── Pipelining (performance improvement)
    ├── Go‑Back‑N (GBN)
    └── Selective Repeat (SR)
```

## 4.2 rdt 1.0 — Reliable Transfer over a Perfectly Reliable Channel

**Assumption:** The underlying channel is **perfectly reliable** — no bit errors, no loss.

**Protocol:** Trivially simple:
- Sender: `rdt_send(data)` → make packet → `udt_send(packet)`
- Receiver: `rdt_rcv(packet)` → extract data → `deliver_data(data)`

> No error detection, no feedback, no retransmission needed.

## 4.3 rdt 2.0 — Channel with Bit Errors (Stop‑and‑Wait with ACK/NAK)

**New Assumption:** Channel can **flip bits** (introduce errors), but no packet loss.

### New Mechanisms
1. **Checksum** — detect bit errors
2. **ACK (Acknowledgment)** — receiver tells sender "got it correctly"
3. **NAK (Negative Acknowledgment)** — receiver tells sender "got it, but it's corrupted"
4. **Retransmission** — sender resends on NAK

### How It Works
```
Sender                              Receiver
  │                                    │
  │─── packet ────────────────────────►│
  │                                    │── checksum OK?
  │                                    │   YES → send ACK
  │◄──────────────────────── ACK ──────│
  │  (send next packet)               │
  │                                    │
  │─── packet (corrupted!) ──────────►│
  │                                    │── checksum OK?
  │                                    │   NO → send NAK
  │◄──────────────────────── NAK ──────│
  │  (retransmit same packet)          │
```

### Fatal Flaw ⚠️
> **What if the ACK or NAK itself is corrupted?**
> The sender doesn't know if it should retransmit or move on. This leads to **rdt 2.1**.

## 4.4 rdt 2.1 — Handling Garbled ACKs/NAKs

### Solution: Add **Sequence Numbers**

- Use sequence numbers **0** and **1** (alternating).
- If sender receives a garbled ACK/NAK → **retransmit** the current packet.
- Receiver uses sequence number to detect **duplicates** and discard them.

### Sender FSM (Finite State Machine) — Simplified
```
State: Wait for call 0 from above
  → rdt_send(data): make pkt(0, data, checksum) → send → go to "Wait for ACK/NAK 0"

State: Wait for ACK/NAK 0
  → rdt_rcv(rcvpkt) AND corrupt OR isNAK → resend pkt(0)
  → rdt_rcv(rcvpkt) AND notcorrupt AND isACK → go to "Wait for call 1 from above"
```

### Receiver
- If packet has **expected seq#** and **not corrupt** → deliver, send ACK
- If packet has **wrong seq#** (duplicate) → discard, re‑send ACK for last correctly received
- If **corrupt** → send NAK

## 4.5 rdt 2.2 — NAK‑Free Protocol

### Key Idea
Instead of NAK, the receiver sends an **ACK for the last correctly received packet**.

- If sender receives **duplicate ACK** (ACK for previous seq#) → same as receiving a NAK → retransmit.

This simplification is important because TCP uses this approach!

### Example
```
Sender sends pkt(1)  ──────────►  Receiver gets corrupt pkt
                                   Sends ACK(0)   [ACK for last good = pkt 0]
Sender gets ACK(0)   ◄──────────
  "I expected ACK(1), got ACK(0) → duplicate ACK → retransmit pkt(1)"
```

## 4.6 rdt 3.0 — Channels with Errors AND Loss (Timeouts)

**New Assumption:** Channel can **flip bits** AND **lose packets entirely** (data or ACKs).

### New Mechanism: **Timer**
- Sender starts a **countdown timer** after sending each packet.
- If ACK not received before timer expires → **retransmit**.
- Sequence numbers handle duplicates caused by premature timeouts.

### Scenarios

**Scenario A: No loss**
```
Sender              Receiver
pkt(0) ──────────► receives → ACK(0)
       ◄────────── ACK(0)
pkt(1) ──────────► receives → ACK(1)
       ◄────────── ACK(1)
```

**Scenario B: Packet loss**
```
Sender              Receiver
pkt(0) ────X        (lost!)
  ... timer expires ...
pkt(0) ──────────► receives → ACK(0)
       ◄────────── ACK(0)
```

**Scenario C: ACK loss**
```
Sender              Receiver
pkt(0) ──────────► receives → ACK(0)
       ◄────X      ACK(0) lost!
  ... timer expires ...
pkt(0) ──────────► duplicate! → discard → ACK(0)
       ◄────────── ACK(0)
```

**Scenario D: Premature timeout**
```
Sender              Receiver
pkt(0) ──────────► receives → ACK(0)
  ... timer expires (ACK delayed) ...
pkt(0) ──────────► duplicate! → discard → ACK(0)
       ◄────────── ACK(0)  (first one, late)
       ◄────────── ACK(0)  (second one)
  Sender ignores duplicate ACK
```

> **This is called the "Alternating‑Bit Protocol"** because the sequence number alternates between 0 and 1.

### Performance Problem 🐢
rdt 3.0 is a **stop‑and‑wait** protocol. The sender sends ONE packet and waits for its ACK before sending the next. This is **extremely inefficient** on high‑bandwidth, high‑delay links.

**Utilization calculation:**
```
U_sender = (L / R) / (RTT + L/R)

Where:
  L = packet size (bits)
  R = link rate (bps)
  RTT = round‑trip time

Example: L = 8000 bits, R = 1 Gbps, RTT = 30 ms
  L/R = 8 μs
  U = 8 μs / 30.008 ms = 0.00027 = 0.027%
```

> Only 0.027% utilization! We're wasting the link. **Solution: Pipelining.**

## 4.7 Pipelined Reliable Data Transfer

### Key Idea
Allow sender to have **multiple un‑ACKed packets** in flight simultaneously.

### Consequences of Pipelining
1. Sequence numbers must be **larger** (not just 0 and 1)
2. Sender and receiver need **buffers** for multiple packets
3. Two main approaches: **Go‑Back‑N** and **Selective Repeat**

```
Stop-and-Wait:          Pipelining:
|pkt1|    |ACK1|        |pkt1|pkt2|pkt3|    |ACK1|ACK2|ACK3|
|----|----|----|----|    |----|----|----|----|----|----|----|
  ▲ idle time ▲           ▲ much less idle time ▲
```

## 4.8 Go‑Back‑N (GBN)

### Overview
- Sender can have up to **N** unacknowledged packets in the pipeline (window size = N).
- Receiver sends **cumulative ACKs** — ACK(n) means "I've received everything up to and including n."
- If a packet is lost, sender **retransmits that packet AND all subsequent packets** in the window.

### Sender's View of Sequence Numbers
```
  ┌─────────────────────────────────────────────────────┐
  │ Already ACKed │  Sent, not ACKed  │ Usable │ Not usable │
  │ (green)       │  (yellow)         │ (blue) │ (grey)     │
  └─────────────────────────────────────────────────────┘
                  ▲                   ▲
                  │                   │
                base              nextseqnum
                  │◄──── window N ───►│
```

### Receiver Behavior
- Simple! Receiver only accepts **in‑order** packets.
- Out‑of‑order packets are **discarded** (not buffered).
- Re‑sends ACK for last correctly received in‑order packet.

### Example (Window N = 4)
```
Sender sends: pkt0, pkt1, pkt2, pkt3
                         pkt2 LOST!

Receiver:
  pkt0 → ACK(0) ✓
  pkt1 → ACK(1) ✓
  pkt2 → (never arrives)
  pkt3 → out of order → discard → ACK(1)  [last in-order]

Sender: timeout for pkt2
  → retransmit pkt2, pkt3  (go back to pkt2!)
```

> **Why "Go‑Back‑N"?** Because the sender "goes back" N packets (or to the lost one) and resends from there.

### Pros and Cons
| ✅ Pros | ❌ Cons |
|---|---|
| Simple receiver (no buffering) | Wastes bandwidth retransmitting correct packets |
| Easy to implement | Performance degrades with large windows or high loss |

## 4.9 Selective Repeat (SR)

### Overview
- Sender can have up to **N** unacknowledged packets.
- Receiver **individually ACKs** each packet (not cumulative).
- Receiver **buffers** out‑of‑order packets.
- Sender **only retransmits** the specific lost/timed‑out packets.

### Sender & Receiver Windows
```
Sender window:
  [0✓] [1✓] [2 sent] [3 sent] [4 avail] [5 avail]
                ▲ timer       ▲ timer

Receiver window:
  [0 delivered] [1 delivered] [2 ???] [3 buffered] [4 ???] [5 ???]
                               ▲ gap
```

### Example
```
Sender sends: pkt0, pkt1, pkt2, pkt3
                         pkt2 LOST!

Receiver:
  pkt0 → ACK(0) ✓, deliver
  pkt1 → ACK(1) ✓, deliver
  pkt2 → (never arrives)
  pkt3 → ACK(3) ✓, BUFFER (out of order)

Sender: timeout for pkt2 only
  → retransmit pkt2 ONLY

Receiver gets pkt2:
  → ACK(2), deliver pkt2, then deliver buffered pkt3
```

### Pros and Cons
| ✅ Pros | ❌ Cons |
|---|---|
| Efficient: only retransmit lost packets | Complex receiver (buffering needed) |
| Better bandwidth utilization | Larger sequence number space needed |

### ⚠️ Important: Sequence Number Space for SR

> **The sequence number space must be at least 2 × window size.**
>
> If `window size = N`, then `seq# space ≥ 2N`

**Why?** With a smaller space, the receiver can't distinguish between new packets and retransmissions.

> **Exam Trap:** For GBN, seq# space ≥ N + 1. For SR, seq# space ≥ 2N. Don't mix them up!

### GBN vs SR Comparison

| Feature | Go‑Back‑N | Selective Repeat |
|---|---|---|
| ACK type | Cumulative | Individual |
| Receiver buffering | No | Yes |
| Retransmission | All from lost packet onward | Only lost packet |
| Timer | Single (for oldest unACKed) | Per‑packet |
| Seq# space needed | ≥ N + 1 | ≥ 2N |
| Efficiency on loss | Low (many retransmissions) | High |
| Complexity | Simpler | More complex |

---

# 5. Connection‑Oriented Transport: TCP

## 5.1 The TCP Connection

### Key Properties
- **Connection‑oriented:** Handshake required before data exchange
- **Full‑duplex:** Data flows in both directions simultaneously
- **Point‑to‑point:** One sender, one receiver (no multicast)
- **Byte‑stream:** TCP sees data as an unstructured stream of bytes
- **Reliable, in‑order:** Guaranteed delivery in the order sent
- **Pipelined:** Sender can have multiple unACKed segments (uses window)

### How a TCP Connection Works (Big Picture)
```
  Client                                Server
    │                                      │
    │──── SYN ────────────────────────────►│
    │◄──────────────────────── SYN+ACK ────│
    │──── ACK ────────────────────────────►│
    │                                      │
    │◄════ Full‑duplex data exchange ═════►│
    │                                      │
    │──── FIN ────────────────────────────►│
    │◄──────────────────────────── ACK ────│
    │◄──────────────────────────── FIN ────│
    │──── ACK ────────────────────────────►│
    │                                      │
```

### Buffers
TCP maintains **send** and **receive buffers** at each end:

```
Application writes → [Send Buffer] → TCP segments → Network
Network → TCP segments → [Receive Buffer] → Application reads
```

**Maximum Segment Size (MSS):** Maximum amount of application‑layer data in a segment (NOT including headers). Typically **1460 bytes** (to fit in a 1500‑byte Ethernet MTU with 20‑byte IP + 20‑byte TCP headers).

## 5.2 TCP Segment Structure

```
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          Source Port          |       Destination Port        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                        Sequence Number                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Acknowledgment Number                      |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Data |       |C|E|U|A|P|R|S|F|                               |
| Offset| Rsrvd |W|C|R|C|S|S|Y|I|         Window Size           |
|       |       |R|E|G|K|H|T|N|N|                               |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|           Checksum            |         Urgent Pointer        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options (variable)                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                                                               |
|                    Application Data (payload)                 |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

### Field Breakdown

| Field | Size | Description |
|---|---|---|
| Source Port | 16 bits | Sender's port number |
| Destination Port | 16 bits | Receiver's port number |
| Sequence Number | 32 bits | Byte‑stream number of first data byte in segment |
| Acknowledgment Number | 32 bits | Next byte expected from other side |
| Data Offset (Header Length) | 4 bits | Number of 32‑bit words in header |
| Reserved | 3 bits | Reserved for future use |
| **Flags** | 9 bits | Control bits (see below) |
| Window Size | 16 bits | Receiver's available buffer space (for flow control) |
| Checksum | 16 bits | Error detection (mandatory) |
| Urgent Pointer | 16 bits | Points to urgent data (rarely used) |
| Options | Variable | e.g., MSS, Window Scale, Timestamps |

### Important Flags

| Flag | Meaning |
|---|---|
| **SYN** | Synchronize — connection setup |
| **ACK** | Acknowledgment field is valid |
| **FIN** | Finish — connection teardown |
| **RST** | Reset — abort connection |
| **PSH** | Push — deliver data to app immediately |
| **URG** | Urgent pointer field is valid |
| **CWR** | Congestion Window Reduced (ECN) |
| **ECE** | ECN‑Echo (ECN) |

> **Mnemonic for key flags: "SARA FiSh"** — **S**YN, **A**CK, **R**ST, **A**nd **Fi**N, p**S**H

## 5.3 Sequence Numbers and Acknowledgment Numbers

### Sequence Numbers
- TCP numbers **every byte** of data in the stream.
- The **sequence number** of a segment is the byte number of the **first byte** of data in that segment.

### Example
```
Suppose data = 500,000 bytes, MSS = 1000 bytes
  → 500 segments

Segment 1: seq# = 0       (bytes 0–999)
Segment 2: seq# = 1000    (bytes 1000–1999)
Segment 3: seq# = 2000    (bytes 2000–2999)
...
Segment 500: seq# = 499000 (bytes 499000–499999)
```

### Acknowledgment Numbers
- The ACK number indicates the **next byte the receiver expects**.
- TCP uses **cumulative ACKs**: ACK(n) means "I have received all bytes up to byte n−1; send me byte n next."

### Example
```
Host A sends segment with seq# = 42, carrying 10 bytes of data (bytes 42–51)
Host B receives it and sends back: ACK# = 52
  (meaning: "I got bytes up to 51; send me byte 52 next")
```

> **Exam Tip:** The ACK number is the **next expected byte**, NOT the last received byte.

### Piggybacking
Since TCP is full‑duplex, a segment from A → B can carry:
- Data from A to B (with A's sequence number)
- An ACK for B's data (with the ACK number)

This is called **piggybacking**.

## 5.4 Round‑Trip Time Estimation and Timeout

### Why Does This Matter?
TCP needs a good timeout value for retransmissions.
- **Too short** → unnecessary retransmissions (wastes bandwidth)
- **Too long** → slow reaction to loss (wastes time)

### Step 1: Measuring Sample RTT
`SampleRTT` = time from segment sent to ACK received (for segments sent only once — not retransmissions).

### Step 2: Exponential Weighted Moving Average (EWMA)

```
EstimatedRTT = (1 − α) × EstimatedRTT + α × SampleRTT
```
- Typical α = **0.125** (= 1/8)
- Gives more weight to recent samples but smooths out fluctuations.

### Step 3: RTT Deviation

```
DevRTT = (1 − β) × DevRTT + β × |SampleRTT − EstimatedRTT|
```
- Typical β = **0.25** (= 1/4)

### Step 4: Setting the Timeout

```
TimeoutInterval = EstimatedRTT + 4 × DevRTT
```

> **Why 4 × DevRTT?** It provides a safety margin. If RTT varies a lot (high DevRTT), the timeout is larger. If RTT is stable (low DevRTT), the timeout is tighter.

### Step‑by‑Step Numerical Example
```
Given: EstimatedRTT = 100ms, DevRTT = 5ms
New SampleRTT = 120ms

New EstimatedRTT = 0.875 × 100 + 0.125 × 120 = 87.5 + 15 = 102.5 ms
New DevRTT = 0.75 × 5 + 0.25 × |120 − 100| = 3.75 + 5 = 8.75 ms
New Timeout = 102.5 + 4 × 8.75 = 102.5 + 35 = 137.5 ms
```

> **Mnemonic: "EST + 4 DEV"** — Timeout = Estimated + 4 × Deviation

---

# 6. Reliable Data Transfer in TCP

TCP's reliability is built from the mechanisms we studied in Section 4, but with practical optimizations.

## 6.1 Simplified TCP Sender

TCP uses a **single retransmission timer** for the oldest unacknowledged segment.

### Three Major Events at the Sender

**Event 1: Data received from application**
- Create segment with sequence number = `NextSeqNum`
- Start timer if not already running
- `NextSeqNum += length(data)`

**Event 2: Timer timeout**
- Retransmit the **oldest unACKed segment**
- Restart timer

**Event 3: ACK received**
- If ACK acknowledges **new data** (ACK# > SendBase):
  - Update `SendBase = ACK#`
  - If there are still unACKed segments → restart timer
  - Else → stop timer

## 6.2 Doubling the Timeout Interval

After each timeout, TCP **doubles** the timeout interval (exponential backoff):

```
Timeout after 1st loss:  TimeoutInterval
Timeout after 2nd loss:  2 × TimeoutInterval
Timeout after 3rd loss:  4 × TimeoutInterval
...
```

> **Why?** If a segment is being lost, the network is probably congested. Backing off reduces load.
> The timer is reset to its computed value (EstimatedRTT + 4×DevRTT) once a new ACK arrives.

## 6.3 Fast Retransmit

### The Problem with Timeouts
Timeout periods can be **long**. Waiting for a timeout wastes time.

### The Solution: Duplicate ACKs
If the sender receives **3 duplicate ACKs** (i.e., 4 identical ACKs total), it assumes the segment is lost and retransmits **immediately** — without waiting for the timeout.

### Why 3 Duplicate ACKs?
```
Sender sends: seg1, seg2, seg3, seg4, seg5
                    seg2 LOST!

Receiver:
  seg1 → ACK(expected: byte after seg1) ✓
  seg3 → out of order → re‑ACK(expected: byte after seg1)  [dup ACK #1]
  seg4 → out of order → re‑ACK(expected: byte after seg1)  [dup ACK #2]
  seg5 → out of order → re‑ACK(expected: byte after seg1)  [dup ACK #3]

Sender gets 3 dup ACKs → FAST RETRANSMIT seg2!
```

> A single duplicate ACK might just mean a reordered packet. Three duplicate ACKs make it very likely the segment is actually **lost**.

### Why This Matters
Fast retransmit significantly improves TCP performance. Without it, TCP would have to wait for a timeout (potentially hundreds of milliseconds) to detect a single lost segment.

> **Common Exam Question:** "How does TCP detect loss without waiting for timeout?" → **Three duplicate ACKs trigger fast retransmit.**

---

# 7. Flow Control

## 7.1 How TCP Flow Control Works

### Definition
> **Flow control** ensures the sender does not overwhelm the receiver's buffer.

### Real‑World Analogy 🚰
Imagine filling a cup from a firehose. If you blast water too fast, the cup overflows.
Flow control is like telling the firehose operator: "I only have *this much* room left in my cup."

### Key Distinction ⚠️
| | Flow Control | Congestion Control |
|---|---|---|
| Protects | Receiver's buffer | Network (routers, links) |
| Signal | Receive window (rwnd) | Packet loss / delay |
| Controlled by | Receiver | Sender (inferred) |

> **Exam Trap:** Students frequently confuse flow control and congestion control. Remember: Flow control = **receiver protection**, Congestion control = **network protection**.

## 7.2 The Receive Window

The receiver advertises its available buffer space using the **receive window** (`rwnd`) field in the TCP header.

```
Receiver Buffer (RcvBuffer)
┌──────────────────────────────────────────┐
│  Delivered  │  Received but  │   Empty   │
│  to app     │  not yet read  │  (rwnd)   │
│             │  by app        │           │
└──────────────────────────────────────────┘
              ▲                ▲            ▲
         LastByteRead    LastByteRcvd    RcvBuffer end
```

```
rwnd = RcvBuffer − (LastByteRcvd − LastByteRead)
```

### Sender's Constraint
The sender ensures:
```
LastByteSent − LastByteAcked ≤ rwnd
```
(Amount of unACKed data in flight ≤ receiver's available buffer)

### The Zero‑Window Problem
If `rwnd = 0`, the sender stops sending. But how does it know when the receiver has space again?

**Solution:** The sender continues to send **tiny probe segments** (1 byte) periodically. The receiver will respond with an ACK that contains the updated `rwnd`. This is the **persist timer** mechanism.

---

# 8. TCP Connection Management

## 8.1 Three‑Way Handshake

### Step‑by‑Step

```
  Client                                          Server
    │                                                │
    │  STEP 1: SYN                                   │
    │  (SYN=1, seq=client_isn)                       │
    │────────────────────────────────────────────────►│
    │                                                │
    │  STEP 2: SYN-ACK                               │
    │  (SYN=1, ACK=1, seq=server_isn,                │
    │   ack=client_isn+1)                            │
    │◄────────────────────────────────────────────────│
    │                                                │
    │  STEP 3: ACK                                   │
    │  (SYN=0, ACK=1, seq=client_isn+1,              │
    │   ack=server_isn+1)                            │
    │  [may carry data!]                             │
    │────────────────────────────────────────────────►│
    │                                                │
    │  ═══════ CONNECTION ESTABLISHED ═══════        │
```

### Why Three Steps? (Why Not Two?)

**Two‑way handshake problem:**
- Old duplicate SYN arrives at server → server thinks it's a new connection → allocates resources → **half‑open connection** (wastes resources)

**Three‑way handshake solves this:**
- Server only fully opens the connection after receiving the third segment (ACK from client).
- This confirms both sides are alive and synchronized.

> **Mnemonic: "SYN → SYN‑ACK → ACK"** (like a phone call: "Hello?" → "Hello, I hear you!" → "Great, let's talk!")

### ISN (Initial Sequence Number)
- Each side picks a **random** ISN — not zero!
- **Why random?** To prevent old segments from previous connections being confused with new ones, and for security against TCP hijacking attacks.

## 8.2 Connection Teardown (Four‑Way)

Either side can initiate the close.

```
  Client                                          Server
    │                                                │
    │  STEP 1: FIN                                   │
    │  (FIN=1, seq=x)                                │
    │────────────────────────────────────────────────►│
    │                                                │
    │  STEP 2: ACK                                   │
    │  (ACK=1, ack=x+1)                              │
    │◄────────────────────────────────────────────────│
    │                                                │
    │       [Server may still send data]             │
    │                                                │
    │  STEP 3: FIN                                   │
    │  (FIN=1, seq=y)                                │
    │◄────────────────────────────────────────────────│
    │                                                │
    │  STEP 4: ACK                                   │
    │  (ACK=1, ack=y+1)                              │
    │────────────────────────────────────────────────►│
    │                                                │
    │  [Client enters TIME_WAIT for 2×MSL]           │
    │                                                │
```

### Why TIME_WAIT?
The client waits for **2 × MSL** (Maximum Segment Lifetime, typically 30 seconds each → 60 seconds total) before fully closing.

**Two reasons:**
1. If the final ACK is lost, the server will retransmit its FIN, and the client can re‑ACK.
2. Ensures all old segments from this connection expire before the port can be reused.

## 8.3 TCP States (Lifecycle)

```
Client States:                    Server States:
─────────────                     ─────────────
CLOSED                            CLOSED
  │ (active open)                   │ (passive open)
  ▼                                 ▼
SYN_SENT                          LISTEN
  │ (receive SYN-ACK, send ACK)     │ (receive SYN, send SYN-ACK)
  ▼                                 ▼
ESTABLISHED ◄═══════════════════► SYN_RCVD
                                    │ (receive ACK)
                                    ▼
                                  ESTABLISHED

  (closing)                        (closing)
ESTABLISHED                       ESTABLISHED
  │ (send FIN)                      │ (receive FIN, send ACK)
  ▼                                 ▼
FIN_WAIT_1                        CLOSE_WAIT
  │ (receive ACK)                   │ (send FIN)
  ▼                                 ▼
FIN_WAIT_2                        LAST_ACK
  │ (receive FIN, send ACK)         │ (receive ACK)
  ▼                                 ▼
TIME_WAIT                         CLOSED
  │ (2 × MSL timeout)
  ▼
CLOSED
```

## 8.4 SYN Flood Attack

### What Is It?
An attacker sends a flood of **SYN segments** (spoofed source IPs) to a server. The server allocates resources (half‑open connections) for each SYN and waits for the ACK (Step 3) — which never comes.

Result: Server runs out of resources → **Denial of Service (DoS)**.

### Defense: SYN Cookies
- Server does NOT allocate resources on receiving SYN.
- Instead, it encodes connection info into the **ISN** (using a hash).
- Resources are only allocated when the valid ACK comes back with the correct value.

> **Exam Tip:** SYN Cookies are a common exam topic — know how they work!

---

# 9. Congestion Control

> **This is arguably the most complex and important topic in Chapter 3.**

## 9.1 Causes and Costs of Congestion

### What Is Congestion?
> Too many sources sending too much data too fast for the **network** to handle.

### Costs of Congestion
1. **Large queuing delays** — packets wait in router buffers
2. **Packet loss** — router buffers overflow → packets dropped
3. **Unnecessary retransmissions** — sender retransmits packets that are merely delayed, not lost → wastes bandwidth
4. **Wasted upstream resources** — a packet dropped at hop 5 has already consumed resources at hops 1–4

### Scenarios (Conceptual)

**Scenario 1: Two senders, infinite buffer router**
- Throughput increases up to R/2 (fair share), then plateaus
- Delay goes to **infinity** as offered load → R/2

**Scenario 2: Two senders, finite buffer router**
- Some capacity is used for retransmissions → **goodput < throughput**
- Unnecessary retransmissions waste even more capacity

**Scenario 3: Multi‑hop paths**
- When a packet is dropped downstream, all upstream transmission was **wasted**
- This "upstream waste" effect makes congestion much worse

## 9.2 Approaches to Congestion Control

| Approach | Description | Used By |
|---|---|---|
| **End‑to‑end** | No explicit feedback from network; sender infers congestion from loss/delay | Classic TCP |
| **Network‑assisted** | Routers provide explicit feedback (e.g., ECN bits, rate info) | TCP with ECN, ATM ABR |

TCP primarily uses **end‑to‑end** congestion control — it detects congestion by observing **packet loss** (timeout or 3 duplicate ACKs).

## 9.3 TCP Congestion Control — AIMD

### The Core Principle: **Additive Increase, Multiplicative Decrease (AIMD)**

- **Additive Increase:** Increase sending rate by **1 MSS per RTT** (linear growth) while no loss.
- **Multiplicative Decrease:** On loss detection, cut sending rate **in half** (multiplicative reduction).

```
      cwnd
        ▲
        │    /\      /\      /\
        │   /  \    /  \    /  \     ← "sawtooth" pattern
        │  /    \  /    \  /    \
        │ /      \/      \/      \
        └──────────────────────────► time
```

### The Congestion Window (`cwnd`)
- TCP maintains a variable called `cwnd` (congestion window).
- Limits the amount of unACKed data:

```
LastByteSent − LastByteAcked ≤ min(cwnd, rwnd)
```

- **Sending rate ≈ cwnd / RTT** (bytes per second)

> **Key Insight:** TCP's effective window is `min(cwnd, rwnd)`. Flow control uses `rwnd`, congestion control uses `cwnd`. The actual usable window is the **minimum** of the two.

## 9.4 Slow Start

### Definition
> **Slow Start** is the initial phase of TCP congestion control. Despite its name, it grows the congestion window **exponentially** — doubling `cwnd` every RTT.

### How It Works
1. Start with `cwnd = 1 MSS`
2. For every ACK received, `cwnd += 1 MSS`
3. Since each RTT the sender gets ACKs for all packets sent, `cwnd` **doubles** each RTT.

```
RTT 1: cwnd = 1 MSS    → send 1 segment    → receive 1 ACK → cwnd = 2
RTT 2: cwnd = 2 MSS    → send 2 segments   → receive 2 ACKs → cwnd = 4
RTT 3: cwnd = 4 MSS    → send 4 segments   → receive 4 ACKs → cwnd = 8
RTT 4: cwnd = 8 MSS    → send 8 segments   → receive 8 ACKs → cwnd = 16
...
```

### When Does Slow Start End?

1. **Loss via timeout:** `ssthresh = cwnd / 2`, `cwnd = 1 MSS`, restart slow start
2. **cwnd ≥ ssthresh:** Switch to **Congestion Avoidance** (linear growth)
3. **Loss via 3 duplicate ACKs:** `ssthresh = cwnd / 2`, `cwnd = ssthresh + 3 MSS`, enter **Fast Recovery**

> **Why is it called "Slow Start" if it grows exponentially?**
> Because it starts from **1 MSS** — which is very slow compared to blasting at full link rate. The "slow" refers to the starting point, not the growth rate!

> **Exam Trap ⚠️:** Slow start is **exponential**, not linear. Many students get this wrong.

## 9.5 Congestion Avoidance

### Definition
> Once `cwnd ≥ ssthresh`, TCP enters congestion avoidance and increases `cwnd` **linearly**: by 1 MSS per RTT.

### How It Works
- For each ACK: `cwnd += MSS × (MSS / cwnd)`
- Net effect: `cwnd` increases by approximately **1 MSS per RTT** (additive increase).

### On Loss Detection
- **Timeout:** `ssthresh = cwnd/2`, `cwnd = 1 MSS`, go to **Slow Start**
- **3 duplicate ACKs:** `ssthresh = cwnd/2`, `cwnd = ssthresh + 3 MSS`, go to **Fast Recovery** (TCP Reno)

## 9.6 Fast Recovery

### Definition
> **Fast Recovery** (TCP Reno) is entered after detecting loss via 3 duplicate ACKs. It avoids going all the way back to slow start.

### How It Works
1. `ssthresh = cwnd / 2`
2. `cwnd = ssthresh + 3 MSS` (inflate for 3 dup ACKs in flight)
3. For each **additional duplicate ACK**: `cwnd += 1 MSS` (inflate further)
4. When the **new ACK** arrives (acknowledging the retransmitted segment):
   - `cwnd = ssthresh`
   - Enter **Congestion Avoidance**

### TCP Tahoe vs TCP Reno

| Event | TCP Tahoe | TCP Reno |
|---|---|---|
| **Timeout** | `ssthresh = cwnd/2`, `cwnd = 1`, Slow Start | Same as Tahoe |
| **3 dup ACKs** | `ssthresh = cwnd/2`, `cwnd = 1`, **Slow Start** | `ssthresh = cwnd/2`, `cwnd = ssthresh + 3`, **Fast Recovery** |

> **TCP Tahoe** always goes back to slow start on any loss.
> **TCP Reno** distinguishes between timeout (more severe) and 3 dup ACKs (less severe).

## 9.7 TCP Congestion Control — State Machine

```
                    ┌───────────────────┐
                    │                   │
                    ▼                   │ timeout:
              ┌──────────┐             │ ssthresh = cwnd/2
              │   SLOW    │             │ cwnd = 1 MSS
     start───►│  START    │─────────────┘
              │           │
              └─────┬─────┘
                    │ cwnd ≥ ssthresh
                    ▼
              ┌──────────────┐      timeout:
              │  CONGESTION  │      ssthresh = cwnd/2
              │  AVOIDANCE   │──────cwnd = 1 MSS ──► SLOW START
              │              │
              └──────┬───────┘
                     │ 3 dup ACKs:
                     │ ssthresh = cwnd/2
                     │ cwnd = ssthresh + 3
                     ▼
              ┌──────────────┐
              │    FAST      │
              │   RECOVERY   │
              │              │
              └──────┬───────┘
                     │ new ACK:
                     │ cwnd = ssthresh
                     ▼
              CONGESTION AVOIDANCE

     (timeout in Fast Recovery → cwnd = 1, go to SLOW START)
```

### Mind Map: TCP Congestion Control States

```
TCP Congestion Control
│
├── SLOW START
│   ├── Initial: cwnd = 1 MSS
│   ├── Growth: Exponential (double every RTT)
│   ├── Exit conditions:
│   │   ├── cwnd ≥ ssthresh → Congestion Avoidance
│   │   ├── Timeout → ssthresh = cwnd/2, cwnd = 1, stay Slow Start
│   │   └── 3 dup ACKs → ssthresh = cwnd/2, cwnd = ssthresh+3, Fast Recovery
│   └── Remember: "Slow" start ≠ slow growth!
│
├── CONGESTION AVOIDANCE
│   ├── Growth: Linear (add 1 MSS per RTT)
│   ├── This is the AIMD "Additive Increase" phase
│   ├── Exit conditions:
│   │   ├── Timeout → ssthresh = cwnd/2, cwnd = 1, Slow Start
│   │   └── 3 dup ACKs → ssthresh = cwnd/2, cwnd = ssthresh+3, Fast Recovery
│   └── Remember: "Probing" for bandwidth carefully
│
└── FAST RECOVERY (Reno only)
    ├── Entered after: 3 duplicate ACKs
    ├── cwnd inflated for each additional dup ACK
    ├── Exit conditions:
    │   ├── New ACK → cwnd = ssthresh, Congestion Avoidance
    │   └── Timeout → cwnd = 1, Slow Start
    └── Remember: This is the "Multiplicative Decrease" that doesn't go to 1
```

## 9.8 TCP Throughput

### Average Throughput Formula (Simplified)

If window size oscillates between `W/2` and `W`:

```
Average throughput ≈ (3/4) × (W / RTT)
```

Where W is the window size (in bytes) at which loss occurs.

### TCP Throughput with Loss Rate

```
Average throughput ≈ (1.22 × MSS) / (RTT × √L)
```

Where **L** is the loss rate (probability of packet loss).

> This formula shows TCP throughput is **inversely proportional** to RTT and √(loss rate). High RTT or high loss = poor throughput.

---

# 10. Fairness

## 10.1 TCP Fairness

### Definition
> A congestion control mechanism is **fair** if K TCP connections sharing a bottleneck link of rate R each eventually get an average throughput of **R/K**.

### Why TCP Is Fair (Under Ideal Conditions)

The AIMD mechanism converges to fairness:

```
     Connection 2's throughput
     ▲
     │     /  Equal bandwidth line
     │    /
     │   /
     │  •→ AIMD adjustments move toward the line
     │ /
     └────────────────────────► Connection 1's throughput
```

- **Additive increase:** Both connections increase at the same rate → move diagonally toward equal‑bandwidth line.
- **Multiplicative decrease:** Both connections halve → move toward the origin, but the ratio improves.
- Over time, they converge toward the **equal share** point.

## 10.2 Fairness and UDP

> UDP does **not** have congestion control. UDP applications can send at any rate they want.

- UDP traffic can "steal" bandwidth from TCP connections.
- TCP backs off when it detects congestion; UDP does not.
- This is a fundamental fairness problem in the Internet.

## 10.3 Fairness and Parallel TCP Connections

An application can open **multiple parallel TCP connections** to the same server (e.g., web browsers).

- If there are K total TCP connections sharing a link, each gets R/K.
- An app with 11 parallel connections gets **11 × (R/K)** — unfairly more bandwidth than an app with 1 connection.

> **Exam Tip:** HTTP/1.1 browsers commonly open 6 parallel connections. This is a workaround for TCP's fairness but undermines it at the same time.

---

# 11. TCP vs UDP — Mind Map & Comparison

```
┌─────────────────────────────────────────────────────────┐
│                TRANSPORT LAYER PROTOCOLS                 │
├────────────────────────┬────────────────────────────────┤
│          TCP           │             UDP                │
├────────────────────────┼────────────────────────────────┤
│ Connection-oriented    │ Connectionless                 │
│ Reliable delivery      │ Best-effort (unreliable)       │
│ In-order delivery      │ No ordering guarantee          │
│ Flow control (rwnd)    │ No flow control                │
│ Congestion ctrl (cwnd) │ No congestion control          │
│ Byte-stream            │ Message-oriented               │
│ Full-duplex            │ Can be full-duplex             │
│ Point-to-point only    │ Supports multicast/broadcast   │
│ 20+ byte header        │ 8 byte header                  │
│ 3-way handshake        │ No handshake                   │
│ Slower setup           │ Faster (no setup)              │
│ Checksum (mandatory)   │ Checksum (optional in IPv4,    │
│                        │   mandatory in IPv6)           │
├────────────────────────┼────────────────────────────────┤
│ USES:                  │ USES:                          │
│ HTTP, HTTPS, FTP,      │ DNS, DHCP, SNMP, VoIP,        │
│ SMTP, SSH, Telnet      │ Video streaming, Gaming        │
└────────────────────────┴────────────────────────────────┘
```

### Decision Tree: When to Use What?

```
Need reliable, ordered delivery?
├── YES → Use TCP
│   ├── File transfer, web, email, remote login
│   └── Any situation where every byte must arrive correctly
│
└── NO → Consider UDP
    ├── Need low latency more than reliability?
    │   ├── YES → UDP (gaming, VoIP, live streaming)
    │   └── NO → TCP is probably fine
    │
    ├── Simple request-response (small messages)?
    │   └── UDP (DNS, DHCP)
    │
    └── Need multicast/broadcast?
        └── UDP (TCP is point-to-point only)
```

---

# 12. Chapter Summary & Quick Revision

## Key Takeaways

1. The transport layer extends the network layer's **host‑to‑host** communication to **process‑to‑process** communication using **port numbers**.

2. **UDP** is a minimal, connectionless protocol offering multiplexing and error detection — nothing more.

3. **Reliable data transfer** is built incrementally: checksums → ACKs/NAKs → sequence numbers → timers → pipelining (GBN, SR).

4. **TCP** provides reliable, in‑order, byte‑stream delivery with flow control and congestion control.

5. TCP's **three‑way handshake** (SYN → SYN‑ACK → ACK) establishes connections; **four‑way FIN exchange** closes them.

6. TCP's **flow control** uses the receive window (`rwnd`) to prevent overwhelming the receiver.

7. TCP's **congestion control** uses AIMD with three states: Slow Start (exponential), Congestion Avoidance (linear), and Fast Recovery (Reno).

8. **Fast retransmit** (3 duplicate ACKs) avoids waiting for timeout to detect loss.

9. TCP's congestion control creates a **sawtooth** pattern in `cwnd` over time.

10. TCP is **fair** under ideal conditions (AIMD converges), but UDP and parallel connections undermine fairness.

## Important Terms

| Term | Definition |
|---|---|
| **MSS** | Maximum Segment Size — max data in one TCP segment |
| **MTU** | Maximum Transmission Unit — max frame size at link layer |
| **RTT** | Round‑Trip Time — time for a segment to reach destination and ACK to return |
| **cwnd** | Congestion Window — sender's self‑imposed limit based on congestion |
| **rwnd** | Receive Window — receiver's advertised available buffer |
| **ssthresh** | Slow Start Threshold — point where slow start transitions to congestion avoidance |
| **AIMD** | Additive Increase, Multiplicative Decrease — TCP's congestion control paradigm |
| **ISN** | Initial Sequence Number — random starting sequence number |
| **MSL** | Maximum Segment Lifetime — max time a segment can exist in the network |
| **ECN** | Explicit Congestion Notification — network‑assisted congestion signaling |
| **SYN Cookie** | Defense against SYN flood — encode state in ISN |

## Quick Revision Bullets 🚀

1. **Transport layer = process‑to‑process delivery** (vs network layer = host‑to‑host)
2. **UDP demux = 2‑tuple** (dest IP + dest port); **TCP demux = 4‑tuple**
3. **UDP header = 8 bytes**; **TCP header = 20+ bytes**
4. **rdt 3.0** = alternating‑bit protocol (seq# 0/1, checksum, ACK, timer)
5. **GBN** = cumulative ACK, no receiver buffering, retransmit from lost packet onward
6. **SR** = individual ACK, receiver buffers, retransmit only lost packets, seq# ≥ 2N
7. **TCP ACK number = next expected byte** (not last received byte!)
8. **Timeout = EstimatedRTT + 4 × DevRTT**
9. **3 duplicate ACKs → fast retransmit** (don't wait for timeout)
10. **Slow Start = exponential growth**, **Congestion Avoidance = linear growth**

---

# 13. Additional References for In‑Depth Study

## Relevant RFCs

| RFC | Title | Why It's Useful |
|---|---|---|
| [RFC 768](https://tools.ietf.org/html/rfc768) | User Datagram Protocol | The original UDP specification — very short (3 pages). Excellent for understanding UDP's simplicity. |
| [RFC 793](https://tools.ietf.org/html/rfc793) | Transmission Control Protocol | The foundational TCP specification. Essential for understanding segment format, state machine, and connection management. |
| [RFC 5681](https://tools.ietf.org/html/rfc5681) | TCP Congestion Control | Defines slow start, congestion avoidance, fast retransmit, and fast recovery. The most important RFC for congestion control. |
| [RFC 6298](https://tools.ietf.org/html/rfc6298) | Computing TCP's Retransmission Timer | Specifies the EWMA algorithm for EstimatedRTT, DevRTT, and timeout calculation. |
| [RFC 2581](https://tools.ietf.org/html/rfc2581) | TCP Congestion Control (older) | Predecessor to RFC 5681. Some textbooks still reference this. |
| [RFC 3168](https://tools.ietf.org/html/rfc3168) | Explicit Congestion Notification (ECN) | Network‑assisted congestion control using IP header bits. Good for understanding modern TCP enhancements. |
| [RFC 4987](https://tools.ietf.org/html/rfc4987) | TCP SYN Flooding Attacks | Describes SYN flood attacks and SYN cookie defenses. Useful for security‑related exam questions. |

## Online Resources

| Resource | Link | Why It's Useful |
|---|---|---|
| **Jim Kurose's Lectures** | [gaia.cs.umass.edu](https://gaia.cs.umass.edu/kurose_ross/lectures.php) | The textbook author's own lecture slides and animations. Best primary supplement. |
| **Ben Eater's Networking** | [YouTube](https://www.youtube.com/c/BenEater) | Hardware‑level networking intuition with excellent visuals. |
| **Computer Networking Course (Neso Academy)** | [YouTube](https://www.youtube.com/playlist?list=PLBlnK6fEyqRgMCUAG0XRw78UA8qnv6jEx) | Structured playlist covering all major networking topics at exam level. |
| **Computerphile TCP/IP Videos** | [YouTube](https://www.youtube.com/user/Computerphile) | Short, accessible explanations of individual concepts like TCP handshake, congestion control, etc. |
| **Stanford CS144** | [cs144.github.io](https://cs144.github.io/) | Stanford's networking course with hands‑on labs. Excellent for building deeper understanding through implementation. |
| **Wireshark Labs** | [gaia.cs.umass.edu/kurose_ross/wireshark.php](https://gaia.cs.umass.edu/kurose_ross/wireshark.php) | Official Wireshark labs accompanying the textbook. See TCP, UDP, and DNS in action through packet captures. |

## Video Lecture Recommendations

| Topic | Recommended Video | Why Watch It |
|---|---|---|
| TCP 3‑Way Handshake | Kurose Lecture Chapter 3.5 | Author's own explanation with animations |
| Congestion Control | Kurose Lecture Chapter 3.7 | Clear walkthrough of AIMD, slow start, and the state machine |
| Reliable Data Transfer | Kurose Lecture Chapter 3.4 | Step‑by‑step build‑up from rdt 1.0 to pipelining |
| GBN vs SR | Neso Academy — GBN and SR | Animated examples with numerical walkthroughs |
| TCP vs UDP | Computerphile — TCP vs UDP | Concise, intuitive comparison for quick review |

---

> 📝 **Last Updated:** March 2026
>
> 💡 **Study Tip:** After reading these notes, try the Wireshark TCP lab. Seeing real TCP segments, three‑way handshakes, retransmissions, and window changes in a packet capture will solidify everything you've learned here.
>
> 🎯 **Exam Strategy:** Focus on: (1) TCP segment structure, (2) reliable data transfer FSMs (especially rdt 3.0), (3) three‑way handshake, (4) congestion control state machine (slow start → congestion avoidance → fast recovery), and (5) the difference between flow control and congestion control.

---

## 🧠 Quick Recall Summary

- **Transport layer** = process-to-process communication (via port numbers); **Network layer** = host-to-host (via IP)
- **Multiplexing** = gathering data from sockets, adding headers; **Demultiplexing** = delivering segments to correct socket
- **UDP demux**: (dest IP, dest port); **TCP demux**: (src IP, src port, dest IP, dest port) — each connection gets its own socket
- **UDP**: connectionless, no handshake, no reliability, no congestion control; 8-byte header (src port, dest port, length, checksum)
- **UDP checksum**: 1's complement sum of 16-bit words; detects bit errors but doesn't fix them
- **Reliable data transfer evolution**: rdt1.0 (perfect channel) → rdt2.0 (ACK/NAK for bit errors) → rdt2.1 (sequence numbers fix duplicate ACKs) → rdt2.2 (NAK-free, ACK with seq#) → rdt3.0 (timers for packet loss) — stop-and-wait is slow
- **Pipelining** improves utilization: **GBN** (cumulative ACK, retransmit entire window) vs **SR** (individual ACKs, retransmit only lost)
- **TCP**: connection-oriented, full-duplex, point-to-point, byte-stream, reliable, flow + congestion controlled
- **TCP segment**: src/dest port, seq#, ack#, header length, flags (SYN/ACK/FIN/RST), receive window, checksum, urgent pointer, options, data
- **Seq#** = byte offset of first byte in segment; **ACK#** = next byte expected (cumulative)
- **RTT estimation**: EWMA with α=0.125; DevRTT with β=0.25; Timeout = EstimatedRTT + 4×DevRTT
- **TCP reliability**: cumulative ACKs + single retransmission timer + fast retransmit (3 duplicate ACKs → retransmit without waiting for timeout)
- **Flow control**: receiver advertises `rwnd` (spare buffer space); sender limits unacked data ≤ rwnd
- **3-way handshake**: SYN (client→server, initial seq#) → SYN-ACK (server→client, server seq#) → ACK (client→server)
- **Connection teardown**: FIN → ACK → FIN → ACK (4 segments); TIME_WAIT = 2×MSL
- **Congestion control (AIMD)**: additive increase (cwnd += MSS per RTT), multiplicative decrease (cwnd /= 2 on loss)
- **Slow start**: cwnd starts at 1 MSS, doubles every RTT (exponential) until ssthresh
- **Fast recovery**: on 3 dup ACKs → ssthresh = cwnd/2, cwnd = ssthresh + 3, retransmit; on timeout → ssthresh = cwnd/2, cwnd = 1 MSS (back to slow start)
- **Flow control ≠ Congestion control**: flow control prevents overwhelming the *receiver*; congestion control prevents overwhelming the *network*

---

## 🛠 C++ Project Suggestions

### Project 1: `ReliableUDP` — Implement reliable data transfer over UDP

- **Size:** Medium (~500 LOC)
- **Concepts Reinforced:** rdt 3.0, Go-Back-N, Selective Repeat, sequence numbers, ACKs, timers, pipelining
- **Approach:**
  - Build a file transfer application over raw UDP sockets
  - Implement three modes: stop-and-wait (rdt 3.0), GBN, and SR
  - Add configurable packet loss/corruption simulation (randomly drop/corrupt packets)
  - Measure and compare throughput of each mode with different window sizes
  - Use `select()` with timeouts for retransmission timers
- **Libraries:** POSIX sockets (UDP), `<chrono>` for timers, `<random>` for loss simulation

### Project 2: `TCPFromScratch` — A minimal TCP implementation in userspace

- **Size:** Medium-Large (~600 LOC)
- **Concepts Reinforced:** 3-way handshake, seq/ack numbers, sliding window, flow control (rwnd), congestion control (slow start, AIMD, fast retransmit/recovery), connection teardown
- **Approach:**
  - Use raw sockets or a TUN/TAP interface to send/receive IP packets
  - Implement TCP state machine: CLOSED → SYN_SENT → ESTABLISHED → FIN_WAIT → TIME_WAIT
  - Implement RTT estimation (EWMA) and adaptive timeout
  - Implement congestion window with slow start and congestion avoidance
  - Log cwnd over time to visualize the "sawtooth" pattern
- **Libraries:** Raw sockets or `<linux/if_tun.h>` for TUN device; plot cwnd with gnuplot or terminal graphs

### Project 3: `FlowControlDemo` — Visualize TCP flow & congestion control

- **Size:** Small (~250 LOC)
- **Concepts Reinforced:** Receive window, sender-side limiting, congestion window evolution, slow start threshold
- **Approach:**
  - Simulate a sender/receiver pair with configurable buffer sizes and link capacity
  - Sender respects min(cwnd, rwnd) — track both windows over time
  - Inject events: 3 dup ACKs (fast retransmit), timeout, buffer full
  - Output a time-series of cwnd, ssthresh, rwnd, and send rate to terminal/CSV
  - Visualize the state machine transitions (slow start → cong. avoidance → fast recovery)
- **Libraries:** Standard C++, `<fstream>` for CSV output
