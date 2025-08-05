class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int max=0;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                c++;
            }
            if(max<c)
            {
                max=c;
            }
            if(nums[i]==0)
            {
                c=0;
            }

        }
        return max;
    }
};