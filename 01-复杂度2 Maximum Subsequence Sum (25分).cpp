#include <cstdio>
int seq[10010];
int main(){
    int n,ThisSum=0,MaxSum=0,PosiCount=0,Count=0;
    int head, end;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&seq[i]);
    }
    for (int i = 0; i < n; i++)
    {   
        if(seq[i]>=0) PosiCount++;
    }
    if(PosiCount==0){
        printf("0 %d %d",seq[0],seq[n-1]);
    }
    else{
        for(int i=0;i<n;i++){
            
            ThisSum+=seq[i];
            Count++;
            if(ThisSum>MaxSum){
                MaxSum=ThisSum;
                end=seq[i];
                head=seq[i-Count+1];
            }
            else if(ThisSum<0){
                ThisSum=0,Count=0;
            }
        }
        if(MaxSum==0)//留意一个0和全为负数的数列
            printf("0 0 0");
        
        else
        printf("%d %d %d",MaxSum,head,end);
    }
    return 0;  
}