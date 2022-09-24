#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int pass_check();
void menu();
int WriteToFile(char* path, string data);
int ReadFile(char* path);
string password = "ikizi";
const char* pathToFile = "C:\\Users\\metal\\Desktop\\Πεβεπρ\\test.txt";

int main() {
	cout << "Welcome!" << endl;
	if (!pass_check())
		return 0;
	menu();
	return 0;
}

void menu() {
	char choice;
	string data = "";
	cout << "INTERFACE\n[r]ead file\n[w]rite to file\n[e]xit";
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
			cout << "Enter data: ";
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
			cout << "Wrong command";
		}
		}
	}
}

int WriteToFile(char* path, string data)
{
	ofstream file(path, ios::out | ios::app | ios::ate);
	if (!file.is_open())
	{
		cout << "Can`t open file" << endl;
		return -1;
	}
	else
		cout << "File is opened" << endl;
	file.write(data.c_str(), data.size());
	file.close();
	cout << "Operation finished" << endl;
	return 0;
}

int ReadFile(char* path)
{
	int size;
	ifstream file(path, ios::in | ios::binary | ios::ate);
	if (!file.is_open())
	{
		cout << "Can`t open file" << endl;
		return -1;
	}
	else
		cout << "File is opened" << endl;
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
	cout << "Enter password: ";
	while (attempt) {
		cin >> check;
		for (int i = 0; i < check.length(); i++) {
			check[i] = check[i] ^ 2;
		}
		if (check._Equal(password)) {
			cout << "Success!" << endl;
			return 1;
		}
		else {
			attempt--;
			cout << "Wrong password. Try again!" << endl;
		}
	}
	return 0;
}