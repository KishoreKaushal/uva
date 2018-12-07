#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

struct car {
    int arrival_time;
    int car_num;
    car(int num , int arrival):car_num{num} , arrival_time{arrival} {}
};

template <typename any> void clear_queue (queue <any> &q) {
    while(!q.empty()){
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    int c , n, t, m , arrival , time_flow;
    istringstream iss;
    string str , bank , ferry_bank;
    (cin>>c).get();

    queue <car> left_bank;
    queue <car> right_bank;

    while(c--) {
        clear_queue<car> (left_bank);
        clear_queue<car> (right_bank);
        str.clear(); bank.clear();
        ferry_bank = "left";

        (cin>>n>>t>>m).get();
        for(int i=0; i<m; i++) {
            iss.clear();
            getline(cin, str);
            iss.str(str);
            iss>>arrival>>bank;
            if(bank=="left") left_bank.push(car{i, arrival});
            else right_bank.push(car{i , arrival});
        }
        vector <int> unload_time(m , -1);
        //cout<<"At Line : "<<__LINE__<<endl;
        // now we have all the data lets solve this problem
        // initially the ferry is at the left bank
        time_flow = 0;
        while(!left_bank.empty() && !right_bank.empty()) {
            if(ferry_bank == "left") {
                // if ferry is on the left bank
                if(left_bank.front().arrival_time <= right_bank.front().arrival_time || left_bank.front().arrival_time <= time_flow) {
                // if(left_bank.front().arrival_time <= time_flow) {
                    // and a car arrives on this bank before a car arrives on the other bank
                    // so what should we do? check the time_flow
                    // load upto n cars who arrived on or before time_flow
                    car first_car = left_bank.front();
                    // if ferry was waiting for the car on this bank
                    if(time_flow < first_car.arrival_time) time_flow = first_car.arrival_time;
                    // if the above is not the case that means ferry is on the other bank and coming towards this bank
                    // in that interval the car arrives in this bank

                    // therefore time at which car is loaded will be equal to time_flow
                    for(int i=0; i<n && !left_bank.empty() && left_bank.front().arrival_time <= time_flow ; i++) {
                        //cout<<time_flow + t<<endl;
                        unload_time[ left_bank.front().car_num ] = time_flow+t;
                        left_bank.pop();
                    }
                    // after reaching at the left bank :
                    // update the time_flow to the time at which the car is unloaded from the ferry
                    time_flow += t;
                    // and the ferry_bank is now right
                    ferry_bank = "right";
                } else {
                    // and a car arrives on the other bank before a car arrives on this bank
                    // in this case the ferry will travel to the other bank to load the car
                    // hence the time: time_flow will be updated to the car arrival_time + t
                    if(time_flow <= right_bank.front().arrival_time) time_flow = right_bank.front().arrival_time + t;
                    else time_flow+=t;
                    // and the ferry is on the right bank
                    ferry_bank = "right";
                }
            } else {
                // this is the case when the ferry_bank is right
                // the procedure will be similar to above
                if(right_bank.front().arrival_time <= left_bank.front().arrival_time || right_bank.front().arrival_time <= time_flow) {
                // if(right_bank.front().arrival_time <= time_flow) {
                    // and a car arrives on this bank first
                    car first_car = right_bank.front();
                    // if the ferry was waiting for another car
                    if(time_flow < first_car.arrival_time) time_flow = first_car.arrival_time;
                    // therefore time at which the car is loaded will be equal to the time_flow
                    for(int i=0; i<n && !right_bank.empty() && right_bank.front().arrival_time<= time_flow ; i++ ){
                        //cout<<time_flow + t<<endl;
                        unload_time[ right_bank.front().car_num ] = time_flow+t;
                        right_bank.pop();
                    }

                    time_flow += t;
                    ferry_bank = "left";

                } else {
                    // car arrives on the other bank first
                    if(time_flow <= left_bank.front().arrival_time) time_flow = left_bank.front().arrival_time+t;
                    else time_flow+=t;
                    ferry_bank = "left";
                }

            }
        }

        // if we reach this point that means anyone of the bank will have no car
        // first considering the case of the left bank
        while(!left_bank.empty()) {
            //if ferry is already at the left bank
            if(ferry_bank == "left") {
                car first_car = left_bank.front();
                // if the ferry was waiting for the car : update the time_flow
                if(time_flow < first_car.arrival_time) time_flow = first_car.arrival_time;
                // if the above is not the case that means ferry is on the other bank and coming towards this bank
                // in that interval the car arrives in this bank

                // therefore time at which car is loaded will be equal to time_flow
                for(int i=0; i<n && !left_bank.empty() && left_bank.front().arrival_time <= time_flow ; i++) {
                    //cout<<time_flow + t<<endl;
                    unload_time[ left_bank.front().car_num ] = time_flow+t;
                    left_bank.pop();
                }
                // after reaching at the left bank :
                // update the time_flow to the time at which the car is unloaded from the ferry
                time_flow += t;
                // and the ferry_bank is now right
                ferry_bank = "right";

            } else {
                // ferry is on the right bank: need to go to the left bank
                // therefore the time_flow will be updated to time of arrival of the car on the left bank plus the time of crossing the river
                if(time_flow <= left_bank.front().arrival_time) time_flow = left_bank.front().arrival_time + t;
                else time_flow+=t;
                // ferry reached at the left bank
                ferry_bank = "left";
            }
        }

        // now considering the case of the right bank
        while(!right_bank.empty()){
            if(ferry_bank == "right") {
                car first_car = right_bank.front();

                // if the ferry was waiting for another car
                if(time_flow < first_car.arrival_time) time_flow = first_car.arrival_time;
                // therefore time at which the car is loaded will be equal to the time_flow
                for(int i=0; i<n && !right_bank.empty() && right_bank.front().arrival_time<= time_flow ; i++ ){
                    // cout<<time_flow + t<<endl;
                    unload_time[ right_bank.front().car_num ] = time_flow+t;
                    right_bank.pop();
                }

                time_flow += t;
                ferry_bank = "left";
            } else {
                // ferry was on the other bank : need to go the right bank
                if(time_flow <= right_bank.front().arrival_time) time_flow = right_bank.front().arrival_time + t;
                else time_flow+=t;
                ferry_bank = "right";
            }
        }
        for(auto &i : unload_time) {
            cout<<i<<endl;
        }
        if(c) cout<<endl;
    }
    return 0;
}
