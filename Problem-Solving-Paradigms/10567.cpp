#include<bits/stdc++.h>

using namespace std;

char S[1000001], SS[101];
int Q, lenS, lenSS, I, J, idx;

bool findSS(){
    int i = 0, j = -1;
    idx = 0;
    while(S[i]!=SS[idx] && i<lenS) ++i;
    if(i<lenS) {
        I = i;
        idx++;
        i++;
        while(idx<lenSS && i<lenS){
            if(S[i]==SS[idx]){
                ++idx;
            }
            ++i;
        }
        if (idx >= lenSS) {J = (i-1); return true;}
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>S; lenS = strlen(S);
    cin>>Q;
    while(Q--){
        cin>>SS;
        lenSS = strlen(SS);
        if(findSS()){
            cout<<"Matched "<<I<<" "<<J<<endl;
        } else {
            cout<<"Not matched"<<endl;
        }
    }

    return 0;
}