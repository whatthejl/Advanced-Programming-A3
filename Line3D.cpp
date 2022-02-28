#include "Line3D.h"

ostream& operator<<(ostream& os, const Line3D& line)
{
	os << "[" << setw(4) << line.getPt1().getX() << "," << setw(5) << line.getPt1().getY() << "," << setw(5) << line.getPt1().getZ() << "]   "
		<< "[" << setw(4) << line.getPt2().getX() << "," << setw(5) << line.getPt2().getY() << "," << setw(5) << line.getPt2().getZ() << "]   "
		<< fixed << setprecision(3) << line.length << endl;
	return os;
}
bool operator==(const Line3D& line1, const Line3D& line2) //check for duplicates or same point (cannot make into line)
{
	if (line1.getPt1() == line2.getPt1() && line1.getPt2() == line2.getPt2())
        return true;
	if (line1.getPt1() == line2.getPt2() && line1.getPt2() == line2.getPt1())
        return true;
	if ((line1.getPt1() == line1.getPt2()) || (line2.getPt1() == line2.getPt2()))
	  	return true;
	return false;
}
bool operator<(const Line3D& line1, const Line3D& line2)
{
	if(line1.sortcrit == "Pt. 1")
    {
        //if (line1.getPt1() < line2.getPt1())
	  	//    return true;
		if (line1.getPt1().getX() < line2.getPt1().getX())
			return true;
		if (line1.getPt1().getX() == line2.getPt1().getX() && line1.getPt1().getY() < line2.getPt1().getY())
			return true;
		if (line1.getPt1().getX() == line2.getPt1().getX() && line1.getPt1().getY() == line2.getPt1().getY() && line1.getPt1().getZ() < line2.getPt1().getZ())
		  	return true;
	}
	else if(line1.sortcrit == "Pt. 2")
    {
        //if (line1.getPt2() < line2.getPt2())
        //    return true;
        if (line1.getPt2().getX() < line2.getPt2().getX())
			return true;
		if (line1.getPt2().getX() == line2.getPt2().getX() && line1.getPt2().getY() < line2.getPt2().getY())
			return true;
		if (line1.getPt2().getX() == line2.getPt2().getX() && line1.getPt2().getY() == line2.getPt2().getY() && line1.getPt2().getZ() < line2.getPt2().getZ())
		  	return true;
	}
	else if(line1.sortcrit == "Length")
    {
		if(line1.length < line2.length)
			return true;
    }
	return false;
}
bool operator>(const Line3D& line1, const Line3D& line2) //return true if pt1 > pt2
{
	if(line1.sortcrit == "Pt. 1")
    {
        //if (line1.getPt1() > line2.getPt1())
	  	//    return true;
		if (line1.getPt1().getX() > line2.getPt1().getX())
			return true;
		if (line1.getPt1().getX() == line2.getPt1().getX() && line1.getPt1().getY() > line2.getPt1().getY())
			return true;
		if (line1.getPt1().getX() == line2.getPt1().getX() && line1.getPt1().getY() == line2.getPt1().getY() && line1.getPt1().getZ() > line2.getPt1().getZ())
		  	return true;
	}
	else if(line1.sortcrit == "Pt. 2")
    {
        //if (line1.getPt2() > line2.getPt2())
        //    return true;
		if (line1.getPt2().getX() > line2.getPt2().getX())
			return true;
		if (line1.getPt2().getX() == line2.getPt2().getX() && line1.getPt2().getY() > line2.getPt2().getY())
			return true;
		if (line1.getPt2().getX() == line2.getPt2().getX() && line1.getPt2().getY() == line2.getPt2().getY() && line1.getPt2().getZ() > line2.getPt2().getZ())
		  	return true;
	}
	else if(line1.sortcrit == "Length")
    {
		if(line1.length > line2.length)
			return true;
	}
	return false;
}
void Line3D::setLength()
{
	int x1 = pt1.getX();
	int y1 = pt1.getY();
	int z1 = pt1.getZ();
	int x2 = pt2.getX();
	int y2 = pt2.getY();
	int z2 = pt2.getZ();
	
	length = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)) + ((z1 - z2) * (z1 - z2)));
}
Line3D::Line3D()
{
	//
}
Line3D::Line3D(Point3D pt1, Point3D pt2){
	this->pt1 = pt1;
	this->pt2 = pt2;
	setLength();
}
Point3D Line3D::getPt1() const
{
	return pt1;
}
Point3D Line3D::getPt2() const
{
	return pt2;
}
void Line3D::setPt1(Point3D pt1)
{
	this->pt1 = pt1;
}
void Line3D::setPt2(Point3D pt2)
{
	this->pt2 = pt2;
}