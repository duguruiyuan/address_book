struct Person                               //Person结构体声明
{
	char name [20];
	char post [20];
	char phone [15];
	char major [20];
	char Email [30];
};

void Menu(struct Person menu[],int count);  //主菜单    函数声明
int Input(struct Person input[],int i);     //录入      函数声明
int Delete(struct Person del[], int z);     //删除      函数声明
void Modify(struct Person modify[], int z); //修改      函数声明
void Sort(struct Person sort[], int z);     //排序      函数声明
void Search(struct Person search[], int z); //查找      函数声明
void Show (struct Person show[], int z);    //显示      函数声明
int Add(struct Person add[], int z);        //添加      函数声明
void Save(struct Person save[], int z);     //保存文件  函数声明
int Download(struct Person down[]);         //加载文件  函数声明