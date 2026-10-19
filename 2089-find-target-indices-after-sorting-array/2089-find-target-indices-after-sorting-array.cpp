class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        int start = 0, last = nums.size() - 1;

        while (start <= last) {
            if (nums[start] == target) {
                ans.push_back(start);
            }
            if(nums[start] > target) break;
            start++;
        }

        return ans; 
    }
};