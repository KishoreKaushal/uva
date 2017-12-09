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
    vector<long long int> v;
    long long int n, a, b;
    cin>>n;
    while(!cin.eof()) {
        v.push_back(n);
        if(v.size()%2){
            nth_element(v.begin() , v.begin()+v.size()/2 , v.end());
            cout<<v[v.size()/2]<<endl;
        } else {
            nth_element(v.begin() , v.begin()+v.size()/2 , v.end());
            a = v[v.size()/2];
            nth_element(v.begin() , v.begin()+v.size()/2-1 , v.end());
            b = v[v.size()/2 - 1];
            cout<< (a/2)+(b/2) + ((a%2)&(b%2)) <<endl;
        }
        cin>>n;
    }
    return 0;
}
