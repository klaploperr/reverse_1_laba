#include <iostream>
#include <string>
#include <fstream>
#include "obfuscate.h"

using namespace std;
int pass_check();
void menu();
int WriteToFile(char* path, string data);
int ReadFile(char* path);
const char* pass = AY_OBFUSCATE("ikizi");
string password(pass);
const char* pathToFile = AY_OBFUSCATE("C:\\Users\\metal\\Desktop\\Реверс\\test.txt");

int main() {
	cout << AY_OBFUSCATE("Welcome!") << endl;
	if (!pass_check())
		return 0;
	menu();
	return 0;
}

void menu() {
	char choice;
	string data = "";
	cout << AY_OBFUSCATE("INTERFACE\n[r]ead file\n[w]rite to file\n[e]xit");
	while (1)
	{
		cout << "\n>> ";
		cin >> choice;
		switch (choice)
		{
		case 'r':
		{
			ReadFile((char*)pathToFile);
			break;
		}
		case 'w':
		{
			cout << AY_OBFUSCATE("Enter data: ");
			cin >> data;
			WriteToFile((char*)pathToFile, (char*)data.c_str());
			break;
		}
		case 'e':
		{
			exit(0);

		}
		default:
		{
			cout << AY_OBFUSCATE("Wrong command");
		}
		}
	}
}

int WriteToFile(char* path, string data)
{
	ofstream file(path, ios::out | ios::app | ios::ate);
	if (!file.is_open())
	{
		cout << AY_OBFUSCATE("Can`t open file") << endl;
		return -1;
	}
	else
		cout << AY_OBFUSCATE("File is opened") << endl;
	file.write(data.c_str(), data.size());
	file.close();
	cout << AY_OBFUSCATE("Operation finished") << endl;
	return 0;
}

int ReadFile(char* path)
{
	int size;
	ifstream file(path, ios::in | ios::binary | ios::ate);
	if (!file.is_open())
	{
		cout << AY_OBFUSCATE("Can`t open file") << endl;
		return -1;
	}
	else
		cout << AY_OBFUSCATE("File is opened") << endl;
	size = file.tellg();
	file.seekg(0, file.beg);
	char* data = new char[size + 1];
	file.read(data, size);
	data[size] = '\0';
	cout << data << endl;
	file.close();
	return 0;
}

int pass_check() {
	string check = "";
	int attempt = 3;
	cout << AY_OBFUSCATE("Enter password: ");
	while (attempt) {
		cin >> check;
		if (check._Equal(password)) {
			cout << AY_OBFUSCATE("Success!") << endl;
			return 1;
		}
		else {
			attempt--;
			cout << AY_OBFUSCATE("Wrong password. Try again!") << endl;
		}
	}
	return 0;
}