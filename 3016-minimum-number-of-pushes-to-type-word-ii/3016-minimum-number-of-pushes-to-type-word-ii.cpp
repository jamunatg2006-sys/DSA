class Solution {
public:
    int minimumPushes(string word) {
        //If no letters repeats this is the logic 
        
        // int ans=0;
        // for(int i=0;i<word.size();i++)
        // {
        //     if(i<8)
        //         ans+=1;
        //     else if(i<16)
        //         ans+=2;
        //     else if(i<24)
        //         ans+=3;
        //     else
        //         ans+=4;
        // }
        // return ans;
        int ans=0;
        vector<int> freq(26,0);
        for(char c:word)
            freq[c-'a']++;
        //if a-a=0 +1
        //a +2
        //it counts the frequency
        sort(freq.begin(), freq.end(), greater<int>());
        for(int i=0;i<26;i++){
            if(freq[i]==0)
                break;
            if(i<8)
                ans+=freq[i];
            else if(i<16)
                ans+=freq[i]*2;
            else if (i<24)
                ans+=freq[i]*3;
            else
                ans+=freq[i]*4;
            
        } 
        return ans;

            
        
    }
};