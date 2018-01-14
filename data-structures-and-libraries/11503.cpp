#include<bits/stdc++.h>
using namespace std;

class union_find {
private:
    vector <int> p;         // parent
    vector <int> rank;      // height of the subtree
    vector <int> set_size;
    unsigned int num_sets;           // total Disjoint sets

public:
    union_find(int N=0) {
        set_size.assign(N,1);
        num_sets = N;
        rank.assign(N,0);
        p.assign(N,0);
        for(int i=0; i<N; ++i) p[i] = i;
    }

    int new_set() {
        int idx = p.size();
        p.push_back(idx);
        rank.push_back(0);
        set_size.push_back(1);
        num_sets++;
        return idx;
    }

    int insert_to_set_containing(int num) {
        int idx = p.size();
        p.push_back(idx);
        rank.push_back(0);
        set_size.push_back(1);
        union_set(idx , num);
        num_sets++;
        return idx;
    }

    void clear() {
        p.clear();
        rank.clear();
        set_size.clear();
        num_sets = 0;
    }

    ~union_find(){
        clear();
    }

    int find_set(int i) {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }

    bool is_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }

    void union_set(int i, int j) {
        if(!is_same_set(i,j)) {
            num_sets--;
            int x = find_set(i) , y = find_set(j);
            // rank is used to keep the tree short
            if(rank[x] > rank[y]) {
                p[y] = x ;
                set_size[x]+=set_size[y];
            } else {
                p[x] = y ;
                set_size[y] += set_size[x];
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    unsigned int num_disjoint_sets() { return num_sets; }
    int size_of_set(int i) { return set_size[find_set(i)]; }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");

    int t;
    (cin>>t).get();
    string s1,s2;
    while(t--) {
        map <string , int> name_to_index;
        int F;
        (cin>>F).get();
        union_find u;
        while(F--) {
            cin>>s1>>s2;
            // cout<<"Str1: "<<s1<<" "<<"Str2: "<<s2<<"#"<<endl;
            if(name_to_index.find(s1)==name_to_index.end()){
                name_to_index[s1] = u.new_set();
            }
            if(name_to_index.find(s2)==name_to_index.end()){
                name_to_index[s2] = u.new_set();
            }
            // cout<<"s1 idx: "<<name_to_index[s1]<<endl;
            // cout<<"s2 idx: "<<name_to_index[s2]<<endl;

            u.union_set(name_to_index[s1] , name_to_index[s2]);
            cout<<u.size_of_set(name_to_index[s1])<<endl;
        }
    }

    return 0;
}
