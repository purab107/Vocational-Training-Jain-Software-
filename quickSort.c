#include<stdio.h>

void swap(int* a, int* b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){

    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<=high-1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    
    if(low<high){
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}

void printArray(int arr[], int n){

    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}

int main() {

    int prices[] = {5000, 8000, 1260, 5432, 9425, 3526};

    int n = sizeof(prices) / sizeof(prices[0]);

    quickSort(prices, 0, n-1);

    printArray(prices, n);

    return 0;
}