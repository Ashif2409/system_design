/*********************************************************
 * Aggregation:
 * Definition: "Aggregation is a weak has-a relationship where 
 * the child can exist independently of the parent."
 * 
 *   +---------+ open diamond---->+---------+
 *   |  Team   |        has  | Player  |
 *   +---------+             +---------+
 * 
 * Simple use: Team has Players; Players can exist without Team.
 *********************************************************/

#include <bits/stdc++.h>
using namespace std;

class Player {
public:
    string name;
    Player(string n) : name(n) {}
};

class Team {
public:
    string name;
    vector<Player*> players; // weak reference
    Team(string n) : name(n) {}
    void addPlayer(Player* p) { players.push_back(p); }
    void showPlayers() {
        cout << name << " team has: ";
        for (auto p : players) cout << p->name << " ";
        cout << endl;
    }
};
int main() {
    Team team("Dream Team");
    Player player1("Alice");
    Player player2("Bob");

    // Aggregation: Team has Players
    team.addPlayer(&player1);
    team.addPlayer(&player2);
    
    team.showPlayers(); // Output: Dream Team team has: Alice Bob 

    // Players can exist independently of the Team
    cout << player1.name << " and " << player2.name << " can play without the team." << endl;

    return 0;
}