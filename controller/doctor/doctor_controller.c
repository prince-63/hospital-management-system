#include "./doctor_controller.h"
#include <stdio.h>


void addDoctor()
{
    printf("Add Doctor\n");
}

void viewDoctor()
{
    printf("View Doctor\n");
}

void updateDoctor()
{
    printf("Update Doctor\n");
}

void deleteDoctor()
{
    printf("Delete Doctor\n");
}

void doctorController()
{
    int choice;
    while (1)
    {
        printf("1. Add Doctor\n");
        printf("2. View Doctor\n");
        printf("3. Update Doctor\n");
        printf("4. Delete Doctor\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addDoctor();
            break;
        case 2:
            viewDoctor();
            break;
        case 3:
            updateDoctor();
            break;
        case 4:
            deleteDoctor();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        };
    }
}
