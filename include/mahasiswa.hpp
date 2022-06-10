#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__


#include <iostream>
#include <vector>
#include "include/person.hpp"
#include "include/matakuliah.hpp"

class mahasiswa : public person {
private:
	std::string nrp;
	std::string departemen;
	int tahunmasuk;
	int semesterke;
	int skslulus;
	int jumlahmatkul;
	float ipk;
	std::vector<float> ips;

public:
	mahasiswa(int id, std::string nama, int dd, int mm, int yy,
					std::string nrp, std::string departemen, int tahunmasuk, int semesterke, int skslulus, int jumlahmatkul);

	void setNRP(std::string nrp);
	std::string getNRP();
	
	void setDepartemen(std::string departemen);
	std::string getDepartemen();

	void setTahunMasuk(int tahunmasuk);
	int getTahunMasuk();


	void setSemester(int semesterke);
	int getSemester();

	void setSKSLulus(int skslulus);
	int getSKSLulus();

	void setIPS(int semester, float ips);
	float getIPS(int semester);
	std::vector<float> getAllIPS();
	std::vector<matkul> matKulTerambil;
};

#endif
