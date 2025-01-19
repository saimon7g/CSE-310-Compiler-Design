#pragma once
#include <string>
#include<bits/stdc++.h>
using namespace std;


class SymbolInfo {
private:
    string name, type;
    SymbolInfo *next;
public:
    SymbolInfo() {
        //cout<<" null constructor called";
        name = "";
        type = "";
        next=NULL;
    }
    SymbolInfo(string n,string t){
        //cout<<" parameter constructor called";
        name=n;
        type=t;
        this->next=NULL;
    }

    string getName(){
        return name;
    }

    void setName( string name) {
        this->name = name;
    }
    string getType(){
        return type;
    }

    void setType(string type) {
        this->type = type;
    }

    SymbolInfo *getNext(){
        return next;
    }

    void setNext(SymbolInfo *next) {
        this->next = next;
    }

    ~SymbolInfo(){
        //cout<< "destructor called";
        //delete next;
    }
};