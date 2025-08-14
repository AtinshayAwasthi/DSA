class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int original=nums[i];
            int extra = target-original;
            if(m.find(extra)!=m.end())
            {
                return {m.at(extra),i};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};