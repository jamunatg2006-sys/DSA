class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int num = low + (high - low) / 2;

            if (guess(num) == 0) {
                return num;
            }
            else if (guess(num) == -1) {
                high = num - 1;
            }
            else {
                low = num + 1;
            }
        }

        return -1;
    }
};