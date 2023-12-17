#include <iostream>
#include <vector>

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    std::vector<int> count(max + 1, 0);

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Example Usage
// int main() {
//     int arr[] = {4, 2, 1, 0, 3, 3, 1, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     countingSort(arr, n);
//      Print sorted array
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     return 0;
// }
