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
    FILE *a1;//,*a2,*b1;

    char fileName[50];//,tempFile[50];
    printf("enter the file name : ");
    scanf("%s",fileName);

    a1 = fopen(fileName, "r");
    //b1 = fopen(tempFile, "w");

    //fseek(a1,sizeof(int),SEEK_SET);

    int a,b,temp,s1=1;
    //s1 = fread(&a,sizeof(int),1,a1);


    if(s1 == 0)
    {
        printf("File is Empty\n");
        return;
    }

printf("INITIAL FP = %ld\n",ftell(a1));
    printf("DATA -- FP -- S\n");
    while(s1 != 0)
    {
            fseek(a1,sizeof(int) * 2,SEEK_CUR);
            s1 = fread(&a,sizeof(int),1,a1);

            if(s1 != 0)
                printf("%d -- %ld -- %d\n",a,ftell(a1),s1);

    }
    printf("FINAL FP --  %ld FINAL S -- %d\n",ftell(a1),s1);

    fclose(a1);
    //fseek(f2,2,SEEK_SET);

    //sorting pairs of nos in the file and rewriting in it

}
