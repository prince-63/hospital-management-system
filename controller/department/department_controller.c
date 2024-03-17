#include "./department_controller.h"
#include "../../services/department/department_service.h"
#include <stdio.h>

void addDepartment()
{
    int status = add_department();
    if (status == 1)
    {
        printf("\nDepartment added successfully\n");
    }
    else
    {
        printf("\nFailed to add department\n");
    }
}

void viewDepartment()
{
    display_department();
}

void updateDepartment()
{
    update_department();
}

void deleteDepartment()
{
    int status = delete_department();
    if (status == 1)
    {
        printf("\nDepartment deleted successfully\n");
    }
    else
    {
        printf("\nFailed to delete department\n");
    }
}

void departmentController()
{
    int choice;
    while (1)
    {
        printf("\n1. Add Department\n");
        printf("2. View Department\n");
        printf("3. Update Department\n");
        printf("4. Delete Department\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addDepartment();
            break;
        case 2:
            viewDepartment();
            break;
        case 3:
            updateDepartment();
            break;
        case 4:
            deleteDepartment();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        };
    }
}
