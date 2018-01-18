#include<bits/stdc++.h>

using namespace std;

struct adj_list_node {
    int node_num;
    int weight;
    adj_list_node(int n=-1 , int w=1) : node_num{n} , weight{w} {}
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
    graph(int V=0): total_vertex{V} , adj_list(V) {}

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
        adj_list.clear();
    }

    void print(){
    	for(int i=0; i<total_vertex; i++) {
    		printf("V:%3d , Adj.List: ", i);
    		display_neighbors(i);
    	}
    }

    bool empty() { return total_vertex==0; }

    ~graph() {
        if(total_vertex!=0) clear();
    }

    int add_node() {
        ++total_vertex;
        adj_list.push_back(vector<adj_list_node>(0));
        return (total_vertex-1);
    }
};


void string_to_edge(graph &G, string &s , map <char , int> &char_to_node , map <int , bool> &area_slept) {
    if(char_to_node.find(s[0]) == char_to_node.end()) {
        char_to_node[s[0]] = G.add_node();
        area_slept[char_to_node[s[0]]] = true;
    }
    if(char_to_node.find(s[1]) == char_to_node.end()) {
        char_to_node[s[1]] = G.add_node();
        area_slept[char_to_node[s[1]]] = true;
    }

    int x = char_to_node[s[0]];
    int y = char_to_node[s[1]];

    G.add_edge(x , y);
    G.add_edge(y ,x);
}

int main() {
    int N;  // slept areas
    int M;  // number of connections
    string s_ini;   // initially wake areas
    string edge;
    graph G;
    map <char , int> char_to_node;
    map <int , bool> area_slept;

    while(cin>>N , !cin.eof()) {
        (cin>>M).get();
        getline(cin , s_ini);   // initially woke up areas
        for(int i=0; i<s_ini.size(); i++){
            if(char_to_node.find(s_ini[i]) == char_to_node.end()) {
                char_to_node[s_ini[i]] = G.add_node();
                area_slept[char_to_node[s_ini[i]]] = false;
            }
        }

        // accepting the edges
        while(M--) {
            getline(cin, edge);
            string_to_edge(G , edge , char_to_node, area_slept);
        }

        // operation starts here
        int year=0 , active_count=0; bool finish=false , changes = false;
        vector <int> store_idx;
        while(!finish){
            changes = false;
            // check each node for activeness
            for(int i=0; i<G.total_vertex ; i++) {
                if(area_slept[i]){
                    // if slept
                    active_count = 0;
                    // count how many active adjacent area
                    for(int j=0; j<G.adj_list[i].size(); j++){
                        if(area_slept[G.adj_list[i][j].node_num] == false) ++active_count;
                    }
                    // if active count >= 3 : then this will become active
                    if(active_count>=3) {
                        store_idx.push_back(i);
                        changes = true;
                    }
                }
            }

            for(auto &itr:store_idx) {
                area_slept[itr] = false;
            }
            if(changes == false) break; // if no changes occurs
            store_idx.clear();
            ++year;
        }

        bool wake = true; int count=0;
        for (auto it=area_slept.begin(); it!=area_slept.end(); ++it)
            if(it->second == false) {
                ++count;
            }
        if(count >= N) {
            cout<<"WAKE UP IN, "<<year<<", YEARS"<<endl;
        } else {
                cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
        }
        G.clear();
        char_to_node.clear();
        area_slept.clear();
    }
    return 0;
}
