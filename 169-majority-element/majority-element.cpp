class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // optimal (moore's voting algo)
        int n = nums.size();
        int c = 0;
        int ele;
        for (int i = 0; i < n; i++) {
            if (c == 0) {
                c++;
                ele = nums[i];
            } else if (nums[i] == ele) {
                c++;
            } else {
                c--;
            }
        }
        int c1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele)
                c1++;
        }
        if (c1 > n / 2)
            return ele;
        else return -1;
    }
};