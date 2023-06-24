#include "Zoo.h"

Zoo::Zoo() // zoo default ctor
{
	this->m_name = NULL;
	this->m_address = NULL;
	this->m_ticketPrice = 0;
	this->m_openHours = NULL;
	this->m_closeHours = NULL;
	this->m_numOfAnimals = 0;
	this->m_animals = NULL;
}

Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close) //zoo ctor that gets info exept number of animals and animals* list
{
	int nameLen = strlen(name);
	int addressLen = strlen(address);
	int openLen = strlen(open);
	int closeLen = strlen(close);

	this->m_name = new char[nameLen + 1];
	strcpy(this->m_name, name);
	this->m_address = new char[addressLen + 1];
	strcpy(this->m_address, address);
	this->m_openHours = new char[openLen + 1];
	strcpy(this->m_openHours, open);
	this->m_closeHours = new char[closeLen + 1];
	strcpy(this->m_closeHours, close);
	this->m_ticketPrice = ticket;

	this->m_numOfAnimals = 0;
	this->m_animals = NULL;
}

Zoo::Zoo(ifstream& in_file)//c'tor that gets a binary file and loads the data of the zoo from the file
{
	int len = 0;
	int numberOfAnimals = 0;
	char type[2];
	in_file.read((char*)&len, sizeof(int));
	this->m_name = new char[len + 1];
	in_file.read(this->m_name, len);
	this->m_name[len] = '\0';

	in_file.read((char*)&len, sizeof(int));
	this->m_address = new char[len + 1];
	in_file.read(this->m_address, len);
	this->m_address[len] = '\0';

	in_file.read((char*)&this->m_ticketPrice, sizeof(float));

	in_file.read((char*)&len, sizeof(int));
	this->m_openHours = new char[len + 1];
	in_file.read(this->m_openHours, len);
	this->m_openHours[len] = '\0';

	in_file.read((char*)&len, sizeof(int));
	this->m_closeHours = new char[len + 1];
	in_file.read(this->m_closeHours, len);
	this->m_closeHours[len] = '\0';

	in_file.read((char*)&this->m_numOfAnimals, sizeof(int));
	this->m_animals = new Animal* [numberOfAnimals];

	for (int i = 0; i < numberOfAnimals; i++)//reads the type of the animal and creats the new animal(ifstream ctor)
	{
		in_file.read(type, 2 * sizeof(char));
		if (!strncmp(type, "Horse", 2))
		{
			m_animals[i] = new Horse(in_file);
		}
		else if (!strncmp(type, "Flamingo", 2))
		{
			m_animals[i] = new Flamingo(in_file);
		}
		else if (!strncmp(type, "GoldFish", 2))
		{
			m_animals[i] = new GoldFish(in_file);
		}
		else if (!strncmp(type, "Mermaid", 2))
		{
			m_animals[i] = new Mermaid(in_file);
		}

	}


}

Zoo::Zoo(const Zoo& other)//c'ctor
{
	this->m_name = NULL;
	this->m_address = NULL;
	this->m_openHours = NULL;
	this->m_closeHours = NULL;
	this->m_animals = NULL;
	*this = other;
}

Zoo::~Zoo()//zoo dtor
{
	delete[] this->m_name;
	delete[] this->m_address;
	delete[] this->m_openHours;
	delete[] this->m_closeHours;

	delete[] this->m_animals;
}

const char* Zoo::GetName() const
{
	return this->m_name;
}

const char* Zoo::GetAddress() const
{
	return this->m_address;
}

float Zoo::GetTicketPrice() const
{
	return this->m_ticketPrice;
}

const char* Zoo::GetOpenHour() const
{
	return this->m_openHours;
}

const char* Zoo::GetCloseHour() const
{
	return this->m_closeHours;
}

int Zoo::GetNumOfAnimals() const
{
	return this->m_numOfAnimals;
}

Animal** Zoo::GetAnimals() const
{
	return this->m_animals;
}

void Zoo::AddAnimal(Animal* an)//creates a copy of "an" (deep copy) and adds an animal to the array
{
	this->m_numOfAnimals++;
	int size = this->m_numOfAnimals;
	if (size == 1)//chekcs if this is the first animal
	{
		this->m_animals = new Animal*;
	}
	else{
	Animal** tmpArr = new Animal * [size];//copys the old animal array
	for (int i = 0; i < size-1; i++)
	{
		tmpArr[i] = this->m_animals[i];
	}
	delete[] this->m_animals;
	this->m_animals = tmpArr;
	}
	//checking the animal type and by the type create deep copy of the new animal
	if (typeid(*an) == typeid(Horse))
	{
		this->m_animals[size-1] = new Horse(*(dynamic_cast<const Horse*>(an)));
	}
	else if (typeid(*an) == typeid(Flamingo))
	{
		this->m_animals[size - 1] = new Flamingo(*(dynamic_cast<const Flamingo*>(an)));
	}
	else if (typeid(*an) == typeid(Mermaid))
	{
		this->m_animals[size - 1] = new Mermaid(*(dynamic_cast<const Mermaid*>(an)));
	}
	else if (typeid(*an) == typeid(GoldFish))
	{
		this->m_animals[size - 1] = new GoldFish(*(dynamic_cast<const GoldFish*>(an)));
	}
	
}

