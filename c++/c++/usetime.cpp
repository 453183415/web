/*
 * usetime.cpp
 *
 *  Created on: 2015年8月18日
 *      Author: zjl
 */
#include"mytime0.h"
//#include "mytime0.cpp"
#include <iostream>
int main()
{
	using std::cout ;
	using std::cin;
	using std ::endl;
	Time lanning;
	Time coding(2,34);
	Time fixing(3,54);
	Time total;
	coding.Show();
	total =coding+fixing;
	total.Show();
	float i=100/27;
	cout<<i;
	return 0;
}




