// https://www.spoj.com/problems/EDIST/
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

string a, b;

int memo[2000][2000];

int dp(int i, int j){
    if(i==a.size() && j==b.size()) return 0;
    if(i==a.size()) return b.size()-j;
    if(j==b.size()) return a.size()-i;
    if(memo[i][j]!=-1) return memo[i][j];
    int ans;
    if(a[i]==b[j]){
        ans = dp(i+1, j+1);
    }
    else{
        ans = min({dp(i+1, j), dp(i, j+1), dp(i+1, j+1)})+1;
    }
    return memo[i][j]= ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(memo, -1, sizeof(memo));
        cout << dp(0, 0) << endl;
    }
    
    return 0;
}