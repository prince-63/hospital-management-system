#include "./room_controller.h"
#include "../../services/room/room_service.h"
#include <stdio.h>

void addRoom()
{
    int status = add_room();
    if (status == 1)
    {
        printf("\nRoom added successfully\n");
    }
    else
    {
        printf("\nFailed to add room\n");
    }
}

void viewRoom()
{
    display_room();
}

void updateRoom()
{
    update_room();
}

void deleteRoom()
{
    int status = delete_room();
    if (status == 1)
    {
        printf("\nRoom deleted successfully\n");
    }
    else
    {
        printf("\nFailed to delete room\n");
    }
}

void roomController()
{
    int choice;
    while (1)
    {
        printf("\n1. Add Room\n");
        printf("2. View Room\n");
        printf("3. Update Room\n");
        printf("4. Delete Room\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addRoom();
            break;
        case 2:
            viewRoom();
            break;
        case 3:
            updateRoom();
            break;
        case 4:
            deleteRoom();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        };
    }
}
