#include<bits/stdc++.h>
using namespace std;

void CLEAR(stack <int> &stk , queue <int> &q , priority_queue <int> &pq_grt ){
    while(!stk.empty()) stk.pop();
    while(!q.empty())   q.pop();
    while(!pq_grt.empty())  pq_grt.pop();
}

int main(){
    stack <int> stk;
    queue <int> q;
    priority_queue <int> pq_grt;    // greatest element on top
    int n , type , num;
    bool isQueue , isStk , isPqGrt, isPq;

    cin>>n;
    while(!cin.eof()) {
        isPqGrt = isStk = isQueue = true;
        while(n--) {
            cin>>type>>num;
            if(type==1) {
                stk.push(num) ;
                q.push(num);
                pq_grt.push(num);
            } else {
                if(!stk.empty() && !q.empty() && !pq_grt.empty()){
                    if(isStk && num!=stk.top()) isStk = false;
                    if(isQueue && num!=q.front()) isQueue = false;
                    if(isPqGrt && num!=pq_grt.top()) isPqGrt = false;
                    stk.pop();
                    q.pop();
                    pq_grt.pop();
                } else {
                    isStk = isQueue = isPqGrt = false;
                }
            }
        }
        isPq = (isPqGrt);
        if((int(isStk) + int(isQueue) + int(isPq))>1) cout<<"not sure"<<endl;
        else if(!isStk && !isQueue && !isPq) cout<<"impossible"<<endl;
        else if(isPq) cout<<"priority queue"<<endl;
        else if(isStk) cout<<"stack"<<endl;
        else cout<<"queue"<<endl;
        CLEAR(stk , q, pq_grt);
        cin>>n;
    }
    return 0;
}
