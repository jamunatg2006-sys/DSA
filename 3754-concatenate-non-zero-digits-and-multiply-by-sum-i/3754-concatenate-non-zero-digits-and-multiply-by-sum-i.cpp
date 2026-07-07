// class Solution {
// public:
//     long long sumAndMultiply(int n) {
//         int count=0;
//         int sum=0;
//         for(int i=0;i<n.size();i++){
//             if(n[i]!=0)
//             {
//                 count++;
//                 int x=n[i];
//             }
//             sum+=x;
//         }
//         return x*sum;
//     }
// };
class Solution{
    public:
        long long sumAndMultiply(int n){
            long long x=0;
            long long sum=0;

            string s=to_string(n);
            for(char c :s ){
                if (c!='0'){
                    int digit  = c-'0';
                    x=x *10 +digit;
                    sum+=digit;

                }
            }
            return x*sum;
        }

};