class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n+1,0);
        int ans=-1e9;
        int prefmini=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=nums[i-1];
            pref[i]=pref[i-1]+nums[i-1];
            // no need for pref calculation
            ans=max(ans,pref[i]-prefmini);
            // use max(ans,sum-prefmini)
            prefmini=min(prefmini,sum);
        }
        return ans;
    }
};
