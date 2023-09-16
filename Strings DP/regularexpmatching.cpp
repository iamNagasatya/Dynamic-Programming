#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

string s, p;

bool dp(int i, int j){
    if(i==s.size()&&j==p.size()) return true;
    if(j==p.size()) return false;

    bool ans = false;
    
    if(j+1<p.size() && p[j+1]=='*'){
        if(i<s.size() && (p[j]==s[i]||p[j]=='.')) ans |= dp(i+1, j);
        ans |= dp(i, j+2);
    }
    else if(i<s.size() &&  (p[j]==s[i] || p[j]=='.')){
        ans |= dp(i+1, j+1);
    }
    
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s >> p;
    cout << dp(0, 0) << endl;
    return 0;
}