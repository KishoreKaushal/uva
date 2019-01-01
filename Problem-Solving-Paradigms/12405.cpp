#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, k;
    char arr[110];
    cin>>t;
    for (int c=1; c<=t; ++c){
        cin>>n;
        cin>>arr;
        k = 0;
        for (int i=0; i<n;){
            if (arr[i]=='#') i++;
            else {
                ++k;
                i+=3;
            }
        }
        cout<<"Case "<<c<<": "<<k<<endl;
    }

    return 0;
}