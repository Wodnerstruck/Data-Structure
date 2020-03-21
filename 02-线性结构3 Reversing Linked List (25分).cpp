#include <cstdio>
#include <vector>
using namespace std;
struct LNode{
    int Address;
    int Data;
    int Next;
};
using List = struct LNode*;
List Nodes[100010] ;
List CreatNode(int Ad,int Data,int Next){
    List L = new LNode;
    L->Address = Ad;L->Data = Data;
    L->Next = Next;
    return L;
}
int main(){
    int head,N,K;//首地址，总结点，每k个反转
    scanf("%d%d%d",&head,&N,&K);
    for(int i=0;i<N;i++){//读入结点，按结点地址作为下标存储
        int a,d,n;
        scanf("%d%d%d",&a,&d,&n);
        Nodes[a] = CreatNode(a,d,n);
    }
    //首尾排序从Head到-1
    vector <List> Sort;
    for(int i = head;i!=-1;i = Nodes[i]->Next){
        Sort.push_back(Nodes[i]);
    }
    //求翻转的子列数
    int times = Sort.size()/K;
    //每K个反转存入输出序列中
    vector <List> Output;
    for(int i=1;i<=times;i++){
        for(int j=i * K - 1;j>(i - 1)*K - 1;j--)
        {
            Output.push_back(Sort[j]);
        }
    }
    //如有剩余未反转直接复制
    if(Sort.size()%K != 0){
        for(int i=0;i<Sort.size()%K;i++){
            Output.push_back(Sort[times*K+i]);//注意复制Sort的剩余，误写为Nodes会引发异常
        }
    }
    //地址转换
    for(int i = 0;i<Output.size()-1;i++){
        Output[i]->Next=Output[i+1]->Address;
    }
    Output[Output.size()-1]->Next = -1;//最后一项可不转换单独输出
    for(int i = 0;i<Output.size()-1;i++){//输出结点
        printf("%05d %d %05d\n",Output[i]->Address,Output[i]->Data,Output[i]->Next);
    }
    printf("%05d %d -1\n",Output[Output.size()-1]->Address,Output[Output.size()-1]->Data);
    return 0;
}