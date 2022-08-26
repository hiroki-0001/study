#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

/* リストの先頭を指すポインタ */
static struct NODE *head = NULL;

void init_list(struct NODE *list)
{
    list->next = NULL;
    list->data = 0;
}

void print_list(struct NODE *list)
{
  struct NODE *p = list->next;
  printf("print_list(): ");

//  std::cout << p << std::endl;
 
  while (p) {
    printf("value(%d)->", p->data);
    p = p->next;
  }
 
  printf("NULL\n");
}

// リストの末尾にnodeを追加する
int add_to_end_list(int data)
{
    struct NODE *new_node;
    struct NODE *current_node;
    struct NODE *previous_node;

    new_node = (struct NODE*)malloc(sizeof(struct NODE));
    if(new_node == NULL)
    {
        return 1;
    }   
    new_node->data = data;
    current_node = head;

    current_node->next = new_node;
    new_node->next = NULL;
    return 0;

}


// nodeのデータ検索機能

/*
void search_data(int target_number)
{
    node = head;
    int node_number = 0;

    while(node != NULL)
    {
        if(node->number_data == target_number)
        {
            std::cout << "found target number" << std::endl;
            std::cout << "node number = " << node_number << std::endl;
        }
        node_number++;
        node = node->next;
    }
}
*/


int main(void){
    struct NODE list;
    init_list(&list);
    print_list(&list);
    //add_to_end_list(15);
    return 0;
}