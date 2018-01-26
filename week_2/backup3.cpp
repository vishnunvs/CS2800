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
#define AFTER_DELETING "_after_deleting"
#define INITIAL (0)
#define INSERT (1)
#define DELETE (-1)

using namespace std;

class heap{
private:
    // vector<int> heap_array;
    int *heap_array = new int[10000];
    int no_of_nodes;
public:
    //we need a function to initialize a heap_array
    void initialize_heap(int *array,int a);
    //to build a heap
    void build_heap();
    //we need to insert an element without disturbing the min_heap property
    void insert_node(int value);
    //we need to delete the top most node and make it a min_heap again
    int delete_min_node();
    //min_heapifier function to make the tree from a particular node min_heap
    void min_heapify(int node_pos);
    //fucntion to get the sorted array,basically to print the sorted array
    void sort();
    //we need a make dot file function
    //void make_dot_file(int which_file);
    //function to swap two numbers in the vector given their node_pos
    void swap(int x, int y);

};
//to swap two values given their node_pos
void heap::swap(int x, int y){
    int temp = heap_array[x];
    heap_array[x] = heap_array[y];
    heap_array[y] = temp;
}
//min heapifies the given node
void heap::min_heapify(int index){
    int smallest_index = min(heap_array[index],min(heap_array[2*index],heap_array[2*index+1]));
    if(heap_array[smallest_index] == heap_array[index]) return;
    else{
        swap(smallest_index,index);
        min_heapify(smallest_index);
    }
}
//to build the min heap
void heap::build_heap(){
    for(int node_pos = no_of_nodes/2;node_pos>=0;node_pos--){
        min_heapify(node_pos);
    }
}
// to initialize the class data heap_array
void heap::initialize_heap(int * array,int n){
    no_of_nodes = n;
    //heap_array = new int[n];
    for(int i=0;i<n;i++){
        // heap_array.push_back(array[i]);
        heap_array[i] = array[i];
    }
}
//we assume that we have a minheap and then insert a value without disturbing
//the minheap property
void heap::insert_node(int value){
    // heap_array.push_back(value);
    no_of_nodes++;
    int n = no_of_nodes;
    int up = n/2,down = n;
    while (1) {
        if(heap_array[down] < heap_array[up]){
            swap(up,down);
            n = up;
            up = n/2;
            down = n;
        }
        else break;
    }
}
//deletes the min node and returns it
//then makes it a min heap again
int heap::delete_min_node(){
        int min = heap_array[0];
        heap_array[0] = heap_array[no_of_nodes];
        no_of_nodes--;
        min_heapify(0);
        return min;
}
//prints the sorted array
void heap::sort(){
    cout<<"the sorted array in ascending order is";
    int value=-1;
    while(no_of_nodes){
        value = delete_min_node();
        cout<<value<<"\t";
    }
    cout<<endl;
}

/*void heap::make_dot_file(int which_file){
    FILE *fp;
    string str="output",output_file_name1,output_file_name2;
    // if(which_file == INITIAL){
    //     output_file_name1 = str + INITIAL_HEAP + ".dot";
    //     output_file_name2 = str + INITIAL_HEAP;
    // }
    // // cout << output_file_name1 << "\n";
    // else if(which_file == INSERT){
    //     output_file_name1 = str + AFTER_INSERTING + ".dot";
    //     output_file_name2 = str + AFTER_INSERTING;
    //
    // }
    // else if(which_file)
    switch(which_file){
        case INITIAL:
                        output_file_name1 = str + INITIAL_HEAP + ".dot";
                        output_file_name2 = str + INITIAL_HEAP;
                        break;
        case DELETE:
                        output_file_name1 = str + AFTER_DELETING + ".dot";
                        output_file_name2 = str + AFTER_DELETING;
                        break;
        case INSERT:
                        output_file_name1 = str + AFTER_INSERTING + ".dot";
                        output_file_name2 = str + AFTER_INSERTING;
                        break;

    }
    const char * c1 = output_file_name1.c_str();
    const char * c2 = output_file_name2.c_str();
    // puts(c1);
    // puts(c2);
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
    fprintf(fp, "%s ","digraph");
    fprintf(fp, "%s{\n",c2);
    //fprintf(fp,"%s{\n","output");
    int down =1;
    for(int up=0;up < no_of_nodes / 2; up++) {
        int counter =0;
        while(counter < 2){
            fprintf(fp, "\t%d -> %d;\n",heap_array[up],heap_array[down]);
            //to ensure that down++ wont happen for the last node if #nodes are
            //even
            if(no_of_nodes%2 == 0 && up == no_of_nodes / 2 -1 ) break;

            down++;
            counter++;
        }
    }
    fprintf(fp,"%c",'}');
    cout<<output_file_name1<<" is generated"<<endl;
    fclose(fp);
}
*/
int main(int argc, char const *argv[]) {
    /* code */
    // int array[15];

    //assume that we get the input in a file to extract till we get a newline

    string line;
    int n;
    // vector<int> array;
    cin >> n;
    int *array = new int[n];
    // array.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    heap obj;
    obj.initialize_heap(array,n);
    obj.build_heap();
    //obj.make_dot_file(INITIAL);

    char choice = 'S';

    cout<<"I assume that you have given the array in a file through ./a.out < in.txt"<<endl;

    /*while(choice!='E'){
        cout<<"To insert: press I"<<endl;
        cout<<"To delete: press D"<<endl;
        cout<<"To print the sorted array: press S"<<endl;
        cout<<"To exit : press E"<<endl;
        cin>>choice;
        int key;
        switch(choice){
            case 'I':
                        cout<<"enter the value to be inserted:";
                        cin>>key;
                        obj.insert_node(key);
                        //obj.make_dot_file(INSERT);
                        break;
            case 'D':
                        cout<<"the deleted element is "<<obj.delete_min_node()<<endl;
                        //obj.make_dot_file(DELETE);
                        break;
            case 'S':
                        obj.sort();
                        break;
            default :
                        cout<<"Invalid Response"<<endl;
        }

    }*/

    // for(int node_pos = floor(no_of_vertices);node_pos>=0;node_pos--){
    //     //we will write after writing insert_node and delete_node functions
    // }

    //obj.insert_node(30);
    //obj.make_dot_file(INSERT);


    return 0;
}
bacjk
