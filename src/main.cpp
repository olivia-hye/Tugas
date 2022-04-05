#include <iostream>
#include <vector>
#include <string>
#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
using namespace std;

int main(int argc, char** argv){
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;
	int menu_terpilih;
	int id = 0, dd, mm, yy, tahunmasuk;
	string nama, nrp, npp, departemen, pendidikan, unit;

	while(1){
		cout << "Selamat datang di Universitas BlockBerry" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " Mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " Dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " Tenaga Kependidikan" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tampilkan semua Dosen" << endl;
		cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  7. Tutup Program" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		cout << endl;
		switch (menu_terpilih){
			case 1:{
				++id;
				cout << "Nama Mahasiswa: ";
				getline(cin >> ws, nama);
				cout << "Tanggal Lahir Mahasiswa" << endl;
				cout << "Tanggal: ";
				cin >> dd;
				cout << "Bulan: ";
				cin >> mm;
				cout << "Tahun: ";
				cin >> yy;
				cout << "NRP Mahasiswa: ";
				cin >> nrp;
				cout << "Departemen Mahasiswa: ";
				getline(cin >> ws, departemen);
				cout << "Tahun Masuk Mahasiswa: ";
				cin >> tahunmasuk;
				cout << endl;
				mahasiswa mhs(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk);
				recMhs.push_back(mhs);
			}
				break;
			case 2:{
				++id;
				cout << "Nama Dosen: ";
				getline(cin >> ws, nama);
				cout << "Tanggal Lahir Dosen" << endl;
				cout << "Tanggal: ";
				cin >> dd;
				cout << "Bulan: ";
				cin >> mm;
				cout << "Tahun: ";
				cin >> yy;
				cout << "NPP Dosen: ";
				cin >> npp;
				cout << "Departemen Dosen: ";
				getline(cin >> ws, departemen);
				cout << "Pendidikan Dosen: ";
				getline(cin >> ws, pendidikan);
				cout << endl;
				dosen dsn(id, nama, dd, mm, yy, npp, departemen, pendidikan);
				recDosen.push_back(dsn);
			}
				break;
			case 3:{
				++id;
				cout << "Nama Tendik: ";
				getline(cin >> ws, nama);
				cout << "Tanggal Lahir Tendik" << endl;
				cout << "Tanggal: ";
				cin >> dd;
				cout << "Bulan: ";
				cin >> mm;
				cout << "Tahun: ";
				cin >> yy;
				cout << "NPP Tendik: ";
				cin >> npp;
				cout << "Unit Tendik: ";
				getline(cin >> ws, unit);
				cout << endl;
				tendik tdk(id, nama, dd, mm, yy, npp, unit);
				recTendik.push_back(tdk);
			}
				break;
			case 4:{
				cout << "LIST MAHASISWA" << endl;
				for(int i=0; i<recMhs.size(); i++){
					cout << "ID Mahasiswa: " << recMhs[i].getId() << endl;
					cout << "Nama Mahasiswa: " << recMhs[i].getNama() << endl;
					cout << "Tanggal Lahir Mahasiswa: " << recMhs[i].getTglLahir() << "/" << recMhs[i].getBulanLahir() << "/" << recMhs[i].getTahunLahir() << endl;
					cout << "NRP Mahasiswa: " << recMhs[i].getNRP() << endl;
					cout << "Departemen Mahasiswa: " << recMhs[i].getDepartemen() << endl;
					cout << "Tahun Masuk Mahasiswa: " << recMhs[i].getTahunMasuk() << endl;
					cout << endl;							
				}
			}
				break;
			case 5:{
				for(int i=0; i<recDosen.size(); i++){
					cout << "ID Dosen: " << recDosen[i].getId() << endl;
					cout << "Nama Dosen: " << recDosen[i].getNama() << endl;
					cout << "Tanggal Lahir Dosen: " << recDosen[i].getTglLahir() << "/" << recDosen[i].getBulanLahir() << "/" << recDosen[i].getTahunLahir() << endl;
					cout << "NPP Dosen: " << recDosen[i].getNPP() << endl;
					cout << "Departemen Dosen: " << recDosen[i].getDepartemen() << endl;
					cout << "Pendidikan Dosen: " << recDosen[i].getPendidikan() << endl;
					cout << endl;							
				}
			}
				break;
			case 6:{
				for(int i=0; i<recTendik.size(); i++){
					cout << "ID Tendik: " << recTendik[i].getId() << endl;
					cout << "Nama Tendik: " << recTendik[i].getNama() << endl;
					cout << "Tanggal Lahir Tendik: " << recTendik[i].getTglLahir() << "/" << recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
					cout << "NPP Tendik: " << recTendik[i].getNPP() << endl;
					cout << "Unit Tendik: " << recTendik[i].getUnit() << endl;
					cout << endl;							
				}
			}
				break;
			case 7:{
				return 0;
			}
				break;
		}
	}
	
	return 0;
}
