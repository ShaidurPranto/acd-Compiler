#include<iostream>
#include<string>

using namespace std;

class SymbolInfo{
    string name;
    string type;
    SymbolInfo* next;

    public:
    SymbolInfo(string name , string type , SymbolInfo* next = NULL){
        this->name = name;
        this->type = type;
        this->next = next;
    }
    ~SymbolInfo(){

    }
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    string getType(){
        return this->type;
    }
    void setType(string type){
        this->type = type;
    }
    SymbolInfo* getNext(){
        return this->next;
    }
    void setNext(SymbolInfo* next){
        this->next = next;
    }

};