#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char *chars;
int charSize;

void getString();
void deleteChars();
void increaseCharsCapacity();
int checkWord(int start, int end);

int main()
{
	charSize = 100;
	chars = new char[charSize];
	int start = 0;
	bool validStart = true;
	int total = 0;

	getString(); //gets the string from the file

	for (int i = start; i < charSize; i++) //finds words
	{
		if (isspace(chars[i]) || i >= charSize - 1) //checks contents of words
		{
			if (validStart && i > start+1)
			{
				total += checkWord(start, i);
				start = i;
			}
			else
			{
				start = i;
				validStart = true;
			}
		}
		else if (!isalpha(chars[i]))
			validStart = false;
	} 


	cout << total;
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
		{
			if (i >= charSize)
				increaseCharsCapacity();
			chars[i] = ch;	
		}
	}
	cin.clear();
	cin.ignore(100, '\n');
}

void increaseCharsCapacity() //increases the capacity of the dynamic array 
{
	char *chars2 = new char[charSize+100];
	for (int i = 0; i < charSize; i++)
		chars2[i] = chars[i];
	deleteChars();
	chars = chars2;
	charSize += 100;
}

void deleteChars() //safely clears dynamic memory
{
	delete [] chars;
	chars = nullptr;
}

int checkWord(int start, int end) //counts each appearance of each letter and returns the highest count
{
	int * counts = new int[end-start];
	for (int i = 0; i < end-start; i++)
		counts[i] = 1;
	int most;
	for (int i = start; i <= end; i++) //counts each letter
	{
		for (int j = i+1; j <= end; j++)
		{
			if (toupper(chars[i]) == toupper(chars[j]))
				counts[i-start]++;

		}
	}
	most = 1;
	for (int i = 1; i < end-start; i++) //finds the highest count
	{	
		if (counts[i] > most)
			most = counts[i];
	}
	return most;
}





