class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int bestSum = nums[0] + nums[1] + nums[2];

        for (int first = 0; first < nums.size() - 2; first++) {
            int left = first + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currentSum = nums[first] + nums[left] + nums[right];
                if (abs(target - currentSum) < abs(target - bestSum)) bestSum = currentSum;

                if (currentSum < target) left++;
                else if (currentSum > target) right--;
                else return currentSum;
            }
        }

        return bestSum;
    }
};