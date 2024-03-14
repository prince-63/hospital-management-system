#include "./staff_controller.h"
#include <stdio.h>


void addStaff()
{
    printf("Add Staff\n");
}

void viewStaff()
{
    printf("View Staff\n");
}

void updateStaff()
{
    printf("Update Staff\n");
}

void deleteStaff()
{
    printf("Delete Staff\n");
}

void staffController()
{
    int choice;
    while (1)
    {
        printf("1. Add Staff\n");
        printf("2. View Staff\n");
        printf("3. Update Staff\n");
        printf("4. Delete Staff\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStaff();
            break;
        case 2:
            viewStaff();
            break;
        case 3:
            updateStaff();
            break;
        case 4:
            deleteStaff();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        };
    }
}
