class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;

        for (int i = 1; i < num; i++) {
            if (num % i == 0) {   // i is a divisor
                sum += i;
            }
        }

        return sum == num;
    }
};