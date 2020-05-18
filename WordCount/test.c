#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
// 统计字符数
int get_file_charNum(char* filename);
// 统计单词数
int get_file_wordNum(char* filename);
// 利用main函数自带参数
int main(int argc, char* argv[])
{
    //判断参数是否是3个
    if (argc == 3)
    {
        //看命令是否为-c 还是-w
        if (strcmp(argv[1],"-c")==0)
        {
            //统计字符数
            int a = get_file_charNum(argv[2]);
            printf("字符数：%d\n", a);
        }
        else if(strcmp(argv[1], "-w") == 0)
        {
            //统计单词数
           // printf("正确");
            int a = get_file_wordNum(argv[2]);
            printf("单词数：%d\n", a);
        }
        else
        {
            printf("你的命令输入错误 正确输入:\n");
            printf("WordCount.exe -c 文件名\n");
            printf("或者：\n");
            printf("WordCount.exe -w 文件名\n");
        }
    }
    else
    {
        printf("你的命令输入错误 正确输入:\n");
        printf("WordCount.exe -c 文件名\n");
        printf("或者：\n");
        printf("WordCount.exe -w 文件名\n");
    }
    //int a=get_file_charNum("F:\\vs2019\\VS2019Code\\WordCount\\Debug\\test.txt");

    //int a=get_file_wordNum("F:\\vs2019\\VS2019Code\\WordCount\\Debug\\test.txt");
    return 0;
}
int get_file_charNum(char* filename)
{
    int count = 0;
    //打开文件
    FILE* fp= fopen(filename, "r");
    if (fp==NULL)
    {
        printf("打开文件错误！强制退出程序!");
        exit(-1);
    }
    while (!feof(fp))
    {
        fgetc(fp);
        count++;
    }
    fclose(fp);
    return (count-1);

}
int get_file_wordNum(char* filename)
{
    FILE* fp;
    int c;
    int n = 0;
    char tmp[500];
    _Bool tmp2[500] = {0};
    char tmp3[500];
    int count = 0;
    int count2 = 0;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("打开文件错误！强制退出程序!");
        exit(-1);
    }
    do
    {
        c = fgetc(fp);
        if (feof(fp))
        {
            break;
        }
        tmp[count] = (char)c;
        count++;
    } while (1);
    fclose(fp);
    tmp[count] = '\0';
    //printf("\n%s", tmp);
    //如果遇到连续的空格或者逗号，就要把他们弄成一个空格和逗号
    for (unsigned int i = 0; i < strlen(tmp); i++)
    {
        if (tmp[i] == ' ' && tmp[i + 1] == ' ')
        {
            tmp2[i + 1] = 1;
        }
        if (tmp[i] == ',' && tmp[i + 1] == ',')
        {
            tmp2[i + 1] = 1;
        }
    }
    int j = 0;
    //处理之后的结果放在tmp3里面
    for (unsigned int i = 0; i < strlen(tmp); i++)
    {
        if (tmp2[i]==0)
        {
            tmp3[j] = tmp[i];
            j++;
        }
    }
    tmp3[j] = '\0';
    //printf("\n%s", tmp3);
    for (unsigned int i = 0; i < strlen(tmp3); i++)
    {
        //如果是空格
        if (tmp3[i] == ' ')
        {
            //空格不在第一的位置和最后的位置
            if (i != 0&&(i!=(strlen(tmp3)-1)))
            {
                count2++;
            }
        }

        if (tmp3[i] == ',')
        {
            if (i != 0 && (i != (strlen(tmp3) - 1)))
            {
                if ((tmp3[i - 1] != ' ') && (tmp3[i + 1] != ' '))
                {
                    count2++;
                }
                if ((tmp3[i - 1] == ' ') && (tmp3[i + 1] == ' '))
                {
                    count2--;
                }
            }
        }
    }
    return (count2+1);
}