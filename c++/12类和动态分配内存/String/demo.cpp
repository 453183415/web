/*
 * demo.cpp
 *
 *  Created on: 2015年8月20日
 *      Author: zjl
 */
#include<iostream>
#include"String1.h"
using namespace std;
int main()
{
	String s1("and I am a C++ student.");
	String s2("Please enter you name :");
	String s3;
	cout<<s2.length()<<endl;
	cout << s2<<endl;;
	//cout <<s2.length()<<endl;
	cout <<s1.length();
	s1=s2;
	//cout << s1<<endl;
	cout<<s3.length();
	//cin>> s3;
	cout<<s3.length();
	s2= "My name is " ;
	cout<<s2<<endl;
	//s2=s2+ s3;
	cout<<s2;
	s2=s2+s1;
	s2.Stringup();
	cout<<"The string \n"<<s2<<"\n contains "<<s2.has('A')<<" 'A' characters in it \n ";
	s1="red";
	String rgb[3]={String(s1),String("green"),String("blue")};
	String ans;
	bool success=false;
	while(cin >> ans){
		ans.Stringlow();
		for(int i=0;i<3;i++){
			if(ans==rgb[i]){
				cout<<"That`s right !\n";
				success=true;
				break;
			}
		}
		if(success)
			break;
		else
			cout<<"Try again !\n";
	}
	cout<< "Bye!\n";
	return 0;
}



