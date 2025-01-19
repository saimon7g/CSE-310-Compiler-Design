#include<bits/stdc++.h>
#include <string>
//#include <fstream>
//#include "SymbolInfo.h"
//#include "SymbolTable.h"
//#include "ScopeTable.h"
//#include <cstring>
//#include <iostream>
using namespace std;

int tokenizer(string str){
    stringstream check1(str);
    string intermediate;
    int i=0;
    getline(check1, intermediate, ' ');
    while(getline(check1, intermediate, ' '))
    {
        //cout<<intermediate<<endl;
        i++;
    }
    check1.clear();
    return i;
}
unsigned long long int SDBMHash(string str) {
    unsigned long long int hash = 0;
    unsigned long long int i = 0;
    unsigned long long int len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = ((str[i]) + (hash << 6) + (hash << 16) - hash);
    }

    return hash;
}

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
class ScopeTable {
private:
    SymbolInfo **hashTable;
    int bucketSize;
    ScopeTable *parent_scope;
    string id;
public:
    ScopeTable(int size, string id) {
        hashTable= new SymbolInfo*[size+1];
        for(int i=1;i<=size;i++){
            hashTable[i]= NULL;
        }
        bucketSize=size;
        parent_scope=NULL;
        this->id=id;
        cout<<"\tScopeTable# "<<id<<" created"<<endl;
    }

    bool insertSymbol(SymbolInfo *symbol) {
        unsigned long long int pos= (SDBMHash(symbol->getName())%bucketSize)+1;
        SymbolInfo *current=hashTable[pos];
        if(current==NULL){
            hashTable[pos]=symbol;
            cout<<"\t"<<"Inserted in ScopeTable# "<<id<<" at position "<<pos<<", 1"<<endl;

            //current=hashTable[pos];
            //cout<<"            its debugging in inseert "<<current->getName()<<"         "<<current->getType()<<endl;
            return true;
        }
        int count=2;
        while(current->getNext()!=NULL){
            if(current->getName()==symbol->getName()){
                cout<<"\t'"<<symbol->getName()<<"' already exists in the current ScopeTable"<<endl;
                return false;
            }
            count++;
            current=current->getNext();
        }
        if(current->getName()==symbol->getName()){
            cout<<"\t'"<<symbol->getName()<<"' already exists in the current ScopeTable"<<endl;
            return false;
        }
        current->setNext(symbol);
        cout<<"\t"<<"Inserted in ScopeTable# "<<id<<" at position "<<pos<<", "<<count<<endl;
        return true;
    }
    SymbolInfo *lookupSymbol(string symbol){
        unsigned long long int pos= (SDBMHash(symbol)%bucketSize)+1;
        //cout<<"SDBM hash                             "<<pos<<endl;
        SymbolInfo *current = hashTable[pos];
        if (current == NULL)
            return NULL;
        int cnt=1;
        while (current!= NULL) {
            string s1=symbol;
            string s2=current->getName();

            if (s1==s2){
                cout<<"\t'"<<symbol<<"' found in ScopeTable# "<<id<<" at position "<<pos<<", "<<cnt<<endl;
                return current;
            }
            cnt++;
            current = current->getNext();
        }
//            if (current->getName() == symbol){
//                cout<<"'"<<symbol<<"' found in ScopeTable# "<<id<<" at position "<<SDBMHash(symbol)<<", "<<cnt<<endl;
//                return current;
//            }
        return NULL;
    }
    SymbolInfo *lookupSymbolForRemove(string symbol){
        unsigned long long int pos= (SDBMHash(symbol)%bucketSize)+1;
        //cout<<"SDBM hash                             "<<pos<<endl;
        SymbolInfo *current = hashTable[pos];
        if (current == NULL)
            return NULL;
        int cnt=1;
        while (current!= NULL) {
            string s1=symbol;
            string s2=current->getName();
            int res=s1.compare(s2);
            if (res==0){
                cout<<"\tDeleted '"<<symbol<<"' from ScopeTable# "<<id<<" at position "<<pos<<", "<<cnt<<endl;
                cnt++;
                return current;
            }
            current = current->getNext();
        }
//            if (current->getName() == symbol){
//                cout<<"'"<<symbol<<"' found in ScopeTable# "<<id<<" at position "<<SDBMHash(symbol)<<", "<<cnt<<endl;
//                return current;
//            }
        return NULL;
    }
    bool deleteSymbol(SymbolInfo *symbol){
        if(symbol->getNext()==NULL){
            unsigned long long int pos= (SDBMHash(symbol->getName())%bucketSize)+1;
            SymbolInfo *currrent=hashTable[pos];
            if(currrent==symbol){
                hashTable[pos]=NULL;
                delete symbol;
                return true;
            }

            while(currrent->getNext()!=symbol){
                currrent=currrent->getNext();
            }
            currrent->setNext(NULL);
            delete symbol;
            return true;
        }
        symbol->setNext(symbol->getNext()->getNext());
        delete symbol;
        return true;
    }
    void printScopeTable() {
        cout<<"\tScopeTable# "<<id<<endl;
        for (int i=1;i<=bucketSize;i++){
            cout<<"\t"<< i <<"--> ";
            SymbolInfo *current= hashTable[i];
            while(current!=NULL){
                cout<<"<"<<current->getName()<<","<<current->getType()<<"> ";
                current=current->getNext();
            }
            cout<<endl;
        }
    }
    ~ScopeTable(){
        cout<<"\tScopeTable# "<<id<<" removed"<<endl;
        for (int i=1; i<=bucketSize; i++){
            delete hashTable[i];
        }
        delete[] hashTable;
    }

