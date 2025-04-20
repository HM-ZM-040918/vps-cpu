## 一、 确保vpsCPU处于活跃，采用'C'语言的递归斐波拉契数列，确保vps有gcc环境如果没有先安装如下操作

```bash
sudo apt update	#更新系统源
apt install gcc	#安装gcc，如果非root模式可使用sudo apt install gcc
gcc -v			#安装后查看gcc版本
```

## 二、 一些配置文件

```bash
touch start.c run.sh	#新建C文件与shell文件
![...](https://github.com/HM-ZM-040918/vps-cpu/blob/main/Img/1.jpg?raw=true)
```

## 三、配置

```bash
//代码在start.c内
gcc start.c -o start 	#-o后面的为可执行文件的名称，可以自定义，此处与.c文件一致
vim run.sh			   #配置run.sh内容
./start				   #在run.sh 写入之后 esc :wq
chmod 777 run.sh 		#给run.sh权限
cd /var/spool/cron/crontabs #到此处配置crontab，主要是利用定时启动的功能
vim root
* * * * * /root/run.sh >> /root/tmp.txt	#在root内写入，意思为每分钟调用run.sh将结果写入tmp.txt中,'>>后面的也可以省略'执行完成后:wq
systemctl restart cron                  #重启cron
systemctl enable cron                   #加入到开机自启中
#如果想不同时间调用建议参考：https://www.pppet.net/
```

