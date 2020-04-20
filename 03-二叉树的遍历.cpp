#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
using BinTree = struct TreeNode*;
using Position = BinTree;
struct TreeNode{
    int Data;
    BinTree Left;
    BinTree Right;
};
//递归先序遍历
void PreOrderTraversal(BinTree BT)
{
    if(BT) {
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}
//递归中序遍历
void InOrderTraversal(BinTree BT)
{
    if(BT) {
        PreOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Right);
    }
}
//递归后序遍历
void PostOrderTraversal(BinTree BT)
{
    if(BT) {
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}
//非递归先序遍历
void PreOrderTraversal_(BinTree BT)
{   
    BinTree T = BT;
    stack <BinTree> S;
    while(T||!S.empty()){
        while(T){
            printf("%d",T->Data);
            S.push(T);
            T = T->Left;
        }
        if(!S.empty()){
            T = S.top();
            S.pop();
            T = T->Right;
        }
    }
}

//非递归中序遍历
void InOrderTraversal_(BinTree BT)
{   
    BinTree T = BT;
    stack <BinTree> S;
    while(T||!S.empty()){
        while(T){
            S.push(T);
            T = T->Left;
        }
        if(!S.empty()){
            T = S.top();
            S.pop();
            printf("%d",T->Data);
            T = T->Right;
        }
    }
}
//非递归后序遍历
void PostOrder_(BinTree BT)
{
    BinTree T = BT;
    BinTree LT = nullptr;
    stack <BinTree> S;
    while(T||!S.empty()){
        while(T){
            S.push(T);
            T = T->Left;
        }
        if(!S.empty()){
            T = S.top();
            S.pop();
            if(!T->Right||T == LT){
                LT  = T;
                printf("%d",T->Data);
            }
            else{
                S.push(T);
                T = T->Right;
            }
        }
    }
}
//层序遍历
void LevelOrderTraversal(BinTree BT){
    BinTree T = BT;
    queue <BinTree> Q;
    Q.push(T);
    while(!Q.empty()){
        T = Q.front();
        printf("%d",T->Data);
        Q.pop();
        Q.push(T->Left);
        Q.push(T->Right);
    }

}
