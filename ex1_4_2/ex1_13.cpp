#include<iostream>
void func0();
void func1();
void func2();
int main(){
		func0();
		func1();
		func2();
		return 0;
}
void func0(){
	int sum = 0, val = 1;
	//只要val 值小于100，循环就一直执行
	for(;val <=100;val++){
		sum += val;
	}
	std::cout<<"Sum of 1 to 100 inclusive is "<<sum<<std::endl;
}	
void func1(){
		int	val = 10;
		//只要val 值大于0，循环就一直执行
		for(;val >= 0;--val){
				std::cout<<val<<std::endl;
		}
}	
void func2(){
	int start = 0, end = 0, v = 0;
	std::cout<<"Please enter two integers: "<<std::endl;
	std::cin>>start>>end;
	if(start > end){
			v = start;
			start = end;
			end = v;
	}
	v = start;
	for(;v <= end;v++){
			std::cout<<v<<std::endl;
	}
}	

