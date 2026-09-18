
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        const int INF = 1e9;

        vector<int> dp(n + 1, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {

                int len = right - left + 1;

                // Combine with a previous non-overlapping subarray
                if (dp[left] != INF) {
                    ans = min(ans, len + dp[left]);
                }

                // Update minimum length of a valid subarray
                dp[right + 1] = len;
            }

            // Carry forward the best previous answer
            dp[right + 1] = min(dp[right + 1], dp[right]);
        }

        return ans == INF ? -1 : ans;
    }
};