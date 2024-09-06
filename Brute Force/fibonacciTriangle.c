#include <stdio.h>

int main() {
    int n;

    printf("Enter the num of n: ");
    scanf("%d", &n);

    int i = 0;       
    int j = 0;       
    int num = 1;  

    while (i < n) {
        if (j < n - i - 1) {
            printf(" ");
            j++;
        } 
        else if (j <= i) {
            printf("%d ", num);
            num = num * (i - j) / (j + 1);
            j++;
        }
        else {
            printf("\n");
            i++;
            j = 0;   
            num = 1;  
        }
    }

    return 0;
}