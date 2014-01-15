/* sort.c 
 * A collection of typical sorting algorithms
 */


#include <stdio.h>
#include <stdlib.h>


// selection sort 
void selectionSort(int arr[], int start, int end) {
    int i, j;
    for (i = start; i < end; i++) {
        int min, k;
        min = arr[i];
        k = i;
        for (j = i; j <= end; j++) {
            if (arr[j] < min) {
                min = arr[j];
                k = j;
            }
        }
        arr[k] = arr[i];
        arr[i] = min;
    }
}


// bubble sort
void bubbleSort(int arr[], int start, int end) {
    int last;
    int j = end;
    int i;
    int tmp;
    
    while (j > start) {
        for (i = start; i < j; i++) {
            last = start;
            if (arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                last = i;
            }
        }
        j = last;
    }
}

// insertion sort
void insertionSort(int arr[], int start, int end) {
    int i, j;
    int tmp;
    
    for (i = start + 1; i <= end; i++) {
        for (j = i - 1; j >= start; j--) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
            else 
                break;
        }
    }
}

// heap and heap sort


// quick sort


// shell sort



// merge sort


int main() {
    int arr[] = {6, 54, 2, 80, 15, 23, 52, 1, 100, 77, 49, 20};
    
    insertionSort(arr, 0, 11);
    int i;
    printf("sorted list:\n");
    for (i = 0; i < 12; i++)
        printf(" %d,", arr[i]);
    printf("\n");

    return 0;
}

