#include<iostream>
#include<string>
#include "2105177_SymbolTable.hpp"

using namespace std;

string interpret_string_literal(string str) {
    string result;
    for (size_t i = 0; i < str.length(); ++i) {
        // Handle backslash at the end of line (line continuation)
        if (str[i] == '\\' && i + 1 < str.length() && str[i + 1] == '\n') {
            cout << "HEHE BOY it was a tab"<<endl;
            i++;               // Skip the newline
            continue;          // Don't add anything to result
        }

        // Handle escape sequences
        if (str[i] == '\\' && i + 1 < str.length()) {
            switch (str[++i]) {
                case 'n': result += '\t';cout << "hello fucking" ;break;
                case 't': result += '\t'; break;
                case 'r': result += '\r'; break;
                case '"': result += '"'; break;
                case '\\': result += '\\'; break;
                default: result += str[i]; break;
            }
        }
        else if (str[i] == '\n') {
            result += '\n';   
        }
        else {
            result += str[i];
        }
    }
    return result;
}

int main(){

    string s = "hello \
    world";
    cout<<interpret_string_literal(s);

    return 0;
}