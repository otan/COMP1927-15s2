#define TRUE 1
#define FALSE 0

typedef struct _node *Node;
typedef struct _list *List;

typedef struct _list {
    Node first;
    Node last;
} list;

typedef struct _node {
    char data;
    Node next;
    Node prev;
} node;

List createList(void);
Node createNode(char i);

int isPalindrome(List l);
