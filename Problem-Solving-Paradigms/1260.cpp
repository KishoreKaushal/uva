#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T, N;
    int A[1001];
    int B[1001];
    long long int sum;

    cin>>T;
    while(T--){
        sum = 0;
        cin>>N;
        cin>>A[0];
        for (int i=1; i<N; ++i){
            cin>>A[i];
            for (int k=0; k<i; k++){
                if(A[k] <= A[i]){
                    ++sum;
                }
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}