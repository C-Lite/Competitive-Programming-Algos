// C++ program to sort an array
#include <bits/stdc++.h>
using namespace std;

// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2}
void DNFS(vector<int> &arr, int arr_size)
{
    int low = 0;
    int high = arr_size - 1;
    int mid = 0;
    // Iterate till all the elements
    // are sorted
    while (mid <= high)
    {
        switch (arr[mid])
        {

            // element is 0
        case 0:
            swap(arr[low++],arr[mid++]);
            break;

            // element is 1 .
        case 1:
            mid++;
            break;

            // element is 2
        case 2:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
}

// Function to print array arr[]
void printArray(vector<int> arr, int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    vector<int> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = arr.size();

    cout << "Array before running the algorithm: ";

    printArray(arr, n);

    DNFS(arr, n);

    cout << "\nArray after DNFS algorithm: ";

    printArray(arr, n);

    return 0;
}
