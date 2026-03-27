#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify upward (used after insertion)
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Heapify downward (used after deletion)
void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

// Insert element into priority queue
void insert(int value) {
    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Delete highest priority element
int delete() {
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return root;
}

// Display elements
void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Main function
int main() {

    insert(40);
    insert(20);
    insert(30);
    insert(10);
    insert(50);

    printf("Priority Queue (Heap): ");
    display();

    printf("Deleted element (Highest Priority): %d\n", delete());

    printf("After deletion: ");
    display();

    return 0;
}