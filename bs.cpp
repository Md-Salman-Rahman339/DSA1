#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low +high)/ 2;  // Calculate mid to avoid overflow

        if (arr[mid] == target) {         // If the middle element matches the target
            return mid;
        } else if (arr[mid] < target) {   // If the target is in the right half
            low = mid + 1;
        } else {                          // If the target is in the left half
            high = mid - 1;
        }
    }
    return -1;                            // Return -1 if not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};     // The array must be sorted
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;

    int result = binarySearch(arr, size, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
