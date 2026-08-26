class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0;
        int r = 0;
        int cnt = 0;

        int ans = 0;
        int mini = INT_MAX;

        while (r < s.size()) {

            if (s[r] == '1')
                cnt++;

            while (cnt > k) {
                if (s[l] == '1')
                    cnt--;
                l++;
            }

            while (cnt == k && s[l] == '0') {
                l++;
            }

            if (cnt == k) {

                int len = r - l + 1;

                if (len < mini) {
                    mini = len;
                    ans = l;
                }
                else if (len == mini) {

                    for (int i = 0; i < len; i++) {

                        if (s[l + i] < s[ans + i]) {
                            ans = l;
                            break;
                        }

                        if (s[l + i] > s[ans + i]) {
                            break;
                        }
                    }
                }
            }

            r++;
        }

        if (mini == INT_MAX)
            return "";

        string result = "";

        for (int i = ans; i < ans + mini; i++) {
            result += s[i];
        }

        return result;
    }
};