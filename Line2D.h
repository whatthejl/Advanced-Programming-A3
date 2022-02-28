#ifndef LINE2D_H
#define LINE2D_H

#include "Point2D.h"

using namespace std;

class Line2D
{
	friend ostream& operator<<(ostream&, const Line2D&);
	friend bool operator==(const Line2D&, const Line2D&);
	friend bool operator<(const Line2D&, const Line2D&);
	friend bool operator>(const Line2D&, const Line2D&);
	
	private:
		Point2D pt1;
		Point2D pt2;
	protected:
		double length;
		void setLength();
		string sortcrit;
	public:
		Line2D();
		Line2D(Point2D, Point2D);
		Point2D getPt1() const;
		Point2D getPt2() const;
		double getScalarValue() const;
		void setPt1(Point2D pt1);
		void setPt2(Point2D pt2);
		void setSorting(string);
};
#endif

