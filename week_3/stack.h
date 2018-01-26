/*
program description: stack implementation
*/


typedef struct stack
{
    int data;
    struct stack *next;
}stack;

void printStack(stack **top)
{
    stack *temp;
    temp=*top;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }

    // printf("\n");
}
void push(stack **top,int newValue)//function to push the element in to stack
{
    stack *temp;
    temp=(stack *)malloc(sizeof(stack));
    temp->data=newValue;
    temp->next=*top;
    *top=temp;
}
int pop(stack **top)//function to pop out the element
{
    int popValue;
    stack *temp;
    if( isEmpty(top) )
    {
        temp=*top;
        popValue=temp->data;
        *top=(*top)->next;
        free(temp);
        return popValue;
    }
    else
    {
        printf("\n Stack is empty");
        return -1;
    }
}
int isEmpty(stack **top)//checking whether the stack is empty or not
{
    if (*top == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
