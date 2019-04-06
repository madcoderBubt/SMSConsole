#include "Console.h"


Console::Console()
{
}

Console::~Console()
{
}

void Console::clrscr() //Clears the screen
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

void Console::textcolor(unsigned color) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}
/*
void Console::textcolor(Color color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}
*/

