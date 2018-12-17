#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli n,m;
pair<lli, lli> lt, rt, inp;
vector<pair<lli,lli>> dom;
vector<pair<lli,lli>> seq;
bool chosen[30];


bool backtrack(lli N){
    if (N == 0){
        if (seq[n].second == rt.first){
            return true;
        }
        return false;
    } else {
        
        for (lli i=0; i<2*m; ++i){
            if (!chosen[i] && seq[n-N].second == dom[i].first){
                seq[n-N+1] = dom[i];
                chosen[i] = true;
                chosen[((i%2)?i-1:i+1)] = true;
                if (backtrack(N-1)) return true;
                chosen[i] = false;
                chosen[((i%2)?i-1:i+1)] = false;
            }
        }
    }
    return false;
}

int main(){
    dom.resize(30);
    seq.resize(30);

    while(cin>>n, n){
        memset(chosen, false, sizeof(bool)*30);
        cin>>m;
        cin>>lt.first>>lt.second;
        cin>>rt.first>>rt.second;

        for (lli i=0; i<2*m; i+=2){
            cin>>inp.first>>inp.second;
            dom[i].first = dom[i+1].second = inp.first;
            dom[i].second = dom[i+1].first = inp.second;
        }

        seq[0] = lt;
        if (backtrack(n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}