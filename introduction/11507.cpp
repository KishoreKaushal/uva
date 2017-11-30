#include<bits/stdc++.h>
#include<string>

using namespace std;

// (+y) (+y) --> (-x)
// (+y) (-y) --> (+x)
// (+z) (-z) --> (+x)
// (+z) (+z) --> (-x)
// (-x) (+z) --> (-z)
// (-x) (-z) --> (+z)
// (-x) (+y) --> (-y)
// (-x) (-y) --> (+y)
// (-z) (-z) --> (-x)
// (-y) (-y) --> (-y)
// (+x) (anything) --> (anything)

int main(){
    int t ;
    string delimiter = " " , s;
    string currentState;
    string token ;
    int pos=0;
    (cin>>t).get();
    // cin>>t;
    do {
        currentState="+x"; // initially the final segment is in the +x direction
        while(--t){
            cin>>token;
            // carry the operation of the bending
            if(currentState=="+x" && token!="No")  currentState = token;
            else if(currentState=="+y" && token=="+y") currentState = "-x";
            else if((currentState=="+y" && token=="-y")||(currentState=="-y" && token=="+y"))   currentState = "+x";
            else if((currentState=="+z" && token=="-z")||(currentState=="-z" && token=="+z"))   currentState = "+x";
            else if(currentState=="+z" && token=="+z")  currentState = "-x";
            else if(currentState=="-x" && token=="+z")  currentState = "-z";
            else if(currentState=="-x" && token=="-z")  currentState = "+z";
            else if(currentState=="-x" && token=="+y")  currentState = "-y";
            else if(currentState=="-x" && token=="-y")  currentState = "+y";
            else if ((currentState=="-z" && token=="-z")||(currentState=="-y" && token=="-y"))
            currentState = "-x";
            else continue;
        }
        cout<<currentState<<endl;
        (cin>>t).get();
    } while (t!=0);
    return 0;
}
