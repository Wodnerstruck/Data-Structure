#include <cstdio>
using PtrToNode=struct SNode*;
using Stack=PtrToNode;
struct SNode{
    int Data;
    PtrToNode Next;
};
//新建空堆栈
Stack CreatStack(){
    Stack S=new SNode;
    S->Next=NULL;
    return S;
}
//判空
bool IsEmpty(Stack S){
    return (S->Next==NULL);
    }
//压栈
bool Push(Stack S,int X){
    PtrToNode tmpCell=new SNode;
    tmpCell->Data=X;
    tmpCell->Next=S->Next;
    S->Next=tmpCell;
    return true;
}
//出栈
constexpr auto ERROR=-1;
int Pop(Stack S){
    PtrToNode firstCell;
    int TopData;
    if(IsEmpty(S)){
        printf("Empty\n");
        return ERROR;
    }
    else{
        firstCell=S->Next;
        TopData=firstCell->Data;
        S->Next=firstCell->Next;
        delete firstCell;
        return TopData;
    }
}

