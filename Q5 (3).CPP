#include <iostream>
#include <vector>

std::vector<int> incrementLargeInteger(std::vector<int>& digits) {
    int n = digits.size();
    int carry = 1;  // Start with a carry of 1 since we want to increment the number

    // Traverse the digits from right to left
    for (int i = n - 1; i >= 0; --i) {
        int sum = digits[i] + carry;  // Add the current digit and the carry
        digits[i] = sum % 10;         // Update the digit with the remainder
        carry = sum / 10;             // Update the carry
    }

    // If there is still a carry after traversing all digits, insert it at the beginning
    if (carry > 0) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}

int main() {
    // Example usage
    std::vector<int> digits = {1, 2, 9, 9};  // Represents the number 1299

    std::cout << "Original number: ";
    for (int digit : digits) {
        std::cout << digit;
    }
    std::cout << std::endl;

    std::vector<int> result = incrementLargeInteger(digits);

    std::cout << "Result: ";
    for (int digit : result) {
        std::cout << digit;
    }
    std::cout << std::endl;

    return 0;
}
