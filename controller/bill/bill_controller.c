#include "./bill_controller.h"
#include <stdio.h>

void addBill()
{
    printf("Add Bill\n");
}

void viewBill()
{
    printf("View Bill\n");
}

void updateBill()
{
    printf("Update Bill\n");
}

void deleteBill()
{
    printf("Delete Bill\n");
}

void billController()
{
    int choice;
    while (1)
    {
        printf("1. Add Bill\n");
        printf("2. View Bill\n");
        printf("3. Update Bill\n");
        printf("4. Delete Bill\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBill();
            break;
        case 2:
            viewBill();
            break;
        case 3:
            updateBill();
            break;
        case 4:
            deleteBill();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        };
    }
}
