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
            if(ThisSum>MaxSum){//>条件可以保证两子列和相等时输出前面的子列，但漏掉了子列只有0最大子列和为0的情况
                MaxSum=ThisSum;
                end=seq[i];
                head=seq[i-Count+1];//得到更大的子列和时一定要更新列首列尾
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