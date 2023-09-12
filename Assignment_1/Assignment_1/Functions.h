// Carolyn Knapp
// CS 303
// Assignment 1
// Due: 9/11/23

#pragma once
#include <iostream>
#include <fstream>

using namespace std;

int findNumber(int* array, int size); //Pre - takes array and size (of array) //Post - if user input (integer) is found, return 1, otherwise, return -1

void changeNumber(int* array, int size); //Pre - takes array and size (of array) //Post - changes integer at index (given by user) to new number (also given by user)

void addNumber(int* array, int size);	//Pre - takes array and size (of array) //Post - adds integer (given by user) to the end of the array by replacing first zero found until arry is full

void replaceNumber(int* array, int size); //Pre - takes array and size (of array) //Post - replaces integer at index (given by user) with the number zero

