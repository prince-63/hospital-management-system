#include "./bill_controller.h"
#include "../../services/bill/bill_service.h"
#include <stdio.h>

void addBill()
{
    int status = add_bill();
    if (status == 1)
    {
        printf("\nBill added successfully\n");
    }
    else
    {
        printf("\nFailed to add bill\n");
    }
}

void viewBill()
{
    display_bill();
}

void updateBill()
{
    int status = update_bill();
    if (status == 1)
    {
        printf("\nBill updated successfully\n");
    }
    else
    {
        printf("\nFailed to update bill\n");
    }
}

void deleteBill()
{
    int status = delete_bill();
    if (status == 1)
    {
        printf("\nBill deleted successfully\n");
    }
    else
    {
        printf("\nFailed to delete bill\n");
    }
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
