#include <stdlib.h>
#include <stdio.h>


typedef struct Node{
        int data;
        struct Node* next;
} node;

node* head;

void Prepend(){  
    //UI
    printf("----------------------------------------\n");
    int x;
    printf("type the value of the new node: ");
    printf(" > ");
    scanf("%d", &x);
    //Logic
    node* temp = (node*)malloc(sizeof(node));

    temp->data = x;
    temp->next = head;

    head = temp;

}
void _append(int x){
    // step 1
    node* temp = (node*)malloc(sizeof(node));
    node *last = head;
    // step 2 & 3
    temp->data = x;
    temp->next = NULL;
    //step 4
    if (head == NULL){
        head = temp;
        return;
    }
    //step 5
    while (last->next != NULL)
        last = last->next;
    //step 6
    last->next = temp;
}
void Append(){
    //UI
    printf("----------------------------------------\n");
    int x;
    printf("type the value of the new node: ");
    printf(" > ");
    scanf("%d", &x);
    //Logic
    // step 1
    node* temp = (node*)malloc(sizeof(node));
    node *last = head;
    // step 2 & 3
    temp->data = x;
    temp->next = NULL;
    //step 4
    if (head == NULL){
        head = temp;
        return;
    }
    //step 5
    while (last->next != NULL)
        last = last->next;
    //step 6
    last->next = temp;


}

void Insert(){
    //UI
    printf("----------------------------------------\n");
    int pos, x;
    printf("type the position of the new node: ");
    printf(" > ");
    scanf("%d", &pos);
    printf("type the value of the new node: ");
    printf(" > ");
    scanf("%d", &x);

    //Logic
    node* temp1 = (node*)malloc(sizeof(node)); 
    temp1->data = x;
    temp1->next = NULL;
    if (pos == 1){
        temp1->next = head;
        head = temp1;
        return;
    }

    node* temp2 = head;
    for (int i = 0; i < pos-2; i++){
        temp2 = temp2 -> next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;


}

void Delete(){
    //UI
    printf("----------------------------------------\n");
    int pos;
    printf("type the position of the node to delete: ");
    printf(" > ");
    scanf("%d", &pos);

    //Logic
    node* temp1 = head;
    
    if(pos==1){
        head = temp1->next; //head now points to seconde node
        free(temp1);
        return;
    }
    for (int i = 0; i < pos-2; i++)
        temp1 = temp1->next;
    //temp1 points to (n-1)th Node
    node* temp2 = temp1->next; //nth node
    temp1->next =temp2->next; //(n+1)th node
    free(temp2);
    

}

void Reverse(){
    //Logic
    node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

}

void Print(){
    //UI
    printf("----------------------------------------\n");
    //Logic
    node* temp = head;
    printf("the list: ");
    while(temp != NULL){
        printf(" %d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");

}
void _print(){
    //Logic
    node* temp = head;
    printf("the list: ");
    while(temp != NULL){
        printf(" %d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
void Serialize(){
    FILE* file = fopen("list.txt", "w");
    if (file == NULL){
        printf("no such file, sorry...");
        return;
    }

    for (node* curr = head; curr != NULL; curr=curr->next){
        fprintf(file, "%d -> ",curr->data );
    }
    fclose(file);
}

void Deserialize(){
    FILE* file = fopen("list.txt", "r");
    if (file == NULL){
        printf("no such file, sorry...");
        return;
    }

    int val;
    while(fscanf(file, "%d -> ",&val) > 0){
        _append(val);
    }
    fclose;
}

void Search(){
    //UI
    printf("----------------------------------------\n");
    int val, count = 0;
    printf("input the value to look for:\n");
    printf(" > ");
    scanf("%d", &val);
    //Logic
    for (node* curr = head; curr != NULL; curr = curr->next){
        count++;
        if (curr->data == val){
            printf("the adress of the node: %d\n", count);
            return;
        }
    }
    printf("such a node does not exist\n");
    return;
    
}
// Sorting the array

// Getting the last node of the list
node* last_node(){
    node* temp = head;
    while (temp != NULL && temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}
    //Putting the last node in ins proper position
node* partition(node* first, node* last){
    node* pivot = first;
    node* front = first;
    int temp = 0;
    while (front != NULL && front != last){
        if (front->data < last->data){
            pivot = first;

            //Swapping the node values
            temp = first->data;
            first->data = front->data;
            front->data = temp;
        
            //Visiting the next node
            first = first->next;
        }

        //Visiting the next node
        front = front->next;
    }

    //Change last node value to current node
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}

void Sort(node* first, node* last){

    if (first == last) {
        return;
    }
    node* pivot = partition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        Sort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) {
        Sort(first, pivot);
    }


}

int main(){

    head = NULL;
    int choice1, choice2, number_of_elements;
    //logic variable
    int exit = 0;


    printf("create a linked list?\n [1] yes\n [2] no\n [3] deserialize\n [4] create a doubly linked list\n");
    printf(" > ");
    scanf("%d", &choice1);

    switch (choice1)
    {
    case 1:
        printf("----------------------------------------\n");
        printf("how many elements will your list have?\n");
        printf(" > ");
        scanf("%d",&number_of_elements);
        for (int i = 0; i < number_of_elements; i++){
            Append();
        }
        Print();
        break;
    case 2:
        printf("suit yourself\nexiting...");
        break;
    case 3:
        Deserialize();
        break;
    default:
        break;
    }

    while(exit == 0){
        printf("----------------------------------------\n");
        printf("what do you want to do next?\n [1] add a node to the nth position\n [2] append a node\n [3] prepend a node\n [4] delete a node\n [5] reverse\n [6] print\n [7] serialize\n [8] search\n [9] sort\n [0] exit\n");
        printf(" > ");
        scanf("%d", &choice2);
            switch (choice2)
            {
            case 1:
                Insert();
                Print();
                break;
            case 2:
                Append();
                Print();
                break;
            case 3:
                Prepend();
                Print();
                break;
            case 4:
                Delete();
                Print();
                break;
            case 5:
                Reverse();
                Print();
                break;
            case 6:
                Print();
                break;
            case 7:
                Serialize();
                break;
            case 8:
                Search();
                break;
            case 9:
                Print();
                Sort(head, last_node());
                Print();
                break;
            case 0:
                printf("exiting...\n");
                exit = 1;
                break;
            default:
                break;
            }
        }
    return 0;
}