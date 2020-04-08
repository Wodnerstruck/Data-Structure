#include <cstdio>
#define MaxTree 10
#define Null -1
using Tree = int;

struct TreeNode
{
    char Element;
    Tree Left,Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[]){
    int N,Root = Null;
    char cl,cr;
    Tree check[MaxTree];
    scanf("%d\n",&N);//吸收行后回车
    if(N){
        for (int i = 0;i<N;i++) check[i] = 0;
        for(int i = 0;i<N;i++){
            scanf("%c %c %c\n",&T[i].Element,&cl,&cr);//吸收行后回车
            if(cl!='-'){
                T[i].Left = cl-'0';
                check[T[i].Left] = 1;
            }
            else {
                T[i].Left = Null;
            }
            if(cr!='-'){
                T[i].Right = cr-'0';
                check[T[i].Right] = 1;
            }
            else {
                T[i].Right = Null;
            }
            
        }
        int j;
        for(j = 0;j<N;j++)
            if(!check[j]) break;
        Root = j;
       
    }
     return Root;
}

int Isomorphic (Tree R1,Tree R2){
    if ((R1==Null)&&(R2==Null))
        return 1;
    if (((R1==Null)&&(R2!=Null))||(R1!=Null&&R2==Null))
        return 0;
    if (T1[R1].Element!=T2[R2].Element)
        return 0;
    if((T1[R1].Left==Null)&&(T2[R2].Left==Null))
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&(T1[T1[R1].Left].Element==T2[T2[R2].Left].Element))
        return (Isomorphic(T1[R1].Left,T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right));
    else
        return (Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));
    

}


int main(){
    Tree R1,R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if(Isomorphic(R1,R2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
