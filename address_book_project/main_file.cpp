//Designed by Zhong Mingyuan 2013/3/24

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>              //����⺯��
#include "person.h"             //����ͷ�ļ�"person.h"

int main ()

{ 	
	system("color 1F");         //���ñ�����ɫ "1"��ʾ��ɫ���� "F"��ʾ������ɫΪ����ɫ
	struct Person per[500];     //�ṹ��Person��������Ϊper[]���飬���鳤��Ϊ500
	int count = 0;              //��������per��ʵ�ʴ洢�˶������ݣ���ֵΪ0	
	
	Menu(per,count);                  //�������˵�����
	
	return 0;	
}
