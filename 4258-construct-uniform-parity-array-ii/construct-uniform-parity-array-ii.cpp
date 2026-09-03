class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int i=0;
        int smallestOdd = INT_MAX, smallestEven = -1;

        for(; i<n; i++) {
            if(nums[i] % 2) {
                if(nums[i] < smallestOdd) {
                    smallestOdd = nums[i];
                } 
            } else if(smallestOdd != INT_MAX && nums[i] > smallestOdd) {
                continue;
            } else break;
        }
        if(i == n) return true;

        int j=0;
        for(; j<n; j++) {
            if(nums[j] % 2 ) return false;
        }
        return true;
        
    }
};