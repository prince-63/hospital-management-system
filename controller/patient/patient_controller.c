#include "./patient_controller.h"
#include <stdio.h>

void addPatient()
{
    printf("Add Patient\n");
}

void viewPatient()
{
    printf("View Patient\n");
}

void updatePatient()
{
    printf("Update Patient\n");
}

void deletePatient()
{
    printf("Delete Patient\n");
}

void patientController()
{
    int choice;
    while (1)
    {
        printf("1. Add Patient\n");
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
