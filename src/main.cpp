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
	int menu_user, menu_terpilih, menu_list, menu_edit;
	int idM = 0, idD = 0, idT=0, dd, mm, yy, tahunmasuk, semesterke, skslulus, idUser, semester;
	float ips;
	long unsigned i;
	string nama, nrp, npp, departemen, pendidikan, unit, user;

	START_MENU:
	ClearScreen();
	cout << "SIM Universitas Anak Bulan" << endl;
	cout << endl << endl << endl << endl << endl;
	cout << "Username: ";
	cin >> user;
	if(user == "Admin"){
		menu_user = 1;
	} else if(user == "Mahasiswa"){
		menu_user = 2;
	} else if(user == "Dosen"){
		menu_user = 3;
	} else{
		cout << endl << "User Tidak Ditemukan"; 
		cout << endl << endl;
		cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
		cin.ignore();		
		cin.ignore();
		goto START_MENU;
		}
	while(menu_user==1){
		START_ADMIN:
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
		cout << "  7. Logout" << endl;
		cout << "  8. Keluar Program" << endl;
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
				cout << endl;
				cout << "Tanggal Lahir" << endl;
				cout << "-------------" << endl;
				cout << "Tanggal (dd): ";
				cin >> dd;
				cout << "Bulan (mm): ";
				cin >> mm;
				cout << "Tahun (yyyy): ";
				cin >> yy;
				cout << endl;
				cout << "NRP: ";
				cin >> nrp;
				cout << "Departemen: ";
				getline(cin >> ws, departemen);
				cout << "Tahun Masuk: ";
				cin >> tahunmasuk;
				cout << "Semester: ";
				cin >> semesterke;
				cout << "Jumlah SKS Lulus: ";
				cin >> skslulus;
				cout << endl;
				mahasiswa mhs(idM, nama, dd, mm, yy, nrp, departemen, tahunmasuk, semesterke, skslulus);
				recMhs.push_back(mhs);
				ClearScreen();
			}
				break;
			case 2:{
				ClearScreen();
				cout << "MENU TAMBAH DOSEN" << endl;
				cout << "-----------------" << endl;
				++idD;
				cout << "Nama: ";
				getline(cin >> ws, nama);
				cout << endl;
				cout << "Tanggal Lahir" << endl;
				cout << "-------------" << endl;
				cout << "Tanggal (dd): ";
				cin >> dd;
				cout << "Bulan (mm): ";
				cin >> mm;
				cout << "Tahun (yyyy): ";
				cin >> yy;
				cout << endl;
				cout << "NPP: ";
				cin >> npp;
				cout << "Departemen: ";
				getline(cin >> ws, departemen);
				cout << "Pendidikan: ";
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
				cout << endl;
				cout << "Tanggal Lahir" << endl;
				cout << "-------------" << endl;
				cout << "Tanggal (dd): ";
				cin >> dd;
				cout << "Bulan (mm): ";
				cin >> mm;
				cout << "Tahun (yyyy): ";
				cin >> yy;
				cout << endl;
				cout << "NPP: ";
				cin >> npp;
				cout << "Unit: ";
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
				if(recMhs.size() == 0){
					cout << "Belum ada data mahasiswa" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();		
					cin.ignore();
					goto START_ADMIN;
					}
				else {
				cout << "LIST MAHASISWA" << endl;
				cout << "--------------" << endl;
				for(i=0; i<recMhs.size(); i++){
					cout << "ID: " << recMhs[i].getId() << " | Nama: " << recMhs[i].getNama() << " | NRP: " << recMhs[i].getNRP() <<endl;
				}
				cout << endl;
				cout << "Masukan ID Mahasiswa: "; 
				cin >> idUser;
				ClearScreen();
				if(idUser > recMhs.size()){
					cout << "ID Mahasiswa Tidak Ditemukan" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();		
					cin.ignore();
					goto START_ADMIN;
				}
				else{
				cout << "DATA MAHASISWA " << idUser << endl;
				cout << "----------------" << endl;
				cout << "ID Mahasiswa: " << idUser << endl;
				cout << "Nama: " << recMhs[idUser-1].getNama() << endl;
				cout << "Tanggal Lahir: " << recMhs[idUser-1].getTglLahir() << "/" << recMhs[idUser-1].getBulanLahir() << "/" << recMhs[idUser-1].getTahunLahir() << endl;
				cout << "NRP: " << recMhs[idUser-1].getNRP() << endl;
				cout << "Departemen: " << recMhs[idUser-1].getDepartemen() << endl;
				cout << "Tahun Masuk: " << recMhs[idUser-1].getTahunMasuk() << endl;
				cout << "Semester: " << recMhs[idUser-1].getSemester() << endl;
				cout << "Jumlah SKS Lulus: " << recMhs[idUser-1].getSKSLulus() << endl << endl;
				/*cout << "Tekan Enter Untuk Kembali ke Menu Utama";
				cin.ignore();		
				cin.ignore();
				*/	
				cout << "Menu: " << endl;
				cout << "  1. Input IP Semester" << endl;
				cout << "  2. Lihat IP Semester & IP Kumulatif" << endl;
				cout << "  3. Edit Data" << endl;
				cout << "  4. Hapus Data" << endl;
				cout << "  5. Kembali ke Menu Utama" << endl;
				cout << "-> Silahkan memilih salah satu: ";
				cin >> menu_list;
				cout << endl;
				switch (menu_list){
					case 1:{
						ClearScreen();
						cout << "MENU INPUT IP SEMESTER" << endl;
						cout << "----------------------" << endl;
						cout << "Input Semester Secara Berurutan" << endl;
						for(i=1; i<=semesterke; i++){
							cout << "Input IP Semester " << i << ": ";
							semester = i;
							cin >> ips;
							recMhs[idUser-1].setIPS(semester, ips);
						}
						cout << endl << "Tekan Enter Untuk Kembali ke Menu Utama...";
						cin.ignore();
						cin.ignore();
						goto START_ADMIN;
					}	break;
					case 2:{
						for(i=1; i<=recMhs[idUser-1].getSemester(); i++){
						cout << "IP Semester " << i << ": " << recMhs[idUser-1].getIPS(i) << endl;
						}
						float ipk=0, temp=0;
						for(i=1; i<=recMhs[idUser-1].getSemester();i++){
						temp += recMhs[idUser-1].getIPS(i);
						}
						ipk = temp / (i-1);
						cout << endl << "IP Kumulatif: " << ipk << endl << endl;
						cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
						cin.ignore();		
						cin.ignore();
						goto START_ADMIN;
					}	break;
					case 3:{
						ClearScreen();
						cout << "MENU EDIT MAHASISWA" << endl;
						cout << "-------------------" << endl;
						cout << "Menu: " << endl;
						cout << "  1. Edit Nama" << endl;
						cout << "  2. Edit Tanggal Lahir" << endl;
						cout << "  3. Edit NRP" << endl;
						cout << "  4. Edit Departemen" << endl;
						cout << "  5. Edit Tahun Masuk" << endl;
						cout << "  6. Edit Semester" << endl;
						cout << "  7. Edit Jumlah SKS Lulus" << endl;
						cout << "-> Silahkan memilih salah satu: ";
						cin >> menu_edit;
						cout << endl;
						switch (menu_edit)
						{
						case 1:{
							cout << "Nama: " << recMhs[idUser-1].getNama() << endl;
							cout << "Masukkan Nama Baru: ";
							getline(cin >> ws, nama);
							recMhs[idUser-1].setNama(nama);
							cout << "Nama Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();	
							goto START_ADMIN;	
							}
							break;
						case 2:{
							cout << "Tanggal Lahir: " << recMhs[idUser-1].getTglLahir() << "/" << recMhs[idUser-1].getBulanLahir() << "/" << recMhs[idUser-1].getTahunLahir() << endl<< endl;
							cout << "Masukkan Tanggal Lahir Baru: " << endl;
							cout << "Tanggal (dd): ";
							cin >> dd;
							cout << "Bulan (mm): ";
							cin >> mm;
							cout << "Tahun (yyyy): ";
							cin >> yy;
							recMhs[idUser-1].setTglLahir(dd,mm,yy);
							cout << "Tanggal Lahir Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
							}
							break;
						case 3:{
							cout << "NRP: " << recMhs[idUser-1].getNRP() << endl;
							cout << "Masukkan NRP Baru: ";
							cin >> nrp;
							recMhs[idUser-1].setNRP(nrp);
							cout << "NRP Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
						}
							break;
						case 4:{
							cout << "Departemen: " << recMhs[idUser-1].getDepartemen() << endl;
							cout << "Masukkan Departemen Baru: ";
							getline(cin >> ws, departemen);
							recMhs[idUser-1].setDepartemen(departemen);
							cout << "Departemen Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();
							goto START_ADMIN;	
						}
							break;
						case 5:{
							cout << "Tahun Masuk: " << recMhs[idUser-1].getTahunMasuk() << endl;
							cout << "Masukkan Tahun Masuk Baru: ";
							cin >> tahunmasuk;
							recMhs[idUser-1].setTahunMasuk(tahunmasuk);
							cout << "Tahun Masuk Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
						}
							break;
						case 6:{
							cout << "Semester: " << recMhs[idUser-1].getSemester() << endl;
							cout << "Masukkan Semester Baru: ";
							cin >> semesterke;
							recMhs[idUser-1].setSemester(semesterke);
							cout << "Semester Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
						}
							break;
						case 7:{
							cout << "Jumlah SKS Lulus: " << recMhs[idUser-1].getSKSLulus() << endl;
							cout << "Masukkan Jumlah SKS Lulus Baru: ";
							cin >> skslulus;
							recMhs[idUser-1].setSKSLulus(skslulus);
							cout << "Jumlah SKS Lulus Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
						}
						}
					}	break;
					case 4:{
							recMhs.erase(recMhs.begin()+idUser-1);
							if(recMhs.back().getId() != 1){recMhs.back().setId(idUser);}
							else{recMhs.back().setId(idUser-1);}
							idM--;
					}	break;
					case 5:{
					}	break;
				}
				}
			}
			break;
			}
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
				if(recDosen.size() == 0){
					cout << "Belum ada data dosen" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();		
					cin.ignore();
					goto START_ADMIN;
					}
				else{
				cout << "LIST DOSEN" << endl;
				cout << "----------" << endl;
				for(i=0; i<recDosen.size(); i++){
					cout << "ID: " << recDosen[i].getId() << " | Nama: " << recDosen[i].getNama() << " | NPP: " << recDosen[i].getNPP()   <<endl;
				}
				cout << endl;
				cout << "Masukan ID Dosen: "; 
				cin >> idUser;
				ClearScreen();
				if(idUser > recDosen.size()){
					cout << "ID Dosen Tidak Ditemukan" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();		
					cin.ignore();
					goto START_ADMIN;
				}
				else{
				cout << "DATA DOSEN " << idUser << endl;
				cout << "------------" << endl;
				cout << "ID Dosen: " << idUser << endl;
				cout << "Nama: " << recDosen[idUser-1].getNama() << endl;
				cout << "Tanggal Lahir: " << recDosen[idUser-1].getTglLahir() << "/" << recDosen[idUser-1].getBulanLahir() << "/" << recDosen[idUser-1].getTahunLahir() << endl;
				cout << "NPP: " << recDosen[idUser-1].getNPP() << endl;
				cout << "Departemen: " << recDosen[idUser-1].getDepartemen() << endl;
				cout << "Pendidikan: " << recDosen[idUser-1].getPendidikan() << endl << endl;
				/*cout << "Tekan Enter Untuk Kembali ke Menu Utama";
				cin.ignore();		
				cin.ignore();
				*/	
				cout << "Menu: " << endl;
				cout << "  1. Edit Data" << endl;
				cout << "  2. Hapus Data" << endl;
				cout << "  3. Kembali ke Menu Utama" << endl;
				cout << "-> Silahkan memilih salah satu: ";
				cin >> menu_list;
				cout << endl;
				switch (menu_list){
					case 1:{
						ClearScreen();
						cout << "MENU EDIT DOSEN" << endl;
						cout << "-------------------" << endl;
						cout << "Menu: " << endl;
						cout << "  1. Edit Nama" << endl;
						cout << "  2. Edit Tanggal Lahir" << endl;
						cout << "  3. Edit NPP" << endl;
						cout << "  4. Edit Departemen" << endl;
						cout << "  5. Edit Pendidikan" << endl;
						cout << "-> Silahkan memilih salah satu: ";
						cin >> menu_edit;
						cout << endl;
						switch (menu_edit)
						{
						case 1:{
							cout << "Nama: " << recDosen[idUser-1].getNama() << endl;
							cout << "Masukkan Nama Baru: ";
							getline(cin >> ws, nama);
							recDosen[idUser-1].setNama(nama);
							cout << "Nama Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();
							goto START_ADMIN;
						
							}
							break;
						case 2:{
							cout << "Tanggal Lahir: " << recDosen[idUser-1].getTglLahir() << "/" << recDosen[idUser-1].getBulanLahir() << "/" << recDosen[idUser-1].getTahunLahir() << endl<< endl;
							cout << "Masukkan Tanggal Lahir Baru: " << endl;
							cout << "Tanggal (dd): ";
							cin >> dd;
							cout << "Bulan (mm): ";
							cin >> mm;
							cout << "Tahun (yyyy): ";
							cin >> yy;
							recDosen[idUser-1].setTglLahir(dd,mm,yy);
							cout << "Tanggal Lahir Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
							}
							break;
						case 3:{
							cout << "NPP: " << recDosen[idUser-1].getNPP() << endl;
							cout << "Masukkan NPP Baru: ";
							cin >> npp;
							recDosen[idUser-1].setNPP(npp);
							cout << "NPP Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
						}
							break;
						case 4:{
							cout << "Departemen: " << recDosen[idUser-1].getDepartemen() << endl;
							cout << "Masukkan Departemen Baru: ";
							getline(cin >> ws, departemen);
							recDosen[idUser-1].setDepartemen(departemen);
							cout << "Departemen Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							goto START_ADMIN;
						}
							break;
						case 5:{
							cout << "Pendidikan: " << recDosen[idUser-1].getPendidikan() << endl;
							cout << "Masukkan Pendidikan Baru: ";
							cin >> pendidikan;
							recDosen[idUser-1].setPendidikan(pendidikan);
							cout << "Pendidikan Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
							}
							break;
						}
					}	break;
					case 2:{
							recDosen.erase(recDosen.begin()+idUser-1);
							if(recDosen.back().getId() != 1){recDosen.back().setId(idUser);}
							else{recDosen.back().setId(idUser-1);}
							idD--;
					}	break;
					case 3:{
					}	break;
					}
				}
			}
			break;
		}
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
				if(recTendik.size() == 0){
					cout << "Belum ada data tendik" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();		
					cin.ignore();
					goto START_ADMIN;
					}
				else{
				cout << "LIST TENDIK" << endl;
				cout << "-----------" << endl;
				for(i=0; i<recTendik.size(); i++){
					cout << "ID: " << recTendik[i].getId() << " | Nama: " << recTendik[i].getNama() << " | NPP: " << recTendik[i].getNPP()   <<endl;
				}
				cout << endl;
				cout << "Masukan ID User: "; 
				cin >> idUser;
				ClearScreen();
				if(idUser > recTendik.size()){
					cout << "ID Tendik Tidak Ditemukan" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();		
					cin.ignore();
					goto START_ADMIN;
				}
				else{
				cout << "DATA TENDIK " << idUser << endl;
				cout << "-------------" << endl;
				cout << "ID Tendik: " << idUser << endl;
				cout << "Nama: " << recTendik[idUser-1].getNama() << endl;
				cout << "Tanggal Lahir: " << recTendik[idUser-1].getTglLahir() << "/" << recTendik[idUser-1].getBulanLahir() << "/" << recTendik[idUser-1].getTahunLahir() << endl;
				cout << "NPP: " << recTendik[idUser-1].getNPP() << endl;
				cout << "Unit: " << recTendik[idUser-1].getUnit() << endl << endl;
				cout << "Menu: " << endl;
				cout << "  1. Edit Data" << endl;
				cout << "  2. Hapus Data" << endl;
				cout << "  3. Kembali ke Menu Utama" << endl;
				cout << "-> Silahkan memilih salah satu: ";
				cin >> menu_list;
				cout << endl;
				switch (menu_list){
					case 1:{
						ClearScreen();
						cout << "MENU EDIT TENDIK" << endl;
						cout << "-------------------" << endl;
						cout << "Menu: " << endl;
						cout << "  1. Edit Nama" << endl;
						cout << "  2. Edit Tanggal Lahir" << endl;
						cout << "  3. Edit NPP" << endl;
						cout << "  4. Edit Unit" << endl;
						cout << "-> Silahkan memilih salah satu: ";
						cin >> menu_edit;
						cout << endl;
						switch (menu_edit)
						{
						case 1:{
							cout << "Nama: " << recTendik[idUser-1].getNama() << endl;
							cout << "Masukkan Nama Baru: ";
							getline(cin >> ws, nama);
							recTendik[idUser-1].setNama(nama);
							cout << "Nama Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();
							goto START_ADMIN;		
							}
							break;
						case 2:{
							cout << "Tanggal Lahir: " << recTendik[idUser-1].getTglLahir() << "/" << recTendik[idUser-1].getBulanLahir() << "/" << recTendik[idUser-1].getTahunLahir() << endl<< endl;
							cout << "Masukkan Tanggal Lahir Baru: " << endl;
							cout << "Tanggal (dd): ";
							cin >> dd;
							cout << "Bulan (mm): ";
							cin >> mm;
							cout << "Tahun (yyyy): ";
							cin >> yy;
							recTendik[idUser-1].setTglLahir(dd,mm,yy);
							cout << "Tanggal Lahir Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
							}
							break;
						case 3:{
							cout << "NPP: " << recTendik[idUser-1].getNPP() << endl;
							cout << "Masukkan NPP Baru: ";
							cin >> npp;
							recTendik[idUser-1].setNPP(npp);
							cout << "NPP Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();		
							cin.ignore();
							goto START_ADMIN;
						}
							break;
						case 4:{
							cout << "Unit: " << recTendik[idUser-1].getUnit() << endl;
							cout << "Masukkan Unit Baru: ";
							getline(cin >> ws, unit);
							recTendik[idUser-1].setUnit(unit);
							cout << "Unit Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();
							goto START_ADMIN;		
						}
							break;
						}
					}	break;
					case 2:{
							recTendik.erase(recTendik.begin()+idUser-1);
							if(recTendik.back().getId() != 1){recTendik.back().setId(idUser);}
							else{recTendik.back().setId(idUser-1);}
							idT--;
					}	break;
					case 3:{
					}	break;
				}
				}
			}
			break;
		}
			case 7:{
				goto START_MENU;
			}
			case 8:{
				ClearScreen();
				return 0;
			}
				break;
		}
	}
	while(menu_user==2){
		if(idM==0){
			ClearScreen();
			cout << "Database Mahasiswa Masih Kosong" << endl << endl;
			cout << "Tekan Tombol Enter Untuk Kembali Ke Menu Utama";
			cin.ignore();
			cin.ignore();
			goto START_MENU;
		}
		cout << "Masukkan ID Mahasiswa Anda: ";
		cin >> idM;
		ClearScreen();
		cout << "Selamat datang di Universitas Anak Bulan, " << recMhs[idM-1].getNama();
		cout << endl << endl;
		cout << "DATA MAHASISWA" << endl;
		cout << "--------------" << endl;
		cout << "ID Mahasiswa: " << idM << endl;
		cout << "Nama: " << recMhs[idM-1].getNama() << endl;
		cout << "Tanggal Lahir: " << recMhs[idM-1].getTglLahir() << "/" << recMhs[idM-1].getBulanLahir() << "/" << recMhs[idM-1].getTahunLahir() << endl;
		cout << "NRP: " << recMhs[idM-1].getNRP() << endl;
		cout << "Departemen: " << recMhs[idM-1].getDepartemen() << endl;
		cout << "Tahun Masuk: " << recMhs[idM-1].getTahunMasuk() << endl;
		cout << "Semester: " << recMhs[idM-1].getSemester() << endl;
		cout << "Jumlah SKS Lulus: " << recMhs[idM-1].getSKSLulus() << endl << endl;
		cout << "Menu: " << endl;
		cout << "  1. Cek IP Semester & IP Kumulatif" << endl;
		cout << "  2. Logout" << endl;
		cout << "  3. Keluar Program" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		cout << endl;
		switch (menu_terpilih){
			case 1:{
				for(i=1; i<=recMhs[idM-1].getSemester(); i++){
						cout << "IP Semester " << i << ": " << recMhs[idM-1].getIPS(i) << endl;
						}
						float ipk=0, temp=0;
						for(i=1; i<=recMhs[idM-1].getSemester();i++){
						temp += recMhs[idM-1].getIPS(i);
						}
						ipk = temp / (i-1);
						cout << endl << "IP Kumulatif: " << ipk << endl << endl;
						cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
						cin.ignore();		
						cin.ignore();
					}	break;
			case 2:{
				goto START_MENU;
			} break;
			case 3:{
				ClearScreen();
				return 0;
			}
		}
	}
	while(menu_user==3){}
	return 0;
}
