#include<stdio.h>
#include<iostream>
using namespace std;
int main(){

    int testcase,N,K,T,F,x;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d %d %d %d",&N,&K,&T,&F);
        if(F<=K*N){
            x=(F-N)/(K-1);
            printf("%d\n",x+F);
        }
        else{

            x=(F-N)/(K-1);
            printf("%d\n",x+F);
        }



    }


}
