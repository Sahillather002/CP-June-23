//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        vector<int> pref(N+1,0);
        unordered_map<int,int> mp;
        mp[0]=1;
        int count=0;
        pref[0]=0;
        for(int i=1;i<=N;i++){
            pref[i]=pref[i-1]+Arr[i-1];
            int x=pref[i]-k;
            if(mp.find(x)!=mp.end())count+=mp[x];
            mp[pref[i]]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
