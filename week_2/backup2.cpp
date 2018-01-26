#include <bits/stdc++.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <stdio.h>


#define INITIAL_HEAP "_initial"
#define AFTER_INSERTING "_afer_inserting"
#define INITIAL (0)
#define INSERT (1)

using namespace std;

class heap{
private:
    int * heap_array = int[];
public:
    //we need a function to initialize a heap_array
    void initialize_heap(vector<int> array);
    //to build a heap
    void build_heap();
    //we need to insert an element without disturbing the min_heap property
    void insert_node(int value);
    //we need to delete the top most node and make it a min_heap again
    int delete_min_node();
    //min_heapifier function to make the tree from a particular node min_heap
    void min_heapifier(int node_pos);
    //fucntion to get the sorted array,basically to print the sorted array
    void sort();
    //we need a make dot file function
    void make_dot_file(int which_file);
    //function to swap two numbers in the vector given their node_pos
    void swap(int x, int y);

};
//to swap two values given their node_pos
void heap::swap(int x, int y){
    int temp = heap_array[x];
    heap_array[x] = heap_array[y];
    heap_array[y] = temp;
}

void heap::initialize_heap(vector<int> array){
    for(int i=0;i<array.size();i++){
        heap_array.push_back(array[i]);
    }
}
//we assume that we have a minheap and then insert a value without disturbing
//the minheap property
void heap::insert_node(int value){
    heap_array.push_back(value);
    int n = heap_array.size();
    int up = floor(n/2),down = n;
    while (1) {
        if(heap_array[down] < heap_array[up]){
            swap(up,down);
            n = up;
            up = floor(n/2);
            down = n;
        }
        else break;
    }
}

void heap::make_dot_file(int which_file){
    FILE *fp;
    string str="output",output_file_name1,output_file_name2;
    if(which_file == INITIAL){
        output_file_name1 = str + INITIAL_HEAP + ".dot";
        output_file_name2 = str + INITIAL_HEAP;
    }
    else if(which_file == INSERT){
        output_file_name1 = str + string(AFTER_INSERTING) + string(".dot");
        output_file_name2 = str + string(AFTER_INSERTING);

    }
    const char * c1 = output_file_name1.c_str();
    const char * c2 = output_file_name2.c_str();
    // string str;
    // cout<<"enter the output file name:";
    // cin>>str;
    fp = fopen(c1, "w");

    if(fp == NULL){
        cout<<"Error in opening the file";
        return;
    }
    // string::size_t pos = str.find("output");
    // string str1 = str.substr(pos);

    fprintf(fp, "%s ","graph");
    fprintf(fp, "%s{\n",c2);
    //fprintf(fp,"%s{\n","output");
    int down =1;
    for(int up=0;up<floor(heap_array.size()/2);up++){
        int counter =0;
        while(counter < 2){
            fprintf(fp, "\t%d -> %d;\n",up,down);
            down++;
            counter++;
        }
    }
    fprintf(fp,"%c",'}');
    fclose(fp);
}

int main(int argc, char const *argv[]) {
    /* code */
    // int array[15];

    //assume that we get the input in a file to extract till we get a newline

    string line;
    int n;
    vector<int> array;
    getline(cin,line);

    istringstream iss(line);

    while(iss>>n){
        array.push_back(n);
    }

    heap obj;

    obj.initialize_heap(array);

    // int no_of_vertices = obj.heap_array.size();
    int no_of_vertices = array.size();
    // for(int node_pos = floor(no_of_vertices);node_pos>=0;node_pos--){
    //     //we will write after writing insert_node and delete_node functions
    // }

    obj.make_dot_file(INITIAL);
    //obj.insert_node(30);
    //obj.make_dot_file(INSERT);


    return 0;
}
