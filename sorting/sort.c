/* sort.c 
 * A collection of typical sorting algorithms
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXINPUTSIZE 1000000

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
// helper function: percolate(int arr[], int start, int end) 
void percolate(int arr[], int start, int end) {
    int curr = start;
    int left = 2 * curr + 1;
    while (left <= end) {
        int next;
        if (left < end) {
            if (arr[left] > arr[left + 1]) 
                next = left;
            else 
                next = left + 1;
        }
        else 
            next = left;

        if (arr[curr] < arr[next]) {
            int tmp = arr[curr];
            arr[curr] = arr[next];
            arr[next] = tmp;
            curr = next; 
            left = 2 * curr + 1;
        }
        else break;
    }
}


void heapSort(int arr[], int start, int end) {
    // first heapify the array
    int i;
    for (i = end; i >= 0; i--) {
        percolate(arr, i, end);
    }

    // then sort and percolate
    for (i = end; i > 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        
        // percolate
        percolate(arr, 0, i - 1);
    }
}



// quick sort
// helper function: swap
void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// recursive version
void recursiveQsort(int arr[], int start, int end) {
    if (end - start <= 120) {
        insertionSort(arr, start, end);
        return;
    }
     
    int pivot, pivotVal;
    int mid = (start + end) / 2;
    if (arr[start] < arr[end]) {
        if (arr[end] < arr[mid]) 
            pivot = end;
        else if (arr[start] > arr[mid])
            pivot = start;
        else
            pivot = mid;
    }
    else {
        if (arr[start] < arr[mid]) 
            pivot = start;
        else if (arr[end] > arr[mid])
            pivot = end;
        else 
            pivot = mid;
    }
    pivotVal = arr[pivot];
    swap(&arr[pivot], &arr[start]);
    int left = start + 1;
    int right = end;
  
    while (1) {
        while (arr[left] <= pivotVal) left++;
        while (arr[right] > pivotVal) right--;
        
        if (left > right)
            break;
        
        swap(&arr[left], &arr[right]);
    }

    swap(&arr[right], &arr[start]);
    if (right <= mid) {
        recursiveQsort(arr, start, right - 1);
        recursiveQsort(arr, right + 1, end);
    }
    else {
        recursiveQsort(arr, start, right - 1);
        recursiveQsort(arr, right + 1, end);
    }
}

// non-recursive version
void qSort(int arr[], int start, int end) {
    

}

// merge sort


int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./test <inputDataFile>\n");
        exit(1);
    }
    
    FILE* ifp = fopen(argv[1], "r");
    if (ifp == NULL) {
        fprintf(stderr, "Can't open input file!\n");
        exit(1);
    }

    int* arr = (int*) malloc(MAXINPUTSIZE * sizeof(int));
    int i = 0;
    while (i < MAXINPUTSIZE && fscanf(ifp, "%d", &arr[i++]) != NULL);
   
    clock_t start = clock();
    recursiveQsort(arr, 0, MAXINPUTSIZE - 1);
    clock_t end = clock();
    double elapsed_time = (end - start) / (double) CLOCKS_PER_SEC;

    FILE* ofp = fopen("output", "w");

    printf("Sorting time: %f\n", elapsed_time);
    for (i = 0; i < MAXINPUTSIZE; i++)
        fprintf(ofp, "%d, ", arr[i]);
    // printf("\n");

    return 0;
}

