class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n, -1);
        for(int i=0; i<n; i++){
            if(v[nums[i]] == nums[i]){
                return nums[i];
            }
            else{
                v[nums[i]] = nums[i];
            }
        }
        return 0;
    }
};