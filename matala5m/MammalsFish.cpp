#include "MammalsFish.h"


MammalsFish::MammalsFish()
	:Mammals(),Fish()//set the default color to GRAY and other params to 0
{
}

MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills)
	:Mammals(color,childs,avgLifetime,preg,milk),Fish(color, childs, avgLifetime,fin,gills )//init the MammalsFish with a given attributes
{
}

MammalsFish::MammalsFish(ifstream& in_file)
	:Mammals(in_file),Fish(in_file)//init the MammalsFish from a binary file
{
}

MammalsFish::MammalsFish(const MammalsFish& other)
	:Mammals(other),Fish(other)//copy constructor
{
	*this = other;
}

MammalsFish::~MammalsFish()
{
}

void MammalsFish::saveSpecial(ofstream& out) const//active Mammals and Fish saveSpecial 
{
	Mammals::saveSpecial(out);
	Fish::saveSpecial(out);
}

void MammalsFish::LoadSpecial(ifstream& ifs)//active Mammals and Fish LoadSpecial 
{
	Mammals::LoadSpecial(ifs);
	Fish::LoadSpecial(ifs);
}

void MammalsFish::saveBinSpecial(ofstream& ofs) const//active Mammals and Fish saveBinSpecial 
{
	Mammals::saveBinSpecial(ofs);
	Fish::saveBinSpecial(ofs);
}

void MammalsFish::loadBinSpecial(ifstream& ifs)//active Mammals and Fish loadBinSpecial 
{
	Mammals::loadBinSpecial(ifs);
	Fish::loadBinSpecial(ifs);
}

const MammalsFish& MammalsFish::operator=(const MammalsFish& m)//active the Mammals and Fish operator= 
{
	if (this != &m)
	{
		Mammals* ptrM = this;
		*ptrM = m;
		Fish* ptrF = this;
		*ptrF = m;
	}
	return *this;
}


