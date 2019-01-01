#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lli n,d,r,load, tmp;
    lli morn[100] , aft[100];

    while(cin>>n>>d>>r , n|d|r){
        for (lli i=0; i<n; ++i) cin>>morn[i];
        for (lli i=0; i<n; ++i) cin>>aft[i];
        sort(morn , morn+n);
        sort(aft , aft+n, greater<int>());

        load = 0;
        for (lli i=0; i<n; ++i){
            tmp = (morn[i]+aft[i]-d)*r;
            load += (tmp > 0) * tmp;
        }
        cout<<load<<endl;
    }

    return 0;
}