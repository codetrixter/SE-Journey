/**
 * @file associativeRelation.cpp
 * @author Abhishek
 * @brief Here we discuss about the associative relationship among classes and objects:
 * 1- To qualify as an association, an object and another object must have the following relationship:
    1.The associated object (member) is otherwise unrelated to the object (class)
    2.The associated object (member) can belong to more than one object (class) at a time
    3.The associated object (member) does not have its existence managed by the object (class)
    4.The associated object (member) may or may not know about the existence of the object (class)

   EXAMPLE: The relationship between doctors and patients is a great example of an association.

   2- Direct association: When one class is associated with anothere via reference or pointer to the object.

   3- Indirect association: Whne the object of one is associated to another without reference or pointer to the object. 
        This kind of indirect associationcanbe used when the object to be accessed is not in main memory and needs to be fetched from some DB.

	@todo:
   4- reflexive Associativity:
--------------------------------------------------------------------------------------------------------------------------------------
    Property                                *   Composition           *     Aggregation           *      Association
--------------------------------------------------------------------------------------------------------------------------------------
    Relationship type                       *   Whole/part            *     Whole/part            *      otherwise unrelated
    Members can belong to multiple classes  *   No                    *     Yes                   *      Yes
    Members existence managed by class      *   yes                   *     No                    *      No
    Directionality                          *   Unidirectional        *     Unidirection          *      Uni/Bidirectional
    Relationship verb                       *   part-of               *     has-a                 *      uses-a
--------------------------------------------------------------------------------------------------------------------------------------
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <vector>
//********************************Direct Association***
// Since Doctor and Patient have a circular dependency, we're going to forward declare Patient
/* class Patient;

class Doctor
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Patient>> m_patient{};

public:
	Doctor(const std::string& name) :
		m_name{ name }
	{
	}

	void addPatient(Patient& patient);

	/// We'll implement this function below Patient since we need Patient to be defined at that point
	friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

	const std::string& getName() const { return m_name; }
};

class Patient
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Doctor>> m_doctor{}; // so that we can use it here

	/// We're going to make addDoctor private because we don't want the public to use it.
	/// They should use Doctor::addPatient() instead, which is publicly exposed
	void addDoctor(const Doctor& doctor)
	{
		m_doctor.push_back(doctor);
	}

public:
	Patient(const std::string& name)
		: m_name{ name }
	{
	}

	/// We'll implement this function below to parallel operator<<(std::ostream&, const Doctor&)
	friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

	const std::string& getName() const { return m_name; }

	/// We'll friend Doctor::addPatient() so it can access the private function Patient::addDoctor()
	friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient)
{
	/// Our doctor will add this patient
	m_patient.push_back(patient);

	/// and the patient will also add this doctor, called on Doctor class hence can use *this as parameter.
	patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor)
{
	if (doctor.m_patient.empty())
	{
		out << doctor.m_name << " has no patients right now";
		return out;
	}

	out << doctor.m_name << " is seeing patients: ";
	for (const auto& patient : doctor.m_patient)
		out << patient.get().getName() << ' ';

	return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
	if (patient.m_doctor.empty())
	{
		out << patient.getName() << " has no doctors right now";
		return out;
	}

	out << patient.m_name << " is seeing doctors: ";
	for (const auto& doctor : patient.m_doctor)
		out << doctor.get().getName() << ' ';

	return out;
}

int main()
{
	/// Create a Patient outside the scope of the Doctor
	Patient dave{ "Dave" };
	Patient frank{ "Frank" };
	Patient betsy{ "Betsy" };

	Doctor james{ "James" };
	Doctor scott{ "Scott" };

	james.addPatient(dave);

	scott.addPatient(dave);
	scott.addPatient(betsy);

	std::cout << james << '\n';
	std::cout << scott << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';

	return 0;
} */
//********************************Direct Association***
//********************************In-Direct Association***
class Car
{
    private:
    std::string m_name;
    int m_id;

    public:
    Car(std::string name, int id):
        m_name{name}, m_id{id}
        {}
    
    const std::string& getName() const {return m_name; }

    int getId() const { return m_id; }
};
// Our CarLot is essentially just a static array of Cars and a lookup function to retrieve them.
// Because it's static, we don't need to allocate an object of type CarLot to use it
class CarLot
{
    private:
    static Car s_carLot[4]; // Ensure we don't try to create a CarLot

    public:
    CarLot() = delete;

    static Car* getCarID(int id)
    {
        for(int i = 0; i < 4; i++)
        {
            if(s_carLot[i].getId() == id)
            {
                return &(s_carLot[i]);
            }
        }
        return nullptr;
    }
};

Car CarLot::s_carLot[4]{ { "Prius", 4 }, { "Corolla", 17 }, { "Accord", 84 }, { "Matrix", 62 } };

class Driver
{
    private:
    std::string m_name;
    int m_id;   // we're associated with the Car by ID rather than pointer

    public:
    Driver(std::string name, int id):
        m_name{name}, m_id{id}
        {}
    
    const std::string& getName() const { return m_name; };
    int getCarId() const { return m_id; };
};

int main(int argc, char const *argv[])
{
    Driver driver{"Franz", 17};

    auto car = CarLot::getCarID(driver.getCarId());

    if(car)
        std::cout << driver.getName() << " is driving a " << car->getName() << std::endl;
    else
        std::cout << "could not find the car in the lot" << std::endl;
    return 0;
}
//********************************In-Direct Association***