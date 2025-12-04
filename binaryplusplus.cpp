#include <bitset>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;    

// Gets input from the user as a string and converts it to an int
int get_number(){
    string user_input;
    int binary_result;

    cout << R"(
    Type a number and it will return as a binary
    Decimal can be as written, Hex should be preceeded with a 0x, Octal with a 0.
    Dec : 5, 65, 76
    Hexidecimal : 0xFF43, 0x10F7, 0xABC123
    Octodecimal : 0771, 0233, 044
    
    )";
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
    // make sure the '0' is not "0" or it will crash
    // "0" is a pointer to a string literal not the character itself
    size_t first_one = bitset_string.find_first_not_of('0');

    if (first_one == string::npos){
        return "0";
    }

    return bitset_string.substr(first_one);

}

char* terminal_conversion(char* terminal_input){
    try{
        int result = stoi(string(terminal_input), nullptr, 0);
        cout << convert_to_binary(result);
    }
    catch(const invalid_argument&){
        cout << "invalid input" << endl;
    }
    return 0;
}


// prints out the number input from user converted to binary
int main(int argc, char* argv[]) {
    // argc checks if an input was given through the terminal or not
    // if not the program runs a little differently
    if (argc > 1) {
       cout << terminal_conversion(argv[1]);
    }
    else{
        cout << convert_to_binary(get_number());
    }
    return 0;
}