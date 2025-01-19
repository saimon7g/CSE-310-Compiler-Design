%{
	#include <bits/stdc++.h>
    #include<vector>
	#include "SymbolTable.h"
    #include "SymbolInfo.h"
	#include "Parameter.h"


    using namespace std;

    // external function and variable declarations
	int yylex();
	int yyparse(void);
	void yyerror(char *s);
	void defineFunction(SymbolInfo*,SymbolInfo*,SymbolInfo*);
	string callFunction(SymbolInfo*,SymbolInfo*);
	void declare_fun_variables();
	void print_parse_tree(SymbolInfo*,int);
	bool voidCheck(SymbolInfo*);
	bool errortype_Check(SymbolInfo*);

    

    extern FILE *yyin;
	ofstream errorOutput;
    ofstream logOutput;
    ofstream lexOut;
    ofstream yOut;
	ofstream parse_tree_output;
	extern int errorCount = 0;
	extern int lineCount=1;
	vector<SymbolInfo*> fun_parameter_list;


	SymbolTable *symbolTable=new SymbolTable(11);



%}


%union{
    class SymbolInfo* symbol_info;
}


%token<symbol_info> IF ELSE FOR WHILE DO BREAK VOID RETURN SWITCH CASE DEFAULT CONTINUE INCOP DECOP ASSIGNOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token <symbol_info> CONST_INT CONST_FLOAT CONST_CHAR ID INT CHAR FLOAT DOUBLE ADDOP MULOP BITOP RELOP LOGICOP PRINTLN
%type<symbol_info> start program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement variable expression logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start start



%%
start : program {
	$$ = new SymbolInfo("program unit","");
	$$->setTypeSpecifier("start : program");

	$$->set_startLine($1->get_startLine());
	$$->set_endLine($1->get_endLine());
	$$->set_isLeaf(false);
	$$->push_into_childList($1);
	
	yOut<<"		inside				start:program		\n"<<endl;

	
	symbolTable->PrinrtAllScope(logOutput); 
	symbolTable->ExitScope();
	cout << "Total Lines: " << lineCount << endl;
	cout << "Total Errors: " << errorCount << endl;
	print_parse_tree($$,0);
	}
	;
