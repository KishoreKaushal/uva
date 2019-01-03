#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int B, S, c=0;
    int bAge[10000], sAgeTmp[10000];
    
    while(cin>>B>>S, B|S) {
        ++c;

        for (int i=0; i<B; ++i) cin>>bAge[i];
        for (int j=0; j<S; ++j) cin>>sAgeTmp[j];

        sort(bAge, bAge+B, greater<int>());
        sort(sAgeTmp, sAgeTmp+S);
        list<int> sAge(sAgeTmp, sAgeTmp+S);


        int b = 0, min_diff;
        list<int>::iterator itr_min;
        while (b<B && !sAge.empty()){
            min_diff = INT_MAX;
            auto itr = itr_min = sAge.begin();
            while (itr != sAge.end()){
                if (abs(*itr - bAge[b]) < min_diff) {
                    min_diff = abs(*itr - bAge[b]);
                    itr_min = itr;
                }
                ++itr;
            }
            sAge.erase(itr_min);
            ++b;
        }

        cout<<"Case "<<c<<":"<<" ";
        if (b == B){
            cout<<0<<endl;
        } else {
            cout<<B-b<<" "<<bAge[B-1]<<endl;
        }
    }

    return 0;
}