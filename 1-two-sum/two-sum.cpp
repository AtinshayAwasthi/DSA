class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            int sum=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                sum=sum+nums[j];
                if(sum==target)
                {
                    return {i,j};
                }
                else
                {
                    sum=nums[i];
                }
            }
        }
        return {};
    }
};