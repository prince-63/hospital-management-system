#include "./doctor_controller.h"
#include "../../services/doctor/doctor_service.h"
#include <stdio.h>

void addDoctor()
{
    int status = add_doctor();
    if (status == 1)
    {
        printf("\nDoctor added successfully\n");
    }
    else
    {
        printf("\nFailed to add doctor\n");
    }
}

void viewDoctor()
{
    display_doctor();
}

void updateDoctor()
{
    update_doctor();
}

void deleteDoctor()
{
    int status = delete_doctor();
    if (status == 1)
    {
        printf("\nDoctor deleted successfully\n");
    }
    else
    {
        printf("\nFailed to delete doctor\n");
    }
}

void doctorController()
{
    int choice;
    while (1)
    {
        printf("\n1. Add Doctor\n");
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
