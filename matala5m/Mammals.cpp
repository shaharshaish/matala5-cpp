//name:shahar shaish
//id:208753095
#include "Mammals.h"

Mammals::Mammals()
	:Animal()//set the default color to GRAY and other params to 0
{
	this->m_pregnancyTime = 0;
	this->m_milkLiters = 0;	
}

Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk)
	:Animal(color, childs, avgLifetime)//init the Mammals with a given attributes
{
	this->m_pregnancyTime = preg;
	this->m_milkLiters = milk;
}

Mammals::Mammals(ifstream& in_file)
	:Animal(in_file)//init the Mammals from a binary file
{
	in_file.read((char*)&this->m_pregnancyTime, sizeof(float));
	in_file.read((char*)&this->m_milkLiters, sizeof(float));
}

Mammals::Mammals(const Mammals& other)
	:Animal(other)//copy constructor
{
	*this = other;
}

Mammals::~Mammals()
{
}

float Mammals::GetPregnanceTime() const
{
	return this->m_pregnancyTime;
}

float Mammals::GetMilk() const
{
	return this->m_milkLiters;
}

void Mammals::saveSpecial(ofstream& out) const//save the Mammals data to text file
{
	out << this->m_pregnancyTime << endl;
	out << this->m_milkLiters << endl;

}

void Mammals::LoadSpecial(ifstream& ifs)//load the Mammals data from a text file
{
	ifs >> this->m_pregnancyTime;
	ifs.ignore();
	ifs >> this->m_milkLiters;
	ifs.ignore();
}

void Mammals::saveBinSpecial(ofstream& ofs) const//save the Mammals data to a bin file
{
	ofs.write((char*)&this->m_pregnancyTime, sizeof(float));
	ofs.write((char*)&this->m_milkLiters, sizeof(float));
}



const Mammals& Mammals::operator=(const Mammals& m)//active the Animal operator= and then copies the Mammals data
{
	if (this != &m)
	{
		Animal* ptr = this;
		*ptr = m;
		this->m_pregnancyTime = m.GetPregnanceTime();
		this->m_milkLiters = m.GetMilk();
	}
	return *this;
}
