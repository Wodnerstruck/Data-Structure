//解法1:先建树，后遍历
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
struct TreeNode{
    int Data;
    Tree Left = nullptr,Right = nullptr;
};
using Tree = struct TreeNode*;
vector <int> In;
vector <int> Pre;
//读入数据函数
void Read(int N){
    int data;
    string act;
    stack <int> S;
    for(int i = 0;i<N;i++){
        cin>>act;
        if(act == "Push"){
            cin>>data;
            S.push(data);
            Pre.push_back(data);
        }
        if (act == "Pop")
        {
            In.push_back(S.top());
            S.pop();
        }
        
    }
}
//建树
Tree BuildTree(int PreL,int PreR,int InL,int InR)
{
    if(PreL>PreR) return nullptr;
    Tree Root = new TreeNode;
    Root->Data = Pre[PreL];
    int k;
    for(k = InL;k<=InR;k++){
        if(In[k] == Pre[PreL]) break;
    }
    int NumLeft = k - InL;//左子树结点个数
    Root->Left = BuildTree(PreL+1,PreL+NumLeft,InL,k-1);//左边递归
    Root->Right = BuildTree(PreL+NumLeft+1,PreR,k+1,InR);//右边递归
    return Root;
}
//后序遍历
void PostTraversal(Tree BT,vector <int> &V){
    Tree T = BT;
    PostTraversal(T->Left,V);
    PostTraversal(T->Right,V);
    V.push_back(T->Data);

}
int main(){
    int N;
    vector <int> Res;
    scanf("%d",&N);
    Read(N);
    BuildTree(0,N-1,0,N-1);
    for(int i = 0;i<N;i++){
        if(i!=N-1){
            printf("%d ",Res[i]);
        }
        else {
            printf("%d",Res[i]);
        }
    }
    return 0;
}