#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )
#define PRECISION(n)  (cout<<fixed<<setprecision(n))

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");

    int N , B, SG , SB, input_lemming_power, count , b_g;
    multiset <int> blue;
    multiset <int> green;
    vector <int> field_green;
    vector <int> field_blue;
    cin>>N;
    while(N--) {
        cin>>B>>SG>>SB;
        blue.clear();
        green.clear();
        // green soilders
        while(SG--) {
            cin>>input_lemming_power;
            green.insert(-1*input_lemming_power); // storing with a negative sign : so that the largest number will be the smallest in the set
        }
        // blue soilders
        while(SB--) {
            cin>>input_lemming_power;
            blue.insert(-1*input_lemming_power);
        }


        // battle rounds
        while(!blue.empty() && !green.empty()) {
            // getting the battlefields ready
            field_blue.clear(); field_green.clear();
            count = 0;
            while(count < B && !blue.empty() && !green.empty()){
                field_blue.push_back(-1* (*blue.begin()));
                field_green.push_back(-1* (*green.begin()));
                blue.erase(blue.begin());   // went to battlefield
                green.erase(green.begin()); // went to battlefield
                ++count;
            }
            // battle begins , count contains the number of battlefield active
            // discard all zeros and add the remaining into the blue and green again
            for(int i=0; i<count ; i++){
                b_g = field_blue[i] - field_green[i];
                field_blue[i] = (b_g >= 0) * b_g;
                field_green[i] = ((-1*b_g) >= 0) * (-1*b_g);
                if(field_blue[i]>0) blue.insert(-1*field_blue[i]);
                if(field_green[i]>0) green.insert(-1*field_green[i]);
            }
        }
        if(blue.empty() && green.empty())   cout<<"green and blue died"<<endl;
        else if(blue.empty()){
            cout<<"green wins"<<endl;
            for(auto mulset_itr = green.begin() ; mulset_itr!=green.end() ; mulset_itr++) {
                cout<<-1* *mulset_itr<<endl;
            }
        }
        else if(green.empty()){
            cout<<"blue wins"<<endl;
            for(auto mulset_itr = blue.begin() ; mulset_itr!= blue.end() ; ++mulset_itr) {
                cout<<-1* *mulset_itr<<endl;
            }
        }
        if(N) cout<<endl;
    }
    return 0;
}
