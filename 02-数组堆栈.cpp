#include <cstdio>
using Position=int;

struct SNode{
    int* Data;
    Position Top;
    int Maxsize;
};
using Stack= struct SNode*;
//创建空堆栈
Stack CreatStack(int Maxsize){
    Stack S=new SNode;
    S->Top=-1;
    S->Data=new int[Maxsize];
    S->Maxsize=Maxsize;
    return S;
}
//压入
bool Push(Stack S,int X){
    if(S->Top==S->Maxsize-1){
        printf("Full\n");
        return false;
    }
    S->Data[++(S->Top)]=X;
    return true;
}
//弹出
constexpr int ERROR=-1;
int Pop(Stack S){
    if(S->Top==-1){
        printf("Empty\n");
        return ERROR;
    }
    return S->Data[(S->Top)--];

}
//或者附加判空判满函数
bool IsEmpty(Stack S){
    if(S->Top==-1) return true;
    else return false;
}
bool IsFull(Stack S){
    if(S->Top==S->Maxsize-1)return true;
    else return false;
}
