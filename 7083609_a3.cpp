#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <conio.h>

#include "Point2D.h"
#include "Point3D.h"
#include "Line3D.h"
#include "Line2D.h"
#include "MyTemplates.h"

using namespace std;

string filter;
string sortcrit;
string sortorder;
bool inputfile;
vector<Point2D> point2d;
vector<Point3D> point3d;
vector<Line2D> line2d;
vector<Line3D> line3d;

vector<string> tokenizeString (string input, string delimiter)
{
	size_t pos = 0;
	string token;
	vector<string> result;

	while ((pos = input.find(delimiter)) != string::npos) 
	{
    	token = input.substr(0, pos);
    	result.push_back (token);
		input.erase(0, pos + delimiter.length());
	}
	result.push_back (input);
	return (result);
}
void safelyDeallocateMemory() //clear vectors
{
	point2d.clear();
	point3d.clear();
	line2d.clear();
	line3d.clear();
}
/*void userenter()
{
	int i = '\0';
	while (i == '\0')
	{
		cout << "\nPress any key to go back to main menu ...";
		i = getch();
	}
	cout << endl;
}*/
//make sure user press enter
void userenter()
{
	int i = 0;
	while (i == 0)
	{
		cout << "\nPress <enter> to go back to main menu...";
		cin.ignore();
		if (cin.get() == '\n')
			i = 1;
	}
	cout << endl;
}
int mainmenu() //main menu
{
    int option;
    cout << endl << "Student ID: 7083609" << endl;
    cout << "Student Name: Yong Jia Liang" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Welcome to Assn3 program!" << endl << endl;
    cout << "1) Read in data" << endl;
    cout << "2) Specify filtering criteria (current: " << filter << ")" << endl;
    cout << "3) Specify sorting criteria (current: " << sortcrit << ")" << endl;
    cout << "4) Specify sorting order (current: " << sortorder << ")" << endl;
    cout << "5) View data" << endl;
    cout << "6) Store data" << endl;
    cout << "7) Exit" << endl << endl;
    cout << "Please enter your choice: ";
    cin >> option;
    return option;
}
void option1() //read in data
{
	cout << "Please enter filename (type \"return\" to go back to main menu): ";
	string filename;
	cin >> filename;
	if (filename != "return")
	{
		ifstream myFile;
		bool checker;
		myFile.open(filename);
		if (!myFile) //error opening file
		{
			cout << "Error opening : " << filename << " . Try again." << endl << endl;
			option1();
		}
		if (myFile.is_open()) //successfully open file
		{
			string line;
			while (getline(myFile, line))
			{
				if (line.empty())
					break;
				checker = true;
				if (line.find("Point2D") != string::npos) //point 2d
				{
					vector<string> tokenStringVector = tokenizeString (line, ", [");
					vector<string> tokenStringVector2 = tokenizeString (tokenStringVector[1], ", ");
					int x = stoi(tokenStringVector2[0]);
					tokenStringVector2[1].pop_back();
					int y = stoi(tokenStringVector2[1]);
					Point2D temppoint = Point2D(x, y); //create new point
					for (int i = 0; i < point2d.size(); i++)//check for duplicates
					{
						if (equals(temppoint, point2d[i]))
							checker = false;
					}
					if (checker == true)
					{
						temppoint.setSorting(sortcrit);
						point2d.push_back(temppoint);
					}
					tokenStringVector.clear();
					tokenStringVector2.clear();
				}
				else if (line.find("Point3D") != string::npos) //point 3d
				{
					vector<string> tokenStringVector = tokenizeString (line, ", [");
					vector<string> tokenStringVector2 = tokenizeString (tokenStringVector[1], ", ");
					tokenStringVector2[2].pop_back();
					int x = stoi(tokenStringVector2[0]);
					int y = stoi(tokenStringVector2[1]);
					int z = stoi(tokenStringVector2[2]);
					Point3D temppoint = Point3D(x, y, z); //create new point
					for (int i = 0; i < point3d.size(); i++)//check for duplicates
					{
						if (equals(temppoint, point3d[i]))
							checker = false;
					}
					if (checker == true)
					{
						temppoint.setSorting(sortcrit);
						point3d.push_back(temppoint);
					}
					tokenStringVector.clear();
					tokenStringVector2.clear();
				}
				else if (line.find("Line2D") != string::npos) //line 2d
				{
					vector<string> tokenStringVector = tokenizeString (line, ", [");
					vector<string> tokenStringVector1 = tokenizeString (tokenStringVector[1], ", ");
					vector<string> tokenStringVector2 = tokenizeString (tokenStringVector[2], ", ");
					tokenStringVector1[1].pop_back();
					tokenStringVector2[1].pop_back();
					int x1 = stoi(tokenStringVector1[0]);
					int y1 = stoi(tokenStringVector1[1]);
					int x2 = stoi(tokenStringVector2[0]);
					int y2 = stoi(tokenStringVector2[1]);
					Point2D temppoint1 = Point2D(x1, y1); //create new point
					Point2D temppoint2 = Point2D(x2, y2); //create new point
					Line2D templine = Line2D(temppoint1, temppoint2);
					for (int i = 0; i < line2d.size(); i++)//check for duplicates
					{
						if (equals(templine, line2d[i]))
							checker = false;
					}
					if (checker == true)
					{
						templine.setSorting(sortcrit);
						line2d.push_back(templine);
					}
					tokenStringVector.clear();
					tokenStringVector1.clear();
					tokenStringVector2.clear();
				}
				else if (line.find("Line3D") != string::npos) //line 3d
				{
					vector<string> tokenStringVector = tokenizeString (line, ", [");
					vector<string> tokenStringVector1 = tokenizeString (tokenStringVector[1], ", ");
					vector<string> tokenStringVector2 = tokenizeString (tokenStringVector[2], ", ");
					tokenStringVector1[2].pop_back();
					tokenStringVector2[2].pop_back();
					int x1 = stoi(tokenStringVector1[0]);
					int y1 = stoi(tokenStringVector1[1]);
					int z1 = stoi(tokenStringVector1[2]);
					int x2 = stoi(tokenStringVector2[0]);
					int y2 = stoi(tokenStringVector2[1]);
					int z2 = stoi(tokenStringVector2[2]);
					Point3D temppoint1 = Point3D(x1, y1, z1); //create new point
					Point3D temppoint2 = Point3D(x2, y2, z2); //create new point
					Line3D templine = Line3D(temppoint1, temppoint2);
					for (int i = 0; i < line3d.size(); i++)//check for duplicates
					{
						if (equals(templine, line3d[i]))
							checker = false;
					}
					if (checker == true)
					{
						templine.setSorting(sortcrit);
						line3d.push_back(templine);
					}
					tokenStringVector.clear();
					tokenStringVector1.clear();
					tokenStringVector2.clear();
				}
			}
			int counter = point2d.size() + point3d.size() + line2d.size() + line3d.size();
			if (counter > 0)
				inputfile = true;
			cout << counter << " records read in successfully!" << endl << endl << "Going back to main menu ..." << endl << endl;
		}
		myFile.close(); //close file
	}
}
void option2()
{
	string option;
	while (option.empty())
	{
		cout << "[Specifying filtering criteria (current: " << filter << ")]" << endl << endl;
		cout << "\ta)\tPoint2D records" << endl;
		cout << "\tb)\tPoint3D records" << endl;
		cout << "\tc)\tLine2D records" << endl;
		cout << "\td)\tLine3D records" << endl;
		cout << "\tq)\tBack" << endl << endl;
		cout << "\tPlease enter your criteria (a-d): ";
		cin >> option;
		//lower case
		for_each(option.begin(), option.end(), [](char & c) 
		{
			c = ::tolower(c);
		});
		if (option == "a")
			filter = "Point2D";
		else if (option == "b")
			filter = "Point3D";
		else if (option == "c")
			filter = "Line2D";
		else if (option == "d")
			filter = "Line3D";
		else if (option == "q")
			cout << "\tGoing back to main menu ..." << endl << endl;
		else
		{
			cout << "\tPlease enter a valid option." << endl << endl;
			option.clear();
		}
	}
	if (option != "q") //user selection within range
	{
		if (option == "a" || option == "b")
			sortcrit = "X-ordinate";
		if (option == "c" || option == "d")
			sortcrit = "Pt. 1";
		cout << "\tFilter criteria successfully set to '" << filter << "'!" << endl << endl;
	}
}
void option3()
{
	string option;
	while (option.empty())
	{
		cout << "[Specifying sorting criteria (current: " << sortcrit << ")]" << endl << endl;
		if (filter == "Point2D")
		{
			cout << "\ta)\tX-ordinate value" << endl;
			cout << "\tb)\tY-ordinate value" << endl;
			cout << "\tc)\tDist from origin" << endl;
			cout << "\tq)\tBack" << endl << endl;
			cout << "\tPlease enter your criteria (a-c): ";
			cin >> option;
			//lower case
			for_each(option.begin(), option.end(), [](char & c)
			{
				c = ::tolower(c);
			});
			if (option == "a")
				sortcrit = "X-ordinate";
			else if (option == "b")
				sortcrit = "Y-ordinate";
			else if (option == "c")
				sortcrit = "Dist. Fr Origin";
			else if (option == "q")
				cout << "\tGoing back to main menu ..." << endl << endl;
			else
			{
				cout << "\tPlease enter a valid option." << endl << endl;
				option.clear();
			}
		}
		else if (filter == "Point3D")
		{
			cout << "\ta)\tX-ordinate value" << endl;
			cout << "\tb)\tY-ordinate value" << endl;
			cout << "\tc)\tZ-ordinate value" << endl;
			cout << "\td)\tDist from origin" << endl;
			cout << "\tq)\tBack" << endl << endl;
			cout << "\tPlease enter your criteria (a-d): ";
			cin >> option;
			//lower case
			for_each(option.begin(), option.end(), [](char & c)
			{
				c = ::tolower(c);
			});
			if (option == "a")
				sortcrit = "X-ordinate";
			else if (option == "b")
				sortcrit = "Y-ordinate";
			else if (option == "c")
				sortcrit = "Z-ordinate";
			else if (option == "d")
				sortcrit = "Dist. Fr Origin";
			else if (option == "q")
				cout << "\tGoing back to main menu ..." << endl << endl;
			else
			{
				cout << "\tPlease enter a valid option." << endl << endl;
				option.clear();
			}
		}
		else if (filter == "Line2D" || filter == "Line3D")
		{
			cout << "\ta)\tX and Y coordinate values of Pt. 1" << endl;
			cout << "\tb)\tX and Y coordinate values of Pt. 2" << endl;
			cout << "\tc)\tLength value" << endl;
			cout << "\tq)\tBack" << endl << endl;
			cout << "\tPlease enter your criteria (a-c): ";
			cin >> option;
			//lower case
			for_each(option.begin(), option.end(), [](char & c)
			{
				c = ::tolower(c);
			});
			if (option == "a")
				sortcrit = "Pt. 1";
			else if (option == "b")
				sortcrit = "Pt. 2";
			else if (option == "c")
				sortcrit = "Length";
			else if (option == "q")
				cout << "\tGoing back to main menu ..." << endl << endl;
			else
			{
				cout << "\tPlease enter a valid option." << endl << endl;
				option.clear();
			}
		}
	}
	if (option != "q") //user selection within range
		cout << "\tSorting criteria successfully set to '" << sortcrit << "'!" << endl << endl;
}
void option4()
{
	string option;
	while (option.empty())
	{
		cout << "[Specifying sorting order (current: " << sortorder << ")]" << endl;
		cout << endl;
		cout << "\ta)\tASC(Ascending order)" << endl;
		cout << "\tb)\tDSC(Descending order)" << endl;
		cout << "\tq)\tBack" << endl;
		cout << endl;
		cout << "\tPlease enter your criteria (a-b): ";
		cin >> option;
		//lower case
		for_each(option.begin(), option.end(), [](char & c)
		{
			c = ::tolower(c);
		});
		if (option == "a")
			sortorder = "ASC";
		else if (option == "b")
			sortorder = "DSC";
		else if (option == "q")
			cout << "\tGoing back to main menu ..." << endl << endl;
		else
		{
			cout << "\tPlease enter a valid option." << endl << endl;
			option.clear();
		}
	}
	if (option != "q") //user selection within range
		cout << "\tSorting order successfully set to '" << sortcrit << "'!" << endl << endl;
}
void option5()
{
	cout << "[View data ...]" << endl;
	cout << "Filtering criteria: " << filter << endl;
	cout << "Sorting criteria: " << sortcrit << endl;
	cout << "Sorting order: " << sortorder << endl << endl;
	
	if (filter == "Point2D")
	{
		if (point2d.empty())
			cout << "No Point2D found. Returning to main menu ..." << endl << endl;
		else
		{
			for (int i = 0; i < point2d.size(); i++)
				point2d[i].setSorting(sortcrit);
			
			if (sortorder == "ASC")
				sort(point2d.begin(), point2d.end(), ASC<Point2D>);
			else
				sort(point2d.begin(), point2d.end(), DSC<Point2D>);

			cout << setw(5) << "X" << setw(5) << "Y" << "    Dist. Fr Origin" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - " << endl;

			for (int i = 0; i < point2d.size(); i++)
				cout << point2d[i];
			cout << endl;
			userenter();
		}
	}
	else if (filter == "Point3D")
	{
		if (point3d.empty())
			cout << "No Point3D found. Returning to main menu ..." << endl << endl;
		else
		{
			for (int i = 0; i < point3d.size(); i++)
				point3d[i].setSorting(sortcrit);
			
			if (sortorder == "ASC")
				sort(point3d.begin(), point3d.end(), ASC<Point3D>);
			else
				sort(point3d.begin(), point3d.end(), DSC<Point3D>);

			cout << setw(5) << "X" << setw(5) << "Y" << setw(5) << "Z" << "    Dist. Fr Origin" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - " << endl;

			for (int i = 0; i < point3d.size(); i++)
				cout << point3d[i];
			cout << endl;
			userenter();
		}
	}
	else if (filter == "Line2D")
	{
		if (line2d.empty())
			cout << "No Line2D found. Returning to main menu ..." << endl << endl;
		else
		{
			for (int i = 0; i < line2d.size(); i++)
				line2d[i].setSorting(sortcrit);
			
			if (sortorder == "ASC")
				sort(line2d.begin(), line2d.end(), ASC<Line2D>);
			else
				sort(line2d.begin(), line2d.end(), DSC<Line2D>);

			cout << setw(5) << "P1-X" << setw(5) << "P1-Y" << setw(9) << "P2-X" << setw(5) << "P2-Y" << "    Length" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - " << endl;

			for (int i = 0; i < line2d.size(); i++)
				cout << line2d[i];
			cout << endl;
			userenter();
		}
	}
	else if (filter == "Line3D")
	{
		if (line3d.empty())
			cout << "No Line3D found. Returning to main menu ..." << endl << endl;
		else
		{
			for (int i = 0; i < line3d.size(); i++)
				line3d[i].setSorting(sortcrit);
			
			if (sortorder == "ASC")
				sort(line3d.begin(), line3d.end(), ASC<Line3D>);
			else
				sort(line3d.begin(), line3d.end(), DSC<Line3D>);

			cout << setw(5) << "P1-X" << setw(5) << "P1-Y" << setw(5) << "P1-Z" 
				<< setw(9) << "P2-X" << setw(5) << "P2-Y" << setw(5) << "P2-Z" << "    Length" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

			for (int i = 0; i < line3d.size(); i++)
				cout << line3d[i];
			cout << endl;
			userenter();
		}
	}
}
void option6()
{
	int counter = 0;
	string filename;
	cout << "Please enter filename: ";
	cin >> filename;
	ofstream myFile(filename.c_str());
	if (!myFile)
	{
		cout << "Error creating " << filename << ". Try again. " << endl;
	}
	else if (filter == "Point2D")
	{
		if (point2d.empty())
			myFile << "No Point2D found.";
		else
		{
			for (int i = 0; i < point2d.size(); i++)
				point2d[i].setSorting(sortcrit);
			
			if (sortorder == "ASC")
				sort(point2d.begin(), point2d.end(), ASC<Point2D>);
			else
				sort(point2d.begin(), point2d.end(), DSC<Point2D>);

			myFile << setw(5) << "X" << setw(6) << "Y" << "    Dist. Fr Origin\n";
			myFile << "- - - - - - - - - - - - - - - - - - - \n";

			for (int i = 0; i < point2d.size(); i++)
			{
				myFile << point2d[i];
				counter++;
			}
		}
	}
	else if (filter == "Point3D")
	{
		if (point3d.empty())
			myFile << "No Point3D found.";
		else
		{
			for (int i = 0; i < point3d.size(); i++)
				point3d[i].setSorting(sortcrit);
			
			if (sortorder == "ASC")
				sort(point3d.begin(), point3d.end(), ASC<Point3D>);
			else
				sort(point3d.begin(), point3d.end(), DSC<Point3D>);

			myFile << setw(5) << "X" << setw(5) << "Y" << setw(6) << "Z" << "    Dist. Fr Origin\n";
			myFile << "- - - - - - - - - - - - - - - - - - - \n";

			for (int i = 0; i < point3d.size(); i++)
			{
				myFile << point3d[i];
				counter++;
			}
		}
	}
	else if (filter == "Line2D")
	{
		if (line2d.empty())
			myFile << "No Line2D found.";
		else
		{
			for (int i = 0; i < line2d.size(); i++)
				line2d[i].setSorting(sortcrit);
			
			if (sortorder == "ASC")
				sort(line2d.begin(), line2d.end(), ASC<Line2D>);
			else
				sort(line2d.begin(), line2d.end(), DSC<Line2D>);

			myFile << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(9) << "P2-X" << setw(6) << "P2-Y" << "    Length\n";
			myFile << "- - - - - - - - - - - - - - - - - - - \n";

			for (int i = 0; i < line2d.size(); i++)
			{
				myFile << line2d[i];
				counter++;
			}
		}
	}
	else if (filter == "Line3D")
	{
		if (line3d.empty())
			myFile << "No Line3D found.";
		else
		{
			for (int i = 0; i < line3d.size(); i++)
				line3d[i].setSorting(sortcrit);
			
			if (sortorder == "ASC")
				sort(line3d.begin(), line3d.end(), ASC<Line3D>);
			else
				sort(line3d.begin(), line3d.end(), DSC<Line3D>);

			myFile << setw(5) << "P1-X" << setw(6) << "P1-Y" << setw(6) << "P1-Z" 
				<< setw(9) << "P2-X" << setw(6) << "P2-Y" << setw(6) << "P2-Z" << "    Length\n";
			myFile << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

			for (int i = 0; i < line3d.size(); i++)
			{
				myFile << line3d[i];
				counter++;
			}
		}
	}
	myFile.close();
	cout << counter << " records output successfully!" << endl << endl;
	cout << "Going back to main menu ..." << endl;
}
int main()
{
    int checkexit = '\0';
	string fileName;
	filter = "Point2D"; // default order
	sortcrit = "X-ordinate"; // default order
	sortorder = "ASC"; // default order
    inputfile = false; //check if file has been uploaded
	while (checkexit == '\0')
    {
        int option = mainmenu();
        if (option == 7) //exit program
        {
            cout << "Exiting application." << endl;
			safelyDeallocateMemory();
			checkexit = 1;
        }
        else if (7 < option || option < 1) //user enter out of range
		{
			cout << endl << "Please select an option 1 - 7. ";
		}
        else if (inputfile == false && option != 1) //user select sort/view/output without uploading
		{
			cout << endl << "No file detected. Please input file.";
			userenter();
		}
        else
		{
            switch (option)
			{
				case 1:
					cout << endl << "You have selected option 1" << endl << endl;
					option1();
					break;
				case 2:
					cout << endl << "You have selected option 2" << endl << endl;
					option2();
					break;
				case 3:
					cout << endl << "You have selected option 3" << endl << endl;
					option3();
					break;
				case 4:
					cout << endl << "You have selected option 4" << endl << endl;
					option4();
					break;
				case 5:
					cout << endl << "You have selected option 5" << endl << endl;
					option5();
					break;
				case 6:
					cout << endl << "You have selected option 6" << endl << endl;
					option6();
					break;
				default: 
					cout << endl << "Please select an option 1 - 8. " << endl << endl;
			}
		}
	}
    return 0;
}