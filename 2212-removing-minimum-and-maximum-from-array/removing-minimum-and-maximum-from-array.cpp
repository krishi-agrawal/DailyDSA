class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        int minInd = -1, maxInd = -1;

        for(int i=0; i<n; i++) {
            if(nums[i] < mini) {
                mini = nums[i];
                minInd = i;
            }
            if(nums[i] > maxi) {
                maxi = nums[i];
                maxInd = i;
            }
        }

        bool maxCloseTOzeo = false, minCloseTOzeo = false;
        if(maxInd + 1 < n - maxInd) {
            maxCloseTOzeo = true;
        }
        if(minInd + 1 < n - minInd) {
            minCloseTOzeo = true;
        }
        if(maxCloseTOzeo == minCloseTOzeo) {
            if(minCloseTOzeo == true) return 1 + max(minInd, maxInd);
            else return max(n - minInd, n- maxInd);
        } else {
            int minii = min(minInd+1, n - minInd) + min(maxInd+1, n - maxInd);
            minii = min(minii, 1 + max(minInd, maxInd));
            minii = min(minii, max(n-minInd, n-maxInd));
            return minii;
        }
        return 0;
    }
};