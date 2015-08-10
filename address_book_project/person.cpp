#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>                  //����̨�������
#include "person.h"

void Menu(struct Person menu[], int count)     //���˵�����

{	
	char choice;                    
	int  x = count;
	
    while (choice != '0')
	{
		system("cls");       //�������ܣ�Ϊ�˴�����ʾ����
		
		printf("\n");
		printf("\n");
		printf("                        ************************\n");
		printf("                        ************************\n");
		printf("                        ************************\n");
		printf("          ########     ��ӭʹ�����ǵ�ͨѶ¼ϵͳ     ##########\n");
		printf("\n");
        printf("########\t\t ¼����ϵ����Ϣ --- 1 \t\t########\n");
		printf("########\t\t ɾ����ϵ����Ϣ --- 2 \t\t########\n");
		printf("########\t\t �޸���ϵ����Ϣ --- 3 \t\t########\n");
		printf("########\t\t ������ϵ����Ϣ --- 4 \t\t########\n");
		printf("########\t\t ������ϵ����Ϣ --- 5 \t\t########\n");
		printf("########\t\t ��ʾ��ϵ����Ϣ --- 6 \t\t########\n");
		printf("########\t\t �����ϵ����Ϣ --- 7 \t\t########\n");
		printf("########\t\t ������ϵ����Ϣ --- 8 \t\t########\n");
		printf("########\t\t ������ϵ����Ϣ --- 9 \t\t########\n");
		printf("########\t\t �˳�ϵͳ       --- 0 \t\t########\n");
		printf("\n");
		printf("################################################################\n");
		printf("\n");
		printf("����ܰ��ʾ��ÿ��ʹ��ʱ������������ϵ����Ϣ��");
		printf("\n");
		printf("\n");
		
        printf("��ѡ����Ҫ�Ĺ���\n");
		printf("����������ѡ��\n");
		
		fflush(stdin);                    //����������
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

int Input(struct Person input[],int i)    //��ʵ�����˵��ĵ�1�����ܣ�¼������ϵ�ˡ�
{
	int count = 0;
	int n;                                //���ڼ�¼����
	
	while (1)                             //�����ж���ԶΪ�棬һֱѭ����ֱ���ڲ������������ѭ��
	{
		putchar('\n');
		printf("��%d���˵���Ϣ:\n",++count);  
		printf("�������Ҫ�˳����밴'end'\n");//��ʾ���ֹͣ����
		printf("\n");
		printf("������");
        scanf("%s", input[i].name);
		
		if (strcmp(input[i].name, "end") == 0)
		{
			i--;
			break;
		}                 //����"end",i--
		
       	printf("ְ��");
        scanf("%s",input[i].post);
		printf("רҵ��");
        scanf("%s",input[i].major);
		printf("�绰��");
        scanf("%s",input[i].phone);
		printf("���䣺");
        scanf("%s",input[i].Email);
		i++;
	}
    n = i+1;                                  //����ֵ��ʵ��������1�������������ܵĲ�������
	return n;
}

int Delete(struct Person del[], int z)        //��ʵ�����˵��ĵ�2�����ܣ�ɾ����ϵ�ˡ�
{
	int i;
	int x =0;
	char a;                                   //a�Ǵ洢�ж�������ַ�
	char name[20];
	
    printf("��������Ҫɾ������ϵ������:");
	scanf("%s",name);
	printf("|   ����     |    ְ��    |    רҵ    |    �绰    |      ����            |\n");
				for (i=0; i<z; i++)
				{
					if (strcmp(del[i].name, name) == 0)
					{
						printf("   %-8s     %-8s      %-8s     %-8s   %-8s  \n",del[i].name, del[i].post, del[i].major, del[i].phone, del[i].Email);
					}
				}
				printf("\n");
				printf("��ȷ��Ҫɾ�����ˣ�����Y��ɾ���������������أ�\n");
				fflush(stdin);
				scanf("%c",&a);
				
				if (a == 'Y' || a == 'y')                  //ע���ַ�Ҫ�õ�����
				{
					for (i=0; i<z; i++)                    
					{
						if (strcmp(del[i].name, name) == 0)//�Ƚ��ַ���
						{
							x = 1;
							
							for (i=i; i<z; i++)             
							{
								del[i] = del[i+1];          //ʹ������del[i+1]��ֵ��del[i]�����ڴﵽɾ��Ч��   
							}
						}
					}
					z--;                                    //��ϵ�˸�����1
					printf("����ϵ����ɾ��!\n");
				}
				
				if (x == 0)                                 //����x�Ƿ�Ϊ0���ж��Ƿ�ʵ��ɾ������
				{
					printf("û�н���ɾ����û�д���ϵ��!\n");
				}
				
				getch();                                    //�ȴ�һ���ַ������롣����ʵ����ʱ��ͣ,�����ڱ���������
				return z;
}

void Modify(struct Person modify[], int z)      //��ʵ�����˵��ĵ�3�����ܣ��޸���ϵ�ˡ�
{
	int a = 0;
	char name [20];
	char post [20];
	char phone [15];
	char major [20];
	char Email [30];
	int i;
	char c;                                     //c����Ϊ�ַ��ͣ����ⰴ�����ʱ���ϵͳ����
	
	printf("��������Ҫ�޸ĵ���ϵ����:");
	scanf("%s",name);
	printf("|   ����     |    ְ��    |    רҵ    |    �绰    |      ����            |\n");
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
						printf("-----------1: ����------------\n");
						printf("-----------2: ְ�� -----------\n");
						printf("-----------3: רҵ------------\n");
						printf("-----------4: �绰------------\n");
						printf("-----------5: ����------------\n");
						printf("-------����1-5ѡ����Ҫ�޸ĵ���Ϣ��\n");
						fflush(stdin);
						scanf("%c",&c);
						
						switch (c)
						{
						case '1':
							{
								printf("������");
								scanf("%s",name);
								strcpy(modify[i].name, name);
								a = 1;
							}
							break;
						case '2':
							{
								printf("ְ��");
								scanf("%s",post);
								strcpy(modify[i].post, post);
								a = 1;
							}
							break;
						case '3':
							{
								printf("רҵ��");
								scanf("%s",major);
								strcpy(modify[i].major, major);
								a = 1;
							}
							break;
						case '4':
							{
								printf("�绰��");
								scanf("%s",phone);
								strcpy(modify[i].phone, phone);
								a = 1;
							}
							break;
						case '5':
							{
								printf("���䣺");
								scanf("%s",Email);
								strcpy(modify[i].Email, Email);
								a = 1;
							}
							break;
						default:
							break;          //Ϊ�˽ṹ������defaultҪд��
						}
					}
				}
				if (a == 1)
				{
					printf("�޸ĳɹ�!\n");
				}
				else
				{
					printf("��û����1-5�н���ѡ���û�д���Ϣ�������޸�ʧ��!\n");
				}
				getch();
}

