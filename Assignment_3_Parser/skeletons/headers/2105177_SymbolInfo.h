#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <string>
#include <vector>

using namespace std;

// data types 
// INT
// FLOAT

class Parameters {
private:
    vector<string> variables;

public:
    // Constructor
    Parameters() = default;

    // getters and setters
    const vector<string>& get_parameters() const {
        return variables;
    }

    void set_parameters(const vector<string>& vars) {
        variables = vars;
    }

    // Add a string to the list
    void add(const std::string& str) {
        variables.emplace_back(str);
    }

    // Get the size of the list
    std::string size() const {
        return std::to_string(variables.size());
    }
};

struct Identifier {
    string idName = "EMPTY";
    string idType = "EMPTY";
    bool isArray = false;
    int arraySize = 0;
    int isFunction = 0;
    int isDeclared = 0;
    string returnType = "EMPTY";
    Parameters parameters;
};

class SymbolInfo {   
    string name;
    string type;
    SymbolInfo* next; // points to next symbol of the chain

public:
    bool isArray = false;
    int arraySize = 0; 
    Identifier id;

    // methods
    SymbolInfo(string name, string type, SymbolInfo* next = NULL);
    ~SymbolInfo();

    string getName();
    void setName(string name);

    string getType();
    void setType(string type);

    SymbolInfo* getNext();
    void setNext(SymbolInfo* next);
};



#endif
