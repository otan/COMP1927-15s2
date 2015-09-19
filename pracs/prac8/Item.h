// Item.h  ... definition for items in Queues
// Written by John Shepherd, March 2013

#ifndef ITEM_H
#define ITEM_H

#include "Graph.h"

typedef Edge Item;

#define ItemCopy(i)     (i)
#define ItemEQ(i1,i2)   ((i1).v == (i2).v && (i1).w == (i2).w))
#define ItemShow(i)     printf("(%d,%d)",(i).v,(i).w)

#endif