Zoo& Zoo::operator+(Animal* an)//adds an animal (only pointer, no copy needed) to the class and returns this with the change
{
	int size = this->m_numOfAnimals + 1;
	this->m_numOfAnimals++;
	Animal** tmpArr = new Animal * [size];
	for (int i = 0; i < size - 1; i++)//copy the old animal array
	{
		tmpArr[i] = this->m_animals[i];
	}
	tmpArr[size - 1] = an;
	delete[] this->m_animals;
	this->m_animals = tmpArr;
	return *this;
}

Zoo Zoo::operator+(const Zoo& other) const//returns a new Zoo with the properties of this and animals of this and other (need to deep copy the data of other)
{
	Zoo newZoo(*this);//copys the (this) zoo data to new zoo object
	for (int i = 0; i < other.GetNumOfAnimals(); i++)//adding the animals from the other animal**
	{
		newZoo.AddAnimal(other.GetAnimals()[i]);
	}
	return newZoo;
}

Zoo& Zoo::operator+=(Animal* an)//adds new animal to the zoo
{
	*this + an;//using the + operator to add the new animal
	return *this;
}


const Zoo& Zoo::operator=(const Zoo& z)//operator = to copy all the zoo data
{
	if (this != &z)
	{
		int nameLen = strlen(z.GetName());
		int addressLen = strlen(z.GetAddress());
		int openLen = strlen(z.GetOpenHour());
		int closeLen = strlen(z.GetCloseHour());
		int animalNum = z.GetNumOfAnimals();

		delete[] this->m_name;
		delete[] this->m_address;
		delete[] this->m_openHours;
		delete[] this->m_closeHours;
		delete[] this->m_animals;
		this->m_name = new char[nameLen + 1];
		strcpy(this->m_name, z.GetName());
		this->m_address = new char[addressLen + 1];
		strcpy(this->m_address, z.GetAddress());
		this->m_openHours = new char[openLen + 1];
		strcpy(this->m_openHours, z.GetOpenHour());
		this->m_closeHours = new char[closeLen + 1];
		strcpy(this->m_closeHours, z.GetCloseHour());
		this->m_ticketPrice = z.GetTicketPrice();
		this->m_numOfAnimals = z.GetNumOfAnimals();

		this->m_animals = new Animal * [animalNum];
		for (int i = 0; i < z.GetNumOfAnimals(); i++)//checks for the animal type and by that sending to copy constructor of the animal type
		{
			if (typeid(*(z.GetAnimals()[i])) == typeid(Horse))
			{ 
				this->m_animals[i] = new Horse(*(dynamic_cast<const Horse*>(z.GetAnimals()[i])));
			}
			else if (typeid(*(z.GetAnimals()[i])) == typeid(Flamingo))
			{
				this->m_animals[i] = new Flamingo(*(dynamic_cast<const Flamingo*>(z.GetAnimals()[i])));
		}
			
			else if (typeid(*(z.GetAnimals()[i])) == typeid(Mermaid))
			{
				this->m_animals[i] = new Mermaid(*(dynamic_cast<const Mermaid*>(z.GetAnimals()[i])));
			}
			
			else if (typeid(*(z.GetAnimals()[i])) == typeid(GoldFish))
			{
				this->m_animals[i] = new GoldFish(*(dynamic_cast<const GoldFish*>(z.GetAnimals()[i])));
		}
		
		}
	}
	return *this;
}

void Zoo::Save(ofstream& ofs) const//method to save the info to a text file
{
	ofs << *this;//using the operator << thats saves info from a text file
}

void Zoo::Load(ifstream& ifs)//method to load the info from a text file
{
	ifs >> *this;//using the operator >> thats load info from a text file
}

void Zoo::SaveBin(ofstream& ofs) const//method to save the info to a binary file
{//for every char*,prints before the len to the text
	int len = 0;
	len = strlen(this->m_name);
	ofs.write((char*)&len, sizeof(int));
	ofs.write(this->m_name, len);

	len = strlen(this->m_address);
	ofs.write((char*)&len, sizeof(int));
	ofs.write(this->m_address, len);

	ofs.write((char*)&this->m_ticketPrice, sizeof(float));

	len = strlen(this->m_openHours);
	ofs.write((char*)&len, sizeof(int));
	ofs.write(this->m_openHours, len);

	len = strlen(this->m_closeHours);
	ofs.write((char*)&len, sizeof(int));
	ofs.write(this->m_closeHours, len);

	ofs.write((char*)&this->m_numOfAnimals, sizeof(int));

	for (int i = 0; i < this->m_numOfAnimals; i++)//sends to the animal(by the type) to save the bin file
	{
		this->m_animals[i]->saveBin(ofs);
	}
}

