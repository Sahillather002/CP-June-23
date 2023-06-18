#include<bits/stdc++.h>
using namespace std;
int st[4*100111];
//build for max value using segment tree
void build(int id,int l,int r,int a[]){
    if(l==r){
        st[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*id+1,l,mid,a);
    build(2*id+2,mid+1,r,a);
    st[id]=max(st[2*id+1],st[2*id+2]);
    // return;
}
//update query for segment tree
void update(int id,int l,int r,int pos,int val){
    if(l==r){
        st[id]=val;
        //cout<<st[pos];
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)update(2*id+1,l,mid,pos,val);
    else update(2*id+2,mid+1,r,pos,val);
    st[id]=max(st[2*id+1],st[2*id+2]);
    // return;
}

//finding max value in range query
int maxInRange(int l,int r,int qs,int qe,int id){
    if(qs>qe)return INT_MIN;
    if(l==qs && r==qe)return st[id];
    int mid=(l+r)/2;
    int x=maxInRange(l,mid,qs,min(mid,qe),2*id+1);
    int y=maxInRange(mid+1,r,max(mid+1,qs),qe,2*id+2);
    return max(x,y);
}
int main(){
    int a[]={4,1,2,7,6,9};
    int n=sizeof(a)/sizeof(a[0]);
    // cout<<n;
    build(0,0,n-1,a);
    for(int i=0;i<n;i++)cout<<st[i]<<" ";
    cout<<endl;
    
    update(0,0,n-1,2,2);
    for(int i=0;i<n;i++)cout<<st[i]<<" ";
    cout<<endl;
    
    cout<< maxInRange(0,n-1,0,3,0);
    
    return 0;
}
