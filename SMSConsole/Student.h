#include "Header.h"


class Student
{
public:
	int id;
	string name;
	string fatherName;
	string department;
	unsigned intake;
	unsigned section;
	unsigned shift;
	unsigned session;
	float cgpa;	

	Student()
	{
		id = 0;
		name = "";
		fatherName = "";
		department = "";
		intake = 0;
		section = 0;
		shift = 0;
		session = 0;
		cgpa = 0.00;
	}
};


