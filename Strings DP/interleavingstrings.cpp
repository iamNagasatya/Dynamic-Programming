#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int md = 1e9+7;

string s1, s2, s3;

bool dp(int i, int j){
    int k = i+j;
    if(i==s1.size() && j==s2.size() && k==s3.size()) return true;

    bool ans = false;

    if(k<s3.size() && i<s1.size() && s3[k]==s1[i]){
        ans |= dp(i+1, j);
    }
    if(k<s3.size() && j<s2.size() && s3[k]==s2[j]){
        ans |= dp(i, j+1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s1 >> s2 >> s3;

    cout << dp(0, 0) << endl;
    
    return 0;
}