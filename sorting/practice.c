#include <stdio.h>
#include <stdlib.h>

// qsort
// helper function swap
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// helper function: parition
int partition(int arr[], int start, int end) {
    int pivot, pivot_val;
    pivot = start;
    pivot_val = arr[start];

    int left = start;
    int right = end;
    while (left < right) {
        while (arr[left] <= pivot_val) left++;
        while (arr[right] > pivot_val) right--;
        if (left < right) 
            swap(&arr[left], &arr[right]);
    }
    swap(&arr[pivot], &arr[right]);
    return right;
}

void quicksort(int arr[], int start, int end) {
    if (start >= end) 
        return;
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
}

// mergesort
// helper function: merge
void merge(int arr[], int start, int end, int interval) {
    int i = start;
    int left, right;
    int* c = (int*) malloc(2 * interval * sizeof(int)); 
    while (i + interval <= end) {
        left = i;
        right = i + interval;
        int rightend;
        if (i + 2 * interval > end + 1) 
            rightend = end + 1;
        else
            rightend = i + 2 * interval;
        int j = 0;
        while (left < i + interval || right < rightend) {
            if (right >= rightend || (arr[left] < arr[right] && left < i + interval)) 
                c[j++] = arr[left++];
            else 
                c[j++] = arr[right++];
        }
        for (j = 0; j < 2 * interval && i + j <= end; j++)
            arr[i + j] = c[j];

        i += 2 * interval;
    }
}

void mergeSort(int arr[], int start, int end) {
    int interval = 1;
    for(; interval <= end - start; interval *= 2) {
        merge(arr, start, end, interval);
    }
}

// merge sort for linked list
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// helper funciton: mergeList
// merge two sorted lists
void mergeList(Node** left, Node** right) {
    Node* a = *left;
    Node* b = *right;
    while (b != NULL && b->val < (*left)->val) {
        Node* tmp = b;
        b = b->next;
        tmp->next = *left;
        *left = tmp;
    }
    if (b == NULL)
        return;
    while (b) {
        while (a->next != NULL && a->next->val <= b->val) 
            a = a->next;
        if (a->next == NULL) {
            a->next = b;
            break;
        }
        // insert b between a and a->next
        Node* tmp = b;
        b = b->next;
        tmp->next = a->next;
        a->next = tmp;
        a = a->next;
    }
}

void mergeSortList(Node** head) {
    int size = 0;
    Node* tmp = *head;
    while (tmp) {
        size++;
        tmp = tmp->next;
    }
    Node** arr = malloc(size * sizeof *arr);
    tmp = *head;
    int i = 0;
    while (tmp) {
        arr[i] = tmp;
        tmp = tmp->next;
        arr[i++]->next = NULL;
    }

    for (int intvl = 1; intvl < size; intvl *= 2) {
        for (int j = 0; j + intvl < size; j += 2 * intvl) 
            mergeList(&arr[j], &arr[j + intvl]);
    }
    *head = arr[0];
    free(arr);
}

Node* buildList(int a[], int size) {
    if (size == 0) 
        return NULL;
    Node* head = malloc(sizeof *head);
    Node* tail = head;
    head->val = a[0];
    head->next = NULL;
    for (int i = 1; i < size; i++) {
        Node* n = malloc(sizeof *n);
        n->val = a[i];
        n->next = NULL;
        tail->next = n;
        tail = n;
    }
    return head;
}

void printList(Node* head) {
    printf("List:\n");
    while (head) {
        printf("%d, ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 12, 1, 188, 21, 999, -12, 23, 98, 0, 77};
   // mergeSort(arr, 0, 11);
    
    int i;
    printf("sorted list:\n");
    for (i = 0; i < 12; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
     
    Node* head = buildList(arr, 12);
    mergeSortList(&head);
    printList(head);   
    return 0;
}



