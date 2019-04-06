#include "Student.h"

namespace {
	/*Reading Data from File*/
	int getFileData(Student *stdData)
	{
		int i = 0;
		//Student stdData[60];
		ifstream in("Student.list");
		char strD[255];
		string s;
		try
		{
			if (in)
			{
				while (in >> stdData[i].id >> stdData[i].name >> stdData[i].fatherName >> stdData[i].department >> stdData[i].intake >> stdData[i].section >> stdData[i].shift >> stdData[i].cgpa >> stdData[i].session)
				{
					i++;
				}
			}
		}
		catch (const std::exception&)
		{
			cout << "File Reading Error Found!" << endl;
		}

		in.close();
		_getch();
		return i;
	}

	/*Writing Data in File*/
	void writeFileData(Student *stdData, int stdLength)
	{
		ofstream out;
		out.open("temp.list");
		for (int i = 0; i < stdLength; i++)
		{
			out << stdData[i].id << " " << stdData[i].name << " " << stdData[i].fatherName << " " << stdData[i].department << " " << stdData[i].intake << " " << stdData[i].section << " " << stdData[i].shift << " " << stdData[i].cgpa << " " << stdData[i].session << "\n";
		}		
		out.close();

		remove("Student.list");
		rename("temp.list", "Student.list");
		//return false;
	}

	/*Deleting Data from File*/
	void deleteFileData(Student *stdData, int stdLength, int id)
	{
		ofstream out;
		out.open("temp.list");
		for (int i = 0; i < stdLength; i++)
		{
			if(i != id)
				out << stdData[i].id << " " << stdData[i].name << " " << stdData[i].fatherName << " " << stdData[i].department << " " << stdData[i].intake << " " << stdData[i].section << " " << stdData[i].shift << " " << stdData[i].cgpa << " " << stdData[i].session << "\n";
		}
		out.close();

		remove("Student.list");
		rename("temp.list", "Student.list");
	}

	/*New Entry for student*/
	Student newEntry()
	{
		Student stdData;

		cout << "Enter Student ID: "; cin >> stdData.id;
		cout << "Enter Student Name: "; cin >> stdData.name;
		cout << "Enter Student Father Name: "; cin >> stdData.fatherName;
		cout << "Enter Student Department: "; cin >> stdData.department;
		cout << "Enter Student Intake: "; cin >> stdData.intake;
		cout << "Enter Student Section: "; cin >> stdData.section;
		cout << "Enter Student Shift: "; cin >> stdData.shift;
		cout << "Enter Student Session: "; cin >> stdData.session;
		cout << "Enter Student CGPA: "; cin >> stdData.cgpa;

		return stdData;
	}

	/*Display Student List*/
	void displayStudentList(Student stdList[],int stdListLength,Console &c)
	{
		cout << setprecision(2) << fixed;

		c.clrscr();
		cout << setw(3) << "ID"<< setw(15) <<"Name"<< setw(10) <<"Dept."<< setw(7) <<"Intake"<< setw(8) <<"Section"<< setw(6) <<"Shift"<< setw(8) <<"Session" << endl;
		cout << "|==================================================================|" << endl;
		c.textcolor(Color::Magenta);
		for (int i = 0; i < stdListLength; i++)
		{
			cout << setw(3) << stdList[i].id;//ID
			cout << setw(15) << stdList[i].name;//Name
			cout << setw(10) << stdList[i].department;//Dept
			cout << setw(7) << stdList[i].intake;//Intake
			cout << setw(8) << stdList[i].section;//Section
			cout << setw(6) << stdList[i].shift;//Shift
			cout << setw(8) << stdList[i].session << endl;//Session
		}
	}

	/*Display Data*/
	void displayStudentData(Student &stdData, Console &cmd)
	{
		cmd.clrscr();
		cmd.textcolor(Color::Cyan);
		cout << "\t\tDisplay Student of " << stdData.id << endl;
		cout << "-----------------------------------" << endl;
		cmd.textcolor(Color::LightCyan);
		cout << "1. Name		: " << stdData.name << endl;
		cout << "2. Father Name	: " << stdData.fatherName << endl;
		cout << "3. Department	: " << stdData.department << endl;
		cout << "4. intake	: " << stdData.intake << endl;
		cout << "5. section	: " << stdData.section << endl;
		cout << "6. shift	: " << stdData.shift << endl;
		cout << "7. session	: " << stdData.session << endl;
		cout << "8. cgpa		: " << stdData.cgpa << endl;
	}

	/*Edit Data*/
	void editStudentData(Student &stdData, Console &cmd)
	{
		int op;
		
		/*	
		cmd.clrscr();
		cmd.textcolor(Color::Cyan);
		cout << "\t\tDisplay Student of " << stdData.id << endl;
		cout << "-----------------------------------" << endl;
		cmd.textcolor(Color::LightCyan);
		cout << "1. Name		: " << stdData.name << endl;
		cout << "2. Father Name	: " << stdData.fatherName << endl;
		cout << "3. Department	: " << stdData.department << endl;
		cout << "4. intake	: " << stdData.intake << endl;
		cout << "5. section	: " << stdData.section << endl;
		cout << "6. shift	: " << stdData.shift << endl;
		cout << "7. session	: " << stdData.session << endl;
		cout << "8. cgpa		: " << stdData.cgpa << endl;
		*/
		displayStudentData(stdData, cmd);
		cmd.textcolor(Color::LightGray);
		cout << "\nSelect to modify: "; cin >> op;
		switch (op)
		{
		case 1:
			cout << "Enter Name:"; cin >> stdData.name;
			break;
		case 2:
			cout << "Enter Father Name:"; cin >> stdData.fatherName;
			break;
		case 3:
			cout << "Enter Department:"; cin >> stdData.department;
			break;
		case 4:
			cout << "Enter intake:"; cin >> stdData.intake;
			break;
		case 5:
			cout << "Enter section:"; cin >> stdData.section;
			break;
		case 6:
			cout << "Enter shift:"; cin >> stdData.shift;
			break;
		case 7:
			cout << "Enter session:"; cin >> stdData.session;
			break;
		case 8:
			cout << "Enter cgpa:"; cin >> stdData.cgpa;
			break;
		default:
			cmd.textcolor(Color::LightRed);
			cout << "Wrong Selection!" << endl;
			break;
		}
	}

	/*Find Data*/
	int findStudentData(Student stdList[], int stdListLength,int id)
	{
		int i;
		for (i = 0; i < stdListLength; i++)
		{
			if (stdList[i].id == id)
			{
				return i;
			}
		}
		return -1;
	}
}

