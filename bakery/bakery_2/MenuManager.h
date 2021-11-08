#pragma once
#ifndef MENUMANAGER_H
#define MENUMANAGER_H

class MenuManager
{
public:
	int insertMenu(Menu* menu);
	int deleteMenu(Menu* menu);
	bool checkAddMenu(Menu* menu);
	bool checkDelMenu(Menu* menu);
	bool checkInsertMenu(Menu* menu);
	Menu* viewMenu(int MenuCode);
};
#endif 
