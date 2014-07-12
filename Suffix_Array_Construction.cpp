#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX_LENGTH 1000000
using namespace std;

//_____________________________________________________________________________________
//original_index : it is the index of the suffix Initially that is before any sorting.
//--------------------------------------------------------------------------------------

//at first step suffixes will we sorted based on first 2 characters
//at second step suffixes will be sorted based on first 4 characters
//similarly ,In later steps on basis of 8,16..... characters until the no. of characters consider are less than n


//after each step suffixes with same prefix will be adjacent so, a kind of groups will be formed lets call these groups buckets
//After ith step each buckets will have property that initial 2^i characters of each suffix belonging to the same buckets are same

//__________________________________________________________________________________________________________________________________
//rank[0] : it will denote the bucket no. that is to which bucket the suffix belongs based on the current considered initial characters
//--------------------------------------------------------------------------------------------------------------------------------------

// Procedure to move from K th step to (K+1)th step
// as we are on Kth step we have sort the suffixes based on initial 2^K characters
// to move to K+1 th step we will combine the result at index (i) and (i+2^K) this can be done easily in O(1) because we already
// know the result of suffix at index (i+2^k) so the combined result will sort the suffixes bases on 2^(K+1) initial characters ,because we have used the result
// at ith index with 2^k characters and i+1th index with 2^k characters.


//_____________________________________________________________________________________________________________________________________
//rank[1] : will denote the bucket no. of the next set of characters (for example as explained above rank[1] will contain the bucket no. of suffix at index i+2^K)
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

//after each step buckets will increase and will stop when each bucket has only one element(suffix)


//it will contain the index of suffixes in sorted order
int pos[MAX_LENGTH+1];
char str[MAX_LENGTH+1];


//start SUFFIX ARRAY SORT code///////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct suffix{
    int original_index;
    int rank[2];
};
struct suffix suffixes[MAX_LENGTH+1];

int cmp(struct suffix  a,struct suffix b){
    return (a.rank[0]==b.rank[0]) ? (a.rank[1] <b.rank[1] ? 1:0 ) : (a.rank[0]<b.rank[0] ? 1: 0);
}

int Build_suffix_array(int len){
  //sort based on first two characters/////
    for(int i=0;i<len;i++){
        suffixes[i].original_index=i;
        suffixes[i].rank[0]= str[i]-'A';
        suffixes[i].rank[1]= (i+1)<len ? (str[i+1]-'A') : -1;
    }
    sort(suffixes,suffixes+len,cmp);

   ///////////////////////////////////////

    int ind[len+1];
    for(int k=4;k<2*len ;k=k*2){

        int rank=0;
        int prev_rank=suffixes[0].rank[0];
        suffixes[0].rank[0]=rank;
        ind[suffixes[0].original_index] = 0;
        int startAt,endsAt;

        for(int i=1;i<len;i++){
                 prev_rank=suffixes[i].rank[0];
            if(suffixes[i].rank[0]==prev_rank && suffixes[i].rank[1]==suffixes[i-1].rank[1]){
                suffixes[i].rank[0]=rank;
            }
            else{
                suffixes[i].rank[0]=++rank;
            }
            ind[suffixes[i].original_index]=i;
        }


        for(int i=0;i<len;i++){
            int nextindex = suffixes[i].original_index + k/2;
            suffixes[i].rank[1] = (nextindex < len)?
                                  suffixes[ind[nextindex]].rank[0]: -1;
        }


        for(int i=0;i<len;i++){
            /////////////////////////////////////////////////////////////
            //This trick made my day////////////////
            endsAt=startAt=i;
                ++i;
            while(i<len && suffixes[i].rank[0]==suffixes[i-1].rank[0])
                ++i;
                --i;
            endsAt=i;
           sort(suffixes+startAt,suffixes+endsAt+1,cmp);
           /////////////////////////////////////////////////////////
           //DETAILS: what is happening is we are sorting elements of each bucket individually this little tricks improved the performance.

        }
        //sort(suffixes,suffixes+len,cmp);
    }


    for(int i=0;i<len;i++){
        pos[i]=suffixes[i].original_index;
    }
}
 //end SUFFIX ARRAY SORT code///////////////////////////////////////////////////////////////////////////////////////////////////////////



//start LCP code////////////////////////////////////////////////////////////////////////////////////////////
int height[MAX_LENGTH+1];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
void LCP(int len){
    int rankOf[len];
    for (int i=0; i<len; ++i)
        rankOf[pos[i]] = i;
    height[0] = 0;
    for (int i=0, h=0; i<len; ++i){
        if (rankOf[i] > 0){
            int j = pos[rankOf[i]-1];
            while (i + h < len && j + h < len && str[i+h] == str[j+h]) h++;
                height[rankOf[i]] = h;
            if (h > 0)
            h--;
    }
  }
}
//end LCP code////////////////////////////////////////////////////////////////////////////////////////////////


int main(){
    int len;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        len=strlen(str);
        Build_suffix_array(len);

        LCP(len);

/*
        for(int i=0;i<len;i++){
            printf("%s %d\n",str+pos[i],height[i]);
        }
*/

        //http://www.quora.com/Programming-Interviews/Given-a-string-how-do-I-find-the-number-of-distinct-substrings-of-the-string
        int ans=len-pos[0];
        for(int i=1;i<len;i++){
            ans=ans+( (len-pos[i]) - height[i] );
        }
        printf("%d\n",ans);
    }
}
