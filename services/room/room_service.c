#include "../../model/room/room_model.h"
#include <stdio.h>

FILE *room_file, *temp_file;

int add_room()
{
    Room room;
    room_file = fopen("./data/room.txt", "a");
    
    if (room_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter room id: ");
    scanf("%d", &room.roomId);
    printf("Enter room type: ");
    scanf("%s", room.roomType);
    printf("Enter room status: ");
    scanf("%s", room.roomStatus);

    fwrite(&room, sizeof(Room), 1, room_file);
    fclose(room_file);
    return 1;
}

void display_room()
{
    Room room;
    room_file = fopen("./data/room.txt", "r");
    if (room_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    while (fread(&room, sizeof(Room), 1, room_file))
    {
        printf("\nRoom Id: %d\n", room.roomId);
        printf("Room Type: %s\n", room.roomType);
        printf("Room Status: %s\n", room.roomStatus);
    }
    fclose(room_file);
}

int update_room()
{
    Room room;
    int roomId;
    room_file = fopen("./data/room.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (room_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter room id to update: ");
    scanf("%d", &roomId);

    while (fread(&room, sizeof(Room), 1, room_file))
    {
        if (room.roomId == roomId)
        {
            printf("Enter room type: ");
            scanf("%s", room.roomType);
            printf("Enter room status: ");
            scanf("%s", room.roomStatus);
        }
        fwrite(&room, sizeof(Room), 1, temp_file);
    }
    fclose(room_file);
    fclose(temp_file);
    remove("./data/room.txt");
    rename("./data/temp.txt", "./data/room.txt");
    return 1;
}

int delete_room()
{
    Room room;
    int roomId;
    room_file = fopen("./data/room.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (room_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter room id to delete: ");
    scanf("%d", &roomId);

    while (fread(&room, sizeof(Room), 1, room_file))
    {
        if (room.roomId != roomId)
        {
            fwrite(&room, sizeof(Room), 1, temp_file);
        }
    }
    fclose(room_file);
    fclose(temp_file);
    remove("./data/room.txt");
    rename("./data/temp.txt", "./data/room.txt");
    return 1;
}