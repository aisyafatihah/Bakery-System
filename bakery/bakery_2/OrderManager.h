
#include <string>
using namespace std;

#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

class OrderManager
{
public:
	Orders* viewOrder(int OrderNum);
	Orders* printOrder(int OrderNum);
	int deleteOrder(Orders* orders);
	int insertOrder(Orders* orders);
	bool checkOrder(Orders* orders);
	bool confirmDeletion(Orders* orders);
	Orders* printTotal(int MenuCode);
};
#endif 
