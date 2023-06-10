#define mod 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>pref(n+1,0);
        int odd=0,even=1;
        int count=0;
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+arr[i-1];
            if(pref[i]%2==0){
                even++;
                count=count%mod+odd%mod;
            }
            else{
                odd++;
                count=count%mod+even%mod;
            }
        }
        return count%mod;
    }
};
