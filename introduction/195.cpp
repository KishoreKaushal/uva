#include<bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = int(a); i<=int(b); i++)

bool compareForPermutation(char a , char b){
    if(a==b) return false;
    char A=tolower(a) , B=tolower(b);
    if(A==B){
        if(isupper(a)) return true;
        else if(isupper(b)) return false;
        else return false;
    } else if(A<B) return true;
    else return false;
}

int main(int argc, char const *argv[]) {
    int t;  string s;
    (cin>>t).get();
    while(t--) {
        cin>>s;
        sort(s.begin() , s.end() , compareForPermutation);
        do{
            cout<<s<<endl;
        }while(next_permutation(s.begin(), s.end() , compareForPermutation));
    }
    return 0;
}
