#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>                  //控制台输入输出
#include "person.h"

void Menu(struct Person menu[], int count)     //主菜单函数

{	
	char choice;                    
	int  x = count;
	
    while (choice != '0')
	{
		system("cls");       //清屏功能，为了窗口显示清晰
		
		printf("\n");
		printf("\n");
		printf("                        ************************\n");
		printf("                        ************************\n");
		printf("                        ************************\n");
		printf("          ########     欢迎使用我们的通讯录系统     ##########\n");
		printf("\n");
        printf("########\t\t 录入联系人信息 --- 1 \t\t########\n");
		printf("########\t\t 删除联系人信息 --- 2 \t\t########\n");
		printf("########\t\t 修改联系人信息 --- 3 \t\t########\n");
		printf("########\t\t 排序联系人信息 --- 4 \t\t########\n");
		printf("########\t\t 查找联系人信息 --- 5 \t\t########\n");
		printf("########\t\t 显示联系人信息 --- 6 \t\t########\n");
		printf("########\t\t 添加联系人信息 --- 7 \t\t########\n");
		printf("########\t\t 保存联系人信息 --- 8 \t\t########\n");
		printf("########\t\t 载入联系人信息 --- 9 \t\t########\n");
		printf("########\t\t 退出系统       --- 0 \t\t########\n");
		printf("\n");
		printf("################################################################\n");
		printf("\n");
		printf("【温馨提示：每次使用时，请先载入联系人信息】");
		printf("\n");
		printf("\n");
		
        printf("请选择您要的功能\n");
		printf("请输入您的选择：\n");
		
		fflush(stdin);                    //清除缓存语句
		scanf("%c", &choice);
		
       	switch (choice)
		{
		case '1': 
			x = Input(menu,x);
			break;
		case '2':
			x = Delete(menu, x);
			break;
		case '3':
			Modify(menu, x);
			break;
		case '4':
			Sort(menu, x);
			break;
		case '5':
			Search(menu, x);
			break;
		case '6':
			Show(menu, x);
			break;
		case '7':
            x = Add(menu, x);
			break;
		case '8':
			Save(menu, x);
			break;
		case '9':
			x = Download(menu);
			break;
		case '0': 
			break;
		default:
			break;
		}
	}
}

int Input(struct Person input[],int i)    //【实现主菜单的第1个功能：录入新联系人】
{
	int count = 0;
	int n;                                //用于记录人数
	
	while (1)                             //条件判断永远为真，一直循环，直到内部语句允许跳出循环
	{
		putchar('\n');
		printf("第%d个人的信息:\n",++count);  
		printf("如果您想要退出，请按'end'\n");//提示如何停止输入
		printf("\n");
		printf("姓名：");
        scanf("%s", input[i].name);
		
		if (strcmp(input[i].name, "end") == 0)
		{
			i--;
			break;
		}                 //遇到"end",i--
		
       	printf("职务：");
        scanf("%s",input[i].post);
		printf("专业：");
        scanf("%s",input[i].major);
		printf("电话：");
        scanf("%s",input[i].phone);
		printf("邮箱：");
        scanf("%s",input[i].Email);
		i++;
	}
    n = i+1;                                  //返回值比实际人数多1，便于其他功能的参数传递
	return n;
}

int Delete(struct Person del[], int z)        //【实现主菜单的第2个功能：删除联系人】
{
	int i;
	int x =0;
	char a;                                   //a是存储判断意义的字符
	char name[20];
	
    printf("请输入您要删除的联系人姓名:");
	scanf("%s",name);
	printf("|   姓名     |    职务    |    专业    |    电话    |      邮箱            |\n");
				for (i=0; i<z; i++)
				{
					if (strcmp(del[i].name, name) == 0)
					{
						printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",del[i].name, del[i].post, del[i].major, del[i].phone, del[i].Email);
					}
				}
				printf("\n");
				printf("您确定要删除此人？按‘Y’删除，按其他键返回：\n");
				fflush(stdin);
				scanf("%c",&a);
				
				if (a == 'Y' || a == 'y')                  //注意字符要用单引号
				{
					for (i=0; i<z; i++)                    
					{
						if (strcmp(del[i].name, name) == 0)//比较字符串
						{
							x = 1;
							
							for (i=i; i<z; i++)             
							{
								del[i] = del[i+1];          //使仅次于del[i+1]赋值给del[i]，用于达到删除效果   
							}
						}
					}
					z--;                                    //联系人个数减1
					printf("此联系人已删除!\n");
				}
				
				if (x == 0)                                 //利用x是否为0来判断是否实现删除功能
				{
					printf("没有进行删除或没有此联系人!\n");
				}
				
				getch();                                    //等待一个字符的输入。可以实现暂时暂停,有利于编译器报错
				return z;
}

