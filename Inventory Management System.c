#include<stdio.h>
#include<string.h>

struct Item {
    int itemcode;
    char itemName[50];
    int quantity;
};

struct Item items[100];
int count = 0;
void addnewitem();
void updatequantity();
void displayitems();
void finditem();

int main() {
    int choice;

    printf("----------INVENTORY MANAGEMENT SYSTEM----------\n");

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Add new item\n");
        printf("2. Update quantity\n");
        printf("3. Display all items\n");
        printf("4. Find item by code\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < 100) {
                    addnewitem();
                } else {
                    printf("Inventory is full! Cannot add more items.\n");
                }
                break;
            case 2:
                updatequantity();
                break;
            case 3:
                displayitems();
                break;
            case 4:
                finditem();
                break;
            case 5:
                printf("Thank you for using Inventory Management System!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addnewitem() {
    printf("\n--------- Add New Item ----------\n");
    printf("Enter item code: ");
    scanf("%d", &items[count].itemcode);

    for (int i = 0; i < count; i++) {
        if (items[i].itemcode == items[count].itemcode) {
            printf("Item code already exists! Please use a different code.\n");
            return;
        }
    }

    printf("Enter item name: ");
    scanf("%s", items[count].itemName);
    printf("Enter quantity: ");
    scanf("%d", &items[count].quantity);

    count++;
    printf("Item added successfully!\n");
}

void updatequantity() {
    int code, newQuantity;
    int found = 0;

    if (count == 0) {
        printf("No items in inventory!\n");
        return;
    }

    printf("\n--------- Update Quantity ----------\n");
    printf("Enter item code: ");
    scanf("%d", &code);
    printf("Enter new quantity: ");
    scanf("%d", &newQuantity);

    for (int i = 0; i < count; i++) {
        if (items[i].itemcode == code) {
            int oldQuantity = items[i].quantity;
            items[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            printf("Old quantity: %d -> New quantity: %d\n", oldQuantity, newQuantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with code %d not found!\n", code);
    }
}

void displayitems() {
    printf("\n--------- All Items in Inventory ----------\n");

    if (count == 0) {
        printf("No items in inventory!\n");
        return;
    }

    printf("%-10s %-20s %-10s\n", "Code", "Name", "Quantity");
    printf("-------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10d\n", items[i].itemcode, items[i].itemName, items[i].quantity);
    }

    printf("--------------------------------------------\n");
    printf("Total items: %d\n", count);
}

void finditem() {
    int code;
    int found = 0;

    if (count == 0) {
        printf("No items in inventory!\n");
        return;
    }

    printf("\n--------- Find Item ----------\n");
    printf("Enter item code to search: ");
    scanf("%d", &code);

    for (int i = 0; i < count; i++) {
        if (items[i].itemcode == code) {
            printf("Item found!\n");
            printf("Code: %d\n", items[i].itemcode);
            printf("Name: %s\n", items[i].itemName);
            printf("Quantity: %d\n", items[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with code %d not found!\n", code);
    }
}
