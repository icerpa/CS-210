/*
* CS-210 Project Three
* 
* Name: Ivette Cerpa
* Description: Header file containing class prototype
* Date: February 18 2023
*/

#ifndef CS210_PROJECTTHREE_PRODUCT_H
#define CS210_PROJECTTHREE_PRODUCT_H

#include <string>
#include <map>

using namespace std;

class Product
{
public:
	void repeatChar(int repeats, char symbol);
	void displayMenu();

	void createMap();
	void backupData();

	void validateSearch(string itemName);
	void printData(string userChoice);

private:
	void setItemName(string itemName);
	string getItemName();

	map<string, int> productMap; //map that holds product data
	map<string, int>::iterator itr; //iterator for productMap
	string itemName;
	

};

#endif // CS210_PROJECTTHREE_PRODUCT_H


