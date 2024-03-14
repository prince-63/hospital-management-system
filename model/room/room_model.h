#ifndef ROOM_MODEL_H
#define ROOM_MODEL_H

typedef struct Room
{
    int roomId;
    char roomName[50];
    char roomType[50];
    char roomStatus[10];
} Room;

#endif