#include<bits/stdc++.h>
using namespace std;

class SHEET{
public:
    int FL , FR , BL, BR ;
    SHEET(int fl=0 , int fr=0, int bl=0, int br=0){
        FL = fl;
        FR = fr;
        BL = bl;
        BR = br;
    }
};

int main(int argc, char const *argv[]) {
    int t, pgCount;
    cin>>t;
    do{
        int pgReq = (t%4==0)?(t/4):((t/4)+1) ;
        //cout<<"Page Required : "<<pgReq<<endl;
        vector <SHEET> sheet(pgReq);
        pgCount = 1;
        for(int i=0; i<pgReq ;i++ ){
            sheet[i].FR = pgCount++;
            if(pgCount<=t) sheet[i].BL = pgCount++;
        }
        for(int i=pgReq-1 ; i>=0 && pgCount<=t ; i-- ) {
            sheet[i].BR = pgCount++;
            if(pgCount<=t) sheet[i].FL = pgCount++;
        }
        cout<<"Printing order for "<<t<<" pages:"<<endl;

        for(int i=0; i<pgReq; i++) {
            cout<<"Sheet "<<i+1<<", front: ";
            if(sheet[i].FL==0) cout<<"Blank, "<<sheet[i].FR<<endl;
            else cout<<sheet[i].FL<<", "<<sheet[i].FR<<endl;

            if(sheet[i].BL != 0) {
                cout<<"Sheet "<<i+1<<", back : ";
                cout<<sheet[i].BL<<", ";
                if(sheet[i].BR != 0) cout<<sheet[i].BR<<endl;
                else cout<<"Blank"<<endl;
            }
        }
        sheet.clear();
        cin>>t;
    } while(t!=0);
    return 0;
}
