#include <iostream>
#include "include/matakuliah.hpp"

matkul::matkul(){}

matkul::matkul(int IdMatKul, std::string NamaMatKul, std::string KodeMatKul, int SksMatKul)
	:idMatKul(IdMatKul), namaMatKul(NamaMatKul), kodeMatKul(KodeMatKul), sksMatKul(SksMatKul){}

void matkul::setID(int IdMatKul)
{
	this->idMatKul = IdMatKul;
}
int matkul::getID()
{
	return this->idMatKul;
}

void matkul::setNama(std::string NamaMatkul)
{
	this->namaMatKul = NamaMatkul;
}

std::string matkul::getNama()
{
	return this->namaMatKul;
}

void matkul::setKode(std::string KodeMatkul)
{
	this->kodeMatKul = KodeMatkul;
}
std::string matkul::getKode()
{
	return this->kodeMatKul;
}

void matkul::setSKS(int SksMatKul)
{
	this->sksMatKul = SksMatKul;
}
int matkul::getSKS()
{
	return this->sksMatKul;
}
