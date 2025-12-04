#include <bitset>
#include <iostream>
using namespace std;    


int get_number(){
    int number;
    cout << "Type a number and it will return as a binary"<< endl;
    while (true) {
        if (cin >> number){
            break;
        }
        else {
            cout << "Please input a valid number"<< endl;
            // cin.clear() gets rid of the user's input
            // cin.ignore() removes the input from the buffer, well it removes 10000 characters 
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    return number;
}
int main() {
    cout << bitset<32>(get_number());
    return 0;
}