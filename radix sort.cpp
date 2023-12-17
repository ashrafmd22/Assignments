#include <iostream>
#include <vector>

void countSortRadix(int arr[], int n, int exp) {
    const int base = 10;
    std::vector<int> output(n, 0);
    std::vector<int> count(base, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % base]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSortRadix(arr, n, exp);
    }
}

// Example Usage
// int main() {
//     int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     radixSort(arr, n);
//      Print sorted array
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     return 0;
// }
