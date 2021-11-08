#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Staff.h"
#include "StaffManager.h"

int StaffManager::staffRegisteration(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO staff VALUES (?,?,?)");

	ps->setString(1, staff-> StaffID);
	ps->setString(2, staff->StaffName);
	ps->setString(3, staff->StaffPassword);

	int status = ps->executeUpdate();
	delete ps;

	return status;
}

bool StaffManager::staffLogin(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM staff WHERE StaffID = ?");

	ps->setString(1, staff->StaffID);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		cout << "\n\t\tThat ID does not exist" << endl << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		ps = dbConn.prepareStatement("SELECT * FROM staff WHERE StaffID = ? AND StaffPassword = ?");

		ps->setString(1, staff->StaffID);
		ps->setString(2, staff->StaffPassword);

		rs = ps->executeQuery();

		if (!(rs->next()))
		{
			cout << "\n\t\t\tWrong password! Please try again " << endl << endl;
			return false;
		}

		delete rs;
		delete ps;
	}

	return true;
}

int StaffManager::insertStaff(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO staff VALUES (?,?,?)");

	ps->setString(1, staff->StaffID);
	ps->setString(2, staff->StaffName);
	ps->setString(3, staff->StaffPassword);

	int status = ps->executeUpdate();
	delete ps;

	return status;
}

bool StaffManager::staffTable(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM staff WHERE StaffID = ?");

	ps->setString(1, staff->StaffID);

	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		cout << "\n\n\t\t\tThis staff is already registered!" << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}



