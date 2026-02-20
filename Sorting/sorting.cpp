#include <iostream>
#include <algorithm>
using namespace std;

// -------------------- Bubble Sort --------------------
// Logic: Repeatedly compare adjacent elements and swap if out of order.
// After each pass, the largest element "bubbles up" to the end.
void BubbleSort(int arr[], int size)
{
  int r, i;
  for (r = 1; r <= size - 1; r++) {
    for (i = 0; i <= size - 1 - r; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
}
// Time Complexity: O(n^2) (worst/average), O(n) (best if already sorted)
// Space Complexity: O(1) (in-place)

// -------------------- Modified Bubble Sort --------------------
// Logic: Same as Bubble Sort, but stops early if no swaps happen in a pass.
// This optimization detects if the array is already sorted.
void Modify_BubbleSort(int arr[], int size)
{
  int r, i;
  bool swap = false;
  for (r = 1; r <= size - 1; r++) {
    for (i = 0; i <= size - 1 - r; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swap = true;
      }
    }
    if (!swap) // no swaps → array is sorted
      break;
  }
}
// Time Complexity: O(n^2) worst/average, O(n) best case (sorted)
// Space Complexity: O(1)

// -------------------- Selection Sort --------------------
// Logic: Find the minimum element in the unsorted part and put it at the front.
// Repeats until the array is sorted.
void SelectionSort(int arr[], int n)
{
  int i, j, minIndex;
  for (i = 0; i < n - 1; i++) {
    minIndex = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}
// Time Complexity: O(n^2) (always, regardless of input)
// Space Complexity: O(1)

// -------------------- Insertion Sort --------------------
// Logic: Builds the sorted array one element at a time.
// Each new element is inserted into its correct position among the sorted part.
void insertionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j > 0; j--) {
      int temp = arr[j];
      if (temp < arr[j - 1]) {
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
      } else {
        break;
      }
    }
  }
}
// Time Complexity: O(n^2) worst/average, O(n) best case (sorted)
// Space Complexity: O(1)

// -------------------- Quick Sort (Partition Function) --------------------
// Logic: Choose pivot (first element), move it to correct position
// by swapping with elements from left and right until left == right.
int quikSort_for_one(int arr[], int l, int r)
{
  int left = l;
  int loc = l;   // pivot starts at first element of subarray
  int right = r;
  while (left != right) {
    if (arr[loc] < arr[right]) {
      right--;
    } else {
      swap(arr[loc], arr[right]);
      loc = right;
    }
    if (arr[left] < arr[loc]) {
      left++;
    } else {
      swap(arr[loc], arr[left]);
      loc = left;
    }
  }
  return loc; // final pivot position
}

// -------------------- Quick Sort --------------------
// Logic: Recursively partition the array around a pivot.
// Left side < pivot, right side > pivot.
int quikSort(int arr[], int l, int r)
{
  if (l < r) {
    int index = quikSort_for_one(arr, l, r);
    quikSort(arr, l, index - 1);
    quikSort(arr, index + 1, r);
  }
}
// Time Complexity: O(n log n) average, O(n^2) worst (bad pivot choice)
// Space Complexity: O(log n) recursion stack (average), O(n) worst case

// -------------------- Merge Function --------------------
// Logic: Merge two sorted halves into one sorted array.
void merge(int arr[], int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int left[n1], right[n2]; // temporary arrays

  for (int i = 0; i < n1; i++)
    left[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    right[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = left[i];
    i++; k++;
  }
  while (j < n2) {
    arr[k] = right[j];
    j++; k++;
  }
}
// Time Complexity: O(n) for merging two halves
// Space Complexity: O(n) (temporary arrays)

// -------------------- Merge Sort --------------------
// Logic: Recursively split array into halves, then merge them back sorted.
void mergeSort(int arr[], int l, int r)
{
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
// Time Complexity: O(n log n) (always)
// Space Complexity: O(n) (temporary arrays + recursion stack)

// -------------------- Main --------------------
int main()
{
  int arr[] = {21, 40, 38, 68, 70, 25, 90, 18, 7, 54};
  quikSort(arr, 0, 9); // Example: QuickSort
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
} 