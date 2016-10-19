struct node {
  int data;
  struct node *next;
};

extern struct node *create_queue(int data, struct node *list);
extern struct node *enqueue(int data, struct node *list);
extern struct node *dequeue(struct node *list);
extern int is_empty(struct node *list);
