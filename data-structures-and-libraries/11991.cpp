#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))

// output : indexing should be 1-based

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");

    // we work with 0-based indexing : but output is 1-based indexing
    std::map<int , int> list_index;
    std::vector<vector<int>> occurence_list;
    vector <int> v;
    int n,m,idx ,inputInt, pos=1;
    int k, V;

    while(cin>>n>>m) {
        pos=1;
        occurence_list.clear();
        list_index.clear();
        while(n--) {
            v.clear();
            cin>>inputInt;
            if(list_index.find(inputInt)==list_index.end()) {
                // if key dosesn't exists in the map
                // create a space for it in the list_index map and occurence_list vector
                list_index[inputInt] = occurence_list.size();
                v.push_back(pos);
                occurence_list.push_back(v);
            } else {
                // if key exists
                idx = list_index[inputInt]; // get the index of the occurence_list
                // append the location(1-based indexing) of the inputInt in the occurence_list[idx]
                occurence_list[idx].push_back(pos);
            }
            pos++;
        }

        while(m--) {
            cin>>k>>V;
            if(list_index.find(V)!=list_index.end()) {
                idx = list_index[V];
                if(k <= occurence_list[idx].size()) cout<<occurence_list[idx].at(k-1) <<endl;
                else cout<<0<<endl;
            } else cout<<0<<endl;
        }
    }
    return 0;
}
