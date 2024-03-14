#include "./department_controller.h"
#include <stdio.h>

void addDepartment()
{
    printf("Add Department\n");
}

void viewDepartment()
{
    printf("View Department\n");
}

void updateDepartment()
{
    printf("Update Department\n");
}

void deleteDepartment()
{
    printf("Delete Department\n");
}

void departmentController()
{
    int choice;
    while (1)
    {
        printf("1. Add Department\n");
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
