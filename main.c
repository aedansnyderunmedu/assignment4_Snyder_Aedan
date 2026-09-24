#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_items(Item *item_list, double price, char *sku, char *category, char *name, int index) //each struct/field given enough memory via malloc.
{
	item_list[index].price = price;
	
	item_list[index].sku = malloc(strlen(sku) + 1); //plus 1 for the NULL terminator. 0
	strcpy(item_list[index].sku, sku); //copy given sku string into [index].sku. 
	
	item_list[index].category = malloc(strlen(category) + 1);
	strcpy(item_list[index].category, category);

	item_list[index].name = malloc(strlen(name) + 1);
	strcpy(item_list[index].name, name);
}

void print_items(Item *item_list, int size) //basic void print function, counting index by index for each field in each struct
{
	for(int i = 0; i < size; i++)
	{
		printf("================\n");
		printf("Item name: %s\n", item_list[i].name);
		printf("Item SKU: %s\n", item_list[i].sku);
		printf("Item category: %s\n", item_list[i].category);
		printf("Item price: %f\n", item_list[i].price);
		printf("================\n\n");
	}
}

double average_items(Item *item_list, int size)
{
	double sum = 0; //basic sum counter/index loop function
	for(int i = 0; i < size; i++)
	{
		sum += item_list[i].price;
	}
	return sum/(double)size;
}

void free_items(Item *item_list, int size)
{
	for(int i = 0; i < size; i++)
	{
		free(item_list[i].sku); //freeing each field within each struct sequentially
		free(item_list[i].category);
		free(item_list[i].name);
	}
	free(item_list); //freeing item_list entirely, after loop closure. 
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("Invalid entry; use %s<SKU> instead.\n", argv[0]); //input verification and rejection.
		return 1;
	}
	Item *item_list = malloc(5 * sizeof(Item));
	
	add_item(item_list, 15.00, "12345", "Antisieze", "WD40", 0); //list/inventory-building
	add_item(item_list, 3.50, "23456", "Degreaser", "BrakeKlean", 1);
	add_item(item_list, 50.00, "34567", "Synth Oil", "Valvoline 5W-30", 2);
	add_item(item_list, 11.33, "45678", "Transmission Fluid", "Mobil ATF", 3);
	add_item(item_list, 231.99, "56789", "Batteries", "Duralast S51/DL", 4);
	
	print_items(item_list, 5);

	printf("Store average item price: %f\n", average_price(item_list, 5)); //inline function call to calculate average. 
	
	char *sku = argv[1]; //user-entered sku set for comparison
	int ct = 0; //count variable
	
	while(ct < 5 && strcmp(item_list[ct].sku, sku) != 0) //AND (&&) operator reads LEFT to RIGHT. if strcmp happens BEFORE the loop verifies ct < 5, it can read values outside of allocated mem. Can read garbage or crash. 
	{
		ct++;
	}
	if(ct < 5)
		print_items(&item_list[ct], 1);
	else
		printf("Item not found!\n");
	free_items(item_list, 5);

	return 0; //close
}


