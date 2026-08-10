#include <iostream>
using namespace std;

// Heapify function
void heapify(int arr[], int n, int i)
{
    int largest = i;          // Assume root is largest
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Fix the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n)
{
    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Step 2: Move largest element to the end
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        // Heap size decreases
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
