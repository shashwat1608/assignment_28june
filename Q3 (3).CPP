#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Find the next greater element to swap with
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }

        // Swap the elements
        swap(nums[i], nums[j]);
    }

    // Reverse the remaining elements
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    // Input array
    vector<int> nums = {1, 2, 3};

    // Find the next permutation
    nextPermutation(nums);

    // Print the result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
