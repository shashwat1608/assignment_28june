#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    std::vector<int> nums = {2, 4, 2, 5, 4, 6, 6};
    int single = singleNumber(nums);
    std::cout << "The single number is: " << single << std::endl;
    return 0;
}
