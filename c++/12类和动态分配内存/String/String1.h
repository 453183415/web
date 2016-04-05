/*
 * String1.h
 *
 *  Created on: 2015年8月20日
 *      Author: zjl
 */

#ifndef STRING1_H_
#define STRING1_H_
#include<iostream>
using std::ostream;
using std::istream;
class String{
	private:
		char *str;
		int len;
		static int num_string;
		static const int CINLIM =80;
	public:
		String(const char *);
		String();
		String(const String &);
		~String();
		int length(){return len;}
		String& Stringlow()const;
		String &Stringup()const;
		int has(const char &);
		String &operator =(const String &);
		String &operator =(const char *);
		char & operator [](int i);
		const char & operator [](int i)const;
		String &  operator +(const String &t);
		String &  operator +(const char*t);
		friend bool operator >(const String &t1,const String &t2);
		friend bool operator <(const String &t1,const String &t2);
		friend bool operator == (const String &t1, const String &t2);
		friend ostream & operator <<(ostream &os,const String &t);
		friend istream & operator >>(istream &is,String &t);
		static int HowMany();


};




#endif /* STRING1_H_ */