void Modify(struct Person modify[], int z)      //【实现主菜单的第3个功能：修改联系人】
{
	int a = 0;
	char name [20];
	char post [20];
	char phone [15];
	char major [20];
	char Email [30];
	int i;
	char c;                                     //c定义为字符型，避免按任意键时造成系统崩溃
	
	printf("请输入您要修改的联系姓名:");
	scanf("%s",name);
	printf("|   姓名     |    职务    |    专业    |    电话    |      邮箱            |\n");
				for (i=0; i<z; i++)
				{
					if (strcmp(modify[i].name, name) == 0)
					{
						printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",modify[i].name, modify[i].post, modify[i].major, modify[i].phone, modify[i].Email);
					}
				}
				printf("\n");
				for (i=0; i<z; i++)
				{
					if (strcmp(modify[i].name, name) == 0)
					{
						printf("-----------1: 姓名------------\n");
						printf("-----------2: 职务 -----------\n");
						printf("-----------3: 专业------------\n");
						printf("-----------4: 电话------------\n");
						printf("-----------5: 邮箱------------\n");
						printf("-------请在1-5选择您要修改的信息：\n");
						fflush(stdin);
						scanf("%c",&c);
						
						switch (c)
						{
						case '1':
							{
								printf("姓名：");
								scanf("%s",name);
								strcpy(modify[i].name, name);
								a = 1;
							}
							break;
						case '2':
							{
								printf("职务：");
								scanf("%s",post);
								strcpy(modify[i].post, post);
								a = 1;
							}
							break;
						case '3':
							{
								printf("专业：");
								scanf("%s",major);
								strcpy(modify[i].major, major);
								a = 1;
							}
							break;
						case '4':
							{
								printf("电话：");
								scanf("%s",phone);
								strcpy(modify[i].phone, phone);
								a = 1;
							}
							break;
						case '5':
							{
								printf("邮箱：");
								scanf("%s",Email);
								strcpy(modify[i].Email, Email);
								a = 1;
							}
							break;
						default:
							break;          //为了结构完整，default要写上
						}
					}
				}
				if (a == 1)
				{
					printf("修改成功!\n");
				}
				else
				{
					printf("您没有在1-5中进行选择或没有此信息，所以修改失败!\n");
				}
				getch();
}

void Sort(struct Person sort[], int z)   //【实现主菜单的第4个功能：排序联系人】
{
    struct Person my;                    //定义结构体变量my
	int i;
	int j;
	
	for (i=0; i<z; i++)
	{
		for (j=i+1; j<z; j++)
		{
			if (strcmp(sort[i].name,sort[j].name) >= 0)
			{
				my = sort[i];
				sort[i] = sort[j];
				sort[j] = my;
			}
		}
	}
	printf("已按姓名排序成功!\n");
	getch();
}

