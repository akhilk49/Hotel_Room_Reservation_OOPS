# Hotel Room Reservation System Using OOP Concpets

A simple C++ program demonstrating OOP concepts through a hotel booking system.

## Features

- Book rooms
- View available rooms

## OOP Concepts Demonstrated

- **Abstraction**: Abstract base class `Room` with pure virtual function `getRoomType()`.
- **Inheritance**: `StandardRoom`, `SuiteRoom`, `VIPRoom` inherit from `Room`.
- **Polymorphism**: Vector of `Room*` used to store different room types.
- **Encapsulation**: Private/protected variables accessed via public methods.

## How to Run

```bash
g++ main.cpp -o hotel
./hotel
