#ifndef ANIMAL_H
#define ANIMAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>
#include <string.h>

using namespace std;

class Animal
{
protected:
	Animal();//set the default color to GRAY and other params to 0
	Animal(const char* color, int childs, float avgLifetime);//init the Animal with a given attributes
	Animal(ifstream& in_file);//init the Animal from a binary file
	Animal(const Animal& other);//copy constructor

public:
	virtual ~Animal();//dtor
	
public:
	const char* GetColor() const;//return the color of the animal
	int			GetChildCount() const;//return the child count of the animal
	float		GetLifetime() const;//return the life time of the animal
	void save(ofstream& out)const;//write the animal data to text file 
	virtual void saveSpecial(ofstream& out)const = 0;//childs function thats provides their data and write to a text file
	void saveBin(ofstream& ofs) const;//write the animal data to bin file
	virtual void saveBinSpecial(ofstream& ofs) const=0;//childs function thats provides their data and write to a bin file
	virtual const Animal& operator=(const Animal& a);//copy the animal data
	void Load(ifstream& ifs);//load the data of the animal from a text file
	virtual void LoadSpecial(ifstream& ifs) = 0;//childs function that loads child data from a text file
	void loadBin(ifstream& ifs);//load the data of the animal from a bin file
	virtual void loadBinSpecial(ifstream& ifs) = 0;//childs function that loads child data from a bin file
	
protected:
	char* m_color;
	int		m_childCount;
	float	m_avgLifetime;
};

#endif // ifndef