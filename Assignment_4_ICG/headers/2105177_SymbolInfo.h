#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <string>
#include <vector>

using namespace std;

// data types 
// INT
// FLOAT
// BOOL

struct Variable {
    string name = "EMPTY";
    string type = "EMPTY";
};

class param_list {
private:
    vector<Variable> variables;

public:
    // Constructor
    param_list() = default;

    // getters and setters
    const vector<Variable>& get_param() const {
        return variables;
    }

    void set_param(const vector<Variable>& vars) {
        variables = vars;
    }

    // Add a string to the list
    void add(const Variable& var) {
        variables.emplace_back(var);    
    }

    // Get the size of the list
    int size() const {
        return variables.size();
    }

    void clear() {
        variables.clear();
    }
};

struct Identifier {
    string idName = "EMPTY";
    string idType = "EMPTY";
    bool isGlobal = false;
    int stackOffset = 0; 
    bool isArray = false;
    string arrayIndex = "EMPTY";
    int arraySize = 0;
    string constValue = "EMPTY";

    bool isFunction = false;
    bool isDeclared = false;
    bool isDefined = false;
    string returnType = "EMPTY";
    param_list parameters;
    bool hasReturn = false;
    bool isError = false;
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
