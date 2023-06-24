#ifndef MAMMALSFISH_H
#define MAMMALSFISH_H

#include "Mammals.h"
#include "Fish.h"

class MammalsFish : public Mammals, public Fish
{
public:
	MammalsFish();//set the default color to GRAY and other params to 0
	MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills);//init the MammalsFish with a given attributes
	MammalsFish(ifstream& in_file);//init the MammalsFish from a binary file
	MammalsFish(const MammalsFish& other);//copy constructor
	virtual ~MammalsFish();//dtor

public:
	virtual void saveSpecial(ofstream& out)const;//save the MammalsFish data to text file
	virtual void LoadSpecial(ifstream& ifs);//load the MammalsFish data from a text file
	virtual void saveBinSpecial(ofstream& ofs) const;//save the MammalsFish data to a bin file
	virtual void loadBinSpecial(ifstream& ifs);//load the MammalsFish data from a bin file
	virtual const MammalsFish& operator=(const MammalsFish& m);//active the Mammals and Fish operator= and then copies the MammalsFish data
};

#endif // ifndef
