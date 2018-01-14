#include <bits/stdc++.h>

using namespace std;

struct adj_list_node {
    int weight;
    int node_num;
    adj_list_node(int n , int w=1) : node_num{n} , weight{w} {}
};

std::ostream& operator<<(std::ostream& ostr, const std::vector<adj_list_node>& vec)
{
    for (auto &a : vec) {
        ostr << "{" << a.node_num << ":" << a.weight << "} ";
    }
    cout<<endl;
    return ostr;
}

class graph {

public:
    int total_vertex;
    vector<vector<adj_list_node>> adj_list;

    int get_total_vertex(){
        return total_vertex;
    }

    /* initializes the graph */
    graph(int V): total_vertex{V} , adj_list(V) {}

    /* adds the edge from the vertex x to the vertex y, if it is not there*/
    void add_edge(int x, int y, int w=1) {
        //if(0<=x && x<total_vertex && 0<=y && y<total_vertex && x!=y && !adjacent(x , y)){
            adj_list[x].push_back(adj_list_node(y , w));
        //}
    }

    /* clear the graph */
    void clear() {
        for(int i=0; i<total_vertex ; i++) {
    		adj_list[i].clear();	       // clear the adjacent list
    	}
    	total_vertex = 0;                      // set the vertex count to zero
    }

    // int get_deg_in(int x);
    // int get_deg_out(int x);
    int get_deg(int x) {
        return adj_list[x].size();
    }

    ~graph() {
        if(total_vertex!=0) clear();
    }
};

int main() {
    int m,n;    // matrix dimensions : m x n
    int r, inputInt;    // no. of elements in each row
    vector<int> idx;
    while(cin>>m>>n) {
        graph G(n);            // graph G: with vertex count: n

        for(int j=1; j<=m; j++ ){
            cin>>r;
            for(int i=0; i<r; i++) {
                cin>>inputInt;
                idx.push_back(inputInt);
            }

            for(int i=0; i<r; i++) {
                cin>>inputInt;
                G.add_edge(idx[i]-1 , inputInt , j);    // j : 1-based indexing for the matrix
            }
            idx.clear();
        }
        cout<<n<<" "<<m<<endl;

        for(int i=0; i<n; i++) {
            r = G.get_deg(i);
            cout<<r;
            for(int j=0; j<r; j++){
                cout<<" "<<G.adj_list[i].at(j).weight;
            }
            cout<<endl;
            for(int j=0; j<r; j++){
                cout<<G.adj_list[i].at(j).node_num;
                if(j!=r-1)  cout<<" ";
            }
            cout<<endl;
        }

        idx.clear();
        G.clear();
    }

    return 0;
}
