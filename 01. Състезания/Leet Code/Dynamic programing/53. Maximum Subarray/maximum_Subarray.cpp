class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        int maxi = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] = max(nums[i - 1], 0) + nums[i];
            if(nums[i] > maxi) maxi = nums[i];
        }

        return maxi;
    }
};
