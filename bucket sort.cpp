#include <iostream>
#include <algorithm>
#include <vector>

void bucketSort(int arr[], int n) {
    const int numBuckets = 5;
    std::vector<std::vector<int>> buckets(numBuckets);

    // Place elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = numBuckets * arr[i] / (INT_MAX + 1LL);
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < numBuckets; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate buckets
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Example Usage
// int main() {
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     bucketSort(arr, n);
//     Print sorted array
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     return 0;
// }
