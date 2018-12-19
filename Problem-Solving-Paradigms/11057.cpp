#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lli cost[10001], N,M;
    while(cin>>N){
        for (lli i=0; i<N; ++i){
            cin>>cost[i];
        }
        cin>>M;
        sort(cost, cost + N);

        lli lo=0, hi=N-1, a, b;
        while(lo<=hi){
            while(cost[lo]+cost[hi]<M && lo <= hi) ++lo;
            while(cost[lo]+cost[hi]>M && lo <= hi) --hi;
            if (cost[lo] + cost[hi] == M){
                if (lo < hi) {
                    a = cost[lo]; b = cost[hi];
                }
                ++lo; --hi;
            }
        }
        
        cout<<"Peter should buy books whose prices are "<<a<<" and "<<b<<"."<<endl;
        cout<<endl;
    }

    return 0;
}