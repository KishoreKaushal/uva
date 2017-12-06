#include<bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

bool splitString(string s, string &a , string &b , string delim) {
    int pos= s.find(delim);
    if(pos!= string::npos) {
        a = string(s.begin() , s.begin()+pos) ;
        b = string(s.begin()+pos+1 , s.end());
        return true;
    } return false;
}

int main(){
    string Time;
    string H, M;
    int h, m , degHr=30, degMin=6;
    float angleDiff=0.0 , hrAngle, minAngle;
    cout<<std::fixed<<std::setprecision(3);
    cin>>Time;
    do {
        splitString(Time, H, M, ":");
        h = stoi(H);
        m = stoi(M);
        hrAngle = (degHr*h+0.5*m);
        if(hrAngle > 360 - 1e-3) {
            hrAngle -=360;
        }
        
        minAngle = (degMin*m)%360;
        if(abs(minAngle-hrAngle) <= 180+1e-3){
            cout<<abs(minAngle-hrAngle)<<endl;
        } else cout<<360.000-abs(minAngle-hrAngle)<<endl;
        cin>>Time;
    } while(Time!="0:00"&& !cin.eof());

    return 0;
}
