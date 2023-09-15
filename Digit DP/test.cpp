// https://codeforces.com/gym/100886/problem/G

#include<bits/stdc++.h>

#define ll long long 
#define endl '\n'

using namespace std;

const int md = 1e9+7;
string s;
ll memo[10][2][2];


ll f(int i, bool last, bool prev_one){
    if(i==s.length()){
        return 1;
    }
    if(memo[i][last][prev_one]!=-1) return memo[i][last][prev_one];

    int till = last ? s[i]-'0' : 9;
    ll ans = 0;
    for(int dig=0; dig<=till; dig++){
        if(dig!=3 || prev_one==false)
        ans+=f(i+1, last&&(dig==till), dig==1);
        ans%=md;
    }
    return memo[i][last][prev_one]=ans;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);  
    int t;
    ll n;
    cin >> t;
    while(t--){
        memset(memo, -1, sizeof(memo));
        cin >> n;
        s = "";
        s.insert(0, n, '9');
        cout << f(0, true, false) << endl;
    }
    return 0;
}