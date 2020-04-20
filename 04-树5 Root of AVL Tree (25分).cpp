//给出插入序列，返回AVL树的根结点
#include <cstdio>

typedef struct AVLNode* Position;
typedef Position AVLTree;
struct AVLNode{
    int Data;
    AVLTree Left,Right;
    int Height;
};
int Max(int a,int b){
    return a>b?a:b;
}
int GetHeight(AVLTree T){
    if(T)
        return T->Height;
    else 
        return -1;
}
//LLRotation
AVLTree SingleLeftRotation(AVLTree A){
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
//更新树高
    A->Height = Max(GetHeight(A->Left),GetHeight(A->Right)) + 1;
    return B;
}
//RRRotation
AVLTree SingleRightRotation(AVLTree A){
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
//更新树高
    A->Height = Max(GetHeight(A->Left),GetHeight(A->Right)) + 1;
    return B;
}
//L-RRotation
AVLTree LeftRightRotation(AVLTree A){
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}
//R-LRotation
AVLTree RightLeftRotation(AVLTree A){
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}
//AVLInsert
AVLTree Insert(AVLTree T,int X){
    if(!T){//空树则新建
        T = new AVLNode;
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = nullptr;
    }
    else if(X<T->Data){
        T->Left = Insert(T->Left,X);
    //如果需要左旋
        if(GetHeight(T->Left) - GetHeight(T->Right) == 2){
            if(X<T->Left->Data)
                T = SingleLeftRotation(T);
            else
                T = LeftRightRotation(T);
        }
    }
    else if(X>T->Data){
        T->Right = Insert(T->Right,X);
    //如果需要右旋
        if(GetHeight(T->Left) - GetHeight(T->Right) == -2){
            if(X>T->Right->Data)
                T = SingleRightRotation(T);
            else
                T = RightLeftRotation(T);
        }
    }
    T->Height = Max(GetHeight(T->Left),GetHeight(T->Right)) + 1;
    return T;
}

int main(){
    int N,data;
    AVLTree T = nullptr;
   // AVLTree Root；此处多加一个AVL树指针用于指向根结点会出现问题，因为Insert使用实参为T，与Root不一致
    scanf("%d",&N);

    for (int i = 0;i<N;i++){
        scanf("%d",&data);
        T = Insert(T,data);
    }
    printf("%d",T->Data);
    return 0;
}