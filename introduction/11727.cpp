#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,i =0;
    vector <int> v(3);
    cin>>t;
    while(i++<t){
        cin>>v[0]>>v[1]>>v[2];
        sort(v.begin() ,v.end());
        cout<<"Case "<<i<<": "<<v[1]<<endl;
    }
    return 0;
}
