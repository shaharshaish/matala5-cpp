//name:shahar shaish
//id:208753095
#include "Fish.h"


Fish::Fish()
	:Animal()//set the default color to GRAY and other params to 0
{
	this->m_finCount = 0;
	this->m_gillsCount = 0;
}

Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills)
	:Animal(color,childs,avgLifetime)//init the Fish with a given attributes
{
	this->m_finCount = fin;
	this->m_gillsCount = gills;
}

Fish::Fish(ifstream& in_file)
	:Animal(in_file)//init the Fish from a binary file
{
	in_file.read((char*)&this->m_finCount, sizeof(int));
	in_file.read((char*)&this->m_gillsCount, sizeof(int));
}

Fish::Fish(const Fish& other)
	:Animal(other)//copy constructor
{
	*this = other;
}

Fish::~Fish()
{
}

int Fish::GetFinCount() const
{
	return this->m_finCount;
}

int Fish::GetGillsCount() const
{
	return this->m_gillsCount;
}

void Fish::saveSpecial(ofstream& out) const//save the Fish data to text file
{
	out << this->m_finCount << endl;
	out << this->m_gillsCount << endl;
}

void Fish::LoadSpecial(ifstream& ifs)//load the Fish data from a text file
{
	ifs >> this->m_finCount;
	ifs.ignore();
	ifs >> this->m_gillsCount;
	ifs.ignore();
}

void Fish::saveBinSpecial(ofstream& ofs) const//save the Fish data to a bin file
{
	ofs.write((char*)&this->m_finCount, sizeof(int));
	ofs.write((char*)&this->m_gillsCount, sizeof(int));
}


const Fish& Fish::operator=(const Fish& f)//active the Animal operator= and then copies the Fish data
{
	if (this != &f)
	{
		Animal* ptr = this;
		*ptr = f;
		this->m_finCount = f.GetFinCount();
		this->m_gillsCount = f.GetGillsCount();
	}
	return *this;
}
