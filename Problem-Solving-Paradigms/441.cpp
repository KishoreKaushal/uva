#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int k;
    int S[13];
    cin>>k;
    while(k){
        for (int i=0; i<k; ++i){
            cin>>S[i];
        }

        for (int a=0; a<k-5; ++a){
            for (int b=a+1; b<k-4; ++b){
                for (int c=b+1; c<k-3; ++c){
                    for (int d=c+1; d<k-2; ++d){
                        for (int e=d+1; e<k-1; ++e){
                            for (int f=e+1; f<k; ++f){
                                cout<<S[a]<<" "<<S[b]<<" "<<S[c]<<" "<<S[d]<<" "<<S[e]<<" "<<S[f]<<endl;
                            }
                        }
                    }
                }
            }
        }

        cin>>k;
        if(k) cout<<endl;
    }

    return 0;
}