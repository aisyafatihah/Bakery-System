#include <iostream>
#include "Orders.h"
#include "OrderManager.h"
#include "Menu.h"
#include "MenuManager.h"
#include "Customer.h"
#include "CustomerManager.h"
#include "Staff.h"
#include "StaffManager.h"
#include<string>
#include <cstdlib>
#include <cstring>
#include <conio.h>

using namespace std;

StaffManager staffManager;
Staff* staff = new Staff();

OrderManager orderManager;
Orders* orders = new Orders();

CustomerManager customerManager;
Customer* customer = new Customer;

MenuManager menuManager;
Menu* menu = new Menu();

//global variable
int choose, choice, option, add, answer;
int MenuCode, CustomerNo, OrderNum;
double Total_price;
string tempid,CustomerName;

//function prototype
void main_menu();                  
void CustomerSection();           
void StaffSection();               
void exit();                       
void staffRegisteration();         
void staffLogin();                 
void viewMenu(int MenuCode);       
void enterCustomer();//(X)
void cancelOrder();					
void DeleteMenu();                 
void addMenu();                    
void calculateSale(int MenuCode);//(X)
void removeCustomer();             
void listOrder(int OrderNum);      
void enterOrder();
void removeCustomer1();
void cancelOrder1();
void newchoice();
void listOrder(int OrderNum);
void printCustNo(string CustomerName);

//Main Menu page
void main_menu()
{

	while (choice != 4)
	{
		system("pause");
		system("cls");
		cout << "\n\t\t\t\t*******************";
		cout << "\n\t\t\t\t*                 *";
		cout << "\n\t\t\t\t*    MAIN MENU    *";
		cout << "\n\t\t\t\t*                 *";
		cout << "\n\t\t\t\t*******************";
		cout << "\n\t\t";
		cout << "\n\n\n\t\t\t1.Customer";
		cout << "\n\t\t\t2.Staff";
		cout << "\n\t\t\t3.Exit";
		cout << "\n\n\t\t\tEnter Your Choice: ";
		cin >> choice;
		

		//customer choose what they want to do
		switch (choice)
		{
		case 1: CustomerSection();
			break;
		case 2: StaffSection();
			break;
		case 3: exit();
		default:
		{
			cout << "\n\n\t\t\tWrong choice!!!\n\n";
			
			main_menu();
		}
		}
		
	}
}

//Customer page
void CustomerSection()
{
	

	system("cls");
	cout << "\n\t\t\t\t************************************";
	cout << "\n\t\t\t\t*       Customer Section           *";
	cout << "\n\t\t\t\t************************************";
	cout << "\n\n\n\t\t\t1.View Menu";
	cout << "\n\t\t\t2.Place Order";
	cout << "\n\t\t\t3.Check Customer Number";
	cout << "\n\t\t\t4.Cancel Order";
	cout << "\n\t\t\t5.Exit";
	cout << "\n\t\t\t6.Back";
	cout << "\n\n\t\t\tEnter Your Choice: ";
	cin >> choose;
	
	//customer choose what they want to do
	if (choose == 1) {
		viewMenu(MenuCode);
	}
	else if (choose == 2) {
		enterCustomer();
	}
	else if(choose==3){
		printCustNo(CustomerName);
	}
	else if (choose == 4) {
		removeCustomer1();
	}
	else if (choose == 5) {
		exit();
	}
	else if (choose == 6) {
		main_menu();
	}
	else {
		cout << "\n\n\t\t\tWrong choice!!!\n";
		
		system("pause");
		CustomerSection();
	}
}

//Staff page
void StaffSection()
{
	
	system("cls");
	cout << "\n\t\t\t\t*************************************************";
	cout << "\n\t\t\t\t*                Staff's Section                *";
	cout << "\n\t\t\t\t*************************************************";
	cout << "\n\n\n\t\t\t1.Register";
	cout << "\n\t\t\t2.Log In";
	cout << "\n\t\t\t3.Exit";
	cout << "\n\t\t\t4.Back";
	cout << "\n\n\t\t\tEnter Your Choice: ";
	cin >> choose;

	//customer choose what they want to do
	if (choose == 1) {
		staffRegisteration();
	}
	else if (choose == 2) {
		staffLogin();
		newchoice();
	}
	else if (choose == 3) {
		exit();
	}
	else if (choose == 4) {
		main_menu();
	}
	else
		cout << "\n\t\tWrong number entered!";
	cout << "\n\t\tTry Again\n\n";
	system("pause");
	StaffSection();

}

