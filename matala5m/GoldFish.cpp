//name:shahar shaish
//id:208753095
#include "GoldFish.h"


GoldFish::GoldFish()
	:Animal(),MammalsFish()//set the default color to GRAY and other params to 0
{
	this->m_avgWeight = 0;
	this->m_avgLength = 0;
}

GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL)
	:Animal(color,childs, avgLifetime),MammalsFish(color,childs,avgLifetime,preg,milk,fin,gills)//init the GoldFish with a given attributes
{
	this->m_avgWeight = avgW;
	this->m_avgLength = avgL;
}

GoldFish::GoldFish(ifstream& in_file)
	:Animal(in_file),MammalsFish(in_file)//init the GoldFish from a binary file
{
	in_file.read((char*)&this->m_avgWeight, sizeof(float));
	in_file.read((char*)&this->m_avgLength, sizeof(float));
}

GoldFish::GoldFish(const GoldFish& other)
	:Animal(other),MammalsFish(other)//copy constructor
{
	*this = other;
}

GoldFish::~GoldFish()
{
}

float GoldFish::GetWeight() const
{
	return this->m_avgWeight;
}

float GoldFish::GetLength() const
{
	return this->m_avgLength;
}

void GoldFish::saveSpecial(ofstream& out) const//active MammalsFish saveSpecial and then save the GoldFish data to text file
{
	MammalsFish::saveSpecial(out);
	out << this->m_avgWeight << endl;
	out << this->m_avgLength << endl;
}

void GoldFish::LoadSpecial(ifstream& ifs)//active MammalsFish LoadSpecial and then load the GoldFish data from a text file
{
	MammalsFish::LoadSpecial(ifs);
	ifs >> this->m_avgWeight;
	ifs.ignore();
	ifs >> this->m_avgLength;
	ifs.ignore();
}

void GoldFish::saveBinSpecial(ofstream& ofs) const//active MammalsFish saveBinSpecial and then save the GoldFish data to a bin file
{
	MammalsFish::saveBinSpecial(ofs);
	ofs.write((char*)&this->m_avgWeight, sizeof(float));
	ofs.write((char*)&this->m_avgLength, sizeof(float));
}



const GoldFish& GoldFish::operator=(const GoldFish& f)//active the MammalsFish operator= and then copies the GoldFish data
{
	if (this != &f)
	{
		MammalsFish* ptr = this;
		*ptr = f;
		this->m_avgWeight = f.GetWeight();
		this->m_avgLength = f.GetLength();
	}
	return *this;
}
