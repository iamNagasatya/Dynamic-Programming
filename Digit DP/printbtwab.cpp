#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

const int MOD = 1e9+7;

string a, b;

//zero false dont insert zero else insert (true case)

void printN(int idx, bool ta, bool tb, string s, bool zero_insert){
    if(idx==b.length()){
        cout << s << endl;
        return ;
    }
    int low = ta ? a[idx]-'0': 0;
    int high = tb ? b[idx]-'0': 9;
    for(int d=low; d<=high; d++){
        printN(idx+1, ta&&(d==low), tb&&(d==high), (d!=0 || zero_insert) ? s+to_string(d) : s, zero_insert || d!=0);
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    a = "012";
    b = "015";

    printN(0, true, true, "", false);
    
    
    return 0;
}