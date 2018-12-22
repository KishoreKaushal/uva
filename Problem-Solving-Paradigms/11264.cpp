#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, n, S, arr[1001], k;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>arr[0]; S = arr[0]; k=1;
        for (int i=1; i<n; i++){
            cin>>arr[i];
            if (arr[i] <= S){
                S = S - arr[i-1] + arr[i];
            } else {
                S += arr[i];
                k++;
            }
        }
        if (n<=2) {
            cout<<n<<endl;
        } else {
            cout<<k<<endl;
        }
    }

    return 0;
}