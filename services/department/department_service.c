#include "../../model/department/department_mode.h"
#include <stdio.h>

FILE *department_file, *temp_file;

int add_department()
{
    Department department;
    department_file = fopen("./data/department.txt", "a");

    if (department_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter department id: ");
    scanf("%d", &department.departmentId);
    printf("Enter department name: ");
    scanf("%s", department.departmentName);
    printf("Enter department head: ");
    scanf("%s", department.departmentHead);
    printf("Enter department contact: ");
    scanf("%s", department.departmentContact);
    printf("Enter department email: ");
    scanf("%s", department.departmentEmail);
    printf("Enter department status: ");
    scanf("%s", department.departmentStatus);

    fwrite(&department, sizeof(Department), 1, department_file);
    fclose(department_file);
    return 1;
}

void display_department()
{
    Department department;
    department_file = fopen("./data/department.txt", "r");
    if (department_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    // Print table header
    printf("\n%-10s %-20s %-20s %-20s %-20s %-20s\n", "Department Id", "Department Name", "Department Head", "Department Contact", "Department Email", "Department Status");

    while (fread(&department, sizeof(Department), 1, department_file))
    {
        // Print table row
        printf("%-10d %-20s %-20s %-20s %-20s %-20s\n", department.departmentId, department.departmentName, department.departmentHead, department.departmentContact, department.departmentEmail, department.departmentStatus);
    }
    fclose(department_file);
}

void update_department_name() {
    Department department;
    int departmentId;
    department_file = fopen("./data/department.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (department_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter department id: ");
    scanf("%d", &departmentId);

    while (fread(&department, sizeof(Department), 1, department_file))
    {
        if (department.departmentId == departmentId)
        {
            printf("\nEnter department name: ");
            scanf("%s", department.departmentName);
        }
        fwrite(&department, sizeof(Department), 1, temp_file);
    }
    fclose(department_file);
    fclose(temp_file);
    remove("./data/department.txt");
    rename("./data/temp.txt", "./data/department.txt");
}

void update_department_head() {
    Department department;
    int departmentId;
    department_file = fopen("./data/department.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (department_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter department id: ");
    scanf("%d", &departmentId);

    while (fread(&department, sizeof(Department), 1, department_file))
    {
        if (department.departmentId == departmentId)
        {
            printf("\nEnter department head: ");
            scanf("%s", department.departmentHead);
        }
        fwrite(&department, sizeof(Department), 1, temp_file);
    }
    fclose(department_file);
    fclose(temp_file);
    remove("./data/department.txt");
    rename("./data/temp.txt", "./data/department.txt");
}

void update_department_contact() {
    Department department;
    int departmentId;
    department_file = fopen("./data/department.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (department_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter department id: ");
    scanf("%d", &departmentId);

    while (fread(&department, sizeof(Department), 1, department_file))
    {
        if (department.departmentId == departmentId)
        {
            printf("\nEnter department contact: ");
            scanf("%s", department.departmentContact);
        }
        fwrite(&department, sizeof(Department), 1, temp_file);
    }
    fclose(department_file);
    fclose(temp_file);
    remove("./data/department.txt");
    rename("./data/temp.txt", "./data/department.txt");
}

void update_department_email() {
    Department department;
    int departmentId;
    department_file = fopen("./data/department.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (department_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter department id: ");
    scanf("%d", &departmentId);

    while (fread(&department, sizeof(Department), 1, department_file))
    {
        if (department.departmentId == departmentId)
        {
            printf("\nEnter department email: ");
            scanf("%s", department.departmentEmail);
        }
        fwrite(&department, sizeof(Department), 1, temp_file);
    }
    fclose(department_file);
    fclose(temp_file);
    remove("./data/department.txt");
    rename("./data/temp.txt", "./data/department.txt");
}

void update_department_status() {
    Department department;
    int departmentId;
    department_file = fopen("./data/department.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (department_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter department id: ");
    scanf("%d", &departmentId);

    while (fread(&department, sizeof(Department), 1, department_file))
    {
        if (department.departmentId == departmentId)
        {
            printf("\nEnter department status: ");
            scanf("%s", department.departmentStatus);
        }
        fwrite(&department, sizeof(Department), 1, temp_file);
    }
    fclose(department_file);
    fclose(temp_file);
    remove("./data/department.txt");
    rename("./data/temp.txt", "./data/department.txt");
}

void update_department()
{
    int choice;
    while (1)
    {
        printf("\n1. Update Department Name\n");
        printf("2. Update Department Head\n");
        printf("3. Update Department Contact\n");
        printf("4. Update Department Email\n");
        printf("5. Update Department Status\n");
        printf("6. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            update_department_name();
            break;
        case 2:
            update_department_head();
            break;
        case 3:
            update_department_contact();
            break;
        case 4:
            update_department_email();
            break;
        case 5:
            update_department_status();
            break;
        case 6:
            return;
        default:
            printf("\nInvalid choice\n");
        }
    }
}

int delete_department()
{
    Department department;
    int departmentId;
    department_file = fopen("./data/department.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (department_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter department id to delete: ");
    scanf("%d", &departmentId);

    while (fread(&department, sizeof(Department), 1, department_file))
    {
        if (department.departmentId != departmentId)
        {
            fwrite(&department, sizeof(Department), 1, temp_file);
        }
    }
    fclose(department_file);
    fclose(temp_file);
    remove("./data/department.txt");
    rename("./data/temp.txt", "./data/department.txt");
    return 1;
}