#include <iostream>
using namespace std;


// ********************************************************************
//  Declaration of class Point
// ********************************************************************

// class Point represents a two-dimensional point
class Point
{
public:
  // default class constructor (with no arguments):
  Point(); 

  // class constructor that sets the coordinates x, y to the values xval,
  // yval:
  Point(int xval, int yval);

  // member function for moving a point by dx, dy:
  void Move(int dx, int dy);

  // member functions for getting values of x, y:
  int Get_X() const;
  int Get_Y() const;

  // member functions for setting x, y to xval, yval respectively  
  void Set_X(int xval);
  void Set_Y(int yval);

//Lab 7 exercise 4.1. Add declaration of member function Print here:
	void print(void);

// private data members x, y represent coordinates of the point:
private:
  int X;
  int Y;
};  


// ********************************************************************
//  Methods for class Point
// ********************************************************************

// class constructor sets X, Y to zero when no values are specified:
Point::Point()
{
  X = 0;
  Y = 0;
}

// class constructor sets X, Y to given values xval, yval:
Point::Point(int xval, int yval)
{
  X = xval;
  Y = yval;
}

// member function Move: increases the x coordinate by dx and the y
// coordinate by dy.
void Point::Move(int dx, int dy)
{
  X += dx;
  Y += dy;
}

// Get_X returns the value of the X coordinate
int Point::Get_X() const
{
  return X;
}

// Get_Y returns the value of the Y coordinate
int Point::Get_Y() const
{
  return Y;
}

// Set_X sets the value of X coordinate to xval
void Point::Set_X(int xval)
{
  X = xval;
} 

// Set_Y sets the value of Y coordinate to yval
void Point::Set_Y(int yval)
{
  Y = yval;
} 
    

//Lab 7 exercise 4.1. Add definition of member function print:
void Point::print()
{
	cout<<"("<<X<<","<<Y<<")"<<endl;
}

// ********************************************************************
//  Declaration of class Rectangle
// ********************************************************************

/*
	Write a definition of a class Rectangle using the Point class.
	A rectangle is specified by two corner points (bottom left and top right). 
	The sides of the rectangle are parallel to the coordinate axes.
	The implementation of the class should be as follows: 
	 The private data members of the class include all 4 corner points of the rectangle. 
 	 There are two constructors: 
	  one takes two points as arguments and creates a rectangle with the first point as the bottom left corner 
	  and the second as the top right corner, 
	  the other (default) constructor creates a rectangle with the corners (0,0), (1,0), (0,1), (1,1). 
Hint: use functions Set_X, Set_Y from the class Point to set the values of the corner points. 
    The print member function prints all 4 corners of the rectangle, using the member function print of the class Point. 
    Test the class Rectangle in main(), demonstrate that all member functions work as specified. 

*/

//Lab 7 exercise 4.2, 4.3: Add class Rectangle declaration HERE: 

/*************************************************************************************

pB*********************************pC
*									*
*									*
*									*
pA*********************************pE

**************************************************************************************/

class Rectangle
{
	public:
		//default class constructor with no arguments
		Rectangle();
		
		/*************************************************************************
		class constructor to sets the value of A and C vertices of the 
		rectangle to points pA and pC respectively.
		***************************************************************************/
		Rectangle(Point pA_temp, Point pC_temp);
		
		//the print function
		void print_rect(void);
		
		//write a public member function to compute the area of the rectangle. 
		int area(void);
		
/**********************************************************************************
 The private data members of the class include all 4 corner points of the rectangle.
************************************************************************************/		
	private:
		Point pA;
		Point pB;
		Point pC;
		Point pE;
		//*****************************************************************************************
		//Add two private member functions side1, side2 to the class Rectangle
		//to compute the lengths of the two sides.
		//Using this function, write a public member function to compute the area of the rectangle. 
		//*****************************************************************************************
		
		int side1(void);
		int side2(void);
		
		
};

// ********************************************************************
//  Methods for class Rectangle
// ********************************************************************

//Lab 7 exercise 4.2, 4.3. Add class Rectangle methods HERE: 

// Default constructor
Rectangle::Rectangle()
{
	pA.Set_X(0);
	pA.Set_Y(0);
	pC.Set_X(1);
	pC.Set_Y(1);
	pB.Set_X(pA.Get_X());
	pB.Set_Y(pC.Get_Y());
	pE.Set_X(pC.Get_X());
	pE.Set_Y(pA.Get_Y());
}

