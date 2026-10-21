
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        vector<int> ans;

        while (!freq.empty()) {
            int num = 0, count = INT_MAX;

            for (auto p : freq) {
                if (p.second < count ||
                    (p.second == count && p.first > num)) {
                    num = p.first;
                    count = p.second;
                }
            }

            for (int i = 0; i < count; i++) {
                ans.push_back(num);
            }

            freq.erase(num);
        }

        return ans;
    }
};
