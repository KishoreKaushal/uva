#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N, P, close, counter=0;
    int A[1001];

    cin>>N;
    while(N){
        cout<<"Case "<<++counter<<":"<<endl;

        for (int i=0; i<N; ++i){
            cin>>A[i];
        }
        
        cin>>M;
        for (int i=0; i<M; ++i){
            cin>>P;
            close = A[0]+A[1];
            for (int a=0; a<N; ++a){
                for (int b=a+1; b<N; ++b){
                    if (abs(P - A[a] - A[b]) < abs(P - close)){
                        close = A[a] + A[b];
                    }
                }
            }
            cout<<"Closest sum to "<<P<<" is "<<close<<"."<<endl;
        }

        cin>>N;
    }

    return 0;
}