//---------------------------------------------------------------program=====================================
program : program unit {
	$$ = new SymbolInfo("program unit","");
	$$->setTypeSpecifier("program : program unit");

	$$->set_startLine($1->get_startLine());
	$$->set_endLine($2->get_endLine());
	$$->set_isLeaf(false);
	$$->push_into_childList($1);
	$$->push_into_childList($2);


	yOut<<"		inside      			program :   program unit		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| unit {
		$$ = new SymbolInfo("unit","");
		$$->setTypeSpecifier("program :  unit");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"		inside      			program : unit		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//---------------------------------------------------------------unit=====================================done
unit : var_declaration {
		$$ = new SymbolInfo("var_declaration","");
		$$->setTypeSpecifier("unit : var_declaration");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"		inside      		unit : var_declaration		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
    | func_declaration {
		$$ = new SymbolInfo("func_declaration","");
		$$->setTypeSpecifier("unit : func_declaration");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"		inside      		unit : 		func_declaration   "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
    | func_definition {
		$$ = new SymbolInfo("func_definition","");
		$$->setTypeSpecifier("unit : func_definition");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"		inside      		unit : 		func_declaration   "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
    ;
//---------------------------------------------------------------func_declaration=====================================done
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {

		$$ = new SymbolInfo("type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",$1->getType());
		$$->set_isfunction_declaration(true);
		$$->setTypeSpecifier("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		$$->set_parameter_list($4->get_parameter_list());
		bool in_inserted=symbolTable->InsertSymbol($2->getName(),$1->getType());
        	if(!in_inserted){
                yOut<<" Not Inserted in sumbolTable   due to multiple dec  "<<endl;
            }

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($6->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($5);
		$$->push_into_childList($6);

		yOut<<"inside			func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| type_specifier ID LPAREN RPAREN SEMICOLON {
		// type id ()
		$$ = new SymbolInfo("type_specifier ID LPAREN RPAREN SEMICOLON",$1->getType());
		$$->set_isfunction_declaration(true);
		$$->setTypeSpecifier("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		bool in_inserted=symbolTable->InsertSymbol($2->getName(),$1->getType());
        	if(!in_inserted){
                yOut<<" Not Inserted in sumbolTable   due to multiple dec  "<<endl;
            }
$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($5->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($5);

		yOut<<"inside			func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//---------------------------------------------------------------func_definition=====================================done
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
    defineFunction($1,$2,$4 );
	fun_parameter_list=$4->get_parameter_list();
	}
	 compound_statement 
	{
			cout<<"--================================================--------"<<endl;
		$$ = new SymbolInfo($2->getName(),$1->getType());
		$$->setTypeSpecifier("func_definition : type_specifier ID LPAREN parameter_list RPAREN");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($7->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($5);
		$$->push_into_childList($7);

		yOut<<"func_definition : type_specifier ID LPAREN parameter_list RPAREN { } compound_statement		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| type_specifier ID LPAREN RPAREN {
		SymbolInfo *temp= new SymbolInfo("","");
		defineFunction($1,$2,temp);
		}
		compound_statement 
		{
		$$ = new SymbolInfo($2->getName(),$1->getType());
		$$->setTypeSpecifier("func_definition : type_specifier ID LPAREN RPAREN");


		$$->set_startLine($1->get_startLine());
		$$->set_endLine($6->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($6);

		yOut<<"insidw		func_definition : type_specifier ID LPAREN RPAREN { } compound_statement	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;				
//---------------------------------------------------------------parameter_list=====================================done
parameter_list : parameter_list COMMA type_specifier ID { // void fun(int a, in b);
		$$ = new SymbolInfo("parameter_list COMMA type_specifier ID",$1->getType());
		$$->setTypeSpecifier("parameter_list : parameter_list COMMA type_specifier ID");
		$$->set_parameter_list($1->get_parameter_list());

		SymbolInfo *temp = new SymbolInfo($4->getName(),$3->getType());
		temp->setTypeSpecifier("Parameter");
		$$->push_into_parameter_list(temp);
		
		$$->set_startLine($1->get_startLine());
		$$->set_endLine($4->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);

		yOut<<"inside			parameter_list :parameter_list COMMA type_specifier  ID   "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| parameter_list COMMA type_specifier { // void fun(int, float)
		$$ = new SymbolInfo("type_specifier ID",$1->getType());
		$$->setTypeSpecifier("parameter_list : parameter_list COMMA type_specifier");
		$$->set_parameter_list($1->get_parameter_list());
		SymbolInfo *temp = new SymbolInfo("",$3->getType());
		temp->setTypeSpecifier("Parameter");
		$$->push_into_parameter_list(temp);

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

		yOut<<"inside			parameter_list : parameter_list COMMA type_specifier     "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;

	}
	| type_specifier ID { // void fun(int a)

		$$ = new SymbolInfo("type_specifier ID",$1->getType());
		$$->setTypeSpecifier("parameter_list");
		SymbolInfo *temp = new SymbolInfo($2->getName(),$1->getType());
		temp->setTypeSpecifier("Parameter");
		$$->push_into_parameter_list(temp);
		
		$$->set_startLine($1->get_startLine());
		$$->set_endLine($2->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);

		yOut<<"inside			parameter_list : type_specifier  ID   "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| type_specifier {
		// void fun(int);
		$$ = new SymbolInfo($1->getType(),"");
		$$->setTypeSpecifier("parameter_list");
		SymbolInfo *temp = new SymbolInfo("",$1->getType());
		temp->setTypeSpecifier("Parameter");
		$$->push_into_parameter_list(temp);


		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"inside			parameter_list : type_specifier     "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//---------------------------------------------------------------compound_statement=====================================done
compound_statement : LCURL {
	symbolTable->EnterScope();
	declare_fun_variables();
	yOut<<"					into compound statemnent		"<<endl;
	} 
	statements RCURL 
	{

		symbolTable->PrinrtCurrentScope(logOutput);
		symbolTable->ExitScope();

		$$ = new SymbolInfo("LCURL","");
		$$->setTypeSpecifier("compound_statement : LCURL statements RCURL");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($4->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($3);
		$$->push_into_childList($4);

		yOut<<"inside			compound_statement : LCURL statements RCURL "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;

	}
	| LCURL {
		symbolTable->EnterScope(); 
		} 
		RCURL 
		{
		symbolTable->PrinrtCurrentScope(logOutput);
		symbolTable->ExitScope();

		$$ = new SymbolInfo("LCURL","");
		$$->setTypeSpecifier("compound_statement : LCURL RCURL");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($3);
		yOut<<"inside			compound_statement : LCURL RCURL "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;

	}
	;
//---------------------------------------------------------------vaar_declaration=====================================done
var_declaration : type_specifier declaration_list SEMICOLON {

            $$ = new SymbolInfo($2->getName(),$1->getType());
			$$->setTypeSpecifier("var_declaration : type_specifier declaration_list SEMICOLON");
            if($1->getType() == "void"){
				logOutput<<"Variable type cannot be void";
			}
			vector<SymbolInfo*> temp_parameter_list=$2->get_declaration_list();
            for(int i=0;i<temp_parameter_list.size();i++){
                bool in_inserted=symbolTable->InsertSymbol(temp_parameter_list[i]->getName(),$1->getType());
                if(!in_inserted){
                    yOut<<" Not Inserted in sumbolTable due to multiple declaration    "<<endl;
                }
            }


		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

		yOut<<"		 inside      var_declaration : type_specifier declaration_list SEMICOLON      "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//---------------------------------------------------------------type_specifier=====================================done
type_specifier	: INT {
		$$ = new SymbolInfo("INT", "int");
		$$->setTypeSpecifier("type_specifier	: INT");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"		inside type_spec: INT       got<<<<<<INT "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
		}
	| FLOAT {

        $$ = new SymbolInfo("FLOAT", "float");
		$$->setTypeSpecifier("type_specifier");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"		inside type_spec: fkoat          got<<<<<<<<<<<<float "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| VOID {
        $$ = new SymbolInfo("VOID", "void");
		$$->setTypeSpecifier("type_specifier");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"		inside type_spec: void          got<<<<<<<<<void    "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//---------------------------------------------------------------declaration_list=====================================done
declaration_list : declaration_list COMMA ID {
		$$ = new SymbolInfo("declaration_list COMMA ID","");
		$$->setTypeSpecifier("declaration_list : declaration_list COMMA ID");

		$$->set_declaration_list($1->get_declaration_list());
		$$->push_into_decList($3);

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

        yOut<<"		inside      declaarationlist: decl comma id    "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
		$$ = new SymbolInfo("declaration_list COMMA ID LTHIRD CONST_INT RTHIRD","");
		$$->setTypeSpecifier("declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
		$$->set_declaration_list($1->get_declaration_list());

		$3->set_isarray(true);
		string str=$5->getName();
		int x = stoi(str);
		$3->set_size(x);
		$$->push_into_decList($3);

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($6->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($5);
		$$->push_into_childList($6);

		yOut<<"		inside      declist: ID LTHIRD CONST_INT RTHIRD    "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| ID {
		// create list for the first symbol
			$$ = new SymbolInfo("ID","");
			$$->setTypeSpecifier("declaration_list: ID");
			$$->push_into_decList($1);


			$$->set_startLine($1->get_startLine());
			$$->set_endLine($1->get_endLine());
			$$->set_isLeaf(false);
			$$->push_into_childList($1);

			yOut<<"		inside      declist: ID    "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	// for array declaration
	// for first declaration
	| ID LTHIRD CONST_INT RTHIRD {
		$$ = new SymbolInfo("ID LTHIRD CONST_INT RTHIRD","");
		$$->setTypeSpecifier("declaration_list: ID LTHIRD CONST_INT RTHIRD");

		$1->set_isarray(true);
		string str=$3->getName();
		int x = stoi(str);
		$1->set_size(x);
		$$->push_into_decList($1);

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($4->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);

		yOut<<"		inside      declist: ID LTHIRD CONST_INT RTHIRD    "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//---------------------------------------------------------------statements    =====================================not yet
statements : statement {
		$$ = new SymbolInfo("statement",$1->getType());
		$$->setTypeSpecifier("statements : statement");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"		inside      statements : statement    "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| statements statement {
		$$ = new SymbolInfo("statement",$1->getType());
		$$->setTypeSpecifier("statements : statements statement");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($2->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);

		yOut<<"		inside      statements : statements statement     "<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//----------------------------------------------------------------statement=======================================================================done
statement : var_declaration {
		$$ = new SymbolInfo("var_declaration",$1->getType());
		$$->setTypeSpecifier("statement : var_declaration");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"inside			statement: var_declaration  		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}	 
	| expression_statement {
		$$ = new SymbolInfo("expression_statement",$1->getType());
		$$->setTypeSpecifier("statement : expression_statement");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"inside			statement: expression_statement  		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| compound_statement {
		$$ = new SymbolInfo("compound_statement",$1->getType());
		$$->setTypeSpecifier("statement : compound_statement");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"inside			statement: compound_statement   		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| FOR LPAREN expression_statement expression_statement expression RPAREN statement {
		$$ = new SymbolInfo("FOR LPAREN expression_statement expression_statement expression RPAREN statement",$1->getType());
		$$->setTypeSpecifier("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($7->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($5);
		$$->push_into_childList($6);
		$$->push_into_childList($7);

		yOut<<"inside			statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement    		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
		$$ = new SymbolInfo("IF LPAREN expression RPAREN statement","int");
		$$->setTypeSpecifier("statement: IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($5->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($5);

		yOut<<"inside			statement: IF LPAREN expression RPAREN statement    		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	} 
	| IF LPAREN expression RPAREN statement ELSE statement {
		$$ = new SymbolInfo("IF LPAREN expression RPAREN statement ELSE statement","int");
		$$->setTypeSpecifier("statement : IF LPAREN expression RPAREN statement ELSE statement");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($7->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($5);
		$$->push_into_childList($6);
		$$->push_into_childList($7);

		yOut<<"inside			statement: IF LPAREN expression RPAREN statement ELSE statement    		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| WHILE LPAREN expression RPAREN statement {
		$$ = new SymbolInfo("WHILE LPAREN expression RPAREN statement","int");
		$$->setTypeSpecifier("statement : WHILE LPAREN expression RPAREN statement");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($5->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($5);


		yOut<<"inside			statement: WHILE LPAREN expression RPAREN statement		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
		if(symbolTable->LookUpSymbol($3->getName())==NULL){
			errorOutput<<" Undeclared value print attempt"<<endl;
		}
		$$ = new SymbolInfo("PRINTLN LPAREN ID RPAREN SEMICOLON","int");
		$$->setTypeSpecifier("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($5->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);
		$$->push_into_childList($5);

		yOut<<"inside			statement: PRINTLN LPAREN ID RPAREN SEMICOLON    		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| RETURN expression SEMICOLON {
		$$ = new SymbolInfo("RETURN expression SEMICOLON",$2->getTypeSpecifier());
		$$->setTypeSpecifier("statement : RETURN expression SEMICOLON");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

		yOut<<"inside			statement: RETURN expression SEMICOLON    		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//---------------------------------------------------------------expression =====================================yesssssssssss
expression_statement : SEMICOLON {
		$$ = new SymbolInfo("SEMICOLON","void");
		$$->setTypeSpecifier("expression_statement : SEMICOLON");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"inside			expression_statement : SEMICOLON    		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;

	}			
	| expression SEMICOLON {
		$$ = new SymbolInfo("expression SEMICOLON",$1->getType());
		$$->setTypeSpecifier("expression_statement : expression SEMICOLON");

		if(voidCheck($1) ){
		errorOutput<<"Void function used in expression_statement"<<endl;
		}
		else if(errortype_Check($1) ){
		errorOutput<<"error  function used in expression_statement"<<endl;
		}

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($2->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);

		yOut<<"inside			expression_statement : expression SEMICOLON   		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;

//---------------------------------------------------------------variable=====================================done
variable : ID { 
	$$ = new SymbolInfo($1->getName(),"");
	$$->setTypeSpecifier("variable");
	SymbolInfo *temp = symbolTable->LookUpSymbol($1->getName());
	if(temp==NULL){
		yOut<<" variable not NOT Declared"<<endl;
	}
	else{
		if(temp->is_array()){
				errorOutput<<"Type mismatch, "<<temp->getName()<<" is an array"<<endl;
			}
		else{
			$$->set_isarray(false);
		}
	}
    yOut<<"inside			variable: ID   		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| ID LTHIRD expression RTHIRD {
		$$ = new SymbolInfo($1->getName(),"");
		$$->setTypeSpecifier("variable");
		SymbolInfo *temp = symbolTable->LookUpSymbol($1->getName());
		if(temp==NULL){
			yOut<<" variable not NOT Declared"<<endl;
		}
		else{
			if(temp->is_array()){
				if($3->getType()=="int"){
				$$->set_isarray(true);
				}
			else{
				errorOutput<<"Type mismatch, "<<temp->getName()<<" is not an array"<<endl;
			}
			}
		}

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

	yOut<<"inside			variable: ID LTHIRD expression RTHIRD  		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//====================================================================expression---------------------------------------yesssss
expression : logic_expression {
	$$ = new SymbolInfo("logic_expression", "int");
	$$->setTypeSpecifier("expression : logic_expression");

	if(voidCheck($1) ){
		errorOutput<<"Void function used in logic_expression"<<endl;
		}
		else if(errortype_Check($1) ){
		errorOutput<<"error  function used in logic_expression"<<endl;
		}



	$$->set_startLine($1->get_startLine());
	$$->set_endLine($1->get_endLine());
	$$->set_isLeaf(false);
	$$->push_into_childList($1);

	yOut<<"inside			expression : logic_expression		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}

	| variable ASSIGNOP logic_expression {
		SymbolInfo *temp=symbolTable->LookUpSymbol($1->getName());
		$$ = new SymbolInfo("variable ASSIGNOP logic_expression", "");
		$$->setTypeSpecifier("expression : variable ASSIGNOP logic_expression");
		if(temp==NULL){
			errorOutput<<" variable not declared"<<endl;
			$$->setType("error");
		}
		else{
			$$->setType(temp->getType());
			if(temp->getType()!=$3->getType()){
				errorOutput<<"assignment operation type mis match"<<endl;//---------------------------------
				$$->setType("error");

			}
		}


		if(voidCheck($1) || voidCheck$3 ){
		errorOutput<<"Void function used in logic_expression"<<endl;
		}
		else if(errortype_Check($1) || voidCheck$3 ){
		errorOutput<<"error  function used in logic_expression"<<endl;
		}

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

		yOut<<"inside			expression : variable ASSIGNOP logic_expression		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}	
	;
//------------------------------------------------------------------------------------logic expression=================================================yesssssssssssss
logic_expression : rel_expression { 
	$$ = new SymbolInfo("rel_expression", "int");
	$$->setTypeSpecifier("logic_expression : rel_expression");

	if(voidCheck($1) ){
		errorOutput<<"Void function used in logic_expression"<<endl;
		}
		else if(errortype_Check($1) ){
		errorOutput<<"error  function used in logic_expression"<<endl;
		}

	

	$$->set_startLine($1->get_startLine());
	$$->set_endLine($1->get_endLine());
	$$->set_isLeaf(false);
	$$->push_into_childList($1);

	yOut<<"inside			logic_expression : rel_expression		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}	
	| rel_expression LOGICOP rel_expression {
		$$ = new SymbolInfo("rel_expression LOGICOP rel_expression", "int");
		$$->setTypeSpecifier("logic_expression : rel_expression LOGICOP rel_expression");

		if(voidCheck($1) || voidCheck$3 ){
		errorOutput<<"Void function used in logic_expression"<<endl;
		}
		else if(errortype_Check($1) || voidCheck$3 ){
		errorOutput<<"error  function used in logic_expression"<<endl;
		}



		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

		yOut<<"inside			logic_expression : rel_expression		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}	
	;
//====================================================================   rel   expression-----------------------------------------------------yessssssssssss
rel_expression : simple_expression {
	$$ = new SymbolInfo("simple_expression", "int");
	$$->setTypeSpecifier("rel_expression : simple_expression");

	if(voidCheck($1) ){
		errorOutput<<"Void function used in rel_expression"<<endl;
		}
		else if(errortype_Check($1) ){
		errorOutput<<"error  function used in rel_expression"<<endl;
		}

	

	$$->set_startLine($1->get_startLine());
	$$->set_endLine($1->get_endLine());
	$$->set_isLeaf(false);
	$$->push_into_childList($1);

	yOut<<"inside			rel_expression : simple_expression		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| simple_expression RELOP simple_expression	{
		$$ = new SymbolInfo("simple_expression RELOP simple_expression", "int");
		$$->setTypeSpecifier("rel_expression : simple_expression RELOP simple_expression");

		if(voidCheck($1) || voidCheck$3 ){
		errorOutput<<"Void function used in rel_expression"<<endl;
		}
		else if(errortype_Check($1) || voidCheck$3 ){
		errorOutput<<"error  function used in rel_expression"<<endl;
		}


		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

		yOut<<"indside			rel_expression : simple_expression RELOP simple_expressio		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
//----------------------------------------------------------------------------simple expression======================================yesss
simple_expression : term {
	$$ = new SymbolInfo("term", $1->getType());
	$$->setTypeSpecifier("simple_expression : term");

	if(voidCheck($1) ){
		errorOutput<<"Void function used in simple_expression"<<endl;
		}
		else if(errortype_Check($1) ){
		errorOutput<<"error  function used in simple_expression"<<endl;
		}

	$$->set_startLine($1->get_startLine());
	$$->set_endLine($1->get_endLine());
	$$->set_isLeaf(false);
	$$->push_into_childList($1);
	
	yOut<<"inside			simple_expression : term		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}	
	| simple_expression ADDOP term {
	$$ = new SymbolInfo("simple_expression ADDOP term", $1->getType());
	$$->setTypeSpecifier("simple_expression : simple_expression ADDOP term");
	if(voidCheck($1) ||  voidCheck($3)){
		errorOutput<<"Void function used in simple_expression"<<endl;
		}
		else if(errortype_Check($1) || voidCheck($3)){
		errorOutput<<"error  function used in simple_expression"<<endl;
		}

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

	yOut<<"inside			simple_expression : simple_expression ADDOP term		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	} 
	;
//===================================================================================unary expression-------------------------------------------yesssssssssssss
term :	unary_expression {
	$$ = new SymbolInfo("unary_expression", $1->getType());

	if(voidCheck($1)){
		errorOutput<<"Void function used in term"<<endl;
		}
		else if(errortype_Check($1) ){
		errorOutput<<"error  function used in term"<<endl;
		}$$->setTypeSpecifier("term : unary_expression");



	$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

	yOut<<"inside			term :	unary_expression		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;

	}
    |  term MULOP unary_expression {
		$$ = new SymbolInfo("term MULOP unary_expression", $1->getType());
		$$->setTypeSpecifier("term : term MULOP unary_expression");


		if(( ($1->getType() != "int") || ($3->getType() != "int") ) && ($2->getType()=="%")){
		errorOutput<<"Non-Integer operand on modulus operator"<<endl;
		}
		else if(voidCheck($1) || voidCheck($3) ){
		errorOutput<<"Void function used in term"<<endl;
		}
		else if(errortype_Check($1) || errortype_Check($3) ){
		errorOutput<<"error  function used in term"<<endl;
		}

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

		yOut<<"inside			term :	term MULOP unary_expression		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
    ;
//----------------------------------------------------------------------------unary expression====================================================== yesssssssssss(void & error check baki)
unary_expression : ADDOP unary_expression {

	$$ = new SymbolInfo("ADDOP unary_expression", $2->getType());
	$$->setTypeSpecifier("unary_expression : ADDOP unary_expression");

	if(voidCheck($2) ){
		errorOutput<<"Void function used in unary_expression"<<endl;
		}
		else if(errortype_Check($2) ){
		errorOutput<<"error  function used in unary_expression"<<endl;
		}

	$$->set_startLine($1->get_startLine());
	$$->set_endLine($2->get_endLine());
	$$->set_isLeaf(false);
	$$->push_into_childList($1);
	$$->push_into_childList($2);

	

	yOut<<"inside			unary_expression : ADDOP unary_expression		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}  
	| NOT unary_expression {
	$$ = new SymbolInfo("NOT unary_expression",$2->getType());

	if(voidCheck($2) ){
		errorOutput<<"Void function used in unary_expression"<<endl;
		}
		else if(errortype_Check($2) ){
		errorOutput<<"error  function used in unary_expression"<<endl;
		}$$->setTypeSpecifier("unary_expression : NOT unary_expression");



	$$->set_startLine($1->get_startLine());
	$$->set_endLine($2->get_endLine());
	$$->set_isLeaf(false);
	$$->push_into_childList($1);
	$$->push_into_childList($2);


	yOut<<"inside			unary_expression : NOT unary_expression		"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	} 
	| factor {
	$$ = new SymbolInfo("factor", $1->getType());
	$$->setTypeSpecifier("unary_expression : factor");
	$$->setType($1->getType());

	$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
	yOut<<"inside			unary_expression : factor	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	} 
	;
	
//===================================================================factor------------------------------------------------------------------------------------yesssssssssssssssssssss
factor	: variable {
	SymbolInfo *temp=symbolTable->LookUpSymbol($1->getName());
	$$ = new SymbolInfo("variable","");
	if(temp==NULL){
		$$->setType("error");
	}
	else{
		$$->setType(temp->getType());
	}
	$$->setTypeSpecifier("factor	: variable");

	$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
	yOut<<"inside			factor variable	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| ID LPAREN argument_list RPAREN {
		SymbolInfo *temp=symbolTable->LookUpSymbol($1->getName());
		$$ = new SymbolInfo("variable","");
		if(temp==NULL){
			errorOutput<<" function not specified"<<endl;
			$$->setType("error");
		}
		else{
			$$->setType(temp->getType());
		}
		string s=callFunction($1,$3);
		$$->setTypeSpecifier("factor : ID LPAREN argument_list RPAREN");

		callFunction($1,$3);

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($4->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);
		$$->push_into_childList($4);

		yOut<<"inside			factor: ID LPAREN argument_list RPAREN	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| LPAREN expression RPAREN {
		$$ = new SymbolInfo(" LPAREN expression RPAREN",$2->getType());
		$$->setTypeSpecifier("factor : LPAREN expression RPAREN ");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($3->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);
		$$->push_into_childList($3);

		yOut<<"inside			factor: LPAREN expression RPAREN	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;

	}
	| CONST_INT { 
		$$ = new SymbolInfo("CONST_INT","int");
		$$->setTypeSpecifier("factor : CONST_INT");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"inside			factor: CONST_INT	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| CONST_FLOAT { 
		$$ = new SymbolInfo("CONST_FLOAT","float");
		$$->setTypeSpecifier("factor : CONST_FLOAT");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"inside			factor: CONST_FLOAT	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| variable INCOP {
		SymbolInfo *temp=symbolTable->LookUpSymbol($1->getName());
		$$ = new SymbolInfo("variable INCOP","");
		$$->setTypeSpecifier("factor : variable INCOP");
		if(temp==NULL){
			$$->setType("error");
			errorOutput<<" error @ variable incop in factor"<<endl;
		}
		else{
			$$->setType(temp->getType());
		}

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($2->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);

		yOut<<"inside			factor: variable INCOP	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| variable DECOP {
		SymbolInfo *temp=symbolTable->LookUpSymbol($1->getName());
		$$ = new SymbolInfo("variable DECOP","");
		if(temp==NULL){
			$$->setType("error");
			errorOutput<<" error @ variable deccop in factor"<<endl;
		}
		else{
			$$->setType(temp->getType());
		}
		$$->setTypeSpecifier("factor : variable DECOP");

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($2->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);
		$$->push_into_childList($2);

		yOut<<"inside			factor: variable DECOP	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
	
//---------------------------------------------------------------argument_list=======================================================
argument_list : arguments {
		$$ = new SymbolInfo("arguments","");
		$$->setTypeSpecifier("argument_list");
		$$->set_parameter_list($1->get_parameter_list());

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"inside			argument_list : arguments	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;

	}
	| //empty 
	{
		$$ = new SymbolInfo("","");
		$$->setTypeSpecifier("argument_list");
		yOut<<"inside			argument_list : empty	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
	
//=================================================================arguements ------------------------------------------------------------------
arguments : arguments COMMA logic_expression {

	$$ = new SymbolInfo("arguments","");
	$$->set_parameter_list($1->get_parameter_list());
	$$->push_into_parameter_list($3);

	$$->set_startLine($1->get_startLine());
	$$->set_endLine($3->get_endLine());
	$$->set_isLeaf(false);
	$$->push_into_childList($1);
	$$->push_into_childList($2);
	$$->push_into_childList($3);
		
	yOut<<"inside			arguments : arguments COMMA logic_expression	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	| logic_expression {
		$$ = new SymbolInfo("logic_expression",$1->getType());
		$$->setTypeSpecifier("arguments");
		$$->push_into_parameter_list($1);

		$$->set_startLine($1->get_startLine());
		$$->set_endLine($1->get_endLine());
		$$->set_isLeaf(false);
		$$->push_into_childList($1);

		yOut<<"inside			arguments : logic_expression	"<<lineCount<<"		"<<$$->getName()<<"		"<<$$->getTypeSpecifier()<<endl;
	}
	;
%%
void yyerror(char *s){

	cout<<"Error at line "<<lineCount<<": "<<s<<"\n"<<endl;
	errorCount++;

}
void defineFunction(SymbolInfo *returnType,SymbolInfo *name,SymbolInfo *parameter ){

		cout<<"just came into define function------------------------2222222222222222222222222222222222222222"<<endl;		
		name->setType(returnType->getType());
		name->set_parameter_list(parameter->get_parameter_list());
		SymbolInfo *temp=symbolTable->LookUpSymbol(name->getName());
		vector<SymbolInfo*> vec2=name->get_parameter_list();

		cout<<"--------------------------------before  if    in define fun"<<endl;
		if(temp==NULL){
			symbolTable->InsertSymbol(name);
			for(int i=0;i<vec2.size();i++){
				cout<<vec2[i]->getName()<<"		"<<vec2[i]->getType()<<"		"<<vec2[i]->getTypeSpecifier()<<endl;;
			}
			return;
		}
		cout<<"--------------------111111111111111111111111111111111111111"<<endl;
		vector<SymbolInfo*> vec1=temp->get_parameter_list();
		cout<<"000000000000000000000000000000000000000000000000000"<<endl;
		if(temp->is_function_defination()){
			errorOutput<<"Multiple declaration of same function"<<endl;
			return;
		}
		else if(temp->getType()!=returnType->getType()){
			errorOutput<<"return type mis match with pre defination"<<endl;
			return;

		}
		else if(vec1.size()!=vec2.size()){
			errorOutput<<"parameter num mis match"<<endl;
			return;

		}else{
			
			for(int i=0;i<vec2.size();i++){
				if(vec1[i]->getType()!=vec2[i]->getType()){
					errorOutput<<"individual parameter type mis match"<<endl;
				}
			}
		}
		cout<<"11111111111111111111111111111111111111111111111"<<endl;
	yOut<<" function defined "<<endl;


}

string callFunction(SymbolInfo* id,SymbolInfo* parameter){


	cout<<"okkkkkkkkkkkkkkkkkkkkk"<<endl;
	
	

}
void declare_fun_variables(){
	vector<SymbolInfo*> vec=fun_parameter_list;
	for(int i=0;i<vec.size();i++){
		symbolTable->InsertSymbol(vec[i]->getName(),vec[i]->getType());
	}
	fun_parameter_list.clear();
}
void print_parse_tree(SymbolInfo *root,int height){
	for(int i=0;i<height;i++){
		parse_tree_output<<" ";
	}
	if(root->get_isLeaf()){
	parse_tree_output<<root->getTypeSpecifier()<<root->getName()<<"		<Line: "<<root->get_startLine()<<">"<<endl;//"					"<<root->getName()<<"		"<<root->getType()<<endl;
	return;
	}
	vector<SymbolInfo*> vec=root->get_child_list();
	parse_tree_output<<root->getTypeSpecifier()<<"		<Line: "<<root->get_startLine()<<"-"<<root->get_endLine()<<">"<<endl;//					"<<root->getName()<<"		"<<root->getType()<<endl;
	for(int i=0;i<vec.size();i++){
		print_parse_tree(vec[i],height+1);
	}
}
bool voidCheck( SymbolInfo *s){
	if(s->getType()=="void"){
	return true;
	}
	return false;
}
bool errortype_Check( SymbolInfo *s){
	if(s->getType()=="error"){
	return true;
	}
	return false;
}
int main(int argc,char *argv[])
{
	if(argc != 2){
        cout<<"not enough file inputed"<<endl;
        return 0;
    }
    FILE *fin = freopen(argv[1], "r", stdin);
    if(fin == nullptr){
        cout<<"Cannt open file"<<endl;
        return 0;
    }	
    errorOutput.open("error.txt");
    logOutput.open("log.txt");
    lexOut.open("lex.txt");
    yOut.open("y.txt");
	parse_tree_output.open("parse_tree.txt");
	yyin = fin;

    // start scanning the file here
	yyparse();



    // symbolTable->printAllScope(logOutput);

	logOutput<<"Total lines: "<<lineCount<<endl;
    logOutput<<"Total errors: "<<errorCount<<endl;

    fclose(yyin);
    errorOutput.close();
    logOutput.close();
	printf(" parse kora shesh");
	return 0;
}