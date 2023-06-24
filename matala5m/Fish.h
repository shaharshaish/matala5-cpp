#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : virtual public Animal
{
public:
	Fish();//set the default color to GRAY and other params to 0
	Fish(const char* color, int childs, float avgLifetime, int fin, int gills);//init the Fish with a given attributes
	Fish(ifstream& in_file);//init the Fish from a binary file
	Fish(const Fish& other);//copy constructor
	virtual ~Fish();//dtor

public:
	int		GetFinCount() const;//return the fin count of the animal
	int		GetGillsCount() const;//return the gills count of the animal
	virtual void saveSpecial(ofstream& out)const;//save the Fish data to text file
	virtual void LoadSpecial(ifstream& ifs);//load the Fish data from a text file
	virtual void saveBinSpecial(ofstream& ofs) const;//save the Fish data to a bin file
	virtual void loadBinSpecial(ifstream& ifs);//load the Fish data from a bin file
	virtual const Fish& operator=(const Fish& f);//active the Animal operator= and then copies the Fish data

protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef
