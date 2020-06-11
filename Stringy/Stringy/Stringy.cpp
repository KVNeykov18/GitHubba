#include <iostream>
#include <string>
using namespace std;
int mainMenu() //Main Menu
{
	int x;
	cout << " .: Welcome to Stringy! :. " << endl;
	cout << "Make a choice." << endl;
	cout << "Manage strings... (1)" << endl;
	cout << "Sort strings by... (2)" << endl;
	cout << "Search for a string's index(es) (3)" << endl;
	cout << "Show all strings (4)" << endl;
	cout << "Project creators (5)" << endl;
	cout << "Exit (0)" << endl;
	cin >> x;
	return x;
}
int manageMenu() //A menu for options related to string manipulation
{
	int x;
	cout << "Create a string (1)" << endl;
	cout << "Remove a string (2)" << endl;
	cout << "Change a string (3)" << endl;
	cout << "Swap strings (4)" << endl;
	cout << "Cancel (0)" << endl;
	cin >> x;
	return x;
} 
string manageString(string *x, int nextEmptySlot, int choice) //The strings get changed here
{
	string y; int indexChoice, iC2;
	switch (choice)
	{
	case 1: //Adds a new string at the first empty index
	{
		if (nextEmptySlot >= 10) cout << "Can't have more than 10 strings." << endl;
		else
		{
			cout << "Enter a string or type 0 to cancel => ";
			cin >> y;
			if (y == "0");
			{
				x[nextEmptySlot] = y;
				nextEmptySlot++;
				cout << "String successfully added." << endl;
			}
		}
		break;
	}
	case 2: //Removes a string from a chosen index by moving strings to the previous index and empties the last filled index
	{
		if (nextEmptySlot <= 0) cout << "There are no strings in the array." << endl;
		else
		{
			cout << "Enter the index of a string to remove => ";
			cin >> indexChoice;
			if (indexChoice >= nextEmptySlot) cout << endl << "There's no string on that index." << endl;
			else
			{
				for (int i = indexChoice; i < nextEmptySlot - 1; i++)
				{
					x[i] = x[i + 1];
				}
				x[nextEmptySlot - 1].clear();
				nextEmptySlot--;
				cout << endl << "String successfully removed." << endl;
			}
		}
		break;
	}
	case 3: //Rewrite an already existing string
	{
		if (nextEmptySlot <= 0) cout << "There are no strings in the array." << endl;
		else
		{
			cout << "Enter the index of a string to change => ";
			cin >> indexChoice;
			if (indexChoice >= nextEmptySlot) cout << endl << "There's no string on that index." << endl;
			else
			{
				x[indexChoice].clear();
				cout << endl << "Change string to => ";
				cin >> x[indexChoice];
				cout << endl << "String successfully changed." << endl;
			}
		}
		break;
	}
	case 4: //Swap two strings' indexes
	{
		if (nextEmptySlot <= 1) cout << "There are less than 2 strings in the array." << endl;
		else
		{
			cout << "Enter 2 indexes of strings to swap => ";
			cin >> indexChoice >> iC2;
			if (indexChoice >= nextEmptySlot or iC2 >= nextEmptySlot) cout << endl << "There's no string on that index." << endl;
			else
			{
				swap(x[indexChoice], x[iC2]);
				cout << endl << "Strings successfully swapped." << endl;
			}
		}
		break;
	}
	case 0: //Goes to the previous menu
	{
		break;
	}
	default: //If the chosen number isn't in the listed options
	{
		cout << "Invalid choice.";
		break;
	}
	}
	return *x;
}
int sortMenu() //A menu for changing strings' positions
{
	int x;
	cout << "Sort by size in decending order (1)" << endl;
	cout << "Sort by size in ascending order (2)" << endl;
	cout << "Cancel (0)" << endl;
	cin >> x;
	return x;
}
string sortString(string *x, int nextEmptySlot, int choice) //A function for sorting string locations
{
	if (nextEmptySlot == 0) cout << "There are no strings.";
	else
	{
		switch (choice)
		{
		case 1: //Sorts the biggest to the left and the smallest to the right
		{
			for (int i = 0; i < nextEmptySlot - 1; i++)
			{
				for (int j = i; j < nextEmptySlot - 1; j++)
				{
					if (x[j] < x[j + 1]) swap(x[j], x[j + 1]);
				}
			}
			break;
		}
		case 2: //Sorts the smallest to the left and the biggest to the right
		{
			for (int i = 0; i < nextEmptySlot - 1; i++)
			{
				for (int j = i; j < nextEmptySlot - 1; j++)
				{
					if (x[j] > x[j + 1]) swap(x[j], x[j + 1]);
				}
			}
			break;
		}
		case 0: //Goes to the previous menu
		{
			break;
		}
		default: //If the chosen number isn't in the listed options
		{
			cout << "Invalid choice.";
			break;
		}
		}
	}
	cout << endl << "Strings successfully sorted." << endl;
	return *x;
}
void stringSearch(string *x, int nextEmptySlot) //Search for a string's indexes
{
	string y;
	int stringsFound = 0, stringsLocation[10];
	cout << "Enter the string you want to find or type 0 to cancel => ";
	cin >> y;
	if (y != "0")
	{
		for (int i = 0; i < nextEmptySlot; i++) //Finds the amount of occurences and where they occur
		{
			if (x[i] == y)
			{
				stringsLocation[stringsFound] = i;
				stringsFound++;
			}
		}
		if (stringsFound == 0) cout << "No strings have been found." << endl; //If there are no indexes matching
		else
		{
			if (stringsFound == 1) cout << stringsFound << " string has been found at index " << stringsLocation[0]; //If there's only one index matching
			else //If more than one indexes are matching
			{
				cout << stringsFound << " strings have been found at indexes ";
				for (int i = 0; i < stringsFound; i++) //Outputs all of the indexes
				{
					cout << stringsLocation[i];
					if (stringsFound - i > 1)
					{
						cout << ", ";
					}
				}
				cout << endl;
			}
		}
	}
}
int main()
{
	string x[10];
	int choice = -1, nextEmptySlot = 0, manage, sort;
	do //This will continue to happen until the input is 0
	{
		choice = mainMenu();
		switch (choice)
		{
		case 1: //This goes to string changing related options
		{
			manage = manageMenu();
			if (manage != 0)
			{
				*x = manageString(x, nextEmptySlot, manage);
			}
			break;
		}
		case 2: //This goes to string sorting related options
		{
			if (nextEmptySlot == 0) cout << "There are no strings." << endl;
			sort = sortMenu();
			if (sort != 0) *x = sortString(x, nextEmptySlot, sort);
			break;
		}
		case 3: //This goes to a string searching tool
		{
			if (nextEmptySlot == 0)
			{
				cout << "There are no strings." << endl;
			}
			else
			{
				stringSearch(x, nextEmptySlot);
			}
			break;
		}
		case 4: //This outputs all of the strings in order
		{
			if (nextEmptySlot == 0) cout << "There are no strings." << endl;
			else
			{
				for (int i = 0; i < nextEmptySlot; i++)
				{
					cout << i << " - " << x[i] << endl;
				}
			}
			break;
		}
		case 5: //This outputs the workers on the project
		{
			cout << "Theodore Angelov 9v: Main programmer, debugger" << endl;
			cout << "Kristian Neikov 9a: Project leader, documentator, presentor" << endl;
			break;
		}
		case 0: //This outputs a message before the program ends
		{
			cout << "Thank you for using Stringy!";
			break;
		}
		default: //If the chosen number isn't in the listed options
		{
			cout << "Invalid choice.";
			break;
		}
		}
		nextEmptySlot = 0; //These four lines update what is the next to use empty index
		for (int i = 0; i < 10; i++)
		{
			if (!x[i].empty()) nextEmptySlot++;
		}
		cout << endl; //This is there just so it looks less messy on the console
	} while (choice != 0);
}