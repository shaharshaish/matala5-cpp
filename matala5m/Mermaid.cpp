#include "Mermaid.h"


Mermaid::Mermaid()
	:Animal(),MammalsFish()//set the default color to GRAY and other params to 0
{
	this->m_firstName = NULL;
	this->m_lastName = NULL;
}

Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName)
	:Animal(color, childs, avgLifetime), MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)//init the Mermaid with a given attributes
{
	this->m_firstName = new char[strlen(firstName) + 1];
	strcpy(this->m_firstName, firstName);
	this->m_lastName = new char[strlen(lastName) + 1];
	strcpy(this->m_lastName, lastName);
}

Mermaid::Mermaid(ifstream& in_file)
	:Animal(in_file),MammalsFish(in_file)//init the Mermaid from a binary file
{
	int firstLen;
	int lastLen;
	in_file.read((char*)&firstLen, sizeof(int));
	this->m_firstName = new char[firstLen + 1];
	in_file.read(this->m_firstName, firstLen);
	this->m_firstName[firstLen] = '\0';

	in_file.read((char*)&lastLen, sizeof(int));
	this->m_lastName = new char[lastLen + 1];
	in_file.read(this->m_lastName, lastLen);
	this->m_lastName[lastLen] = '\0';
}

Mermaid::Mermaid(const Mermaid& other)
	:Animal(other),MammalsFish(other)//copy constructor
{
	this->m_firstName = NULL;
	this->m_lastName = NULL;
	*this = other;
}

Mermaid::~Mermaid()//dtor
{
	delete[] this->m_firstName;
	delete[] this->m_lastName;
}

const char* Mermaid::GetFirstName() const
{
	return this->m_firstName;
}

const char* Mermaid::GetLastName() const
{
	return this->m_lastName;
}

void Mermaid::saveSpecial(ofstream& out) const//active MammalsFish saveSpecial and then save the Mermaid data to text file
{
	MammalsFish::saveSpecial(out);
	out << strlen(this->m_firstName) << endl;
	out << this->m_firstName << endl;
	out << strlen(this->m_lastName) << endl;
	out << this->m_lastName << endl;
}

void Mermaid::LoadSpecial(ifstream& ifs)//active MammalsFish LoadSpecial and then load the Mermaid data from a text file
{
	MammalsFish::LoadSpecial(ifs);
	int len = 0;
	ifs >> len;
	ifs.ignore();
	this->m_firstName = new char[len + 1];
	ifs.getline(this->m_firstName, len + 1);

	ifs >> len;
	ifs.ignore();
	this->m_lastName = new char[len + 1];
	ifs.getline(this->m_lastName, len + 1);
}

void Mermaid::saveBinSpecial(ofstream& ofs) const//active MammalsFish saveBinSpecial and then save the Mermaid data to a bin file
{
	MammalsFish::saveBinSpecial(ofs);
	int len = 0;
	len = strlen(this->m_firstName);
	ofs.write((char*)&len, sizeof(int));
	ofs.write(this->m_firstName, len);

	len = strlen(this->m_lastName);
	ofs.write((char*)&len, sizeof(int));
	ofs.write(this->m_lastName, len);
}

void Mermaid::loadBinSpecial(ifstream& ifs)//active MammalsFish loadBinSpecial then load the Mermaid data from a bin file
{
	MammalsFish::loadBinSpecial(ifs);
	int len;
	ifs.read((char*)&len, sizeof(len));
	this->m_firstName = new char[len + 1];
	ifs.read(this->m_firstName, len);
	this->m_firstName[len] = '\0';

	ifs.read((char*)&len, sizeof(len));
	this->m_lastName = new char[len + 1];
	ifs.read(this->m_lastName, len);
	this->m_lastName[len] = '\0';

}

const Mermaid& Mermaid::operator=(const Mermaid& m)//active the MammalsFish operator= and then copies the Mermaid data
{
	if (this != &m)
	{
		int len = 0;
		MammalsFish* ptr = this;
		*ptr = m;
		delete[] this->m_firstName;
		delete[] this->m_lastName;
		len = strlen(m.GetFirstName()) + 1;
		this->m_firstName = new char[len];
		strcpy(this->m_firstName, m.GetFirstName());

		len = strlen(m.GetLastName()) + 1;
		this->m_lastName = new char[len];
		strcpy(this->m_lastName, m.GetLastName());
	}
	return *this;
}
