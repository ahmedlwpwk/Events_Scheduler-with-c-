#include "Events.h"
#include <string>
#include <iostream>
#include <cassert>
#include<fstream>
#include<Windows.h>

using namespace std;

Events::Events()
{
	head = tail = NULL;
	no_of_events = 0;
}

bool Events::isEmpty()
{
	return (head == NULL);
}

int Events::Length()
{
	return no_of_events;
}// تتجرب// تتجرب // تتجرب

void Events::DeleteAt(int pos)
{

	Node* temp = head;
	if (pos == 0)
	{
		head = head->Next;
		delete temp;
		no_of_events--;
	}
	else
	{
		
		for (size_t i = 1; i < pos; i++)
		{
			temp = temp->Next;
		}
		Node* delevent = temp->Next;
		temp->Next = delevent->Next;
		delete delevent;
		no_of_events--;
		if (pos == no_of_events)
		{
			
			tail = temp;
		}

	}

}

void Events::Delete_byname()
{
	string names;
	cout << "enter the name of event do you want to delete" << endl;
	cin >> names;

	{

		if (isEmpty())
			cout << "List is empty , no items to delete \n";
		else
		{
			Node* delptr = head;

			if (head->name == names)
			{

				head = head->Next;
				delete delptr;
				no_of_events--;
			}
			else
			{
				Node* prev = NULL;
				delptr = head;
				while (delptr->name != names)
				{
					prev = delptr;
					delptr = delptr->Next;
				}
				prev->Next = delptr->Next;
				delete delptr;
				no_of_events--;

			}
		}


	}
}

void Events::Delete_bytime(int days, int months)
{
	Node* delptr = head;
	Node* prev = NULL;
	delptr = head;
	while (delptr->End_Date.month != months && delptr->End_Date.day != days)
	{
		prev = delptr;
		delptr = delptr->Next;
	}
	prev->Next = delptr->Next;
	delete delptr;
	no_of_events--;
}

void Events::show()
{
	Node* temp = head;
	fstream myFile;
	myFile.open("Events.txt", ios::out);//write
	while (temp != NULL)
	{

		myFile << "This is the upcoming events" << endl;
		myFile << "the name of the event is : " << temp->name << endl;
		myFile << "the place of the event is : " << temp->place << endl;
		myFile << "Event start_day : " << temp->Start_Date.day << endl;
		myFile << "Event start_month : " << temp->Start_Date.month << endl;
		myFile << "Event start year : " << temp->Start_Date.year << endl;
		myFile << "Event end_day : " << temp->End_Date.day << endl;
		myFile << "Event end_month : " << temp->End_Date.day << endl;
		myFile << "Event end year : " << temp->End_Date.year << endl;
		myFile << "Event start_time : " << temp->start_time << endl;

		myFile << "--------------------------------------------------------------\n" << endl;

		temp = temp->Next;

	}

}

void Events::remainder_Time()
{
	string names;
	cout << "enter the event name " << endl;
	cin >> names;
	Node* temp = head;

	int h, d, m, eer, a;
	eer = a = 0;
	cout << "please enter the current date \n";
	while (eer == 0)
	{
		cin >> h >> d >> m;
		if (h < 24 && d < 30 && m < 12)
			eer++;
		else
			system("cls");
	}
	while (a == 0)
	{
		system("cls");
		cout << h << " : " << d << " : " << m << endl;
		if (h == temp->start_time && d == temp->reminder.day && m == temp->reminder.month)
		{

			cout << "this is the remainder message for event " << temp->name << " the event will start at " << temp->Start_Date.day << " / " << temp->Start_Date.month << endl;
			break;
		}
		else
		{

			temp = head;
			while (temp->name != names)
			{

				temp = temp->Next;
			}
			if (h == temp->start_time && d == temp->reminder.day && m == temp->reminder.month)
			{
				cout << "this is the remainder message for event " << temp->name << " the event will start at " << temp->Start_Date.day << " / " << temp->Start_Date.month << endl;
				break;
			}
		}



		Sleep(0.01);
		h++;
		if (h > 24)
		{
			h = 0;
			d++;
		}
		if (d > 30)
		{
			d = 0;
			m++;

		}
		if (m > 12)
		{
			m = 0;

		}
	}
}

void Events::finished()
{
	int day, month;
	cout << "enter the current time day >> month\n";
	cin >> day >> month;
	Node* temp = head;
	while (temp != NULL)
	{
		if (month > temp->End_Date.month)
			temp->Done = true;
		else if (month == temp->End_Date.month && day > temp->End_Date.day)
			temp->Done = true;
		else if (month < temp->End_Date.month)
			temp->Done = false;

		if (temp->Done)
			cout << "the event of " << temp->name << "      IS DONE \n";
		else if (!temp->Done)
			cout << "the event of " << temp->name << " IS not DONE YET \n";
		temp = temp->Next;
	}
}