/**********************************************************************
 	  one takes two points as arguments and creates a rectangle with 
	  the first point as the bottom left corner 
	  and the second as the top right corner,
*************************************************************************/
Rectangle::Rectangle(Point pA_temp,Point pC_temp)
{
	pA.Set_X(pA_temp.Get_X());
	pA.Set_Y(pA_temp.Get_Y());
	pC.Set_X(pC_temp.Get_X());
	pC.Set_Y(pC_temp.Get_Y());
	pB.Set_X(pA.Get_X());
	pB.Set_Y(pC.Get_Y());
	pE.Set_X(pC.Get_X());
	pE.Set_Y(pA.Get_Y());
}

/*********************************************************************
the print_rect's definition 
**********************************************************************/
void Rectangle::print_rect()
{
	pA.print();
	pB.print();
	pC.print();
	pE.print();
}

/************************************************************************
SIDE1 function
*************************************************************************/
int Rectangle::side1()
{
	if(pA.Get_X()<pC.Get_X())
	{
		return pC.Get_X()-pA.Get_X();
	}
	else
	{
		return pA.Get_X()-pC.Get_X();
	}
}

/************************************************************************
SIDE2 function
*************************************************************************/
int Rectangle::side2()
{
	if(pA.Get_Y()<pC.Get_Y())
	{
		return pC.Get_Y()-pA.Get_Y();
	}
	else
	{
		return pA.Get_Y()-pC.Get_Y();
	}
}

/***************************************************************************
area Function
****************************************************************************/
int Rectangle::area()
{
	return (side1()*side2());
}


// ********************************************************************
//  main() function for testing classes Point and Rectangle
// ********************************************************************



// Testing classes Point and Rectangle
int main()
{
// Declaring a point using default class constructor (x = y = 0):
  Point p1;
  cout<< "The x value for p1 is " << p1.Get_X() << endl;
  cout<< "The y value for p1 is " << p1.Get_Y() << endl;

// Declaring a point with coordinates X = 2, Y = 3:
  Point p2(2, 3);
  cout<< "The x value for p2 is " << p2.Get_X() << endl;
  cout<< "The y value for p2 is " << p2.Get_Y() << endl;

// Moving point p2 by (1, -1):
  p2.Move(1, -1);
  cout<< "After the move:" << endl;
  cout<< "The x value for p2 is " << p2.Get_X() << endl;
  cout<< "The y value for p2 is " << p2.Get_Y() << endl;

//Lab 7 exercise 4.1. Test member function print on points p1, p2:
	cout<<"\n solution of exercise 4.1\n"<<endl;
	cout<<"the point p1 is ";
	p1.print();
	cout<<"the point p2 is ";
	p2.print();

//Lab 7 Exercises 4.2, 4.3. Testing of the class Rectangle goes here:  
/********************************************************************
 The print member function prints all 4 corners of the rectangle, using the member function print of the class Point. 
Test the class Rectangle in main(), demonstrate that all member functions work as specified. 
********************************************************************/
	cout<<"\n sol to 4.2 starts here\n"<<endl;
	//Declaring default Rectangle
	Rectangle R1;
	cout<<"The four points of default rectangle are \n";
	R1.print_rect();
	
	//Declaring specific case of Rectangle
	Rectangle R2(p1,p2);
	cout<<"The four points of the rectangle with p1 and p2 as the vetices are \n";
	R2.print_rect();
/**********************************************************************************************************************
output for the area
***********************************************************************************************************************/
	cout<<"\n the solution for 4.3 starts here \n"<<endl;
	cout<<"The area of the default rectangle is "<<R1.area()<<" units"<<endl;
	cout<<"The area of the custom rectangle is "<<R2.area()<<" units"<<endl;
	cout<<"\n \n \n \n **************************************end*******************************************************\n";
  return 0;
}
/*
ooof! this the end of a long journey. Thank you sir for everything you have taught us. I don't know if you are readig this or not.
But I am very happy to complete this project. It was wonderful, and a little complex. Whatever be it I liked it. Maybe it is easy and i'm a noob.
but I enjoyed solving it and lked the way you taught us the whole semester.

One suggestion ,

next semester give such an assignment for which we have to learn VFX too.


Again, Thamk You Sir,

Arnab.
*/
