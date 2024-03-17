#include "../../model/staff/staff_model.h"
#include <stdio.h>

FILE *staff_file, *temp_file;

int add_staff()
{
    Staff staff;
    staff_file = fopen("./data/staff.txt", "a");

    if (staff_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter staff id: ");
    scanf("%d", &staff.staffId);
    printf("Enter staff name: ");
    scanf("%s", staff.staffName);
    printf("Enter staff gender: ");
    scanf("%s", staff.staffGender);
    printf("Enter staff position: ");
    scanf("%s", staff.staffPosition);
    printf("Enter staff status: ");
    scanf("%s", staff.staffStatus);

    fwrite(&staff, sizeof(Staff), 1, staff_file);
    fclose(staff_file);
    return 1;
}

void display_staff()
{
    Staff staff;
    staff_file = fopen("./data/staff.txt", "r");
    if (staff_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    // Print table header
    printf("\n%-10s %-20s %-15s %-20s %-15s\n", 
           "Staff Id", "Staff Name", "Staff Gender", "Staff Position", "Staff Status");

    while (fread(&staff, sizeof(Staff), 1, staff_file))
    {
        // Print table row
        printf("%-10d %-20s %-15s %-20s %-15s\n", 
               staff.staffId, staff.staffName, staff.staffGender, staff.staffPosition, staff.staffStatus);
    }
    fclose(staff_file);
}

void update_staff_name()
{
    Staff staff;
    int staffId;
    staff_file = fopen("./data/staff.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (staff_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter staff id to update: ");
    scanf("%d", &staffId);

    while (fread(&staff, sizeof(Staff), 1, staff_file))
    {
        if (staff.staffId == staffId)
        {
            printf("\nEnter new staff name: ");
            scanf("%s", staff.staffName);
        }
        fwrite(&staff, sizeof(Staff), 1, temp_file);
    }
    fclose(staff_file);
    fclose(temp_file);
    remove("./data/staff.txt");
    rename("./data/temp.txt", "./data/staff.txt");
}

void update_staff_gender()
{
    Staff staff;
    int staffId;
    staff_file = fopen("./data/staff.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (staff_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter staff id to update: ");
    scanf("%d", &staffId);

    while (fread(&staff, sizeof(Staff), 1, staff_file))
    {
        if (staff.staffId == staffId)
        {
            printf("\nEnter new gender: ");
            scanf("%s", staff.staffGender);
        }
        fwrite(&staff, sizeof(Staff), 1, temp_file);
    }
    fclose(staff_file);
    fclose(temp_file);
    remove("./data/staff.txt");
    rename("./data/temp.txt", "./data/staff.txt");
}

void update_staff_position()
{
    Staff staff;
    int staffId;
    staff_file = fopen("./data/staff.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (staff_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter staff id to update: ");
    scanf("%d", &staffId);

    while (fread(&staff, sizeof(Staff), 1, staff_file))
    {
        if (staff.staffId == staffId)
        {
            printf("\nEnter new staff position: ");
            scanf("%s", staff.staffPosition);
        }
        fwrite(&staff, sizeof(Staff), 1, temp_file);
    }
    fclose(staff_file);
    fclose(temp_file);
    remove("./data/staff.txt");
    rename("./data/temp.txt", "./data/staff.txt");
}

void update_staff_status()
{
    Staff staff;
    int staffId;
    staff_file = fopen("./data/staff.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (staff_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter staff id to update: ");
    scanf("%d", &staffId);

    while (fread(&staff, sizeof(Staff), 1, staff_file))
    {
        if (staff.staffId == staffId)
        {
            printf("\nEnter new staff status: ");
            scanf("%s", staff.staffStatus);
        }
        fwrite(&staff, sizeof(Staff), 1, temp_file);
    }
    fclose(staff_file);
    fclose(temp_file);
    remove("./data/staff.txt");
    rename("./data/temp.txt", "./data/staff.txt");
}

void update_staff()
{
    int choice;
    while (1)
    {
        printf("\n1. Update staff name");
        printf("\n2. Update gender");
        printf("\n3. Update position");
        printf("\n4. Update status");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            update_staff_name();
            break;
        case 2:
            update_staff_gender();
            break;
        case 3:
            update_staff_position();
            break;
        case 4:
            update_staff_status();
            break;
        case 5:
            return;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
}

void delete_staff()
{
    Staff staff;
    int staffId;
    staff_file = fopen("./data/staff.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (staff_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter staff id to delete: ");
    scanf("%d", &staffId);

    while (fread(&staff, sizeof(Staff), 1, staff_file))
    {
        if (staff.staffId != staffId)
        {
            fwrite(&staff, sizeof(Staff), 1, temp_file);
        }
    }
    fclose(staff_file);
    fclose(temp_file);
    remove("./data/staff.txt");
    rename("./data/temp.txt", "./data/staff.txt");
}