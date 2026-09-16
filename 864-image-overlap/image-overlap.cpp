class Solution {
public:
    int countOverlap(const vector<vector<int>>& img1, const vector<vector<int>>& img2, int dr, int dc, int n) {
        int count = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int shifted_r = r + dr;
                int shifted_c = c + dc;
                
                if (shifted_r >= 0 && shifted_r < n && shifted_c >= 0 && shifted_c < n) {
                    if (img1[r][c] == 1 && img2[shifted_r][shifted_c] == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = 0;

        // Try every possible shift (dr, dc)
        for (int dr = -(n - 1); dr < n; ++dr) {
            for (int dc = -(n - 1); dc < n; ++dc) {
                maxOverlap = max(maxOverlap, countOverlap(img1, img2, dr, dc, n));
            }
        }

        return maxOverlap;
    }
};