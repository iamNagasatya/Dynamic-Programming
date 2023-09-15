#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int MOD = 1e9+7;

string num;

void printN(int idx, bool last, string s){
    if(idx==num.length()){
        cout << s << endl;
        return ;
    }
    int till = last ? num[idx]-'0': 9;
    for(int d=0; d<=till; d++){
        printN(idx+1, last&&(d==till), s+to_string(d));
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> num;

    printN(0, true, "");
    
    return 0;
}