#ifndef __DOSEN_HPP__
#define __DOSEN_HPP__

#include <iostream>
#include <vector>
#include "include/person.hpp"
#include "include/matakuliah.hpp"

class dosen : public person {
private:
	std::string npp;
	std::string departemen;
	std::string pendidikan;

public:
	dosen(int id, std::string nama, int dd, int mm, int yy, std::string npp, std::string departemen, std::string pendidikan);
	void setNPP(std::string npp);
	std::string getNPP();
	void setDepartemen(std::string departemen);
	std::string getDepartemen();
	void setPendidikan(std::string pendidikan);
	std::string getPendidikan();
	std::vector<matkul> matKulAjar;
};

#endif 
