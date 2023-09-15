#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int MOD = 1e9+7;

string a, b;

//zero false dont insert zero else insert (true case)

int maxprod(int idx, bool ta, bool tb, int rp, bool zero_insert){
    if(rp==0) return 0;
    if(idx==b.length()){
        return rp;
    }
    int low = ta ? a[idx]-'0': 0;
    int high = tb ? b[idx]-'0': 9;
    int ans=1;

    for(int d=low; d<=high; d++){
        int res = maxprod(idx+1, ta&&(d==low), tb&&(d==high), (d!=0 || zero_insert) ? rp*d : rp, zero_insert || d!=0);
        ans = max(ans, res);
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    a = "51";
    b = "62";

    cout << maxprod(0, true, true, 1, false);
    
    
    return 0;
}