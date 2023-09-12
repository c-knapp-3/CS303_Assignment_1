#include "Functions.h"

int main() {
    const int ARRAY_SIZE = 150;
    int array_of_numbers[ARRAY_SIZE];

    ifstream inFile("numbers.txt");             //open file
    if (!inFile.is_open()) {
        cout << "File not found.";              //if file does not open, display error message
    }
    else {
        for (int i = 0; i < ARRAY_SIZE; i++) {  //read numbers from file into array
            inFile >> array_of_numbers[i];
        }
    }
    inFile.close();                             //close file

    for (int i = 100; i < ARRAY_SIZE; ++i) {   
        array_of_numbers[i] = 0;                //adds zeros from last number read from file to end of array
    }

    while (true) {
        char userChoice;
        cout << "What would you like to do with the array?\n\n(F)ind a number\n(C)hange a number\n(A)dd a number to the end\n(R)eplace a number\n(Q)uit\n\nPlease enter your choice (F, C, A, R or Q) -> ";
        cin >> userChoice;                      //get char selection from user
        cout << endl;

        if (toupper(userChoice) == 'Q') {       //make user char input into an uppercase char to cover for user entering a lowercase char
            break;
        }
        switch (toupper(userChoice)) {          //make user char input uppercase
        case 'F':                               //when input is 'f' or 'F'
            cout << "Your number was found at index " << findNumber(array_of_numbers, ARRAY_SIZE) << " (if -1, your number was not found).\n\n";
            break;
        case 'C':                               //when input is 'c' or 'C'
            while (true) {                      
                try {                           
                    changeNumber(array_of_numbers, ARRAY_SIZE);  //try to run function, if it runs without errors
                    break;                                       //leave loop to go back to main menu
                }
                catch (out_of_range& e) {                         //catch error
                    cerr << "Error: " << e.what() << " Please try again...\n\n";   //display error message to user
                }
            }
            break;
        case 'A':                                //when user input is 'a' or 'A'
            try {
                addNumber(array_of_numbers, ARRAY_SIZE);         //try to run function
            }
            catch (out_of_range& excpt) {                        //catch error
                cerr << "Error: " << excpt.what() << endl;       //display error message
            }
            break;
        case 'R':                                 //when user input is 'r' or 'R'
            replaceNumber(array_of_numbers, ARRAY_SIZE);     //run function
            break;
        default:
            cout << "Wrong choice, please enter (F, C, A, R or Q).\n\n";     //if user fails to enter one of the 5 correct cases
            break;
        }
    }
}


