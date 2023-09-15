// https://www.spoj.com/problems/NUMTSN/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int MOD = 1e9+7;

string num;
ll memo[55][2][19][19][19];

ll digitdp(int idx, bool last, int cnt3, int cnt6, int cnt9){
    if(idx==num.size()){
        if(cnt3>=1 && (cnt3==cnt6 && cnt6==cnt9)) return 1;
        return 0;
    }
    if(cnt3>17 || cnt6>17 || cnt9>17) return 0;

    if(memo[idx][last][cnt3][cnt6][cnt9]!=-1) return memo[idx][last][cnt3][cnt6][cnt9];
    ll res=0;
    int till = last? num[idx]-'0': 9;
    for(int digit=0; digit<=till; digit++){
        switch (digit)
        {
        case 3:
            res+=digitdp(idx+1, last&&(digit==till), cnt3+1, cnt6, cnt9);
            res%=MOD;
            break;
        case 6:
            res+=digitdp(idx+1, last&&(digit==till), cnt3, cnt6+1, cnt9);
            res%=MOD;
            break;
        case 9:
            res+=digitdp(idx+1, last&&(digit==till), cnt3, cnt6, cnt9+1);
            res%=MOD;
            break;
        
        
        default:
            res+=digitdp(idx+1, last&&(digit==till), cnt3, cnt6, cnt9);
            res%=MOD;
            break;
        }
    }
    return memo[idx][last][cnt3][cnt6][cnt9]=res;
}

ll solve(string s){
    num = s;
    memset(memo, -1, sizeof(memo));
    return digitdp(0, true, 0, 0, 0);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        
        int i = a.size()-1;
        while(i>=0 && a[i]=='0'){
            a[i--]='9';
        }
        a[i] = a[i]-1;
        cout << (solve(b)-solve(a)+MOD)%MOD << endl;
    
    }
    return 0;
}