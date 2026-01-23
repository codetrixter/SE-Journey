# THREADS

# THREAD's WEIGHT

# MOTIVATION OF MULTITHREADING

# BENEFITS OF MULTITHREADING

| Type of process | Can it use multiple cores simultaneously? | Explanation | Max cores it can use at once (typical modern system) |
| --- | --- | --- | --- |
| Single-threaded process (1 thread) | No | A single thread of execution can only run on one core at any given moment. The OS can move it between cores over time (migration), but never split it across cores simultaneously. | 1 core |
| Multi-threaded process (≥2 threads) | Yes | Each thread is an independent unit of execution. The OS scheduler can assign different threads of the same process to different cores at the same instant → true parallelism. | Up to the number of threads (or available cores / hyper-threads) |
| Single-threaded process + multiple processes running | Indirectly helps the system | Multiple single-threaded processes can be spread across cores, but each individual process still uses only one core at a time. | Still only 1 per process |

# MULTICORE PROGRAMMING

# CHALLENGES OF MULTICORE PROGRAMMING

