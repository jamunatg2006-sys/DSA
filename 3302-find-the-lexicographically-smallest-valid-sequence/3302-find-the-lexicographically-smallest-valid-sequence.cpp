class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);
        vector<int> last(m, -1);

        // last[j] = last occurrence of word2[j]
        // that can be used while matching from right to left.
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // Greedily construct lexicographically smallest answer.
        bool canSkip = true;
        j = 0;

        for (i = 0; i < n; i++) {
            if (j == m)
                break;

            // Normal matching
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }
            // Use the one allowed mismatch
            else if (canSkip &&
                     (j == m - 1 || i < last[j + 1])) {
                ans[j] = i;
                j++;
                canSkip = false;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};