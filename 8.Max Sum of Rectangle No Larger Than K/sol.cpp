class Solution {
public:
    int maxSub(vector<int>& arr,int k){
        set<int> s;
        s.insert(0);
        int prefsum=0,ans=-1e9;
        for(auto i:arr){
            prefsum+=i;
            auto itr=s.lower_bound(prefsum-k);
            if(itr!=s.end()){
                ans=max(ans,prefsum-*itr);
            }
            s.insert(prefsum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=-1e9;
        for(int j1=0;j1<m;j1++){
            vector<int> mergedsum(n,0);
            for(int j2=j1;j2<m;j2++){
                for(int k=0;k<n;k++)mergedsum[k]+=matrix[k][j2];
                ans=max(ans,maxSub(mergedsum,k));
            }
        }
        return ans;
    }
};
