# Chapter 8: Network Security

---

## 📑 Table of Contents

1. [What Is Network Security?](#1-what-is-network-security)
   - [1.1 Security Goals (CIA Triad + More)](#11-security-goals-cia-triad--more)
   - [1.2 Threat Landscape Overview](#12-threat-landscape-overview)
   - [1.3 Intruder Categories](#13-intruder-categories)
2. [Principles of Cryptography](#2-principles-of-cryptography)
   - [2.1 Symmetric‑Key Cryptography](#21-symmetrickey-cryptography)
   - [2.2 Public‑Key (Asymmetric) Cryptography](#22-publickey-asymmetric-cryptography)
   - [2.3 Symmetric vs Asymmetric — Comparison](#23-symmetric-vs-asymmetric--comparison)
   - [2.4 Session Keys — Best of Both Worlds](#24-session-keys--best-of-both-worlds)
3. [Message Integrity and Digital Signatures](#3-message-integrity-and-digital-signatures)
   - [3.1 Cryptographic Hash Functions](#31-cryptographic-hash-functions)
   - [3.2 Message Authentication Code (MAC)](#32-message-authentication-code-mac)
   - [3.3 Digital Signatures](#33-digital-signatures)
   - [3.4 Public Key Certification & CAs](#34-public-key-certification--cas)
4. [End‑Point Authentication](#4-endpoint-authentication)
   - [4.1 Authentication Protocols](#41-authentication-protocols)
   - [4.2 Nonces and Challenge–Response](#42-nonces-and-challengeresponse)
5. [Securing E‑Mail](#5-securing-email)
   - [5.1 Secure E‑Mail Requirements](#51-secure-email-requirements)
   - [5.2 PGP (Pretty Good Privacy)](#52-pgp-pretty-good-privacy)
6. [Securing TCP Connections: SSL/TLS](#6-securing-tcp-connections-ssltls)
   - [6.1 The Big Picture](#61-the-big-picture)
   - [6.2 TLS Handshake — Step by Step](#62-tls-handshake--step-by-step)
   - [6.3 TLS Record Protocol](#63-tls-record-protocol)
   - [6.4 TLS 1.3 Improvements](#64-tls-13-improvements)
7. [Network‑Layer Security: IPsec and VPNs](#7-networklayer-security-ipsec-and-vpns)
   - [7.1 IPsec Overview](#71-ipsec-overview)
   - [7.2 Security Associations (SAs)](#72-security-associations-sas)
   - [7.3 AH vs ESP](#73-ah-vs-esp)
   - [7.4 Tunnel Mode vs Transport Mode](#74-tunnel-mode-vs-transport-mode)
   - [7.5 IKE (Internet Key Exchange)](#75-ike-internet-key-exchange)
   - [7.6 VPN (Virtual Private Network)](#76-vpn-virtual-private-network)
8. [Securing Wireless LANs and 4G/5G](#8-securing-wireless-lans-and-4g5g)
   - [8.1 WEP (and Why It Failed)](#81-wep-and-why-it-failed)
   - [8.2 WPA / WPA2 / WPA3 (IEEE 802.11i)](#82-wpa--wpa2--wpa3-ieee-80211i)
   - [8.3 4G/5G Cellular Security](#83-4g5g-cellular-security)
9. [Firewalls and Intrusion Detection Systems](#9-firewalls-and-intrusion-detection-systems)
   - [9.1 Firewalls](#91-firewalls)
   - [9.2 Intrusion Detection Systems (IDS)](#92-intrusion-detection-systems-ids)
   - [9.3 Intrusion Prevention Systems (IPS)](#93-intrusion-prevention-systems-ips)
10. [Attacks on Networks](#10-attacks-on-networks)
    - [10.1 Malware](#101-malware)
    - [10.2 Denial‑of‑Service (DoS / DDoS)](#102-denialofservice-dos--ddos)
    - [10.3 Packet Sniffing](#103-packet-sniffing)
    - [10.4 IP Spoofing](#104-ip-spoofing)
    - [10.5 Man‑in‑the‑Middle (MITM)](#105-manintheMiddle-mitm)
    - [10.6 DNS Attacks](#106-dns-attacks)
11. [Summary](#11-summary)
12. [Additional References](#12-additional-references)

---

## 1. What Is Network Security?

Network security is concerned with **protecting data and systems** during communication across networks. It isn't a single technology — it's a *collection of policies, techniques, protocols, and tools* designed to prevent, detect, and respond to threats.

### 1.1 Security Goals (CIA Triad + More)

| Goal | Meaning | Example |
|---|---|---|
| **Confidentiality** | Only sender & intended receiver understand message contents | Encryption prevents eavesdropping |
| **Integrity** | Message is not altered in transit | Hash/MAC detects tampering |
| **Availability** | Services remain accessible to legitimate users | DoS protection keeps servers online |
| **Authentication** | Confirm the identity of the communicating party | Digital certificates verify a web server |
| **Non‑repudiation** | Sender cannot deny having sent a message | Digital signatures provide proof of origin |

> 🧠 **Memory Tip — "CIA‑AN"**: **C**onfidentiality, **I**ntegrity, **A**vailability, **A**uthentication, **N**on‑repudiation.

### 1.2 Threat Landscape Overview

```
                        ┌──────────────────────┐
                        │   NETWORK  THREATS    │
                        └──────────┬───────────┘
           ┌───────────┬───────────┼───────────┬──────────┐
           ▼           ▼           ▼           ▼          ▼
      Eavesdrop    Tampering   Spoofing     DoS/DDoS   Malware
     (sniffing)   (modify     (fake        (flood      (virus,
                   packets)    identity)    resources)  worm,
                                                       trojan)
```

### 1.3 Intruder Categories

- **Passive attacker** — eavesdrops; does *not* modify data (e.g., packet sniffing).
- **Active attacker** — modifies, injects, deletes, or replays messages.

> ✅ **Key Point**: A secure channel must protect against **both** passive and active attacks.

---

## 2. Principles of Cryptography

Cryptography is the **foundation** of network security. It transforms readable data (*plaintext*) into unreadable form (*ciphertext*) and back again.

**Core terminology:**

| Term | Definition |
|---|---|
| **Plaintext** | Original readable message |
| **Ciphertext** | Encrypted (scrambled) message |
| **Key** | Secret parameter controlling encryption/decryption |
| **Cipher** | Algorithm used for encryption/decryption |
| **Encrypt** | Plaintext → Ciphertext |
| **Decrypt** | Ciphertext → Plaintext |

### 2.1 Symmetric‑Key Cryptography

Both sender and receiver share the **same secret key**.

```
   Alice                                       Bob
     │                                          │
     │  plaintext ──► [ Encrypt(K) ] ──► ciphertext ──► [ Decrypt(K) ] ──► plaintext
     │                     ▲                                   ▲
     │                     │                                   │
     └─────── same key K ──┴───────────────────────────────────┘
```

**Classical ciphers (historical context):**

- **Caesar cipher** — shift each letter by a fixed number of positions. Trivially breakable (only 25 possible keys).
- **Monoalphabetic cipher** — arbitrary 1‑to‑1 letter substitution. Key space = 26! ≈ 4 × 10²⁶, but vulnerable to **frequency analysis**.
- **Polyalphabetic cipher (Vigenère)** — uses multiple monoalphabetic substitutions, cycling through a keyword. Harder to break but still classically vulnerable.

**Modern symmetric ciphers:**

#### Block Ciphers

- Operate on fixed‑size blocks of plaintext (e.g., 64‑bit or 128‑bit).
- **DES (Data Encryption Standard)**
  - 56‑bit key, 64‑bit block.
  - 16 rounds of Feistel network.
  - ⚠️ **No longer considered secure** — 56‑bit key is brute‑forceable.
- **3DES (Triple DES)**
  - Applies DES three times with 2 or 3 keys.
  - Effective key length: 112 bits.
  - Slower but more secure than single DES.
- **AES (Advanced Encryption Standard)** ✅
  - 128‑bit block, key sizes: 128, 192, or 256 bits.
  - 10/12/14 rounds depending on key size.
  - Current gold standard for symmetric encryption.

#### Block Cipher Modes of Operation

| Mode | Description | Notes |
|---|---|---|
| **ECB** (Electronic Codebook) | Each block encrypted independently | ⚠️ Identical plaintext blocks → identical ciphertext blocks — leaks patterns |
| **CBC** (Cipher Block Chaining) | Each block XORed with previous ciphertext block before encryption | Requires IV; much more secure than ECB |
| **CTR** (Counter) | Encrypts a sequential counter, XORs result with plaintext | Parallelizable; acts as a stream cipher |

> ⚠️ **Common Mistake**: Never use ECB mode for real‑world encryption. The famous "ECB penguin" image demonstrates how patterns leak through.

> 🧠 **Memory Tip**: **ECB** = "**E**ach **C**hunk is **B**lind" (doesn't see other blocks).

#### Stream Ciphers

- Encrypt one bit (or byte) at a time.
- Generate a **pseudorandom keystream** from the key; XOR with plaintext.
- Example: **RC4** (historically used in WEP and early TLS; now deprecated).

### 2.2 Public‑Key (Asymmetric) Cryptography

Each entity has a **key pair**: a *public key* (shared openly) and a *private key* (kept secret).

```
   Alice                                              Bob
     │                                                 │
     │  plaintext ──► [ Encrypt(Bob's public key) ] ──► ciphertext
     │                                                 │
     │                   ciphertext ──► [ Decrypt(Bob's private key) ] ──► plaintext
```

- **Anyone** can encrypt with Bob's public key.
- **Only Bob** can decrypt with his private key.

**RSA Algorithm — step by step:**

1. Choose two large primes **p** and **q**.
2. Compute **n = p × q**.
3. Compute **ϕ(n) = (p − 1)(q − 1)**.
4. Choose **e** such that **1 < e < ϕ(n)** and **gcd(e, ϕ(n)) = 1**.
5. Compute **d** such that **e × d ≡ 1 (mod ϕ(n))** (i.e., d is the modular inverse of e).
6. **Public key** = (n, e); **Private key** = (n, d).
7. **Encrypt**: c = m^e mod n
8. **Decrypt**: m = c^d mod n

> 🧠 **Analogy**: Think of RSA like a **mailbox**. Anyone can **drop a letter in** (encrypt with public key), but only the owner with the **mailbox key** can **open it** (decrypt with private key).

> 📌 **Exam Tip**: RSA's security relies on the computational difficulty of **factoring large numbers**. If you can factor *n*, you can find *p*, *q*, *ϕ(n)*, and thus *d*.

**Diffie‑Hellman Key Exchange:**

- Not an encryption algorithm per se — it's a method for two parties to **agree on a shared secret** over an insecure channel.
- Based on the difficulty of the **discrete logarithm problem**.
- Vulnerable to **man‑in‑the‑middle** attacks if not combined with authentication.

**Step‑by‑step:**

1. Alice and Bob publicly agree on a prime **p** and generator **g**.
2. Alice picks a secret **a**, sends Bob **A = g^a mod p**.
3. Bob picks a secret **b**, sends Alice **B = g^b mod p**.
4. Alice computes **s = B^a mod p**.
5. Bob computes **s = A^b mod p**.
6. Both arrive at the **same shared secret s = g^(ab) mod p**.

### 2.3 Symmetric vs Asymmetric — Comparison

| Feature | Symmetric | Asymmetric |
|---|---|---|
| Keys | One shared key | Key pair (public + private) |
| Speed | **Fast** (100–1000× faster) | **Slow** |
| Key distribution | Hard (must securely share key) | Easy (public key is public) |
| Use case | Bulk data encryption | Key exchange, digital signatures |
| Examples | AES, DES, 3DES, ChaCha20 | RSA, Diffie‑Hellman, ECC |
| Key length (equiv. security) | 128 bits | ~3072 bits (RSA) |

### 2.4 Session Keys — Best of Both Worlds

In practice, protocols like TLS use **hybrid encryption**:

1. **Asymmetric** crypto to securely exchange a short‑lived **session key**.
2. **Symmetric** crypto (with the session key) for fast bulk data encryption.

```
  Alice                            Bob
    │  ── RSA/DH key exchange ──►  │     (slow, but only once)
    │  ◄── shared session key ──►  │
    │  ── AES(session key, data) ─► │   (fast, for all data)
```

> ✅ **Key Point**: Almost no real‑world protocol uses *only* asymmetric encryption for data — it's too slow.

---

## 3. Message Integrity and Digital Signatures

Even with encryption, we need to ensure messages haven't been **tampered with** and truly come from the claimed sender.

### 3.1 Cryptographic Hash Functions

A hash function **H(m)** takes an arbitrary‑length message *m* and produces a fixed‑length **digest** (hash).

**Required properties:**

| Property | Meaning |
|---|---|
| **Deterministic** | Same input → same output, always |
| **Fast** | Efficient to compute |
| **Pre‑image resistant** | Given H(m), infeasible to find m |
| **Second pre‑image resistant** | Given m₁, infeasible to find m₂ ≠ m₁ with H(m₁) = H(m₂) |
| **Collision resistant** | Infeasible to find *any* m₁ ≠ m₂ with H(m₁) = H(m₂) |

**Common hash functions:**

| Algorithm | Digest Size | Status |
|---|---|---|
| MD5 | 128 bits | ⚠️ Broken — collisions found |
| SHA‑1 | 160 bits | ⚠️ Deprecated — collisions demonstrated (SHAttered, 2017) |
| SHA‑256 | 256 bits | ✅ Widely used (SHA‑2 family) |
| SHA‑3 | 256 bits | ✅ Latest standard (Keccak) |

> 🧠 **Analogy**: A hash is like a **fingerprint**. Two different people (messages) should never share the same fingerprint (hash). If they do, that's a "collision."

### 3.2 Message Authentication Code (MAC)

A MAC combines a **message** and a **shared secret key** to produce an authentication tag.

```
  Sender:  tag = MAC(key, message)          →  sends (message, tag)
  Receiver: tag' = MAC(key, message)        →  verifies tag == tag'
```

**HMAC (Hash‑based MAC):**
- Most widely used MAC construction.
- HMAC(K, m) = H( (K ⊕ opad) || H( (K ⊕ ipad) || m ) )
- Used in TLS, IPsec, SSH, etc.

> ✅ **Key Point**: A hash alone does NOT provide authentication — an attacker can change both the message and its hash. A MAC requires the *secret key*, preventing forgery.

> ⚠️ **Common Mistake**: Confusing *encryption* with *integrity*. Encryption provides confidentiality, **not** integrity. You need a MAC or digital signature for integrity.

### 3.3 Digital Signatures

Digital signatures use **asymmetric cryptography** to provide:
- **Integrity** — message hasn't been altered.
- **Authentication** — confirms the signer's identity.
- **Non‑repudiation** — signer cannot deny signing.

**How it works:**

1. Alice computes the hash of the message: **h = H(m)**.
2. Alice encrypts the hash with her **private key**: **sig = Encrypt(K_A_private, h)**.
3. Alice sends **(m, sig)** to Bob.
4. Bob decrypts the signature with Alice's **public key**: **h' = Decrypt(K_A_public, sig)**.
5. Bob independently hashes the message: **h'' = H(m)**.
6. If **h' == h''**, the signature is valid. ✅

```
  Alice (signing)                          Bob (verifying)
  ─────────────                            ────────────────
  m ──► H(m) = h                           Receive (m, sig)
  h ──► Encrypt(privA, h) = sig            sig ──► Decrypt(pubA, sig) = h'
  Send (m, sig) ──────────────────────►    m ──► H(m) = h''
                                           h' == h'' ? ✅ Valid : ❌ Forged
```

> 🧠 **Memory Tip**: "**Sign** with **private**, **verify** with **public**" — the opposite direction from encryption.

> 📌 **Exam Tip**: Digital signatures use the *private key to sign* (not encrypt the data) and the *public key to verify*. This is the **reverse** of public‑key encryption where you encrypt with the public key and decrypt with the private key.

### 3.4 Public Key Certification & CAs

**Problem**: How does Bob know that a public key really belongs to Alice and not an impersonator?

**Solution**: **Certificate Authorities (CAs)**.

A **digital certificate** binds a public key to an identity. It contains:
- Subject's name (e.g., www.example.com)
- Subject's public key
- Issuer (CA) name
- Validity period
- CA's digital signature over all the above

**Certificate chain of trust:**

```
  Root CA (self‑signed, pre‑installed in browsers/OS)
      │
      ├──► Intermediate CA (signed by Root CA)
      │        │
      │        └──► End‑entity certificate (signed by Intermediate CA)
      │             e.g., www.example.com
```

> 🧠 **Analogy**: A CA is like a **notary public**. Just as a notary verifies your identity and stamps a document, a CA verifies an entity's identity and signs their public key certificate.

> ⚠️ **Common Mistake**: Assuming the root CA certificates are verified by someone "above." Root CAs are **self‑signed** and trusted because they are **pre‑installed** in the OS/browser trust store.

---

## 4. End‑Point Authentication

Authentication answers: **"Are you really who you claim to be?"**

### 4.1 Authentication Protocols

**Progression of increasingly secure protocols:**

| Protocol | Method | Vulnerability |
|---|---|---|
| ap1.0 | "I am Alice" (plain statement) | Anyone can claim to be Alice |
| ap2.0 | "I am Alice" + source IP address | IP spoofing defeats this |
| ap3.0 | "I am Alice" + password | Playback (replay) attack — attacker records and resends |
| ap3.1 | "I am Alice" + encrypted password | Still vulnerable to replay |
| ap4.0 | Nonce‑based challenge–response | ✅ Secure against replay |

### 4.2 Nonces and Challenge–Response

A **nonce** is a number used **once** — it ensures freshness and prevents replay attacks.

**Protocol ap4.0 (symmetric key version):**

1. Alice says: "I am Alice."
2. Bob sends a **nonce R** (random number).
3. Alice encrypts the nonce with their shared secret: sends **Encrypt(K, R)**.
4. Bob decrypts and checks if R matches. If yes → Alice is authenticated. ✅

**Protocol ap5.0 (public key version):**

1. Alice says: "I am Alice."
2. Bob sends nonce **R**.
3. Alice signs R with her private key: sends **Encrypt(K_A_private, R)**.
4. Bob decrypts with Alice's public key. If R matches → authenticated. ✅

> ⚠️ **Common Mistake**: ap5.0 is vulnerable to a **man‑in‑the‑middle** attack if Bob doesn't have a **certified** copy of Alice's public key. Trudy can intercept and substitute her own public key.

---

## 5. Securing E‑Mail

### 5.1 Secure E‑Mail Requirements

| Requirement | How Achieved |
|---|---|
| Confidentiality | Encrypt message body |
| Authentication | Digital signature |
| Integrity | Hash + signature |
| Non‑repudiation | Digital signature |

### 5.2 PGP (Pretty Good Privacy)

PGP provides **confidentiality + integrity + authentication** for e‑mail.

**PGP sending process (Alice → Bob):**

1. Alice generates a random **symmetric session key K_S**.
2. Alice **encrypts the message** with K_S (using AES or similar): **C = Encrypt(K_S, m)**.
3. Alice **encrypts K_S** with Bob's public key: **Encrypt(K_B_pub, K_S)**.
4. Alice **signs the message hash** with her private key: **sig = Sign(K_A_priv, H(m))**.
5. Alice sends: **(C, Encrypt(K_B_pub, K_S), sig)**.

**PGP receiving process (Bob):**

1. Bob decrypts K_S using his private key.
2. Bob decrypts the message using K_S.
3. Bob verifies the signature using Alice's public key.

```
  ┌──────────────────────────────────────────────────────────────┐
  │                     PGP — Alice Sends to Bob                 │
  │                                                              │
  │  m ──► H(m) ──► Sign(K_A_priv) ──► sig                      │
  │  m ──► Encrypt(K_S) ──► ciphertext                           │
  │  K_S ──► Encrypt(K_B_pub) ──► encrypted session key          │
  │                                                              │
  │  Send: { ciphertext, encrypted session key, sig }            │
  └──────────────────────────────────────────────────────────────┘
```

> ✅ **Key Point**: PGP uses the hybrid approach — asymmetric for key exchange, symmetric for bulk encryption.

> 🧠 **Analogy**: PGP is like sending a package in a **locked box** (symmetric encryption) with the **box key sealed in a smaller envelope** that only the recipient can open (asymmetric encryption), and your **wax seal** on the box proving it's from you (digital signature).

**PGP Trust Model: Web of Trust**
- Unlike TLS/SSL (which uses CAs), PGP uses a **decentralized** trust model.
- Users sign each other's public keys.
- If you trust Alice and Alice has signed Bob's key, you can transitively trust Bob's key.

---

## 6. Securing TCP Connections: SSL/TLS

### 6.1 The Big Picture

**SSL (Secure Sockets Layer)** was developed by Netscape. It evolved into **TLS (Transport Layer Security)**, which is the current standard.

- Operates **between the application layer and transport layer** (often described as sitting on top of TCP).
- Provides: **confidentiality**, **integrity**, **authentication** (of the server, and optionally the client).
- Used in: **HTTPS**, secure email (SMTPS, IMAPS), VPN tunnels, etc.

```
  ┌───────────────┐
  │  Application  │  (HTTP, SMTP, etc.)
  ├───────────────┤
  │   TLS/SSL     │  ◄── security layer
  ├───────────────┤
  │     TCP       │
  ├───────────────┤
  │      IP       │
  └───────────────┘
```

**TLS provides a "secure socket" API** to applications, so applications can use it just like regular TCP but with security.

### 6.2 TLS Handshake — Step by Step

The handshake establishes: the TLS version, cipher suite, server authentication, and a shared secret.

```
  Client                                        Server
    │                                              │
    │ ──── 1. ClientHello ────────────────────►    │
    │      (TLS version, cipher suites,            │
    │       client random)                         │
    │                                              │
    │ ◄─── 2. ServerHello ────────────────────     │
    │      (chosen cipher suite, server random)    │
    │                                              │
    │ ◄─── 3. Server Certificate ─────────────     │
    │      (X.509 cert with server's public key)   │
    │                                              │
    │ ◄─── 4. ServerHelloDone ────────────────     │
    │                                              │
    │ ──── 5. ClientKeyExchange ──────────────►    │
    │      (pre‑master secret encrypted with       │
    │       server's public key)                   │
    │                                              │
    │ ──── 6. ChangeCipherSpec ───────────────►    │
    │ ──── 7. Finished (encrypted) ───────────►    │
    │                                              │
    │ ◄─── 8. ChangeCipherSpec ───────────────     │
    │ ◄─── 9. Finished (encrypted) ───────────     │
    │                                              │
    │ ◄════ Encrypted Application Data ══════►     │
```

**Detailed walkthrough:**

1. **ClientHello**: Client proposes supported TLS versions, cipher suites, and sends a **client random** (28‑byte random number).
2. **ServerHello**: Server selects the TLS version and cipher suite. Sends a **server random**.
3. **Certificate**: Server sends its **X.509 certificate** (containing its public key), signed by a trusted CA.
4. **ServerHelloDone**: Signals that the server is done with hello messages.
5. **ClientKeyExchange**: Client generates a **pre‑master secret (PMS)**, encrypts it with the server's public key, and sends it.
6. **Key Derivation**: Both sides now have: client random, server random, PMS. They independently derive **four session keys** (explained below).
7. **ChangeCipherSpec + Finished**: Both sides switch to encrypted communication and send a "Finished" message encrypted with the derived keys — verifying the handshake.

**Key Derivation — Four Session Keys:**

From (client random + server random + PMS), both sides derive:

| Key | Purpose |
|---|---|
| **E_c** | Encryption key for client → server data |
| **E_s** | Encryption key for server → client data |
| **M_c** | MAC key for client → server data |
| **M_s** | MAC key for server → client data |

> 🧠 **Memory Tip**: "**2E + 2M**" — two encryption keys (one per direction) and two MAC keys (one per direction).

> 📌 **Exam Tip**: The reason for separate keys per direction is **security isolation** — compromising one direction's key doesn't automatically compromise the other.

### 6.3 TLS Record Protocol

After the handshake, application data is processed as:

1. **Fragment** the data into manageable blocks.
2. **Compress** (optional, often disabled due to CRIME attack).
3. **MAC**: Append HMAC for integrity.
4. **Encrypt**: Encrypt (data + MAC) using the session key.
5. **Add TLS record header**: content type, version, length.

```
  ┌──────────────┬─────────────┬─────────────┬────────────────┐
  │ TLS Record   │  Encrypted  │             │                │
  │ Header       │  Data       │  MAC        │  Padding       │
  │ (type,ver,   │             │             │  (for block    │
  │  length)     │             │             │   cipher)      │
  └──────────────┴─────────────┴─────────────┴────────────────┘
```

**Sequence numbers** are included in the MAC computation (but NOT sent in the record) to prevent **reordering** and **replay** attacks.

### 6.4 TLS 1.3 Improvements

TLS 1.3 (RFC 8446, 2018) is a major overhaul:

| Improvement | Detail |
|---|---|
| **Faster handshake** | 1‑RTT handshake (vs 2‑RTT in TLS 1.2); 0‑RTT resumption possible |
| **Removed weak algorithms** | No more RSA key exchange, RC4, SHA‑1, CBC mode, etc. |
| **Forward secrecy mandatory** | Only Diffie‑Hellman–based key exchange (ephemeral); even if long‑term key is compromised, past sessions remain secure |
| **Encrypted handshake** | More of the handshake is encrypted (including certificate) |
| **Simplified cipher suites** | Only 5 cipher suites (vs dozens in 1.2) |

> ✅ **Key Point — Forward Secrecy**: If the server's private key is later stolen, an attacker **cannot** decrypt previously captured TLS 1.3 sessions (because each session used a unique ephemeral DH key).

> 🧠 **Analogy**: Forward secrecy is like burning the unique key to a lock after each conversation — even if someone later steals your master key ring, they can't open old locked boxes because those one‑time keys no longer exist.

---

## 7. Network‑Layer Security: IPsec and VPNs

### 7.1 IPsec Overview

IPsec provides security at the **network layer (IP)**:
- **Confidentiality** — encrypts IP payloads.
- **Integrity** — ensures IP packets aren't modified.
- **Authentication** — verifies the source of IP packets.

IPsec is **transparent to applications** — unlike TLS, applications don't need to be modified.

### 7.2 Security Associations (SAs)

Before secure communication, two endpoints establish a **Security Association (SA)** — a **one‑way** logical connection with agreed security parameters.

An SA includes:
- **SPI (Security Parameter Index)** — identifies the SA.
- **Encryption algorithm** and key.
- **Authentication algorithm** and key.
- **SA lifetime**.

> ⚠️ **Common Mistake**: An SA is **unidirectional**. For two‑way communication, you need **two SAs** (one in each direction).

The **SAD (Security Association Database)** stores all active SAs. The **SPD (Security Policy Database)** determines *which* traffic should be protected and *how*.

### 7.3 AH vs ESP

IPsec defines two main protocols:

| Feature | **AH** (Authentication Header) | **ESP** (Encapsulating Security Payload) |
|---|---|---|
| Authentication | ✅ Yes | ✅ Yes |
| Integrity | ✅ Yes (including outer IP header) | ✅ Yes (payload only) |
| Confidentiality | ❌ No | ✅ Yes (encrypts payload) |
| Protocol Number | 51 | 50 |
| Usage | Rare today | **Most commonly used** |

> 📌 **Exam Tip**: ESP is far more common because it provides **confidentiality** in addition to integrity and authentication. AH cannot encrypt.

### 7.4 Tunnel Mode vs Transport Mode

| Mode | What's Protected | Use Case |
|---|---|---|
| **Transport** | Only the IP **payload** is encrypted/authenticated; original IP header remains | Host‑to‑host |
| **Tunnel** | The **entire original IP packet** is encapsulated inside a new IP packet and encrypted | **Gateway‑to‑gateway (VPN)** — most common |

**Tunnel mode packet structure (ESP):**

```
  ┌────────────┬─────┬──────────────────────────────────────────┬──────────┬──────┐
  │ New IP Hdr │ ESP │  [ Original IP Header | Original Data ] │ ESP      │ ESP  │
  │            │ Hdr │  ◄──── encrypted ────────────────────►   │ Trailer  │ Auth │
  └────────────┴─────┴──────────────────────────────────────────┴──────────┴──────┘
```

> 🧠 **Analogy**: **Tunnel mode** is like putting a sealed letter inside a *new* envelope — even the destination address on the inner envelope is hidden. **Transport mode** is like sealing the letter content but leaving the same envelope.

### 7.5 IKE (Internet Key Exchange)

IKE automates the creation of SAs — negotiating algorithms, exchanging keys, and authenticating peers.

**IKE operates in two phases:**

1. **Phase 1 (IKE SA)**: Establish a secure channel between peers.
   - Authenticate each other (pre‑shared key or certificates).
   - Establish an IKE SA (for managing subsequent SAs).
2. **Phase 2 (IPsec SA)**: Use the IKE SA to negotiate the actual IPsec SAs for data traffic.

IKEv2 (RFC 7296) simplifies this to fewer message exchanges.

### 7.6 VPN (Virtual Private Network)

A VPN uses **IPsec tunnel mode** to create a secure "tunnel" over the public Internet.

```
  Branch Office                           Headquarters
  ┌──────────┐     ┌─────────────┐     ┌──────────┐
  │ Internal │◄───►│ VPN Gateway │◄═══►│ VPN Gateway │◄───►│ Internal │
  │ Network  │     │ (IPsec)     │     │ (IPsec)     │     │ Network  │
  └──────────┘     └─────────────┘     └──────────────┘     └──────────┘
                          ▲                    ▲
                          └──── Public Internet ───┘
                               (encrypted tunnel)
```

**Benefits:**
- Traffic between sites is encrypted — eavesdroppers on the public Internet see only encrypted packets addressed to the VPN gateways.
- Internal IP addresses are hidden.
- Much cheaper than dedicated leased lines.

---

## 8. Securing Wireless LANs and 4G/5G

Wireless is inherently less secure than wired — anyone within radio range can intercept signals.

### 8.1 WEP (and Why It Failed)

**WEP (Wired Equivalent Privacy)** was the original 802.11 security protocol.

**Design:**
- Uses RC4 stream cipher.
- 40‑bit (or 104‑bit) key + 24‑bit **Initialization Vector (IV)**.
- CRC‑32 for integrity.

**Why WEP is broken:**
1. **IV is only 24 bits** → only ~16.7 million possible IVs → IVs repeat quickly on a busy network.
2. When IVs repeat, attackers can XOR two ciphertexts to cancel out the keystream, revealing plaintext relationships.
3. **CRC‑32 is not cryptographically secure** — attackers can modify packets and fix the CRC without knowing the key.
4. **Static shared key** — same key used by all devices; no per‑user or per‑session key.
5. **No mutual authentication** — client doesn't authenticate the AP.

> ⚠️ **Common Mistake**: Thinking WEP is "good enough." WEP can be cracked in **minutes** with freely available tools (e.g., aircrack‑ng).

### 8.2 WPA / WPA2 / WPA3 (IEEE 802.11i)

| Feature | WPA | WPA2 | WPA3 |
|---|---|---|---|
| Encryption | TKIP (RC4‑based) | **AES‑CCMP** | AES‑CCMP / AES‑GCMP |
| Key management | 802.1X / PSK | 802.1X / PSK | **SAE** (Simultaneous Auth of Equals) |
| IV length | 48 bits | 48 bits | — |
| Integrity | Michael MIC | CBC‑MAC | GCM |
| Status | Deprecated | ✅ Currently dominant | ✅ Recommended |
| Forward secrecy | ❌ | ❌ | ✅ |

**802.11i / WPA2 — Four‑Phase Operation:**

1. **Discovery**: Client and AP agree on security capabilities.
2. **Authentication**: Using 802.1X (enterprise) with an **Authentication Server (AS)**, or using a **Pre‑Shared Key (PSK)**.
3. **Key Generation & Distribution (4‑Way Handshake)**:
   - Derives a **Pairwise Master Key (PMK)**.
   - From PMK, derives a **Pairwise Transient Key (PTK)** using nonces.
   - PTK is split into: encryption key, integrity key, EAPOL key.
4. **Data Transfer**: All frames encrypted with AES‑CCMP.

```
  ┌─────────────────────── 802.11i / WPA2 ───────────────────────┐
  │                                                                │
  │  Phase 1        Phase 2            Phase 3          Phase 4    │
  │  Discovery  →  Authentication  →  4‑Way Handshake → Encrypted  │
  │  (capabilities)  (802.1X/PSK)     (key derivation)   Data      │
  │                                                                │
  └────────────────────────────────────────────────────────────────┘
```

> 🧠 **Memory Tip**: "**D‑A‑K‑D**" — **D**iscover, **A**uthenticate, **K**eys, **D**ata.

**WPA3 — SAE (Simultaneous Authentication of Equals):**
- Replaces the PSK‑based handshake with a Diffie‑Hellman‑based **password‑authenticated key exchange**.
- Provides **forward secrecy** — even if the password is later compromised, past sessions cannot be decrypted.
- Resistant to **offline dictionary attacks** (unlike WPA2‑PSK, where captured handshakes can be brute‑forced offline).

### 8.3 4G/5G Cellular Security

- **Mutual authentication**: Both device and network authenticate each other (unlike 3G where only the device authenticated to the network).
- **Key derivation hierarchy**: Multiple keys derived from a master key for different purposes.
- **IMSI privacy in 5G**: IMSI (subscriber identity) is encrypted, preventing IMSI catchers.
- **User‑plane encryption**: Traffic is encrypted between device and base station.

---

## 9. Firewalls and Intrusion Detection Systems

### 9.1 Firewalls

A firewall is a **network security device** that monitors and filters incoming/outgoing traffic based on predefined rules.

**Goals of a firewall:**
- All traffic between inside and outside network passes through the firewall.
- Only authorized traffic (as defined by security policy) is allowed through.
- The firewall itself is immune to penetration.

**Three types of firewalls:**

#### 1. Stateless Packet Filters

- Operates at **network/transport layer**.
- Examines each packet **independently** against a set of rules (ACLs).
- Filters based on: source/dest IP, source/dest port, protocol, TCP flags.

**Example ACL rules:**

| Action | Src IP | Dest IP | Protocol | Src Port | Dest Port | Flag |
|---|---|---|---|---|---|---|
| Allow | Any | 222.22/16 | TCP | Any | 80 | Any |
| Allow | 222.22/16 | Any | TCP | 80 | Any | ACK |
| Deny | All | All | All | All | All | All |

> 📌 **Exam Tip**: The ACK‑bit trick — allowing only packets with **ACK=1** from outside prevents external hosts from initiating TCP connections (since the initial SYN has ACK=0), while allowing responses to internal connections.

**Limitations:**
- Cannot inspect **application‑layer data**.
- Vulnerable to **IP spoofing** (attacker forges trusted source IP).
- Cannot track TCP connection **state**.

#### 2. Stateful Packet Filters

- Tracks the **state of TCP connections** (e.g., whether a connection was properly established with SYN → SYN‑ACK → ACK).
- Allows return packets only for **established** connections.
- More secure than stateless but still doesn't inspect application data.

**Connection table example:**

| Src IP | Src Port | Dest IP | Dest Port | State |
|---|---|---|---|---|
| 10.0.0.5 | 49152 | 93.184.216.34 | 80 | Established |
| 10.0.0.8 | 50200 | 151.101.1.69 | 443 | SYN‑Sent |

#### 3. Application Gateways (Proxy Firewalls)

- Operates at the **application layer**.
- Acts as a **proxy**: internal clients connect to the gateway, which connects to the external server on their behalf.
- Can inspect **application‑layer data** (e.g., block specific HTTP requests, filter email content).
- **Disadvantage**: slower; must run a separate proxy for each application.

```
  ┌──────────────────────────────────────────────────┐
  │           Firewall Types — Mind Map               │
  │                                                    │
  │               ┌──── Stateless Packet Filter        │
  │               │     (IP/port/flags)                │
  │  Firewall ────┤                                    │
  │               ├──── Stateful Packet Filter         │
  │               │     (+ connection tracking)        │
  │               │                                    │
  │               └──── Application Gateway            │
  │                     (proxy, deep inspection)       │
  └──────────────────────────────────────────────────┘
```

> 🧠 **Memory Tip**: Think of firewall types as **security checkpoints**:
> - **Stateless** = guard who checks your ID (packet header) but doesn't remember you.
> - **Stateful** = guard who checks your ID *and* remembers if you already entered (connection state).
> - **Application Gateway** = guard who checks your ID, remembers you, AND opens your bag to inspect contents (application data).

### 9.2 Intrusion Detection Systems (IDS)

A firewall is a **preventive** tool (blocks traffic). An IDS is a **detective** tool (monitors and alerts).

**Types of IDS:**

| Type | Description | Analogy |
|---|---|---|
| **Signature‑based** | Compares traffic against a database of known attack patterns (signatures) | Like antivirus with a virus database |
| **Anomaly‑based** | Learns "normal" traffic patterns and flags deviations | Like a credit card company flagging unusual spending |

**IDS deployment:**

| Deployment | Location | What it Sees |
|---|---|---|
| **NIDS** (Network IDS) | At network boundary (often behind firewall) | All network traffic passing through |
| **HIDS** (Host IDS) | On individual hosts | Activity on that specific host |

**Snort** — a widely‑used open‑source NIDS:
- Uses **rule‑based** detection.
- Example Snort rule:
  ```
  alert tcp any any -> 192.168.1.0/24 80 (content:"../"; msg:"Directory traversal attempt"; sid:1001;)
  ```

> ✅ **Key Point**: Signature‑based IDS cannot detect **zero‑day attacks** (new, unknown attacks). Anomaly‑based IDS can, but suffers from **false positives** (flagging normal traffic as malicious).

### 9.3 Intrusion Prevention Systems (IPS)

An IPS is essentially an IDS that can also **take action** — it can **block** or **modify** malicious traffic in real time, not just alert.

| Feature | IDS | IPS |
|---|---|---|
| Detection | ✅ | ✅ |
| Alerting | ✅ | ✅ |
| Prevention/Blocking | ❌ | ✅ |
| Placement | Passive (tap/mirror port) | **Inline** (all traffic passes through) |

---

## 10. Attacks on Networks

### 10.1 Malware

| Type | Description | Propagation |
|---|---|---|
| **Virus** | Malicious code that attaches to a legitimate program; requires user action to execute | User runs infected file |
| **Worm** | Self‑replicating malware that spreads automatically without user action | Exploits network vulnerabilities |
| **Trojan horse** | Disguised as legitimate software; performs hidden malicious actions | User installs it willingly |
| **Ransomware** | Encrypts victim's files; demands payment for decryption key | Phishing, exploits |
| **Spyware** | Secretly monitors user activity (keystrokes, browsing) | Bundled with software |
| **Botnet** | Network of compromised machines (bots/zombies) controlled by attacker (botmaster) | Worms, trojans |

**Botnet lifecycle:**

```
  1. Infection        2. Command & Control     3. Attack
  ────────────       ─────────────────────    ────────────
  Malware spreads →  Bots connect to C&C  →  Botmaster issues
  to thousands of    server for instructions   DDoS, spam, etc.
  machines (zombies)
```

> 🧠 **Memory Tip**: "**V**iruses need **V**olunteers (user action); **W**orms **W**alk on their own."

### 10.2 Denial‑of‑Service (DoS / DDoS)

**Goal**: Make a service unavailable to legitimate users by overwhelming it with traffic.

**Three categories:**

1. **Vulnerability attack**: Exploit a specific software bug to crash the service.
2. **Bandwidth flooding**: Saturate the target's network link with traffic.
3. **Connection flooding**: Exhaust the target's resources by opening many half‑open or full connections.

**SYN Flood Attack (classic example):**

```
  Attacker sends thousands of TCP SYN packets with spoofed source IPs
      │
      ▼
  Server allocates resources for each half‑open connection (SYN_RCVD state)
      │
      ▼
  Server's connection table fills up → cannot accept legitimate connections
```

**Defenses:**
- **SYN cookies**: Server doesn't allocate resources at SYN; instead encodes connection info in the SYN‑ACK sequence number. Resources allocated only upon receiving a valid ACK.
- **Rate limiting**: Limit the rate of incoming SYN packets.
- **CDNs / DDoS mitigation services** (e.g., Cloudflare, Akamai): Absorb attack traffic across distributed infrastructure.

**DDoS (Distributed DoS):**
- Uses a **botnet** of thousands/millions of machines.
- Much harder to defend against than single‑source DoS.
- Spoofed source IPs make tracing difficult.

> 📌 **Exam Tip**: **Amplification attacks** (e.g., DNS amplification, NTP amplification) exploit services that return responses much larger than requests. Attacker sends small requests with a **spoofed victim source IP** → the amplifier sends large responses to the victim.

### 10.3 Packet Sniffing

- A **passive** attack — the attacker captures packets traversing a network.
- Easy on **broadcast media** (Wi‑Fi, shared Ethernet hubs).
- Tools: Wireshark, tcpdump.
- **Defense**: Encryption (TLS, IPsec) makes sniffed packets unreadable.

### 10.4 IP Spoofing

- Attacker forges the **source IP address** in packets to impersonate another host.
- Used in: DoS reflection attacks, bypassing IP‑based access controls.
- **Defense**: **Ingress filtering** — ISPs/routers should drop packets with source IPs that don't belong to the sending network (BCP 38 / RFC 2827).

### 10.5 Man‑in‑the‑Middle (MITM)

- Attacker positions themselves **between** two communicating parties.
- Intercepts, and potentially modifies, messages in both directions.
- Neither party knows the attacker is present.

```
  Alice ◄───► [  Trudy (MITM)  ] ◄───► Bob
          Alice thinks she's         Bob thinks he's
          talking to Bob             talking to Alice
```

**Defense**: Proper **authentication** (certificates, verified public keys).

### 10.6 DNS Attacks

**DNS Cache Poisoning:**
- Attacker injects **forged DNS responses** into a DNS resolver's cache.
- Victim is redirected to a malicious IP address when querying a legitimate domain.

**Defense**: **DNSSEC (DNS Security Extensions)** — uses digital signatures to authenticate DNS responses.

---

## 11. Summary

### Core Concepts Recap

| Topic | Key Takeaway |
|---|---|
| **Security Goals** | CIA + Authentication + Non‑repudiation |
| **Symmetric Crypto** | Fast; shared key; AES is the standard |
| **Asymmetric Crypto** | Key pairs; RSA, DH; slow but solves key distribution |
| **Hash Functions** | Fixed‑length digest; collision resistance; SHA‑256 |
| **MAC** | Hash + shared key = authentication + integrity |
| **Digital Signatures** | Sign with private, verify with public → non‑repudiation |
| **Certificates & CAs** | Bind public key to identity; chain of trust |
| **TLS/SSL** | Secures TCP; handshake + record protocol; TLS 1.3 = forward secrecy |
| **IPsec** | Network‑layer security; ESP preferred; tunnel mode for VPNs |
| **Wireless Security** | WEP broken → WPA2 (AES‑CCMP) → WPA3 (SAE, forward secrecy) |
| **Firewalls** | Stateless → Stateful → Application Gateway (increasing depth) |
| **IDS/IPS** | Signature‑based vs anomaly‑based; IPS blocks in‑line |
| **DoS/DDoS** | SYN flood, amplification; defense = SYN cookies, rate limiting |
| **Malware** | Viruses (user action), worms (self‑propagating), botnets (coordinated) |

### Security Protocol Stack — Where Each Operates

```
  ┌──────────────────────────────┐
  │  Application Layer           │  PGP, S/MIME, HTTPS
  ├──────────────────────────────┤
  │  Transport Layer (TLS/SSL)   │  TLS 1.2, TLS 1.3
  ├──────────────────────────────┤
  │  Network Layer (IPsec)       │  AH, ESP, IKE
  ├──────────────────────────────┤
  │  Link Layer                  │  WPA2, WPA3 (802.11i)
  └──────────────────────────────┘
```

> ✅ **Final Key Point**: Security is **not a single mechanism** — it's a **defense‑in‑depth** strategy. Different layers protect against different threats. TLS secures an individual connection; IPsec secures all IP traffic between two points; firewalls control what traffic enters/leaves a network; IDS/IPS monitors for attacks that get through.

---

## 12. Additional References

### 📜 RFCs (Request for Comments)

| RFC | Topic |
|---|---|
| [RFC 5246](https://www.rfc-editor.org/rfc/rfc5246) | TLS 1.2 |
| [RFC 8446](https://www.rfc-editor.org/rfc/rfc8446) | TLS 1.3 |
| [RFC 4301](https://www.rfc-editor.org/rfc/rfc4301) | IPsec Architecture |
| [RFC 4302](https://www.rfc-editor.org/rfc/rfc4302) | IP Authentication Header (AH) |
| [RFC 4303](https://www.rfc-editor.org/rfc/rfc4303) | Encapsulating Security Payload (ESP) |
| [RFC 7296](https://www.rfc-editor.org/rfc/rfc7296) | IKEv2 |
| [RFC 4880](https://www.rfc-editor.org/rfc/rfc4880) | OpenPGP Message Format |
| [RFC 2827](https://www.rfc-editor.org/rfc/rfc2827) | BCP 38 — Ingress Filtering (IP Spoofing Defense) |
| [RFC 4033](https://www.rfc-editor.org/rfc/rfc4033) | DNSSEC Introduction |

### 📚 Academic & Textbook Resources

- **Kurose & Ross** — *Computer Networking: A Top‑Down Approach*, 8th Edition, Chapter 8
- **Stallings, W.** — *Cryptography and Network Security: Principles and Practice*
- **Kaufman, Perlman, Speciner** — *Network Security: Private Communication in a Public World*

### 🌐 Online Resources

**General Network Security:**
- [Cloudflare Learning Center — Network Security](https://www.cloudflare.com/learning/security/)
- [OWASP (Open Web Application Security Project)](https://owasp.org/)

**Cryptography:**
- [Stanford — Cryptography I (Coursera, Dan Boneh)](https://www.coursera.org/learn/crypto)
- [Khan Academy — Cryptography](https://www.khanacademy.org/computing/computer-science/cryptography)

**TLS/SSL:**
- [Cloudflare — What is TLS?](https://www.cloudflare.com/learning/ssl/transport-layer-security-tls/)
- [The Illustrated TLS 1.3 Connection](https://tls13.xargs.org/)
- [Mozilla SSL Configuration Generator](https://ssl-config.mozilla.org/)

**IPsec & VPN:**
- [Cisco — IPsec Overview](https://www.cisco.com/c/en/us/td/docs/net_mgmt/vpn_solutions_center/2-0/ip_security/provisioning/guide/IPsecPG1.html)

**Firewalls & IDS:**
- [Snort — Open Source IDS](https://www.snort.org/)
- [NIST SP 800‑41 — Guidelines on Firewalls and Firewall Policy](https://csrc.nist.gov/publications/detail/sp/800-41/rev-1/final)

**Wireless Security:**
- [Wi‑Fi Alliance — WPA3 Specification](https://www.wi-fi.org/discover-wi-fi/security)

### 🎥 Video Lectures

- [MIT OCW 6.858 — Computer Systems Security (full course)](https://ocw.mit.edu/courses/6-858-computer-systems-security-fall-2014/)
- [Computerphile — YouTube playlist on Cryptography & Security](https://www.youtube.com/user/Computerphile)
- [Ben Eater — Networking Tutorial Series](https://www.youtube.com/c/BenEater)
- [Professor Messer — Network Security (CompTIA focused)](https://www.youtube.com/c/professormesser)

---

*Last updated: March 2026*
