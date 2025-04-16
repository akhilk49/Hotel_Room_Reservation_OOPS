#include <iostream>
#include <vector>
using namespace std;

// Abstraction
class Room {
protected:
    int roomNumber;
    double price;
    bool isBooked;

public:
    Room(int num, double pr) : roomNumber(num), price(pr), isBooked(false) {}
    virtual ~Room() {}

    virtual string getRoomType() = 0; // Abstraction
    virtual void displayDetails() {
        cout << "Room Number: " << roomNumber << "\n";
        cout << "Price: $" << price << "\n";
        cout << "Status: " << (isBooked ? "Booked" : "Available") << "\n";
        cout << "Room Type: " << getRoomType() << "\n\n";
    }

    void bookRoom() { // Encapsulation
        if (!isBooked) {
            isBooked = true;
            cout << "Room " << roomNumber << " booked successfully.\n";
        } else {
            cout << "Room " << roomNumber << " is already booked.\n";
        }
    }

    int getRoomNumber() const { return roomNumber; }
    bool available() const { return !isBooked; }
};

// Inheritance
class StandardRoom : public Room {
public:
    StandardRoom(int num) : Room(num, 100.0) {}
    string getRoomType() override { return "Standard"; }
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int num) : Room(num, 200.0) {}
    string getRoomType() override { return "Suite"; }
};

class VIPRoom : public Room {
public:
    VIPRoom(int num) : Room(num, 300.0) {}
    string getRoomType() override { return "VIP"; }
};

int main() {
    vector<Room*> rooms;

    // Create rooms – Polymorphism in action
    rooms.push_back(new StandardRoom(101));
    rooms.push_back(new SuiteRoom(102));
    rooms.push_back(new VIPRoom(103));

    int choice;
    do {
        cout << "\n--- Hotel Room Reservation System ---\n";
        cout << "1. View Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (Room* room : rooms) {
                if (room->available()) {
                    room->displayDetails();
                }
            }
        } else if (choice == 2) {
            int roomNum;
            cout << "Enter Room Number to Book: ";
            cin >> roomNum;
            bool found = false;
            for (Room* room : rooms) {
                if (room->getRoomNumber() == roomNum) {
                    room->bookRoom();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Room not found.\n";
            }
        }
    } while (choice != 3);

    for (Room* room : rooms) delete room;
    return 0;
}
