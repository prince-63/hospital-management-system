#include "./inventory_controller.h"
#include "../../services/inventory/inventory_service.h"
#include <stdio.h>

void addInventory()
{
    int status = add_inventory();
    if (status == 1)
    {
        printf("\nInventory added successfully\n");
    }
    else
    {
        printf("\nFailed to add inventory\n");
    }
}

void viewInventory()
{
    display_inventory();
}

void updateInventory()
{
    update_inventory();
}

void deleteInventory()
{
    int status = delete_inventory();
    if (status == 1)
    {
        printf("\nInventory deleted successfully\n");
    }
    else
    {
        printf("\nFailed to delete inventory\n");
    }
}

void inventoryController()
{
    int choice;
    while (1)
    {
        printf("\n1. Add Inventory\n");
        printf("2. View Inventory\n");
        printf("3. Update Inventory\n");
        printf("4. Delete Inventory\n");
        printf("5. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addInventory();
            break;
        case 2:
            viewInventory();
            break;
        case 3:
            updateInventory();
            break;
        case 4:
            deleteInventory();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        };
    }
}
