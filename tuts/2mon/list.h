#include "Item.h"

// gDLList is defined as:  typedef struct gDLListRep *gDLList;

typedef struct gDLListNode {
        Item value;  // value of this list item
        struct gDLListNode *prev;
                     // pointer previous node in list
        struct gDLListNode *next;
                     // pointer to next node in list
} gDLListNode;

typedef struct gDLListRep {
        int nitems;      // count of Items in list
        gDLListNode *first; // first node in list
        gDLListNode *last;  // last node in list
        gDLListNode *curr;  // current node in list
} gDLListRep;
