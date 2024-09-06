#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char name[50];
    int checkInTime;
} Attendence;

void merge(Attendence arr[], int low, int mid, int high) {

    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    
    Attendence* L = (Attendence*)malloc(n1 * sizeof(Attendence));
    Attendence* R = (Attendence*)malloc(n2 * sizeof(Attendence));


    for (i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0; 
    j = 0; 
    k = low;

    
    while (i < n1 && j < n2) {
        if (L[i].checkInTime <= R[j].checkInTime) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

   
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(Attendence arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void printAttendenceList(Attendence arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Check In Time: %d\n", arr[i].name, arr[i].checkInTime);
    }
}

int main() {

    Attendence attendees[] = {
        {"Alex", 540},
        {"Bob", 210},
        {"Charlie", 630},
        {"David", 350},
        {"Eve", 110},
        {"Ferb", 460}
    };

    int n = sizeof(attendees) / sizeof(attendees[0]);

    mergeSort(attendees, 0, n - 1);

    printAttendenceList(attendees, n);

    return 0;
}
