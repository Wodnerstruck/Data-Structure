#include <cstdio>
using Polynomial = struct PolyNode*;
struct PolyNode
{
	int coef;
	int expon;
	Polynomial link;
};
void Attach(int c, int e, Polynomial &Rear) {//传尾指针引用（或指针的指针也可）
	Polynomial P;
	P = new PolyNode;
	P->coef = c;
	P->expon = e;
	P->link = nullptr;
	Rear->link = P;
	Rear = P;
}
//读入多项式
Polynomial ReadPoly() {
	Polynomial P, Rear, Temp;
	int N, c, e;
	scanf("%d", &N);
	P = new PolyNode;//新建空的头结点
	P->link = nullptr;
	Rear = P;
	while (N--) {
		scanf("%d%d", &c, &e);
		Attach(c, e, Rear);
	}
	Temp = P;
	P = P->link;
	delete Temp;//删除空的头结点
	return P;
}
//多项式乘法
Polynomial Mult(Polynomial P1, Polynomial P2) {
	Polynomial P, Rear, t1, t2, t;
	int c, e;
	if (!P1 || !P2) return nullptr;//只要一个为空返回Null（一个为空就无法做乘法）,而加法不用作此判断，即使两个都空也可以正确返回Null
	t1 = P1; t2 = P2;
	P = new PolyNode;
	P->link = nullptr;
	Rear = P;
	while (t2) {//将P1第一项乘P2每一项得到一个多项式
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, Rear);//该多项式一定是指数递减的
		t2 = t2->link;
	}
	t1 = t1->link;//P1后挪一位准备后续乘法插入计算
	while (t1) {
		t2 = P2; Rear = P;//每轮计算从P2头部开始
		while (t2) {
			c = t1->coef * t2->coef;//先求c, e值
			e = t1->expon + t2->expon;
			while (Rear->link&&Rear->link->expon > e)//多项式P中项指数大于e则不断后移
				Rear = Rear->link;
			if (Rear->link&&Rear->link->expon == e) {
				if (Rear->link->coef + c) {
					Rear->link->coef += c;//合并完成后Rear不做挪动
				}
				else {
					t = Rear->link;
					Rear->link = t->link;
					delete t;
				}
			}
			else {
				t = new PolyNode;
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
				Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = P;
	P = P->link;
	delete t2;
	return P;//删除空的头结点并返回第一项
}
//比较函数
int Compare(int a, int b) {
	if (a > b) return 1;
	else if (a == b) return 0;
	else if (a < b) return -1;
}
//多项式加法
Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial t1, t2, Rear, t;
	t1 = P1; t2 = P2;//指针赋值给临时变量，避免对原多项式的修改
	Polynomial P = new PolyNode;
	P->link = nullptr;
	Rear = P;
	while (t1&&t2) {//判断指数大小，大者复制并指针后移，相等的系数相加不为零添加，两者指针后移
		switch (Compare(t1->expon, t2->expon)) {
		case 1:
			Attach(t1->coef, t1->expon, Rear);
			t1 = t1->link;
			break;
		case -1:
			Attach(t2->coef, t2->expon, Rear);
			t2 = t2->link;
			break;
		case 0:
			if (t1->coef + t2->coef) Attach(t1->coef + t2->coef, t1->expon, Rear);
			t1 = t1->link;
			t2 = t2->link;
			break;
		}
	}
	for (; t1; t1 = t1->link) Attach(t1->coef, t1->expon, Rear);//复制剩余多项式
	for (; t2; t2 = t2->link) Attach(t2->coef, t2->expon, Rear);
	t = P;
	P = P->link;
	delete t;
	return P;
}
//打印多项式
void PrintPoly(Polynomial P) {
	int flag = 0;//控制空格输出
	if (!P) { printf("0 0\n"); return; }//空多项式输出 0 0
	while (P) {
		if (!flag) flag = 1;
		else printf(" ");
		printf("%d %d", P->coef, P->expon);
		P = P->link;//不要漏掉
	}
	printf("\n");
	return;
}
int main() {
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1, P2);
	PrintPoly(PP);
	PS = Add(P1, P2);
	PrintPoly(PS);
	return 0;
}
