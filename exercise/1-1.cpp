/*
 * 1-1.cpp
 *
 *  Created on: 2015年11月2日
 *      Author: zjl
 */
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<list>
#include<deque>
#include<queue>
#include<map>
int main()
{
	std::multimap<std::string,std::size_t>word_count;
	std::string word;
	std::size_t i;
	while(std::cin>>word){
		word_count.insert(make_pair(word,i));
		if(word_count.size()>5)
			break;
	}
	std::cout<<std::endl;
	for(const auto & w : word_count){

		//std::cout<<w.first<<"    occurs    "<<w.second<<((w.second>"ds")?"  times":"    time")<<std::endl;
		std::cout<<w.second<<std::endl;
	}
	#if(0)
	//std::list<std::deque<int>> listt;
	//std::ifstream in("a.txt");
	//std::ofstream ou("a.txt");
	std::vector <int>v1={1,2,3,4,5,6,7,8,9,0};
	std::deque <int>V1={1,2,3,4,5,6,7,8,9,0};
	//std::cout<<listt.max_size()<<std::endl;

	for(int i=0;i<100;i++)
		v1.push_back(i);
	for(auto a: v1)
	//std::cout<<a<<std::endl;
	v1.size();
	std::cout<<v1.size()<<std::endl;;

	std::queue<int>deq(V1);
	deq.pop();
	while(!deq.empty()){
		//std::cout<<deq.front()<<std::endl;
		deq.pop();
	}
	#endif
#if(0)
	auto begin=v1.begin();
	while(begin!=v1.end()){
	//auto a=v1.begin();
		++begin;
		begin=v1.insert(begin,*begin);
		++begin;
	//std::cout<<*begin<<std::endl;

	}
	std::vector<int>ivce;

	std::cout <<ivce.size()<<std::endl;
	ivce.reserve(20);
	int i=0;
	while(i<21){
		ivce.push_back(i);
		i++;
	}
	std::cout <<ivce.size()<<std::endl;
	std::cout<<ivce.capacity()<<std::endl;
	auto a=v1.begin();
	while(a!=v1.end()){
		//std::cout<<*a<<std::endl;
				a++;;
	}

#endif

	return 0;
}



