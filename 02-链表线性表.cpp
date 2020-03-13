#include <cstdio>
using PtrToNode=struct LNode*;
struct LNode{
    int Data;
    PtrToNode Next;
};

using Position=PtrToNode;
using List=PtrToNode;
//查找
Position Find(List L,int X){
    Position p=L;
    while(p&&p->Data!=X)
    p=p->Next;
    return p;
}
//新建空表
List Empty(){
    List L=new LNode;
    L->Next=NULL;
    return L;
}
//带头结点的插入
bool Insert(List L,int X,Position P){
    //默认L有头结点
    Position tmp, pre;
    //查找P的前一个结点
    for(pre=L;pre&&pre->Next!=P;pre=pre->Next);//不需要额外操作
        if(pre==NULL){
            printf("Insert Postion Error\n");
            return false;
        }
        else{
            tmp=new LNode;
            tmp->Data=X;
            tmp->Next=pre->Next;
            pre->Next=tmp;
            return true;
        
    }
}
//带头结点的删除
bool Delete(List L,Position P){
    Position pre;
    for(pre=L;pre&&pre->Next!=P;pre=pre->Next);
    if(pre==NULL||P==NULL){
        printf("Positon Error\n");
        return false;
    }
    else{
        pre->Next=P->Next;
        delete P;
        return true;
    }
}

