#include<iostream>
int main(){
	int sum = 0, val = 1;
	//ֻҪval ֵС��10��ѭ����һֱִ��
	while(val <=10){
		sum += val;
		++val;
	}
	std::cout<<"Sum of 1 to 10 inclusive is "<<sum<<std::endl;
	return 0;
}	
