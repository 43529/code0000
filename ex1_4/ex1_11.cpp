#include<iostream>
int main(){
	int start = 0, end = 0, v = 0;
	std::cout<<"Please enter two integers: "<<std::endl;
	std::cin>>start>>end;
	if(start > end){
			v = start;
			start = end;
			end = v;
	}
	v = start;
	while(v <= end){
			std::cout<<v<<std::endl;
					v++;
	}
	return 0;
}	
