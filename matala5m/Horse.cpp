//name:shahar shaish
//id:208753095
#include "Horse.h"

Horse::Horse():Animal(),Mammals()//set the default color to GRAY and other params to 0
{
	this->m_type = NULL;
}

Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type)
	:Animal(color,childs,avgLifetime),Mammals(color,childs,avgLifetime,preg,milk)//init the Horse with a given attributes
{
	int len = strlen(type);
	this->m_type = new char[len + 1];
	strcpy(this->m_type, type);
}

Horse::Horse(ifstream& in_file)
	:Animal(in_file),Mammals(in_file)//init the Horse from a binary file
{
	int len;
	in_file.read((char*)&len, sizeof(len));
	this->m_type = new char[len + 1];
	in_file.read(this->m_type, len);
	this->m_type[len] = '\0';
}

Horse::Horse(const Horse& other)
	:Animal(other),Mammals(other)//copy constructor
{
	this->m_type = NULL;
	*this = other;
}

Horse::~Horse()//dtor
{
	delete[] this->m_type;
}

const char* Horse::GetType() const
{
	return this->m_type;
}

void Horse::saveSpecial(ofstream& out) const//active Mammals saveSpecial and then save the Horse data to text file
{
	Mammals::saveSpecial(out);
	out << strlen(this->m_type) << endl;
	out << this->m_type << endl;
}

void Horse::LoadSpecial(ifstream& ifs)//active Mammals LoadSpecial and then load the Horse data from a text file
{
	Mammals::LoadSpecial(ifs);
	int len = 0;
	ifs >> len;
	ifs.ignore();
	this->m_type = new char[len + 1];
	ifs.getline(this->m_type, len + 1);

}
void Horse::saveBinSpecial(ofstream& ofs) const//active Mammals saveBinSpecial and then save the Horse data to a bin file
{
	Mammals::saveBinSpecial(ofs);
	int len = 0;
	len = strlen(this->m_type);
	ofs.write((char*)&len, sizeof(int));
	ofs.write(this->m_type, len);
}



const Horse& Horse::operator=(const Horse& h)//active the Mammals operator= and then copies the Horse data
{
	if (this != &h)
	{
		Mammals* ptr = this;
		*ptr = h;
		int typeLen = strlen(h.GetType()) + 1;
		delete[] this->m_type;
		this->m_type = new char[typeLen];
		strcpy(this->m_type, h.GetType());
	}
	return *this;
}


