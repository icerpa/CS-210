/*
* CS-210 Project Three
* 
* Name: Ivette Cerpa
* Description: Main uses a Product object to create the item map and to backup the data. Then prompts the user for a menu
*				choice and calls the needed functions using the Product object. Keeps prompting the user for a menu choice
*				until the user selects 4 which will end the program. 
* Date: February 18 2023
*/

#include "Product.h"
#include <iostream>
#include <string>

using namespace std;


int main() {

	Product item;
	string userChoice;
	string itemName;

	item.createMap(); //creates map
	item.backupData(); // creates backup
	
	while (userChoice != "4") {
		item.displayMenu();
		cin >> userChoice;

		if (userChoice == "1") {
			cout << "Please enter product name: ";
			cin >> itemName;
			cout << endl;

			item.validateSearch(itemName);
			item.printData("1");
		}
		else if (userChoice == "2") {
			cout << endl << endl; //for better readability
			item.printData("2");
		}
		else if (userChoice == "3") {
			cout << endl; //for better readability
			item.printData("3");
		}
		else if (userChoice == "4") {
			cout << "End of program";
			break;
		}
		else {
			cout << "\n\nPlease only enter 1 2 3 or 4\n\n";
		}
	}

	return 0;
}