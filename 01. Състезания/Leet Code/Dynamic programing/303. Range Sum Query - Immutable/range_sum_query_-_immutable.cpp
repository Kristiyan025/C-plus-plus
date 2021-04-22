class NumArray {
private:
    vector<int> sums[10000];
public:
    NumArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            sums[i].assign(nums.size() - i, -1);
            sums[i][0] = nums[i];
            for(int j = i + 1; j < nums.size(); j++)
            {
                sums[i][j - i] = sums[i][j - i - 1] + nums[j];
            }
        }
    }

    int sumRange(int i, int j) {
        return sums[i][j - i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
