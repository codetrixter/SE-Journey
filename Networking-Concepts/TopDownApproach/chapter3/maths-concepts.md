# Mathematical Concepts in Networking 🧮

## Table of Contents
- [Exponential Weighted Moving Average (EWMA)](#exponential-weighted-moving-average-ewma)
  - [Simple Explanation](#simple-explanation)
  - [The Formula](#the-formula)
  - [Why "Exponential"?](#why-exponential)
  - [Practical Example: TCP RTT Estimation](#practical-example-tcp-rtt-estimation)
  - [Choosing the Right Alpha (α)](#choosing-the-right-alpha-α)
  - [Advantages and Disadvantages](#advantages-and-disadvantages)

---

## Exponential Weighted Moving Average (EWMA)

### Simple Explanation

Imagine you're trying to estimate how long your daily commute takes. Some days it's 25 minutes, other days 35 minutes due to traffic. How do you get a "smooth" estimate that adapts to changes but doesn't jump around wildly?

**EWMA is like having a "fading memory":**
- You care **most** about recent measurements
- You care **less** about older measurements (they "fade away" exponentially)
- But you never completely forget the past - it always influences your estimate a little bit

Think of it as **90% trusting your current estimate and 10% updating it with the new measurement** (when α = 0.1).

---

### The Formula

```
EstimatedValue = (1 - α) × OldEstimate + α × NewMeasurement
```

**Breaking it down:**

| Component | What it means | Weight |
|-----------|---------------|--------|
| `(1 - α) × OldEstimate` | Trust your previous estimate | 90% (if α=0.1) |
| `α × NewMeasurement` | Trust the new data point | 10% (if α=0.1) |

**α (alpha)** is the "smoothing factor" between 0 and 1:
- **α close to 0** (e.g., 0.1): Very smooth, slow to adapt, heavily weights history
- **α close to 1** (e.g., 0.9): Very reactive, quick to adapt, mostly ignores history

---

### Why "Exponential"?

Let's see what happens to old measurements over time. Say we're at time `n` and we had measurements at times 0, 1, 2, ..., n.

**Expanding the formula backward:**

```
Step 1: Current estimate at time n
Estimated_n = (1-α) × Estimated_(n-1) + α × Sample_n

Step 2: Substitute Estimated_(n-1)
Estimated_n = (1-α) × [(1-α) × Estimated_(n-2) + α × Sample_(n-1)] + α × Sample_n
            = (1-α)² × Estimated_(n-2) + (1-α) × α × Sample_(n-1) + α × Sample_n

Step 3: Keep expanding...
Estimated_n = α × Sample_n 
            + (1-α) × α × Sample_(n-1)
            + (1-α)² × α × Sample_(n-2)
            + (1-α)³ × α × Sample_(n-3)
            + ...
```

**The weight of each measurement:**

| Time ago | Weight |
|----------|--------|
| Current (t=n) | α |
| 1 step back (t=n-1) | (1-α) × α |
| 2 steps back (t=n-2) | (1-α)² × α |
| 3 steps back (t=n-3) | (1-α)³ × α |
| k steps back (t=n-k) | (1-α)^k × α |

**This is exponential decay!** Each older measurement gets weighted by `(1-α)` raised to an increasing power.

---

### Practical Example: TCP RTT Estimation

**Scenario:** Measuring Round-Trip Time (RTT) for TCP packets

```
α = 0.125 (typical value for TCP)
Initial EstimatedRTT = 100 ms

Measurement 1: SampleRTT = 120 ms
EstimatedRTT = 0.875 × 100 + 0.125 × 120
             = 87.5 + 15
             = 102.5 ms

Measurement 2: SampleRTT = 90 ms
EstimatedRTT = 0.875 × 102.5 + 0.125 × 90
             = 89.69 + 11.25
             = 100.94 ms

Measurement 3: SampleRTT = 130 ms
EstimatedRTT = 0.875 × 100.94 + 0.125 × 130
             = 88.32 + 16.25
             = 104.57 ms
```

**Notice:**
- The estimate changes gradually, not drastically
- A single outlier (130 ms) doesn't cause a huge jump
- The estimate smoothly adapts to the trend

---

### Visual Comparison: Different Alpha Values

```
Sample RTT values: [100, 150, 110, 140, 120, 160, 115]

α = 0.125 (Smooth, TCP standard):
Estimated: [100, 106, 107, 111, 112, 118, 118]
           └─ Gradual changes, smooth curve

α = 0.5 (Moderate):
Estimated: [100, 125, 118, 129, 124, 142, 129]
           └─ Faster response, moderate smoothing

α = 0.9 (Reactive):
Estimated: [100, 145, 114, 138, 122, 156, 119]
           └─ Quick adaptation, follows samples closely
```

**Graph visualization:**
```
RTT (ms)
│
160 │     ×           ×
    │                   
150 │   ×
    │                     ○ Sample RTT (×)
140 │       ×       ×     ― α=0.125 (smooth)
    │                     ··· α=0.5 (moderate)
130 │
    │
120 │ ×       ×   ×     ×
    │  ╲   ╱   ╲ ╱   ╲ ╱
110 │    ×        
    │   ················
100 │ ●─────────────────────
    └─────────────────────── Time
```

---

### Choosing the Right Alpha (α)

| Value of α | Behavior | Use Case |
|------------|----------|----------|
| **0.01 - 0.2** | Very smooth, slow adaptation | Stable environments, want to filter noise |
| **0.125** (TCP) | Balanced | General network RTT estimation |
| **0.3 - 0.5** | Moderate responsiveness | Medium variability |
| **0.7 - 0.9** | Very responsive | Quickly changing environments |

**Formula to relate α to "memory span":**
```
Effective window ≈ 2/α samples

Examples:
α = 0.125 → Effectively considers last ~16 samples
α = 0.25  → Effectively considers last ~8 samples
α = 0.5   → Effectively considers last ~4 samples
```

---

### Mathematical Properties

#### 1. **Weights Sum to 1** (approximately)

```
Total weight = α + (1-α)α + (1-α)²α + (1-α)³α + ...
             = α × [1 + (1-α) + (1-α)² + (1-α)³ + ...]
             = α × [1 / (1 - (1-α))]    [geometric series]
             = α × [1 / α]
             = 1 ✓
```

#### 2. **Recursive Computation** (Memory Efficient)

You only need to store:
- Current estimate (1 value)
- New measurement (1 value)

You **don't** need to store all historical data!

#### 3. **Lag Behind Step Changes**

If the true value suddenly jumps by Δ, the EWMA lags behind:

```
After n steps, the gap closes by factor (1-α)^n

Example: α = 0.125, true value jumps by 100
After 1 RTT: gap = 100 × 0.875 = 87.5
After 5 RTTs: gap = 100 × 0.875⁵ = 51.3
After 10 RTTs: gap = 100 × 0.875¹⁰ = 26.3
After 20 RTTs: gap = 100 × 0.875²⁰ = 6.9
```

---

### Advantages and Disadvantages

#### ✅ Advantages

1. **Memory Efficient**: Only stores current estimate
2. **Computationally Simple**: Just one multiplication and addition
3. **Smooth Estimates**: Filters out random noise/spikes
4. **Adaptive**: Gradually responds to genuine changes
5. **Well-Studied**: Proven in decades of TCP use

#### ⚠️ Disadvantages

1. **Lags Behind**: Slow to react to sudden real changes
2. **Parameter Tuning**: Choosing α requires domain knowledge
3. **Exponential Bias**: Recent samples have disproportionate influence
4. **Initial Value Sensitivity**: Takes time to "forget" bad initial estimate

---

### Real-World Applications

| Domain | Application | Typical α |
|--------|-------------|-----------|
| **Networking** | TCP RTT estimation | 0.125 |
| **Finance** | Stock price smoothing | 0.1 - 0.3 |
| **System Monitoring** | CPU/Memory usage trending | 0.2 - 0.5 |
| **Machine Learning** | Gradient descent optimization (momentum) | 0.9 - 0.999 |
| **Control Systems** | Sensor noise filtering | 0.1 - 0.4 |

---

### TCP-Specific: RTT Deviation (DevRTT)

TCP also estimates the **variability** of RTT using EWMA:

```
DevRTT = (1 - β) × DevRTT + β × |SampleRTT - EstimatedRTT|
```

Where β = 0.25 (typical value)

**Purpose:** Measure how much RTT fluctuates

**Used in timeout calculation:**
```
TimeoutInterval = EstimatedRTT + 4 × DevRTT
```

**Why 4×?** Statistical reasoning:
- If RTT is normally distributed, 4 standard deviations covers 99.99% of cases
- Prevents premature timeouts due to variance

**Example:**
```
EstimatedRTT = 100 ms
DevRTT = 20 ms (high variability)
TimeoutInterval = 100 + 4×20 = 180 ms

vs.

EstimatedRTT = 100 ms
DevRTT = 5 ms (low variability)
TimeoutInterval = 100 + 4×5 = 120 ms
```

---

### Code Implementation

#### Simple EWMA in Python
```python
class EWMA:
    def __init__(self, alpha=0.125):
        self.alpha = alpha
        self.estimate = None
    
    def update(self, sample):
        if self.estimate is None:
            self.estimate = sample  # Initialize with first sample
        else:
            self.estimate = (1 - self.alpha) * self.estimate + self.alpha * sample
        return self.estimate

# Usage
ewma = EWMA(alpha=0.125)
samples = [100, 120, 90, 130, 110]

for sample in samples:
    estimate = ewma.update(sample)
    print(f"Sample: {sample}, Estimate: {estimate:.2f}")

# Output:
# Sample: 100, Estimate: 100.00
# Sample: 120, Estimate: 102.50
# Sample: 90, Estimate: 100.94
# Sample: 130, Estimate: 104.57
# Sample: 115, Estimate: 105.87
```

#### TCP RTT Estimator in C++
```cpp
class TCPRTTEstimator {
private:
    double estimatedRTT;
    double devRTT;
    const double alpha = 0.125;
    const double beta = 0.25;
    bool initialized = false;

public:
    void updateRTT(double sampleRTT) {
        if (!initialized) {
            estimatedRTT = sampleRTT;
            devRTT = sampleRTT / 2;
            initialized = true;
        } else {
            devRTT = (1 - beta) * devRTT + beta * abs(sampleRTT - estimatedRTT);
            estimatedRTT = (1 - alpha) * estimatedRTT + alpha * sampleRTT;
        }
    }
    
    double getTimeout() {
        return estimatedRTT + 4 * devRTT;
    }
    
    double getEstimatedRTT() { return estimatedRTT; }
    double getDevRTT() { return devRTT; }
};
```

---

### Summary

**EWMA in One Sentence:**
> A weighted average that gives exponentially decreasing importance to older measurements, creating a smooth estimate that adapts to recent trends while filtering noise.

**Key Takeaways:**
1. 📊 **Smooths data** while remaining responsive to trends
2. 🧠 **Memory efficient** - only needs current estimate
3. ⚖️ **Balance** between stability (low α) and responsiveness (high α)
4. 🌐 **Used in TCP** for RTT estimation with α = 0.125
5. 📉 **Exponential weights** - recent data matters most

**When to use EWMA:**
- ✅ You want smooth estimates from noisy data
- ✅ Recent data is more important than old data
- ✅ You need memory-efficient computation
- ✅ The underlying value changes gradually, not abruptly

**When NOT to use EWMA:**
- ❌ You need all historical data with equal weight (use simple moving average)
- ❌ Sudden changes must be detected immediately (use change detection algorithms)
- ❌ You need precise statistical properties (use Kalman filters)

---

**Related Concepts:**
- Simple Moving Average (SMA): Equal weights to last N samples
- Weighted Moving Average (WMA): Linearly decreasing weights
- Kalman Filter: Optimal estimation with noise models
- Low-pass Filter: Signal processing equivalent

