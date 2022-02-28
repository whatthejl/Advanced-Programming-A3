#ifndef POINT2D_H
#define POINT2D_H

#include<string>
#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

class Point2D
{
	friend ostream& operator<<(ostream&, const Point2D&);
	friend bool operator==(const Point2D&, const Point2D&);
   	friend bool operator<(const Point2D&, const Point2D&);
    	friend bool operator>(const Point2D&, const Point2D&);

	protected:
		int x;
		int y;
		string sortcrit;
		double length;
		void setDistFrOrigin();
	public:
		Point2D();
		Point2D(int, int);
		int getX();
		int getY();
		string getSorting();
		double getScalarValue();
		void setX(int);
		void setY(int);
		void setSorting(string);
};
#endif