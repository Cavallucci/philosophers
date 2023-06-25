# Philosophers

Welcome to the Philosophers project! This project aims to simulate the classic "Dining Philosophers Problem" using threads and synchronization mechanisms. The goal is to implement a solution that avoids deadlock and starvation while allowing the philosophers to eat peacefully.

## Problem Description

The Dining Philosophers Problem is a classic synchronization problem in computer science. It involves a group of philosophers sitting at a table, each with a plate of food in front of them, and a chopstick between each pair of adjacent philosophers. The philosophers alternate between thinking and eating. However, to eat, a philosopher needs both the chopstick to their left and the chopstick to their right.

The challenge is to design a solution that prevents deadlock (where philosophers are unable to make progress) and starvation (where a philosopher is continually denied access to the resources).

## Features

- **Simulation**: Simulate the behavior of the philosophers using threads.
- **Synchronization**: Use synchronization mechanisms such as mutex locks and semaphores to prevent deadlock and ensure fairness.
- **Resource Allocation**: Implement a strategy for allocating the chopsticks to the philosophers in a way that avoids deadlock and starvation.
- **Visualization**: Optionally visualize the state of the dining philosophers and their actions during the simulation.

## Requirements

- Operating System: Linux, macOS, or Windows (with WSL)
- Compiler: GCC or compatible C compiler

## Installation

1. Clone this GitHub repository to your local machine:

  git clone https://github.com/Cavallucci/philosophers.git

2. Navigate to the project directory:

  cd philo

3. Build the project using the provided Makefile:

  make

4. Run the simulation:

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

## Usage

Once you have executed the `philosophers` executable, the simulation will start. You can customize the number of philosophers, the time for thinking, and the time for eating by modifying the command line arguments or the constants defined in the source code.

During the simulation, you will see the state of each philosopher (thinking, hungry, or eating) and their actions (picking up chopsticks, putting down chopsticks) displayed in the console. The program will terminate automatically after a certain duration or when you interrupt it manually.


I would like to express my gratitude to the open-source community for their valuable libraries, resources, and inspiration.
