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

    // Print table header
    printf("\n%-10s %-20s %-20s\n", "Room Id", "Room Type", "Room Status");

    while (fread(&room, sizeof(Room), 1, room_file))
    {
        // Print table row
        printf("%-10d %-20s %-20s\n", room.roomId, room.roomType, room.roomStatus);
    }
    fclose(room_file);
}

void update_room_type()
{
    Room room;
    int roomId;
    room_file = fopen("./data/room.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (room_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter room id to update: ");
    scanf("%d", &roomId);

    while (fread(&room, sizeof(Room), 1, room_file))
    {
        if (room.roomId == roomId)
        {
            printf("Enter new room type: ");
            scanf("%s", room.roomType);
        }
        fwrite(&room, sizeof(Room), 1, temp_file);
    }
    fclose(room_file);
    fclose(temp_file);
    remove("./data/room.txt");
    rename("./data/temp.txt", "./data/room.txt");
}

void update_room_status()
{
    Room room;
    int roomId;
    room_file = fopen("./data/room.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (room_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter room id to update: ");
    scanf("%d", &roomId);

    while (fread(&room, sizeof(Room), 1, room_file))
    {
        if (room.roomId == roomId)
        {
            printf("Enter new room status: ");
            scanf("%s", room.roomStatus);
        }
        fwrite(&room, sizeof(Room), 1, temp_file);
    }
    fclose(room_file);
    fclose(temp_file);
    remove("./data/room.txt");
    rename("./data/temp.txt", "./data/room.txt");
}

void update_room()
{
    int choice;
    while (1)
    {
        printf("\n1. Update room type");
        printf("\n2. Update room status");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            update_room_type();
            break;
        case 2:
            update_room_status();
            break;
        case 3:
            return;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
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