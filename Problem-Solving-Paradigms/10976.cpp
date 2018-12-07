#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int luint;
typedef pair<int,int> ii;

void print(const vector<ii> &v,const int &k){
    for(auto itr = v.rbegin() ; itr!=v.rend(); ++itr) {
        cout<<"1/"<<k<<" = "<<"1/"<<(*itr).first<<" + "<<"1/"<<(*itr).second<<endl;
    }
}

int main() {
    luint k ;
    while(cin>>k) {
        vector<ii> v;
        for(luint y=2*k; y >= k+1 ; --y) {
            if((k*y)%(y-k) == 0) {
                v.push_back(ii((k*y)/(y-k) , y));
            }
        }
        cout<<v.size()<<endl;
        print(v, k);
    }
    return 0;
}
