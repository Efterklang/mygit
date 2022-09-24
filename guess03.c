#include <stdio.h>
#include <string.h>
#include<time.h>

char id[100],pwd[100],text[100];
int ok = 0;
//登录 
int login()
{
    printf("登录界面\n");
    printf("ID：");   // add \n
    scanf("%s",&id);
    printf("PWD：");
    scanf("%s",&pwd); 
    strcat(id,pwd);
    strcat(id,"\n");
    
	int len = 0, ok=0;
    FILE *fp = fopen("user.txt", "r");
    if(NULL == fp)
    {
        printf("Failed to open user.txt\n");
        return 0; 
    }

    while(!feof(fp))
    {
        memset(text, 0, sizeof(text));
        fgets(text, sizeof(text) - 1, fp); 
        if(strcmp(id,text) == 0)
		{
           ok=1;
           break;
        }
    }
    
    if(ok)
    {
      printf("登录成功!\n");
	}
    else
    {
      printf("登录失败!\n");
	}
	fclose(fp);
}

//注册 
void regist()
{
	printf("注册界面\n");
    FILE *fp = fopen("user.txt","a");
    printf("ID：");  
    scanf("%s",&id);
    printf("PWD：");
    scanf("%s",&pwd); 
    fputs(id,fp);
    fputs(pwd,fp);
    fputs("\n",fp);
    fflush(stdin);
    fclose(fp);
    login();
}

//游戏 
void game()
{	 
	clock_t start, end;
    double run_time;
    start = clock();
    printf("runtime = %f\n",run_time);
    int num = rand() % 1000;  
    int guess, i = 0; 
	int min = 0, max = 1000;  
    while (1)
	{
    	printf("Please guess number:");
        scanf("%d", &guess);
        if (num > guess)
		{
            i++;	
            printf("猜小了\n");
            min = guess;
            printf("范围:%d - %d\n", min, max);
        }
		else if (num < guess)
		{
            i++;	
            printf("猜大了\n");
            max = guess;
            printf("范围:%d - %d\n", min, max);
        }
		else
		{
            i++;	
            
            printf("猜对了!\n猜数次数：%d次\n用时：%f秒", i, run_time);  // %d-->%f
 
            break;
        }
        end = clock();
        run_time=(double)(end-start)/CLOCKS_PER_SEC;
        
    }
    

}

//菜单 
void meun()
{
	printf("1 注册\n");
	printf("0 登录\n");
    int a = 0;
    scanf("%d",&a);
    fflush(stdin);
    if(a)
       regist();
    else
        login();
}

int main()
{ 
	int a;
    meun();
    printf("1 Play\n");
    printf("0 Exit\n");
    scanf("%d", &a);
    switch (a){
        case 1:
        game();
        break;
        
        case 0:
        break;
        
        default:
        printf("选项错误!\n请重新输入：\n");
    }
    return 0;
}