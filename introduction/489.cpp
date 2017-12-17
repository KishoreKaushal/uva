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
    int n ;
    string  sol, guess; int hangman , pos;
    while ((cin>>n).get() , (n!=-1)) {
        vector <bool> presence(26 , false);
        getline(cin, sol);
        sort(ALL(sol)); UNIQUE(sol);
        // cout<<"You enterred Sol: "<<sol<<endl;
        getline(cin, guess);
        for(int i=0; i<guess.size(); i++ ){
            //std::cout << "Dealing with: " << guess[i]<<" Index: "<<i<<endl;
            if(presence[guess[i]-'a']){
                guess.erase(i , 1);
                i--;
            }
            else presence[guess[i]-'a'] = true;
        }
        //cout<<"Guess after modification: "<<guess<<endl;
        hangman = 0;
        while(hangman<=7 && guess.size()!=0 && sol.size()!=0) {
            //cout<<"Loop Sol: "<<sol<<endl;
            pos = sol.find(guess[0]);
            if(pos != std::string::npos) sol.erase(pos , 1);
            else {
                hangman++;
            }
            if(guess.size()>1)guess = guess.substr(1);
            else guess.clear();
        }
        //cout<<"Hangman: "<<hangman<<endl;
        cout<<"Round "<<n<<endl;
        if(hangman>=7) cout<<"You lose."<<endl;
        else {
            if(sol.size()==0) cout<<"You win."<<endl;
            else cout<<"You chickened out."<<endl;
        }
        //else if(attempt>0 && sol.size()!=0) cout<<"You chickened out."<<endl;

        guess.clear();
        sol.clear();
    }
    return 0;
}
