#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    string score;
    int total_score;
    while(getline(cin, score) , (score!="Game Over")) {
        // transform the string by clearing the space in the string
        for(auto itr= score.begin() ; itr<score.end(); itr++ ){
            if(*itr ==' '){
                score.erase(itr, itr+1);
                itr--;
            }
        }
        //cout<<score<<endl;

        // counting the score : for 10 frames
        // for each frame a maximum of 2 rolls are allowed
        total_score = 0;
        for(int i=0 ; i<10 ; i++ ){
            //cout<<"Loop : "<<i<<" Score String: "<<score<<" Score till now: "<<total_score<<endl;
            if(score[0]!='X'){
                if(score[1]!='/') total_score += ((score[0] - '0') + (score[1]-'0'));
                else{
                    total_score+=10;
                    if(score[2]!='X') total_score += (score[2] - '0');
                    else total_score+=10;
                }
                score = score.substr(2);
            } else {
                total_score += 10;
                if(score[1]=='X' && score[2]=='X') total_score+=20;
                else if(score[1]=='X' && score[2]!='X') total_score+= (10+ (score[2]-'0'));
                else if(score[2]=='/') total_score+=10;
                else total_score += ((score[1]-'0') + (score[2]-'0'));
                score = score.substr(1);
            }
        }
        //cout<<"Out of the loop: "<<score<<endl;
        cout<<total_score<<endl;
        score.clear();
    }
    return 0;
}
