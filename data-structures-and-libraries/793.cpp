#include<bits/stdc++.h>
using namespace std;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
    vector<long long int> p, rank, setSize;                       // remember: vi is vector<int>
    long long int numSets;
public:
    UnionFind(long long int N) {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (long long int i = 0; i < N; i++)
        p[i] = i;
    }

    long long int findSet(long long int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(long long int i, long long int j) { return findSet(i) == findSet(j); }

    void unionSet(long long int i, long long int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            long long int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y]) {
                p[y] = x; setSize[x] += setSize[y];
            } else {
                p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    long long int numDisjointSets() { return numSets; }
    long long int sizeOfSet(long long int i) { return setSize[findSet(i)]; }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    long long int t ;  // test cases
    (cin>>t).get();
    char ch;
    long long int c1, c2;
    string s;
    getline(cin,s);
    while(t--) {
        long long int N , suc=0, unsuc=0;
        (cin>>N).get();
        UnionFind u(N);
        while(getline(cin,s) , !s.empty()) {
            istringstream iss(s);
            iss>>ch>>c1>>c2;
            --c1; --c2;
            // cout<<"C1: "<<c1<<" C2: "<<c2<<endl;
            if(ch=='c') {
                u.unionSet(c1 , c2);
            } else if(ch=='q') {
                if(u.isSameSet(c1 , c2)) suc++;
                else unsuc++;
            }
        }
        cout<<suc<<","<<unsuc<<endl;
        if(t) cout<<endl;
    }
    return 0;
}
