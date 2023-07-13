#include <iostream>
#include <vector>
#include <algorithm>

bool canAttendAllMeetings(std::vector<std::vector<int>>& intervals) {
    // Sort the intervals based on their start time
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    // Check if any two consecutive meetings overlap
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false; // Meetings overlap
        }
    }

    return true; // No overlapping meetings
}

int main() {
    // Example usage
    std::vector<std::vector<int>> intervals = {{1, 3}, {4, 6}, {8, 10}, {2, 5}, {7, 9}};

    if (canAttendAllMeetings(intervals)) {
        std::cout << "The person can attend all meetings.\n";
    } else {
        std::cout << "The person cannot attend all meetings.\n";
    }

    return 0;
}
