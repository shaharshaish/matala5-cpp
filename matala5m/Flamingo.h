//name:shahar shaish
//id:208753095
#ifndef FLAMINGO_H
#define FLAMINGO_H

#include "Birds.h"

class Flamingo : public Birds
{
public:
	Flamingo();//set the default color to GRAY and other params to 0
	Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight);//init the Flamingo with a given attributes
	Flamingo(ifstream& in_file);//init the Flamingo from a binary file
	Flamingo(const Flamingo& other);//copy constructor
	virtual ~Flamingo();//dtor

public:
	float		GetHeight() const;//return the avg height of the flamingo
	virtual void saveSpecial(ofstream& out)const;//save the Flamingo data to text file
	virtual void LoadSpecial(ifstream& ifs);//load the Flamingo data from a text file
	virtual void saveBinSpecial(ofstream& ofs) const;//save the Flamingo data to a bin file
	
	virtual const Flamingo& operator=(const Flamingo& f);//active the Birds operator= and then copies the Flamingo data

protected:
	float m_avgHeight;
};

#endif // ifndef
