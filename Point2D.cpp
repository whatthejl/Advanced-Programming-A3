#include "Point2D.h"

ostream& operator<<(ostream& os, const Point2D& pt)
{
    os << "[" << setw(4) << pt.x << "," << setw(4) << pt.y << "]   " << fixed << setprecision(3) << pt.length << endl;
	return os;
}
bool operator==(const Point2D& pt1, const Point2D& pt2) //check for duplicates
{
	if (pt1.x == pt2.x && pt1.y == pt2.y)
		return true;
	return false;
}
bool operator<(const Point2D& pt1, const Point2D& pt2) //return true if pt1 < pt2
{
	if (pt1.sortcrit == "X-ordinate")
    {
		if (pt1.x < pt2.x)
			return true;
        if (pt1.x == pt2.x && pt1.y < pt2.y)
            return true;
	}
	else if (pt1.sortcrit == "Y-ordinate")
    {
		if (pt1.y < pt2.y)
			return true;
        if (pt1.y == pt2.y && pt1.x < pt2.x)
            return true;
	}
	else if (pt1.sortcrit == "Dist. Fr Origin")
    {
		if (pt1.length < pt2.length)
			return true;
	}
	return false;
}
bool operator>(const Point2D& pt1, const Point2D& pt2) //return true if pt1 > pt2
{
	if (pt1.sortcrit == "X-ordinate")
    {
		if (pt1.x > pt2.x)
			return true;
        if (pt1.x == pt2.x && pt1.y > pt2.y)
            return true;
	}
	else if (pt1.sortcrit == "Y-ordinate")
    {
		if (pt1.y > pt2.y)
			return true;
        if (pt1.y == pt2.y && pt1.x > pt2.x)
            return true;
	}
	else if (pt1.sortcrit == "Dist. Fr Origin")
    {
		if (pt1.length > pt2.length)
			return true;
	}
	return false;
}
Point2D::Point2D()
{
	x = 0;
	y = 0;
	length = 0.0;
    sortcrit = "X-ordinate";
}
Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
	setDistFrOrigin();
}
int Point2D::getX()
{
	return x;
}
int Point2D::getY()
{
	return y;
}
string Point2D::getSorting()
{
	return sortcrit;
}
double Point2D::getScalarValue()
{
	return length;
}
void Point2D::setX(int x)
{
	this->x = x;
}
void Point2D::setY(int y)
{
	this->y = y;
}
void Point2D::setSorting(string sortcrit)
{
	this->sortcrit = sortcrit;
}
void Point2D::setDistFrOrigin()
{
	length = sqrt((x * x) + (y * y));;
}