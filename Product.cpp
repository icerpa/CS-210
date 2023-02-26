/*
* CS-210 Project Three
* 
* Name: Ivette Cerpa
* Description: Product class contains a setter and getter, and functions for formatting output, displaying the menu,
*				creating a map, backing up that map, validating input, and printing output. 
* Date: February 18 2023
*/

#include "Product.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

////////////////////////////////////////////setter and getter
void Product::setItemName(string itemName){
	this->itemName = itemName;
}

string Product::getItemName(){
	return itemName;
}
///////////////////////////////////////////

/*
* repeatChar takes an int and char as parameters, does not return
* 
* repeats the given char for the given int amount of times.
*/
void Product::repeatChar(int repeats, char symbol){
	for (int i = 0; i < repeats; i++) {
		cout << left << symbol;
	}
	cout << endl;
}

/*
* displayMenu takes no paramenters and does not return
* 
* prints to screen the program's available functions
*/
void Product::displayMenu(){
	cout << "Please enter 1 2 3 or 4" << endl
		<< "Option 1: " << "Get frequency of an item" << endl
		<< "Option 2: " << "Print a list of frequency of all items purchased" << endl
		<< "Option 3: " << "Print a histogram of frequency of all items purchased" << endl
		<< "Option 4: " << "Exit program" << endl << endl;

	cout << "Enter option choice: ";
}

/*
* createMap takes no parameters and does not return
* 
* will read file line by line and if product isn't in the map, it will be added to the map.
* else if the product is already exists in the map, it will increase the product count.
*/
void Product::createMap(){
	ifstream FileToRead("CS210_Project_Three_Input_File.txt");
	string productName;
	string fileLine;
	int count;

	while (getline(FileToRead, fileLine)) {

		productName = fileLine;

		//checks if product isn't in map
		if (productMap.count(productName) == 0) {
			productMap.emplace(productName, 1); //adds to map
		}
		else {
			count = productMap.at(productName);
			count++;
			productMap.at(productName) = count; //replaces old count with new count in map
		}
	}

	FileToRead.close();
}

/*
* backupData takes no parameters and does not return
* 
* iterates through the product map and will write the product name and count
* to the frequency.dat file
*/
void Product::backupData(){
	ofstream FileToWrite("frequency.dat");

	for (itr = productMap.begin(); itr != productMap.end(); itr++) {
		FileToWrite << itr->first << " " << itr->second << endl;
	}

	FileToWrite.close();
}

/*
* validateSearch takes a string parameter, does not return
* 
* While the input isn't valid, will check each char in the given string
* to make sure that only letters are present. If something other than a letter is found
* then will let user know input is invalid and ask for another input and the string check will start over.
* Will capitalize first letter and make sure all following letters are lowercase. Finally will set item name with valid input.
*/
void Product::validateSearch(string itemName){

	bool invalidSearch = true;
	string validatedInput;

	while (invalidSearch == true) {
		string validatedInput = "";
		for (size_t i = 0; i < itemName.size(); i++) {
			//if branch makes sure only letters are input
			if (!isalpha(itemName.at(i))) {
				cout << "\nPlease use only letters when entering search term\n\n"
					<< "Please enter item to search for: ";
				cin >> itemName;
				break; //breaks out of for loop to start over with new input
			}
			//this branch will capitalize first letter
			else if (i == 0) {
				char firstLetter = toupper(itemName.at(i));
				validatedInput.push_back(firstLetter); //appends to the validated string
			}
			//This branch will make sure all other letters are lowercase
			else {
				char letter = tolower(itemName.at(i));
				validatedInput.push_back(letter); 

				//when this if is entered, then the entire string has been checked and is validated so while loop can be ended.
				if (i == itemName.size() - 1) {
					invalidSearch = false;
				}
			}
		}
	}
	setItemName(validatedInput);
}

/*
* printData takes a string parameter, does not return
* 
* Prints out the data formatted depending on the choice the user made from the menu options.
* 
*/
void Product::printData(string userChoice){
	string itemName;
	int itemFrequency;

	//This branch prints out the frequency of the item that was searched for or lets user know that the item was not found
	if (userChoice == "1") {
		itemName = getItemName();
		if (productMap.count(itemName) == 1) {
			itemFrequency = productMap.at(itemName);
			cout << itemFrequency << endl;
		}
		else {
			cout << "Item not found" << endl;
		}
	}
	//This branch will print out either the item name and the frequency or will print out the item name and histogram
	else{
		cout << right << setw(26) << "Item Name | Frequency" << endl;
		repeatChar(31, '-');

		for (itr = productMap.begin(); itr != productMap.end(); itr++) {
			//this choice prints out item and frequency
			if (userChoice == "2") {
				cout << right << setw(15) << itr->first;
				cout << setw(1) << "   "; //three spaces better readability of data
				cout << itr->second << endl;
			}
			//else will print out the item name and histogram created using a call to repeatChar
			else {
				cout << right << setw(15) << itr->first;
				cout << setw(1) << "| ";
				repeatChar(productMap.at(itr->first), '*');
			}
		}
	}
	cout << endl << endl;
}


