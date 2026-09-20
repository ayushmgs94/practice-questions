class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long positiveDividend = llabs((long long)dividend);
        long long positiveDivisor = llabs((long long)divisor);
        long long quotient = 0;

        for (int bit = 31; bit >= 0; bit--) {
            if ((positiveDivisor << bit) <= positiveDividend) {
                positiveDividend -= positiveDivisor << bit;
                quotient += 1LL << bit;
            }
        }

        if ((dividend < 0) != (divisor < 0)) quotient = -quotient;
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;
        return (int)quotient;
    }
};