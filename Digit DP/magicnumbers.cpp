// https://codeforces.com/contest/628/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int MOD = 1e9+7;

int m, d;
string n;

ll memo[2000][2][2000];

ll dp(int idx, bool last, int num_mod){
    if(idx==n.size()){
        return num_mod == 0;
    }
    if(memo[idx][last][num_mod]!=-1) return memo[idx][last][num_mod];
    
    int till = (last? n[idx]-'0' : 9);
    ll ans=0;
    if(idx%2==1){
        if(d<=till)
            ans = (ans+dp(idx+1, last&(d==till), (num_mod*10+d)%m))%MOD;
    }
    else{
        for(int digits=0; digits<=till; digits++){
            if(digits!=d){
                ans = (ans+dp(idx+1, last&&(digits==till), (num_mod*10+digits)%m))%MOD;
            }
        }
    }
    return memo[idx][last][num_mod] = ans;
}

ll solve(string s){
    n = s;
    memset(memo, -1, sizeof(memo));
    return dp(0, true, 0);
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    string a, b;
    cin >> m >> d;
    cin >> a >> b;
    
    int i = a.size()-1;
    while(i>=0 && a[i]=='0'){
        a[i--]='9';
    }
    a[i] = a[i]-1;
    cout << (solve(b)-solve(a)+MOD)%MOD;
    
    return 0;
}