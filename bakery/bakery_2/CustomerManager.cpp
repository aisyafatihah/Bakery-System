#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Customer.h"
#include "CustomerManager.h"

int CustomerManager::insertCustomer(Customer* customer)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Customer VALUES (?,?,?)");

	ps->setInt(1, customer->CustomerNo);
	ps->setString(2, customer->CustomerName);
	ps->setString(3, customer->TypeOrder);

	int status = ps->executeUpdate();
	delete ps;

	return status;
}

int CustomerManager::removeCustomer(Customer* customer)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM customer WHERE CustomerNo = ?");

	ps->setInt(1, customer->CustomerNo);

	int status = ps->executeUpdate();
	delete ps;

	return status;
}

Customer* CustomerManager::printCustomer(string CustomerName)
{
	Customer* customer = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM customer WHERE CustomerName = ?");

	ps->setString(1, CustomerName);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		customer = new Customer();
		customer->CustomerNo = rs->getInt(1);
		customer->CustomerName = rs->getString(2);
		customer->TypeOrder = rs->getString(3);
		
		cout << "\n\t\tCustomer Number: " << customer->CustomerNo << endl;
		//cout << "Customer Name: " << customer->CustomerName << endl;
		//cout << "Type Order: " << customer->TypeOrder << endl;
	}


	delete ps;
	delete rs;

	return customer;
}

bool CustomerManager::checkAddCust(Customer* customer)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM customer WHERE CustomerNo=? ");

	ps->setInt(1, customer->CustomerNo);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		return false;
	}
	else
	{
		cout << "\n\t\tYour customer number is: " << customer->CustomerNo;
		delete rs;
		delete ps;

		return true;
	}
}

bool CustomerManager::checkDelCust(Customer* customer)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM customer WHERE CustomerNo=? ");

	ps->setInt(1, customer->CustomerNo);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		cout << "\n\t\tThat customer and order does not exist\n\n";
		return false;
	}
	else
	{
		
		delete rs;
		delete ps;

		return true;
	}
}

