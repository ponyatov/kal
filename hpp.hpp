#ifndef _H_HPP
#define _H_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

struct AST {
	string tag,val;
	vector<AST*> nest; void push(AST*);
	AST(); AST(string,string); AST(string);
	virtual string dump(int=0); virtual string head(); string pad(int);
};

struct Def: AST { Def(string); };
struct Ext: AST { Ext(string); };
struct Id: AST { Id(string); };
struct Num: AST { Num(string); float val; string head(); };

struct Op: AST { Op(string); };

struct Vector: AST { Vector(); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"

#endif // _H_HPP
