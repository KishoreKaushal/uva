#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lli t, n, p, temp;
    lli bars[20];
    lli bar_idx;
    bool possible=false;

    cin>>t;
    while(t--){
        possible = false;
        bar_idx = 0;

        cin>>n>>p;
        for (lli i=0; i<p; ++i){
            cin>>temp;
            if(temp <= n){
                if (temp == n){
                    possible = true;
                    break;
                }
                bars[bar_idx++] = temp;
            }
        }

        sort(bars , bars + bar_idx);

        lli sum = 0, idx=0, temp;
        if(!possible){
            for (lli comb = 0 ; comb < (1<<bar_idx); ++comb){
                sum = 0; idx = 0;
                while((temp = (1<<idx)) <= comb){
                    if (temp & comb) sum += bars[idx];
                ++idx;
                } 
                if (sum == n){
                    possible = true;
                    break;
                }
            }
        }
        
        if(possible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    

    return 0;
}