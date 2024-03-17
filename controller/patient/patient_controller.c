#include "./patient_controller.h"
#include "../../services/patient/patient_service.h"
#include <stdio.h>

void addPatient()
{
    int status = add_patient();
    if (status == 1)
    {
        printf("\nPatient added successfully\n");
    }
    else
    {
        printf("\nFailed to add patient\n");
    }
}

void viewPatient()
{
    display_patient();
}

void updatePatient()
{
    update_patient();
}

void deletePatient()
{
    int status = delete_patient();
    if (status == 1)
    {
        printf("\nPatient deleted successfully\n");
    }
    else
    {
        printf("\nFailed to delete patient\n");
    }
}

void patientController()
{
    int choice;
    while (1)
    {
        printf("\n1. Add Patient\n");
        printf("2. View Patient\n");
        printf("3. Update Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            viewPatient();
            break;
        case 3:
            updatePatient();
            break;
        case 4:
            deletePatient();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        };
    }
}
