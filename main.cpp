#include <iostream>
#include <map>

using namespace std;

class Room{
public:
    int id;
    string name;
    string desc;
    Room* n_to;
    Room* s_to;

    void set_values (int, string, string, Room*, Room*);

    void print_current();
};

void Room::print_current(){
    cout << name << desc;
};

void Room::set_values (int id, string name, string desc,  Room* n_to, Room* s_to){
    id = id;
    name = name;
    desc = desc;
    n_to = n_to;
    s_to = s_to;
};

class Player{
public:
    Room* currentRoom;

    void set_values (Room* currentRoom);

    void move_rooms(string direction);
};

void Player::set_values(Room* currentRoom) {
    currentRoom = currentRoom;
};

void Player::move_rooms(string direction){
    if (direction == "n"){
        currentRoom = currentRoom -> n_to;
    };
    if(direction == "s"){
        currentRoom = currentRoom -> s_to;
    };
};



int main(void)
{
    Room room1;
    Room room2;
    room1.set_values(0, "outside", "You are outside", &room2, NULL);
    room2.set_values(1, "inside", "You are inside", NULL, &room1);

    Player player1;
    player1.set_values(&room1);

    bool playing = true;
    string commands [] = {"n", "s", "e", "w"};

    while(playing == true){
        string command;
        cout << player1.currentRoom->name;
        cout << "Please enter a command... \n";
        cin >> command;
        cout << command;

        if (command == "n" || command == "s"){
            player1.move_rooms(command);
        }
    }
}
