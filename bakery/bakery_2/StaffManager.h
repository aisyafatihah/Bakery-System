
#ifndef STAFFMANAGER_H
#define STAFFMANAGER_H

class StaffManager
{
public:
	int staffRegisteration(Staff* staff);
	bool staffLogin(Staff* staff);
	int insertStaff(Staff* staff);
	bool staffTable(Staff* staff);
	
};
#endif 
