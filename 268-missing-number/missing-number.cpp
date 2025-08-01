class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<=n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(i==nums[j])
                {
                    c=1;
                    break;
                }
            }
            if(c==0) return i;
        }
        return -1;
    }
};