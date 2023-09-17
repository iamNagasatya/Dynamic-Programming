#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

string s;

int memo[1000][1000];

bool dp(int i, int j){
    if(i>=j) return true;
    if(memo[i][j]!=-1) return memo[i][j];
    bool ans = s[i]==s[j]&&dp(i+1, j-1);
    return memo[i][j]=ans;
}

int solve(){
    int ans=0;
    for(int i=0; i<s.size(); i++){
        for(int j=i; j<s.size(); j++){
            ans += dp(i, j);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(memo, -1, sizeof(memo));
    cin >> s;
    cout << solve() << endl;

    return 0;
}