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
    PRECISION(4);   // setting the precision
    int t, total_trees;
    (cin>>t).get();

    string str;
    map <string , int> trees;

    getline(cin, str); // for the empty line
    while(t--) {
        total_trees=0;  // initialization step
        trees.clear();

        getline(cin, str);
        while(!str.empty()){
            ++total_trees;
            if(trees.find(str) != trees.end()){
                // it exist in the list : hence increase the count by one
                trees[str] +=1;
            } else {
                trees[str] = 1;
            }
            getline(cin, str); // for the empty line
        }
        // printing the percentage of all the trees
        for(auto map_itr = trees.begin() ; map_itr != trees.end() ; ++map_itr) {
            cout<<map_itr->first<<" "<<float(map_itr->second*100) / (total_trees)<<endl;
        }
        if(t) cout<<endl;
    }

    return 0;
}
