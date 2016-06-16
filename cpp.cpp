#include "hpp.hpp"
#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<<"]\n\n"
void yyerror(string msg) { cout<<YYERR; cerr<<YYERR; exit(-1); }
int main() { return yyparse(); }

AST::AST(){}
AST::AST(string T,string V) { tag=T; val=V; }
AST::AST(string V):AST("sym",V) {}
void AST::push(AST*o) { nest.push_back(o); }

string AST::head() { return tag+":"+val; }
string AST::pad(int n) { string S; for (int i=0;i<n;i++) S+='\t'; return S; }
string AST::dump(int depth) { string S = "\n"+pad(depth)+head();
	for (auto it=nest.begin(),e=nest.end();it!=e;it++)
		S += (*it)->dump(depth+1);
	return S; }

Def::Def(string V):AST("def",""){}
Ext::Ext(string V):AST("ext",""){}

Id::Id(string V):AST("id",V){}

Num::Num(string V):val(atof(V.c_str())) {tag="num";}
string Num::head() { ostringstream os; os<<tag<<":"<<val; return os.str(); }

Op::Op(string V):AST("op",V){}

Vector::Vector():AST("vector","[]"){}
