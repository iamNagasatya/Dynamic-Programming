// https://lightoj.com/problem/investigation

#include<bits/stdc++.h>
#define int long long int
using namespace std;

string n;
int k;

int memo[10][2][90][90];                     

int solve(int index, bool last, int n_mod, int sum_dig_mod){
    if(index==n.size()){
        if(n_mod==0 && sum_dig_mod==0) return 1;
        else return 0;
    }
    if(memo[index][last][n_mod][sum_dig_mod]!=-1) return memo[index][last][n_mod][sum_dig_mod];
    int till = last ? n[index]-'0' : 9;
    int ans=0;
    for(int digit=0; digit<=till; digit++){
        ans+=solve(index+1, last&&digit==till, (n_mod*10+digit)%k, 
                 (sum_dig_mod+digit)%k);
    }
    return memo[index][last][n_mod][sum_dig_mod]=ans;
}

int f(int _n){
    if(k>90) return 0;
    memset(memo, -1, sizeof(memo));
    n = to_string(_n);
    
    return solve(0, true, 0, 0);
}

int32_t main(){
    int t;
    int a, b;
    cin >> t;
    
    for(int i=1; i<=t; i++){
        cin >> a >> b >> k;
        cout << "Case " << i << ": " << f(b)-f(a-1) << '\n';
    }
    return 0;
}