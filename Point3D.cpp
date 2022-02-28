#include "Point3D.h"

ostream& operator<<(ostream& os, const Point3D& pt)
{
    os << "[" << setw(4) << pt.x << "," << setw(4) << pt.y << "," << setw(4) << pt.z << "]   " << fixed << setprecision(3) << pt.length << endl;
	return os;
}
bool operator==(const Point3D& pt1, const Point3D& pt2) //check for duplicates
{
	if (pt1.x == pt2.x && pt1.y == pt2.y && pt1.z == pt2.z)
		return true;
	return false;
}
bool operator<(const Point3D& pt1, const Point3D& pt2) //return true if pt1 < pt2
{
	if (pt1.sortcrit == "X-ordinate")
    {
		if (pt1.x < pt2.x)
			return true;
        if (pt1.x == pt2.x && pt1.y < pt2.y)
            return true;
        if (pt1.x == pt2.x && pt1.y == pt2.y && pt1.z < pt2.z)
            return true;
	}
	else if (pt1.sortcrit == "Y-ordinate")
    {
		if (pt1.y < pt2.y)
            return true;
        if (pt1.y == pt2.y && pt1.x < pt2.x)
            return true;
        if (pt1.y == pt2.y && pt1.x == pt2.x && pt1.z < pt2.z)
			return true;
	}
	else if (pt1.sortcrit == "Z-ordinate")
    {
		if (pt1.z < pt2.z)
            return true;
        if (pt1.z == pt2.z && pt1.x < pt2.x)
            return true;
        if (pt1.z == pt2.z && pt1.x == pt2.x && pt1.y < pt2.y)
			return true;
	}
	else if (pt1.sortcrit == "Dist. Fr Origin")
    {
		if (pt1.length < pt2.length)
			return true;
	}
	return false;
}
bool operator>(const Point3D& pt1, const Point3D& pt2) //return true if pt1 > pt2
{
	if (pt1.sortcrit == "X-ordinate")
    {
		if (pt1.x > pt2.x)
			return true;
		if (pt1.x == pt2.x && pt1.y > pt2.y)
			return true;
		if (pt1.x == pt2.x && pt1.y == pt2.y && pt1.z > pt2.z)
			return true;
	}
	else if (pt1.sortcrit == "Y-ordinate")
    {
		if (pt1.y > pt2.y)
			return true;
		if (pt1.y == pt2.y && pt1.x > pt2.x)
			return true;
		if (pt1.y == pt2.y && pt1.x == pt2.x && pt1.z > pt2.z)
			return true;
	}
	else if (pt1.sortcrit == "Z-ordinate")
    {
		if (pt1.z > pt2.z)
			return true;
		if (pt1.z == pt2.z && pt1.x > pt2.x)
			return true;
		if (pt1.z == pt2.z && pt1.x == pt2.x && pt1.y > pt2.y)
			return true;
	}
	else if (pt1.sortcrit == "Dist. Fr Origin")
    {
		if (pt1.length > pt2.length)
			return true;
	}
	return false;
}
Point3D::Point3D(): Point2D()
{
	z = 0;
}
Point3D::Point3D(int x, int y, int z): Point2D(x, y)
{
	this->z = z;
    setDistFrOrigin();
}
int Point3D::getZ()
{
	return z;
}
void Point3D::setZ(int z)
{
	this->z = z;
}
void Point3D::setDistFrOrigin()
{
	length = sqrt((x * x) + (y * y) + (z * z));
}