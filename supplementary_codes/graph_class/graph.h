#include<iostream>
#include<iterator> // for iterators
#include<vector> // for vectors

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

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
    int total_vertex;
    vector<vector<adj_list_node>> adj_list;

public:
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

    bool empty() { return total_vertex==0; }

    ~graph() {
        if(total_vertex!=0) clear();
    }
};

#endif // GRAPH_H