//Staff Login
void staffLogin()
{

	system("pause");
	system("cls");
	string pass;
	int i = 0;
	char a;
	cout << "\t\t-----------------------------------------\n";
	cout << "\t\t              Staff Login                \n";
	cout << "\t\t-----------------------------------------\n";


	cout << "\n\t\tStaff ID: ";
	cin.ignore(1, '\n');
	getline(cin, tempid);
	staff->StaffID = tempid;

	
	
	cout << "\t\tPassword: ";
	getline(cin, staff->StaffPassword);

	/*for (i = 0;;) //infinite loop
	{
		a = _getch(); //stores char type in a
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {	//check if a is numeric or alphabet
			pass += a; //stores a in pass
			i++;
			cout << "*";
		}
		if (a == '\b' && i >= 1) //if user typed backspace and i should be greater than 1
		{
			cout << "\b \b"; //rub the character behind cursor
			--i;
		}
		if (a == '\r') //if enter 
		{
			pass += '\0'; //end of string
			break; //break the loop
		}
	}
	//staff->StaffPassword = pass;
	getline(cin, staff->StaffPassword);
	staff->StaffPassword = pass;*/

	if (staffManager.staffLogin(staff)) {
		cout << endl << endl;
		cout << "\t\t\tSuccessfully logged in." << endl << endl;
		
		system("pause");
		system("cls");
		newchoice();
	}
	else {
		system("pause");
		system("cls");
		StaffSection();
	}
}

//Staff Register
void staffRegisteration()
{

	system("cls");
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t             New Staff Registration          \n";
	cout << "\t\t---------------------------------------------\n";

	//cout << "\n\n\t\tEnter 1 to start ";
	//cin >> option;
	//if (option == 1) {
		cout << "\n\t\tPlease enter your details: " << endl << endl;
		cout << "\t\tEnter your ID:\t";
		cin.ignore();
		getline(cin, staff->StaffID);

		//error handling
		while ((staff->StaffID).length() != 5)
		{
			cout << "\n\t\tWrong Length of Staff ID!\n";
			cout << "\t\tPlease Try Again\n";

			cout << "\n\t\tID:\t";
			getline(cin, staff->StaffID);
		}

		cout << "\t\tName:\t";
		getline(cin, staff->StaffName);
	
		cout << "\t\tPassword: ";
		getline(cin, staff->StaffPassword);
		//error handling
		

		if (staffManager.staffTable(staff)) {

			int status = staffManager.insertStaff(staff);

			if (status != 0)
				cout << "\n\t\t\tSuccessfully register staff\n";
			else
				cout << "\t\t\tRegisteration unsuccessful. Please Try Again\n";

			system("pause");
			system("cls");
			StaffSection();
		}
		else {
			cout << "\t\t\tRegisteration unsuccessful. Please Try Again\n";
			system("pause");
			system("cls");
			StaffSection();
		}
	/*}

	else {
		cout << "\n\n";
		system("pause");
		system("cls");*/
		StaffSection();
	
}

//Customer place order
void enterCustomer()
{
	system("cls");

	cout << "\n\n" << endl;
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t*                    Order                  *\n";
	cout << "\t\t*          (Take Away / Dine In)            *\n";
	cout << "\t\t---------------------------------------------\n";

	cout << "\n\n\t\t(Make sure you already know your menu code and price)\n";
	cout << "\t\tPlease enter 1 to continue ordering ";
	cin >> option;
	if (option == 1) {

		cout << "\n\t\tPlease enter your details\n\n";

		/*cout << "\t\tInsert your phone number: ";
		cin >> customer->CustomerNo;*/

		cout << "\t\tName: ";
		cin.ignore(1, '\n');
		getline(cin, customer->CustomerName);

		/*cout << "\n\t\t(T-Take away || D-Dine In)\n";
		cout << "\t\t--------------------------\n";*/
		cout << "\n\t\tType of order: ";
		getline(cin, customer->TypeOrder);
		
	
		int status = customerManager.insertCustomer(customer);
		
		if (customerManager.checkAddCust(customer)) {

			if (status != 0)
			{
				cout << "\n\n\t\t\tSuccessfully add a customer\n";
				//printCustNo(CustomerName);
				//printCustNo(CustomerName);
				//enterOrder();
			}
			else {
				cout << "\n\n\t\t\tUnable to add a customer\n\n";
			}
			system("pause");
			system("cls");
			CustomerSection();
		  }
		else {
			cout << "\n\t\t\tCustomer is successfully added!" ;
			cout<<"\n\t\tPlease check your customer number (3) at 'Customer Section' to complete the order" << endl << endl;


			system("pause");
			system("cls");
			CustomerSection();
			}
	}
	else if (option == 2) {
		CustomerSection();
	}
	else {
		cout << "\n\t\tInvalid option! Please Try Again. " << endl << endl;
		customerManager.removeCustomer(customer);
	}

		
	}

