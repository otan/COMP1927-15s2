#define TRUE 1
#define FALSE 0

typedef struct _node *Node;
typedef struct _list *List;

typedef struct _list {
    Node first;
    Node last;
    int size;
} list;

typedef struct _node {
    int data;
    Node next;
} node;

List createList(void);
Node createNode(int i);

int isSorted(List l);
