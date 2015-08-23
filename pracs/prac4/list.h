#define TRUE 1
#define FALSE 0

typedef struct _node *Node;

typedef struct _node {
    int data;
    Node next;
    Node random;
} node;

Node createNode(int i);

Node cloneList(Node first);