//Staff remove customer upon order completion
void removeCustomer() {
	listOrder(OrderNum);
	int add;

	system("pause");
	system("cls");
	cout << "\n\n" << endl;
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t               Update Customer               \n";
	cout << "\t\t---------------------------------------------\n";

	cout << "\n\n\t\tEnter 1 to start ";
	cin >> option;
	if (option == 1) {

			cout << "\n\t\tPlease enter the details \n\n";

			cout << "\t\tCustomer Number: ";
			cin >> customer->CustomerNo;

			if (customerManager.checkDelCust(customer)) {

				int status = customerManager.removeCustomer(customer);

				if (status != 0){
					cout << "\n\t\t\tSuccessfully remove completed customer" << endl << endl;
				cancelOrder();
			}
				else
					cout << "\t\t\tUnable to remove completed customer" << endl << endl;
			}

		
		system("pause");
		system("cls");
		StaffSection();
	}
	else {
		cout << "\n\n\t\t\tCustomer removal is cancelled" << endl << endl;
		system("pause");
		system("cls");
		newchoice();
	}

}
	
void newchoice() {
		system("cls");
		cout << "\n\t\tPlease Choose one: \n";
		cout << "\n\t\t1 ------ Delete Menu";
		cout << "\n\t\t2 ------ Add Menu";
		cout << "\n\t\t3 ------ Calculate Sales";
		cout << "\n\t\t4 ------ Update Customer";
		cout << "\n\t\t5 ------ Exit";

		cout << "\n\t\tPlease enter number: ";
		cin >> option;
		if (option == 1) {
			DeleteMenu();
		}
		else if (option == 2) {
			addMenu();
		}
		else if (option == 3) {
			calculateSale(MenuCode);
		}
		else if (option == 4) {
			removeCustomer();
		}
		else if (option == 5) {
			exit();
		}
		else {
			cout << "\n\n\t\t\tWrong choice!!!\n\n";
			//cout << "\n\t\t\tPlease Restart Again\n\n";
			system("pause");
			newchoice();
		}
	}

//Staff Calculate Sale
void calculateSale(int MenuCode)
{
	system("pause");
	system("cls");

	OrderManager orderManager;
	Orders* total = new Orders();
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t                 Total Sales                    \n";
	cout << "\t\t---------------------------------------------\n";
	
	//cout << "\n\t\tEnter Any Number: ";
	//cin >> orders->MenuCode;

	cout << "\n\t\tTotal Sale: RM ";
	total = orderManager.printTotal(MenuCode);
	//cout << "\n\t\t" << sum;
	system("pause");
	system("cls");
	newchoice();
}

//Customer view menu
void viewMenu(int MenuCode)
{
	system("pause");
	system("cls");

	MenuManager menuManager;
	Menu* printmenu = new Menu();
	cout << "\t\t-----------------------------------------------------\n";
	cout << "\t\t                    List of menu \n";
	cout << "\t\t-----------------------------------------------------\n";

	printmenu = menuManager.viewMenu(MenuCode); 

	cout << "\n\n";

	system("pause");
	system("cls");
	CustomerSection();

}

//Staff view list order
void listOrder(int OrderNum)
{
	system("pause");
	system("cls");
	OrderManager orderManager;
	Orders* print = new Orders();
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t                   Order List                \n";
	cout << "\t\t---------------------------------------------\n";

	print = orderManager.viewOrder(OrderNum);

	cout << "\n\n";
	//system("pause");
	//system("cls");
	//StaffSection();

}

