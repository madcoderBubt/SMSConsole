#include "Student.cpp"


int main()
{
	system("clear");

	char option;
	Console console;
	//list<Student> stdList;
	Student stdArray[60];	
	int stdArrayLength = 2, i;
	stdArrayLength = getFileData(stdArray);
	
	//Default Data
	/*stdArray[0].id = 35;
	stdArray[0].name = "Sudhananda";
	stdArray[0].fatherName = "Binoy";
	stdArray[0].department = "CSE";
	stdArray[0].intake = 28;
	stdArray[0].section = 1;
	stdArray[0].shift = 2;
	stdArray[0].session = 18;
	stdArray[0].cgpa = 3.5;

	stdArray[1].id = 79;
	stdArray[1].name = "Smita";
	stdArray[1].fatherName = "Unkown";
	stdArray[1].department = "CSE";
	stdArray[1].intake = 28;
	stdArray[1].section = 2;
	stdArray[1].shift = 2;
	stdArray[1].session = 18;
	stdArray[1].cgpa = 3.0;*/
	//End of Default Data

	//console.textcolor(Color::LightBlue);
	//cout << "I am Light Blue\n";
	
begin:
	console.clrscr();
	console.textcolor(Color::Green);
	cout << "            |-------------------->SMSConsole<------------------------|              " << endl;
	cout << "            |================>Mad Coder Team(4)<=====================|              " << endl;
	cout << "            |================>CSE Evening(28/1)<=====================|              " << endl;
	cout << endl;
	console.textcolor(Color::White);
	cout << "\t\t\t1. New Student Entry" << endl;
	cout << "\t\t\t2. Modify Student Records" << endl;
	cout << "\t\t\t3. Delete Records" << endl;
	cout << "\t\t\t4. Search Records" << endl;
	cout << "\t\t\t5. Save Changes(in File)" << endl;
	cout << "\t\t\t6. Display ALL Records" << endl;
	cout << "\t\t\te. Exit" << endl;
	console.textcolor(Color::DarkGray);
	cout << "\t\t\tselect your option: ";
	cin >> option;
	if (option == 'e')
	{
		console.textcolor(Color::Red);
		cout << "\t\tWould you like to exit now? y/n=> ";
		cin >> option;
		if (option == 'y') goto end; else goto begin;
	}
	else
	{
		int ID;
		Student stdData;
		switch (option)
		{
		case '1':			
			stdData = newEntry();
			//stdList.push_back(stdData);
			stdArray[stdArrayLength++] = stdData;
			console.textcolor(Color::Green);
			cout << "Entry Successfull" << endl;
			break;
		case '2':
			//Modify Record using Student Id
			
			cout << "Enter Student ID: ";
			cin >> ID;
			
			i = findStudentData(stdArray, stdArrayLength, ID);

			if (i < 0) {
				console.textcolor(Color::Red);
				cout << "Records Not Found!" << endl;
			}
			else {
				editStudentData(stdArray[i], console);
				console.textcolor(Color::Green);
				cout << "Records Modified! " << i << endl;
			}
			break;
		case '3':
			//Deleting Data from file
			cout << "Enter Student ID: ";
			cin >> ID;

			i = findStudentData(stdArray, stdArrayLength, ID);
			if (i < 0) {
				console.textcolor(Color::Red);
				cout << "Records Not Found!" << endl;
			}
			else {
				deleteFileData(stdArray, stdArrayLength, i);
				cout << "Press Any key to continue..." << endl;
			}
			break;
		case '4':
			//Search Data 
			cout << "Enter Student ID: ";
			cin >> ID;

			i = findStudentData(stdArray, stdArrayLength, ID);
			if (i < 0) {
				console.textcolor(Color::Red);
				cout << "Records Not Found!" << endl;
			}
			else {
				displayStudentData(stdArray[i], console);
				console.textcolor(Color::LightGray);
				cout << "Press Any key to continue..." << endl;
			}
			break;
		case '5':
			//Write Data in file
			writeFileData(stdArray, stdArrayLength);
			break;
		case '6':
			//Display ALL Recordss
			console.textcolor(Color::LightMagenta);
			displayStudentList(stdArray, stdArrayLength, console);
			break;
		case 'a':
			console.clrscr();
			cout << "\n\n\n";
			console.textcolor(Color::Brown);
			cout << "\t|============================================================|" << endl;
			cout << "\t||  ===         ===    ==     |====\\\\    C                  ||" << endl;
			cout << "\t||  ||\\\\       //||   //\\\\    ||    ||    O  INTAKE 28/1    ||" << endl;
			cout << "\t||  || \\\\     // ||  //  \\\\   ||    ||     D     EVENING    ||" << endl;
			cout << "\t||  ||  \\\\   //  || //====\\\\  ||    ||      E        CSE    ||" << endl;
			cout << "\t||  ||   \\\\ //   ||//      \\\\ ||    ||       R              ||" << endl;
			cout << "\t||  ==    ===    ===        ==|====//         S             ||" << endl;
			cout << "\t|============================================================|" << endl;
			console.textcolor(Color::Yellow);
			cout << "\n\n\t               Team Members: " << endl;
			cout << "\t-------------------------------------------------------------" << endl;
			console.textcolor(Color::LightGreen);
			cout << "\t1. Team Leader & Programmer: Sudhananda Biswas{ID: 17181203035}" << endl;
			cout << "\t2. Desing Supporter: SH Amit Hasan{ID: 17181203007}" << endl;
			cout << "\t3. Presentation Desinger: Fahim Forhad{ID: 17181203003}" << endl;
			break;
		default:
			cout << "Wrong Selection. Select From List Above."<<endl;
			break;
		}
	}
	
	_getch();
	goto begin;

end:
	return 0;
}