void Events::search()
{
	string n;
	bool flag = false;

	if (head == NULL)
	{
		cout << "List is Empty" << endl;
		return;
	}

	cout << "Enter the event name to be searched: ";
	cin >> n;

	struct Node* s;
	s = head;

	while (s != NULL)
	{

		if (s->name == n)
		{
			flag = true;
			cout << "the name of event ' " << n << " 'is founded in list  and the discribtion about that " << endl;
			cout << "the event begins at " << s->Start_Date.month << " / " << s->Start_Date.day << endl;
			cout << "the event ends at " << s->End_Date.month << " / " << s->End_Date.day << endl;
			cout << "the place of the event is : " << s->place << endl;
			cout << "the start time of event is : " << s->start_time << endl;
			cout << "--------------------------------------------------------------\n" << endl;

		}
		s = s->Next;
	}
	if (!flag)
		cout << "the name of event ' " << n << " 'is not found" << endl;
}

void Events::display()
{
	if (isEmpty())
		cout << "there is no events to display \n ";
	else
	in_order();
		
		Node* temp = head;
		while (temp != NULL)
		{

			cout << "the name of event is : " << temp->name << endl;
			cout << "the place of event is : " << temp->place << endl;
			cout << "Event start day : " << temp->Start_Date.day << endl;
			cout << "Event start month : " << temp->Start_Date.month << endl;
			cout << "Event start year : " << temp->Start_Date.year << endl;
			cout << "Event end day : " << temp->End_Date.day << endl;
			cout << "Event end month : " << temp->End_Date.month << endl;
			cout << "Event end year : " << temp->End_Date.year << endl;
			cout << "Event start time : " << temp->start_time << endl;
			cout << "the reminder day : " << temp->reminder.day << endl;
			cout << "the reminder month : " << temp->reminder.month << endl;
			cout << "--------------------------------------------------------------\n" << endl;
			temp = temp->Next;

		}
	
}

void Events::addFirst()
{
	string Name,Place;
	int  S_D_D, S_D_M,S_D_Y, E_D_D , E_D_M , E_D_Y  ;
	float S_T ,R_D, R_M;
	cout << endl;
	cout << "please enter the Event's name \n ";
	cin >> Name;
	cout << "please enter the Event's start date by day >> month >> year \n ";
	cin >> S_D_D >> S_D_M >> S_D_Y ;
	cout << "please enter the Event's end date by day >> month >> year \n ";
	cin >> E_D_D >> E_D_M >> E_D_Y;
	cout << "please enter the Event's location \n ";
	cin >> Place;
	cout << "please enter the Event's start time \n ";
	cin >> S_T;
	cout << "please enter the Event's reminder time >> day >> month \n ";
	cin >> R_D >> R_M;

	Node* newnode = new Node();
	newnode->name = Name;
	assert(S_D_D > 0 && S_D_D <= 30 && S_D_M > 0 && S_D_M <= 12 && S_D_Y > 2002 );
	newnode->Start_Date.day = S_D_D;
	newnode->Start_Date.month = S_D_M;
	newnode->Start_Date.year = S_D_Y;
	assert(E_D_M >= S_D_M );
	if (E_D_M > S_D_M)
	{
		newnode->End_Date.day = E_D_D;
		newnode->End_Date.month = E_D_M;
		newnode->End_Date.year = E_D_Y;
	}
	else if (E_D_M == S_D_M && E_D_D >= S_D_D)
	{
		newnode->End_Date.day = E_D_D;
		newnode->End_Date.month = E_D_M;
		newnode->End_Date.year = E_D_Y;
	}
	newnode->place = Place;
	newnode->start_time = S_T;
	assert(R_D < S_D_D && R_M <= S_D_M);
	newnode->reminder.day = R_D;
	newnode->reminder.month = R_M;

	Node* temp = head;
	bool notfound = true;
	while (temp != NULL)
	{

		if (((newnode->Start_Date.month >= temp->Start_Date.month) && (newnode->Start_Date.month <= temp->End_Date.month)) &&
			((newnode->Start_Date.day >= temp->Start_Date.day) && (newnode->Start_Date.day <= temp->End_Date.day)))
		{
			notfound = false;
			break;
		}

		else if (((newnode->End_Date.month >= temp->Start_Date.month) && (newnode->End_Date.month <= temp->End_Date.month)) &&
			((newnode->End_Date.day >= temp->Start_Date.day) && (newnode->End_Date.day <= temp->End_Date.day)))
		{

			notfound = false;
			break;

		}

		else
		{
			temp = temp->Next;
		}

	}


	if (notfound == true)
	{
		if (isEmpty())
		{
			head = tail = newnode;
			newnode->Next = NULL;
			no_of_events++;
		}
		else
		{
			newnode->Next = head;
			head = newnode;
			no_of_events++;
		}

	}
	else if (notfound == false)
	{
		int con;
		cout << "sorry, we can't add event " << newnode->name << " because it intersects with Event '" << temp->name << " '\n";
		cout << "for more details push 1 to skip push \n";
		cin >> con;
		if (con == 1)
			cout << "we cant' insert this event because it start at  " << newnode->Start_Date.month << " / " << newnode->Start_Date.day << "and finished at  " << newnode->End_Date.month << " / " << newnode->End_Date.day << "  so it will be between the time range of another Event \n ";

	}

}

