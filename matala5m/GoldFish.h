//name:shahar shaish
//id:208753095
#ifndef GOLDFISH_H
#define GOLDFISH_H

#include "MammalsFish.h"

class GoldFish : public MammalsFish
{
public:
	GoldFish();//set the default color to GRAY and other params to 0
	GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL);//init the GoldFish with a given attributes
	GoldFish(ifstream& in_file);//init the GoldFish from a binary file
	GoldFish(const GoldFish& other);//copy constructor
	virtual ~GoldFish();//dtor

public:
	float		GetWeight() const;//return the avg weight of the gold fish
	float		GetLength() const;//return the avg length of the gold fish
	virtual void saveSpecial(ofstream& out)const;//save the GoldFish data to text file
	virtual void LoadSpecial(ifstream& ifs);//load the GoldFish data from a text file
	virtual void saveBinSpecial(ofstream& ofs) const;//save the GoldFish data to a bin file
	
	virtual const GoldFish& operator=(const GoldFish& f);//active the MammalsFish operator= and then copies the GoldFish data

protected:
	float m_avgWeight;
	float m_avgLength;
};

#endif // ifndef
