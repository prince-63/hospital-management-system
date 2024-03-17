#include "./appointment_controller.h"
#include "../../services/appointment/appointment_service.h"
#include <stdio.h>

void addAppointment()
{
    int status = add_appointment();
    if (status == 1)
    {
        printf("\nAppointment added successfully\n");
    }
    else
    {
        printf("\nFailed to add appointment\n");
    }
}

void viewAppointment()
{
    display_appointment();
}

void updateAppointment()
{
    int status = update_appointment();
    if (status == 1)
    {
        printf("\nAppointment updated successfully\n");
    }
    else
    {
        printf("\nFailed to update appointment\n");
    }
}

void deleteAppointment()
{
    int status = delete_appointment();
    if (status == 1)
    {
        printf("\nAppointment deleted successfully\n");
    }
    else
    {
        printf("\nFailed to delete appointment\n");
    }
}

void appointmentController()
{
    int choice;
    while (1)
    {
        printf("\n1. Add Appointment\n");
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
            printf("\nInvalid choice\n");
        };
    }
}