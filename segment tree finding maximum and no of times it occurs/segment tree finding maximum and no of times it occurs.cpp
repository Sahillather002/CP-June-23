//finding maximum and number of times it appears in array
#include<bits/stdc++.h>
using namespace std;

// pair of numbers at each vertex of tree
// stores max with no of times it occured in that segment
// {id,occurences}
pair<int,int> st[4*100111];

//combining pairs should return the pairs
//stores the max and combine the occurences if same element occurs
pair<int,int> combine(pair<int,int> a,pair<int,int> b){
    if(a.first>b.first)return a;
    if(b.first>a.first)return b;
    //warna dono same honge to occurence badh jaigi
    return make_pair(a.first,a.second+b.second);
}

//building segment tree
void build(int id,int tl,int tr,int a[]){
    if(tl==tr){
        st[id]=make_pair(a[tl],1);
        return;
    }
    int mid=(tl+tr)/2;
    build(2*id,tl,mid,a);
    build(2*id+1,mid+1,tr,a);
    //combine the pair of leaf and so on
    st[id]=combine(st[2*id],st[2*id+1]);
}

// our main function to compute answer
pair<int,int> solveMax(int id,int tl,int tr,int l, int r){
    if(l>r) return make_pair(-1e9,0);
    if(l==tl && r==tr) return st[id];
    int mid=(tl+tr)/2;
    return combine(solveMax(2*id,tl,mid,l,min(r,mid)),
                    solveMax(2*id+1,mid+1,tr,max(l,mid+1),r));
}
//update query
void update(int id,int tl,int tr,int pos,int val){
    if(tl==tr){
        st[id]=make_pair(val,1);
    }
    else{
        int mid=(tl+tr)/2;
        if(pos<=mid)update(2*id,tl,mid,pos,val);
        else update(2*id+1,mid+1,tr,pos,val);
        st[id]=combine(st[2*id],st[2*id+1]);
    }
}
int main(){
    int a[]={2,1,2,3,1,2,3,2,3,1,3};
    int n=sizeof(a)/sizeof(a[0]);
    build(1,1,n-1,a);
    for(int i=1;i<2*n;i++){
        cout<<st[i].first<<" : "<<st[i].second;
        cout<<endl;
    }
    pair<int,int> ans=solveMax(1,0,n-1,1,6);
    cout<<ans.first<<" "<<ans.second;
}

