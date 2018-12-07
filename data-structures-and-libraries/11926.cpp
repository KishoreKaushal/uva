#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    int n, m , startTime, endTime, interval;
    bool conflict= false;
    std::bitset<1000001> b;
    while(cin>>n>>m , (n||m)){
        b.reset();
        conflict = false;
        // one time task
        while(n--) {
            cin>>startTime>>endTime;
            if(!conflict) {
                //b.set(startTime);
                //b.set(endTime);
                for(int i=startTime ; i<endTime; i++){
                    if(b[i]) {
                        conflict = true;
                        break;
                    }
                    b.set(i);
                }
            }
        }
        // repeating task
        while(m--){
            cin>>startTime>>endTime>>interval;
            if(!conflict) {
                while(startTime<1000001) {
                    //b.set(startTime);
                    //if(endTime<1000001) b.set(endTime);
                    for(int i=startTime ; i<endTime&&i<1000001; i++){
                        if(b[i]) {
                            conflict = true;
                            break;
                        }
                        b.set(i);
                    }
                    startTime+=interval;
                    endTime+=interval;
                }
            }
        }

        if(conflict) cout<<"CONFLICT"<<endl;
        else cout<<"NO CONFLICT"<<endl;
    }
    return 0;
}
