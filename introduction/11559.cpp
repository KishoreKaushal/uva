#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))

class hotel {
public:
    int price;
    int max_week;   // max bed for a weekend
    hotel(int p , int w) : price{p} , max_week{w} {}
};

bool compare_hotel(const hotel &a , const hotel &b) {
    return (a.price<b.price);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");

    int N;  //number of the participants
    int B;  // budget
    int H;  // number of the hotels
    int W;  // number of the weekends;
    int p;  // price
    int w1 ,w2;
    vector<hotel> v;
    while(cin>>N>>B>>H>>W , !cin.eof()) {
        for(int i=0; i<H ; i++) {
            cin>>p;
            cin>>w1;
            for(int j=1; j<W; ++j) {
                cin>>w2;
                if(w2>w1) {
                    w1 = w2;
                }
            }
            v.push_back(hotel(p,w1));
        }

        sort(ALL(v) , compare_hotel);
        bool found = false;
        int price=INT_MAX;
        for(int i=0; i<v.size() ; ++i) {
            if(v[i].max_week >= N) {
                found = true;
                price = N*v[i].price;
                break;
            }
        }

        if(found && price<= B) {
            cout<<price<<endl;
        } else cout<<"stay home"<<endl;
        v.clear();
    }
    return 0;
}
