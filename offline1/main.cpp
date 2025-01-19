#include<bits/stdc++.h>
#include <string>
#include <fstream>
#include "SymbolInfo.h"
#include "SymbolTable.h"
#include "ScopeTable.h"
#include <cstring>
#include <iostream>
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