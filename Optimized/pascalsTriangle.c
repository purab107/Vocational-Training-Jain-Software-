#include <stdio.h>

int main() {
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    int i = 0;       
    int j = 0;       
    int number = 1;  

    while (i < rows) {
        
        if (j < rows - i - 1) {
            printf(" ");
            j++;
        } 
        
        else if (j <= i + (rows - i - 1)) {
            printf("%d ", number);
            number = number * (i - (j - (rows - i - 1))) / (j - (rows - i - 1) + 1);
            j++;
        } 
        
        else {
            printf("\n");
            i++;
            j = 0;         
            number = 1;   
        }
    }

    return 0;
}
