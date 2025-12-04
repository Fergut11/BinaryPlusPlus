#include <bitset>
#include <iostream>
#include <string>
using namespace std;    

// Gets input from the user as a string and converts it to an int
int get_number(){
    string user_input;
    int binary_result;

    cout << "Type a number and it will return as a binary"<< endl;
    while (true) {
        cin >> user_input;
        try {
            // this takes user_input and converts it to an int
            // nullptr means to not care about pointers
            // the 0 denotes the base and when 0 it should auto detect
            binary_result = stoi(user_input,nullptr, 0);
            break;
        }
        catch (const invalid_argument&) {
        cout << "Invalid input: not a number." << endl;
        }
    }
    return binary_result;
}

bitset<32> convert_to_binary(int number){
    return bitset<32>(number);
}

int main() {
    cout << convert_to_binary(get_number());
    return 0;
}