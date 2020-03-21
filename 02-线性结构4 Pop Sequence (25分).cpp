#include <cstdio>
//不用stack，自写堆栈
using Stack=SNode*;
struct SNode{
    int* Data;
    int Top;
    int Maxsize;
};
//创建
Stack CreateStack(int Maxsize){
    Stack S=new SNode;
    S->Top=-1;
    S->Data=new int[Maxsize];
    S->Maxsize=Maxsize;
    return S;
}
//入栈
bool Push(Stack S,int X){
    if(S->Top==S->Maxsize-1)
       { return false;}
    S->Data[++(S->Top)]=X;
    return true;
}
//出栈
void Pop(Stack S){//此题不用输出栈顶元素，只用对Top操作即可
    if(S->Top!=-1)
    S->Top--;
}
int main(){
    int seq[1010];
    int M,N,K;
    scanf("%d%d%d",&M,&N,&K);
    for(int i=0;i<K;i++){
        for(int i=0;i<N;i++)
            scanf("%d",&seq[i]);
        Stack S=CreateStack(M);
        int count=0;
        for(int i=1;i<=N;i++){//从1开始不从0，因为Push的元素从1开始
            if(!Push(S,i)){//堆栈满退出
                break;
            }
            while(S->Top!=-1&&S->Data[S->Top]==seq[count]){//push的元素与序列开始的元素相等时才pop并对比序列下一个
                Pop(S);
                count++;
            }
        }
        if(count==N) printf("YES\n");
        else printf("NO\n");
    }

}