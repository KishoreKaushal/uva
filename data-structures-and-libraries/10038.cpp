#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

int main(){
    int n, idx;
    vector <int> v;
    vector <int> w(3000,0);
    cin>>n;
    bool jolly=true;
    while(!cin.eof()){
        v.clear();
        v.resize(n+1, 0);
        cin>>w[0];
        REP(j, 1, n){
            cin>>w[j];
            idx = abs(w[j]-w[j-1]);
            //cout<<idx<<endl;
            if(idx < n) v[idx] = 1;
        }
        jolly = true;
        //for(auto i:v)   cout<<i<<" "<<endl;
        REP(j, 1, n){
            if(v[j] == 0)   {
                jolly = false;
                break;
            }
        }
        if(!jolly) cout<<"Not jolly"<<endl;
        else cout<<"Jolly"<<endl;
        cin>>n;
    }
    return 0;
}
