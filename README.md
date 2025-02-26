# 🍝 Philosophers

## 📚 Overview
A solution to the dining philosophers problem from 42 school curriculum, demonstrating concurrent programming concepts through process synchronization using mutexes and semaphores.

## 🎯 The Challenge
Five philosophers sit at a round table performing three actions:
- 🍴 Eating (requires two forks)
- 💭 Thinking
- 😴 Sleeping

### Core Rules
- Philosophers need two forks to eat
- They can't communicate with each other
- They don't know if another philosopher is about to die
- They must avoid deadlocks and starvation
- Each philosopher must eat, sleep, then think
- If a philosopher doesn't start eating within [time_to_die] milliseconds, they die
- All philosophers need to eat [number_of_times_each_philosopher_must_eat] times

## 🔧 Technical Details

### Mandatory Part (philo/)
Thread-based implementation using mutexes
```c
actions.c        // Eating, sleeping, thinking actions
cleanup.c        // Memory management and cleanup
even_odd.c       // Fork acquisition optimization
ft_atoi.c        // String to int conversion
header.h         // Main header and structures
init_data.c      // Data initialization
init_time.c      // Timestamp and timing functions
Makefile         // Compilation rules
philosofer.c     // Entry point
simulation.c     // Main simulation loop
threads.c        // Thread management
```

### Bonus Part (philo_bonus/)
Process-based implementation using semaphores
```c
actions.c        // Core philosopher actions
cleanup.c        // Resource cleanup
ft_atoi.c        // Number parsing
header_bonus.h   // Bonus structures/prototypes
init_data.c      // Initial setup
init_time.c      // Time management
Makefile         // Compilation
one_philo.c      // Single philosopher case
philo_bonus.c    // Main program
process.c        // Process handling
simulation.c     // Simulation control
taken_fork.c     // Semaphore operations
```

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make
- Unix-based OS (Linux/Mac)

### Compilation

Mandatory:
```bash
cd philo
make
```

Bonus:
```bash
cd philo_bonus
make
```

### Running

Mandatory:
```bash
./philo [philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [times_to_eat]
```

Bonus:
```bash
./philo_bonus [philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [times_to_eat]
```

## 📊 Parameters

| Parameter | Description | Example |
|-----------|-------------|---------|
| philosophers | Number of philosophers/forks | 5 |
| time_to_die | Milliseconds until death after last meal | 800 |
| time_to_eat | Milliseconds to eat | 200 |
| time_to_sleep | Milliseconds to sleep | 200 |
| times_to_eat | Optional: number of times each must eat | 7 |

## 🎮 Test Cases

### Basic Tests:
```bash
./philo 1 800 200 200       # One philosopher case
./philo 5 800 200 200       # Basic five philosophers
./philo 4 410 200 200       # Timing-sensitive case
./philo 100 800 200 200     # Performance test
```

### Edge Cases:
```bash
./philo 200 800 200 200     # Maximum philosophers
./philo 5 800 200 200 7     # Must eat specific times
./philo 4 310 200 100       # Death timing test
```

## 🎯 Features

- Real-time death detection
- Resource management
- Race condition prevention
- Deadlock avoidance
- Performance optimization
- Memory leak prevention
- Error handling

## 🔍 Monitoring

The program outputs status messages:
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

## ⚠️ Common Issues

- Race conditions
- Deadlocks
- Memory leaks
- Timing accuracy
- Resource contention
- Process synchronization

## 🛠️ Testing Tools

- Valgrind for memory leaks
- Helgrind for race conditions
- Custom test scripts
- System resource monitors
