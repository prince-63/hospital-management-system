#include "./room_controller.h"
#include <stdio.h>

void addRoom()
{
    printf("Add Room\n");
}

void viewRoom()
{
    printf("View Room\n");
}

void updateRoom()
{
    printf("Update Room\n");
}

void deleteRoom()
{
    printf("Delete Room\n");
}

void roomController()
{
    int choice;
    while (1)
    {
        printf("1. Add Room\n");
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
