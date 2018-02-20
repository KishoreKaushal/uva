#include<iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int tmp{N} , used{0} ;
    while(tmp) {
        used |= (1 << (tmp%10));
        tmp /= 10;
    }

    if(used == (1<<10) -1) {
        cout<<"All digits Used"<<endl;
    } else cout<<"Not all digits are used"<<endl;
    return 0;
}
