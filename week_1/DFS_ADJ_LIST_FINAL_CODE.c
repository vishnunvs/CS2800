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




typedef struct node
{
		int data;
		struct node * next;
}node;

typedef struct graph
{
    node **adjacency_list;
    int vertices;
    int *begin;
    int *end;
    int *parent;
    int *visited;
}graph;
//this function checks if there is a directed edge from root to destination in graph G
int checkEdge(int root, int destination,graph *G)
{
    node *p,*head;
    head = G->adjacency_list[root];
    p = head;
    while(p!=NULL && 1)
    {
        if(p->data == destination)
        {
            return(1);
        }
        else
        {
            p = p->next;
        }
    }
    return 0;
}
//prints the pre post timings i.e; begin and end of each vertex
void timings(graph *G)
{
    printf("The pre and post timings of all the vertices are given below:\n");
    for(int i = 0; i<G->vertices ; i++)
    {
        printf("%d -- (%d,%d)\n",i,G->begin[i],G->end[i]);
    }
}
//function prints all the dfs edges and their edge types
void edgeType(graph *G)
{
    printf("Edge types are as follows:\n");
    int post =0;
    for (int pre = 0; pre < G->vertices; pre++)
    {
        node *p;
        p = G->adjacency_list[pre];

        while(p != NULL && 1)
        {
            post = p->data;
            p = p->next;
        if(checkEdge(pre,post,G))
            {
                if(G->begin[pre]!=0 && G->end[pre]!=0 && G->begin[post]!=0 && G->end[post]!=0 )
                {
                    if(G->parent[post] == pre )
                    {
                        printf("(%d,%d)  Tree Edge\n",pre,post);
                    }
                    else if(G->begin[pre] < G->begin[post])
                    {
                        printf("(%d,%d) Forward Edge\n",pre,post);
                    }
                    if(G->begin[pre]>G->begin[post])
                    {
                        if(G->end[post] < G->begin[pre])
                        {
                            printf("(%d,%d) Cross Edge\n",pre,post);
                        }
                        else
                        {
                            printf("(%d,%d) Back Edge\n",pre,post);
                        }
                    }
                }
            }
        }
    }
}
//function prints the given adjacency_list
void printAL(graph *G)
{
    printf("The adjacency_list is:\n");
    int post = 0;
    for (int pre = 0; pre < G->vertices; pre++)
    {
        printf("%d -- ",pre);
        node *p;
        p = G->adjacency_list[pre];

        while(p != NULL && 1)
        {
            post = p->data;
            p = p->next;
            printf("%d ",post);
        }
        printf("\n");
    }
}
//dfs function
void dfs(graph *G,int root,int *count)
{
    //printf("count = %d\n",*count);
    node *temp;

    // temp =G->adjacency_list[root];
    // if( temp == NULL) return;
    if(G->end[root]!=0 && G->visited[root] == 1)
    {
            return;
    }

    if(G->begin[root]==0 && G->visited[root] == 0)
    {
        G->begin[root] = *count;
        (*count)++;
    }
    G->visited[root] = 1;
    temp = G->adjacency_list[root];
    while(temp != NULL)
    {

        if(G->visited[temp->data] == 0)
        {
            G->parent[temp->data] = root;
            dfs(G,temp->data,count);
        }
        temp = temp->next;
    }
    if(G->begin[root] != 0)
    {
        G->end[root] = *count;
        (*count)++;
    }
}

//function to create graph i.e; initialize it
graph *create_graph(int vertices)
{
    graph *G;
    G = (graph *)malloc(sizeof(graph));

    G->vertices=vertices;
    G->adjacency_list=(node**)malloc(G->vertices * sizeof(node*));//given adjacency_list
    G->visited = (int*)malloc(G->vertices * sizeof(int));
    G->begin = (int*)malloc(G->vertices * sizeof(int));
    G->end = (int*)malloc(G->vertices * sizeof(int));
    G->parent = (int*)malloc(G->vertices * sizeof(int));

    for (int i = 0; i < G->vertices; i++)
    {
        G->visited[i] = 0;
        G->begin[i] = 0;
        G->end[i] = 0;
        G->parent[i] = 0;
    }
	return G;
}

//function to read_file
graph *read_file()
{

    int no_vertices,temp=0;
    scanf("%d",&no_vertices);

    graph *G;
	G=create_graph(no_vertices);

    //printf("\n\nadjWt1:\n\n");

    for(int i=0;i<no_vertices;i++)
    {
        node *head,*p; //creating head pointer and moving variable pointer

           int j=0;
            while(1)
            {
                //printf("1");
                if(j==0)
                {
                    scanf("%d",&temp);
                    if(temp == -1) break;
                    head=(node *) malloc(sizeof(node));
                    head->next = NULL;
                    G->adjacency_list[i] = head;
                    head->data = temp;
                    j++;
                }
                else
                {
                    scanf("%d",&temp);
                    if(temp == -1) break;
                    p = (node *) malloc(sizeof(node));
                    p->data = temp;
                    p->next = NULL;
                    head->next = p;
                    head = p;
                }
            }
            temp = 0;

		    //printf("%d\t",G->adjacency_matrix[i][j]);
	//printf("\n");
    }
//	printf("____________________________________________________\n");
    return G;
}

void main()
{

        graph *G = read_file(); //reads the file and returns the graph pointer

        printAL(G);

        printf("---------------------------------------------\n");
        printf("PLEASE NOTE THAT THE VERTICES ARE '0' INDEXED\n");
        printf("---------------------------------------------\n");

        int count =1;
        for(int i=0;i<G->vertices;i++)
    	   dfs(G,i,&count);
        timings(G);
        edgeType(G);
}
