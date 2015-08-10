//Designed by Zhong Mingyuan 2013/3/24

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>              //引入库函数
#include "person.h"             //引入头文件"person.h"

int main ()

{ 	
	system("color 1F");         //设置背景颜色 "1"表示蓝色背景 "F"表示字体颜色为亮白色
	struct Person per[500];     //结构体Person变量定义为per[]数组，数组长度为500
	int count = 0;              //表明数组per中实际存储了多少数据，初值为0	
	
	Menu(per,count);                  //调用主菜单函数
	
	return 0;	
}
