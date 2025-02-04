#include <stdio.h>
#include <string.h>

#define MAX_STOCK_ITEMS 1000

// Structure to represent a stock item
struct StockItem 
{
    char name[50];
    int quantity;
    float buyingPrice;
    float sellingPrice;
    char expDate[20];
};

// Function to add a new item to the stock
void addItem(struct StockItem stock[], int *numItems) {
    if (*numItems >= MAX_STOCK_ITEMS) {
        printf("Stock is full. Cannot add more items.\n");
        return;
    }

    printf("Enter the Name of the Item: ");
    getchar();  // to consume any leftover newline character from previous input
    fgets(stock[*numItems].name, sizeof(stock[*numItems].name), stdin);
    stock[*numItems].name[strcspn(stock[*numItems].name, "\n")] = '\0'; // remove newline character if present

    printf("Enter the Quantity: ");
    scanf("%d", &stock[*numItems].quantity);

    printf("Enter the Buying Price: ");
    scanf("%f", &stock[*numItems].buyingPrice);

    printf("Enter the Selling Price: ");
    scanf("%f", &stock[*numItems].sellingPrice);

    printf("Enter the Expiry Date (DD/MM/YYYY): ");
    getchar();  // consume any leftover newline character
    fgets(stock[*numItems].expDate, sizeof(stock[*numItems].expDate), stdin);
    stock[*numItems].expDate[strcspn(stock[*numItems].expDate, "\n")] = '\0';  // remove newline character if present

    (*numItems)++;
}

// Function to display all items in the stock
void displayItems(struct StockItem stock[], int numItems) {
    if (numItems == 0) {
        printf("Stock is empty.\n");
        return;
    }

    printf("Stock Items:\n");
    printf("%-20s %-10s %-15s %-15s %-10s\n", "Item Name", "Quantity", "Buying Price", "Selling Price", "Exp. Date");

    for (int i = 0; i < numItems; i++) {
        printf("%-20s %-10d %-15.2f %-15.2f %-10s\n", stock[i].name, stock[i].quantity, stock[i].buyingPrice, stock[i].sellingPrice, stock[i].expDate);
    }
}

// Function to search for an item in the stock by its name
void searchItem(struct StockItem stock[], int numItems) {
    char searchName[50];
    printf("Enter the name of item to search for: ");
    getchar();  // consume any leftover newline character
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // remove newline character if present

    for (int i = 0; i < numItems; i++) {
        if (strcmp(stock[i].name, searchName) == 0) {
            printf("Item Found:\n");
            printf("%-20s %-10s %-15s %-15s %-10s\n", "Item Name", "Quantity", "Buying Price", "Selling Price", "Exp. Date");
            printf("%-20s %-10d %-15.2f %-15.2f %-10s\n", stock[i].name, stock[i].quantity, stock[i].buyingPrice, stock[i].sellingPrice, stock[i].expDate);
            return;
        }
    }

    printf("Item not found in the stock.\n");
}

// Function to delete an item from the stock by its name
void deleteItem(struct StockItem stock[], int *numItems) {
    char deleteName[50];
    printf("Enter the name of item to delete: ");
    getchar();  // consume any leftover newline character
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';  // remove newline character if present

    for (int i = 0; i < *numItems; i++) {
        if (strcmp(stock[i].name, deleteName) == 0) {
            // Shift the items after the deleted item to the left
            for (int j = i; j < *numItems - 1; j++) {
                stock[j] = stock[j + 1];
            }
            (*numItems)--;  // Decrease the count of items
            printf("Item '%s' has been deleted.\n", deleteName);
            return;
        }
    }

    printf("Item not found in the stock. Cannot delete.\n");
}

// Function to update an item in the stock by its name
void updateItem(struct StockItem stock[], int numItems) {
    char updateName[50];
    printf("Enter the name of item to update: ");
    getchar();  // consume any leftover newline character
    fgets(updateName, sizeof(updateName), stdin);
    updateName[strcspn(updateName, "\n")] = '\0';  // remove newline character if present

    for (int i = 0; i < numItems; i++) {
        if (strcmp(stock[i].name, updateName) == 0) {
            printf("Item Found: %s\n", stock[i].name);

            printf("Enter the new Quantity: ");
            scanf("%d", &stock[i].quantity);

            printf("Enter the new Buying Price: ");
            scanf("%f", &stock[i].buyingPrice);

            printf("Enter the new Selling Price: ");
            scanf("%f", &stock[i].sellingPrice);

            printf("Enter the new Expiry Date (DD/MM/YYYY): ");
            getchar();  // consume any leftover newline character
            fgets(stock[i].expDate, sizeof(stock[i].expDate), stdin);
            stock[i].expDate[strcspn(stock[i].expDate, "\n")] = '\0';  // remove newline character if present

            printf("Item '%s' has been updated.\n", stock[i].name);
            return;
        }
    }

    printf("Item not found in the stock. Cannot update.\n");
}

int main() {
    struct StockItem stock[MAX_STOCK_ITEMS];
    int numItems = 0;
    int choice;

    do {
        printf("\n");
        printf("Welcome to StockMaster\n");
        printf("\n");
        printf("1. Stock Entry\n");
        printf("2. View Product\n");
        printf("3. Find Product\n");
        printf("4. Delete Stock\n");
        printf("5. Update Stock\n");
        printf("6. Exit The Program\n");
        printf("\n");
        printf("Enter your choice (option number): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addItem(stock, &numItems);
                break;
            case 2:
                displayItems(stock, numItems);
                break;
            case 3:
                searchItem(stock, numItems);
                break;
            case 4:
                deleteItem(stock, &numItems);
                break;
            case 5:
                updateItem(stock, numItems);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}
