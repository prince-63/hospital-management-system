#include "./staff_controller.h"
#include "../../services/staff/staff_service.h"
#include <stdio.h>

void addStaff()
{
    int status = add_staff();
    if (status == 1)
    {
        printf("\nStaff added successfully\n");
    }
    else
    {
        printf("\nFailed to add staff\n");
    }
}

void viewStaff()
{
    display_staff();
}

void updateStaff()
{
    update_staff();
}

void deleteStaff()
{
    int status = delete_staff();
    if (status == 1)
    {
        printf("\nStaff deleted successfully\n");
    }
    else
    {
        printf("\nFailed to delete staff\n");
    }
}

void staffController()
{
    int choice;
    while (1)
    {
        printf("\n1. Add Staff\n");
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
