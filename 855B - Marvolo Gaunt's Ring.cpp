#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll n,p,q,r;
    cin>>n>>p>>q>>r;
    vector<ll>v;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    vector<ll>pref(n),suff(n);
    pref[0]=p*v[0];
    suff[n-1]=r*v[n-1];
    for(ll i=1;i<n;i++){
        pref[i]=max(pref[i-1],p*v[i]);
        // cout<<pref[i]<<" ";
    }
    for(ll i=n-2;i>=0;i--){
        suff[i]=max(suff[i+1],r*v[i]);
        // cout<<suff[i]<<" ";
    }
    ll ans=-1e20;
    // now fixing the middle element
    for(ll j=0;j<n;j++){
        ll x=pref[j]+q*v[j]+suff[j];
        ans=max(ans,x);
    }
    cout<<ans;
    return 0;
}
