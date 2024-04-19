#include <iostream>
#include <vector>


using namespace std;


int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; 
}


int main() {
    
    vector<int> arr = {2, 5, 7, 9, 12};
    int target = 7;
    int index = linearSearch(arr, target);
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