//Staff update Menu (DELETE Row menu code in database)
void DeleteMenu()
{
	MenuManager menuManager;
	Menu* menu = new Menu();

	system("pause");
	system("cls");
	cout << "\n\n" << endl;
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t               Menu Deletion                \n";
	cout << "\t\t---------------------------------------------\n";

	cout << "\n\n\t\tEnter 1 to start ";
	cin >> option;
	if (option == 1) {

		cout << "\n\t\tHow many menu you want to delete: ";
		cin >> add;

		while (add != 0) {
			add--;
			cout << "\n\t\tPlease enter the menu \n\n";

			cout << "\t\tMenu Code: ";
			cin >> menu->MenuCode;

			if (menuManager.checkDelMenu(menu)) {

				int status = menuManager.deleteMenu(menu);

				if (status != 0)
					cout << "\n\t\t\tSuccessfully remove a menu" << endl << endl;
				else
					cout << "\t\t\tUnable to remove a new menu" << endl << endl;
			}

		}
		system("pause");
		system("cls");
		newchoice();
	}
	else {
		cout << "\t\t\tMenu deletion is cancelled" << endl << endl;
		system("pause");
		system("cls");
		newchoice();
	}

	}

//Customer cancel Order
void cancelOrder()
{
	int option;

	system("pause");
	system("cls");
	OrderManager orderManager;
	Orders* cancel = new Orders();


	cout << "\n\n\n";
	cout << "\t\t\t-----------------------------------------\n";
	cout << "\t\t\t              Remove Order               \n";
	cout << "\t\t\t-----------------------------------------\n\n";

	/*cout << "\t\tPlease enter 1 to continue ";
	cin >> option;
	if (option == 1) {*/
		cout << "\n\t\tEnter the ORDER NUMBER : ";
		cin >> cancel->OrderNum; 

		if (orderManager.confirmDeletion(cancel)) {
			cout << "\n\n\t\tAre you sure you want to cancel this order? (Y/N) : ";
			char ans;
			cin >> ans;

			if (ans == 'Y' || ans == 'y') {
				orderManager.deleteOrder(cancel);
				cout << "\t\t\tOrder has been removed\n\n";
				system("pause");
				system("cls");
				newchoice();
			}
			else if (ans == 'N' || ans == 'n') {
				cout << "\t\t\tCancelling request aborted!\n\n";
				system("pause");
				system("cls");
				newchoice();
			}
			else {
				cout << "\n\t\tInvalid option!\n\n";
				orderManager.deleteOrder(cancel);
			}
		}
		else {
			cout << "\n\tNo order of this." << "\n\tPlease try again\n\n";
			orderManager.deleteOrder(cancel);
		}
	/*}
	else if (option == 2) {
		newchoice();
	}
	else {
		cout << "\n\t\tInvalid option! Please choose again. " << endl << endl;
		orderManager.deleteOrder(cancel);*/
	}
//}

void enterOrder()
{
	MenuManager menuManager;
	Menu* printmenu = new Menu();
	cout << "\n\n\t---------------Menu Available-------------------\n";
	printmenu = menuManager.viewMenu(MenuCode);
	cout << "\n\t---------------Completing your Order-------------------\n";
	cout << "\n\n\t(Make sure you already know your menu code and price)\n";
	/*cout << "\n\n\t\tEnter 1 to continue ordering ";
	cin >> option;
	if (option == 1) {*/
		cout << "\n\t\tPlease enter the details: \n\n";

				cout << "\n\t\tEnter Menu Code: ";
				//cin.ignore();
				cin >> orders->MenuCode;

			cout << "\t\tQuantity: ";
			cin >> orders->Quantity;

			cout << "\t\tMenu Price: ";
			cin >> orders->Menuprice;

			cout << "\t\tRe-enter your customer number: ";
			cin >> orders->OrderNum;
		

		if (orderManager.checkOrder(orders)) {
			int status = orderManager.insertOrder(orders);
			if (status != 0)
				cout << "\n\t\t\tSuccessfully added order" << endl << endl;
			else
				cout << "\t\t\tUnable to add order" << endl << endl;
		}

	
		system("pause");
		system("cls");
		CustomerSection();
	}
	

//Staff update menu (ADD)
void addMenu()
{
	MenuManager menuManager;
	Menu* menu = new Menu();
	int add;

	system("pause");
	system("cls");
	cout << "\n\n" << endl;
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t               Menu Insertion                \n";
	cout << "\t\t---------------------------------------------\n";

	cout << "\n\n\t\tEnter 1 to start ";
	cin >> option;
	if (option == 1) {

		cout << "\n\t\tHow many menu you want to add: ";
		cin >> add;

		while(add!=0) {
			add--;
		cout << "\n\t\tPlease enter the menu: \n\n";
		cout << "\t\tMenu Name: ";
		cin.ignore();
		getline(cin, menu->MenuName);

		cout << "\t\tMenu Code: ";
		cin >> menu ->MenuCode;

		cout << "\t\tMenu Price: ";
		cin >> menu->Price;
	
		if (menuManager.checkAddMenu(menu)) {

			int status = menuManager.insertMenu(menu);

			if (status != 0)
				cout << "\n\t\t\tSuccessfully added a menu" << endl << endl;
			else
				cout << "\t\t\tUnable to add a new menu" << endl << endl;
		  }
		
		}
		system("pause");
		system("cls");
		newchoice();
	}
	else {
		cout << "\t\t\tMenu insertion is cancelled" << endl << endl;
		system("pause");
		system("cls");
		newchoice();
	}

}

