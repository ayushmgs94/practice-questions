class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int size = nums.size();

        for (int first = 0; first < size - 3; first++) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;

            for (int second = first + 1; second < size - 2; second++) {
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;

                int left = second + 1;
                int right = size - 1;
                while (left < right) {
                    long long sum = (long long)nums[first] + nums[second] + nums[left] + nums[right];

                    if (sum == target) {
                        answer.push_back({nums[first], nums[second], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else if (sum < target) left++;
                    else right--;
                }
            }
        }

        return answer;
    }
};