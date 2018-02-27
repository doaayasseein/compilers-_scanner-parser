#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
	ifstream in("tiny_sample_code.txt");
	cin.rdbuf(in.rdbuf());
	string s;
	ofstream outfile;
	string lowAlphabets= "abcdefghijklmnopqrstuvwxyz";
	string highAlphabets="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

   outfile.open("scanner_output.txt");
   string reservedWords[8]={"if","then","repeat","else","read","write","end","until"};
	while (getline(cin,s)){
		for(int i=0; i<s.length();i++){
		if((i>0)&&(s[i]=='=')&&(s[i-1]==':') ){ outfile<<s[i-1]<<s[i]<<":special symbol"<<endl; }
		else   if((s[i]=='(')||(s[i]==')')||(s[i]=='+')||(s[i]=='-')||(s[i]=='*') ||(s[i]=='/')||(s[i]=='=')||(s[i]=='<')||(s[i]=='>')||(s[i]==';')||(s[i]=='%')){
				outfile<<s[i]<<":special symbol"<<endl;
			}
		else  if((s[i]=='i')||(s[i]=='e')||(s[i]=='r')||(s[i]=='w')||(s[i]=='u') ||(s[i]=='t')){ 
			string temp;
			while(lowAlphabets.find(s[i])<lowAlphabets.length()){
				// (i==s.length()){break;}
				//(s[i]==';'){ i--; break;}
			temp.insert(temp.length(),1,s[i]);
			i++;
						}
		int 	flag=0;
			for(int j =0;j<8;j++){
			if (temp==reservedWords[j]){ outfile<<temp<<":reserved words"<<endl;  flag=1;  break;  }
			}
			if (flag==0){outfile<<temp<<":identifier"<<endl;} 
			i--;
		}
		else if((s[i]=='0')||(s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4') ||(s[i]=='5')||(s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9')){
		string temp; 
		while((s[i]=='0')||(s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4') ||(s[i]=='5')||(s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9')){
			if(s[i]==';'){i--;  break;}
			temp.insert(temp.length(),1,s[i]);
			i++;
						}
		i--;
		outfile<<temp<<":number"<<endl;
		}
		else if(s[i]=='{'){
			while(s[i]!='}'){i++;}
		}
		else if((lowAlphabets.find(s[i])<lowAlphabets.length())||(highAlphabets.find(s[i])<highAlphabets.length())){
		string temp ;
		while((lowAlphabets.find(s[i])<lowAlphabets.length())||(s[i]=='’')||(highAlphabets.find(s[i])<highAlphabets.length())){
				
			temp.insert(temp.length(),1,s[i]);
			i++;
						}
		outfile<<temp<<":identifier"<<endl;
		i--;}

		
		}}
   outfile.close();
	system("pause");
return 0;}