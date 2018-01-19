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

int count1,count2;

void main()
{
    FILE *a1,*a2,*b1;
    int size=1,noOfLoops=0,totalNos = 2;//,sizeTemp=2;
    char file1[50],file2[50] = "file2_";
    printf("enter the file name : ");
    scanf("%s",file1);

    strcat(file2,file1);

    int a,b,s1 = 1,s2 = 1;

//1st while loop
//sorts everything using merge sort
    while((size/2) <= (totalNos/2))//some condition to make sure the loop runs untill all the nos are over
    {
        //by the time they come here the file would have been sorted pair wise with a
        // particular size or it would have just started
        if(noOfLoops%2 == 0)
        {
            a1 = fopen(file1, "r");
            a2 = fopen(file1, "r");
            b1 = fopen(file2, "w");

            printf("1\t");
            if(a1 == NULL)
            {
                printf("File is Empty\n");
                return;
            }

        }
        else
        {
            //break;
            a1 = fopen(file2, "r");
            a2 = fopen(file2, "r");
            b1 = fopen(file1, "w");

            printf("2\t");
            if(a1 == NULL)
            {
                printf("File is Empty\n");
                return;
            }
        }

        fseek(a2,sizeof(int) * size,SEEK_SET);
//2nd inner while loop
        //merges pairs of a particular size
        //after the loop rewind both a1 and a2
        //after this loop size doubles
        while(s2!=0)
        {
                //sizeTemp = size;

                // to merge two pairs of size = size
                count1=0,count2=0;
//3rd inner 1st while loop
                while(count1 != size && count2 != size)
                {
                    if(count1 == 0 && count2 ==0)
                    {
                        s1 = fread(&a,sizeof(int),1,a1);
                        s2 = fread(&b,sizeof(int),1,a2);
                        printf("count1 = %d -- count2 = %d\n",count1,count2);
                    }

                    if(a<=b)
                    {
                        fwrite((char*)&a,sizeof(int),1,b1);
                        if(size == 1)
                            totalNos++;
                        //fseek(a1,sizeof(int),SEEK_CUR);
                        count1++;
                        printf("count1 = %d --- data = %d\n",count1,a);
                        s1 = fread(&a,sizeof(int),1,a1);

                    }
                    else
                    {
                        fwrite((char*)&b,sizeof(int),1,b1);
                        if(size == 1)
                            totalNos++;
                        //fseek(a2,sizeof(int),SEEK_CUR);
                        count2++;
                        printf("count2 = %d --- data = %d\n",count2,b);
                        s2 = fread(&b,sizeof(int),1,a2);

                    }
//end of 3rd inner 1st while loop
                }
                //to merge the left over nos in a1 part of the pair
//3rd inner 2nd while loop
                while(count1 !=size && s1 != 0)
                {

                    fwrite((char*)&a,sizeof(int),1,b1);
                    if(size == 1)
                        totalNos++;
                    count1++;
                    printf("count1 = %d --- data = %d\n",count1,a);
                    if(count1!=size || size == 1)
                        s1 = fread(&a,sizeof(int),1,a1);
//end of 3rd inner 2nd while loop
                }
                //to merge the left over nos in a2 part of the pair
//3rd inner 3rd while loop
                while(count2 !=size && s2 != 0)
                {

                    fwrite((char*)&b,sizeof(int),1,b1);
                    if(size == 1)
                        totalNos++;
                    count2++;
                    printf("count2 = %d --- data = %d \n",count2,b);
                    if(count2!=size || size == 1)
                        s2 = fread(&b,sizeof(int),1,a2);
//end of 3rd inner 3rd while loop
                }

                fseek(a1,sizeof(int) * size,SEEK_CUR);
                fseek(a2,sizeof(int) * size,SEEK_CUR);

                s1 = fread(&a,sizeof(int),1,a1);
                s2 = fread(&b,sizeof(int),1,a2);


//end of 2nd inner while loop
        }
        noOfLoops++;
        fclose(a1);
        fclose(a2);
        fclose(b1);

        size = size * 2;
//end of 1 st inner while loop
    }

    printf("output file is generated with a name: %s\n",file2);

    //fseek(f2,2,SEEK_SET);

    //sorting pairs of nos in the file and rewriting in it

}
