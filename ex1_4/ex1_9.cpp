#include<iostream>
int main(){
	int sum = 0, val = 1;
	//ֻҪval ֵС��100��ѭ����һֱִ��
	while(val <=100){
		sum += val;
		++val;
	}
	std::cout<<"Sum of 1 to 100 inclusive is "<<sum<<std::endl;
	return 0;
}	
