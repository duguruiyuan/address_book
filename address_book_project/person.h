struct Person                               //Person�ṹ������
{
	char name [20];
	char post [20];
	char phone [15];
	char major [20];
	char Email [30];
};

void Menu(struct Person menu[],int count);  //���˵�    ��������
int Input(struct Person input[],int i);     //¼��      ��������
int Delete(struct Person del[], int z);     //ɾ��      ��������
void Modify(struct Person modify[], int z); //�޸�      ��������
void Sort(struct Person sort[], int z);     //����      ��������
void Search(struct Person search[], int z); //����      ��������
void Show (struct Person show[], int z);    //��ʾ      ��������
int Add(struct Person add[], int z);        //���      ��������
void Save(struct Person save[], int z);     //�����ļ�  ��������
int Download(struct Person down[]);         //�����ļ�  ��������