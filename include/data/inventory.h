#ifndef INVENTORY_H
#define INVENTORY_H

#include <gb/gb.h>


typedef struct FInventoryItem {
    uint8_t current_quantity;
    uint8_t max_quantity;
} FInventoryItem;

#define ITEM_TYPES 10
#define SLOT_POTION 1
#define SLOT_02 2
#define SLOT_03 3
#define SLOT_04 4
#define SLOT_05 5
#define SLOT_06 6
#define SLOT_07 7
#define SLOT_08 8
#define SLOT_09 9
#define SLOT_10 10

typedef struct FInventory {
    FInventoryItem inventoryItems[ITEM_TYPES];
} FInventory;

void initInventory(FInventory *inv);

uint8_t addItem();
uint8_t removeItem();
uint8_t getItemQuantity();

#endif // INVENTORY_H
