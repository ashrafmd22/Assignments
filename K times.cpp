/*Given array of size N and number K, find all elements that appear more than N/K times*/
#include <iostream>
#include <unordered_map>
#include <vector>

void findElementsWithFrequency(std::vector<int>& nums, int k) {
    int n = nums.size();
    int threshold = n / k;

    std::unordered_map<int, int> countMap;

    for (int num : nums) {
        if (countMap.find(num) != countMap.end()) {
            countMap[num]++;
        } else if (countMap.size() < k - 1) {
            countMap[num] = 1;
        } else {
            // Decrease counts for all elements in the map
            for (auto& pair : countMap) {
                pair.second--;
                if (pair.second == 0) {
                    countMap.erase(pair.first);
                }
            }
        }
    }

    // Reset counts in the map for accurate counting
    for (auto& pair : countMap) {
        pair.second = 0;
    }

    // Count occurrences of potential elements
    for (int num : nums) {
        if (countMap.find(num) != countMap.end()) {
            countMap[num]++;
        }
    }

    // Print elements that appear more than N/K times
    std::cout << "Elements appearing more than " << n / k << " times: ";
    for (const auto& pair : countMap) {
        if (pair.second > threshold) {
            std::cout << pair.first << " ";
        }
    }
}

int main() {
    std::vector<int> nums = {4, 5, 6, 7, 8, 4, 4, 5, 5, 5};
    int k = 3;

    findElementsWithFrequency(nums, k);

    return 0;
}
