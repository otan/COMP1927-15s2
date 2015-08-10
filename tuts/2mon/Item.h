// Item.h - Integer Items for use in GADTs

#ifndef ITEM_H
#define ITEM_H

#define EPISOLON 0.001

typedef float Item;

#define ItemCopy(x) (x)
#define ItemEQ(x,y) (fabs(y-x) < EPSILON)
#define ItemLT(x,y) ((x) < (y))
#define ItemLE(x,y) ((x) <= (y))
#define ItemGT(x,y) ((x) > (y))
#define ItemGE(x,y) ((x) >= (y))
#define ItemScan(x) atof((x))
#define ItemShow(f,x) fprintf((f),"%f",(x))

#endif ITEM_H

#ifndef ITEM_H
#define ITEM_H


typedef char* Item;

#define ItemCopy(x) (strdup(x))
#define ItemEQ(x,y) (strcmp(x,y) == 0)
#define ItemLT(x,y) (strcmp(x,y) < 0)
#define ItemLE(x,y) (strcmp(x,y) <= 0)
#define ItemGT(x,y) ((x))
#define ItemGE(x,y) ((x) >= (y))
#define ItemScan(x) x
#define ItemShow(f,x) fprintf((f),"%s",(x))

#endif ITEM_H
