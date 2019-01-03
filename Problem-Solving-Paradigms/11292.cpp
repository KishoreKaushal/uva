#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    int dia[20000], ht[20000];
    while(cin>>n>>m, n|m){
        for (int i=0; i<n; i++) cin>>dia[i];
        for (int i=0; i<m; i++) cin>>ht[i];

        sort(dia, dia+n); sort(ht, ht+m);
        
        int cost = 0, d=0, k=0;
        while(d<n && k<m){
            if (ht[k] >= dia[d]) { ++d; cost += ht[k]; }
            ++k;
        }

        if (d == n){
            cout<<cost<<endl;
        } else cout<<"Loowater is doomed!"<<endl;

    }

    return 0;
}