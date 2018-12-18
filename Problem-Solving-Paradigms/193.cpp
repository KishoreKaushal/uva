#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli m,n,k;
bool white[105];
pair<lli, lli> edge;
vector<set<lli>> adj_list;
lli opt_cnt=0;
set<lli> opt_clr;

void backtrack(lli N=1, lli blk_cnt=0){
    if (N == n+1) {
        if (blk_cnt > opt_cnt){
            opt_cnt = blk_cnt;
            opt_clr.clear();
            for (lli i=1; i<=n; ++i){
                if (!white[i]) opt_clr.insert(i);
            }
        }
    } else {
        bool possible = true;
        for (auto it = adj_list[N].begin(); it!=adj_list[N].end(); ++it){
            if (!white[*it]) {
                possible = false; break;
            }
        }
        if (possible){
            white[N] = false;
            backtrack(N+1, blk_cnt +1);
            white[N] = true;
        }
        backtrack(N+1, blk_cnt);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>m;
    while(m--){
        cin>>n>>k;

        memset(white, true, sizeof(bool)*105);
        opt_clr.clear();
        opt_cnt = 0;
        adj_list.resize(n+1);

        for (lli i=0; i<k; ++i){
            cin>>edge.first>>edge.second;
            adj_list[edge.first].insert(edge.second);
            adj_list[edge.second].insert(edge.first);
        }

        backtrack();
        cout<<opt_cnt<<endl;
        
        auto it = opt_clr.begin();
        cout<<*it;  ++it;
        while(it!=opt_clr.end()){
            cout<<" "<<*it;
            ++it;
        } cout<<endl;
        
        adj_list.clear();
    }

    return 0;
}