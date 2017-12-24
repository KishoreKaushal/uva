#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    int m, n , inputInt , totalCD=0;
    set <int> jack;
    set <int> jill;
    while (cin>>n>>m , (n||m)) {
        jack.clear();
        jill.clear();
        totalCD = 0;
        while(n--) {
            cin>>inputInt;
            jack.insert(inputInt);
        }
        while(m--) {
            cin>>inputInt;
            jill.insert(inputInt);
        }
        for(auto set_itr = jack.begin() ; set_itr!=jack.end(); ++set_itr) {
            if(jill.find(*set_itr) != jill.end()) {
                ++totalCD;
            }
        }
        cout<<totalCD<<endl;
    }
    return 0;
}
