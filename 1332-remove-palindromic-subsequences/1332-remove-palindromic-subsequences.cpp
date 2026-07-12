class Solution {
public:
    int removePalindromeSub(string s) {
        // to retrun the number of steps to remove to make string EMPTY
    if(s.empty())
    {
        return 0;
        // no steps are required to remove the elements
    }
    int i=0;//left =0;
    int j=s.size()-1;//right =length -1

    while(i<j){
        if(s[i] != s[j])
        {
            return 2;
            // if not pallindrome found minimun 2 stepps are reuired 
        }
        i++;//left ++ // FORWARDING CHECK
        j--;// right-- BACKWARDING CHECk
    }  
    return 1;
    // this is the minimum step    

        
    }
};