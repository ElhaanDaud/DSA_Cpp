//Write a program to perform the analysis of merge sort.

#include<iostream>
#include<vector>

using namespace std;


void merge(vector<int>& array, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // Number of elements in the left subarray
    int n2 = right - mid;    // Number of elements in the right subarray

    // Create temp arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    // Merge the temp arrays back into array[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index to start merging from
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& array, int left, int right) {
    if (left < right) {
       
        int mid = left + (right - left) / 2;

        
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        
        merge(array, left, mid, right);
    }
}


void printArray(vector<int>& array) {
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 0, 13, 5, 6, 7};
    int arr_size = arr.size();

    cout << "Given array is \n";
    printArray(arr);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr);
    return 0;
}
