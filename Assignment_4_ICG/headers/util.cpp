#pragma once;
#include<string>
#include<vector>
#include<algorithm>
#include "2105177_SymbolInfo.h"


class identifier_list {
private:
    std::vector<Identifier> identifiers;
public:
    // Constructor
    identifier_list() = default;

    // Add an identifier to the list
    void add(const Identifier& id) {
        identifiers.emplace_back(id);
    }

    // Get the list of identifiers
    const std::vector<Identifier>& get_identifiers() const {
        return identifiers;
    }
    
    // Find an identifier in the list
    bool find(const std::string& id) const {
        return std::find_if(identifiers.begin(), identifiers.end(),
            [&id](const Identifier& identifier) {
                return identifier.idName == id;
            }) != identifiers.end();
    }
};