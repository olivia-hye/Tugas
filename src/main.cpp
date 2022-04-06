#include <iostream>
#include <vector>
#include <string>
#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/clearscreen.hpp"
using namespace std;

int main(int argc, char** argv){
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;
	int menu_terpilih;
	int idM = 0, idD = 0, idT=0, dd, mm, yy, tahunmasuk, idUser;
	string nama, nrp, npp, departemen, pendidikan, unit;

	while(1){
		ClearScreen();
		cout << "Selamat datang di Universitas Anak Bulan" << endl << endl;
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
				ClearScreen();
				cout << "MENU TAMBAH MAHASISWA" << endl;
				cout << "---------------------" << endl;
				++idM;
				cout << "Nama: ";
				getline(cin >> ws, nama);
				cout << "Tanggal Lahir" << endl;
				cout << "-------------" << endl;
				cout << "Tanggal: ";
				cin >> dd;
				cout << "Bulan: ";
				cin >> mm;
				cout << "Tahun: ";
				cin >> yy;
				cout << "NRP: ";
				cin >> nrp;
				cout << "Departemen: ";
				getline(cin >> ws, departemen);
				cout << "Tahun Masuk: ";
				cin >> tahunmasuk;
				cout << endl;
				mahasiswa mhs(idM, nama, dd, mm, yy, nrp, departemen, tahunmasuk);
				recMhs.push_back(mhs);
				ClearScreen();
			}
				break;
			case 2:{
				ClearScreen();
				cout << "MENU TAMBAH DOSEN" << endl;
				cout << "-----------------" << endl;
				++idD;
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
				dosen dsn(idD, nama, dd, mm, yy, npp, departemen, pendidikan);
				recDosen.push_back(dsn);
				ClearScreen();
			}
				break;
			case 3:{
				ClearScreen();
				cout << "MENU TAMBAH TENDIK" << endl;
				cout << "------------------" << endl;
				++idT;
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
				tendik tdk(idT, nama, dd, mm, yy, npp, unit);
				recTendik.push_back(tdk);
				ClearScreen();
			}
				break;
			case 4:/*{
				for(int i=0; i<recMhs.size(); i++){
					cout << "ID Mahasiswa: " << recMhs[i].getId() << endl;
					cout << "Nama Mahasiswa: " << recMhs[i].getNama() << endl;
					cout << "Tanggal Lahir Mahasiswa: " << recMhs[i].getTglLahir() << "/" << recMhs[i].getBulanLahir() << "/" << recMhs[i].getTahunLahir() << endl;
					cout << "NRP Mahasiswa: " << recMhs[i].getNRP() << endl;
					cout << "Departemen Mahasiswa: " << recMhs[i].getDepartemen() << endl;
					cout << "Tahun Masuk Mahasiswa: " << recMhs[i].getTahunMasuk() << endl;
					cout << endl;							
				}
			}*/
			{
				ClearScreen();
				cout << "LIST MAHASISWA" << endl;
				cout << "--------------" << endl;
				for(int i=0; i<recMhs.size(); i++){
					cout << "ID: " << recMhs[i].getId() << " | Nama: " << recMhs[i].getNama() << " | NRP: " << recMhs[i].getNRP() <<endl;
				}
				cout << endl;
				cout << "Masukan ID Mahasiswa: "; 
				cin >> idUser;
				ClearScreen();
				cout << "DATA MAHASISWA " << idUser << endl;
				cout << "----------------" << endl;
				cout << "ID: " << idUser << endl;
				cout << "Nama: " << recMhs[idUser-1].getNama() << endl;
				cout << "Tanggal Lahir: " << recMhs[idUser-1].getTglLahir() << "/" << recMhs[idUser-1].getBulanLahir() << "/" << recMhs[idUser-1].getTahunLahir() << endl;
				cout << "NRP: " << recMhs[idUser-1].getNRP() << endl;
				cout << "Departemen: " << recMhs[idUser-1].getDepartemen() << endl;
				cout << "Tahun Masuk: " << recMhs[idUser-1].getTahunMasuk() << endl;
				cout << "Tekan Enter Untuk Kembali ke Menu Utama";
				cin.ignore();		
				cin.ignore();	
			}
				break;
			case 5:/*{
				cout << "LIST DOSEN" << endl;
				for(int i=0; i<recDosen.size(); i++){
					cout << "ID Dosen: " << recDosen[i].getId() << endl;
					cout << "Nama Dosen: " << recDosen[i].getNama() << endl;
					cout << "Tanggal Lahir Dosen: " << recDosen[i].getTglLahir() << "/" << recDosen[i].getBulanLahir() << "/" << recDosen[i].getTahunLahir() << endl;
					cout << "NPP Dosen: " << recDosen[i].getNPP() << endl;
					cout << "Departemen Dosen: " << recDosen[i].getDepartemen() << endl;
					cout << "Pendidikan Dosen: " << recDosen[i].getPendidikan() << endl;
					cout << endl;							
				}
			}*/
			{
				ClearScreen();
				cout << "LIST DOSEN" << endl;
				cout << "----------" << endl;
				for(int i=0; i<recDosen.size(); i++){
					cout << "ID: " << recDosen[i].getId() << " | Nama: " << recDosen[i].getNama() << " | NPP: " << recDosen[i].getNPP()   <<endl;
				}
				cout << endl;
				cout << "Masukan ID Dosen: "; 
				cin >> idUser;
				cout << "DATA DOSEN " << idUser << endl;
				cout << "------------" << endl;
				cout << endl;
				cout << "ID: " << idUser << endl;
				cout << "Nama: " << recDosen[idUser-1].getNama() << endl;
				cout << "Tanggal Lahir: " << recDosen[idUser-1].getTglLahir() << "/" << recDosen[idUser-1].getBulanLahir() << "/" << recDosen[idUser-1].getTahunLahir() << endl;
				cout << "NPP: " << recDosen[idUser-1].getNPP() << endl;
				cout << "Departemen: " << recDosen[idUser-1].getDepartemen() << endl;
				cout << "Pendidikan: " << recDosen[idUser-1].getPendidikan() << endl << endl;
				cout << "Tekan Enter Untuk Kembali ke Menu Utama";
				cin.ignore();		
				cin.ignore();	
			}
				break;
			case 6:/*{
				cout << "LIST TENDIK" << endl;
				for(int i=0; i<recTendik.size(); i++){
					cout << "ID Tendik: " << recTendik[i].getId() << endl;
					cout << "Nama Tendik: " << recTendik[i].getNama() << endl;
					cout << "Tanggal Lahir Tendik: " << recTendik[i].getTglLahir() << "/" << recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
					cout << "NPP Tendik: " << recTendik[i].getNPP() << endl;
					cout << "Unit Tendik: " << recTendik[i].getUnit() << endl;
					cout << endl;							
				}
			}*/
			{
				ClearScreen();
				cout << "LIST TENDIK" << endl;
				cout << "-----------" << endl;
				for(int i=0; i<recTendik.size(); i++){
					cout << "ID: " << recTendik[i].getId() << " | Nama: " << recTendik[i].getNama() << " | NPP: " << recTendik[i].getNPP()   <<endl;
				}
				cout << endl;
				cout << "Masukan ID User: "; 
				cin >> idUser;
				ClearScreen();
				cout << "DATA TENDIK " << idUser << endl;
				cout << "-------------" << endl;
				cout << endl;
				cout << "ID: " << idUser << endl;
				cout << "Nama: " << recTendik[idUser-1].getNama() << endl;
				cout << "Tanggal Lahir: " << recTendik[idUser-1].getTglLahir() << "/" << recTendik[idUser-1].getBulanLahir() << "/" << recTendik[idUser-1].getTahunLahir() << endl;
				cout << "NPP: " << recTendik[idUser-1].getNPP() << endl;
				cout << "Unit: " << recTendik[idUser-1].getUnit() << endl << endl;
				cout << "Tekan Enter Untuk Kembali ke Menu Utama";
				cin.ignore();		
				cin.ignore();	
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
