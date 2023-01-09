#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Node
{
    long data;
    struct Node* next; //pointer called next points to another struct Node
};

struct Node* top; 

void pop();
void push(long num);
void enqueue(long num);
void print_list();


int main(int argc, char* argv[]) //check this
{

    
FILE*fp = fopen(argv[1], "r"); //open the file to read
//top = NULL;
long num;
char s1[7];
while(fscanf(fp, "%s %ld\n", s1, &num) != EOF)
{

    if (strcmp(s1, "POP")== 0)
    {
        
        pop(); 
        print_list();

    }
    else if (strcmp(s1, "PUSH")== 0)
    {
        
        push(num); //push node
        print_list();
    }
    else if (strcmp(s1, "ENQUEUE")== 0)
    {
        
        
        enqueue(num);
        print_list();
    }
    else printf("error");

}
    fclose(fp);
    EXIT_SUCCESS;
}

void pop()
{
    if(top!=NULL)
    {
  struct Node* temp = top;
  top = top->next;
  free(temp); 
    }
  
}

void push(long num)
{
    
    struct Node* new_node = malloc(sizeof(struct Node)); //make new node
    new_node->next = top; //make new node point to top
    new_node->data = num;  
    top = new_node;  

}
void enqueue(long num) 
{
    if(top!=NULL){
    struct Node* temp = top; //points to the head
    while(temp->next!=NULL) //(*temp).next
    {
        temp = temp->next; 
    }
    struct Node* new_node = malloc(sizeof(struct Node));
    temp->next = new_node;
    new_node->data=num;
    }
    else
    {
        push(num);
    }
}

void print_list()
{
    if(top==NULL)
    {
        printf("EMPTY");
    }
    struct Node *temp;
    temp=top;
    while(temp!=NULL)
    {
        printf("%ld ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
