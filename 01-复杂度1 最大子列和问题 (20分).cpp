#include <cstdio>
int Seq[100010];
int main(){
    int ThisSum=0,MaxSum=0,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&Seq[i]);
    }
    for(int i=0;i<n;i++){
        ThisSum+=Seq[i];
        if(ThisSum>=MaxSum) 
        MaxSum=ThisSum;
        else if(ThisSum<0)
        ThisSum=0;
    }
    printf("%d\n",MaxSum);
}
