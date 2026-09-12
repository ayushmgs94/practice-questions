class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());

        for (int first = 0; first < nums.size(); first++) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;

            int left = first + 1;
            int right = nums.size() - 1;
            while (left < right) {
                long long sum = (long long)nums[first] + nums[left] + nums[right];

                if (sum == 0) {
                    answer.push_back({nums[first], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < 0) left++;
                else right--;
            }
        }

        return answer;
    }
};