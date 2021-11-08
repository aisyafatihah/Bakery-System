#ifndef DINEINMANAGER_H
#define DINEINMANAGER_H

class DineInManager
{
public:
	int insertOrder(DineIn* dinein);
	int cancelOrder(DineIn* dinein);
	DineIn* printOrder(int TableNo);
};
#endif 
