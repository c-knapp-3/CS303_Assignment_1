// Carolyn Knapp
// CS 303
// Assignment 1
// Due: 9/11/23

#pragma once
#include "Functions.h"

int findNumber(int* array, int size) {
	int userNumber;
	cout << "Please enter the number you wish to find -> ";
	cin >> userNumber;		                         //get number input from user

	for (int i = 0; i < size; i++) {	             //loop through each element in array to determine if it is the same as user number
		if (array[i] == userNumber) {
			return i;					             //if number is found, return it's index (i)
		}                                  
	}
	return -1;                                       //if number is not found, return -1                                
}

void changeNumber(int* array, int size) {
	int userIndex;
	int userNewNumber;
	cout << "Please enter the index of the number you wish to change -> ";
	cin >> userIndex;		                         //get index input from user      

	if (userIndex < 0 || userIndex >= size) {	     //if index entered is below 0 or is 150 or higher (highest index should be 149)
		throw out_of_range("You must enter an index between 0 & 149 (including 0 & 149).");   //throw error
	}

	int oldNumber = array[userIndex];	                 //set variable to hold the original number
	cout << "\nPlease enter the new number -> ";
	cin >> userNewNumber;	                             //get number input from user (to replace oldNumber)
	array[userIndex] = userNewNumber;	                 //replace number at given userIndex 
	cout << "The number at index " << userIndex << " has been changed from " << oldNumber << " to " << userNewNumber << "." << endl << endl;
}

void addNumber(int* array, int size) {
	int userNumber;	                                   //get number input from user
	cout << "Please enter the number you wish to add -> ";
	cin >> userNumber;

	if (array[size - 1] != 0) {		                   //if last number in array is not zero, array is full
		throw out_of_range("Array is full, cannot add new number. Sorry!\n");
	}

	for (int i = 0; i < size; i++) {	              
		if (array[i] == 0) {                          //find first zero in array
			array[i] = userNumber;				      //replace that zero with given user input
			cout << array[i] << endl;	              //display number	         
			break;
		}
		cout << array[i] << " ";			          //display full array
	}
	cout << endl;
}

void replaceNumber(int* array, int size) {
	int userIndex;
	cout << "Please enter the index of the number you wish to replace with 0 -> ";
	cin >> userIndex;				                  //get index input from user
	array[userIndex] = 0;			                  //set element at userIndex equal to zero

	for (int i = 0; i <= userIndex; i++) {	          
		cout << array[i] << " ";                      //display array to zero just added - to show functionality
	}
	cout << endl << endl;
}