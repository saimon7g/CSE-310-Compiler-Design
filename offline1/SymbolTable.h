//
// Created by saimon7 on 11/29/22.
//

#ifndef OFFLINE1_SYMBOLTABLE_H
#define OFFLINE1_SYMBOLTABLE_H
#pragma once
#include <string>
#include <fstream>
#include"ScopeTable.h"
using namespace std;



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
#endif //OFFLINE1_SYMBOLTABLE_H