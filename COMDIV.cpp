#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
bool is_prime[1000005];

int comdiv(int gdiv){
    int ans=1,counti=0,temp;
    for(int i=2;i<=gdiv;i++){
        if(is_prime[i]==true){
            temp=i;
            counti=0;

            while(gdiv%temp==0 ){
                counti++;
                temp=temp*i;
            }
            ans=ans*(counti+1);
        }
    }
    return ans;
}

int gcd(int a,int b){
    if(b==0)
        return a;

    return gcd(b,a%b);
}

int main(){
    int t,a,b;
    scanf("%d",&t);

    for(int i=1;i<1000005;i++)
        is_prime[i]=true;

    is_prime[1]=false;
    is_prime[2]=true;
    for(int i=2;i*i<1000005;i++){
        if(is_prime[i]){
            for(int j=i*2;j<1000005;j=j+i)
                is_prime[j]=false;
        }
    }

    while(t--){
        scanf("%d %d",&a,&b);
        printf("%d\n",comdiv(gcd(a,b)));
    }
}
