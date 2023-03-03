#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int FB(int i)
{
	if (i <= 2)
		return 1;
	else 
		return FB(i-1)+FB(i-2);	//递归当数值大于2时带入
}
int main() {	
	int r = 2;	//整型变量决定循环的执行次数	
	while (r)	
	{
		unsigned long long i = 0;	//声明变量为非负数
		srand((unsigned long long)time(NULL));	//生成随机数，非负数
		i = rand()%50;	//随机数对50取余范围在0~50之间，这里的数值取决于cpu性能，建议不要大于50，由于随机数值不确定
		int p = FB(i);	//带入FB函数内，将结果赋给p
		system("date");	//显示当前执行时间与日期
		printf("%d\n", p);	//递归斐波拉契数列执行完后输出结果		
		r--;			//r = r-1;
        sleep(5);		//等待5s后再次进入循环
	}
	return 0;
}
