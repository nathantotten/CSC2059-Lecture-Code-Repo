// Implementation file for the Person class
#include "Person.h"
#include <ostream>

using std::ostream;

Person::Person(string first, string family, string ID, int birth)
	: given_name(first), family_name(family), ID_number(ID), birth_year(birth)
{
}
Person::Person()
	: given_name(""), family_name(""), ID_number(""), birth_year(1900)
{
}

void Person::set_given_name(const string& given) 
{ 
	given_name = given; 
}
void Person::set_family_name(const string& family) 
{ 
	family_name = family; 
}
void Person::set_ID_number(const string& ID) 
{ 
	ID_number = ID; 
}
void Person::set_birth_year(int new_birth_year) 
{ 
	birth_year = new_birth_year; 
}

string Person::get_given_name() const 
{ 
	return given_name; 
}
string Person::get_family_name() const 
{ 
	return family_name; 
}
string Person::get_ID_number() const 
{ 
	return ID_number; 
}
int Person::get_birth_year() const 
{ 
	return birth_year; 
}

int Person::age(int year) const 
{
	return year - birth_year;
}
bool Person::can_vote(int year) const 
{
	int the_age = age(year);
	return the_age >= VOTE_AGE;
}
bool Person::is_senior(int year) const 
{
	return age(year) >= SENIOR_AGE;
}
bool Person::operator==(const Person& p) const 
{
	return ID_number == p.ID_number;
}

void Person::print()
{
	cout << "Given name: " << given_name << '\t'
		<< "Family name: " << family_name << '\n'
		<< "ID number: " << ID_number << '\t'
		<< "Year of birth: " << birth_year << '\n' << '\n';
}


