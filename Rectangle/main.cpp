#include <iostream>
#include "Vector2D.h"

float Vector2D::inner(Vector2D &a){ return(x * a.x + y * a.y); }
void Vector2D::display(){ std::cout<<"("<<x<<", "<<y<<")"<<std::endl;}
Vector2D Vector2D::difference(Vector2D &v){ Vector2D tmp; tmp.x= x-v.x; tmp.y= y-v.y; return tmp;}
inline float ABS(float x) { return (x>0? x: -x); }
bool Vector2D::isPerpendicular(Vector2D &v){ return(nonzero() && v.nonzero() && ABS(inner(v)) < .00000001); }

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
		if(!u.isPerpendicular(v)){
			std::cout<< "No, not a rectangle." << std::endl;
			return 1;
		}
		u = v;
	}
	std::cout<<"Yes, a rectangle." << std::endl;
	return 0;
}