void Sort(struct Person sort[], int z)   //��ʵ�����˵��ĵ�4�����ܣ�������ϵ�ˡ�
{
    struct Person my;                    //����ṹ�����my
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
	printf("�Ѱ���������ɹ�!\n");
	getch();
}

void Search(struct Person search[], int z) //��ʵ�����˵��ĵ�5�����ܣ�������ϵ�ˡ�
{
	int a = 0;
	int i;
	char name [20];
	char post [20];
	char phone [15];
	char major [20];
	char Email [30];
	char c;
	
	printf("-----------1: ����------------\n");
	printf("-----------2: ְ�� -----------\n");
	printf("-----------3: רҵ------------\n");
	printf("-----------4: �绰------------\n");
	printf("-----------5: ����------------\n");
	printf("-------����1-5ѡ����Ҫ���ҵķ�ʽ��\n");
	fflush(stdin);
	scanf("%c",&c);
	switch (c)
	{
	case '1':
		printf("������");
		scanf("%s",name);
		printf("|   ����     |    ְ��    |    רҵ    |    �绰    |      ����            |\n");
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
		printf("ְ��");
		scanf("%s",post);
		printf("|   ����     |    ְ��    |    רҵ    |    �绰    |      ����            |\n");
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
		printf("רҵ��");
		scanf("%s",major);
		printf("|   ����     |    ְ��    |    רҵ    |    �绰    |      ����            |\n");
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
		printf("�绰��");
		scanf("%s",phone);
		printf("|   ����     |    ְ��    |    רҵ    |    �绰    |      ����            |\n");
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
		printf("���䣺");
		scanf("%s",Email);
		printf("|   ����     |    ְ��    |    רҵ    |    �绰    |      ����            |\n");
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
		printf("��û����1-5�н���ѡ���û�д���Ϣ�����Բ���ʧ��!\n");
	}
	getch();
}

void Show (struct Person show[], int z)      //��ʵ�����˵��ĵ�6�����ܣ���ʾ��ϵ�ˡ�
{
    int i;
	
	printf("                              �ҵ�ͨѶ¼\n");
    printf("\n");
	printf("  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
	printf("|   ����     |    ְ��    |    רҵ    |    �绰    |      ����            |\n");
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

int Add(struct Person add[], int z)   //��ʵ�����˵��ĵ�7�����ܣ������ϵ�ˡ�
{
	printf("������");
	scanf("%s",add[z].name);
	printf("ְ��");
	scanf("%s",add[z].post);
	printf("רҵ��");
	scanf("%s",add[z].major);
	printf("�绰��");
	scanf("%s",add[z].phone);
	printf("���䣺");
	scanf("%s",add[z].Email);
	printf("��ӳɹ�!\n");
	getch();
	return z+1;                       //����ֵ��z+1��Ӧע��������ݵ����⣬��������
}

void Save(struct Person save[], int z)//��ʵ�����˵��ĵ�8�����ܣ�������ϵ�ˡ�

{
	int i;
	FILE *fp;
	
	if ((fp=fopen("address_book.bin","wb")) == NULL)     //Ϊ�����һ���������ļ�
	{
		printf("This file can't be opened!");
		exit(1);
	}
	
	for (i=0; i<z; i++)
	{
		fwrite(&save[i], sizeof(struct Person), 1, fp);//�������Զ�������ʽд��address_book.bin
	}
	
	fclose(fp);
	
	printf("����ɹ���");
	getch();
}

int Download(struct Person down[])   //��ʵ�����˵��ĵ�9�����ܣ�������ϵ�ˡ�
{
	int i;
	int len=0;
	FILE *fp;
	
	if((fp = fopen("address_book.bin","rb")) == NULL)  //�����һ���������ļ�
	{
		printf("The file can't be opened!");
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);//��"address_book.bin"�Ķ�дλ��ָ���趨���ļ�ĩβ�����λ����Ϊ0
	
	int k = ftell(fp);     //�õ��ļ����ֽڵ�����
	
	printf("k=%d", k);
	
	rewind(fp);            //��ָ������ָ���ļ���ͷ
	
	while(ftell(fp) != k)  //��һ���ļ��ж�����ϵ����Ϣ��down�ṹ������
	{
		fread(&down[len], sizeof(struct Person), 1, fp);
		len++;
	}	
	
	printf("                              �ҵ�ͨѶ¼\n");
	printf("\n");
	printf("  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n ");
	printf("|   ����     |    ְ��    |    רҵ    |    �绰    |      ����            |\n");
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
