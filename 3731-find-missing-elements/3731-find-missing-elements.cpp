class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       //1.sort
       sort(nums.begin(),nums.end());
       vector<int> ans;
       for(int i=1;i<nums.size();i++){
        if(nums[i]-nums[i-1]>1)
        {
            for(int j=nums[i-1]+1;j<nums[i];j++)
            {   //this is where the next number counts like 2 4
                //nums[i-1] is 2
                //soo 2+1=3 is push backed to ans 
                ans.push_back(j); 
            }
                        
        }

        
       }
       return ans;//missing num

        
    }
};