#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;



/* this function calculates (a*b)%c taking into account that a*b might overflow */
long long int mulmod(long long int a,long long int b,long long int c){
    long long int x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
/* This function calculates (a^b)%c */
long long int  modulo(long long int a,long long int b,long long int c){
    long long int x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=mulmod(x,y,c);
        }
        y = mulmod(y,y,c); // squaring the base
        b /= 2;
    }
    return x%c;
}

/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(long long int p,long long int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long int s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long int a=rand()%(p-1)+1,temp=s;
        long long int mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int main(){

    int t;
    long long int N;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&N);

        if(Miller(N,10))
            printf("YES\n");
        else
            printf("NO\n");
    }
}
