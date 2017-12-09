#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream cin("input");
    // ofstream cout("output");
    std::string s;
    cin>>s;
    while(!cin.eof() && s!="#") {
        if(next_permutation(ALL(s))){
            cout<<s<<endl;
        }else cout<<"No Successor\n";
        cin>>s;
    }
    return 0;
}
