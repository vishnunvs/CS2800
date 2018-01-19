/*
name : NVS Vishnu Kanth Reddy
id : 111601012
sem : 4
program : mergeSortBigFile2.c
program description : merging a big binary file
 full of integers upto 1000000
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include <time.h>

void main()
{
    FILE *fp1,*fp2,*fp,*op;
    char file[2][50],outputFile[50] = "output.txt";
    //char outputFile[50];
    strcpy(file[1],"temp.bin");

    printf("enter the file name: ");
    scanf("%s",file[0]);

    int index_1,index_2,cycles = 0,size=1,s1,s2,a,b,flag,left_flag=0,right_flag=0;
    int left_count=0,right_count =0,edge_flag=0,lp=0,rp=0;

    while(1)
    {
        //opening different files based on odd parity of cycles
        index_1 = cycles%2;
        index_2 = (cycles + 1)%2;
        fp1 = fopen(file[index_1], "rb");
        fp2 = fopen(file[index_1], "rb");
        fp = fopen(file[index_2], "wb+");

        if(fp1 == NULL)
        {
            printf("error in the file %s\n",file[index_1]);
            return;
        }
        if(fp2 == NULL)
        {
            printf("error in the file %s\n",file[index_1]);
            return;
        }
        if(fp == NULL)
        {
            printf("error in the file %s\n",file[index_2]);
            return;
        }
        //seeking the fp2 by an amount size
        fseek(fp2,sizeof(int) * size,SEEK_SET);
        //then read the second element
        s2 = fread(&b,sizeof(int),1,fp2);
        rp = ftell(fp2);
        flag = 0;
        //edge_flag=0;
        //this means if the fp2 reached EOF then s2 == 0, so break the loop
        if(s2 == 0 && edge_flag !=1)
        {
            edge_flag = 2;
            break;
        }
        edge_flag = 0;

        //while(s2!=0 && edge_flag != 2)/*
name : NVS Vishnu Kanth Reddy
id : 111601012
sem : 4
program : mergeSortBigFile2.c
program description : merging a big binary file
 full of integers upto 1000000
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include <time.h>

void main()
{
    FILE *fp1,*fp2,*fp,*op;
    char file[2][50],outputFile[50] = "output.txt";
    //char outputFile[50];
    strcpy(file[1],"temp.bin");

    printf("enter the file name: ");
    scanf("%s",file[0]);

    int index_1,index_2,cycles = 0,size=1,s1,s2,a,b,flag,left_flag=0,right_flag=0;
    int left_count=0,right_count =0,edge_flag=0,lp=0,rp=0;

    while(1)
    {
        //opening different files based on odd parity of cycles
        index_1 = cycles%2;
        index_2 = (cycles + 1)%2;
        fp1 = fopen(file[index_1], "rb");
        fp2 = fopen(file[index_1], "rb");
        fp = fopen(file[index_2], "wb+");

        if(fp1 == NULL)
        {
            printf("error in the file %s\n",file[index_1]);
            return;
        }
        if(fp2 == NULL)
        {
            printf("error in the file %s\n",file[index_1]);
            return;
        }
        if(fp == NULL)
        {
            printf("error in the file %s\n",file[index_2]);
            return;
        }
        //seeking the fp2 by an amount size
        fseek(fp2,sizeof(int) * size,SEEK_SET);
        //then read the second element
        s2 = fread(&b,sizeof(int),1,fp2);
        rp = ftell(fp2);
        flag = 0;
        //edge_flag=0;
        //this means if the fp2 reached EOF then s2 == 0, so break the loop
        if(s2 == 0 && edge_flag !=1)
        {
            edge_flag = 2;
            break;
        }
        edge_flag = 0;

        //while(s2!=0 && edge_flag != 2)
        while(edge_flag != 2)
        {



            if(left_flag == 0 && right_flag == 0 && flag == 1)
            {
                s1 = fread(&a,sizeof(int),1,fp1);
                s2 = fread(&b,sizeof(int),1,fp2);
                if(s2 == 0)
                {
                    edge_flag = 1;
                    // left_count++;
                    //break;
                }
                if(s1 == 0 )
                {
                    edge_flag = 2;
                    break;
                }
            }

            if(flag == 0)
            {
                s1 = fread(&a,sizeof(int),1,fp1);
                flag = 1;
            }
            else
            {
                if(left_flag == 1 && right_flag == 0)
                {
                    s1 = fread(&a,sizeof(int),1,fp1);
                    left_flag = 0;
                }
                else
                {
                    if(right_flag == 1 && left_flag == 0)
                    {
                        s2 = fread(&b,sizeof(int),1,fp2);
                        rp = ftell(fp2);
                        if(s2 == 0)
                        {
                            edge_flag = 1;
                        }//break;
                        right_flag = 0;
                    }
                }
            }
            //edge flag if was here
            if(edge_flag == 1)
            {
                // printf("left_counter:\n");
                while(left_count!=size)
                {
                    //if(size!=1)
                    // s1 = fread(&a, sizeof(int), 1, fp1);
                    if(s1 != 0)
                        fwrite((char *)&a,sizeof(int),1,fp);
                    left_count++;
                    // printf("%d \t",left_count);
                    if(left_count != size)
                        s1 = fread(&a,sizeof(int),1,fp1);
                    // fseek(fp1,sizeof(int) * size,SEEK_CUR);
                    // fseek(fp2,sizeof(int) * size,SEEK_CUR);
                }
                //printf("\n");
                lp = ftell(fp1);
                // if(rp == lp )
                // {
                    // edge_flag = 2;
                // }
                left_count = 0;
                right_count = 0;
                left_flag = 0;
                right_flag = 0;
                edge_flag = 2;
                break;
            }

            if(a<=b)
            {
                fwrite((char *)&a,sizeof(int),1,fp);
                left_count++;
                left_flag = 1;
                right_flag = 0;
            }
            else
            {
                fwrite((char *)&b,sizeof(int),1,fp);
                right_count++;
                left_flag = 0;
                right_flag = 1;
            }

            while(left_count == size && right_count!=size)
            {
                //if(size!=1)
                //s2 = fread(&b, sizeof(int), 1, fp2);
                fwrite((char *)&b,sizeof(int),1,fp);
                right_count++;
                if(right_count != size)
                {
                    s2 = fread(&b,sizeof(int),1,fp2);
                    rp = ftell(fp2);
                }
                // fseek(fp1,sizeof(int) * size,SEEK_CUR);
                // fseek(fp2,sizeof(int) * size,SEEK_CUR);
            }

            while(right_count == size && left_count!=size)
            {
                //if(size!=1)
                // s1 = fread(&a, sizeof(int), 1, fp1);
                fwrite((char *)&a,sizeof(int),1,fp);
                left_count++;
                if(left_count != size)
                    s1 = fread(&a,sizeof(int),1,fp1);
                // fseek(fp1,sizeof(int) * size,SEEK_CUR);
                // fseek(fp2,sizeof(int) * size,SEEK_CUR);
            }
            if(left_count == size && right_count == size)
            {
                left_count = 0;
                right_count = 0;
                left_flag = 0;
                right_flag = 0;
                flag = 1;
                fseek(fp1,sizeof(int) * size,SEEK_CUR);
                fseek(fp2,sizeof(int) * size,SEEK_CUR);
            }


        }

        fclose(fp1);
        fclose(fp2);
        fclose(fp);

        /********************************************/

        // fp = fopen(file[index_2], "rb");
        // int num;
        // while(fread(&num, sizeof(int), 1, fp)) {
        //     printf("%d ", num);
        // }
        // printf("\n");
        // fclose(fp);
        /********************************************/

        size = size * 2;
        cycles++;
    }

    //outputFile = file[index_2];
    /***********************************************/


    fp = fopen(file[index_1], "rb");
    op = fopen(outputFile, "w");

    if(fp == NULL)
    {
        printf("error in opening the temp file\n");
        return;
    }

    if(op == NULL)
    {
        printf("error in opening the output file\n");
        return;
    }

    int s=1,outputValue=0;
    while(s!=0)
    {
        s = fread(&outputValue,sizeof(int),1,fp);
        if(s!=0)
            fprintf(op,"(%d) ",outputValue);
    }

    fclose(fp);
    fclose(op);

    printf("%s file is generated successfully\n",outputFile);
    /***********************************************/


    // printf("Successfull\n");

}

        while(edge_flag != 2)
        {



            if(left_flag == 0 && right_flag == 0 && flag == 1)
            {
                s1 = fread(&a,sizeof(int),1,fp1);
                s2 = fread(&b,sizeof(int),1,fp2);
                if(s2 == 0)
                {
                    edge_flag = 1;
                    // left_count++;
                    //break;
                }
                if(s1 == 0 )
                {
                    edge_flag = 2;
                    break;
                }
            }

            if(flag == 0)
            {
                s1 = fread(&a,sizeof(int),1,fp1);
                flag = 1;
            }
            else
            {
                if(left_flag == 1 && right_flag == 0)
                {
                    s1 = fread(&a,sizeof(int),1,fp1);
                    left_flag = 0;
                }
                else
                {
                    if(right_flag == 1 && left_flag == 0)
                    {
                        s2 = fread(&b,sizeof(int),1,fp2);
                        rp = ftell(fp2);
                        if(s2 == 0)
                        {
                            edge_flag = 1;
                        }//break;
                        right_flag = 0;
                    }
                }
            }
            //edge flag if was here
            if(edge_flag == 1)
            {
                // printf("left_counter:\n");
                while(left_count!=size)
                {
                    //if(size!=1)
                    // s1 = fread(&a, sizeof(int), 1, fp1);
                    if(s1 != 0)
                        fwrite((char *)&a,sizeof(int),1,fp);
                    left_count++;
                    // printf("%d \t",left_count);
                    if(left_count != size)
                        s1 = fread(&a,sizeof(int),1,fp1);
                    // fseek(fp1,sizeof(int) * size,SEEK_CUR);
                    // fseek(fp2,sizeof(int) * size,SEEK_CUR);
                }
                //printf("\n");
                lp = ftell(fp1);
                // if(rp == lp )
                // {
                    // edge_flag = 2;
                // }
                left_count = 0;
                right_count = 0;
                left_flag = 0;
                right_flag = 0;
                edge_flag = 2;
                break;
            }

            if(a<=b)
            {
                fwrite((char *)&a,sizeof(int),1,fp);
                left_count++;
                left_flag = 1;
                right_flag = 0;
            }
            else
            {
                fwrite((char *)&b,sizeof(int),1,fp);
                right_count++;
                left_flag = 0;
                right_flag = 1;
            }

            while(left_count == size && right_count!=size)
            {
                //if(size!=1)
                //s2 = fread(&b, sizeof(int), 1, fp2);
                fwrite((char *)&b,sizeof(int),1,fp);
                right_count++;
                if(right_count != size)
                {
                    s2 = fread(&b,sizeof(int),1,fp2);
                    rp = ftell(fp2);
                }
                // fseek(fp1,sizeof(int) * size,SEEK_CUR);
                // fseek(fp2,sizeof(int) * size,SEEK_CUR);
            }

            while(right_count == size && left_count!=size)
            {
                //if(size!=1)
                // s1 = fread(&a, sizeof(int), 1, fp1);
                fwrite((char *)&a,sizeof(int),1,fp);
                left_count++;
                if(left_count != size)
                    s1 = fread(&a,sizeof(int),1,fp1);
                // fseek(fp1,sizeof(int) * size,SEEK_CUR);
                // fseek(fp2,sizeof(int) * size,SEEK_CUR);
            }
            if(left_count == size && right_count == size)
            {
                left_count = 0;
                right_count = 0;
                left_flag = 0;
                right_flag = 0;
                flag = 1;
                fseek(fp1,sizeof(int) * size,SEEK_CUR);
                fseek(fp2,sizeof(int) * size,SEEK_CUR);
            }


        }

        fclose(fp1);
        fclose(fp2);
        fclose(fp);

        /********************************************/

        // fp = fopen(file[index_2], "rb");
        // int num;
        // while(fread(&num, sizeof(int), 1, fp)) {
        //     printf("%d ", num);
        // }
        // printf("\n");
        // fclose(fp);
        /********************************************/

        size = size * 2;
        cycles++;
    }

    //outputFile = file[index_2];
    /***********************************************/


    fp = fopen(file[index_1], "rb");
    op = fopen(outputFile, "w");

    if(fp == NULL)
    {
        printf("error in opening the temp file\n");
        return;
    }

    if(op == NULL)
    {
        printf("error in opening the output file\n");
        return;
    }

    int s=1,outputValue=0;
    while(s!=0)
    {
        s = fread(&outputValue,sizeof(int),1,fp);
        if(s!=0)
            fprintf(op,"(%d) ",outputValue);
    }

    fclose(fp);
    fclose(op);

    printf("%s file is generated successfully\n",outputFile);
    /***********************************************/


    // printf("Successfull\n");

}
