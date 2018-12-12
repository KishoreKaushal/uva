#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

inline lli count_setbits(lli N) {
    lli cnt = 0;
    while (N > 0) {
        cnt += (N & 1);
        N = N >> 1;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    lli N, num_tracks, best_comb, best_sum;
    
    lli tape[10000];
    
    while(cin>>N){
        cin>>num_tracks;
        
        for (lli i=0; i<num_tracks; ++i){
            cin>>tape[i];
        }

        best_comb = 0;
        lli sum = 0 ;
        lli idx = 0;
        best_sum = 0;
        for (lli comb = 1; comb < (1<<num_tracks); ++comb){
            sum = 0;
            idx = 0;
            while (idx < num_tracks){
                if (comb & (1<<idx)){
                    sum += tape[idx];
                    if(sum > N) break;
                }
                ++idx;
            }
            if (sum > best_sum && sum <= N){
                best_comb = comb;
                best_sum = sum;
            } 
            /*not needed but doing this is also fine, both solution is acceptable*/
            // else if (sum == best_sum && (count_setbits(best_comb) < count_setbits(comb))){
            //         best_comb = comb;
            //         best_sum = sum;
            // }
        }

        idx = 0;
        while (idx < num_tracks){
            if (best_comb & (1<<idx)){
                cout<<tape[idx]<<" ";
            }
            ++idx;
        }
        cout<<"sum:"<<best_sum<<endl;
    }


    return 0;
}