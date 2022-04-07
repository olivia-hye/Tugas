#include <iostream>
#include <string>
#include <vector>
#include "include/mahasiswa.hpp"


mahasiswa::mahasiswa(int id, std::string nama, int dd, int mm, int yy, 
				std::string nrp, std::string departemen, int tahunmasuk, int semesterke, int skslulus)
		: person(id, nama, dd, mm, yy), nrp(nrp), departemen(departemen), tahunmasuk(tahunmasuk), semesterke(semesterke), skslulus(skslulus)
{
	this->ipk = 0.0;
	this->ips = std::vector<float>(14,0);
}

void mahasiswa::setNRP(std::string nrp){
	this->nrp = nrp;
}
std::string mahasiswa::getNRP(){
		return this->nrp;
}

void mahasiswa::setDepartemen(std::string departemen){
	this->departemen = departemen;
}
std::string mahasiswa::getDepartemen(){
	return this->departemen;
}

void mahasiswa::setTahunMasuk(int tahunmasuk){
	this->tahunmasuk = tahunmasuk;
}
int mahasiswa::getTahunMasuk(){
	return this->tahunmasuk;
}

void mahasiswa::setSemester(int semesterke)
{
	this->semesterke = semesterke;
}
int mahasiswa::getSemester()
{
	return this->semesterke;
}

void mahasiswa::setSKSLulus(int skslulus)
{
	this->skslulus = skslulus;
}
int mahasiswa::getSKSLulus()
{
	return this->skslulus;
}

void mahasiswa::hitungIPK()
{
}

void mahasiswa::setIPS(int semester, float ips)
{
	// semester mulai dari 1
	if (semester < 15) {
		this->ips[semester-1] = ips;
		this->hitungIPK();
	}
}

float mahasiswa::getIPS(int semester)
{
	if (semester < 15)
		return this->ips[semester-1];

	return -1.0;
}

std::vector<float> mahasiswa::getAllIPS()
{
	return this->ips;
}



