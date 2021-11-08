#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

class CustomerManager
{
public:
	int insertCustomer(Customer* customer);
	int removeCustomer(Customer* customer);
	Customer* printCustomer(string CustomerName);
	bool checkAddCust(Customer* customer);
	bool checkDelCust(Customer* customer);
};
#endif 
