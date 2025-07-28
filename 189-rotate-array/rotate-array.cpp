class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        if(n==0) return;
        k=k%n;
        if(k>n) return;
        vector<int>temp;
        for(int i=0;i<(n-k);i++)
        {
            temp.push_back(arr[i]);
        }
        for(int i=(n-k);i<n;i++)
        {
            arr[i-(n-k)]=arr[i];
        }
        int j=0;
        for(int i=k;i<n;i++)
        {
            arr[i]=temp[j];
            j++;
        }
        
    }
};