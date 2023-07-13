#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    
    if (n < 4) {
        return result; // If the array has less than 4 elements, return empty result
    }
    
    sort(nums.begin(), nums.end()); // Sort the array in ascending order
    
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue; // Skip duplicates for the first number
        }
        
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue; // Skip duplicates for the second number
            }
            
            int left = j + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++; // Skip duplicates for the third number
                    }
                    
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--; // Skip duplicates for the fourth number
                    }
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++; // Increment left pointer if the sum is too small
                } else {
                    right--; // Decrement right pointer if the sum is too large
                }
            }
        }
    }
    
    return result;
}

int main() {
    // Test the function
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    
    vector<vector<int>> result = fourSum(nums, target);
    
    // Print the result
    for (const auto& quadruplet : result) {
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
