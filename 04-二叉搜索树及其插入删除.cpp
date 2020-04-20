#include <cstdio>
using BinTree = struct TreeNode*;
struct TreeNode{
    int Data;
    BinTree Left,Right;

};
//Insert
BinTree Insert(BinTree BST,int X)
{
    if(!BST){
        BST = new TreeNode;
        BST->Data = X;
        BST->Left = BST->Right = nullptr;
    }   
    else{
        if(X<BST->Data)
            BST->Left = Insert(BST->Left,X);
        else if(X>BST->Data)
            BST->Right = Insert(BST->Right,X);
    } 
    return BST;
}
//Delete
BinTree Delete(BinTree BST,int X)
{
    BinTree Tmp;
    if(!BST){
        printf("Can't find it!");
    }
    else{
        if(X<BST->Data)
            BST->Left = Delete(BST->Left,X);
        else if(X>BST->Data)
            BST->Right = Delete(BST->Right,X);
            else{
                if(BST->Left&&BST->Right){
                    Tmp = FindMin(BST->Right);
                    BST->Data = Tmp->Data;
                    BST->Right = Delete(BST->Right,BST->Data);
                }
                else{
                    Tmp = BST;
                    if(!BST->Left)//如果左子树为空或两边都空
                        BST = BST->Right;
                    else//如果左子树不空
                        BST = BST->Left;
                    delete Tmp;
                    
                }
            }
    }
    return BST;
}

//FindMin in Right SubTree
BinTree FindMin(BinTree BST){
    while(BST->Left){
        BST = BST->Left;
    }
    return BST;
}