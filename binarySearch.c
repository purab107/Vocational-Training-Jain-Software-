#include <stdio.h>

typedef struct {
    int orderID;
    char customerName[50];
    char product[50];
} Order;

Order* binarySearch(Order orders[], int n, int targetOrderID) {
    
    int low = 0;
    int high = n - 1;

    while (low <= high) { 
        
        int mid = low + (high - low) / 2; 
        
        if (orders[mid].orderID == targetOrderID) {
            return &orders[mid];
        } 
        
        else if (orders[mid].orderID < targetOrderID) {
            low = mid + 1;
        } 
        
        else {
            high = mid - 1;
        }
    }

    return NULL;
}

int main() {
    
    Order orders[] = {
        {101, "Alex", "Laptop"},
        {102, "Bob", "Smartphone"},
        {103, "Charlie", "Tablet"},
        {104, "David", "Monitor"},
        {105, "Eve", "Keyboard"}
    };

    int n = sizeof(orders) / sizeof(orders[0]);

    int targetOrderID;
    printf("Enter Target Order ID: ");
    scanf("%d", &targetOrderID);

    Order* order = binarySearch(orders, n, targetOrderID);

    if (order != NULL) {
        printf("Order Found:\nOrder ID: %d\nCustomer Name: %s\nProduct Name: %s\n", 
                order->orderID, order->customerName, order->product);
    } 
    
    else {
        printf("Order Not Found\n");
    }
    
    return 0;
}
