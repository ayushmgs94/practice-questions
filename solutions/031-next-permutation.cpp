class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = nums.size() - 2;
        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) pivot--;

        if (pivot >= 0) {
            int larger = nums.size() - 1;
            while (nums[larger] <= nums[pivot]) larger--;
            swap(nums[pivot], nums[larger]);
        }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};