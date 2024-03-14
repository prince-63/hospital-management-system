#include "./inventory_controller.h"
#include <stdio.h>

void addInventory()
{
    printf("Add Inventory\n");
}

void viewInventory()
{
    printf("View Inventory\n");
}

void updateInventory()
{
    printf("Update Inventory\n");
}

void deleteInventory()
{
    printf("Delete Inventory\n");
}

void inventoryController()
{
    int choice;
    while (1)
    {
        printf("1. Add Inventory\n");
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