void Search(struct Person search[], int z) //【实现主菜单的第5个功能：查找联系人】
{
	int a = 0;
	int i;
	char name [20];
	char post [20];
	char phone [15];
	char major [20];
	char Email [30];
	char c;
	
	printf("-----------1: 姓名------------\n");
	printf("-----------2: 职务 -----------\n");
	printf("-----------3: 专业------------\n");
	printf("-----------4: 电话------------\n");
	printf("-----------5: 邮箱------------\n");
	printf("-------请在1-5选择您要查找的方式：\n");
	fflush(stdin);
	scanf("%c",&c);
	switch (c)
	{
	case '1':
		printf("姓名：");
		scanf("%s",name);
		printf("|   姓名     |    职务    |    专业    |    电话    |      邮箱            |\n");
		for (i=0; i<z; i++)
		{
			if (strcmp(search[i].name, name) == 0)
			{
				printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",search[i].name, search[i].post, search[i].major, search[i].phone, search[i].Email);
				a = 1;
			}
		}
		break;
	case '2':
		printf("职务：");
		scanf("%s",post);
		printf("|   姓名     |    职务    |    专业    |    电话    |      邮箱            |\n");
		for (i=0; i<z; i++)
		{
			if (strcmp(search[i].post, post) == 0)
			{
				printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",search[i].name, search[i].post, search[i].major, search[i].phone, search[i].Email);
				a = 1;	
			}	
		}
		break;
	case '3':
		printf("专业：");
		scanf("%s",major);
		printf("|   姓名     |    职务    |    专业    |    电话    |      邮箱            |\n");
		for (i=0; i<z; i++)
		{
			if (strcmp(search[i].major, major) == 0)	
			{
				printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",search[i].name, search[i].post, search[i].major, search[i].phone, search[i].Email);
				a = 1;	
			}	
		}
		break;
	case '4':
		printf("电话：");
		scanf("%s",phone);
		printf("|   姓名     |    职务    |    专业    |    电话    |      邮箱            |\n");
		for (i=0; i<z; i++)
		{
			if (strcmp(search[i].phone, phone) == 0)
			{
				printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",search[i].name, search[i].post, search[i].major, search[i].phone, search[i].Email);
				a = 1;
			}
		}
		break;
	case '5':
		printf("邮箱：");
		scanf("%s",Email);
		printf("|   姓名     |    职务    |    专业    |    电话    |      邮箱            |\n");
		for (i=0; i<z; i++)
		{
			if (strcmp(search[i].Email, Email) == 0)
			{
				printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",search[i].name, search[i].post, search[i].major, search[i].phone, search[i].Email);
				a = 1;
			}
		}
		break;
	default:
		break;
	}
	if (a != 1)
	{
		printf("您没有在1-5中进行选择或没有此信息，所以查找失败!\n");
	}
	getch();
}

void Show (struct Person show[], int z)      //【实现主菜单的第6个功能：显示联系人】
{
    int i;
	
	printf("                              我的通讯录\n");
    printf("\n");
	printf("  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
	printf("|   姓名     |    职务    |    专业    |    电话    |      邮箱            |\n");
	printf("\n");
	
	for (i=0; i<z; i++)
	{
		printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",show[i].name, show[i].post, show[i].major, show[i].phone, show[i].Email);
		printf("\n");
	}
	printf(" |            |            |            |            |                      |\n");
	printf("  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
	getch();	 
}

int Add(struct Person add[], int z)   //【实现主菜单的第7个功能：添加联系人】
{
	printf("姓名：");
	scanf("%s",add[z].name);
	printf("职务：");
	scanf("%s",add[z].post);
	printf("专业：");
	scanf("%s",add[z].major);
	printf("电话：");
	scanf("%s",add[z].phone);
	printf("邮箱：");
	scanf("%s",add[z].Email);
	printf("添加成功!\n");
	getch();
	return z+1;                       //返回值是z+1，应注意参数传递的问题，否则会出错
}

void Save(struct Person save[], int z)//【实现主菜单的第8个功能：保存联系人】

{
	int i;
	FILE *fp;
	
	if ((fp=fopen("address_book.bin","wb")) == NULL)     //为输出打开一个二进制文件
	{
		printf("This file can't be opened!");
		exit(1);
	}
	
	for (i=0; i<z; i++)
	{
		fwrite(&save[i], sizeof(struct Person), 1, fp);//将数据以二进制形式写入address_book.bin
	}
	
	fclose(fp);
	
	printf("保存成功！");
	getch();
}

int Download(struct Person down[])   //【实现主菜单的第9个功能：载入联系人】
{
	int i;
	int len=0;
	FILE *fp;
	
	if((fp = fopen("address_book.bin","rb")) == NULL)  //输入打开一个二进制文件
	{
		printf("The file can't be opened!");
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);//将"address_book.bin"的读写位置指针设定到文件末尾，相对位移量为0
	
	int k = ftell(fp);     //得到文件中字节的总数
	
	printf("k=%d", k);
	
	rewind(fp);            //将指针重新指向文件开头
	
	while(ftell(fp) != k)  //逐一从文件中读入联系人信息到down结构数组中
	{
		fread(&down[len], sizeof(struct Person), 1, fp);
		len++;
	}	
	
	printf("                              我的通讯录\n");
	printf("\n");
	printf("  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
	printf("|   姓名     |    职务    |    专业    |    电话    |      邮箱            |\n");
	printf("\n");
	
	for (i = 0; i < len; i++)
	{
		printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",down[i].name, down[i].post, down[i].major, down[i].phone, down[i].Email);
		printf("\n");
	}
	printf(" |            |            |            |            |                      |\n");
	printf("  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
	printf("\n");
	printf("i = %d",i);

	fclose(fp);

	getch();
	return (i);
}
