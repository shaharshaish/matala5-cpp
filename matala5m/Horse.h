#ifndef HORSE_H
#define HORSE_H

#include "Mammals.h"

class Horse : public Mammals
{
public:
	Horse();//set the default color to GRAY and other params to 0
	Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type);//init the Horse with a given attributes
	Horse(ifstream& in_file);//init the Horse from a binary file
	Horse(const Horse& other);//copy constructor
	virtual ~Horse();//dtor
	
public:
	const char* GetType() const;//return the type of the horse
	virtual void saveSpecial(ofstream& out)const;//save the Horse data to text file
	virtual void LoadSpecial(ifstream& ifs);//load the Horse data from a text file
	virtual void saveBinSpecial(ofstream& ofs) const;//save the Horse data to a bin file
	virtual void loadBinSpecial(ifstream& ifs);//load the Horse data from a bin file
	virtual const Horse& operator=(const Horse& h);//active the Mammals operator= and then copies the Horse data

protected:
	char* m_type;
};

#endif // ifndef
