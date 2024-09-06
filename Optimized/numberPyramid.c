#include<stdio.h>

int main(){

    int n;
    printf("Enter Any Number : ");
    scanf("%d",&n);

    int num = 1, i=1, j=1;
    while(i<n){
        printf("%d ", num);
        num++;
        if(i==j){
            printf("\n");
            j++;
            i = 0;
        }
        i++;
    }
    return 0;
}