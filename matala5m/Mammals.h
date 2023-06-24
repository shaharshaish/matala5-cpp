#ifndef MAMMALS_H
#define MAMMALS_H

#include "Animal.h"

class Mammals :virtual public Animal
{
public:
	Mammals();//set the default color to GRAY and other params to 0
	Mammals(const char* color, int childs, float avgLifetime, float preg, float milk);//init the Mammals with a given attributes
	Mammals(ifstream& in_file);//init the Mammals from a binary file
	Mammals(const Mammals& other);//copy constructor
	virtual ~Mammals();//dtor

public:
	float		GetPregnanceTime() const;//return the pregnance time of the animal
	float		GetMilk() const;//return the milk liters of the animal
	virtual void saveSpecial(ofstream& out)const;//save the Mammals data to text file
	virtual void LoadSpecial(ifstream& ifs);//load the Mammals data from a text file
	virtual void saveBinSpecial(ofstream& ofs) const;//save the Mammals data to a bin file
	virtual void loadBinSpecial(ifstream& ifs);//load the Mammals data from a bin file
	virtual const Mammals& operator=(const Mammals& m);//active the Animal operator= and then copies the Mammals data

	

protected:
	float m_pregnancyTime;
	float m_milkLiters;
};

#endif // ifndef
