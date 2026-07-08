// // class Solution {
// // public:
// //     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
// //         int sum=0;
// //         int x=0;
// //         for(char c:s){
// //             if(c != '0'){
// //                 int digit =c-'0';
// //                 x=x*10+digit;
// //                 sum+=digit ;
// //             }
// //         }
// //          int ans =sum *x;
// //     }
// // };
// class Solution{
//     public:
//         vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
//             vector<long long > ans;

//             for(auto q:queries){
//                 int l=q[0];
//                 int r=q[1];
//                 long long x=0;
//                 long long  sum =0;

//                 for(int i=l;i<=r;i++){
//                     if(s[i] !='0'){
//                         int digit = s[i]- '0';
//                          x=x*10+digit;
//                         sum+=digit;

//                     }
                   
//                 }
//                   ans.push_back(sum * x);
//             }
//             return ans;
//         }

    
// };
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const long long MOD = 1000000007;

        vector<int> pos;
        vector<int> digit;

        // Store non-zero digits and their indices
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int n = digit.size();

        // Prefix sum of digits
        vector<long long> prefSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + digit[i];

        // Powers of 10
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix number
        vector<long long> prefNum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int left = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int right = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (left > right) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[right + 1] - prefSum[left];

            int len = right - left + 1;

            long long x =
                (prefNum[right + 1] -
                 (prefNum[left] * pow10[len]) % MOD +
                 MOD) % MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};

