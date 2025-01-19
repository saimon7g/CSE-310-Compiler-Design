#pragma once
#include <bits/stdc++.h>

using namespace std;

class Parameter {
private:
    string name, type;
public:
    Parameter() {
        //cout<<" null constructor called";
        name = "";
        type = "";
    }
    Parameter(string n,string t){
        //cout<<" parameter constructor called";
        name=n;
        type=t;
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

    ~Parameter(){
        //cout<< "destructor called";
        //delete next;
    }
};