#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

#define RESULT(N, P) (cout<<"Position of player "<<N<<" is "<<P<<"."<<endl)

// struct entity {
// //    char type;  // S: snake or L: ladder
// //    int src;    // for snake this is tail & for ladder this is the bottom
//     int dest;   // for snake this is mouth & for ladder this is the top
//     //entity(int typ , int l, int h): type{typ} , src{l} , dest{h} {}
//     entity(int h): dest{h} {}
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    // a: number of the players
    // b: number of the snakes or the ladder
    // c: number of the rolls < 1,000,000
    int t , a, b , c, m , n , dice_roll , roll, current_player;
    // map <int , entity> snakes_ladder;   // int data is the source and the entity.dest contains the final Position
    map <int , int> snakes_ladder;   // first int data is the source and the second int data is the final Position
    vector <int> player_position;
    //bool game_end = false;
    cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        //cout<<"A: "<<a<<" B: "<<b<<" C: "<<c<<endl;
        snakes_ladder.clear();
        player_position.clear();
        REP(j, 0, a){
            player_position.push_back(1);
        }

        //player_position.resize(a);
        // fill(ALL(player_position) , 1);

        // making the board ready
        REP(j, 0, b){
            cin>>m>>n;
            snakes_ladder[m] = n; // maps the source to the dest
        }

        // the game begins
        current_player = 0;
        for(roll=0; roll<c; roll++) {
            cin>>dice_roll;
            current_player = roll%a;
            if(snakes_ladder.find(player_position[current_player] + dice_roll)!=snakes_ladder.end()) {
                player_position[current_player] = snakes_ladder[player_position[current_player]+dice_roll];
                if(player_position[current_player]>=100){
                    player_position[current_player] = 100;
                    break;
                }
            } else {
                if(player_position[current_player] + dice_roll >= 100 ) {
                    player_position[current_player] = 100;
                    break;
                } else {
                    player_position[current_player] += dice_roll;
                }
            }
        }
        roll++;
        for( ; roll<c ; roll++) cin>>dice_roll;

        // print the RESULT
        REP(j, 0, a){
            RESULT(j+1 , player_position[j]);
        }
    }
    return 0;
}
