#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

string s, p;

bool isMatch(int i, int j){
    if(i==s.size() && j==p.size()) return true;
    if(j==p.size()) return false;
    if(i==s.size()){
        if(j==p.size()-1 && p[j]=='*') return true;
        return false;
    }

    bool ans;

    if(p[j]=='?'){
        ans = isMatch(i+1, j+1);
    }
    else if(p[j]=='*'){
        ans = isMatch(i+1, j) || isMatch(i, j+1);
    }
    else{
        if(p[j]==s[i]){
            ans = isMatch(i+1, j+1);
        }
        else{
            ans = false;
        }
    }
    return ans;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s >> p;

    cout << isMatch(0, 0) << endl;
    
    return 0;
}