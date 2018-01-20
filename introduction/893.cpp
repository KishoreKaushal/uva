#include<bits/stdc++.h>
using namespace std;

/*
Leap years are all years divisible by 4 and not divisible by 100, except
for those divisible by 400.
Thus 1900 was not a leap year, 1904, 1908 ... 1996 were leap years,
2000 will be a leap year, 2100 will not be a leap year, etc.
*/

static const long long int num_days[12] = {31, 28, 31, 30, 31 , 30, 31, 31, 30, 31, 30, 31};
static const long long int leap_num_days[12] = {31, 29, 31, 30, 31 , 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(long long int yy) {
    return ((yy%4==0 && yy%100!=0) || (yy%400 == 0)) ;
}

// 1-1-1998 : day 0
long long int months_to_days(long long int mm , long long int yy){
    long long int days=0;
    if(is_leap_year(yy))
        for(long long int M=1 ; M<mm; ++M) {
            days+=leap_num_days[M-1];
        }
    else
        for(long long int M=1 ; M<mm; ++M) {
            days+=num_days[M-1];
        }
    return days;
}

int year_to_days(long long int yy) {
    long long int days=0;
    for(long long int Y=1998; Y<yy ; ++Y) {
        days+=365;
        if(is_leap_year(Y))
            ++days;
    }
    return days;
}

long long int days_to_year(long long int &d) {
    long long int days=d;
    long long int Y=1998;
    for(Y=1998; days>365 ; ++Y) {
        days-=365;
        if(days>=1 && is_leap_year(Y))
            --days;
    }
    d = days;
    return Y;
}

long long int days_to_months(long long int &d , long long int yy) {
    long long int days=d;
    long long int M=1;
    if(is_leap_year(yy)){
        while(days>leap_num_days[M-1]){
            days-=leap_num_days[M-1];
            ++M;
        }
    } else {
        while(days>num_days[M-1]){
            days-=num_days[M-1];
            ++M;
        }
    }
    d = days;
    return M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    long long int D;
    long long int DD , MM , YY;
    long long int total_days;

    while(cin>>D>>DD>>MM>>YY , D||DD||MM||YY) {
        total_days = DD;
        total_days+=year_to_days(YY);
        total_days+=months_to_days(MM , YY);
        total_days+=D;

        // cout<<"Year To days: "<<year_to_days(YY)<<endl;
        // cout<<"Months To days: "<<months_to_days(MM , YY)<<endl;
        // cout<<"total_days: "<<total_days<<endl;

        // cout<<"days to years: "<<days_to_year(total_days)<<endl;
        // cout<<"days left: "<<total_days<<endl;
        // cout<<"days to months : "<<days_to_months(total_days , YY)<<endl;
        // cout<<"days left: "<<total_days<<endl;

        YY = days_to_year(total_days);
        MM = days_to_months(total_days , YY);
        DD = total_days;
        if(DD!=0) cout<<DD<<" "<<MM<<" "<<YY<<endl;
        else {
            if(MM-1 == 0) {
                MM = 12;
                --YY;
                DD = 31;
            } else {
                --MM;
                if(is_leap_year(YY)){
                    DD = leap_num_days[MM-1];
                }
            }
            cout<<DD<<" "<<MM<<" "<<YY<<endl;
        }
    }

    return 0;
}
