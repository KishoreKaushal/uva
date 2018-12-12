#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    lli idx[] = {0,1,2,3,4,5,6,7};
    lli M[8][8];
    lli t,n;
    lli min, sum;
    cin>>t;
    
    while(t--){
        cin>>n;
        vector<lli> col_idx(idx , idx+n);
        
        for (lli i=0; i<n; ++i){
            for (lli j=0; j<n; ++j){
                cin>>M[i][j];
            }
        }

        min = INT64_MAX;

        do {
            sum = 0;
            for (lli i=0; i<n; ++i){
                sum += M[i][col_idx[i]];
            }
            if (sum < min){
                min = sum;
            }
        } while(next_permutation(col_idx.begin(), col_idx.end()));

        cout<<min<<endl;
    }

    return 0;
}