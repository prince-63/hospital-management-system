#ifndef INVENTORY_MODEL_H
#define INVENTORY_MODEL_H

typedef struct Inventory
{
    int inventoryId;
    char inventoryName[50];
    int inventoryQuantity;
    int inventoryPrice;
    char inventoryStatus[10];
} Inventory;

#endif