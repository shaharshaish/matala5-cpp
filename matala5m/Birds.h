 #ifndef BIRDS_H
#define BIRDS_H

#include "Animal.h"

class Birds : public Animal
{
public:
	Birds();//set the default color to GRAY and other params to 0
	Birds(const char* color, int childs, float avgLifetime, float incubation);//init the Birds with a given attributes
	Birds(ifstream& in_file);//init the Birds from a binary file
	Birds(const Birds& other);//copy constructor
	virtual ~Birds();//dtor

public:
	float		GetIncubationTime() const;//return the incubation time of the animal
	virtual void saveSpecial(ofstream& out)const;//save the Birds data to text file
	virtual void LoadSpecial(ifstream& ifs);//load the Birds data from a text file
	virtual void saveBinSpecial(ofstream& ofs) const;//save the Birds data to a bin file
	virtual void loadBinSpecial(ifstream& ifs);//load the Birds data from a bin file
	virtual const Birds& operator=(const Birds& b);//active the Animal operator= and then copies the Birds data

protected:
	float m_incubationTime;
};

#endif // ifndef