void Events::Add()
{
	string Name, Place;
	int  S_D_D, S_D_M, S_D_Y, E_D_D, E_D_M, E_D_Y,R_D,R_M;

	float S_T;
	cout << endl;
	cout << "please enter the Event's name \n ";
	cin >> Name;
	cout << "please enter the Event's start date by day >> month >> year \n ";
	cin >> S_D_D >> S_D_M >> S_D_Y;
	cout << "please enter the Event's end date by day >> month >> year \n ";
	cin >> E_D_D >> E_D_M >> E_D_Y;
	cout << "please enter the Event's location \n ";
	cin >> Place;
	cout << "please enter the Event's start time \n ";
	cin >> S_T;
	cout << "please enter the Event's reminder time >> day >> month \n ";
	cin >> R_D >> R_M;

	Node* newnode = new Node();
	newnode->name = Name;
	assert(S_D_D > 0 && S_D_D <= 30 && S_D_M > 0 && S_D_M <= 12 && S_D_Y > 0 && R_D>0 && R_M > 0);
	newnode->Start_Date.day = S_D_D;
	newnode->Start_Date.month = S_D_M;
	newnode->Start_Date.year = S_D_Y;
	assert(E_D_M >= S_D_M);

	if (E_D_M > S_D_M)
	{
		newnode->End_Date.day = E_D_D;
		newnode->End_Date.month = E_D_M;
		newnode->End_Date.year = E_D_Y;
	}
	else if (E_D_M == S_D_M && E_D_D >= S_D_D )
	{
		newnode->End_Date.day = E_D_D;
		newnode->End_Date.month = E_D_M;
		newnode->End_Date.year = E_D_Y;
	}
	newnode->place = Place;
	newnode->start_time = S_T;
	newnode->reminder.day = R_D;
	newnode->reminder.month = R_M;

	Node* temp = head;
	bool notfound = false;
	while (temp != NULL)
	{

		if ((newnode->Start_Date.month == temp->Start_Date.month) && (newnode->Start_Date.month == temp->End_Date.month) &&
			(newnode->Start_Date.day >= temp->Start_Date.day) && (newnode->Start_Date.day <= temp->End_Date.day))
		{
			notfound = true;
			break;

		}
		else if ((newnode->End_Date.month == temp->Start_Date.month) && (newnode->End_Date.month == temp->End_Date.month) &&
			(newnode->End_Date.day >= temp->Start_Date.day) && (newnode->End_Date.day <= temp->End_Date.day))
		{
			notfound = true;
			break;

		}
		else
			temp = temp->Next;
	}
	if (notfound == false)
	{
		if (isEmpty())
		{
			addFirst();
		}
		else
		{
			tail->Next = newnode;
			newnode->Next = NULL;
			tail = newnode;
			no_of_events++;
		}
	}
	else if (notfound == true)
	{
		int con;
		cout << "sorry, we can't add event " << newnode->name << " because it intersects with Event '" << temp->name << " '\n";
		cout << "for more details push 1 to skip push \n";
		cin >> con;
		if (con == 1)
			cout << "we cant' insert this event because it start at  " << newnode->Start_Date.month << " / " << newnode->Start_Date.day << "and finished at  " << newnode->End_Date.month << " / " << newnode->End_Date.day << "  so it will be between the time range of another Event \n ";


	}

}

void Events::clear()
{
	{
		Node* temp = new Node();
		while (head != NULL) {
			temp = head;
			head = head->Next;
			delete(temp);
		}

		cout << "All nodes are deleted successfully.\n";
	}
}

void Events::is_done()
{
	int cur_day, cur_month;
	cout << "please enter the current time>>day>>month \n";
	cin >> cur_day >> cur_month;
	assert(cur_day > 0 && cur_day <= 30 && cur_month > 0 && cur_month <= 30);
	arrstack finished_events(5);
	Node* temp = head;
	while (temp != NULL)
	{

		if (cur_month > temp->End_Date.month)
		{
			finished_events.push(temp->name);
			;
		}

		else if (cur_month == temp->End_Date.month && cur_day > temp->End_Date.day)
		{
			finished_events.push(temp->name);
		
		}
		else
		{
			cout << "the upcoming events     \n";
			cout << "the events name is      \t" << temp->name << endl;
			cout << "the events startdate is day>>month \t" << temp->Start_Date.day << " / " << temp->Start_Date.month << endl;
			cout << "the events enddate is  day>>month \t" << temp->End_Date.day << " / " << temp->End_Date.month << endl;
			cout << "the events location is  \t" << temp->place << endl;
			cout << "=================================================\n";
		}
		temp = temp->Next;

	}
	cout << "=================================================\n";
	if (finished_events.isempty())
		cout << "no events has finished yet \n";
	else
	{
		cout << "the finished events is \n";
		while (!finished_events.isempty())
		{
			cout << finished_events.top() << endl;
			finished_events.pop();
		}
	}
}

