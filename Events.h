#pragma once
#include <iostream>
using namespace std;

class Time
{
public:

	int day;
	int month;
	int year;
	
	
};

class Node
{

public:

	string name;
	string place;
	float start_time;
	Time Start_Date;
	Time End_Date;
	Time reminder;
	bool Done;
	Node* Next;

};

class Events {


	Node* head;
	Node* tail;
	int no_of_events;

public:

	Events();
	bool isEmpty();
	int Length();
	void DeleteAt(int pos);
	void Delete_byname();
	void Delete_bytime(int  days, int months);
	void display();
	void addFirst();
	void Add();
	void is_done();
	void in_order();
	void update();
	void show();
	void remainder_Time();
	void finished();
	void search();
	void clear();

};
class arrstack
{
public:
	string* arr;
	int capacity;
	int elements;
	arrstack(int);
	void push(string value);
	void pop();
	int length();
	void expand();
	bool isempty();
	string top();

};



