// https://www.spoj.com/problems/CPCRC1C/

#include<bits/stdc++.h>

#define ll long long 
#define endl '\n'

using namespace std;

string s;

ll dp[10][2][90];

ll sumdigitsN(int i, bool last, int sum){
    if(i==s.length()){
        return sum;
    }

    if(dp[i][last][sum]!=-1) return dp[i][last][sum];

    int till = last ? s[i]-'0' : 9;
    ll ans = 0;
    for(int dig=0; dig<=till; dig++){
        ans+=sumdigitsN(i+1, last&&(dig==till), sum+dig);
    }
    return dp[i][last][sum] = ans;
}

ll solve(ll n){
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return sumdigitsN(0, true, 0);
}

int main(){    
    ll a, b;

    while(1){
        cin >> a >> b;
        if(a==-1 && b==-1) break;
        cout << solve(b)-solve(a-1) << endl;
    }
    return 0;
}