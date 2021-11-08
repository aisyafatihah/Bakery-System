#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Menu.h"
#include "MenuManager.h"

int MenuManager::insertMenu(Menu* menu)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO menu VALUES (?,?,?)");

	ps->setInt(1, menu->MenuCode);
	ps->setString(2, menu->MenuName);
	ps->setDouble(3, menu ->Price);

	int status = ps->executeUpdate();
	delete ps;

	return status;
}

int MenuManager::deleteMenu(Menu* menu)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM menu WHERE MenuCode = ? ");

	ps->setInt(1, menu->MenuCode);

	int status = ps->executeUpdate();
	delete ps;

	return status;
}

Menu* MenuManager::viewMenu(int MenuCode)
{
	Menu* menu = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Menu");

	ResultSet* rs = ps->executeQuery();

	while (rs->next())
	{
		menu = new Menu();
		menu->MenuCode = rs->getInt(1);
		menu->MenuName = rs->getString(2);
		menu->Price = rs->getDouble(3);

		cout << "\n\t\tMenu Code: " << menu->MenuCode;
		cout << "\n\t\tMenu Name: " << menu->MenuName;
		cout << "\n\t\tPrice: " << menu->Price << "\n\n";

	}
	delete ps;
	delete rs;

	return menu;

}

bool MenuManager::checkAddMenu(Menu* menu)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM menu WHERE MenuCode = ?");

	ps->setInt(1, menu ->MenuCode);

	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		cout << "\n\n\t\t\tMenu already added!" << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

bool MenuManager::checkDelMenu(Menu* menu)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM menu WHERE MenuCode = ?");

	ps->setInt(1, menu->MenuCode);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		cout << "\n\t\tThat menu is not exist\n\n\n";
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

bool MenuManager::checkInsertMenu(Menu* menu)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM menu WHERE MenuCode = ?");

	ps->setInt(1, menu->MenuCode);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		cout << "\n\n\t\t\tThat menu did not exist!" << endl;
		cout << "\n\t\t\tPlease enter a correct menu code";
		return false;
	}
	else
	{
		delete rs;
		delete ps;
		return true;
	}
}

