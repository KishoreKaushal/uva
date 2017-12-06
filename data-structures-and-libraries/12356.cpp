#include<bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

class soil {
public:
    int lt,rt;
    soil(int l , int r) {
        lt = l; rt = r;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int S, B, L, R;
    std::vector<soil> v;

    while(cin>>S>>B , (S||B)){
        v.clear();
        REP(j,0, (S+2)){
            v.push_back(soil(j-1 , j+1));
        }
        while(B--) {
            cin>>L>>R;
            v[v[L].lt].rt = v[R].rt;
            v[ v[R].rt ].lt = v[L].lt;
            if(v[ v[R].rt ].lt!=0) cout<<v[ v[R].rt ].lt <<" ";
            else cout<<"* ";
            if(v[v[L].lt].rt!=S+1) cout<<v[v[L].lt].rt <<endl;
            else cout<<"*\n";
        }
        cout<<"-"<<endl;
    }
    return 0;
}
