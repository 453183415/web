/*
 * complex0.cpp
 *
 *  Created on: 2015年8月20日
 *      Author: zjl
 */
#include"complex0.h"
namespace COMPLEX{
	complex0::complex0(double real,double imag){
		this->real=real;
		this->imag=imag;
	}
	complex0 complex0::operator +(const complex0 &t)const{
		return complex0(real+t.real,imag+t.imag);
	}
	complex0 complex0::operator -(const complex0 &t)const{
			return complex0(real-t.real,imag-t.imag);
	}
	complex0 complex0::operator *(const complex0 &t)const{
			return complex0(real*t.real-imag*t.imag,real*t.imag+t.real*imag);
	}/*
	complex0 complex0::operator =(const complex0 &t)const{
			return complex0(real=t.real,imag=t.imag);
	}*/
	complex0 complex0::operator &()const{
			return complex0(real,-imag);
	}
	complex0 complex0::operator *(double n)const{
		return complex0(real*n,imag*n);
	}
	std::istream & operator >>(std::istream &is,complex0 &t){
		std::cout<<"real:";
		double n;
		is>>n;
		t.set_real(n);
		//std::cout<<"\n";
		std::cout<<"imaginary:";
		is>>n;
		t.set_imag(n);
	//	std::cout<<"\n";
		return is;
	}
	std::ostream & operator <<(std::ostream &os,complex0 const &t){
		os<<"("<<t.real<<","<<t.imag<<"i)";
		return os;
	}
}



