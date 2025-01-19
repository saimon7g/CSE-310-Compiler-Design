%option noyywrap

%x INSIDE_STRING

%{
#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
// #include "SymbolInfo.h"
//#include "SymbolTable.cpp"
// #include "ScopeTable.h"


using namespace std;


int line_count=1;
int error_count = 0;
int multiString;
string str1 = "";
string str2 = "";
FILE *logout;
FILE *tokenout;



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
        //cout<<"\tScopeTable# "<<id<<" created"<<endl;
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
            //cout<<"\t"<<"Inserted in ScopeTable# "<<id<<" at position "<<pos<<", 1"<<endl;
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
    void printScopeTable(FILE *file) {
        //cout<<"\tScopeTable# "<<id<<endl;
        fprintf(file, "\tScopeTable# %s\n", const_cast<char*>(this->id.c_str()));
        for (int i=1;i<=bucketSize;i++){
            if(hashTable[i]!=NULL){
            //cout<<"\t"<< i <<"--> ";
            fprintf(file, "\t%d--> ", i);
            SymbolInfo *current= hashTable[i];
            while(current!=NULL){
                cout<<"<"<<current->getName()<<","<<current->getType()<<"> ";
                fprintf(file, "<%s,%s> ", const_cast<char*>(current->getName().c_str()), const_cast<char*>(current->getType().c_str()));
                current=current->getNext();
            }
            fprintf(file,"\n");
            }
        
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
        else{
            // cout<<"\tScopeTable# "<<currentScope->getId()<<" cannot be removed"<<endl;
        }
    }
    bool InsertSymbol(string name,string type){
        SymbolInfo *tempSymbol= new SymbolInfo(name,type);
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
    void PrinrtCurrentScope(FILE *file){
        currentScope->printScopeTable(file);
    }
    void PrinrtAllScope(FILE *file){
        ScopeTable *tempScopeTable=currentScope;
        while(tempScopeTable!=NULL){
            tempScopeTable->printScopeTable(file);
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


char ConverChar(char *ch){
        if(ch[0]=='\\'){
            if(ch[1] == 'n')
                return (char)10;
            else if(ch[1] == 't')
                return (char)9;
            else if(ch[1] == '\\')
                return (char)92;
            else if(ch[1] == '\'')
                return (char)39;
            else if(ch[1] == 'a')
                return (char)7;
            else if(ch[1] == 'f')
                return (char)12;
            else if(ch[1] == 'r')
                return (char)13;
            else if(ch[1] == 'b')
                return (char)8;
            else if(ch[1] == 'v')
                return (char)11;
            else if(ch[1] == '0')
                return (char)0;
            else if(ch[1] == '\"')
                return (char)34;
        }
         else if(ch[1] == '\\') {
            if(ch[2] == 'n')
                return (char)10;
            else if(ch[2] == 't')
                return (char)9;
            else if(ch[2] == '\\')
                return (char)92;
            else if(ch[2] == '\'')
                return (char)39;
            else if(ch[2] == 'a')
                return (char)7;
            else if(ch[2] == 'f')
                return (char)12;
            else if(ch[2] == 'r')
                return (char)13;
            else if(ch[2] == 'b')
                return (char)8;
            else if(ch[2] == 'v')
                return (char)11;
            else if(ch[2] == '0')
                return (char)0;
            else if(ch[2] == '\"')
                return (char)34;    
        }
        return (char)ch[1];
    }

SymbolTable *symbolTable=new SymbolTable(10);

%}

WHITESPACE [ \t\f\r\v]+
NEWLINE [\r]?\n

/*-------------------------- operators def start---------------*/
ADDOP [+-]
MULOP [*/%]
INCOP ("++"|"--")
RELOP ("<"|"<="|">"|">="|"=="|"!=")
ASSIGNOP [=]
LOGICOP ("&&"|"||")
BITOP ("&"|"^"|"<<"|">>"|"|")
NOT [!]
LPAREN [(]
RPAREN [)]
LCURL [{]
RCURL [}]
LSQUARE ("[")
RSQUARE ("]")
COMMA [,]
SEMICOLON [;]
/*------------------------------------------operators def end------------------------*/

DIGIT [0-9]
DIGITS {DIGIT}+
LETTER [a-zA-Z]
ALPHABET {LETTER}|_
ALPHANUMERIC {ALPHABET}|{DIGIT}
IDENTIFIER ({ALPHABET})+({ALPHANUMERIC}*)

CONST_FLOAT {DIGITS}?(\.{DIGITS})?([Ee][+-]?{DIGITS})?
SPECIAL_CHAR_IN_CHAR_CONST '(\\[nt\\afrbv0\'\"])'
CHAR '([ -~]{-}['\\])'
CONST_CHAR {SPECIAL_CHAR_IN_CHAR_CONST}|{CHAR}
SPECIAL_CHAR (\\[nt\\afrbv0\'\"])


STRING_BEGIN \"
SINGLE_COMMENT \/\/(([\\]+([\n])?)|([^\n])*)*
MULTI_COMMENT (\/\*)([^\*]|\*[^\/])*(\*\/)






%%

{WHITESPACE}    { }
{NEWLINE} {line_count++;}

"if"	{
			fprintf(tokenout,"<IF, if>\n");
			fprintf(logout,"Line# %d: Token <IF> Lexeme %s found\n",line_count,yytext);
		}
		
"else"	{
			fprintf(tokenout,"<ELSE, else>\n");
			fprintf(logout,"Line# %d: Token <ELSE> Lexeme %s found\n",line_count,yytext);
		}
"for"	{
			fprintf(tokenout,"<FOR, for>\n");
			fprintf(logout,"Line# %d: Token <FOR> Lexeme %s found\n",line_count,yytext);
		}

"while"	{
			fprintf(tokenout,"<WHILE, while>\n");
			fprintf(logout,"Line# %d: Token <WHILE> Lexeme %s found\n",line_count,yytext);
		}
"do"	{
			fprintf(tokenout,"<DO,do>\n");
			fprintf(logout,"Line# %d: Token <DO> Lexeme %s found\n",line_count,yytext);
		}

"break"	{
			fprintf(tokenout,"<BREAK, break>\n");
			fprintf(logout,"Line# %d: Token <BREAK> Lexeme %s found\n",line_count,yytext);
		}
"int"	{
			fprintf(tokenout,"<INT, int>\n");
			fprintf(logout,"Line# %d: Token <INT> Lexeme %s found\n",line_count,yytext);
		}

"char"	{
			fprintf(tokenout,"<CHAR, char>\n");
			fprintf(logout,"Line# %d: Token <CHAR> Lexeme %s found\n",line_count,yytext);
		}
"float"	{
			fprintf(tokenout,"<FLOAT, float>\n");
			fprintf(logout,"Line# %d: Token <FLOAT> Lexeme %s found\n",line_count,yytext);
		}

"double"	{
			fprintf(tokenout,"<DOUBLE, double>\n");
			fprintf(logout,"Line# %d: Token <DOUBLE> Lexeme %s found\n",line_count,yytext);
		}
"void"	{
			fprintf(tokenout,"<VOID, void>\n");
			fprintf(logout,"Line# %d: Token <VOID> Lexeme %s found\n",line_count,yytext);
		}

"return"	{
			fprintf(tokenout,"<RETURN, return>\n");
			fprintf(logout,"Line# %d: Token <RETURN> Lexeme %s found\n",line_count,yytext);
		}
"switch"	{
			fprintf(tokenout,"<SWITCH, switch>\n");
			fprintf(logout,"Line# %d: Token <SWITCH> Lexeme %s found\n",line_count,yytext);
		}

"case"	{
			fprintf(tokenout,"<CASE, case>\n");
			fprintf(logout,"Line# %d: Token <CASE> Lexeme %s found\n",line_count,yytext);
		}
"default"	{
			fprintf(tokenout,"<DEFAULT, default>\n");
			fprintf(logout,"Line# %d: Token <DEFAULT> Lexeme %s found\n",line_count,yytext);
		}

"continue"	{
			fprintf(tokenout,"<CONTINUE, continue>\n");
			fprintf(logout,"Line# %d: Token <CONTINUE> Lexeme %s found\n",line_count,yytext);
		}



{DIGITS}    {
				fprintf(tokenout,"<CONST_INT, %s>\n",yytext);
				fprintf(logout,"Line# %d: Token <CONST_INT> Lexeme %s found\n",line_count,yytext);
			}
{CONST_FLOAT}   {
                    fprintf(tokenout,"<CONST_FLOAT, %s>\n",yytext);
                    fprintf(logout,"Line# %d: Token <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
                }
{CONST_CHAR}    {
                    fprintf(tokenout,"<CONST_CHAR, %c>\n",ConverChar(yytext));
                    fprintf(logout,"Line# %d: Token <CONST_CHAR> Lexeme %c found\n",line_count,ConverChar(yytext));
                }



{ADDOP}     {
                fprintf(tokenout,"<ADDOP, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <ADDOP> Lexeme %s found\n",line_count,yytext);
            }
{MULOP}     {
                fprintf(tokenout,"<MULOP, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <MULOP> Lexeme %s found\n",line_count,yytext);
            }
{INCOP}     {
                fprintf(tokenout,"<INCOP, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <INCOP> Lexeme %s found\n",line_count,yytext);
            }
{RELOP}     {
                fprintf(tokenout,"<RELOP, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <RELOP> Lexeme %s found\n",line_count,yytext);
            }
{ASSIGNOP}     {
                fprintf(tokenout,"<ASSIGNOP, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
            }
{LOGICOP}     {
                fprintf(tokenout,"<LOGICOP, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <LOGICOP> Lexeme %s found\n",line_count,yytext);
            }
{BITOP}     {
                fprintf(tokenout,"<BITOP, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <BITOP> Lexeme %s found\n",line_count,yytext);
            }
{NOT}     {
                fprintf(tokenout,"<NOT, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <NOT> Lexeme %s found\n",line_count,yytext);
          }
{LPAREN}     {
                fprintf(tokenout,"<LPAREN, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <LPAREN> Lexeme %s found\n",line_count,yytext);
             }
{RPAREN}     {
                fprintf(tokenout,"<RPAREN, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <RPAREN> Lexeme %s found\n",line_count,yytext);
             }
{LCURL}     {
                fprintf(tokenout,"<LCURL, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <LCURL> Lexeme %s found\n",line_count,yytext);
                symbolTable->EnterScope();
            }
{RCURL}     {
                fprintf(tokenout,"<RCURL, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <RCURL> Lexeme %s found\n",line_count,yytext);
                symbolTable->ExitScope();
            }
{LSQUARE}     {
                fprintf(tokenout,"<LSQUARE, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <LSQUARE> Lexeme %s found\n",line_count,yytext);
              }
{RSQUARE}     {
                fprintf(tokenout,"<RSQUARE, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <RSQUARE> Lexeme %s found\n",line_count,yytext);
              }
{COMMA}     {
                fprintf(tokenout,"<COMMA, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <COMMA> Lexeme %s found\n",line_count,yytext);
            }
{SEMICOLON}     {
                fprintf(tokenout,"<SEMICOLON, %s>\n",yytext);
                fprintf(logout,"Line# %d: Token <SEMICOLON> Lexeme %s found\n",line_count,yytext);
                }


{IDENTIFIER}    {
                    fprintf(tokenout,"<ID, %s>\n",yytext);
                    fprintf(logout,"Line# %d: Token <ID> Lexeme %s found\n",line_count,yytext);
                    bool result = symbolTable->InsertSymbol(yytext,"ID");
                    if (!result) {
                        fprintf(logout,"\t%s already exisits in the current ScopeTable\n",yytext);
                    }else
                        symbolTable->PrinrtAllScope(logout);
                }


{STRING_BEGIN}  {
                    multiString=0;
                    str1="";
                    str2="";
                    BEGIN INSIDE_STRING;
                }
<INSIDE_STRING>{SPECIAL_CHAR} {
	str1 += ConverChar(yytext);
	str2 += yytext;
} 
<INSIDE_STRING>\\\r\n {
    multiString++;
	str2 += "\\\r\n";
}

<INSIDE_STRING>\\\n {
    multiString++;
	str2 += "\\\r\n";
}

<INSIDE_STRING>[\r]?\n {
	error_count++;
    str2 = "\"" + str2;
    line_count+=multiString;
	fprintf(logout,"Error at line# %d: UNFINISHED_STRING %s\n", line_count,&*str2.begin());
    line_count++;
	BEGIN INITIAL;
}

<INSIDE_STRING><<EOF>> {
	error_count++;
	fprintf(logout,"Error at line# %d: UNFINISHED_STRING %s\n", line_count,&*str2.begin());
	BEGIN INITIAL;
}

<INSIDE_STRING>\" {
	str2 = "\"" + str2 + "\"";
    if(multiString>0){
	    fprintf(logout,"Line# %d: Token <MULTI LINE STRING> Lexeme %s found\n",line_count,&*str2.begin());
        fprintf(tokenout,"<MULTI LINE STRING, %s>\n",&*str1.begin());
    }
    else{
        fprintf(logout,"Line# %d: Token <SINGLE LINE STRING> Lexeme %s found\n",line_count,&*str2.begin()); 
        fprintf(tokenout,"<SINGLE LINE STRING, %s>\n",&*str1.begin());
    }
    line_count+=multiString;
	BEGIN INITIAL;
}

<INSIDE_STRING>. {
	str1 += yytext[0];
	str2 += yytext[0];
}



{SINGLE_COMMENT}    {
    fprintf(logout, "Line# %d: Token <SINGLE LINE COMMENT> Lexeme %s found\n", line_count, yytext);
    for(int i=0; i<strlen(yytext); i++){
        if(yytext[i]=='\n'){
            line_count++;
        }
    }
}

{MULTI_COMMENT} {
    fprintf(logout, "Line# %d: Token <MULTI LINE COMMENT> Lexeme %s found\n", line_count, yytext);
    for(int i=0; i<strlen(yytext); i++){
        if(yytext[i]=='\n'){
            line_count++;
        }
    }
}







{DIGITS}(\.{DIGITS})\.[0-9\.Ee+-]* {
    fprintf(logout,"Error at line# %d: TOO_MANY_DECIMAL_POINTS %s\n", line_count, yytext);
    error_count++;
}
({DIGIT}*(\.{DIGIT}*)?[Ee][+-]?{DIGIT}*(\.|[eE])+{DIGIT}*) {
	fprintf(logout,"Error at line# %d: ILLFORMED_NUMBER %s\n", line_count, yytext);
    error_count++;
}
{DIGITS}{ALPHABET}+     {
    fprintf(logout,"Error at line# %d: INVALID_ID_SUFFIX_NUM_PREFIX %s\n", line_count, yytext);
    error_count++;
}
\'{ALPHANUMERIC}({ALPHANUMERIC}|\ )+\'    {
    fprintf(logout,"Error at line# %d: MULTICHAR_CONST_CHAR %s\n", line_count, yytext);
    error_count++;
}
\'\'  {
    fprintf(logout,"Error at line# %d: EMPTY_CONST_CHAR ''\n", line_count);
    error_count++;
}

\'(.|\\\')?[^\'\r\n]* {
    
    fprintf(logout,"Error at line# %d: UNFINISHED_CONST_CHAR %s\n", line_count, yytext);
    error_count++;
}
(\/\*)([^\*]|\*[^\/])* {
      for(int i=0; i<strlen(yytext); i++){
        if(yytext[i]=='\n'){
            line_count++;
        }
    }
    fprintf(logout,"Error at line# %d: UNFINISHED_COMMENT %s\n", line_count, yytext);
    error_count++;
  
}


. {
    fprintf(logout,"Error at line# %d: UNRECOGNIZED_CHAR %s\n", line_count, yytext);
    error_count++;
}


%%


int main(int argc, char** argv) {
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("1905056_log.txt","w");
	tokenout= fopen("1905056_token.txt","w");

	yyin= fin;
	yylex();

	symbolTable->PrinrtAllScope(logout);
    fprintf(logout,"Total lines: %d\n",line_count) ;
    fprintf(logout,"Total errors: %d\n",error_count) ;

	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}