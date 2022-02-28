#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

using namespace std;

class Point3D:public Point2D
{
	friend ostream& operator<<(ostream&, const Point3D&);
	friend bool operator==(const Point3D&, const Point3D&);
    	friend bool operator<(const Point3D&, const Point3D&);
    	friend bool operator>(const Point3D&, const Point3D&);

	protected:
		int z;
		void setDistFrOrigin();
	public:
		Point3D();
		Point3D(int, int, int);
		int getZ();
		void setZ(int);
};
#endif

