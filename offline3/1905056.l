%option noyywrap
%x INSIDE_STRING

%{
    #include "y.tab.h"
	#include <bits/stdc++.h>
	#include "SymbolTable.h"
	// extern ofstream logOutput;
	// extern ofstream errorOutput;
	// extern YYSTYPE yylval;
	extern SymbolTable* symbolTable;
	extern int lineCount;
	extern int errorCount;

	extern ofstream lexOut;

%}



WHITESPACE [ \t\f\r\v]+
NEWLINE [\r]?\n

/*-------------------------- operators def start---------------*/
ADDOP [+-]
MULOP [*/%]
INCOP ("++")
DECOP ("--")
RELOP ("<"|"<="|">"|">="|"=="|"!=")
ASSIGNOP [=]
LOGICOP ("&&"|"||")
BITOP ("&"|"^"|"<<"|">>"|"|")
NOT [!]
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
{NEWLINE}		{lineCount++;}
"if"	{
	lexOut<<"get       if   \n";
	yylval.symbol_info = new SymbolInfo(yytext, "IF");
	yylval.symbol_info->setTypeSpecifier("IF : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
    return IF;
	}

"else"	{
	yylval.symbol_info = new SymbolInfo(yytext, "ELSE");
	yylval.symbol_info->setTypeSpecifier("ELSE : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       else   \n";
    return ELSE;
	}

"for"	{
	yylval.symbol_info = new SymbolInfo(yytext, "FOR");
	yylval.symbol_info->setTypeSpecifier("FOR : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       for   \n";
    return FOR;
	}

"while"	{
	yylval.symbol_info = new SymbolInfo(yytext, "WHILE");
	yylval.symbol_info->setTypeSpecifier("WHILE : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);			
	lexOut<<"get       while   \n";
	return WHILE;
	}

"do"	{
	yylval.symbol_info = new SymbolInfo(yytext, "DO");
	yylval.symbol_info->setTypeSpecifier("DO : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       do   \n";
    return DO;
	}

"break"	{
	yylval.symbol_info = new SymbolInfo(yytext, "BREAK");
	yylval.symbol_info->setTypeSpecifier("BREAK : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       break   \n";
    return BREAK;
	}

"int"	{
	yylval.symbol_info = new SymbolInfo(yytext, "INT");
	yylval.symbol_info->setTypeSpecifier("INT : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"got		 int\n";
    return INT;
	}
"char"	{
	yylval.symbol_info = new SymbolInfo(yytext, "CHAR");
	yylval.symbol_info->setTypeSpecifier("CHAR : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       char   \n";
    return CHAR;
	}

"float"	{
	yylval.symbol_info = new SymbolInfo(yytext, "FLOAT");
	yylval.symbol_info->setTypeSpecifier("FLOAT : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get		 float\n";
    return FLOAT;
	}

"double" {
	yylval.symbol_info = new SymbolInfo(yytext, "DOUBLE");
	yylval.symbol_info->setTypeSpecifier("DOUBLE : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       double   \n";
    return DOUBLE;
	}

"void"	{
	yylval.symbol_info = new SymbolInfo(yytext, "VOID");
	yylval.symbol_info->setTypeSpecifier("VOID : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       void   \n";
    return VOID;
	}

"return" {
	yylval.symbol_info = new SymbolInfo(yytext, "RETURN");
	yylval.symbol_info->setTypeSpecifier("RETURN : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       return   \n";
    return RETURN;
	}

"switch" {
	yylval.symbol_info = new SymbolInfo(yytext, "SWITCH");
	yylval.symbol_info->setTypeSpecifier("SWITCH : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       switch   \n";
    return SWITCH;
	}

"case"	{
	yylval.symbol_info = new SymbolInfo(yytext, "CASE");
	yylval.symbol_info->setTypeSpecifier("CASE : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       case   \n";
    return CASE;
	}

"default" {
	yylval.symbol_info = new SymbolInfo(yytext, "DEFAULT");
	yylval.symbol_info->setTypeSpecifier("DEFAULT : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       default   \n";
    return DEFAULT;
	}

"continue" {
	yylval.symbol_info = new SymbolInfo(yytext, "CONTINUE");
	yylval.symbol_info->setTypeSpecifier("CONTINUE : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       continue   \n";
    return CONTINUE;
	}

{ADDOP}     {
	yylval.symbol_info = new SymbolInfo(yytext, "ADDOP");
	yylval.symbol_info->setTypeSpecifier("ADDOP : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       ADDop \n"<<endl;
	return ADDOP;
    }
{MULOP}     {
	yylval.symbol_info = new SymbolInfo(yytext, "MULOP");
	yylval.symbol_info->setTypeSpecifier("MULOP : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       mul op   \n";
	return MULOP;
	}
{INCOP}     {
	yylval.symbol_info = new SymbolInfo(yytext, "INCOP");
	yylval.symbol_info->setTypeSpecifier("INCOP : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       inc op   \n";
	return INCOP;
    }
{DECOP}     {
	yylval.symbol_info = new SymbolInfo(yytext, "DECOP");
	yylval.symbol_info->setTypeSpecifier("INCOP : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       inc op   \n";
	return INCOP;
    }
{ASSIGNOP}     {
	yylval.symbol_info = new SymbolInfo(yytext, "ASSIGNOP");
	yylval.symbol_info->setTypeSpecifier("ASSIGNOP : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       assign op   \n";
	return ASSIGNOP;
    }
{LOGICOP}     { 
	yylval.symbol_info = new SymbolInfo(yytext, "LOGICOP");
	yylval.symbol_info->setTypeSpecifier("LOGICOP : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       logicop   \n";
	return LOGICOP;
    }
{BITOP}     {
	yylval.symbol_info = new SymbolInfo(yytext, "BITOP");
	yylval.symbol_info->setTypeSpecifier("BITOP : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       bitop   \n";
	return BITOP;
    }
{NOT}     {
	yylval.symbol_info = new SymbolInfo(yytext, "NOT");
	yylval.symbol_info->setTypeSpecifier("NOT : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true); 
	lexOut<<"get       nott   \n";
	return NOT;
    }
\( {
	yylval.symbol_info = new SymbolInfo(yytext, "LPAREN");
	yylval.symbol_info->setTypeSpecifier("LPAREN : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true); 		
	lexOut<<"get       l parenthesis   \n";
	return LPAREN;
    }
\) {
	yylval.symbol_info = new SymbolInfo(yytext, "RPAREN");
	yylval.symbol_info->setTypeSpecifier("RPAREN : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       r parenthesis   \n";
	return RPAREN;
    }
\{ {
	yylval.symbol_info = new SymbolInfo(yytext, "LCURL");
	yylval.symbol_info->setTypeSpecifier("LCURL : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       l curl \n";
	return LCURL;
    }
\} {
	yylval.symbol_info = new SymbolInfo(yytext, "RCURL");
	yylval.symbol_info->setTypeSpecifier("RCURL : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       r curl  \n";
	return RCURL;
    }
\[ {
	yylval.symbol_info = new SymbolInfo(yytext, "LTHIRD");
	yylval.symbol_info->setTypeSpecifier("LTHIRD : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       l square\n";
	 return LTHIRD;
    }
\] {
	yylval.symbol_info = new SymbolInfo(yytext, "RTHIRD");
	yylval.symbol_info->setTypeSpecifier("RTHIRD : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       r square\n";
	return RTHIRD;
    }
{COMMA}     {
	yylval.symbol_info = new SymbolInfo(yytext, "COMMA");
	yylval.symbol_info->setTypeSpecifier("COMMA : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       comma\n";
	return COMMA;
    }
{SEMICOLON}     {
	yylval.symbol_info = new SymbolInfo(yytext, "SEMICOLON");
	yylval.symbol_info->setTypeSpecifier("SEMICOLON : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       semicolon     \n";
	return SEMICOLON;
    }
{IDENTIFIER}    {
	yylval.symbol_info = new SymbolInfo(yytext, "ID");
	yylval.symbol_info->setTypeSpecifier("ID : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<" 		got identifier            "<< yytext<<endl;
    return ID;
    }
{DIGITS}    {
	yylval.symbol_info = new SymbolInfo(yytext, "INT");
	yylval.symbol_info->setTypeSpecifier("CONST_INT : ");	
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       Int const     "<<yytext<<"\n";
	return CONST_INT;
	}
{CONST_FLOAT}   {
    yylval.symbol_info =  new SymbolInfo(yytext, "FLOAT");
	yylval.symbol_info->setTypeSpecifier("CONST_FLOAT : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       float const     "<<yytext<<"\n";
	return CONST_FLOAT; 
	}
{CONST_CHAR}    {
	yylval.symbol_info = new SymbolInfo(yytext, "CHAR");
	yylval.symbol_info->setTypeSpecifier("CONST_CHAR : ");
	yylval.symbol_info->set_startLine(lineCount);	
	yylval.symbol_info->set_endLine(lineCount);
	yylval.symbol_info->set_isLeaf(true);
	lexOut<<"get       char const     "<<yytext<<"\n";
	return CONST_CHAR; 
	}
%%

// {STRING_BEGIN}  {
//                     multiString=0;
//                     str1="";
//                     str2="";
//                     BEGIN INSIDE_STRING;
//                 }
// <INSIDE_STRING>{SPECIAL_CHAR} {
// 	str1 += ConverChar(yytext);
// 	str2 += yytext;
// } 
// <INSIDE_STRING>\\\r\n {
//     multiString++;
// 	str2 += "\\\r\n";
// }

// <INSIDE_STRING>\\\n {
//     multiString++;
// 	str2 += "\\\r\n";
// }

// <INSIDE_STRING>[\r]?\n {
// 	error_count++;
//     str2 = "\"" + str2;
//     line_count+=multiString;
// 	fprintf(logout,"Error at line# %d: UNFINISHED_STRING %s\n", line_count,&*str2.begin());
//     line_count++;
// 	BEGIN INITIAL;
// }

// <INSIDE_STRING><<EOF>> {
// 	error_count++;
// 	fprintf(logout,"Error at line# %d: UNFINISHED_STRING %s\n", line_count,&*str2.begin());
// 	BEGIN INITIAL;
// }

// <INSIDE_STRING>\" {
// 	str2 = "\"" + str2 + "\"";
//     if(multiString>0){
// 	    fprintf(logout,"Line# %d: Token <MULTI LINE STRING> Lexeme %s found\n",line_count,&*str2.begin());
//         fprintf(tokenout,"<MULTI LINE STRING, %s>\n",&*str1.begin());
//     }
//     else{
//         fprintf(logout,"Line# %d: Token <SINGLE LINE STRING> Lexeme %s found\n",line_count,&*str2.begin()); 
//         fprintf(tokenout,"<SINGLE LINE STRING, %s>\n",&*str1.begin());
//     }
//     line_count+=multiString;
// 	BEGIN INITIAL;
// }

// <INSIDE_STRING>. {
// 	str1 += yytext[0];
// 	str2 += yytext[0];
// }



// {SINGLE_COMMENT}    {
//     fprintf(logout, "Line# %d: Token <SINGLE LINE COMMENT> Lexeme %s found\n", line_count, yytext);
//     for(int i=0; i<strlen(yytext); i++){
//         if(yytext[i]=='\n'){
//             line_count++;
//         }
//     }
// }

// {MULTI_COMMENT} {
//     fprintf(logout, "Line# %d: Token <MULTI LINE COMMENT> Lexeme %s found\n", line_count, yytext);
//     for(int i=0; i<strlen(yytext); i++){
//         if(yytext[i]=='\n'){
//             line_count++;
//         }
//     }
// }







// {DIGITS}(\.{DIGITS})\.[0-9\.Ee+-]* {
//     fprintf(logout,"Error at line# %d: TOO_MANY_DECIMAL_POINTS %s\n", line_count, yytext);
//     error_count++;
// }
// ({DIGIT}*(\.{DIGIT}*)?[Ee][+-]?{DIGIT}*(\.|[eE])+{DIGIT}*) {
// 	fprintf(logout,"Error at line# %d: ILLFORMED_NUMBER %s\n", line_count, yytext);
//     error_count++;
// }
// {DIGITS}{ALPHABET}+     {
//     fprintf(logout,"Error at line# %d: INVALID_ID_SUFFIX_NUM_PREFIX %s\n", line_count, yytext);
//     error_count++;
// }
// \'{ALPHANUMERIC}({ALPHANUMERIC}|\ )+\'    {
//     fprintf(logout,"Error at line# %d: MULTICHAR_CONST_CHAR %s\n", line_count, yytext);
//     error_count++;
// }
// \'\'  {
//     fprintf(logout,"Error at line# %d: EMPTY_CONST_CHAR ''\n", line_count);
//     error_count++;
// }

// \'(.|\\\')?[^\'\r\n]* {
    
//     fprintf(logout,"Error at line# %d: UNFINISHED_CONST_CHAR %s\n", line_count, yytext);
//     error_count++;
// }
// (\/\*)([^\*]|\*[^\/])* {
//       for(int i=0; i<strlen(yytext); i++){
//         if(yytext[i]=='\n'){
//             line_count++;
//         }
//     }
//     fprintf(logout,"Error at line# %d: UNFINISHED_COMMENT %s\n", line_count, yytext);
//     error_count++;
  
// }


// . {
//     fprintf(logout,"Error at line# %d: UNRECOGNIZED_CHAR %s\n", line_count, yytext);
//     error_count++;
// }