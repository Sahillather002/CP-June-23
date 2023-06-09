//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    #define ll long
    long maximumSumSubarray(int k, vector<int> &Arr , int n){
        // code here 
        vector<ll> pref(n+1,0);
        unordered_map<int,int> mp;
        ll ans=-1e9;
        ll sum=0;
        ll minpref=0;
        for(int i=1;i<=n;i++){
            sum+=Arr[i-1];
            pref[i]=sum;
            if(i>=k)
            ans=max(ans,(pref[i]-pref[i-k]));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
