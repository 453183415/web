/*
 * mytime0.h
 *
 *  Created on: 2015年8月18日
 *      Author: zjl
 */

#ifndef MYTIME0_H_
#define MYTIME0_H_


class Time{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h,int m=0);
	void AddMin(int m);
	void AddHr(int h);
	void reset(int h=0, int m=0);
	Time operator + (const Time  &T)const;
	void Show()const;
};





#endif /* MYTIME0_H_ */
