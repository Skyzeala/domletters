#include <iostream>
#include <cstring>

using namespace std;

char *chars;
int charSize;

void getString();
void deleteChars();

int main()
{
	charSize = 100;
	chars = new char[charSize];
	//int start = 0;
	//bool validStart = true;

	getString();

	for (int i = 0; i < charSize; i++)
		cout << chars[i];
	//for (int i = start; i < 






	deleteChars();	
	return 0;
}

void getString() //gets every character including newlines
{
	char ch;
	for (int i = 0; cin; i++)
	{
		cin.get(ch);
		if (cin)
			chars[i] = ch;	
	}
	cin.clear();
	cin.ignore(100, '\n');
}

void increaseCharsCapacity()
{
	char *chars2 = new char[charSize+100];
	for (int i = 0; i < charSize; i++)
		chars2[i] = chars[i];
	deleteChars();
	chars = chars2;
	charSize += 100;
}

void deleteChars()
{
	delete [] chars;
	chars = nullptr;
}

int checkWord(int start, int end)
{



	return 1;
}





