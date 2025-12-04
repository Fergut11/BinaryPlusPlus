#include <bitset>
#include <cstddef>
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

// Takes an int and converts it to a binary string
// size_t gets the size of a string and the find_first_not_of() looks for the first 1 in the string
// the substr will only show the bits after the fird found 1
string convert_to_binary(int number){
    string bitset_string = bitset<32>(number).to_string();
    size_t first_one = bitset_string.find_first_not_of("0");
    return bitset_string.substr(first_one);

}

// prints out the number input from user converted to binary
int main() {
    cout << convert_to_binary(get_number());
    return 0;
}