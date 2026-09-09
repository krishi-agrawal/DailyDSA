class Solution {
public:
    long long countCommas(long long n) {
        return (n == 1e15) + ((n > 999999999999) ? n - 999999999999: 0) + ((n > 999999999) ? n - 999999999: 0) + ((n > 999999) ? n - 999999: 0) + ((n > 999) ? n - 999: 0);
    }
};