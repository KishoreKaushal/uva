#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

class participant{
public:
    std::vector<bool> probSolved;
    std::vector<int> incSub;
    int penaltyTime;
    int totalProbSolved;
    bool submission;
    int teamNumber;
    participant(int t):probSolved(10) , incSub(10){
        for(int u=0; u<10; u++) {incSub[u]=0; probSolved[u]=false;}
        penaltyTime=0;
        totalProbSolved=0;
        submission=false;
        teamNumber = t;
    }
};

bool compareParticipantClass(participant &a , participant &b){
    if(a.totalProbSolved != b.totalProbSolved) return (a.totalProbSolved > b.totalProbSolved);
    else if(a.penaltyTime != b.penaltyTime) return (a.penaltyTime < b.penaltyTime);
    else if(a.teamNumber != b.teamNumber) return (a.teamNumber < b.teamNumber);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ifstream cin("input");
    // ofstream cout("output");

    int t, teamNumber , problemNumber , penaltyTime;
    char L;
    string s;
    istringstream iss;
    (cin>>t).get();
    getline(cin, s);

    while(t--) {
        //getline(cin, s);

        vector<participant>::iterator itr;
        std::vector<participant> v;
        v.push_back(participant(0));
        REP(j , 1 , 101) v.push_back(participant(j));


        while(!cin.eof()){
            getline(cin, s);
            if(s.empty()) break;
            iss.str(s);
            iss>>teamNumber>>problemNumber>>penaltyTime>>L;
            //cout<<"\nTeam No: "<<teamNumber<<" problemNumber: "<<problemNumber<<" penaltyTime: "<<penaltyTime<<" L: "<<L<<endl;
            v[teamNumber].submission = true;
            if(L=='C') {
                if(!v[teamNumber].probSolved[problemNumber]){
                    v[teamNumber].penaltyTime+= (penaltyTime + v[teamNumber].incSub[problemNumber]*20);
                    v[teamNumber].probSolved[problemNumber] = true;
                    v[teamNumber].totalProbSolved++;
                }
            } else if(L=='I'){
                if(!v[teamNumber].probSolved[problemNumber]){
                    v[teamNumber].incSub[problemNumber]++;
                    //cout<<"For Team: "<<teamNumber<<" inc sub: "<<v[teamNumber].incSub[problemNumber] <<" Prob No.: "<<problemNumber<<endl;
                }
            }
        }

        for(itr = v.begin() ; itr < v.end(); itr++)
            while(!(*itr).submission && itr<v.end()){
                v.erase(itr);
            }

        sort(ALL(v) , compareParticipantClass);
        for(int i=0; i<v.size(); i++){
            cout<<v[i].teamNumber<<" "<<v[i].totalProbSolved<<" "<<v[i].penaltyTime<<endl;
        }
        if(t!=0)cout<<endl;
    }


    return 0;
}
