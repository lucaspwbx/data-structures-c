struct node {
  int data;
  struct node *next;
};

extern struct node *create_stack(int data, struct node *list);
extern struct node *push(int data, struct node *list);
extern struct node *pop(struct node *list);
extern int peek(struct node *list);
