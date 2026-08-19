class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1) return s.size();
        int l=0;
        int r=1;
        vector<int> hash(256, 0);
        int length = 1;
        int maxlength = 1;
        hash[s[l]]++;
        while(r<s.size()){
            if(hash[s[r]]==0){
                hash[s[r]]++;
                length++;
                maxlength = max(maxlength,length);
                r++;
            }
            else{
                hash[s[l]]--;
                l++;
                length--;
            }
        }
        return maxlength;
    }
};