#include<stdio.h>
#include<iostream>
using namespace std;

 int josephus[1000000+5];
int main(){
        int N,D,W;

    while(1){
        scanf("%d %d",&N,&D);
        if(N==0&&D==0)
            return 0;

        josephus[1]=1;
        for(int i=2;i<=N;i++){
            josephus[i]=(josephus[i-1]+D-1)%i+1;
        }

        printf("%d %d %d\n",N,D,josephus[N]);
    }
}
