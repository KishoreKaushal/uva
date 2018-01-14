#include<bits/stdc++.h>
#define NOT_DISCOVERED 	(0)
#define DISCOVERED 		(1)

using namespace std;

struct adj_list_node {
    int node_num;
    int weight;
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

    /* removes the edge from the vertex x to the vertex y, if it is there*/
    void remove_edge(int x, int y) {
        // necessary checks for the following function to work bug free
    	// self directed edges are not allowed : i.e x != y
    	if(0<=x && x<total_vertex && 0<=y && y<total_vertex && x!=y){
            for(size_t i=0; i<adj_list[x].size() ; ++i ) {
                if(adj_list[x].at(i).node_num == y) {
                    adj_list[x].erase(adj_list[x].begin() + i);
                }
            }
        }
    }

    /* adds the edge from the vertex x to the vertex y, if it is not there*/
    void add_edge(int x, int y, int w=1) {
        if(0<=x && x<total_vertex && 0<=y && y<total_vertex && x!=y && !adjacent(x , y)){
            adj_list[x].push_back(adj_list_node(y , w));
        }
    }

    /* print all vertices y such that there is an edge from the vertex x to the vertex y */
    void display_neighbors(int x) {
        // prints all the neighbours of the vertex 'x'
        if(0<=x && x<total_vertex){
            cout<<adj_list[x];
        }
    }

    /* tests whether there is an edge from the vertex x to the vertex y */
    bool adjacent(int x, int y) {
        if(0<=x && x<total_vertex && 0<=y && y<total_vertex && x!=y){
            for(auto &i : adj_list[x]) {
                if(i.node_num == y) {
                    return true;
                }
            }
        }
        return false;
    }

    /* clear the graph */
    void clear() {
        for(int i=0; i<total_vertex ; i++) {
    		adj_list[i].clear();	       // clear the adjacent list
    	}
    	total_vertex = 0;                      // set the vertex count to zero
    }

    void print(){
    	for(int i=0; i<total_vertex; i++) {
    		printf("V:%3d , Adj.List: ", i);
    		display_neighbors(i);
    	}
    }

    int add_vertex(){
        total_vertex++;
        vector<adj_list_node> v;
        adj_list.push_back(v);
        return (total_vertex-1);
    }

    int get_num_adjacent(int x) {
        return adj_list[x].size();
    }

    bool empty() { return total_vertex==0; }

    ~graph() {
        if(total_vertex!=0) clear();
    }
};

void string_to_nodes(string &s , graph &G , map <char , int> &char_to_vertex) {
    for(auto itr = s.begin() ; itr != s.end() ; itr++) {
        if(*itr == ',') continue;
        if(char_to_vertex.find(*itr) == char_to_vertex.end()) {
            char_to_vertex[*itr] = G.add_vertex();
        }
    }
}

void string_to_edge(string &s , graph &G , map <char , int> &char_to_vertex ){
    char X , Y;
    X = s[1];   Y = s[3];
    if(char_to_vertex.find(X)==char_to_vertex.end()){
        char_to_vertex[X] = G.add_vertex();
    }
    if(char_to_vertex.find(Y)==char_to_vertex.end()){
        char_to_vertex[Y] = G.add_vertex();
    }
    // since undirected graph
    G.add_edge(char_to_vertex[X],char_to_vertex[Y]);
    G.add_edge(char_to_vertex[Y],char_to_vertex[X]);
}

/*  recursive implementation of the DFS */
void DFS_recursive(graph &G , int V , vector<bool> &discovered ) {
	int W;
	discovered[V] = true;
    for(auto itr = G.adj_list[V].begin() ; itr!=G.adj_list[V].end() ; ++itr) {
        W = itr->node_num;
        if(discovered[W] == false) {
            DFS_recursive(G , W , discovered);
        }
    }
}



int main() {
    int t;  // test cases
    cin>>t;
    map <char , int> char_to_vertex;    // node associated with that character
    graph G(0);
    string edge ;
    string node_list;       // the list of the available nodes
    while(t--) {
        G.clear();
        char_to_vertex.clear();
        while(cin>>edge , !edge.empty() && edge[0]!='*') {
            string_to_edge(edge , G , char_to_vertex);
        }
        cin>>node_list;
        string_to_nodes(node_list , G , char_to_vertex);
        // printing the map
        // for(auto itr = char_to_vertex.begin() ; itr!=char_to_vertex.end() ; ++itr) {
        //     cout<<itr->first<<" : "<<itr->second<<endl;
        // }
        //G.print();
        int num_acorn=0, conn_comp=0;
        int total_vertex = G.get_total_vertex();
        for(int i=0; i<total_vertex ; i++) {
            if(G.get_num_adjacent(i)==0)
                num_acorn++;
        }
        // finding number of connected components
        vector<bool> discovered(total_vertex , false);
        auto it = find(discovered.begin() , discovered.end() , false);
        while(it!=discovered.end()) {
            int DFS_start_vertex = it - discovered.begin() ;
            DFS_recursive(G , DFS_start_vertex , discovered);
            ++conn_comp;
            it = find(discovered.begin() , discovered.end() , false);
        }
        //cout<<"Total Connected components: "<<conn_comp<<endl;
        // total trees = total connected components - total acorns
        cout<<"There are "<< conn_comp - num_acorn <<" tree(s) and "<< num_acorn <<" acorn(s)."<<endl;
    }
    return 0;
}
