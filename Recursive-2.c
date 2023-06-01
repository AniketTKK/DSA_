2.A code to sort an array using quicksort algorithm
#include <stdio.h>

// A function to swap two elements in an array
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// A function to sort an array using quicksort algorithm
void quicksort(int arr[], int low, int high) {
  // Base case: if the array has one or zero elements, return
  if (low >= high) {
    return;
  }
  // Choose the last element as the pivot and initialize the index of the smaller element
  int pivot = arr[high], i = low - 1;
  // Loop through the array and swap the elements that are smaller than the pivot with the index i
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      swap(&arr[++i], &arr[j]);
    }
  }
  // Swap the pivot with the element at index i+1 and return its index
  int p = i+1;
  swap(&arr[p], &arr[high]);
  // Sort the left and right subarrays recursively
  quicksort(arr, low, p-1);
  quicksort(arr, p+1, high);
}

// A function to print an array
void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  // Create a sample array
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Print the original array
  printf("Original array: ");
  print_array(arr, n);

  // Sort the array using quicksort and print the sorted array
  quicksort(arr, 0, n-1);
  printf("Sorted array: ");
  print_array(arr, n);

  return 0;
}
