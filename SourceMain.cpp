#include<iostream>
#include "Events.h"

using namespace std;
void the_lobby()
{

	cout << "------------------------------------------GOOD MORNING------------------------------------------------------\n";
	cout << endl;
	cout << "************ if you want to excute any operation press it's number **************** \n";
	cout << "1-ADD first EVENT IN THE LIST \n";
	cout << "2-ADD EVENT IN THE LIST \n";
	cout << "3-DELETE EVENT WITH IT'S NAME  \n";
	cout << "4-DISPLAY ALL EVENT WITH IT'S DATA  \n";
	cout << "5-DISPLAY the upcoming EVENT WITH IT'S DATA and the passed events \n";
	cout << "6-SEARCH FOR EVENT \n";
	cout << "7-delete all events  \n";
	cout << "8-update event \n";
	cout << "9-to show the events in file \n";
	cout << "10-to show the event is finished or not \n";
	cout << "11-remaining time function \n";
	cout << "12-the size of list \n";
	cout << "13-to exit the program\n";

}

int main()
{
	Events f;
	int x;
	while (true)
	{
		the_lobby();
		cin >> x;
		if (x == 1)
		{
			system("cls");
			f.addFirst();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 2)
		{
			system("cls");
			f.Add();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}

		if (x == 3)
		{
			system("cls");
			f.Delete_byname();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}


		}
		if (x == 4)
		{
			system("cls");
			f.display();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 5)
		{
			system("cls");
			f.is_done();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 6)
		{
			system("cls");
			f.search();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 7)
		{
			system("cls");
			f.clear();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 8)
		{
			system("cls");
			f.update();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 9)
		{
			system("cls");
			f.show();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 10)
		{
			system("cls");
			f.finished();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 11)
		{
			system("cls");
			f.remainder_Time();
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 12)
		{
			system("cls");
			cout << "the length of the linkedlist is : " << f.Length() << endl;;
			cout << "if you want to return to the lobby press 0\n";
			cin >> x;
			if (x == 0)
			{
				system("cls");

			}
		}
		if (x == 13)
		{
			cout << "good bye \n";
			break;
		}

	}

}