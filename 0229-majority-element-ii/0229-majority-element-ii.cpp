class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mp;
        vector<int> ans;

        // Count frequency
        for (int x : nums) {
            mp[x]++;
        }

        // Check frequency
        for (auto p : mp) {
            if (p.second > nums.size() / 3) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};