#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
    std::vector<std::string> result;

    // Helper function to add a range to the result
    auto addRange = [&](int start, int end) {
        if (start == end)
            result.push_back(std::to_string(start));
        else
            result.push_back(std::to_string(start) + "->" + std::to_string(end));
    };

    // Handle the lower boundary
    if (nums.empty() || nums[0] > lower)
        addRange(lower, (nums.empty() ? upper : nums[0] - 1));

    // Handle the missing ranges between elements
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - nums[i - 1] > 1)
            addRange(nums[i - 1] + 1, nums[i] - 1);
    }

    // Handle the upper boundary
    if (!nums.empty() && nums.back() < upper)
        addRange(nums.back() + 1, upper);

    return result;
}

int main() {
    std::vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    std::vector<std::string> missingRanges = findMissingRanges(nums, lower, upper);

    std::cout << "Missing Ranges:\n";
    for (const auto& range : missingRanges) {
        std::cout << range << "\n";
    }

    return 0;
}
