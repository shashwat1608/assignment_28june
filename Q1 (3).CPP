#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int threeSumClosest(std::vector<int>& nums, int target) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            if (currentSum == target) {
                return currentSum; // Found exact sum, return immediately
            }

            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            if (currentSum < target) {
                ++left; // Increment left pointer for a larger sum
            } else {
                --right; // Decrement right pointer for a smaller sum
            }
        }
    }

    return closestSum;
}

int main() {
    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int closestSum = threeSumClosest(nums, target);
    std::cout << "Closest sum to target: " << closestSum << std::endl;
    return 0;
}
