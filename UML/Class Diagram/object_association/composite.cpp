/*********************************************************
 * Composition:
 * Definition: "Composition is a strong has-a relationship where 
 * the child cannot exist without the parent."
 * 
 *   +---------+  (owns) +---------+
 *   |  House  |(close diamond)<>------>|  Room   |
 *   +---------+         +---------+
 * 
 * Simple use: House owns Room(s); Room doesn't exist without House.
 *********************************************************/

#include <bits/stdc++.h>
using namespace std;

class Room {
public:
    string name;
    Room(string n) : name(n) {}
};

class House {
public:
    vector<Room> rooms; // strong ownership
    void addRoom(const Room& r) { rooms.push_back(r); }
    void showRooms() {
        cout << "House has rooms: ";
        for (auto &r : rooms) cout << r.name << " ";
        cout << endl;
    }
};
int main() {
    House house;
    Room room1("Living Room");
    Room room2("Bedroom");

    // Composition: House owns Rooms
    house.addRoom(room1);
    house.addRoom(room2);

    house.showRooms(); // Output: House has rooms: Living Room Bedroom 

    // Rooms cannot exist without the House
    // (if we try to create a Room without a House, it doesn't make sense in this context)

    return 0;
}