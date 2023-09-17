#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

string s;

int dp(int i, int j){
    if(i==j) return 1;
    if(i>j) return 0;

    int ans;
    
    if(s[i]==s[j]) ans=dp(i+1, j-1)+2;
    else ans = max(dp(i+1, j), dp(i, j-1));
    
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s;
    cout << dp(0, s.size()-1) << endl;
    
    return 0;
}