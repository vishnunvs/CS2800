/*
name : NVS Vishnu Kanth Reddy
id : 111601012
sem : 4
program : DFS
program description : DFS using adjacency_matrix and differentiating the edges
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include <time.h>

void main()
{
    int n,i=0;
    char fileName[50];

    printf("Enter the file name :" );
    scanf("%s",fileName);

    FILE *fp;

    fp = fopen(fileName, "wb");
    if(fp == NULL)
    {
        printf("Error while opening the file\n");
        return;
    }

    srand(time(0));

    while(i<1000000)
    {
        n = rand();
        //n = 20 - i;
        //fprintf(fp,"%d ",n);
        fwrite((char *)&n,sizeof(int),1,fp);
        i++;
    }
    printf("file is generated successfully\n");
    fclose(fp);

}
