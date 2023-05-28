// Subset Sum Problem
// Recurrence formula: result[i][j] = result[i - 1][j] or result[i - 1][j - nums[i]]
// i -> (i + 1)th number, j -> the target number

#include <iostream>
#include <vector>

bool isSubsetPossible(std::vector<int>& nums, int target) {
    std::vector<std::vector<bool>> result(nums.size() + 1, std::vector<bool> arr(target + 1, false));

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            if (i == 0) result[i][j] = false;
            if (j == 0) result[i][j] = true;

            if (j < nums[i]) result[i][j] = result[i - 1][j];
            else result[i][j] = result[i - 1][j] || result[i - 1][j - nums[i]];
        }
    }
    
    return result[nums.size()][target];
}

int main() {
    std::cout << "===== Start =====" << std::endl;

    std::vector<int> nums = { 7, 8, 5, 3 };
    int target = 13;

    std::cout << "Is it possible to make the target with subset sum of the array?: " << isSubsetPossible(nums, target) << std::endl;
}