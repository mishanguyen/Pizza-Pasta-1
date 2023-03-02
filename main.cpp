/* Here we need to create a queue. This porgram manages the orders in the italian restaurant where you can only order pizza or pasta (not both).
We enqueue() when a new customer comes in (basically, like when we place an order in starbucks). We get their info, order
Then we dequeue() when we give out the order. We can print smt like "Thank you, see you next time!" */

#include <iostream>
#include <type_traits>
#include "classLine.h"
#include "classOrder.h"

using namespace std;

int main() {

    cout << "**************************" << endl;
    cout << "Welcome to Pasta&Pizza #1!" << endl;
    cout << "**************************" << endl;
    cout << endl;

    // Declare type either PizzaOrder or PastaOrder
    Line<PastaOrder> newLine;

    // Printing a message depending on the previoius type declaration
    if (is_same<decltype(newLine), Line<PizzaOrder> >::value) {
        cout << "Today is a Pizza Day!" << endl;
    } else {
        cout << "Today is a Pasta Day!" << endl;
    }

    for (;;) {
        string role;
        cout << endl;
        cout << "Select your role:" << endl;
        cout << endl;
        cout << "1. Manager" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Quit" << endl;
        cout << endl;
        
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> role;

        if (role == "1") {
            char done = 'n';
            while (done != 'y') {
                cout << endl;
                cout << "Choose one of the options: " << endl;
                cout << "1. Check how many customers are in the line." << endl;
                cout << "2. View order details of the current customer." << endl;
                cout << "3. Give away the order for the current customer." << endl;
                cout << endl;
                cout << "Enter your choice: ";
                char managerChoice;
                cin >> managerChoice;

                // if user did not input a character (i.e. string)
                if (cin.fail() || cin.peek() != '\n') {  // check if input is not a single character
                    cout << endl;
                    cout << "Invalid choice. Please try again: " << endl;
                    cin.clear();  // reset input stream state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear input buffer
                    continue;
                }

                switch (managerChoice) {
                    case '1':  
                        cout << endl;
                        cout << "Number of people in line: " << newLine.size() << endl;
                        cout << endl;
                        cout << "Done (y/n)?: ";
                        cin >> done;
                        break;
                    case '2':
                        cout << endl;
                        cout << "Here is the order of the current customer: " << endl;
                        newLine.getFront();
                        cout << endl;
                        cout << "Done (y/n)?: ";
                        cin >> done;
                        break;
                    case '3':
                        cout << endl;
                        cout << "Giving away the order for " << newLine.getFrontName() << "!";
                        newLine.dequeue();
                        cout << endl;
                        cout << "Done (y/n)?: ";
                        cin >> done;
                        break;
                }
            }
        } else if (role == "2") {
            char done = 'n';
            while (done != 'y') {
                cout << endl;
                cout << "Choose one of the options: " << endl;
                cout << "1. Place an order" << endl;
                cout << "2. Check how many customers are in the line" << endl;
                cout << endl;
                char customerChoice;
                cout << "Enter your choice: ";
                cin >> customerChoice; 

                // if user did not input a character (i.e. string)
                if (cin.fail() || cin.peek() != '\n') {  // check if input is not a single character
                    cout << "Invalid choice. Please try again: " << endl;
                    cin.clear();  // reset input stream state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear input buffer
                    continue;
                }

                switch (customerChoice) {
                    case '1': 
                        cout << endl;
                        cout << "Let's get your order..." << endl;
                        cout << endl;
                        newLine.enqueue();
                        cout << endl;
                        cout << "Done (y/n)?: ";
                        cin >> done;
                        break;
                    case '2':
                        cout << endl;
                        cout << "Number of people in line: " << newLine.size() << endl;
                        cout << endl;
                        cout << "Done (y/n)?: ";
                        cin >> done;
                        break;
                }
            }
        } else if (role == "3") {
            newLine.clear();
            cout << "See you soon!" << endl;
            return EXIT_SUCCESS;
        } else {
            cout << endl;
            cout << "Inavlid choice. Please try again.";
            cout << endl;
        }
    }
}