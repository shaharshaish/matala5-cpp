//name:shahar shaish
//id:208753095
#include "Animal.h"

Animal::Animal()//animal ctor thats sets the color "GRAY" and others to 0
{
	const char tmpColor[] = "GRAY";
	this->m_color = new char[5];
	strcpy(this->m_color, tmpColor);
	this->m_avgLifetime = 0;
	this->m_childCount = 0;
}

Animal::Animal(const char* color, int childs, float avgLifetime)//animal ctor thats sets the color, childs and average life time 
{
	int colorNameLen = strlen(color);
	this->m_color = new char[colorNameLen + 1];
	strcpy(this->m_color, color);
	this->m_childCount = childs;
	this->m_avgLifetime = avgLifetime;
}

Animal::Animal(ifstream& in_file)//init the Animal from a binary file
{
	int colorLen;
	in_file.read((char*)&colorLen, sizeof(int));
	this->m_color = new char[colorLen + 1];
	in_file.read(this->m_color, colorLen);
	this->m_color[colorLen] = '\0';
	in_file.read((char*)&this->m_avgLifetime, sizeof(float));
	in_file.read((char*)&this->m_childCount, sizeof(int));
}

Animal::Animal(const Animal& other)//copy constructor
{
	this->m_color = NULL;
	*this = other;
}

Animal::~Animal()//dtor
{
	delete[] this->m_color;
}

const char* Animal::GetColor() const
{
	return this->m_color;
}

int	Animal::GetChildCount() const
{
	return this->m_childCount;
}

float Animal::GetLifetime() const
{
	return this->m_avgLifetime;
}

void Animal::save(ofstream& out) const//write the animal data to text file 
{
	out << strlen(typeForDebug(typeid(*this).name())) << endl;
	out << typeForDebug(typeid(*this).name()) << endl;
	out << strlen(this->GetColor()) << endl;
	out << this->GetColor() << endl;
	out << this->GetLifetime() << endl;
	out << this->GetChildCount() << endl;
	this->saveSpecial(out);//sends by inheritance to child to save his data to the file
}

void Animal::saveBin(ofstream& ofs) const//write the animal data to bin file
{
	int len = 0;
	char type[2];
	strncpy(type, typeForDebug(typeid(*this).name()), 2);
	ofs.write((char*)type, 2);

	len = strlen(this->m_color);
	ofs.write((char*)&len, sizeof(int));
	ofs.write(this->m_color, len);

	ofs.write((char*)&this->m_avgLifetime, sizeof(float));

	ofs.write((char*)&this->m_childCount, sizeof(int));
	this->saveBinSpecial(ofs);//sends by inheritance to child to save his data to the file
}

void Animal::Load(ifstream& ifs)//load the data of the animal from a text file
{
	int len = 0;
	ifs >> len;
	ifs.ignore();
	this->m_color = new char[len + 1];
	ifs.getline(this->m_color, len + 1);
	ifs >> this->m_avgLifetime;
	ifs.ignore();
	ifs >> this->m_childCount;
	ifs.ignore();
	this->LoadSpecial(ifs);//send by inheritance to child to load his data from text file
}




const Animal& Animal::operator=(const Animal& a)//copy the animal data
{
	if (this != &a)
	{
		int colorSize = strlen(a.GetColor()) + 1;
		delete[] this->m_color;
		this->m_color = new char[colorSize];
		strcpy(this->m_color, a.GetColor());
		this->m_childCount = a.GetChildCount();
		this->m_avgLifetime = a.GetLifetime();
	}
	return *this;
}

char* typeForDebug(const char* type)
{
	if ('0' <= type[0] && type[0] <= '9')
		return (char*)(type + 1);

	return (char*)(type + 6);
}
