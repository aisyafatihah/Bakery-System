#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Orders.h"
#include "OrderManager.h"

int OrderManager::insertOrder(Orders* orders)
{
	DatabaseConnection dbConn; 
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO orders VALUES (?,?,?,?,?)");

	ps-> setInt(1, orders-> MenuCode);
	ps->setInt(2, orders->Quantity);
	ps->setDouble(3, orders->Menuprice);
	ps->setInt(4, orders->OrderNum);
	ps->setDouble(5, orders->Total_price = orders->Quantity*orders->Menuprice);

	int status = ps->executeUpdate();
	delete ps;

	return status;
}

int OrderManager::deleteOrder(Orders* orders)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM orders WHERE OrderNum = ? ");

	ps->setInt(1, orders->OrderNum);

	int status = ps->executeUpdate();
	delete ps;

	return status;
}

//Print All
Orders* OrderManager::viewOrder(int OrderNum)
{
	Orders* orders = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Orders");

	ResultSet* rs = ps->executeQuery();

	while (rs->next())
	{
		orders = new Orders();
		
		orders->MenuCode = rs->getInt(1);
		orders->Quantity = rs->getInt(2);
		orders->Menuprice = rs->getDouble(3);
		orders->OrderNum = rs->getInt(4);

		cout << "Order Number: " << orders->OrderNum << endl;
		cout << "Menu Code: " << orders->MenuCode << endl;
		cout << "Quantity: " << orders-> Quantity << endl;
		cout << "Menu Price: " << orders->Menuprice << endl << endl;
	}
	delete ps;
	delete rs;

	return orders;
}

//Print one only
Orders* OrderManager::printOrder(int CustomerNo)
{
	Orders* orders = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM orders WHERE OrderNum =?)");
	ps->setInt(1, orders->OrderNum);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		orders = new Orders();
		orders->OrderNum = rs->getInt(1);
		orders->MenuCode = rs->getInt(2);
		orders->Quantity = rs->getInt(3);
		orders->Menuprice = rs->getDouble(4);

		cout << "\n\t\tOrder Number: " << orders->OrderNum << endl;
		cout << "\n\t\tMenu Code: " << orders->MenuCode << endl;
		cout << "\n\t\tQuantity: " << orders->Quantity << endl;
		cout << "\n\t\tTotal Price: " << orders->Menuprice << endl << endl;
	}
	delete ps;
	delete rs;

	return orders;
} 

bool OrderManager::checkOrder(Orders* orders)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM orders WHERE OrderNum = ?");

	ps->setInt(1, orders->OrderNum);

	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		cout << "\n\n\t\t\tOrder already exists!" << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

Orders* OrderManager::printTotal(int MenuCode)
{
	Orders* orders = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT SUM(Total_price) FROM orders");
	

	ResultSet* rs = ps->executeQuery();
	
	if (rs->next())
	{
		orders = new Orders();
		orders->Total_price = rs->getDouble(1);
		cout << orders->Total_price;

		cout << "\n\t\t";
		
	}
	delete ps;
	delete rs;

	return orders;
}

bool OrderManager::confirmDeletion(Orders* orders)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM orders WHERE OrderNum = ?");

	ps->setInt(1, orders->OrderNum);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

