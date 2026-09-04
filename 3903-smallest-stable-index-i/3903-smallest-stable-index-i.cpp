class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
      int n=nums.size();
      for(int i=0;i<n;i++){
        int maxi=nums[0];//first number itself is largest 
        int mini=nums[i];//min 

        for(int j=0;j<=i;j++)
             maxi=max(maxi,nums[j]);
            //maximum is the first number 

        //start from tht index and see the min number 
        for(int j=i;j<n;j++)
            mini=min(mini,nums[j]);
        //condition
       if(maxi - mini <= k)
            return i;
      }
      return -1;
    }
};