#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void insert(long num);
void delete_node(long num);
void print_list();
bool isDuplicate(long num);
struct Node* find_node_previous(long num);

struct Node
{
    long data;
    struct Node* next; //pointer called next points to another struct Node
};

struct Node* head;

int main(int argc, char* argv[]) //check this
{
    
FILE*fp = fopen(argv[1], "r"); //open the file to read
if(fp==NULL)
{
 printf("error");
 return EXIT_SUCCESS;
}

  
    char s1[7]; //array is a pointer, call by name bc has address
    
     
    long num;
    
    while (fscanf(fp, "%s %ld\n", s1, &num) != EOF)//get string
    {
        //printf("cmd: %s %d\n",  s1, num);
    if ((strcmp(s1, "INSERT")== 0) && (!isDuplicate(num)))
    {
       
        insert(num);
        print_list();// fix method needs to print after every head
       

    }
    else if (strcmp(s1, "DELETE")==0) //get string
    {
       
        delete_node(num);
       
        print_list();// fix method needs to print after every head
        
    }
    else if ((strcmp(s1, "INSERT")== 0) && (isDuplicate(num))) //silently ignore 
    {
        print_list();
        
    }
    else printf("error");
    }
    
    fclose(fp);
    EXIT_SUCCESS;

}
void insert(long num)
{
    
    if(head == NULL)
    {
        struct Node* new_node = malloc(sizeof(struct Node)); //make a pointer new that points to type node
        head = new_node;
        new_node->data = num;
        return;
    }
    else
    {
        if(num<head->data) //inserting before head
            {
                
                struct Node* new_node = malloc(sizeof(struct Node));
                new_node->next = head;
                head = new_node;
                new_node-> data = num;
                return;
            }
        else 
        {
            struct Node* temp = head;
            while(temp!=NULL) //if not at the end of list
            {
                if(temp-> next == NULL) //if temp is at the last node/ add after
                {
                    //printf("hello\n");
                    struct Node* new_node = malloc(sizeof(struct Node));
                    temp->next = new_node;
                    new_node->data = num; 
                    return;      
                }
                else if((num>temp->data && num < (temp->next)->data)) // add in between
                {
                    struct Node* new_node = malloc(sizeof(struct Node));
                    new_node->next = temp->next;
                    temp->next = new_node;
                    new_node->data = num;
                    return;

                                        
                }
                temp = temp->next;
                
            }
        }

    }


     //new->next = *head; // get what new points to. Then, of that value, make the next property equal what head points to
     //*head = new; //head now points to new   
   
}

void delete_node(long num)
{
 if(head!=NULL) //if none exist 
 {
    if(head->data == num) //if num to delete is at head
    {
        if(head->next==NULL) //if one exists only
        {
            free(head);
            head=NULL;
            return;

        }
        else
        {
        struct Node* temp = head;
        head= temp->next;
        free(temp);
        return;
        }

        
    }
    else //multiple exist
    {
     struct Node* found_node_previous = find_node_previous(num);

     if(found_node_previous ==NULL) //if node does not exist
     {
        return;
     }
     else
     {
        //printf("hello1\n");
        struct Node* temp = found_node_previous->next;
        found_node_previous->next = (found_node_previous->next)->next;
        free(temp);
        return;
     }
    }
 }
    
    
}


void print_list()
{
    struct Node* temp = head;
    if(head==NULL)
    {
        printf("EMPTY\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%ld ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool isDuplicate(long num)
{
    struct Node* current = head; 
    while(current!=NULL)
    {
        if(current->data==num)
            return true;
        else 
            current = current->next;
    }
    return false;

}

struct Node* find_node_previous(long num)
{
    
    struct Node* temp = head;
    while(temp->next!=NULL)
    {
        if((temp->next)->data ==num)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }

    return NULL; //node does not exist
}




