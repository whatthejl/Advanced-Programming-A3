#ifndef LINE3D_H
#define LINE3D_H

#include "Point3D.h"
#include "Line2D.h"

using namespace std;

class Line3D:public Line2D
{
	friend ostream& operator<<(ostream& os, const Line3D&);
	friend bool operator<(const Line3D&, const Line3D&);
	friend bool operator==(const Line3D&, const Line3D&);
	friend bool operator>(const Line3D&, const Line3D&);
	private:
		Point3D pt1;
		Point3D pt2;
	protected:
		void setLength();
	public:
		Line3D();
		Line3D(Point3D, Point3D);
		Point3D getPt1() const;
		Point3D getPt2() const;
		void setPt1(Point3D pt1);
		void setPt2(Point3D pt2);
};
#endif

