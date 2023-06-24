#include "Flamingo.h"


Flamingo::Flamingo()
	:Birds()//set the default color to GRAY and other params to 0
{
	this->m_avgHeight = 0;
}

Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight)
	:Birds(color,childs,avgLifetime,incubation)//init the Flamingo with a given attributes
{
	this->m_avgHeight = avgHeight;
}

Flamingo::Flamingo(ifstream& in_file)
	:Birds(in_file)//init the Flamingo from a binary file
{
	in_file.read((char*)&this->m_avgHeight, sizeof(float));
}

Flamingo::Flamingo(const Flamingo& other)
	:Birds(other)//copy constructor
{
	*this = other;
}

Flamingo::~Flamingo()
{
}

float Flamingo::GetHeight() const
{
	return this->m_avgHeight;
}

void Flamingo::saveSpecial(ofstream& out) const//active Birds saveSpecial and then save the Flamingo data to text file
{
	Birds::saveSpecial(out);
	out << this->m_avgHeight << endl;
}

void Flamingo::LoadSpecial(ifstream& ifs)//active Birds LoadSpecial and then load the Flamingo data from a text file
{
	Birds::LoadSpecial(ifs);
	ifs >> this->m_avgHeight;
	ifs.ignore();
}

void Flamingo::saveBinSpecial(ofstream& ofs) const//active Birds saveBinSpecial and then save the Flamingo data to a bin file
{
	Birds::saveBinSpecial(ofs);
	ofs.write((char*)&this->m_avgHeight, sizeof(float));
}

void Flamingo::loadBinSpecial(ifstream& ifs)//active Birds loadBinSpecial then load the Flamingo data from a bin file
{
	Birds::loadBinSpecial(ifs);
	ifs.read((char*)&this->m_avgHeight, sizeof(float));
}

const Flamingo& Flamingo::operator=(const Flamingo& f)//active the Birds operator= and then copies the Flamingo data
{
	if (this != &f)
	{
		Birds* ptr = this;
		*ptr = f;
		this->m_avgHeight = f.GetHeight();
	}
	return *this;
}
