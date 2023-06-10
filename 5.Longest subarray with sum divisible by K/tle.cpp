//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    vector<int> pref(n+1,0);
	    unordered_map<int,int> mp;
	    int ans=0;
	    for(int i=1;i<=n;i++){
	        pref[i]=pref[i-1]+arr[i-1];
	        for(int j=0;j<=i;j++){
	            int d=pref[i]-pref[j];
	            if(d%k==0){
	                ans=max(ans,i-j);
	                break;
	            }
	        }
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
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends
