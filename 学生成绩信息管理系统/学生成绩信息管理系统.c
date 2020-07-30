#include<stdio.h>
#include<conio.h> 
#include<stdlib.h>
#include<windows.h>
void interface();//主菜单函数声明
void student_interface();//学生入口
void teacher_interface();//教师入口
void administratorsr_interface();//管理员入口
void super_administrators_interface();//超级管理员入口
char PASS[]="abc123";//超级管理员预设密码
struct Admin//管理员
{
   int number;//工号
   char name[20];//姓名
   char code[20];//密码
   int year;//出生年
   char sex;//性别
   char state;//0正常 1 冻结 2 离职
   struct Admin *link;
};
struct Teacher//老师
{
   int number;//工号
   char name[20];//姓名
   char sex;//性别
   int year;//出生年
   char code[20];//密码
   char state;//0正常 1 冻结 2 退学
   struct Teacher *link;
};
struct Student//学生
{
   char code[20];//密码
   char name[20];//姓名
   int number;//学号
   int year;//出生年
   int month;//出生月
   int C_language;//c语言成绩
   int English;//英语成绩
   int Physical;//物理成绩
   int Math;//数学成绩
   char sex;//性别
   char state;//0正常 1 冻结 2 离职
   struct Student *link;
};



void interface()
{
	system("cls");//清屏函数 
	printf("********************************************************\n");
	printf("------------------学生成绩信息管理系统------------------\n");	
	printf("********************************************************\n");
	printf("\n					1、学生登录入口						\n");
	printf("\n					2、教师登录入口						\n");
	printf("\n					3、管理员登录入口					\n");
	printf("\n					4、超级管理员登录入口				\n");
	printf("\n					5、退出系统 						\n");
	printf("\n					请按键选择,回车确定					\n"); 
	printf("********************************************************\n");
	switch(getch())
	{
		case 49: student_interface(); break;
		case 50: teacher_interface(); break;
		case 51: administratorsr_interface(); break;
		case 52: super_administrators_interface(); break;
		case 53: exist(0); break;//退出系统 
	}
}
void student_interface()
{
	char stu_num[20];//学号 
	char stu_code[20];//密码 
	int i=0;
	system("cls");//清屏函数 
	printf("********************************************************\n");
	printf("------------------------学生登录------------------------\n");	
	printf("********************************************************\n");
	printf("\n				1、登录学生成绩查询系统					\n");
	printf("\n				2、返回主界面							\n");
	printf("\n\n			请按键选择,回车确定						\n"); 
	printf("********************************************************\n");//getch函数接收一个字符，屏幕上不显示 ,返回值是ASII值 
	switch(getch())
	{
		case 49:
			while(1)
			{
				system("cls");//清屏函数 
				printf("********************************************************\n");
				printf("------------------登入学生成绩查询系统------------------\n");	
				printf("********************************************************\n");
				printf("\n					1、输入学号和密码					\n");
				printf("\n					2、返回上一界面						\n");
				printf("\n\n			请按键选择,回车确定						\n"); 
				printf("********************************************************\n");
					switch(getch())
				{
					case 49:printf("请输入学号：");
							scanf("%s",stu_num);
							printf("\n请输入密码：");
							scanf("%s",stu_code);
							password_input(stu_code);//调用密码加密函数 
							i=cmp_stu_num(stu_num);//与文件内存储的学号进行比较
							if(i==0)
							{
								printf("该账号不存在!\n");
								printf("按任意键返回");
								getch();
								continue;
							}
							if(cmp_stu_code(i,stu_code))
							{
								system("cls");
								sleep(2000);
								student_interface_son(i);//学生子菜单 
							};break;
					case 50:return;//退出
				}
			};break;//1.学生入口
		case 50:return;break;//退出
	}

}
void teacher_interface(void)
{
	system("cls");
	printf("********************************************************\n");
	printf("------------------------教师登录------------------------\n");	
	printf("********************************************************\n");
	printf("\n				1、登录教师管理系统						\n");
	printf("\n				2、返回主界面							\n");
	printf("\n\n			请按键选择,回车确定						\n"); 
	printf("********************************************************\n");
	int tea_num=[20];
	char tea_code[20];
	int i=0;
	switch(getch())
	{
		case 49:
			while(1)
			{
				system("cls");//清屏函数 
				printf("********************************************************\n");
				printf("--------------------登入教师管理系统--------------------\n");	
				printf("********************************************************\n");
				printf("\n					1、输入账号和密码					\n");
				printf("\n					2、返回上一界面						\n");
				printf("\n\n			请按键选择,回车确定						\n"); 
				printf("********************************************************\n");
				switch(getch())
				{
					case 49:printf("请输入教师工号：");
							scanf("%s",tea_num);
							printf("\n请输入密码：");
							getch();
							password_input(tea_code);//教师密码加密函数
							i=cmp_tea_num(tea_num);//与文件内存储的教师工号进行对比
							if(i==0)
							{
								printf("该账号不存在!\n");
								printf("按任意键返回");
								getch();
								continue;
							}
							if(cmp_tea_code(i,tea_code))
							{
								system("cls");//后面可以输入某某欢迎你吗,四个菜单同理
								sleep(2000);
								teacher_interface_son(i);//教师子菜单
							};break;
					case 50:return;
				}
			};break;
		case 50:return;break;
	}
}
void administratorsr_interface()
{
	int adm_num=[20];
	char adm_code[20];
	int i=0;
	system("cls");
	printf("********************************************************\n");
	printf("-----------------------管理员登录-----------------------\n");	
	printf("********************************************************\n");
	printf("\n				1、登录管理员管理系统					\n");
	printf("\n				2、返回主界面							\n");
	printf("\n\n			请按键选择,回车确定						\n"); 
	printf("********************************************************\n");
	
	switch(getch())
	{
		case 49:
			while(1)
			{
				system("cls");//清屏函数 
				printf("********************************************************\n");
				printf("-------------------登入管理员管理系统-------------------\n");	
				printf("********************************************************\n");
				printf("\n					1、输入账号和密码					\n");
				printf("\n					2、返回上一界面						\n");
				printf("\n\n			请按键选择,回车确定						\n"); 
				printf("********************************************************\n");
				switch(getch())
				{
					case 49:printf("请输入管理员工号：");
							scanf("%s",adm_num);
							printf("请输入密码：");
							getch();
							password_input(adm_code);//密码加密函数
							i=cmp_adm_num(adm_num);//与文件内工号进行匹配
							if(i==0)
							{
								printf("该账号不存在!\n");
								printf("按任意键返回");
								getch();
								continue;
							}
							if(cmp_adm_code(i,adm_code))
							{
								system("cls");
								sleep(2000);
								admin_interface_son(i);
							};break;
					case 50:return;break;
				}	
			};break;
		case 50:return;break;
	}
}
void super_administrators_interface(void)
{
	int i=0,super_adm_num=[20];
	char sup_adm_code[20];
	while(1)
	{
		system("cls");
		printf("********************************************************\n");
		printf("---------------------超级管理员登录---------------------\n");	
		printf("********************************************************\n");
		printf("\n				1、登录超级管理员管理系统				\n");
		printf("\n				2、返回主界面							\n");
		printf("\n\n			请按键选择,回车确定						\n"); 
		printf("********************************************************\n");
		switch(getch())
		{
			case 49:system("cls");//清屏函数 
					printf("********************************************************\n");
					printf("-----------------登入超级管理员管理系统-----------------\n");	
					printf("********************************************************\n");
					printf("\n					1、输入口令							\n");
					printf("\n					2、退出								\n");
					printf("\n\n			请按键选择,回车确定						\n"); 
					printf("********************************************************\n");
					switch(getch())
					{
							case 49:printf("请输入管理员工号：");
							scanf("%d",adm_num);
							printf("请输入密码：");
							getch();
							password_input(super_adm_code);
							i=cmp_super_adm_num(super_adm_num);
							if(i==0)
							{
								printf("账号不存在!\n");
								printf("按任意键返回");
								getch();
								continue;
							}
							if(cmp_super_adm_code(i,super_adm_code))
							{
								system("cls");
								sleep(2000);
								admin_interface_son(i);
							};break;
					case 50:return;break;
					} 
					password_input(sup_adm_mima);
					
					if(index==0)
					{
						printf("登入成功!!");
						super_administrators_interface_son();
					}
					else
					{
						anykey_continue();
						return;
					};break;
			case 50:return;
		}
	}
}

void password_input(char* str)


















