#include "./appointment_controller.h"
#include <stdio.h>

void addAppointment()
{
    printf("Add Appointment\n");
}

void viewAppointment()
{
    printf("View Appointment\n");
}

void updateAppointment()
{
    printf("Update Appointment\n");
}

void deleteAppointment()
{
    printf("Delete Appointment\n");
}

void appointmentController()
{
    int choice;
    while (1)
    {
        printf("1. Add Appointment\n");
        printf("2. View Appointment\n");
        printf("3. Update Appointment\n");
        printf("4. Delete Appointment\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAppointment();
            break;
        case 2:
            viewAppointment();
            break;
        case 3:
            updateAppointment();
            break;
        case 4:
            deleteAppointment();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        };
    }
}