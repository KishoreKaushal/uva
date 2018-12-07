#include<bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define ALL(x) x.begin() , x.end()

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");

    int N , K , M;
    long long int totCents;
    char c;
    string s;
    vector <int> priceOfCharVec(256);
    string::iterator it;

    (cin>>N).get();
    while(N--) {
        (cin>>K).get();

        fill(ALL(priceOfCharVec) , 0);

        while(K--){
            cin>>c; (cin>>priceOfCharVec[c]).get();
        }

        (cin>>M).get();

        totCents=0;
        while(M--) {
            getline(cin, s);
            for(it = s.begin() ; it < s.end() ; it++)
                totCents += priceOfCharVec[*it];
        }

        cout<<std::fixed<<std::setprecision(2)<<(totCents/100.0)<<"$"<<endl;
    }
    return 0;
}