    int getTotalBuckets(){
        return bucketSize;
    }
    ScopeTable *getParentScope(){
        return parent_scope;

    }
    string getId(){
        return id;

    }
    void setParentScope(ScopeTable *parentScope){
        this->parent_scope=parentScope;
    }
};
class SymbolTable {
    ScopeTable *currentScope;
    int bucketSize;
    int id;
public:
    SymbolTable(int size) {
        this->bucketSize=size;
        id=1;
        currentScope=new ScopeTable(bucketSize, to_string(id));
        id++;
    }
    void EnterScope(){
        string newId= to_string(id);
        id++;
        ScopeTable *temp=new ScopeTable(bucketSize,newId);
        temp->setParentScope(currentScope);
        currentScope=temp;
        //cout<<"	ScopeTable# "<<currentScope->getId()<<" created"<<endl;
    }
    void ExitScope(){
        if(currentScope->getParentScope()!=NULL){
            //cout<<"                 exit scope if   "<<endl;
            ScopeTable *temp= currentScope;
            currentScope=currentScope->getParentScope();
            delete temp;
        }
        else
            cout<<"\tScopeTable# "<<currentScope->getId()<<" cannot be removed"<<endl;

    }
    bool InsertSymbol(string name,string type){
        SymbolInfo *tempSymbol= new SymbolInfo( name,type);
        return currentScope->insertSymbol(tempSymbol);
    }
    bool RemoveSymbol( string name){
        SymbolInfo *tempSymbol= currentScope->lookupSymbolForRemove(name);
        if(tempSymbol==NULL){
            cout<<"\tNot found in the current ScopeTable"<<endl;
            return false;
        }
        return currentScope->deleteSymbol(tempSymbol);
    }
    SymbolInfo *LookUpSymbol(string symbol){
        ScopeTable *tempScope=currentScope;
        //cout<<"             its just debugging              scope id                "<<tempScope->getId()<<endl;
        while (tempScope!=NULL){
            SymbolInfo *tempSymbol=tempScope->lookupSymbol(symbol);
            if(tempSymbol==NULL){
                tempScope=tempScope->getParentScope();
                //cout<<"7777777777";
            }
            else
                return tempSymbol;
            //cout<<"8888888888"<<endl;
        }
        if(tempScope==NULL){
            cout<<"\t'"<<symbol<<"' not found in any of the ScopeTables"<<endl;
        }
        return NULL;
    }
    void PrinrtCurrentScope(){
        currentScope->printScopeTable();
    }
    void PrinrtAllScope(){
        ScopeTable *tempScopeTable=currentScope;
        while(tempScopeTable!=NULL){
            tempScopeTable->printScopeTable();
            tempScopeTable=tempScopeTable->getParentScope();
        }
    }
    ScopeTable *getCurrentScope() const {
        return currentScope;
    }

    void setCurrentScope(ScopeTable *currentScope) {
        SymbolTable::currentScope = currentScope;
    }
};


int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
//    ifstream in("input.txt");
//    ofstream out("output.txt");
//    std::fstream out;
//    out.open ("output1.txt", std::fstream::out | std::fstream::app);
    int x,count=0;
    string instruction,str;
    cin>> x;
    SymbolTable table= SymbolTable(x);

//    cin>>instruction;
//    cout<<instruction<<endl;
//    cin>>str;
//    cout<<str<<endl;
//    cin>>input1;
//    cout<<input1<<endl;
//    cin>>input2;
//    cout<<input2<<endl;


