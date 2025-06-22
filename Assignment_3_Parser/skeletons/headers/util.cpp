#pragma once;
#include<string>
#include<vector>
#include<algorithm>
#include "2105177_SymbolInfo.h"

class symbol_list {
private:
    std::vector<SymbolInfo*> variables;
public:
    // Add a variable to the list
    void add(SymbolInfo* var) {
        variables.emplace_back(var);
    }

    // Get the list of variables
    const std::vector<SymbolInfo*>& get_variables() const {
        return variables;
    }

    // Find a variable in the list
    SymbolInfo* find(const std::string& name) {
        for (auto& var : variables) {
            if (var->getName() == name) {
                return var;
            }
        }
        return nullptr;
    } 
};

class str_list {
private:
    std::vector<std::string> variables;

public:
    // Constructor
    str_list() = default;

    // getters and setters
    const std::vector<std::string>& get_variables() const {
        return variables;
    }
    void set_variables(const std::vector<std::string>& vars) {
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

    // Clear the list
    void clear() {
        variables.clear();
    }

    std::string get_list_as_string() const {
        std::string result;
        for (const auto& var : variables) {
            if (!result.empty()) {
                result += ", ";
            }
            result += var;
        }
        return result;
    }

};