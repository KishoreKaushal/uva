#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<utility>
#include<map>
#include<queue>

#define MAXR (300)
#define MAXC (300)

using namespace std;

void bfs(char ch[MAXR][MAXC], int R, int C, int S , int E){
    bool visited[3][MAXR][MAXC];
    int dist[3][MAXR][MAXC];

    /*initialization*/
    for (int i=0; i<3; ++i){
        for (int j=0; j<R; ++j){
            for (int k=0; k<C; ++k){
                visited[i][j][k] = false;
                dist[i][j][k] = 0;
            }
        }
    }


    queue<pair<int , int>> to_visit;
    pair<int, int> curr_state, next_state;
    bool state_reachable = true;
    bool end_state_reached = false;

    /*start action and state pair: (1,S) */
    int r = S/C;
    int c = S%C;
    int a = 1;

    to_visit.push(make_pair(a,S));
    visited[a-1][r][c] = true;
    
    while(!to_visit.empty()){
        curr_state = to_visit.front(); to_visit.pop();
        r = curr_state.second / C;
        c = curr_state.second % C;
        a = curr_state.first;
        
        /*RIGHT*/
        state_reachable = true;
        if (c+a >= C) {
            state_reachable = false;
        } else {
            for (int d=1; d<=a; ++d){
                if (ch[r][c+d] == '#'){
                    state_reachable = false;
                    break;
                }
            }
        }

        if (state_reachable) {
            next_state.first = (a%3) + 1;
            next_state.second = r*C + (c+a);
            if (!visited[next_state.first-1][r][c+a]){
                dist[next_state.first-1][r][c+a] = dist[a-1][r][c] + 1;
                if (next_state.second == E){
                    end_state_reached = true;
                    break;
                }
                visited[next_state.first-1][r][c+a] = true;
                to_visit.push(next_state);
            } 
        }

        /*UP*/
        state_reachable = true;
        if (r-a < 0) {
            state_reachable = false;
        } else {
            for (int d=1; d<=a; ++d){
                if (ch[r-d][c] == '#'){
                    state_reachable = false;
                    break;
                }
            }
        }

        if (state_reachable) {
            next_state.first = (a%3) + 1;
            next_state.second = (r-a)*C + c;
            if(!visited[next_state.first-1][r-a][c]){
                dist[next_state.first-1][r-a][c] = dist[a-1][r][c] + 1;
                if (next_state.second == E){
                    end_state_reached = true;
                    break;
                }
                visited[next_state.first-1][r-a][c] = true;
                to_visit.push(next_state);
            }
        }
        

        /*LEFT*/
        state_reachable = true;
        if (c-a < 0) {
            state_reachable = false;
        } else {
            for (int d=1; d<=a; ++d){
                if (ch[r][c-d] == '#'){
                    state_reachable = false;
                    break;
                }
            }
        }

        if (state_reachable) {
            next_state.first = (a%3) + 1;
            next_state.second = r*C + (c-a);
            if (!  visited[next_state.first-1][r][c-a]){
                dist[next_state.first-1][r][c-a] = dist[a-1][r][c] + 1;
                if (next_state.second == E){
                    end_state_reached = true;
                    break;
                }
                visited[next_state.first-1][r][c-a] = true;
                to_visit.push(next_state);
            }
        }
        

        /*DOWN*/
        state_reachable = true;
        if (r+a >= R) {
            state_reachable = false;
        } else {
            for (int d=1; d<=a; ++d){
                if (ch[r+d][c] == '#'){
                    state_reachable = false;
                    break;
                }
            }
        }
        if (state_reachable) {
            next_state.first = (a%3) + 1;
            next_state.second = (r+a)*C + c;
            if (!visited[next_state.first-1][r+a][c]){
                dist[next_state.first-1][r+a][c] = dist[a-1][r][c] + 1;
                if (next_state.second == E){
                    end_state_reached = true;
                    break;
                }
                visited[next_state.first-1][r+a][c] = true;
                to_visit.push(next_state);
            }
        }
    }

    if (end_state_reached){
        int r = next_state.second / C;
        int c = next_state.second % C;
        cout<<dist[next_state.first-1][r][c]<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char ch[MAXR][MAXC];
    int T, R, C, S, E;
    cin>>T;
    while(T--) {
        cin>>R>>C;
        for(int i=0; i<R; ++i){
            for (int j=0; j<C; ++j){
                cin>>ch[i][j];
                if (ch[i][j] == 'S'){
                    S = i*C + j;
                } else if (ch[i][j] == 'E'){
                    E = i*C + j;
                }
            }
        }
        bfs(ch, R, C, S, E);
    }
    return 0;
}