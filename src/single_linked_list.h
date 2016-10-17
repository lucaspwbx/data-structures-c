struct node {
  int data;
  struct node *next;
};

extern struct node *create_list(int data, struct node *list);
extern struct node *insert_end(int data, struct node *list);
extern struct node *insert_begin(int data, struct node *list);
extern struct node *insert_after(int search_data, int data, struct node *list);
extern struct node *insert_before(int search_data, int data, struct node *list);