void Events::in_order()
{


	for (Node* i = head; i != NULL; i = i->Next)
	{
		for (Node* j = i->Next; j != NULL; j = j->Next)
		{
			if (i->Start_Date.month > j->Start_Date.month)
			{

				swap(i->name, j->name);
				swap(i->Start_Date.month, j->Start_Date.month);
				swap(i->Start_Date.day, j->Start_Date.day);
				swap(i->End_Date.month, j->End_Date.month);
				swap(i->End_Date.day, j->End_Date.day);
				swap(i->place, j->place);
				swap(i->reminder.month, j->reminder.month);
				swap(i->reminder.day, j->reminder.day);

			}
			else if (i->Start_Date.month == j->Start_Date.month && i->Start_Date.day > j->Start_Date.day)
			{
				swap(i->name, j->name);
				swap(i->Start_Date.month, j->Start_Date.month);
				swap(i->Start_Date.day, j->Start_Date.day);
				swap(i->End_Date.month, j->End_Date.month);
				swap(i->End_Date.day, j->End_Date.day);
				swap(i->place, j->place);
				swap(i->reminder.month, j->reminder.month);
				swap(i->reminder.day, j->reminder.day);
			}

		}

	}

}

void Events::update()
{
	int x;
	string s, r;
	int f, c;
	int v;
	float s_t;
	Node* temp = head;
	string n;
	bool finished = false;

	cout << "please enter the name of the event which you want to update \n";
	cin >> n;
	while (true)
	{
		if (n == temp->name)
		{
			cout << "\ncongratulation we find this event \n";
			cout << "if you want to change event's name press 1 or 0 to skip \n";
			cin >> x;
			if (x == 1)
			{
				cout << "please enter new name \n ";
				cin >> s;
				temp->name = s;
			}
			cout << "if you want to change place press 1 or 0 to skip \n";
			cin >> x;
			if (x == 1)
			{
				cout << "please enter new place \n ";
				cin >> r;
				temp->place = r;
			}
			cout << "if you want to change start_time press 1 or 0 to skip \n";
			cin >> x;
			if (x == 1)
			{
				cout << "please enter new start_time \n ";
				cin >> s_t;

				temp->start_time = s_t;
			}
			cout << "if you want to change start_date press 1 or 0 to skip \n";
			cin >> x;
			if (x == 1)
			{
				cout << "please enter new start_date >> day >> month \n ";
				cin >> c >> f;

				temp->Start_Date.day = c;
				temp->Start_Date.month = f;
			}
			cout << "if you want to change end_date press 1 or 0 to skip \n";
			cin >> x;
			if (x == 1)
			{
				cout << "please enter new end_date >> day >> month \n ";
				cin >> c >> f;

				temp->End_Date.day = c;
				temp->End_Date.month = f;

			}
			cout << "if you want to change the reminder time press 1 or 0 to skip \n";
			cin >> x;
			if (x == 1)
			{
				cout << "please enter new reminder time >> day >> month \n ";
				cin >> c >> f;

				temp->reminder.day = c;
				temp->reminder.month = f;

			}
			finished = true;
			cout << " -----------------------------------thank you------------------------------------------------  \n";
			break;

		}

		else if (finished == false)
		{
			temp = temp->Next;

		}

		if ((temp == NULL) && (finished == false))
		{
			cout << " the name you enterd invalid please try again \n";

			update();
		}

	}

}

arrstack::arrstack(int size)
{
	capacity = size;
	arr = new string[capacity];
	elements = 0;

}

void arrstack::push(string value)
{
	if (elements == capacity)
		expand();
	arr[elements] = value;
	elements++;


}

void arrstack::pop()
{
	assert(elements != 0);
	elements--;
}

int arrstack::length()
{
	return elements;
}

void arrstack::expand()
{
	if (elements == capacity)
	{


		string* newarr = new string[capacity * 2];
		for (int i = 0; i < capacity; i++)
		{
			newarr[i] = arr[i];
		}
		capacity *= 2;
		delete[] arr;
		arr = newarr;

	}
}

bool arrstack::isempty()
{
	return(elements == 0);
}

string arrstack::top()
{
	return arr[elements - 1];
}