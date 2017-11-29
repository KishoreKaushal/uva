#include<bits/stdc++.h>
using namespace std;

// simulating snail
// increases by U feet a day
// decreases by D feet in night
// U decreses by a fatigue factor of F
// D remains Constant
// find at which day the snail will reach the top of the well or will again come back to the ground
// H is the height of the well

int main(){
    int H , D , F;
    float U, firstDayClimbDist;
    int day=0;
    float curH =0 , eps = 1e-6;
    while(scanf(" %d %f %d %d\n", &H , &firstDayClimbDist , &D , &F)!=EOF){
        U = firstDayClimbDist;
        curH = 0;
        day = 0;
        if(H==0) break;
        // else
        while (1) {
            day++;
            if (U>0){
                curH += U;
                if(H < curH) {
                    printf("success on day %d\n", day);
                    break;
                }
            }
            //printf("Day: %d   Height Day: %f   ", day ,curH );
            curH -= D;
            //printf("Height Night: %f ", curH );
            if( curH <0) {
                printf("failure on day %d\n" , day);
                break;
            }
            U -= (F*firstDayClimbDist/100) ;
            //printf(" U: %f\n", U);
        }
    }
    return 0;
}
