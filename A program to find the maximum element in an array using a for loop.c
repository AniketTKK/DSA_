//A program to find the maximum element in an array using a for loop

#include <stdio.h>

int main()
 {
  int n;
  printf("Enter size of  array: ");
  scanf("%d", &n);

  int A[n];
printf("Enter the elements /n“);

  for (int i = 0; i < n; i++) {

    scanf("%d", &A[i]);
  }

  int largest_element = largest(A, n);
  printf("The largest element in the array is %d\n", largest_element);
  return 0;
}
