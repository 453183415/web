/*
 * demo.cpp
 *
 *  Created on: 2015年8月20日
 *      Author: zjl
 */
#include<iostream>
#include"complex0.h"
using namespace std;
using COMPLEX::complex0;
int main()
{
	complex0 a(3.0,4.0);
	complex0 c;
	cout <<"Enter a complex number (q to quite):\n";
	while(cin >> c){
		cout << "c is "<<c<<endl;
		cout <<"complex conjugate is"<< &c<<"\n";
		cout <<"a is "<<a<<endl;
		cout << "a +c"<<a+c<<endl;
		cout <<"a -c " <<a-c <<endl;
		cout <<"a * c" <<a*c<<endl;
		cout << "2*c" <<c*2.0 <<endl;
		cout <<"Enter a complex number (q to quite):\n";
		}
	cout<<"Done!\n";

	return 0;
}
