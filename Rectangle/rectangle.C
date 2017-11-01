#include <iostream>
#include "Vector2D.h"
Vector2D getVec(int i){
	float x,y;
	std::cout << "x" << i<< "= ";
	std::cin  >> x;
	std::cout << "y" << i <<"= ";
	std::cin  >> y;
	return Vector2D(x,y);
}

int main(){
	std::cout<< "Enter vertices 0,1,2,3 " << std::endl;
	Vector2D p[4];
	for(int i=0;i<4;i++) p[i] = getVec(i);
	Vector2D u =p[0].difference(p[3]);
	Vector2D v;
	for (int i=0;i<3;i++){
		v = p[i+1].difference(p[i]);
		if(!u.Perpendicular(v)){
			std::cout<< "No, not a rectangle." << std::endl;
			return 1;
		}
		u = v;
	}
	std::cout<<"Yes, a rectangle." << std::endl;
	return 0;
}
