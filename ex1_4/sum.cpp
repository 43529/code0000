#include<iostream>
int main(){
	int sum = 0, val = 1;
	//只要val 值小于10，循环就一直执行
	while(val <=10){
		sum += val;
		++val;
	}
	std::cout<<"Sum of 1 to 10 inclusive is "<<sum<<std::endl;
	return 0;
}	
