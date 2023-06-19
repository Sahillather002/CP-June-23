//counting number of zeroes and searching for the k-th zero
#include<bits/stdc++.h>
using namespace std;
int st[4*100111];

//building the segment tree
void build(int id,int tl,int tr,int a[]){
    if(tl==tr){
        if(a[tl]==0)st[id]=1;
        else st[id]=0;
        return;
    }
    int mid=(tl+tr)/2;
    build(2*id,tl,mid,a);
    build(2*id+1,mid+1,tr,a);
    st[id]=st[2*id]+st[2*id+1];
}


//update query of segment tree
void update(int id,int tl,int tr,int pos,int val){
    if(tl==tr){
        st[id]=val;
        return;
    }
    else{
        int mid=(tl+tr)/2;
        if(pos<=mid)update(2*id,tl,mid,pos,val);
        else update(2*id+1,mid+1,tr,pos,val);
        //st[id]=st[2*id]+st[2*id+1];
    }
}

//finding kth zero in the given array 
int findKth(int id,int tl,int tr,int k){
    if(k>st[id])return -1;
    if(tl==tr){
        return tl;
    }
    int mid=(tl+tr)/2;
    if(st[2*id]>=k)return findKth(2*id,tl,mid,k);
    else return findKth(2*id+1,mid+1,tr,k-st[2*id]);
}
int main(){
    int a[]={1,0,1,0,2,0,1,0,0,1,0};
    int n=sizeof(a)/sizeof(a[0]);
    build(1,1,n-1,a);
    for(int i=0;i<2*n;i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
    
    update(1,1,n-1,2,100);
    for(int i=0;i<2*n;i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
    
    cout<<findKth(1,1,n-1,4);
}
