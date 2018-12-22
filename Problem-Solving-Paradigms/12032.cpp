#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, max_diff, inp, prev, diff[100001], k;
    cin>>T;
    for (int c=1; c<=T; c++){
        cin>>N;
        max_diff=0;  prev=0;
        
        for (int i=0; i<N; ++i){
            cin>>inp;
            diff[i] = inp - prev;
            if (diff[i] > max_diff) max_diff = diff[i]; 
            prev = inp;
        }

        k = max_diff;
        for (int i=0; i<N; ++i){
            if (k==diff[i]) --k;
            else if (k < diff[i]){
                ++max_diff;
                break;
            }
        }
        cout<<"Case "<<c<<": "<<max_diff<<endl;
    }

    return 0;
}