#include<bits/stdc++.h>

using namespace std;

int N, M, Q;
int L,U, c0, c1, r0, r1, temp1, temp2, vr;
int grid[500][500];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    while(cin>>N>>M, N){
        for (int i=0; i<N; ++i){
            for (int j=0; j<M; ++j){
                cin>>grid[i][j];
            }
        }
        cin>>Q;
        while(Q--){
            cin>>L>>U;
            c0=0; c1=M-1; vr=0;
            for (int r=0; r<N; ++r){
                temp1 = lower_bound(grid[r], grid[r]+M, L) - grid[r];
                for (int k=vr; k<N; ++k){
                    if (r+k >= N || temp1+k >= M  || grid[r+k][temp1+k] > U) break;
                    if (k + 1 > vr) vr = k + 1;
                }
            }
            cout<<vr<<endl;
        }

        cout<<"-"<<endl;
    }

    return 0;
}