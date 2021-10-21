// Declaration of the Person class that represents a human being
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

// constants
constexpr int VOTE_AGE = 18;
constexpr int SENIOR_AGE = 65;

class Person {
public:
	// Constructors
	// parameterised
	Person(string first, string family, string ID, int birth);
	// default or parameter-less
	Person();

	// Modifier Functions
	// sets the given_name field
	void set_given_name(const string& given);
	// sets the family_name field
	void set_family_name(const string& family);
	// sets the ID number field
	void set_ID_number(const string& ID);
	// sets the birth_year field
	void set_birth_year(int new_birth_year);

	// Accessor Functions
	// gets the person's given name
	string get_given_name() const;
	// gets the person's family name
	string get_family_name() const;
	// gets the person's ID number
	string get_ID_number() const;
	// gets the person's year of birth
	int get_birth_year() const;

	// Other Functions
	// calculates a person's age at this year's birthday
	int age(int year) const;
	// determines whether a person can vote
	// return true if the person's age is >= the voting age
	bool can_vote(int year) const;
	// determines whether a person is a senior citizen
	// return true if person's age >= age at which a person is considered to be a senior citizen
	bool is_senior(int year) const;
	// compares two Person objects for equality
	// return true if the Person objects have the same ID number; false if they don't
	bool operator==(const Person& p) const;

	// print a person object information on screen
	void print();

private:
	// Data Fields
	// the given name
	string given_name;
	// the family name
	string family_name;
	// the ID number
	string ID_number;
	// the birth year
	int birth_year;
};

#endif
