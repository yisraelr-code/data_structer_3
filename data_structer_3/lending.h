/*
The goal of this program : B TREE
name of corse : Data data_structure
targil 3
AUTHORS:		Salay Shalom Shuker ,Yisrael Rolnick
ID:				311600605 , 206672057
*/
#pragma once
#include<iostream>
using namespace std;
class Lending
{
	int id;
	string name;
	string date;
	int itemCode;
public:
	Lending(){}
	Lending(int, string, string, int);
	~Lending() {}
	void set_date(string);
	bool operator==(Lending a)const;
	bool operator!=(Lending a) { return!operator==(a); }
	bool operator<(Lending a);
	bool operator>(Lending a);
	bool operator<=(Lending a);
	bool operator>=(Lending a);
	/*int getYear() { return atoi(date.substr(0, 4).c_str()); }
	int getMonth() { return atoi(date.substr(6, 2).c_str()); }
	int getDay() { return atoi(date.substr(9, 2).c_str()); }*/
	friend istream& operator>>(istream& is, Lending& l)
	{
		cout << "enter: id, name, date, item ";
		is >> l.id >> l.name >> l.date >> l.itemCode;
		return is;
	}
	friend ostream& operator<<(ostream& os, Lending& l)
	{
		os << endl << "Lending details: id: " << l.id << " name: " << l.name << " date: " << l.date << " item: " << l.itemCode << endl;
		return os;
	}
};
inline void Lending::set_date(string s)
{
	this->date = s;
} //
bool Lending::operator==(Lending a)const
{
	return id == a.id && name == a.name && date == a.date && itemCode == a.itemCode;
}
bool Lending::operator<(Lending a)
{
	if (operator==(a))
		return false;
	else if (date < a.date)
		return true;
	else if (date == a.date && itemCode < a.itemCode)
		return true;
	else if (date == a.date && itemCode == a.itemCode && id < a.id)
		return true;
	else return false;
}
bool Lending::operator<=(Lending a)
{
	return operator<(a) || operator==(a);
}
bool Lending::operator>(Lending a)
{
	return !operator<(a) && !operator==(a);
}
bool Lending::operator>=(Lending a)
{
	return operator>(a) || operator==(a);
}
Lending::Lending(int a,string b,string c,int d)
{
	id = a; name = b; date = c; itemCode = d;
}
