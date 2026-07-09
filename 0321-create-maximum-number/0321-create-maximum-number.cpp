class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;

        for (int x : nums) {
            while (!st.empty() && remove > 0 && st.back() < x) {
                st.pop_back();
                remove--;
            }
            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> ans;

        while (!a.empty() || !b.empty()) {
            if (a > b) {
                ans.push_back(a[0]);
                a.erase(a.begin());
            } else {
                ans.push_back(b[0]);
                b.erase(b.begin());
            }
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = max(0, k - m); i <= min(k, n); i++) {

            vector<int> a = maxSubsequence(nums1, i);
            vector<int> b = maxSubsequence(nums2, k - i);

            vector<int> cur = merge(a, b);

            if (cur > ans)
                ans = cur;
        }

        return ans;
    }
};