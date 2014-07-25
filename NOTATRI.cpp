#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int L[20005];

//TIME COMPLEXITY O(N^2)
int main(){
    int N;


    while(true){
         scanf("%d",&N);
        if(N==0)
        return 0;
        for(int i=0;i<N;i++)
            scanf("%d",&L[i]);
        sort(L,L+N);

        int j,k,ans=0;
        for(int i=N-1;i>1;--i){
            j=0;k=i-1;
            while(j<k){
                while(j<k && L[j]+L[k]>=L[i])
                    --k;
                ans+=k-j;
                ++j;
            }

        }
        printf("%d\n",ans);



    }


}
