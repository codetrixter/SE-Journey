# Chapter 3: Transport Layer 🚀

## Table of Contents

- [Overview](#overview)
- [3.1 Introduction and Transport-Layer Services 📡](#31-introduction-and-transport-layer-services-)
  - [3.1.1 Relationship Between Transport and Network Layers](#311-relationship-between-transport-and-network-layers)
  - [3.1.2 Overview of Transport Layer in the Internet](#312-overview-of-transport-layer-in-the-internet)
- [3.2 Multiplexing and Demultiplexing 🔀](#32-multiplexing-and-demultiplexing-)
  - [3.2.1 Connectionless Multiplexing and Demultiplexing (UDP)](#321-connectionless-multiplexing-and-demultiplexing-udp)
  - [3.2.2 Connection-Oriented Multiplexing and Demultiplexing (TCP)](#322-connection-oriented-multiplexing-and-demultiplexing-tcp)
- [3.3 Connectionless Transport: UDP 📦](#33-connectionless-transport-udp-)
  - [3.3.1 UDP Segment Structure](#331-udp-segment-structure)
  - [3.3.2 UDP Checksum](#332-udp-checksum)
  - [Why UDP?](#why-udp)
- [3.4 Principles of Reliable Data Transfer 🛡️](#34-principles-of-reliable-data-transfer-️)
  - [3.4.1 Building a Reliable Data Transfer Protocol](#341-building-a-reliable-data-transfer-protocol)
  - [3.4.2 Pipelined Reliable Data Transfer Protocols](#342-pipelined-reliable-data-transfer-protocols)
- [3.5 Go-Back-N (GBN) Protocol ⏮️](#35-go-back-n-gbn-protocol-️)
- [3.6 Selective Repeat (SR) Protocol 🎯](#36-selective-repeat-sr-protocol-)
- [3.7 Connection-Oriented Transport: TCP 🔗](#37-connection-oriented-transport-tcp-)
  - [3.7.1 TCP Connection](#371-tcp-connection)
  - [3.7.2 TCP Segment Structure](#372-tcp-segment-structure)
  - [3.7.3 Round-Trip Time Estimation and Timeout](#373-round-trip-time-estimation-and-timeout)
- [3.8 Reliable Data Transfer in TCP 🔒](#38-reliable-data-transfer-in-tcp-)
- [3.9 Flow Control 🌊](#39-flow-control-)
- [3.10 TCP Connection Management 🤝](#310-tcp-connection-management-)
  - [3.10.1 Connection Establishment: Three-Way Handshake](#3101-connection-establishment-three-way-handshake)
  - [3.10.2 Connection Teardown: Four-Way Handshake](#3102-connection-teardown-four-way-handshake)
- [3.11 Principles of Congestion Control 🚦](#311-principles-of-congestion-control-)
  - [3.11.1 The Causes and Costs of Congestion](#3111-the-causes-and-costs-of-congestion)
  - [3.11.2 Approaches to Congestion Control](#3112-approaches-to-congestion-control)
- [3.12 TCP Congestion Control 🎛️](#312-tcp-congestion-control-️)
  - [3.12.1 Classic TCP Congestion Control](#3121-classic-tcp-congestion-control)
  - [3.12.2 TCP Throughput](#3122-tcp-throughput)
  - [3.12.3 TCP Fairness](#3123-tcp-fairness)
- [3.13 Evolution of Transport-Layer Functionality 🚀](#313-evolution-of-transport-layer-functionality-)
  - [3.13.1 Explicit Congestion Notification (ECN)](#3131-explicit-congestion-notification-ecn)
  - [3.13.2 QUIC: Quick UDP Internet Connections](#3132-quic-quick-udp-internet-connections)
- [Summary 📝](#summary-)

---

## Overview

The **Transport Layer** provides logical communication between application processes running on different hosts. It sits between the application layer and the network layer, handling process-to-process communication while the network layer handles host-to-host communication.

---

## 3.1 Introduction and Transport-Layer Services 📡

### 3.1.1 Relationship Between Transport and Network Layers

**Key Distinction:**
- **Network Layer**: Provides logical communication between *hosts*
- **Transport Layer**: Provides logical communication between *processes*

**Analogy**: 
- Network layer = postal service delivering mail between houses
- Transport layer = distributing mail to specific family members within houses

### 3.1.2 Overview of Transport Layer in the Internet

The Internet provides **two distinct transport-layer protocols**:

| Protocol | Full Name | Characteristics |
|----------|-----------|-----------------|
| **TCP** | Transmission Control Protocol | Reliable, connection-oriented, congestion control, flow control |
| **UDP** | User Datagram Protocol | Unreliable, connectionless, lightweight, no congestion control |

**Important Note**: Transport-layer protocols run on end systems, not on network routers.

---

## 3.2 Multiplexing and Demultiplexing 🔀

### Definition

- **Multiplexing** (at sender): Gathering data from multiple sockets, encapsulating with headers, and passing to network layer
- **Demultiplexing** (at receiver): Delivering received segments to correct socket

### How Demultiplexing Works

Transport layer examines fields in the segment to identify the receiving socket:
- **Source port number field** (16 bits)
- **Destination port number field** (16 bits)

**Port Number Ranges:**
- **Well-known ports**: 0-1023 (e.g., HTTP=80, FTP=21, SSH=22)
- **Registered ports**: 1024-49151
- **Dynamic/Private ports**: 49152-65535

### 3.2.1 Connectionless Multiplexing and Demultiplexing (UDP)

🔹 **UDP socket** identified by: `(destination IP, destination port)`

**Key Point**: UDP socket identified by 2-tuple (dest IP, dest port). All segments with same destination IP/port are directed to same socket, regardless of source.

**Example:**
```
Host A (192.168.1.1:9157) → Host B (192.168.1.2:6428)
Host C (192.168.1.3:5775) → Host B (192.168.1.2:6428)
Both arrive at same socket on Host B!
```

### 3.2.2 Connection-Oriented Multiplexing and Demultiplexing (TCP)

🔹 **TCP socket** identified by: `(source IP, source port, destination IP, destination port)`

**Key Point**: TCP socket identified by 4-tuple. Server may support many simultaneous TCP connections, each with its own socket.

**Web Server Example:**
- Server listens on port 80
- Each client connection creates a new socket
- Multiple connections = multiple sockets, all using port 80

---

## 3.3 Connectionless Transport: UDP 📦

### 3.3.1 UDP Segment Structure

**UDP Header Format (8 bytes total):**

```
 0      7 8     15 16    23 24    31
+--------+--------+--------+--------+
|   Source Port   |  Dest Port      |
+--------+--------+--------+--------+
|    Length       |   Checksum      |
+--------+--------+--------+--------+
|        Application Data           |
|          (payload)                |
+-----------------------------------+
```

**Fields:**
- **Source Port** (16 bits): Optional, for return path
- **Destination Port** (16 bits): Destination socket
- **Length** (16 bits): Length of UDP segment (header + data) in bytes
- **Checksum** (16 bits): Error detection

### 3.3.2 UDP Checksum

**Purpose**: Detect errors (flipped bits) in transmitted segment

**Calculation Process:**
1. Treat segment contents as 16-bit integers
2. Compute 1's complement sum of all 16-bit words
3. Take 1's complement of the sum
4. Result is the checksum

**Example:**
```
Word 1: 0110011001100000
Word 2: 0101010101010101
Sum:    1011101110110101
Checksum: 0100010001001010 (1's complement of sum)
```

**At Receiver:**
- Add all 16-bit words including checksum
- If no errors: sum = 1111111111111111
- If errors detected: sum ≠ 1111111111111111

⚠️ **Limitation**: Checksum can detect some but not all errors (e.g., may miss errors when bits flip in compensating ways)

### Why UDP?

**Advantages of UDP:**
1. ✅ **No connection establishment** - No RTT delay
2. ✅ **No connection state** - More clients supported
3. ✅ **Small header overhead** - Only 8 bytes vs TCP's 20 bytes
4. ✅ **No congestion control** - Can blast data as fast as desired

**Use Cases:**
- 🎮 Gaming (real-time, loss-tolerant)
- 📹 Streaming multimedia (loss-tolerant, rate-sensitive)
- 🌐 DNS (simple request-response)
- 📊 SNMP (network management)
- 🎙️ VoIP (some implementations)

---

## 3.4 Principles of Reliable Data Transfer 🛡️

### The Problem

Network layer provides **unreliable service**: packets can be lost, corrupted, reordered, or duplicated.

**Goal**: Implement reliable data transfer over unreliable channel

### 3.4.1 Building a Reliable Data Transfer Protocol

#### rdt 1.0: Reliable Transfer over Reliable Channel

**Assumption**: Underlying channel is perfectly reliable (no bit errors, no packet loss)

**Mechanism**: Simple send and receive
- Sender: `rdt_send()` → `make_pkt()` → `udt_send()`
- Receiver: `rdt_rcv()` → `extract()` → `deliver_data()`

#### rdt 2.0: Channel with Bit Errors

**New Capability Needed**: Detect and recover from bit errors

**Mechanisms Introduced:**
1. 🔍 **Error detection**: Checksum
2. 📢 **Feedback**: ACK (acknowledgment) and NAK (negative acknowledgment)
3. 🔄 **Retransmission**: Resend packets received with errors

**Problem with rdt 2.0**: ACK/NAK themselves can be corrupted!

#### rdt 2.1: Handling Corrupted ACKs/NAKs

**Solution**: Add **sequence numbers** to packets

**Key Points:**
- Sender numbers packets (0, 1, 0, 1, ...)
- Receiver checks sequence number to detect duplicates
- For stop-and-wait protocol, 1-bit sequence number suffices

**Operation:**
```
Sender sends Pkt0 → 
Receiver gets Pkt0, sends ACK → 
ACK corrupted →
Sender retransmits Pkt0 →
Receiver detects duplicate (seq=0), sends ACK
```

#### rdt 2.2: NAK-Free Protocol

**Improvement**: Eliminate NAKs by using **duplicate ACKs**

**Mechanism:**
- Receiver sends ACK for last correctly received packet
- Duplicate ACK indicates error (acts like NAK)

**Example:**
```
Sender sends Pkt0 → Receiver sends ACK0
Sender sends Pkt1 → Pkt1 corrupted
Receiver sends ACK0 again (duplicate ACK)
Sender interprets duplicate ACK0 as NAK, retransmits Pkt1
```

#### rdt 3.0: Channels with Errors and Loss

**New Problem**: Packets can be lost (dropped) entirely

**Solution**: **Timeout mechanism**

**Countdown Timer:**
- Sender starts timer when sending packet
- If timeout occurs before ACK received → retransmit
- Timer must be reasonably longer than RTT

**Edge Cases:**
1. **Premature timeout**: Packet/ACK delayed but not lost
   - Solution: Sequence numbers handle duplicates
2. **ACK lost**: Timeout causes retransmission
   - Solution: Receiver discards duplicate

**Performance Issue**: Stop-and-wait is inefficient!

**Example:**
```
1 Gbps link, 15ms RTT, 8000-bit packet
Transmission time: 8 μs
Utilization: 8 μs / 30.008 ms = 0.027% 😱
```

### 3.4.2 Pipelined Reliable Data Transfer Protocols

**Solution**: Allow multiple in-flight packets (pipelining)

**Requirements:**
1. ↗️ Increase sequence number range
2. 🗃️ Buffer packets at sender/receiver
3. 🎯 Define error recovery strategy

**Two Generic Approaches:**
1. **Go-Back-N (GBN)**
2. **Selective Repeat (SR)**

---

## 3.5 Go-Back-N (GBN) Protocol ⏮️

### Sliding Window Concept

**Window**: Range of sequence numbers allowed to be in-flight

```
[sent & ACK'd] [sent, not ACK'd] [usable, not sent] [not usable]
               ^                 ^                  ^
            send_base         nextseqnum       send_base + N
```

**Parameters:**
- **N**: Window size
- **send_base**: Oldest unacknowledged packet
- **nextseqnum**: Next packet to send

### GBN Sender Operations

1. **Send packet**: If window not full (`nextseqnum < send_base + N`)
   - Create packet, send, start timer (if not running)
   - Increment `nextseqnum`

2. **Receive ACK(n)**: Cumulative acknowledgment
   - All packets up to sequence number `n` acknowledged
   - Move `send_base` to `n+1`

3. **Timeout**: Retransmit ALL packets in window
   - Restart timer

### GBN Receiver Operations

**Simplified Receiver:**
- Only sends cumulative ACKs
- Discards out-of-order packets
- Maintains only `expectedseqnum`

**Actions:**
- If packet `n` received correctly and in-order:
  - Send ACK(n)
  - Deliver data to upper layer
  - Increment `expectedseqnum`
- Otherwise: Discard packet, resend ACK for last in-order packet

### Example: GBN in Action

```
Window size N = 4

Time  Sender                    Receiver
-------------------------------------------
t0    Send Pkt0, Pkt1, Pkt2
t1                              ACK0 (Pkt0 received)
t2                              ACK1 (Pkt1 received)
t3    Send Pkt3                 Pkt2 LOST
t4                              Discard Pkt3, send ACK1
t5    TIMEOUT! Resend Pkt2, Pkt3, ...
```

**Performance:**
- ✅ Simple receiver (no buffering)
- ⚠️ Retransmits correctly received packets when one lost

---

## 3.6 Selective Repeat (SR) Protocol 🎯

### Key Difference from GBN

**SR** avoids unnecessary retransmissions by individually acknowledging correctly received packets.

### SR Windows

**Sender Window**: Packets sent but not yet ACK'd
**Receiver Window**: Packets receiver is willing to receive

**Critical Constraint**: Window size ≤ half the sequence number space
- Prevents ambiguity from delayed packets/ACKs

### SR Sender Operations

1. **Data from above**: If next sequence number in window, send packet
2. **Timeout(n)**: Resend packet `n`, restart timer
3. **ACK(n) received**: 
   - Mark packet `n` as received
   - If `n` is `send_base`, move window forward to next unACK'd packet

### SR Receiver Operations

1. **Packet n in `[rcv_base, rcv_base+N-1]` received correctly:**
   - Send ACK(n)
   - If not previously received: buffer packet
   - If `n == rcv_base`: deliver in-order packets, advance window

2. **Packet n in `[rcv_base-N, rcv_base-1]` received:**
   - Send ACK(n) (might be retransmitted ACK)

3. **Otherwise:** Ignore packet

### SR Example

```
Window size N = 4

Sender Window: [0, 1, 2, 3]
Receiver Window: [0, 1, 2, 3]

Send Pkt0, Pkt1, Pkt2, Pkt3
Pkt1 LOST
Receiver gets: Pkt0 → ACK0, deliver
               Pkt2 → ACK2, buffer
               Pkt3 → ACK3, buffer
Timeout(Pkt1)
Sender resends only Pkt1
Receiver gets Pkt1 → ACK1, deliver Pkt1,2,3
```

**Performance:**
- ✅ Only retransmits packets that were lost
- ⚠️ More complex (receiver buffering, individual timers)

### Dilemma: Sequence Number Space

**Problem**: Small sequence number space can cause ambiguity

**Example:** Window size = 3, Seq numbers = {0,1,2,3}
```
Scenario: Receiver receives Pkt0
Is this NEW Pkt0 or RETRANSMITTED old Pkt0?
```

**Solution**: Window size ≤ sequence number space / 2

---

## 3.7 Connection-Oriented Transport: TCP 🔗

### 3.7.1 TCP Connection

**Key Characteristics:**
- ✅ **Connection-oriented**: Handshaking before data exchange
- ✅ **Full-duplex**: Bidirectional data flow
- ✅ **Point-to-point**: One sender, one receiver (no multicast)
- ✅ **Reliable, in-order byte stream**: No message boundaries
- ✅ **Pipelined**: Window size controlled by flow/congestion control
- ✅ **Send and receive buffers**: Both sides buffer data

**Three-Way Handshake:**
```
Client → Server: SYN
Server → Client: SYN-ACK
Client → Server: ACK (connection established!)
```

### 3.7.2 TCP Segment Structure

**TCP Header (20 bytes minimum):**

```
 0               16              31
+----------------+----------------+
|  Source Port   | Dest Port      |
+----------------+----------------+
|     Sequence Number             |
+----------------+----------------+
|  Acknowledgment Number          |
+----------------+----------------+
|Hlen|Rsv|Flags  | Receive Window |
+----------------+----------------+
|   Checksum     | Urgent Pointer |
+----------------+----------------+
|         Options (if any)        |
+----------------+----------------+
|           Data                  |
```

**Important Fields:**

| Field | Size | Description |
|-------|------|-------------|
| **Sequence Number** | 32 bits | Byte-stream number of first data byte |
| **Acknowledgment Number** | 32 bits | Next byte expected from other side |
| **Receive Window** | 16 bits | Flow control - available buffer space |
| **Header Length** | 4 bits | Length of TCP header in 32-bit words |
| **Flags** | 6 bits | ACK, RST, SYN, FIN, PSH, URG |
| **Checksum** | 16 bits | Error detection (mandatory) |

**TCP Flags:**
- **SYN**: Synchronize sequence numbers (connection setup)
- **ACK**: Acknowledgment field is valid
- **FIN**: Sender finished sending data
- **RST**: Reset connection
- **PSH**: Push data immediately
- **URG**: Urgent data (rarely used)

### 3.7.3 Round-Trip Time Estimation and Timeout

#### Estimating RTT

**Sample RTT** (`SampleRTT`): Time from segment transmission to ACK receipt
- Measured for one segment at a time
- Ignore retransmissions

**Exponential Weighted Moving Average (EWMA):**
```
EstimatedRTT = (1 - α) × EstimatedRTT + α × SampleRTT
```
- Typical α = 0.125
- Smooths out fluctuations

**RTT Deviation:**
```
DevRTT = (1 - β) × DevRTT + β × |SampleRTT - EstimatedRTT|
```
- Typical β = 0.25
- Measures variability

#### Setting Timeout

**Timeout Interval:**
```
TimeoutInterval = EstimatedRTT + 4 × DevRTT
```

**Rationale:** 
- Should be greater than RTT but not too much
- Safety margin accounts for RTT variation

**Timeout Occurs:**
- Double timeout interval (exponential backoff)
- Retransmit earliest unACK'd segment
- Restart timer

---

## 3.8 Reliable Data Transfer in TCP 🔒

### TCP RDT Mechanisms

**1. Sequence Numbers & ACKs:**
- Sequence number = byte-stream number (not segment number!)
- ACK number = next byte expected (cumulative ACK)

**2. Timeout/Retransmission:**
- Single retransmission timer
- Retransmit on timeout

**3. Fast Retransmit:**
- If 3 duplicate ACKs received → retransmit immediately
- Don't wait for timeout!

### TCP Sender Events

**Event 1: Data from Application**
```
1. Create segment with sequence number
2. Start timer if not running
3. Timer expiration interval = TimeoutInterval
```

**Event 2: Timer Timeout**
```
1. Retransmit segment that caused timeout
2. Restart timer
```

**Event 3: ACK Received**
```
1. If ACK acknowledges new data:
   - Update send_base
   - Start timer if there are unACK'd segments
```

### TCP Receiver Events - Generating ACKs

**TCP ACK Generation Policy:**

| Event | TCP Receiver Action |
|-------|---------------------|
| In-order segment arrives, all prior data ACK'd | Delayed ACK: Wait 500ms for next segment. If none, send ACK |
| In-order segment arrives, one delayed ACK pending | Immediately send single cumulative ACK |
| Out-of-order segment arrives (gap detected) | Immediately send duplicate ACK indicating next expected byte |
| Segment arrives that fills gap | Immediately send ACK if segment starts at lower end of gap |

### Fast Retransmit Example

```
Time  Event
-----------------------------------
t0    Send Pkt1 (seq=1)
t1    Send Pkt2 (seq=2)
t2    Send Pkt3 (seq=3)
t3    Send Pkt4 (seq=4)
t4    Receive ACK1
t5    Pkt2 LOST
t6    Receive ACK1 (duplicate, expects seq=2)
t7    Receive ACK1 (duplicate)
t8    Receive ACK1 (3rd duplicate)
t9    FAST RETRANSMIT Pkt2 (don't wait for timeout!)
```

### TCP vs GBN vs SR

| Feature | GBN | SR | TCP |
|---------|-----|-----|-----|
| **Cumulative ACK** | Yes | No | Yes |
| **Selective ACK** | No | Yes | Optional (SACK) |
| **Retransmit on timeout** | All in window | Only timed-out | Smallest unACK'd |
| **Receiver buffering** | No | Yes | Yes |

**TCP is a hybrid:**
- Uses cumulative ACKs (like GBN)
- Buffers out-of-order segments (like SR)
- Retransmits only one segment on timeout
- Fast retransmit for quick recovery

---

## 3.9 Flow Control 🌊

### The Problem

**Scenario:** Fast sender overwhelming slow receiver
- Sender sends data faster than receiver can process
- Receiver's buffer overflows
- Data lost!

### TCP Flow Control Mechanism

**Solution:** Sender maintains **receive window** (`rwnd`)

**Receiver Advertises Available Buffer Space:**
```
rwnd = RcvBuffer - [LastByteRcvd - LastByteRead]
```

**Sender Limits Unacknowledged Data:**
```
LastByteSent - LastByteAcked ≤ rwnd
```

### Flow Control Example

```
Receiver buffer size: 4096 bytes
Application reads 1000 bytes/sec
Sender sends 2000 bytes/sec

Initial: rwnd = 4096
After 1s: rwnd = 4096 - (2000 - 1000) = 3096
After 2s: rwnd = 3096 - (2000 - 1000) = 2096
...
Eventually: rwnd → 0, sender stops!
```

**Zero Window Probe:**
- When `rwnd = 0`, sender still sends 1-byte segments
- Forces receiver to send updated `rwnd`
- Prevents deadlock

---

## 3.10 TCP Connection Management 🤝

### 3.10.1 Connection Establishment: Three-Way Handshake

**Purpose:** 
- Agree on initial sequence numbers
- Allocate resources (buffers, variables)

**Steps:**

```
1️⃣ Client → Server: SYN
   - SYN bit = 1
   - Initial sequence number = client_isn
   
2️⃣ Server → Client: SYN-ACK
   - SYN bit = 1, ACK bit = 1
   - Initial sequence number = server_isn
   - ACK number = client_isn + 1
   
3️⃣ Client → Server: ACK
   - ACK bit = 1
   - ACK number = server_isn + 1
   - Can contain payload data
```

**State Transitions:**
```
Client: CLOSED → SYN_SENT → ESTABLISHED
Server: CLOSED → LISTEN → SYN_RCVD → ESTABLISHED
```

**Why Three-Way? (Why not Two-Way?)**
- Prevents old duplicate connection initiations
- Both sides acknowledge each other's initial sequence numbers

### 3.10.2 Connection Teardown: Four-Way Handshake

**Steps:**

```
1️⃣ Client → Server: FIN
   - FIN bit = 1
   - Client enters FIN_WAIT_1
   
2️⃣ Server → Client: ACK
   - Server enters CLOSE_WAIT
   - Client enters FIN_WAIT_2
   
3️⃣ Server → Client: FIN
   - Server enters LAST_ACK
   
4️⃣ Client → Server: ACK
   - Client enters TIME_WAIT
   - Waits 2 × MSL (Maximum Segment Lifetime)
   - Then enters CLOSED
```

**TIME_WAIT State:**
- Duration: 2 × MSL (typically 30-120 seconds)
- Ensures:
  1. Final ACK received
  2. Old duplicate segments expire

### TCP State Transition Diagram

```
                    +---------+
         +--------->| CLOSED  |<----------+
         |          +---------+           |
         |               | passive open   | close
         | close         | (listen)       |
         |               v                |
         |          +---------+           |
         |     +--->| LISTEN  |           |
         |     |    +---------+           |
         |     | close    | rcv SYN       |
         |     |          | send SYN,ACK  |
         |     |          v               |
         | +---+-----+---------+          |
         | |         | SYN_RCVD|          |
    FIN  | |         +---------+          |
    received |       | rcv ACK            |
         | |         v                    |
active   | |    +-----------+             |
open     | |    |ESTABLISHED|             |
send SYN | |    +-----------+             |
         | |         |                    |
         v |         | close              |
    +---------+      | send FIN           |
    |SYN_SENT |      v                    |
    +---------+ +-----------+        +---------+
         |      | FIN_WAIT_1|        |CLOSE_WAIT
         |      +-----------+        +---------+
         |           |                    |
         +---------->+                    | close
          rcv SYN,ACK                     | send FIN
          send ACK   |                    v
                     |               +---------+
                     |               |LAST_ACK |
                     v               +---------+
              +-----------+               |
              | FIN_WAIT_2|               | rcv ACK
              +-----------+               |
                     |                    |
                     | rcv FIN            |
                     | send ACK           |
                     v                    |
              +-----------+               |
              | TIME_WAIT |               |
              +-----------+               |
                     |                    |
                     +--------------------+
                          timeout
                             |
                             v
                        +---------+
                        | CLOSED  |
                        +---------+
```

---

## 3.11 Principles of Congestion Control 🚦

### 3.11.1 The Causes and Costs of Congestion

**Congestion**: Too many sources sending too much data too fast for network to handle

#### Scenario 1: Two Senders, Infinite Buffers

**Setup:**
- Two hosts sending through router with capacity `R`
- Router has infinite buffers (unrealistic)

**Result:**
- When λ_in > R/2: large queuing delays
- Maximum throughput = R/2 per connection

**Cost of Congestion #1:** 📈 Large queuing delays

#### Scenario 2: Two Senders, Finite Buffers

**Setup:**
- Finite router buffers
- Senders retransmit lost packets

**Result:**
- Sender must send at rate λ_in' > λ_out due to retransmissions
- Retransmissions include:
  - Lost packets (dropped at full buffer)
  - Timed-out but not lost packets (premature timeout)

**Cost of Congestion #2:** 🔄 Unnecessary retransmissions waste capacity

#### Scenario 3: Four Senders, Multi-Hop Paths

**Setup:**
- Four hosts, multi-hop paths
- Finite buffers

**Result:**
- Packets dropped after consuming resources on earlier hops
- Wasted upstream transmission capacity

**Cost of Congestion #3:** 💀 Dropped packet = wasted work by all upstream routers

### 3.11.2 Approaches to Congestion Control

| Approach | Description | Who Controls? | Examples |
|----------|-------------|---------------|----------|
| **End-to-End** | No explicit network feedback; congestion inferred from loss/delay | End systems | TCP (original) |
| **Network-Assisted** | Routers provide explicit feedback (choke packets, ECN bits) | Network + End systems | ATM ABR, TCP ECN |

**TCP Uses End-to-End Congestion Control:**
- Infers congestion from packet loss and delay
- Adjusts sending rate accordingly

---

## 3.12 TCP Congestion Control 🎛️

### 3.12.1 Classic TCP Congestion Control

**Goal:** Maximize throughput while avoiding congestion

**Key Variable: `cwnd` (Congestion Window)**
- Limits rate: `LastByteSent - LastByteAcked ≤ min(cwnd, rwnd)`
- Sending rate ≈ `cwnd / RTT` bytes/sec

### TCP Congestion Control Algorithm: AIMD

**AIMD (Additive Increase, Multiplicative Decrease):**

**Additive Increase (No Congestion):**
- Increase `cwnd` by 1 MSS every RTT (linear increase)
- Probing for available bandwidth

**Multiplicative Decrease (Congestion Detected):**
- Cut `cwnd` in half after loss event
- Quick backoff from congestion

```
      cwnd
       |     /\
       |    /  \    /\
       |   /    \  /  \
       |  /      \/    \
       | /              
       +-------------------> time
       Loss     Loss    Loss
```

### TCP Congestion Control States

#### 1️⃣ Slow Start

**When:** Connection begins, or after timeout

**Behavior:**
- Initial `cwnd` = 1 MSS
- Increase `cwnd` by 1 MSS for each ACK received
- **Exponential growth**: `cwnd` doubles every RTT

**Example:**
```
RTT 0: cwnd = 1 MSS
RTT 1: cwnd = 2 MSS
RTT 2: cwnd = 4 MSS
RTT 3: cwnd = 8 MSS
```

**Exit Conditions:**
1. Timeout → Set `ssthresh = cwnd/2`, `cwnd = 1`, restart slow start
2. `cwnd ≥ ssthresh` → Enter congestion avoidance
3. 3 duplicate ACKs → Set `ssthresh = cwnd/2`, `cwnd = ssthresh`, enter fast recovery

#### 2️⃣ Congestion Avoidance

**When:** `cwnd ≥ ssthresh`

**Behavior:**
- Increase `cwnd` by 1 MSS per RTT (linear growth)
- Implementation: Increase by `MSS × (MSS/cwnd)` per ACK

**Exit Conditions:**
1. Timeout → Set `ssthresh = cwnd/2`, `cwnd = 1`, enter slow start
2. 3 duplicate ACKs → Set `ssthresh = cwnd/2`, `cwnd = ssthresh`, enter fast recovery

#### 3️⃣ Fast Recovery (TCP Reno)

**When:** 3 duplicate ACKs received

**Behavior:**
- `cwnd = ssthresh + 3 MSS` (inflate window)
- Retransmit missing segment (fast retransmit)
- Increase `cwnd` by 1 MSS for each additional duplicate ACK
- When new ACK arrives: `cwnd = ssthresh`, enter congestion avoidance

**Rationale:** Duplicate ACKs indicate packets still flowing

### TCP Congestion Control Diagram

```
             +-------------+
        +--->| Slow Start  |<----+
        |    +-------------+     |
        |        |    |          |
        |        |    | cwnd >= ssthresh
        | timeout|    v          | timeout
        |        | +---------------+
        |        | |   Congestion  |
        |        | |   Avoidance   |
        |        | +---------------+
        |        |     |      |
        |        |     |      | 3 dup ACKs
        |        |     |      v
        |        | +---+  +-----------+
        |        | |      |   Fast    |
        |        | | new  | Recovery  |
        |        +-+ ACK  +-----------+
        |          |          |
        |          +----------+ new ACK
        |                     (to Congestion Avoidance)
        +---------------------+
              timeout
```

### TCP Variants Comparison

| Variant | Loss Detection | Cwnd Reduction | Recovery |
|---------|---------------|----------------|----------|
| **TCP Tahoe** | Timeout or 3 dup ACKs | cwnd = 1 | Slow start always |
| **TCP Reno** | Timeout or 3 dup ACKs | Timeout: cwnd=1<br>3dupACK: cwnd=cwnd/2 | Fast recovery for 3dupACK |
| **TCP NewReno** | Like Reno | Like Reno | Improved fast recovery |
| **TCP CUBIC** | Like Reno | Like Reno | Cubic window growth |

### 3.12.2 TCP Throughput

**Average TCP Throughput:**
```
Average Throughput = (0.75 × W) / RTT
```
Where `W` is window size when loss occurs

**Simplified Model:**
```
Average Throughput ≈ 1.22 × MSS / (RTT × √L)
```
Where `L` is loss rate

**Implications:**
- Throughput ∝ 1/RTT (shorter RTT = higher throughput)
- Throughput ∝ 1/√L (less loss = higher throughput)

### 3.12.3 TCP Fairness

**Question:** Do competing TCP connections get equal share of bandwidth?

**Idealized Analysis (Two Connections):**
- Both connections converge to equal bandwidth share
- AIMD ensures fairness

**Reality:**
- ⚠️ Connections with smaller RTT grab bandwidth faster
- ⚠️ Parallel connections get more bandwidth (web browsers)
- ⚠️ UDP doesn't back off; can crowd out TCP

**Fairness and UDP:**
- UDP has no congestion control
- Can monopolize bandwidth
- Applications need to implement their own congestion control

**Fairness and Parallel TCP Connections:**
- Application opens multiple connections
- Gets N times more bandwidth than single connection
- Example: Web browsers open 6-10 parallel connections

---

## 3.13 Evolution of Transport-Layer Functionality 🚀

### 3.13.1 Explicit Congestion Notification (ECN)

**Concept:** Network routers signal congestion explicitly

**Mechanism:**
- Router sets ECN bits in IP header when experiencing congestion
- Receiver echoes ECN notification in TCP ACK
- Sender reduces `cwnd` without waiting for packet loss

**Benefits:**
- ✅ Earlier congestion detection
- ✅ Fewer packet drops
- ✅ Better performance

**IP Header ECN Field:**
- `00`: Non ECN-capable transport
- `01` or `10`: ECN-capable transport
- `11`: Congestion experienced

**TCP Header ECN Flags:**
- **ECE (ECN-Echo)**: Receiver sets to notify sender of congestion
- **CWR (Congestion Window Reduced)**: Sender sets to acknowledge ECE

### 3.13.2 QUIC: Quick UDP Internet Connections

**Motivation:** TCP ossification - hard to deploy TCP changes

**QUIC Overview:**
- Application-layer protocol on top of UDP
- Provides reliability, congestion control, connection setup
- Used by HTTP/3

**Key Features:**

| Feature | Description | Benefit |
|---------|-------------|---------|
| **Connection Multiplexing** | Multiple streams per connection | No head-of-line blocking |
| **Improved Loss Recovery** | Per-stream loss recovery | One lost packet doesn't block all streams |
| **Faster Connection Setup** | 0-RTT or 1-RTT handshake | Reduced latency |
| **Connection Migration** | Survives IP address changes | Mobile resilience |
| **Encrypted by Default** | TLS 1.3 integrated | Better security & privacy |

**QUIC Connection Setup:**
```
Traditional TCP + TLS:
Client → Server: TCP SYN (1 RTT)
Client ↔ Server: TLS handshake (1-2 RTT)
Total: 2-3 RTT before data

QUIC:
Client → Server: Client Hello (includes data!) (0-1 RTT)
Total: 0-1 RTT before data! ✨
```

**QUIC Streams:**
- Each HTTP request/response on separate stream
- Loss on one stream doesn't block others
- Independent flow control per stream

**Future:** HTTP/3 = HTTP over QUIC

---

## Summary 📝

### Key Takeaways

1. **🔀 Multiplexing & Demultiplexing**
   - Transport layer directs data to correct application process
   - UDP uses 2-tuple (dest IP, dest port), TCP uses 4-tuple (source IP, source port, dest IP, dest port)
   - Port numbers identify processes (0-65535)

2. **📦 UDP: Simple, Unreliable Transport**
   - Connectionless, minimal overhead (8-byte header)
   - No flow control, no congestion control, no reliability
   - Best for real-time, loss-tolerant applications (gaming, streaming, DNS)
   - Checksum provides basic error detection

3. **🛡️ Reliable Data Transfer Principles**
   - Built incrementally: checksums → ACKs/NAKs → sequence numbers → timeouts → pipelining
   - Stop-and-wait is inefficient; pipelining improves utilization
   - Two pipelining approaches: Go-Back-N (cumulative ACK, discard out-of-order) and Selective Repeat (individual ACK, buffer out-of-order)

4. **🔗 TCP: Reliable, Connection-Oriented Transport**
   - Three-way handshake establishes connection; four-way teardown closes it
   - Provides reliable, in-order byte-stream delivery
   - Sequence numbers track bytes (not segments); cumulative ACKs indicate next expected byte
   - Fast retransmit: retransmit on 3 duplicate ACKs without waiting for timeout
   - Adaptive timeout based on RTT estimation with variance

5. **🌊 Flow Control vs Congestion Control**
   - **Flow Control**: Prevents sender from overwhelming receiver (receive window `rwnd`)
   - **Congestion Control**: Prevents sender from overwhelming network (congestion window `cwnd`)
   - Sender rate limited by `min(cwnd, rwnd)`

6. **🎛️ TCP Congestion Control**
   - **AIMD**: Additive Increase (probe for bandwidth), Multiplicative Decrease (back off from congestion)
   - **Three states**: Slow Start (exponential growth), Congestion Avoidance (linear growth), Fast Recovery (after 3 dup ACKs)
   - `ssthresh` divides slow start from congestion avoidance
   - Throughput depends on RTT and loss rate: shorter RTT and lower loss → higher throughput
   - Fairness: competing flows converge to equal shares (ideally), but RTT and parallel connections affect real-world fairness

7. **🚀 Modern Developments**
   - **ECN**: Routers signal congestion explicitly → fewer drops, better performance
   - **QUIC**: HTTP/3's transport protocol, runs over UDP, provides 0-RTT connection setup, stream multiplexing, and connection migration
   - Evolution driven by need for flexibility (UDP-based), lower latency, and better mobile support

---

### Visual Summary: Transport Layer Stack

```
┌─────────────────────────────────────┐
│      Application Layer              │
│   (HTTP, SMTP, FTP, DNS, etc.)     │
└─────────────────────────────────────┘
                 ↕
┌─────────────────────────────────────┐
│      Transport Layer                │
│  ┌─────────────┐  ┌──────────────┐ │
│  │     TCP     │  │     UDP      │ │
│  │  Reliable   │  │  Unreliable  │ │
│  │ Connection  │  │ Connectionless│ │
│  │ Flow Control│  │   Minimal    │ │
│  │ Congestion  │  │   Overhead   │ │
│  │  Control    │  │              │ │
│  └─────────────┘  └──────────────┘ │
└─────────────────────────────────────┘
                 ↕
┌─────────────────────────────────────┐
│       Network Layer (IP)            │
│   (Best-effort, unreliable)         │
└─────────────────────────────────────┘
```

### Protocol Comparison Quick Reference

| Aspect | UDP | TCP |
|--------|-----|-----|
| **Connection** | ❌ Connectionless | ✅ Connection-oriented |
| **Reliability** | ❌ Unreliable | ✅ Reliable |
| **Ordering** | ❌ No guarantees | ✅ In-order delivery |
| **Flow Control** | ❌ No | ✅ Yes (rwnd) |
| **Congestion Control** | ❌ No | ✅ Yes (cwnd, AIMD) |
| **Header Size** | 8 bytes | 20-60 bytes |
| **Speed** | ⚡ Fast | 🐢 Slower (overhead) |
| **Use Cases** | Streaming, gaming, DNS | Web, email, file transfer |

---

**End of Chapter 3: Transport Layer** 🎓

*These notes cover the fundamental concepts of the Transport Layer, focusing on UDP and TCP protocols, reliable data transfer mechanisms, flow control, congestion control, and modern developments like ECN and QUIC. Master these concepts to understand how applications communicate reliably over unreliable networks!*