//    cout<<"entering while"<<endl;


    while(true){
        count++;
        cin>>instruction;
        cout<<"Cmd "<<count<<": "<<instruction;

        if (instruction =="Q"){
            cout<<endl;
            ScopeTable *temp=table.getCurrentScope();

            while(temp->getParentScope()!=NULL){
                //cout<<"        xddddd                 "<<table.getCurrentScope()->getId()<<endl;
                table.ExitScope();
                temp=temp->getParentScope();

            }
            delete table.getCurrentScope();
            break;
        }
        if (instruction == "I") {
            getline(cin,str);
            cout<<str<<endl;
            int num= tokenizer(str);
            if(num==2){

                stringstream check1(str);
                string intermediate;
                getline(check1, intermediate, ' ');
                getline(check1, intermediate, ' ');
                string input1=intermediate;
                //cout<<" intermediate                 "<<input1;
                getline(check1, intermediate, ' ');
                string input2=intermediate;
                //cout<<" intermediate                 "<<input2;
                check1.clear();

                table.InsertSymbol(input1,input2);
            }
            else
                cout<<"\tNumber of parameters mismatch for the command "<<instruction<<endl;
            //cout<<"NUMMMMMMMMMMMMMMMMMMMMMMMMMMMM"<<num<<endl;

        }
        else if (instruction == "L") {

            getline(cin,str);
            cout<<str<<endl;
            int num= tokenizer(str);
            if(num==1){
                stringstream check1(str);
                string intermediate;
                getline(check1, intermediate, ' ');
                getline(check1, intermediate, ' ');
                string input1=intermediate;
                //cout<<" intermediate                 "<<input1;
                //getline(check1, intermediate, ' ');
                //string input2=intermediate;
                //cout<<" intermediate                 "<<input2;
                check1.clear();

                table.LookUpSymbol(input1);
            }
            else
                cout<<"\tNumber of parameters mismatch for the command "<<instruction<<endl;
        }
        else if (instruction == "D") {

            getline(cin,str);
            cout<<str<<endl;
            int num= tokenizer(str);
            if(num==1){
                stringstream check1(str);
                string intermediate;
                getline(check1, intermediate, ' ');
                getline(check1, intermediate, ' ');
                string input1=intermediate;
                //cout<<" intermediate                 "<<input1;
                //getline(check1, intermediate, ' ');
                //string input2=intermediate;
                //cout<<" intermediate                 "<<input2;
                check1.clear();

                table.RemoveSymbol(input1);
            }
            else
                cout<<"\tNumber of parameters mismatch for the  command "<<instruction<<endl;
        }
        else if (instruction == "P") {

            getline(cin,str);
            cout<<str<<endl;
            int num= tokenizer(str);
            if(num==1){
                stringstream check1(str);
                string intermediate;
                getline(check1, intermediate, ' ');
                getline(check1, intermediate, ' ');
                string input1=intermediate;
                //cout<<" intermediate                 "<<input1;
                //getline(check1, intermediate, ' ');
                //string input2=intermediate;
                //cout<<" intermediate                 "<<input2;
                check1.clear();
                if(input1=="A"){
                    table.PrinrtAllScope();
                }
                else if (input1=="C"){
                    table.PrinrtCurrentScope();
                }
            }
            else
                cout<<"\tNumber of parameters mismatch for the command "<<instruction<<endl;
        }
        else if (instruction == "S") {

            getline(cin,str);
            cout<<str<<endl;
            int num= tokenizer(str);
            if(num==0){
                stringstream check1(str);
                string intermediate;
                getline(check1, intermediate, ' ');
                //getline(check1, intermediate, ' ');
                //string input1=intermediate;
                //cout<<" intermediate                 "<<input1;
                //getline(check1, intermediate, ' ');
                //string input2=intermediate;
                //cout<<" intermediate                 "<<input2;
                check1.clear();

                table.EnterScope();
            }
            else
                cout<<"\tNumber of parameters mismatch for the command "<<instruction<<endl;
        }
        else if (instruction == "E") {

            getline(cin,str);
            cout<<str<<endl;
            int num= tokenizer(str);
            if(num==0){
                stringstream check1(str);
                string intermediate;
                getline(check1, intermediate, ' ');
                //getline(check1, intermediate, ' ');
                //string input1=intermediate;
                //cout<<" intermediate                 "<<input1;
                //getline(check1, intermediate, ' ');
                //string input2=intermediate;
                //cout<<" intermediate                 "<<input2;
                check1.clear();

                table.ExitScope();
            }
            else
                cout<<"\tNumber of parameters mismatch for the command "<<instruction<<endl;
        }
        else
            cout<<"Invalid Command"<<endl;
    }
    return 0;
}