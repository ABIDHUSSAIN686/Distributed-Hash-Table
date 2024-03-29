#include<iostream>
#include"Header.h"
#include<string>
#include <stdio.h>
#include <windows.h>
using namespace std;
int main()
{
	Identifierspace space;
	int UserChoice;
	int No_of_Machines, No_of_Bits, dht, m_id = 0, x = 0;
	string key, data;
	string feedback1 = "";
	system("Color C4");
	int want = 0;
	cout << "\033[0;36m";
	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWelCome To Our Company ASA\n\n\n";
	cout << "\n\t\t\t\t\tDo you want to be a part of our company\n\n\t\t\t\t\tPress (1) to Strat.\n";
	cout << "\n\t\t\t\t\tPress (2) to Exit.\n";
	cout << "\n\t\t\t\t\t";
	cin >> want;

	while (want < 0 || want > 3) {
		cout << "Invalid Entry\nAgain input: ";
		cin >> want;
	}
	if (want == 1) {
		Beep(50000, 500);
		system("cls");
	}
	else if (want == 2) {
		for (int x = 0; x < 3; x++)
			Beep(50000, 500);
		system("cls");
		exit(0);
	}

	//taking input no of bits to create identifier space
	system("Color F1");
	cout << "\033[0;36m";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tGood To See You\n\n\n\n";
	cout << "\t\t\t\t\tEnter Number of Bits (Range: 1 --> 160) : \n\t\t\t\t\t";
	cin >> No_of_Bits;
	while (No_of_Bits > 160 || No_of_Bits < 1)
	{
		cout << "Out of Range Try Again" << endl;
		cin >> No_of_Bits;
	}
	insert(No_of_Bits, space);
	system("cls");

	//taking input no of machines to create on 2identifier space
	system("Color 80");
	cout << "\033[0;33m";
	x = pow(2, No_of_Bits);
	cout << "Enter Total Number of Machines: \n";
	cin >> No_of_Machines;
	while (No_of_Machines<0 || No_of_Machines>x) {
		cout << "Invalid No of machines\nEnter again: ";
		cin >> No_of_Machines;
	}
	addingMachine(No_of_Machines, space);
	system("cls");
	//assiging the machines
	system("Color 81");
	int choice1 = 0;
	cout << "\t\t\tPress 1 if you want to assign manually IDs  machines. \n\n ";
	cout << "\t\t\tPress 2 if you want to assign Automatically IDs  machines.\n \n ";
	cin >> choice1;
choiceAgain:;
	if (choice1 == 1) {
		Creat_Machines(space.Total_No_Machine, space);
	}
	else if (choice1 == 2) {
		Creat_Machines_Automatically(space.Total_No_Machine, space);
	}
	else if (choice1 > 3) {
		cout << "\n\nInvalid Input\n\nenter Again: ";
		cin >> choice1;
		goto choiceAgain;
	}
	system("cls");
	system("Color 4F");//4 = red & f text white.
	cout << "\033[0;31m";
Menu:
	cout << "\t\t\t\t\t\t----------------------\n";
	cout << "\n\t\t\t\t\t\t\tMenu\n\n";
	cout << "\t\t\t\t\t\t----------------------\n\n";

	cout << "\t\t\tPress 1 Displaying IDs handled by a Machine. \n\n ";
	cout << "\t\t\tPress 2 Add a new Machine on the Fly. \n\n ";
	cout << "\t\t\tPress 3 Delete a Machine on the Fly. \n\n ";
	cout << "\t\t\tPress 4 To Display DHT of a Machine.\n\n ";
	cout << "\t\t\tPress 5 To Enter Data \n\n";
	cout << "\t\t\tPress 6 To search data using Key: \n\n ";
	cout << "\t\t\tPress 7 To Delete data using Key: \n\n ";
	cout << "\t\t\tPress 8 To print AVL Tree using Key \n\n ";
	cout << "\t\t\tPress 0 to exit.\n\n";
start:
	cin >> UserChoice;
	Beep(750, 800);
	switch (UserChoice)
	{
	case 1:
		system("cls");
		cout << "\033[0;33m";
		system("Color 6F");
		space.display_handling_IDs_by_Machine();
		goto Menu;
	case 2:
		system("Color B0");
		cout << "\033[0;33m";
		Add_Machine_on_Fly(space);
		system("cls");
		goto Menu;
	case 3:
		system("Color 84");
		cout << "\033[0;33m";
		Delete_Machine_on_Fly(space);
		system("cls");
		goto Menu;
	case 4:
		system("Color B2");
		cout << "\033[0;33m";
		system("cls");
		space.Machine_DHT_Display();
		goto Menu;
	case 5:
		system("Color E4");
		cout << "\033[0;33m";
		cout << "Enter Key for Data: " << endl;
		cin >> key;
		cout << "Enter Machine ID from where you want to Enter Data: " << endl;
		cin >> m_id;
	again:
		for (int i = 0; i < space.Machines_IDs.size(); i++)
		{
			if (space.Machines_IDs[i] == m_id)
			{

				goto start1;
			}

		}
		cout << "Wrong input Please Try Again! " << endl;
		cin >> m_id;
		goto again;
	start1:
		cout << "Enter Data correspondig to Key: " << endl;
		cin >> data;
		Store_Data(key, data, space, m_id);
		goto Menu;
	case 6:
		system("Color A4");
		cout << "\033[0;31m";
		cout << "Please Enter Key" << endl;
		cin >> key;
		cout << "Enter Machine ID from where you want to search Data: " << endl;
		cin >> m_id;
	again1:
		for (int i = 0; i < space.Machines_IDs.size(); i++)
		{
			if (space.Machines_IDs[i] == m_id)
			{

				goto start2;
			}

		}
		cout << "Wrong input Please Try Again! " << endl;
		cin >> m_id;
		goto again1;
	start2:
		Search_Data(key, space, m_id);
		goto Menu;
	case 7:
		system("Color B4");
		cout << "\033[0;35m";
		cout << "Please Enter Key" << endl;
		cin >> key;
		cout << "Enter Machine ID from where you want to Delete Data: " << endl;
		cin >> m_id;
	again2:
		for (int i = 0; i < space.Machines_IDs.size(); i++)
		{
			if (space.Machines_IDs[i] == m_id)
			{

				goto start3;
			}

		}
		cout << "Wrong input Please Try Again! " << endl;
		cin >> m_id;
		goto again2;
	start3:
		Deleting(key, space, m_id);
		goto Menu;
	case 8:
		system("Color E1");
		cout << "\033[0;32m";
		cout << "Please Enter Machine ID" << endl;
		cin >> m_id;
	again3:
		for (int i = 0; i < space.Machines_IDs.size(); i++)
		{
			if (space.Machines_IDs[i] == m_id)
			{

				goto start4;
			}

		}
		cout << "Wrong input Please Try Again! " << endl;
		cin >> m_id;
		goto again3;
	start4:
		Showing_AVL(m_id, space);
		goto Menu;
	case 0:
		system("cls");
		system("Color 0C");
		cout << "\033[0;33m";
		cout << "Thank you for coming\n\nHave you enjoyed our company: ";
		cin >> feedback1;
		system("cls");
		for (int x = 0; x < 3; x++)
			Beep(50000, 500);
		exit(0);
	default:
		cout << "Wrong Input! Please Try Again.\n";
		goto start;
	}

	return 0;
}


