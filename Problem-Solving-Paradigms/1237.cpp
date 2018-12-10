#include<bits/stdc++.h>
#define MAXD 10001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T, D, Q, P, count, idx;
    
    int L[MAXD];
    int H[MAXD];
    char M[MAXD][21];

    cin>>T;
    while(T--){
        cin>>D;
        for (int i=0; i<D; ++i) {
            cin>>M[i]>>L[i]>>H[i];
        }

        cin>>Q;
        
        while(Q--){
            cin>>P;
            count = 0;
            for (int i=0; i<D; ++i){
                if (L[i] <= P && P <= H[i]){
                    idx = i;
                    if(++count > 1) break;
                }
            }
            if (count == 1){
                cout<<M[idx]<<endl;
            } else {
                cout<<"UNDETERMINED"<<endl;
            }
        }
        if(T) cout<<endl;
    }
    return 0;
}