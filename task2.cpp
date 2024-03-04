#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	map<string, string> contacts;
	while (true) {
		cout << "1. Add a contact\n";
		cout << "2. Search for a contact\n";
		cout << "3. Quit\n";
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			string name, contact;
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter Contact: ";
			getline(cin, contact);
			contacts[name] = contact;
			cout << "Contact added successfully.\n";
		}
		else if(choice==2) {
			string Name;
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, Name);
			auto i = contacts.find(Name);
			if (i != contacts.end()) {
				cout << "Contact details: " << i->second << endl; 
			}
			else {
				cout << "Contact not found.\n";
			}
		}
		else if (choice==3) {
			cout << "Exiting program.\n";
			return 0;
		}
		else{
			cout << "Invalid choice. Please enter a valid option.\n";
		}
	}
	
	return 0;
}