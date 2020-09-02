typedef struct node* List;

List* create_list();
void free_list(List* li);

int get_size_list(List* li);
int check_list_empty(List* li);

int insert_list(List* li, int value);
int insert_list_sorted(List* li, int value);
int insert_list_last(List* li, int value);

int remove_list_at(List* li, int position);

int search_list_at(List* li, int pos, int *value);

void show_list(List* li);
