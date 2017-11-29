#include<bits/stdc++.h>

using namespace std;

int main(){
    int n , p , r , num=0, maxR;
    float d , minPrice;
    char clearBuff;
    char buff[90] , pName[90] , temp[90];
    while (scanf(" %d %d", &n , &p) && (n||p)) {
        num++;
        if(n==0) break;
        else {
            // take input of the all the requirements in a buff variable
            for (int b=0; b<n; b++) scanf(" %80[^\n]s" ,buff);

            // take input of each proposal
            scanf("%c", &clearBuff);
            scanf("%80[^\n]s", pName);
            //takeStringInput(pName , 80);
            scanf(" %f %d", &minPrice , &maxR);
            for (int b=0; b<maxR; b++) scanf(" %80[^\n]s" ,buff);
            p--;

            while (p--) {
                scanf("%c", &clearBuff);
                scanf("%80[^\n]s", temp);
                //takeStringInput(temp , 80);
                scanf(" %f %d", &d , &r);
                for (int b=0; b<r; b++) scanf(" %80[^\n]s" ,buff);
                if((r>maxR) || (r==maxR && (minPrice - d)>1e-3)) {
                    //printf("%f %f %f\n",minPrice , d, (minPrice - d) );
                    strcpy(pName , temp);
                    maxR = r;
                    minPrice = d;
                }
            }

            // print the result
            if(num>1) printf("\n");
            printf("RFP #%d\n%s\n", num , pName);
        }
    }
    return 0;
}
