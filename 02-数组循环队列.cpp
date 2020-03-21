#include <cstdio>
using Position=int;
struct QNode{
    int* Data;
    Position Front, Rear;
    int Maxsize;

};
using Queue=struct QNode*;
//创建队列
Queue CreatQueue(int Maxsize){
    Queue Q=new QNode;
    Q->Data=new int[Maxsize];
    Q->Maxsize=Maxsize;
    Q->Front=Q->Rear=0;
    return Q;
}
//判空
bool IsEmpty(Queue Q){
    return Q->Front==Q->Rear;
}
//判满
bool IsFull(Queue Q){
    return (Q->Rear+1)%Q->Maxsize==Q->Front;
}
//入队
bool AddQ(Queue Q,int X){
    if(IsFull(Q)){
        printf("Full\n");
        return false;
    }
    else{
        Q->Rear=(Q->Rear+1)%Q->Maxsize;
        Q->Data[Q->Rear]=X;
    }
}
//出队
constexpr auto ERROR=-1;
int DeleteQ(Queue Q){
    if(IsEmpty){
        printf("Empty\n");
        return ERROR;
    }
    else{
        Q->Front=(Q->Front+1)%Q->Maxsize;
        return Q->Data[Q->Front];
    }
}
