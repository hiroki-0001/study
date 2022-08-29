#include <iostream>

struct NODE {
    int data;
    struct NODE *next;
    struct NODE *prev;
};

// リストのNODEの初期化
void init_list(struct NODE *list)
{
    list->next = nullptr;
    list->data = 0;
}

// リストのdataの出力
void print_list(struct NODE *list)
{
    struct NODE *p = list->next;
    std::cout << "print_list(): ";

    while (p) 
    {
        std::cout << p->data << ", ";
        p = p->next;
    } 
    std::cout << "NULL" << std::endl;
}

// リストの末尾にnodeを追加する
int add_to_end_list(struct NODE *list, int data)
{
    struct NODE *new_node;
    struct NODE *current_node = list;

    new_node = new NODE;
    if(new_node == nullptr)
    {
        return 1;
    }

    while(current_node->next)
    {
        current_node = current_node -> next;
    }

    new_node->data = data;
    current_node->next = new_node;
    new_node->next = nullptr;
    return 0;

}

void clear_list(struct NODE *list)
{
  struct NODE *prev = list->next;
  struct NODE *node;
 
  while (prev) {
    node = prev->next;
    free(prev);
    prev = node;
  }
 
  init_list(list);
}


int main(void){
    struct NODE list;
    init_list(&list);

    int list_size;
    std::cout << "作成するリストのNODE数を入力してください" << std::endl;
    std::cin >> list_size;
    std::cout << "数値データを入力してください" << std::endl;
    for(int i = 0; i < list_size; i++)
    {
        int node_data;
        std::cout << i+1 << " : ";
        std::cin >> node_data;
        add_to_end_list(&list, node_data);
    }
    print_list(&list);
    clear_list(&list);
    print_list(&list);

    return 0;
}