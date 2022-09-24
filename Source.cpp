#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int pass_check();
void menu();
int WriteToFile(char* path, string data);
int ReadFile(char* path);
void printen(string str);
string password = "kikxk]qknc";
const char* pathToFile = "C:\\Users\\metal\\Desktop\\Πεβεπρ\\test.txt";

int main() {
	printen("Ugnamog#");
	if (!pass_check())
		return 0;
	menu();
	return 0;
}

void printen(string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = str[i] ^ 2;
	}
	cout << str << endl;
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
			printen("Glvgp\"fcvc8\"");
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
			printen("Upmle\"amooclf");
		}
		}
	}
}

int WriteToFile(char* path, string data)
{
	ofstream file(path, ios::out | ios::app | ios::ate);
	if (!file.is_open())
	{
		printen("Aclbv\"mrgl\"dkng");
		return -1;
	}
	else
		printen("Dkng\"kq\"mrglgf");
	file.write(data.c_str(), data.size());
	file.close();
	printen("Mrgpcvkml\"dklkqjgf");
	return 0;
}

int ReadFile(char* path)
{
	int size;
	ifstream file(path, ios::in | ios::binary | ios::ate);
	if (!file.is_open())
	{
		printen("Aclbv\"mrgl\"dkng");
		return -1;
	}
	else
		printen("Dkng\"kq\"mrglgf");
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
	printen("Glvgp\"rcqqumpf8\"");
	while (attempt) {
		cin >> check;
		for (int i = 0; i < check.length(); i++) {
			check[i] = check[i] ^ 2;
		}
		if (check._Equal(password)) {
			printen("Qwaagqq#");
			return 1;
		}
		else {
			attempt--;
			printen("Upmle\"rcqqumpf#\"Vp{\"ceckl, ");
		}
	}
	return 0;
}