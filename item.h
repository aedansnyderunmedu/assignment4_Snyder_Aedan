#ifndef ITEM_H //include guards
#define ITEM_H
struct _Item
{
	double price;
	char *sku;
	char *name;
	char *category;
};
typedef struct _Item Item;

#endif//

