#include<iostream>
#include<string>
#include<fstream>
#include<list>
using namespace std;
void program();
void stmt_sequence();
void statement();
void if_stmt();
void read_stmt();
void write_stmt();
void repeat_stmt();
void assign_stmt();
void simple_exp();
void term();
void exp();
void factor();
void comparison_Op();
void add_Op();
void mul_Op();
void match(string t);

ifstream in("scanner_output.txt");
ofstream outfile;
list <string>  tokens;

int  main(){
	cin.rdbuf(in.rdbuf());
	outfile.open( "parser_output.txt");
	string s;
	while (getline(cin,s)){
		string temp;
		int index=s.find(":");
		if(s[index+1]=='='){ temp=s.substr(index+3,s.length());  s=s.substr(0,index+2);  tokens.push_back(s); }
		else{	temp=s.substr(index+1,s.length());
		if ((temp=="special symbol")|| temp=="reserved words")
		{s=s.substr(0,index);  tokens.push_back(s);}
		else{  s=temp;    tokens.push_back(s);}}

	}
	/*while(!tokens.empty()){cout<<tokens.front()<<endl;
	tokens.pop_front();
	}*/
	
	program();
	outfile.close();
	system("pause");
	return 0;
}
void error(){
	cout<<"Error caused the programm to stop"<<endl;
	system("pause");
	exit(EXIT_FAILURE);}
void program(){
	stmt_sequence();
	outfile<<"Programm Found"<<endl;
}
void stmt_sequence(){
	statement();
	while(tokens.front()==";"){
		match(";");    statement();
	}

	outfile<<"Statement_Sequence Found "<<endl;
}
void statement(){
	if(tokens.front()=="if")   { if_stmt();   }
	else if(tokens.front()=="read"){    read_stmt();   }
	else if(tokens.front()=="write"){    write_stmt();   }
	else if(tokens.front()=="identifier"){     assign_stmt();   }
	else if(tokens.front()=="repeat"){    repeat_stmt();   }
	outfile<<"Statement Found"<<endl;
	}
void if_stmt(){
	
	match("if");   
	exp();
	match("then");
	stmt_sequence();
	if (tokens.front()=="end"){match("end");}
	if (tokens.front()=="else"){
		match("else");     stmt_sequence();   match("end");}
	outfile<<"If Statement Found "<<endl;
		}

void read_stmt(){
	match("read");
	match("identifier");
	outfile<<"Read_Statement Found "<<endl;
}
void write_stmt(){
	match("write");   exp();
	outfile<<"Write_Statement Found "<<endl;
}
void repeat_stmt(){
		match("repeat"); 
	stmt_sequence();
	match("until");
	exp();
	outfile<<"Repeat_Statement Found "<<endl;
}
void assign_stmt(){
	match("identifier");
	match(":=");
		exp();
	outfile<<"Assignment_Statement Found "<<endl;
}
void simple_exp(){ term();
while(tokens.front()=="+"|| tokens.front()=="-"){
	add_Op();    term();}
	outfile<<"Simple_Expression Found"<<endl;
}
void term(){factor();
while(tokens.front()=="*"|| tokens.front()=="/"){
	mul_Op();  factor();}
	outfile<<"Term Found "<<endl;
}
void exp(){simple_exp();
while(tokens.front()=="<"|| tokens.front()=="="){
	comparison_Op();
	simple_exp();}
	outfile<<"Expression Found"<<endl;
}
void factor(){
	if (tokens.front()=="("){match("(");
	exp(); match(")");   }
	else if (tokens.front()=="number"){match("number");}
	else if (tokens.front()=="identifier"){match("identifier");}
	else error();
	outfile<<"Factor Found"<<endl;
	
}
void comparison_Op(){
	if (tokens.front()=="<") match("<");
	else if (tokens.front()=="=")   match("=");
	else error();
outfile<<"Comparator_Operator Found"<<endl;
}
void add_Op(){
	if (tokens.front()=="+") match("+");
	else if (tokens.front()=="-")   match("-");
	else error();
	outfile<<"Add_Operator Found"<<endl;
}
void mul_Op(){
	if (tokens.front()=="/") match("/");
	else if (tokens.front()=="*")   match("*");
	else error();
outfile<<"Mul_Operator Found"<<endl;
}
void match(string t){
	if (tokens.front()==t){
		if(tokens.size()==1){}
		else {tokens.pop_front();}
	}
		else error();
}