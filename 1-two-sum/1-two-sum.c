#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b) {
  
  int temp = *a;
  
  *a = *b;
  
  *b = temp;
  
}
  
// To indexHeapify a subtree rooted with node i
// which is an index in arr[]. 
// n is size of heap
void indexHeapify(int numsArr[], int indexArr[], int n, int i) {
  
  // Find largest among root, left child and right child
  
    // Initialize largest as root
  int largest = i;
  
   // left = 2*i + 1
  int left = 2 * i + 1;
  
   // right = 2*i + 2
  int right = 2 * i + 2;
  
  // If left child is larger than root
  if (left < n && numsArr[indexArr[left]] > numsArr[indexArr[largest]])
  
    largest = left;
  
  // If right child is larger than largest 
    // so far
  if (right < n && numsArr[indexArr[right]] > numsArr[indexArr[largest]])
  
    largest = right;
  
  // Swap and continue indexHeapifying if root is not largest
// If largest is not root
  if (largest != i) {
  
    swap(&indexArr[i], &indexArr[largest]);
  
     // Recursively indexHeapify the affected 
     // sub-tree
    indexHeapify(numsArr, indexArr, n, largest);
  
  }
  
}
  
// Main function to do heap sort
void indexHeapSort(int numsArr[], int indexArr[], int n) {
  
  // Build max heap
  for (int i = n / 2 - 1; i >= 0; i--)
  
    indexHeapify(numsArr, indexArr, n, i);
  
  // Heap sort
  for (int i = n - 1; i >= 0; i--) {
  
    swap(&indexArr[0], &indexArr[i]);
  
    // indexHeapify root element to get highest element at root again
    indexHeapify(numsArr, indexArr, i, 0);
  
  }
  
}


// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int indexBinarySearchPivot(int numsArr[], int indexArr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (numsArr[indexArr[mid]] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (numsArr[indexArr[mid]] > x)
            return indexBinarySearchPivot(numsArr, indexArr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return indexBinarySearchPivot(numsArr, indexArr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return r;
}
  

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int pivot;
    int *indexes = (int*)malloc(numsSize * sizeof(int));
    int *answer = (int*)malloc((sizeof(int) * 2));
    *returnSize = 2;
    for(int index = 0; index < numsSize; index++) indexes[index] = index;
    indexHeapSort(nums, indexes, numsSize);
    pivot = indexBinarySearchPivot(nums, indexes, 0, numsSize-1, target);
    for (int index1 = pivot; index1 > 0; index1--){
        for (int index2 = 0; index2 < index1; index2++){
            if ((target - nums[indexes[index1]]) < nums[indexes[index2]]) {
                break;
            }
            else if ((target - nums[indexes[index1]]) == nums[indexes[index2]]){
                answer[0] = indexes[index2];
                answer[1] = indexes[index1];
                goto out;
            }
        }
    }
    for (int index1 = (pivot + 1); index1 < numsSize; index1++){
        for (int index2 = 0; index2 < index1; index2++){
            if ((target - nums[indexes[index1]]) < nums[indexes[index2]]) {
                break;
            }
            else if ((target - nums[indexes[index1]]) == nums[indexes[index2]]){
                answer[0] = indexes[index2];
                answer[1] = indexes[index1];
                goto out;
            }
        }
    }
    out:
    free(indexes);
    if (answer[0] > answer[1]) swap(&answer[0], &answer[1]);
    return answer;
}