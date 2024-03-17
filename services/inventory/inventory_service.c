#include "../../model/inventory/inventory_model.h"
#include <stdio.h>

FILE *inventory_file, *temp_file;

int add_inventory()
{
    Inventory inventory;
    inventory_file = fopen("./data/inventory.txt", "a");

    if (inventory_file == NULL)
    {
        printf("\nFailed to open file\n");
        return 0;
    }

    printf("\nEnter inventory id: ");
    scanf("%d", &inventory.inventoryId);
    printf("Enter inventory name: ");
    scanf("%s", inventory.inventoryName);
    printf("Enter inventory quantity: ");
    scanf("%d", &inventory.inventoryQuantity);
    printf("Enter inventory price: ");
    scanf("%d", &inventory.inventoryPrice);
    printf("Enter inventory status: ");
    scanf("%s", inventory.inventoryStatus);

    fwrite(&inventory, sizeof(Inventory), 1, inventory_file);
    fclose(inventory_file);
    return 1;
}

void display_inventory()
{
    Inventory inventory;
    inventory_file = fopen("./data/inventory.txt", "r");
    if (inventory_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    // Print table header
    printf("\n%-10s %-20s %-20s %-20s %-20s\n", "Inventory Id", "Inventory Name", "Inventory Quantity", "Inventory Price", "Inventory Status");

    while (fread(&inventory, sizeof(Inventory), 1, inventory_file))
    {
        // Print table row
        printf("%-10d %-20s %-20d %-20d %-20s\n", inventory.inventoryId, inventory.inventoryName, inventory.inventoryQuantity, inventory.inventoryPrice, inventory.inventoryStatus);
    }
    fclose(inventory_file);
}

void update_inventory_name()
{
    Inventory inventory;
    int inventoryId;
    inventory_file = fopen("./data/inventory.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (inventory_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter inventory id: ");
    scanf("%d", &inventoryId);

    while (fread(&inventory, sizeof(Inventory), 1, inventory_file))
    {
        if (inventory.inventoryId == inventoryId)
        {
            printf("\nEnter new inventory name: ");
            scanf("%s", inventory.inventoryName);
        }
        fwrite(&inventory, sizeof(Inventory), 1, temp_file);
    }
    fclose(inventory_file);
    fclose(temp_file);
    remove("./data/inventory.txt");
    rename("./data/temp.txt", "./data/inventory.txt");
}

void update_inventory_quantity()
{
    Inventory inventory;
    int inventoryId;
    inventory_file = fopen("./data/inventory.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (inventory_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter inventory id: ");
    scanf("%d", &inventoryId);

    while (fread(&inventory, sizeof(Inventory), 1, inventory_file))
    {
        if (inventory.inventoryId == inventoryId)
        {
            printf("\nEnter new inventory quantity: ");
            scanf("%d", &inventory.inventoryQuantity);
        }
        fwrite(&inventory, sizeof(Inventory), 1, temp_file);
    }
    fclose(inventory_file);
    fclose(temp_file);
    remove("./data/inventory.txt");
    rename("./data/temp.txt", "./data/inventory.txt");
}

void update_inventory_price()
{
    Inventory inventory;
    int inventoryId;
    inventory_file = fopen("./data/inventory.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (inventory_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter inventory id: ");
    scanf("%d", &inventoryId);

    while (fread(&inventory, sizeof(Inventory), 1, inventory_file))
    {
        if (inventory.inventoryId == inventoryId)
        {
            printf("\nEnter new inventory price: ");
            scanf("%d", &inventory.inventoryPrice);
        }
        fwrite(&inventory, sizeof(Inventory), 1, temp_file);
    }
    fclose(inventory_file);
    fclose(temp_file);
    remove("./data/inventory.txt");
    rename("./data/temp.txt", "./data/inventory.txt");
}

void update_inventory_status()
{
    Inventory inventory;
    int inventoryId;
    inventory_file = fopen("./data/inventory.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (inventory_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter inventory id: ");
    scanf("%d", &inventoryId);

    while (fread(&inventory, sizeof(Inventory), 1, inventory_file))
    {
        if (inventory.inventoryId == inventoryId)
        {
            printf("\nEnter new inventory status: ");
            scanf("%s", inventory.inventoryStatus);
        }
        fwrite(&inventory, sizeof(Inventory), 1, temp_file);
    }
    fclose(inventory_file);
    fclose(temp_file);
    remove("./data/inventory.txt");
    rename("./data/temp.txt", "./data/inventory.txt");
}

void update_inventory()
{
    int choice;
    while (1)
    {
        printf("\n1. Update inventory name");
        printf("\n2. Update inventory quantity");
        printf("\n3. Update inventory price");
        printf("\n4. Update inventory status");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            update_inventory_name();
            break;
        case 2:
            update_inventory_quantity();
            break;
        case 3:
            update_inventory_price();
            break;
        case 4:
            update_inventory_status();
            break;
        case 5:
            return;
        default:
            printf("\nInvalid choice");
        }
    }
}

void delete_inventory()
{
    Inventory inventory;
    int inventoryId;
    inventory_file = fopen("./data/inventory.txt", "r");
    temp_file = fopen("./data/temp.txt", "w");
    if (inventory_file == NULL)
    {
        printf("\nFailed to open file\n");
        return;
    }

    printf("\nEnter inventory id: ");
    scanf("%d", &inventoryId);

    while (fread(&inventory, sizeof(Inventory), 1, inventory_file))
    {
        if (inventory.inventoryId != inventoryId)
        {
            fwrite(&inventory, sizeof(Inventory), 1, temp_file);
        }
    }
    fclose(inventory_file);
    fclose(temp_file);
    remove("./data/inventory.txt");
    rename("./data/temp.txt", "./data/inventory.txt");
}
