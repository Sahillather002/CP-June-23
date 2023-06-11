#include <bits/stdc++.h>
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    int n=nums.size();
    vector<int> pref(n+1,0);
    unordered_map<int,pair<int,int>> mp;
    mp[0]={1,0};
    int ans=0;
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+nums[i-1];
        int idx=pref[i]-k;
        if(mp.find(idx)!=mp.end()){
            ans=max(ans,i-mp[idx].second);
        }
        
        if(mp[pref[i]].first>=1){
            mp[pref[i]].second=min(i,mp[pref[i]].second);
        }else mp[pref[i]].second=i;
        mp[pref[i]].first++;
        // cout<<pref[i]<<" "<<mp[pref[i]].second;
        // cout<<endl;
    }
    return ans;
}
