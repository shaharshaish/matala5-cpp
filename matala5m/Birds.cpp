#include "Birds.h"

Birds::Birds()
	:Animal()//set the default color to GRAY and other params to 0
{
	this->m_incubationTime = 0;
}

Birds::Birds(const char* color, int childs, float avgLifetime, float incubation)
	:Animal(color,childs,avgLifetime)//init the Birds with a given attributes
{
	this->m_incubationTime = incubation;
}

Birds::Birds(ifstream& in_file)
	:Animal(in_file)//init the Birds from a binary file
{
	in_file.read((char*)&this->m_incubationTime, sizeof(float));
}

Birds::Birds(const Birds& other)
	:Animal(other)//copy constructor
{
	*this = other;
}

Birds::~Birds()
{
}

float Birds::GetIncubationTime() const
{
	return this->m_incubationTime;
}

void Birds::saveSpecial(ofstream& out) const//save the Birds data to text file
{
	out << this->m_incubationTime << endl;
}

void Birds::LoadSpecial(ifstream& ifs)//load the Birds data from a text file
{
	ifs >> this->m_incubationTime;
	ifs.ignore();
}

void Birds::saveBinSpecial(ofstream& ofs) const//save the Birds data to a bin file
{
	ofs.write((char*)&this->m_incubationTime, sizeof(float));
}

void Birds::loadBinSpecial(ifstream& ifs)//load the Birds data from a bin file
{
	ifs.read((char*)&this->m_incubationTime, sizeof(float));
}

const Birds& Birds::operator=(const Birds& b)//active the Animal operator= and then copies the Birds data
{
	if (this != &b)
	{
		Animal* ptr = this;
		*ptr = b;
		this->m_incubationTime = b.GetIncubationTime();
	}
	return *this;
}
