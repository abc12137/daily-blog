#include<stdio.h>
int main() {
        int n; 
        int count=0;
        int cur,high,low;
        printf("please input n \n");
        scanf("%d",&n);
        long long i=1;
        while(i<=n){
         cur=(n/i)%10;
         high=n/(10*i);
         low=n%i;
         if(cur==0){
              count+=high*i;
           }  else if(cur==1){
                 count+=high*i+low+1;
              }  else{                    //9>cur>=2
                     count+=(high+1)*i;
                   }
          i=i*10;
        }
    printf("%d",count);
}