## 一、 确保vpsCPU处于活跃，采用'C'语言的递归斐波拉契数列，确保vps有gcc环境如果没有先安装如下操作

```bash
sudo apt update	#更新系统源
apt install gcc	#安装gcc，如果非root模式可使用sudo apt install gcc
gcc -v			#安装后查看gcc版本
```

## 二、 一些配置文件

```bash
touch start.c run.sh	#新建C文件与shell文件
```

## 三、C文件内容

```c
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
//编写后esc :wq
```

## 四、配置

```bash
gcc start.c -o start 	#-o后面的为可执行文件的名称，可以自定义，此处与.c文件一致
vim run.sh			   #配置run.sh内容
./start				   #在run.sh 写入之后 esc :wq
chmod 777 run.sh 		#给run.sh权限
cd /var/spool/cron/crontabs #到此处配置crontab，主要是利用定时启动的功能
vim root
* * * * * /root/run.sh >> /root/tmp.txt	#在root内写入，意思为每分钟调用run.sh将结果写入tmp.txt中,'>>后面的也可以省略'
#如果想不同时间调用建议参考：https://www.pppet.net/
```

