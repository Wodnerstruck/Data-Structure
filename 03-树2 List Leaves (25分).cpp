#include <cstdio>
#include <queue>
using namespace std;
#define MaxTree 10
#define Null -1
using Tree = int;

struct TreeNode
{
	int Position;
	Tree Left, Right;
}T1[MaxTree];
Tree BuildTree(struct TreeNode T[]) {
	int N, Root = Null;
	char cl, cr;
	Tree check[MaxTree];
	scanf("%d", &N);//吸收行后回车
	getchar();
	if (N) {
		for (int i = 0; i < N; i++) check[i] = 0;
		for (int i = 0; i < N; i++) {
			scanf("%c %c", &cl ,&cr);
			getchar();
			T[i].Position = i;
			if (cl != '-') {
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else {
				T[i].Left = Null;
			}
			if (cr != '-') {
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else {
				T[i].Right = Null;
			}

		}
		int j;
		for (j = 0; j < N; j++)
			if (!check[j]) break;
		Root = j;

	}
	return Root;
}

void LevelOrderTraversal(Tree P) {

	queue <TreeNode> Q;
	Q.push(T1[P]);
	int flag = 0;
	while (!Q.empty()) {

		if (Q.front().Left == Null && Q.front().Right == Null) {
			if (!flag) flag = 1;
			else printf(" ");
			printf("%d", Q.front().Position);
		}
		if (Q.front().Left != Null )
			Q.push(T1[Q.front().Left]);
		if(Q.front().Right != Null)
			Q.push(T1[Q.front().Right]);
		
		Q.pop();
	}

}

int main() {
	Tree T;
	T = BuildTree(T1);
	LevelOrderTraversal(T);
	return 0;
}