#include<iostream>

using namespace std;
int m = 0;//搬动计数

void move(char A, int n, char C) {
	//cout << "第" << ++m << "步" << "将编号为" << n 
		//<< "的圆盘从第" << A << "个柱子移到第" << C << "个柱子上" << endl;
	cout << "第" << ++m << "步  " << "圆盘 " << n
		<< " 从" << A << "柱子---->" << C << "柱子" << endl;
}
void Hanoi(int n, char A, char B, char C) {
	//将塔座A上的n个圆盘按规则搬到C上，B做过渡
	if (n == 1)
		move(A, 1, C);//将编号为1的圆盘从A到C
	else {
		Hanoi(n - 1, A, C, B);//将A上编号为1至n-1的圆盘移到B，C做辅助塔
		move(A, n, C);//将编号为n的圆盘从A移到C
		Hanoi(n - 1, B, A, C);//
	}
}
int main() {
	int n;
	char a = '1', b = '2', c = '3';
	cout << "请输入初始第一个柱子上的圆盘个数：" << endl;
	cin >> n;
	cout << "将塔座A上的n个圆盘按规则搬到C上:\n" << endl;
	Hanoi(n, a, b, c);
	system("pause");
}