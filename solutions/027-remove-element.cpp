class Solution {
public:
    int removeElement(vector<int>& nums, int value) {
        int newLength = 0;

        for (int number : nums) {
            if (number != value) {
                nums[newLength] = number;
                newLength++;
            }
        }

        return newLength;
    }
};