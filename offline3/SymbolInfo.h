#pragma once
#include <bits/stdc++.h>

using namespace std;

class SymbolInfo {
private:
    string name;
    string type;
    string typeSpecifier;
    bool functionDefinition = false;
    bool functionDeclaration = false;
    bool array = false;
    int size = 0;
    int startLine;
    int endLine;
    bool isLeaf;
    vector<SymbolInfo*> declaration_list;
    vector<SymbolInfo*> parameter_list;
    vector<SymbolInfo*> child_list;
    SymbolInfo *next;


public:
    SymbolInfo() {
        //cout<<" null constructor called";
        name = "";
        type = "";
        typeSpecifier="";
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

    string getTypeSpecifier(){
        return typeSpecifier;
    }
    void setTypeSpecifier(string typeSpecifier) {
        this->typeSpecifier = typeSpecifier;
    }
    void set_size( int x) {
        this->size = x;
    }
    int get_size(){
        return size;
    }

    void set_startLine( int x) {
        this->startLine = x;
    }
    int get_startLine(){
        return startLine;
    }

    void set_endLine( int x) {
        this->endLine = x;
    }
    int get_endLine(){
        return endLine;
    }

    void set_isLeaf( bool x) {
        this->isLeaf = x;
    }
    bool get_isLeaf(){
        return isLeaf;
    }



    void push_into_decList(SymbolInfo *s) {
        declaration_list.push_back(s);
    }
    void push_into_parameter_list(SymbolInfo *s) {
        parameter_list.push_back(s);
    }
     void push_into_childList(SymbolInfo *s) {
        child_list.push_back(s);
    }


    vector<SymbolInfo*> get_declaration_list(){
        return declaration_list;
    }
    void set_declaration_list(vector<SymbolInfo*> decList) {
        this->declaration_list = decList;
    }
    vector<SymbolInfo*> get_child_list(){
        return child_list;
    }
    void set_child_list(vector<SymbolInfo*> decList) {
        this->child_list = decList;
    }






    void set_isfunction_declaration(bool x){
        this->functionDeclaration=x;
    }
    void set_isarray(bool x){
        this->array=x;
    }
    void set_isfunction_defination(bool x){
        this->functionDefinition=x;
    }
    
    bool is_array(){
        return array;
    }
     bool is_function_declaration(){
        return functionDeclaration;
    }
     bool is_function_defination(){
        return functionDefinition;
    }







    void set_parameter_list(vector<SymbolInfo*> pmList) {
        this->parameter_list = pmList;
    }
    vector<SymbolInfo*> get_parameter_list(){
        return parameter_list;
    }
    void extend_name(string x ) {
        name=name+","+x;
    }void extend_before_name(string x ) {
        name=x+","+name;
    }



    void setLast(SymbolInfo *last) {
        SymbolInfo *temp=this;
        while(temp->next!=NULL){
            temp=temp->next;
        }
         temp->next=last;
    }

    void printAll(){
        SymbolInfo *temp=this;
        // while(temp->next!=NULL){
        //     cout<<" name "<<this->name<<"  type   "<< this->type<<"   \n";
        //     temp=temp->next;
        // }

    }

    ~SymbolInfo(){
        //cout<< "destructor called";
        //delete next;
    }

    
};