//#include<iostream>
//#include"Header.h"
//#include<string>
//using namespace std;
//int main()
//{
//	Identifierspace space;
//	char UserChoice;
//	int No_of_Machines, No_of_Bits, dht, m_id = 0;
//	string key, data;
//Menu:
//	cout << "\n\t\t\t\tMenu\n";
//	cout << "Press 1 to Sepecify the Number of Machines in Identifier space: \n ";
//	cout << "Press 2 to Sepecify the Number of Bits of Identifier space: \n ";
//	cout << "Press 3 if you want to assign manually IDs  machines: \n ";
//	cout << "Press 4 if you want to assign Automatically IDs  machines: \n ";
//	cout << "Press 5 Displaying IDs handled by a Machine: \n ";
//	cout << "Press 6 Add new Machine on the Fly: \n ";
//	cout << "Press 7 Delete a Machine on the Fly: \n ";
//	cout << "Press 8 To Display DHT of a Machine \n ";
//	cout << "Press 9 To Enter Data \n ";
//	cout << "Press 'a' To search data using Key: \n ";
//	cout << "Press 'b' To Delete data using Key: \n ";
//	cout << "Press 'c' To print AVL Tree using Key \n ";
//	cout << " press 0 to exit\n";
//start:
//	cin >> UserChoice;
//	switch (UserChoice)
//	{
//
//	case '1':
//		cout << "Enter Total Number of Machines: \n";
//		cin >> No_of_Machines;
//		addingMachine(No_of_Machines, space);
//		goto Menu;
//
//	case '2':
//		cout << "Enter Number of Bits (Range: 1 --> 160) : \n";
//		cin >> No_of_Bits;
//		while (No_of_Bits > 160 || No_of_Bits < 1)
//		{
//			cout << "Out of Range Try Again" << endl;
//			cin >> No_of_Bits;
//		}
//		insert(No_of_Bits, space);
//		goto Menu;
//	case '3':
//		Creat_Machines(space.Total_No_Machine, space);
//		//space.display();
//		goto Menu;
//	case '4':
//		Creat_Machines_Automatically(space.Total_No_Machine, space);
//	//	space.display();
//		goto Menu;
//	case '5':
//		space.display_handling_IDs_by_Machine();
//		goto Menu;
//	case '6':
//		Add_Machine_on_Fly(space);
//		goto Menu;
//	case '7':
//		Delete_Machine_on_Fly(space);
//		goto Menu;
//	case '8':
//		cout << "Enter ID of Machine you want to display DHT " << endl;
//		cin >> dht;
//		space.Machine_DHT_Display(dht);
//		goto Menu;
//	case '9':
//		cout << "Enter Machine ID from where you want to Enter Data: " << endl;
//		cin >> m_id;
//		while (m_id<0 || m_id>pow(2, No_of_Bits)) {
//			cout << "\n\nInvalid Input\n\n";
//			cin >> m_id;
//		}
//		cout << "Enter Key for Data: " << endl;
//		cin >> key;
//		cout << "Enter Data correspondig to Key: " << endl;
//		cin >> data;
//		Store_Data(key, data, space, m_id);
//		goto Menu;
//	case 'a':
//		cout << "Please Enter Key" << endl;
//		cin >> key;
//		cout << "Enter Machine ID from where you want to search Data: " << endl;
//		cin >> m_id;
//		Search_Data(key, space, m_id);
//		goto Menu;
//	case 'b':
//		cout << "Please Enter Key" << endl;
//		cin >> key;
//		cout << "Enter Machine ID from where you want to Delete Data: " << endl;
//		cin >> m_id;
//		Deleting(key, space, m_id);
//		goto Menu;
//	case 'c':
//		cout << "Please Enter Machine ID" << endl;
//		cin >> m_id;
//		Showing_AVL(m_id, space);
//		goto Menu;
//	case '0':
//		exit(0);
//	default:
//		"Wrong Input! Please Try Again.\n";
//		goto start;
//	}
//
//	return 0;
//}