void Zoo::LoadBin(ifstream& ifs)
{
	int len = 0;
	int numberOfAnimals = 0;
	char type[2];
	ifs.read((char*)&len, sizeof(int));
	delete[] this->m_name;
	this->m_name = new char[len + 1];
	ifs.read(this->m_name, len);
	this->m_name[len] = '\0';

	ifs.read((char*)&len, sizeof(int));
	delete[] this->m_address;
	this->m_address = new char[len + 1];
	ifs.read(this->m_address, len);
	this->m_address[len] = '\0';

	ifs.read((char*)&this->m_ticketPrice, sizeof(float));

	ifs.read((char*)&len, sizeof(int));
	delete[] this->m_openHours;
	this->m_openHours = new char[len + 1];
	ifs.read(this->m_openHours, len);
	this->m_openHours[len] = '\0';

	ifs.read((char*)&len, sizeof(int));
	delete[] this->m_closeHours;
	this->m_closeHours = new char[len + 1];
	ifs.read(this->m_closeHours, len);
	this->m_closeHours[len] = '\0';

	ifs.read((char*)&numberOfAnimals, sizeof(int));
	this->m_numOfAnimals = numberOfAnimals;
	delete this->m_animals;
	this->m_animals = new Animal * [numberOfAnimals];

	for (int i = 0; i < numberOfAnimals; i++)//checks the type of the animal and by that sends to to ifstream ctor
	{
		ifs.read(type, 2 * sizeof(char));
		if (!strncmp(type, "Horse", 2))
		{
			this->m_animals[i] = new Horse();
		}
		
		else if (!strncmp(type, "Flamingo", 2))
		{
			this->m_animals[i] = new Flamingo();
		}
		
		else if (!strncmp(type, "Mermaid", 2))
		{
			this->m_animals[i] = new Mermaid();
		}
		
		else if (!strncmp(type, "GoldFish", 2))
		{
			this->m_animals[i] = new GoldFish();
		}
		
		this->m_animals[i]->loadBin(ifs);
	}
	
}

ofstream& operator<<(ofstream& out, const Zoo& z)//operator to write the zoo to a text file
{//writes the len of every char* before the char*
	out << strlen(z.GetName()) << endl;
	out << z.GetName() << endl;
	out << strlen(z.GetAddress()) << endl;
	out << z.GetAddress() << endl;
	out << z.GetTicketPrice() << endl;
	out << strlen(z.GetOpenHour()) << endl;
	out << z.GetOpenHour() << endl;
	out << strlen(z.GetCloseHour()) << endl;
	out << z.GetCloseHour() << endl;
	out << z.GetNumOfAnimals() << endl;

	for (int i = 0; i < z.GetNumOfAnimals(); i++)//sends by the type to the animal save function
	{
		z.GetAnimals()[i]->save(out);
	}

	return out;
}

ifstream& operator>>(ifstream& in, Zoo& z)//operator to read the zoo from a text file
{
	int len = 0;
	char* ch;
	in >> len;
	in.ignore();
	delete[] z.m_name;
	z.m_name = new char[len + 1];
	in.getline(z.m_name, len+1);

	in >> len;
	in.ignore();
	delete[] z.m_address;
	z.m_address = new char[len + 1];
	in.getline(z.m_address, len + 1);

	in >> z.m_ticketPrice;

	in >> len;
	in.ignore();
	delete[] z.m_openHours;
	z.m_openHours = new char[len + 1];
	in.getline(z.m_openHours, len + 1);

	in >> len;
	in.ignore();
	delete[] z.m_closeHours;
	z.m_closeHours = new char[len + 1];
	in.getline(z.m_closeHours, len + 1);

	in >> z.m_numOfAnimals;
	int size = z.m_numOfAnimals;
	delete z.m_animals;
	z.m_animals = new Animal * [size];
	in.ignore();
	for (int i = 0; i < z.m_numOfAnimals; i++)//checks the type of the animal and by that create new animal
	{
		
		in >> len;
		ch = new char[len + 1];
		in.ignore();
		in.getline(ch, len + 1);
		if (!strcmp(ch, "Horse"))
		{
			z.m_animals[i] = new Horse();
		}
		else if (!strcmp(ch, "Flamingo"))
		{
			z.m_animals[i] = new Flamingo();
		}
		
		else if (!strcmp(ch, "Mermaid"))
		{
			z.m_animals[i] = new Mermaid();
		}
		
		else if (!strcmp(ch, "GoldFish"))
		{
			z.m_animals[i] = new GoldFish();
		}
		
		z.m_animals[i]->Load(in);
	}

	return in;
}
