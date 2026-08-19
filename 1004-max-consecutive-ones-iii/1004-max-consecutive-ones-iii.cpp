class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int e = 0;
        int len = 0;
        int maxlen = 0;
        int temp = k;

        while (e < n) {

            if (nums[e] == 1) {
                len++;
                maxlen = max(maxlen, len);
                e++;
            }
            else {
                if (temp > 0) {
                    len++;
                    maxlen = max(maxlen, len);
                    temp--;
                    e++;
                }
                else {
                    // Move left until one zero is removed
                    while (l <= e && nums[l] == 1) {
                        l++;
                        len--;
                    }

                    // Remove the zero that was using one of our k changes
                    if (l <= e && nums[l] == 0) {
                        l++;
                        temp++;
                        len--;
                    }

                    // Now current zero can be included
                    len++;
                    temp--;
                    e++;

                    maxlen = max(maxlen, len);
                }
            }
        }

        return maxlen;
    }
};