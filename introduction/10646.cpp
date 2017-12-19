#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

inline int value_of_card(string &s) {
    if(isdigit(s[0])) {
        return (s[0]-'0');
    } else return 10;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    int t, Y ,X;    // t: test cases & X : card value
    (cin>>t).get();
    std::vector<string> deck; // deck of 52 cards
    std::vector<string> cards_in_hand;   // top 25 cards in deck
    std::vector<string> pile;    // remaining cards
    string top_card;
    REP(c, 0, t){
        deck.clear();
        cards_in_hand.clear();
        pile.clear();
        deck.resize(52);
        for(int j=51 ; j>=0 ; j--){
            cin>>deck[j];   // all set ==> card[51] is the bottom
        }

        Y=0;    // initially set to zero
        cards_in_hand = vector<string>(deck.begin() , deck.begin()+25); // top 25 cards of the pile
        pile = vector<string>(deck.begin()+25 , deck.end());    // remaining pile : 52 - 25 cards

        // repeat the following process three times
        for(int i=0; i<3; i++) {
            top_card = pile[0]; // topmost card in the pile
            X = value_of_card(top_card);
            Y+=X;
            pile.erase(pile.begin() , pile.begin()+(10-X+1));
        }

        // put the remaining 25 cards on the top of this pile
        // constructing that pile :
        cards_in_hand.insert(cards_in_hand.end() , ALL(pile));

        // now the task is to tell what is the Yth card from the bottom of this pile
        cout<<"Case "<<c+1<<": "<< *(cards_in_hand.end()-Y) <<endl;
    }

    return 0;
}
