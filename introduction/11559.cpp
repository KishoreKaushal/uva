#include<bits/stdc++.h>
#include<climits>
using namespace std;

// Constraints :
// Total cost should be within the budget
// All the participants must stay at the same hotel


// Input format :
// N : no. of the participants
// B : Budget
// H : no. of the hotels
// W : no. of the weeks
// First line : N  B  H  W
// Follow 2 lines for each hotels
// ----> p : price per person
// W ints --> a : available beds

int main(){
    int N, B, H, W , minCost, minWeek, ava, p ;
    vector <int> price;
    vector <vector<int>> bedAvailable;
    vector <int> avail ;
    vector <int> temp;
    bool found;
    while (scanf(" %d %d %d %d\n" , &N , &B, &H, &W) != EOF ){
        minCost=0;
        // taking input for all the hotels
        for (int h=0; h<H ; h++){
            scanf(" %d\n" , &p);    price.push_back(p); // store the price into a vector
            for(int w=0 ; w<W; w++){
                scanf(" %d" , &ava);
                avail.push_back(ava);
            }
            bedAvailable.push_back(avail);
            avail.clear();
        }

        // // print bed bedAvailable
        //
        // for(int i=0  ; i<bedAvailable.size(); i++){
        //     for (int j=0; j<W; j++){
        //         std::cout << bedAvailable[i].at(j) << ' ';
        //     }
        //     cout<<endl;
        // }


        // finding  the minimum cost
        for (int w=0; w<W; w++) {
            found  = false;;
            // finding minWeek price per person
            for (int h=0; h<H; h++ ){
                if(bedAvailable[h].at(w) >= N) {
                    temp.push_back(price[h]);
                }
            }

            // temp : contains the price of the hotels which has atleast B beds
            // if for that weekend any hotel exist with atleast N beds
            if(temp.size()>0) {
                found = true;
                minWeek = INT_MAX;
                for(int k=0; k<temp.size(); k++){
                    if(minWeek>temp[k]) minWeek = temp[k];
                }
                //cout<<"MinWeek: "<<minWeek<<endl;
                minCost += N*minWeek;
            } else {
                found = false;
                break;
            }
        }

        if(!found) cout<<"Found is false \n";

        if(found && minCost<=B) {
            cout<<minCost<<endl;
        } else {
            cout << "stay home" << '\n';
        }

        // clearing all the vectors for next usage
        found = false;
        price.clear();
        avail.clear();
        for(int i=0; i<bedAvailable.size() ; i++ ){
            bedAvailable[i].clear();
        }
        bedAvailable.clear();
        temp.clear();
        minCost=0;
    }

    return 0;
}
