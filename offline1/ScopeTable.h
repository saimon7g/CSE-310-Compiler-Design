//
// Created by saimon7 on 11/27/22.
//
#pragma once
#ifndef OFFLINE1_SCOPETABLE_H
#define OFFLINE1_SCOPETABLE_H
#include <string>
#include <fstream>
#include"SymbolInfo.h"
using namespace std;

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
        unsigned long long int pos= (SDBMHash(symbol->getName())%bucketSize)+1;
        SymbolInfo *currrent=hashTable[pos];
        if(symbol->getNext()==NULL){
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

        else if( symbol==hashTable[pos])
        {
            hashTable[pos]=hashTable[pos]->getNext();
            delete symbol;
            return true;
        }
        else{
            while(currrent->getNext()!=symbol) {
                currrent = currrent->getNext();
            }
            currrent->setNext(currrent->getNext()->getNext());
            delete symbol;
            return true;
        }

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


#endif //OFFLINE1_SCOPETABLE_H