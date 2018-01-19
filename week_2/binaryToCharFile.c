/*
name : NVS Vishnu Kanth Reddy
id : 111601012
sem : 4
program : binaryToCharFile.c
program description : reads a file and converts files that are in binary form to
                        charater form
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include <time.h>

void main()
{
    FILE *f1,*f2;
    char file1[50],file2[50] = "binary_final_answer.txt";
    int s=1,a=0;

    printf("enter the file name: ");
    scanf("%s",file1);

    //strcat(file2,file1);

    f1 = fopen(file1, "rb");
    f2 = fopen(file2, "w");

    if(f1 == NULL)
    {
        printf("error in opening the file1\n");
        return;
    }

    if(f2 == NULL)
    {
        printf("error in opening the file2\n");
        return;
    }

    while(s!=0)
    {
        s = fread(&a,sizeof(int),1,f1);
        if(s!=0)
            fprintf(f2,"%d\n",a);
    }

    fclose(f1);
    fclose(f2);

    printf("%s file is generated\n",file2);
}
