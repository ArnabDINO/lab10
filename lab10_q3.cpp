/*
3.Create a class for rectangle that stores data of length and breadth 
and has two functions : area() and perimeter(). 
Write a program that uses this class to create two rectangles (rectangle objects) of user inputted length and breadth. 
Compare the areas and perimeter of the those rectangles.
*/

#include<iostream>

using namespace std;

class rectangle//.Create a class for rectangle
{
	public:
	//stores data of length and breadth
	double length;
	double breadth;
	
	//has two functions : area() and perimeter()
	double area(void);
	double perimeter(void);
	
};

double rectangle::area(void)
{
	return length*breadth;
}

double rectangle::perimeter(void)
{
	return 2*(length+breadth);
}

int main()
{
	rectangle rect1,rect2;
	cout<<"enter the dimensions for first rectangle"<<endl;
	cin>>rect1.length>>rect1.breadth;
	cout<<"enter the dimensions for second rectangle"<<endl;
	cin>>rect2.length>>rect2.breadth;
	
	
	double area1=rect1.area(),area2=rect2.area();
	double peri1=rect1.perimeter(),peri2=rect2.perimeter();
	
	//********************************************************************************
	//Compare the areas of the those rectangles.
	//********************************************************************************
	if (area1<area2)
	{
		cout<<"rectangle 2 has greater area than the first one"<<endl;
	}
	else if (area1>area2)
	{
		cout<<"rectangle 1 has greater area than the second one"<<endl;
	}
	else cout<<"the areas are equal"<<endl;
	
	//**********************************************************************************
	//perimeter comparing
	//**********************************************************************************
	if (peri1<peri2)
	{
		cout<<"rectangle 2 has greater perimeter than the first one"<<endl;
	}
	else if (peri1>peri2)
	{
		cout<<"rectangle 1 has greater perimeter than the second one"<<endl;
	}
	else cout<<"the areas are equal"<<endl;
	
	return 0;
}
