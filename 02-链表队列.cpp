#include <cstdio>
using PtrToNode=struct Node*;
using Position=PtrToNode;
struct Node{
    int Data;
    PtrToNode Next;
};
struct QNode{
    Position Front,Rear;
    int Maxsize;
};
using Queue=struct QNode*;

//创建空队列
Queue CreatQueue(int Maxsize){
    Queue Q=new QNode;
    Q->Front=Q->Rear=nullptr;
    Q->Maxsize=Maxsize;
}
//判空
bool IsEmpty(Queue Q){
    return Q->Front==nullptr;
}
//出队
constexpr auto ERROR=-1;
int DeleteQ(Queue Q){
    PtrToNode FrontCell;
    int FrontData;
    if(IsEmpty(Q)){
        printf("Empty\n");
        return ERROR;
    }
    else{
        FrontCell=Q->Front;
        Q->Front=FrontCell->Next;
        FrontData=FrontCell->Data;
        delete FrontCell;
        return FrontData;
    }
}
//判满
bool IsFull(Queue Q){
    PtrToNode P=Q->Front;
    int count=0;
    while(P){
        count++;
        P=P->Next;
    }
    return count==Q->Maxsize;
}
//入队
void AddQ(Queue Q,int X){
    if(IsFull){
        return;
    }
    PtrToNode N=new Node;
    N->Data=X;
    N->Next=nullptr;
    if(IsEmpty){
        Q->Front=Q->Rear=N;
        return;
    }
    else{
        Q->Rear->Next=N;
        Q->Rear=N;
        return;
    }
}
