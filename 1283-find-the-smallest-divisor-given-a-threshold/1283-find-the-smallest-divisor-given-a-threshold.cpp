
class Solution {
public:
    long long getSum(vector<int>& nums, int div) {
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + div - 1) / div;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (getSum(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
