/*
841. Keys and Rooms

Problem:
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, 
denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, 
return true if you can visit all the rooms, or false otherwise.
*/

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int visited[roomsSize];
    for(int i = 0; i < roomsSize; i++) visited[i] = 0;

    int stack[roomsSize];
    int top = -1;

    stack[++top] = 0;
    visited[0] = 1;

    while(top != -1) {
        int room = stack[top--];

        for(int i = 0; i < roomsColSize[room]; i++) {
            int key = rooms[room][i];
            if(!visited[key]) {
                visited[key] = 1;
                stack[++top] = key;
            }
        }
    }

    for(int i = 0; i < roomsSize; i++) {
        if(!visited[i]) return false;
    }

    return true;
}