class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int uniqueCount = 1;
        for (int index = 1; index < nums.size(); index++) {
            if (nums[index] != nums[uniqueCount - 1]) {
                nums[uniqueCount] = nums[index];
                uniqueCount++;
            }
        }

        return uniqueCount;
    }
};