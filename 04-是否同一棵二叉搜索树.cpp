#include <cstdio>
using Tree = struct TreeNode*;
struct TreeNode{
    int v;
    Tree Left,Right;
    int flag;
};
Tree NewNode(int V){
    Tree T = new TreeNode;
    T->v = V;
    T->Left = T->Right = nullptr;
    T->flag = 0;
    return T;
}
Tree Insert(Tree T,int V){
    if(!T) T = NewNode(V);
    else{
        if(V>T->v)
        T->Right = Insert(T->Right,V);
        else
        T->Left = Insert(T->Left,V);      
    }
    return T;
}
Tree MakeTree(int N){
    Tree T;
    int i,V;
    scanf("%d",&V);
    T = NewNode(V);
    for(i = 1;i<N;i++){
        scanf("%d",&V);
        T = Insert(T,V);
    }
    return T;
}


int check(Tree T,int V){
    if(T->flag){//如果为1，表示已访问过
        if(V<T->v) return check(T->Left,V);
        else if (V>T->v) return check(T->Right,V);
        else return 0;//如果V与v还相等，则等于出现了两次，这个序列与树不一致
    }
    else{//如果没有访问过
        if(V == T->v){//如果等于则访问并置T->flag 为 1，返回1
            T->flag = 1;
            return 1;
        }
        else return 0;//否则树不一致，返回 0 
    }
}
int Judge(Tree T,int N){
    int i,V,flag = 0;//为0代表一致，为1代表不一致（此处flag作为返回值的标记，当不一致时需要将序列读完再返回
    scanf("%d",&V);
    if(V!=T->v) flag = 1;//第一个就不等于，直接置为 1
    else T->flag = 1;
    for(i=1;i<N;i++){//对剩余N-1个数作循环读取判断
        scanf("%d",&V);
        if(!flag&&(!check(T,V))) flag = 1;//如果flag = 1直接不check，如果等于 0 则check
        //check值为0执行 flag = 1，否则不执行
    }
    if(flag) return 0;
    else return 1;
}

void ResetT(Tree T){
    if(T->Left) ResetT(T->Left);
    if(T->Right) ResetT(T->Right);
    T->flag = 0;
}
void DeleteTree(Tree T){
    if(T->Left) DeleteTree(T->Left);
    if(T->Right) DeleteTree(T->Right);
    delete T;
}

int main(){
    int N,L,i;
    Tree T;
    scanf("%d",&N);
    while(N){
        scanf("%d",&L);
        T = MakeTree(N);
        for(i = 0;i<L;i++){
            if(Judge(T,N)) printf("Yes\n");
            else printf("No\n");
            ResetT(T);
        }
        DeleteTree(T);
        scanf("%d",&N);
    }
    
    return 0;
}

