#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define REP(i, a, b) for(int i = int(a) ; i < int(b) ; i++ )

void createList(list<int> &A , int N){
    for(int i=1; i<=N ; i++ ){
            A.push_back(i);
    }
}

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input");
    //ofstream cout("output");
    list<int> A , B, C;
    stack<int> S;
    int n , N;
    bool possible, found;
    cin>>N;
    do {
        // train before reaching at station
        while(1){
            possible = true;
            A.clear();
            B.clear();
            C.clear();
            while(!S.empty())   S.pop();
            createList(A , N);
            //cout<<A<<endl;
            // one by one trying to create the list B , if it can be made then its possible else its not

            cin>>n;
            if(n==0) break;
            B.push_back(n);
            for(int i=1; i<N; i++)  { cin>>n; B.push_back(n); }
            //cout<<B<<B.front()<<endl;

            while(!B.empty() && possible ) {
                if(!S.empty() && (S.top()==B.front())) {
                    C.push_back(B.front());
                    B.pop_front();
                    S.pop();
                } else if(S.empty() || (!S.empty()&&(S.top()!=B.front()))) {
                    found = false;
                    while(!A.empty()) {
                        if(A.front() == B.front()){
                            found = true;
                            C.push_back(B.front());
                            B.pop_front();
                            A.pop_front();
                            break;
                        }
                        else if(!A.empty()){
                            S.push(A.front());
                            A.pop_front();
                        }
                    }
                    if(!found) possible = false;
                }
            }
            //cout<<C<<endl;
            if(possible) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        cin>>N;
        cout<<endl;
    }while(N);


    return 0;
}