void removeCustomer1() {

	int add;

	system("pause");
	system("cls");
	cout << "\n\n" << endl;
	cout << "\t\t---------------------------------------------\n";
	cout << "\t\t               Cancel Order                  \n";
	cout << "\t\t---------------------------------------------\n";

	cout << "\n\n\t\tEnter 1 to start ";
	cin >> option;
	if (option == 1) {

			cout << "\n\t\tPlease enter the details \n\n";

			cout << "\t\tCustomer Number: ";
			cin >> customer->CustomerNo;

			if (customerManager.checkDelCust(customer)) {

				int status = customerManager.removeCustomer(customer);

				if (status != 0) {
					cout << "\n\t\t\tSuccessfully removed" << endl << endl;
					cancelOrder1();
				}
					
				else
					cout << "\t\t\tUnable to remove" << endl << endl;
			}

		
		system("pause");
		system("cls");
		CustomerSection();
	}
	else {
		cout << "\n\n\t\t\tCustomer removal is cancelled" << endl << endl;
		system("pause");
		system("cls");
		CustomerSection();
	}

}
void cancelOrder1()
{
	int option;

	system("pause");
	system("cls");
	OrderManager orderManager;
	Orders* cancel = new Orders();


	cout << "\n\n\n";
	cout << "\t\t\t-----------------------------------------\n";
	cout << "\t\t\t              Cancel Order               \n";
	cout << "\t\t\t-----------------------------------------\n\n";

	/*cout << "\t\tPlease enter 1 to continue ";
	cin >> option;
	if (option == 1) {*/
		cout << "\n\t\tEnter the your ORDER NUMBER : ";
		cin >> cancel->OrderNum;

		if (orderManager.confirmDeletion(cancel)) {
			cout << "\n\n\t\tAre you sure you want to cancel this order? (Y/N) : ";
			char ans;
			cin >> ans;

			if (ans == 'Y' || ans == 'y') {
				orderManager.deleteOrder(cancel);
				cout << "\t\t\tOrder has been removed\n\n";
				system("pause");
				system("cls");
				CustomerSection();
			}
			else if (ans == 'N' || ans == 'n') {
				cout << "\t\t\tCancelling request aborted!\n\n";
				system("pause");
				system("cls");
				CustomerSection();
			}
			else {
				cout << "\n\t\tInvalid option!\n\n";
				orderManager.deleteOrder(cancel);
			}
		}
		else {
			cout << "\n\tYou have not book any menu of this." << "\n\tPlease try again\n\n";
			orderManager.deleteOrder(cancel);

		}
	/*}
	else if (option == 2) {
		CustomerSection();
	}
	else {
		cout << "\n\t\tInvalid option! Please choose again. " << endl << endl;
		orderManager.deleteOrder(cancel);
	}*/
}

void printCustNo(string CustomerName) {
	
	system("pause");
	system("cls");
	string name;
	CustomerManager customerManager;
	Customer* printCust = new Customer();

	cout << "\n\t\tEnter your name again to check your customer no \n\t\t\t-";
	cin.ignore(1, '\n');
	getline(cin, name);

	customer->CustomerName = name;

	printCust = customerManager.printCustomer(customer->CustomerName);


	enterOrder();
	cout << "\n\n";
	system("pause");
	system("cls");

}

void exit()
{
	system("pause");
	system("cls");
	cout << "\n\t\t\t**********************************";
	cout << "\n\t\t\t*          THANK YOU             *";
	cout << "\n\t\t\t**********************************\n\n\n";
	exit(1);
}

int main()
{

	system("pause");
	system("cls");
	cout << "\n\t\t\t**********************************";
	cout << "\n\t\t\t*                                *";
	cout << "\n\t\t\t*   WELCOME TO BUTTER'S BAKERY   *";
	cout << "\n\t\t\t*                                *";
	cout << "\n\t\t\t**********************************\n\n\n";
	main_menu();
	
}
