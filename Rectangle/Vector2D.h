#include <iostream>

class Vector2D{
	public:
	Vector2D(){}
	Vector2D(float a, float b){ x=a; y=b;}
	Vector2D difference(Vector2D& v);
	float inner(Vector2D& v);
	bool isPerpendicular(Vector2D& v);
	bool nonzero(){ return( x!=0.0 || y!=0.0); }
	void display();
	private:
	float x,y;
};
