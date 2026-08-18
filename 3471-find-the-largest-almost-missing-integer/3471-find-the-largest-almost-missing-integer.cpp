class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, vector<int>> pos;

        // Store positions of every number
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = -1;

        for (auto &[x, v] : pos) {
            int count = 0;

            int L = -1, R = -1;

            for (int i : v) {
                int l = max(0, i - k + 1);
                int r = min(i, n - k);

                if (L == -1) {
                    L = l;
                    R = r;
                }
                else if (l <= R + 1) {
                    // Intervals overlap
                    R = max(R, r);
                }
                else {
                    // Separate interval
                    count += R - L + 1;
                    L = l;
                    R = r;
                }
            }

            if (L != -1) {
                count += R - L + 1;
            }

            if (count == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};