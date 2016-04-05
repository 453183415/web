/*
 * complex0.h
 *
 *  Created on: 2015年8月19日
 *      Author: zjl
 */

#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include<iostream>
namespace COMPLEX{
	class complex0{
	private:
		double real;
		double imag;
	public:
		complex0():real(0.0),imag(0.0){}
		complex0(double real,double imag);
		~complex0(){}
		void set_real(double n){
			//double n;
			//std::cin>>n;
			real=n;}
		void set_imag(double n){
			//double n;
		//	std::cin>>n;
			imag=n;
		}
	//	complex0 operator =(complex0 const &t)const;
		complex0 operator +(complex0 const &t)const;
		complex0 operator -(complex0 const  &t)const;
		complex0 operator *(complex0 const &t)const;
		complex0 operator &(complex0 const &t)const;
		complex0 operator*(double const n)const;
		friend std::istream & operator >>(std::istream &is,complex0 const &t);
		friend std::ostream & operator <<(std::ostream &os ,complex0 const &t);
	};
}





#endif /* COMPLEX0_H_ */
