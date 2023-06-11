class Solution {
public:
    int solve(vector<int>& nums,int k){
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefsum=0,ans=0;
        for(int i=0;i<n;i++){
            prefsum+=nums[i];
            ans+=mp[prefsum-k];
            mp[prefsum]++;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int j1=0;j1<m;j1++){
            vector<int>mergedsum(n,0);
            for(int j2=j1;j2<m;j2++){
                for(int k=0;k<n;k++)mergedsum[k]+=matrix[k][j2];
                ans+=solve(mergedsum,target);
            }
        }
        return ans;
    }
};
