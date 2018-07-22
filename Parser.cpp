//============================================================================
// Name        : Parser.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include <bits/stdc++.h>
using namespace std;


/*


2. identifiers - words that the programmer constructs to attach a name to
a construct, usually having some indication as to the purpose or intent
of the construct. Identifiers may be used to identify variables, classes,
constants, functions, etc.


4. numeric constants - numbers such as 124, 12.35, 0.09E-23, etc. These
must be converted to a numeric format so that they can be used in arithmetic
operations, because the compiler initially sees all input as a string
of characters. Numeric constants may be stored in a table.
6. special characters - characters used as delimiters such as .,(,),,,;. These
are generally single-character words.
7. comments - Though comments must be detected in the lexical analysis
phase, they are not put out as tokens to the next phase of compilation.





*/

/************************************************************************************************************************/

bool isoperator(string s){

if (s=="="||s=="+"||s=="-"||s=="*"||s=="/"||s=="%"||s=="++"||s=="--"||s=="=="||s=="!=")
	return true;
else if(s==">"||s=="<"||s=="<="||s==">="||s=="&&"||s=="*&"||s=="&"||s=="|"||s=="||"||s=="!")
{
	return 1;

	}
else if(s=="~"||s=="^"||s=="<<"||s==">>"||s=="+="||s=="-="||s=="*="||s=="/="||s=="%="||s=="%="||s=="&="||s=="^="||s=="|=")

{
	return 1;
	}

else {
	return 0;
}




}

/**************************************************************************************************************************************/

bool keyword(string s){

if(s=="if")
	return 1;
else if (s=="while")
{
	return 1;
}

else if (s=="for")
{
	return 1;
}
else if (s=="else")
{
	return 1;
}
else if (s=="case")
{
	return 1;
}
else if (s=="class")
{
	return 1;
}
else if (s=="switch"||s=="iostream"||s=="include"||s=="fstream"||s=="using"||s=="namespace")
{
	return 1;
}
else if (s=="break")
{
	return 1;
}

else if (s=="continue"||s=="true"||s=="false"||s=="return"||s=="this"
		||s=="signed"||s=="unsigned"||s=="static"||s=="cout"||s=="cin"||s=="getline"||s=="gets"||s=="puts"
				||s=="scanf"||s=="printf")
{
	return 1;
}
else if (s=="struct"||s=="const"||s=="static")
{
	return 1;
}
else if (s=="string")
{
	return 1;
}
else if (s=="int"||s=="double"||s=="flaot"||s=="long long"||s=="bool")
{
	return 1;}

else{


	return 0;
}


}
/****************************************************************************************************/

bool numericconstants(string s){

	int len=s.length();
	int count=0;
	for(int i=0;i<len;i++){
		if((int)s[i]>=48&&(int)s[i]<=57)
			++count;
	}
	if(len==count)
		return 1;
	else
		return 0;
}
/************************************************************************/

vector<string> devidestring(string s){
	vector <string> vect;
	int len=s.length();
	int pastindsex=-1;
	for(int i=0;i<len;i++){

		if(s[i]==' '||i==len-1){
			string y=s.substr(pastindsex+1,i-pastindsex-1);
			pastindsex=i;
			vect.push_back(y);

		}

	}
	return vect;
}
/*************************************************************************************************/
bool isSpecialcharater(string s){
	 if(s=="."||s=="'"||s==";"||s==":"||s==","||s=="\""||s=="("||s==")"||s=="{"||s=="}"||s=="#")
		 return 1;
	 else return 0;

}


int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	string s;
	vector<string> parts ;
	vector<string> operators;
	vector<string> keywords;
	vector<string> numberconstants;
	vector<string> Specialcharaters;
	vector <string> identifire;


while(getline(cin,s))
	{
	parts=devidestring(s);
		int length=parts.size();
		/*for(int i=0;i<length;i++){
			cout<<parts[i]<<endl;
		}*/

		for(int i=0;i<length;i++){
			if(isoperator(parts[i])&&parts[i]!=" ")
				operators.push_back(parts[i]);
			else if(keyword(parts[i])&&parts[i]!=" ")
				keywords.push_back(parts[i]);
			else if(numericconstants(parts[i])&&parts[i]!=" ")
				numberconstants.push_back(parts[i]);
			else  if(isSpecialcharater(parts[i])&&parts[i]!=" ")
				Specialcharaters.push_back(parts[i]);
			else {
				if(parts[i]!=" ")
				identifire.push_back(parts[i]);

			}


		}
	}
cout<<"                -_-  welcome to the parser   -_-              "<<endl;
cout<<"                *_* here is the tokens :  *_*"<<endl<<endl<<endl<<endl<<endl<<endl;
	/*************************************output keywords******************************************/
	int keywordslength=keywords.size();
	cout<<"***  the keywords are : "<<endl<<"****************                   ****************"<<endl<<endl;
	for(int i=0;i<keywordslength;i++){
		cout<<keywords[i]<<"\n";
	}
	/*******************************************output operators ******************************************/
	cout<<endl<<endl<<"***  the operators are : "<<endl<<"****************                   ****************"<<endl<<endl;
		int operatorslength=operators.size();
	for(int i=0;i<operatorslength;i++){
			cout<<operators[i]<<"\n";
		}
	/*******************************************output numberconstants  ******************************************/
		cout<<endl<<endl<<"***  the  numberconstants are : "<<endl<<"****************                   ****************"<<endl<<endl;
			int numberconstantslength=numberconstants.size();
		for(int i=0;i<numberconstantslength;i++){
				cout<<numberconstants[i]<<"\n";
			}

 /*******************************************output Specialcharaters  ******************************************/
			cout<<endl<<endl<<"***  the Specialcharaters are : "<<endl<<"****************                   ****************"<<endl<<endl;
				int Specialcharaterslength=Specialcharaters.size();
			for(int i=0;i<Specialcharaterslength;i++){
					cout<<Specialcharaters[i]<<"\n";
				}
/*******************************************output identifire  ******************************************/
						cout<<endl<<endl<<"***  The identifires are : "<<endl<<"****************                   ****************"<<endl<<endl;
							int identifirelength=identifire.size();
						for(int i=0;i<identifirelength;i++){
								cout<<identifire[i]<<"\n";
							}

/***************************************************************************************************/
					cout<<"\n\n\n\n\n";
					cout<<"Happy cooding \n";
					cout<<"thanks ,\n Mohand Sakr\n";



	return 0;

}
