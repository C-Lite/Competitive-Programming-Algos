# [Question Link](https://practice.geeksforgeeks.org/problems/quick-sort/1)

# Quick Sort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.

### Given an array arr[], its starting position low and its ending position high.

### Input:
### N = 5
### arr[] = {10, 80, 30, 90, 40, 50, 70}
### Indexes:  0   1   2   3   4   5   6 
### low = 0, high =  6, pivot = arr[h] = 70
### Initialize index of smaller element, i = -1

### Traverse elements from j = low to high-1
### j = 0 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j]), i = 0 
### arr[] = {10, 80, 30, 90, 40, 50, 70}, No change as i and j are same

### j = 1 : Since arr[j] > pivot, do nothing. No change in i and arr[]

### j = 2 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
### i = 1
### arr[] = {10, 30, 80, 90, 40, 50, 70} // We swap 80 and 30 

### j = 3 : Since arr[j] > pivot, do nothing. No change in i and arr[]

### j = 4 : Since arr[j] <= pivot, do i++ and swap(arr[i], arr[j])
### i = 2
### arr[] = {10, 30, 40, 90, 80, 50, 70} // 80 and 40 Swapped
### j = 5 : Since arr[j] <= pivot, do i++ and swap arr[i] with arr[j] 
### i = 3 
### arr[] = {10, 30, 40, 50, 80, 90, 70} // 90 and 50 Swapped 

### We come out of loop because j is now equal to high-1. Finally we place pivot at correct position by swapping arr[i+1] and arr[high] (or pivot) 
### arr[] = {10, 30, 40, 50, 70, 90, 80} // 80 and 70 Swapped 

### Now 70 is at its correct place. All elements smaller than 70 are before it and all elements greater than 70 are after it.

### Expected Time Complexity: O(N*log N) --> Best & Average, O(N^2) --> Worst
### Expected Space Complexity: O(log N)


## JAVA Solution: 

```
import java.util.Arrays;
class Quicksort {
    static int partition(int array[], int low, int high) {
        int pivot = array[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        return (i + 1);
    }

    static void quickSort(int array[], int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);
            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }
}
class Main {
    public static void main(String args[]) {

        int[] data = { 8, 7, 2, 1, 0, 9, 6 };
        System.out.println("Unsorted Array");
        System.out.println(Arrays.toString(data));
        int size = data.length;
        Quicksort.quickSort(data, 0, size - 1);
        System.out.println("Sorted Array in Ascending Order: ");
        System.out.println(Arrays.toString(data));
    }
}

```