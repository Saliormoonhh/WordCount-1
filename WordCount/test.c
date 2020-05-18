#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
// ͳ���ַ���
int get_file_charNum(char* filename);
// ͳ�Ƶ�����
int get_file_wordNum(char* filename);
// ����main�����Դ�����
int main(int argc, char* argv[])
{
    //�жϲ����Ƿ���3��
    if (argc == 3)
    {
        //�������Ƿ�Ϊ-c ����-w
        if (strcmp(argv[1],"-c")==0)
        {
            //ͳ���ַ���
            int a = get_file_charNum(argv[2]);
            printf("�ַ�����%d\n", a);
        }
        else if(strcmp(argv[1], "-w") == 0)
        {
            //ͳ�Ƶ�����
           // printf("��ȷ");
            int a = get_file_wordNum(argv[2]);
            printf("��������%d\n", a);
        }
        else
        {
            printf("�������������� ��ȷ����:\n");
            printf("WordCount.exe -c �ļ���\n");
            printf("���ߣ�\n");
            printf("WordCount.exe -w �ļ���\n");
        }
    }
    else
    {
        printf("�������������� ��ȷ����:\n");
        printf("WordCount.exe -c �ļ���\n");
        printf("���ߣ�\n");
        printf("WordCount.exe -w �ļ���\n");
    }
    //int a=get_file_charNum("F:\\vs2019\\VS2019Code\\WordCount\\Debug\\test.txt");

    //int a=get_file_wordNum("F:\\vs2019\\VS2019Code\\WordCount\\Debug\\test.txt");
    return 0;
}
int get_file_charNum(char* filename)
{
    int count = 0;
    //���ļ�
    FILE* fp= fopen(filename, "r");
    if (fp==NULL)
    {
        printf("���ļ�����ǿ���˳�����!");
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
        printf("���ļ�����ǿ���˳�����!");
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
    //������������Ŀո���߶��ţ���Ҫ������Ū��һ���ո�Ͷ���
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
    //����֮��Ľ������tmp3����
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
        //����ǿո�
        if (tmp3[i] == ' ')
        {
            //�ո��ڵ�һ��λ�ú�����λ��
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