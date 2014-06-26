#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string num[10005];
char tmp[15];

int main(){

    int t,n;
    bool prefix;
    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",tmp);
            num[i]=tmp;
        }

        //sort the strings lexicographically
        sort(num,num+n);
        //After the lexicographical sorting you just have to check the adjacent strings for prefix

        for(int i=0;i<n-1;i++){
                prefix=true;

            //if all the characters match then it is a prefix
            for(int j=0;j<num[i].length();j++){
                if(num[i][j]!=num[i+1][j])
                prefix=false;
            }

           if(prefix==true){
            break;
           }
        }

        //if any no. was prefix of another list is not consistent
        if(prefix==true)
            printf("NO\n");
        else
            printf("YES\n");

    }

}
