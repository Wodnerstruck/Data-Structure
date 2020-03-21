#include <cstdio>
constexpr int MAXSIZE=100;
using Position=int;
using List=struct LNode*;
struct LNode{
    int Data[MAXSIZE];
    Position Last;
};
//空表
List MakeEmpty()
{
    List L;
    L=new LNode;
    L->Last=-1;
}
//查找
constexpr int ERROR=-1;
Position Find(List L,int X)
{
    Position i=0;
    while(i<=L->Last&&L->Data[i]!=X)
    i++;
    if(i>L->Last) return ERROR;
    else return i;

}
//插入
bool Insert(List L,int X,Position P)
{
    if(L->Last==MAXSIZE-1){
        printf("Full List\n");
        return false;
    }
    if(P<0||P>L->Last+1){
        printf("OverRange\n");
        return false;
    }
    for(int i=L->Last;i>=P;i--){
        L->Data[i+1]=L->Data[i];
    }
    L->Data[P]=X;
    L->Last++;
    return true;
}
//删除
bool Delete(List L,Position P){
    if(P<0||P>L->Last){//P与Last比较可以判别查找位置是否合法，也可判别是否空表
        
        printf("Error\n");
        return false;
    }
    for(int i=P;i<L->Last;i++){
        L->Data[i]=L->Data[i+1];
    }
    L->Last--;
    return true;
}

