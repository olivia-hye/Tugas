#include <iostream>
#include <vector>
#include <string>
#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/matakuliah.hpp"

using namespace std;

//Vector
vector<mahasiswa> recMhs;
vector<dosen> recDosen;
vector<tendik> recTendik;
vector<matkul> recMatKul;

//Global Variables (outside int main(); to prevent being redefined each time the program return to main();)
int menu_user=0, menu_terpilih, menu_list, menu_edit;
long long unsigned id = 0, idM = 0, idD = 0, idT=0, idMK=0, idUser=0, idMatKul = 0;
bool isLoggedIn = false;

//ClearScreen Function: clears the terminal using both "system("cls")" (for cmd) and "system("clear")" (for powershell & unix based terminal)
void ClearScreen(){
    system("cls")&&system("clear");
}

int main(){
	//Global Variables
	int dd, mm, yy, tahunmasuk, semesterke, skslulus, semester, sks, jumlahmatkul = 0;
	float ips;
	long unsigned i;
	string nama, nrp, npp, departemen, pendidikan, unit, user, kodeMK;

	//User Logon Page
	while(menu_user==0){
		ClearScreen();
		cout << "SIAKAD Universitas Anak Bulan" << endl;
		cout << "-----------------------------" << endl;

		//Output current date using ctime library
		time_t ttime = time(0);
		tm *local_time = localtime(&ttime);
		cout << "Tanggal: " << local_time->tm_mday << "/" << 1 + local_time->tm_mon << "/" << 1900 + local_time->tm_year << endl;

		cout << "User List: Admin, Mahasiswa, Dosen";
		cout << endl << endl << endl << endl << endl;
		cout << "User: ";
		cin >> user;
		if(user == "Admin" || user == "admin" || user == "1"){menu_user = 1;} 
		else if(user == "Mahasiswa" || user == "mahasiswa" || user == "2"){menu_user = 2;} 
		else if(user == "Dosen" || user == "dosen" || user == "3" ){menu_user = 3;} 
		else{
			cout << endl << "User Tidak Ditemukan" << endl << endl; 
			cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
			cin.ignore(); cin.ignore();
			return main();
		}
	}
	//Interface Admin
	while(menu_user==1){
		ClearScreen();
		cout << "Selamat datang di SIAKAD Universitas Anak Bulan" << endl; 
		cout << "-----------------------------------------------" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " Mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " Dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " Tenaga Kependidikan" << endl;
		cout << "  4. Jumlah Mata Kuliah		  : " << recMatKul.size() << " Mata Kuliah" << endl << endl;

		cout << "Menu: " << endl;
		cout << "  1.  Tambah Mahasiswa" << endl;
		cout << "  2.  Tambah Dosen" << endl;
		cout << "  3.  Tambah Tenaga Kependidikan" << endl;
		cout << "  4.  Tambah Mata Kuliah" << endl;
		cout << "  5.  Tampilkan semua Mahasiswa" << endl;
		cout << "  6.  Tampilkan semua Dosen" << endl;
		cout << "  7.  Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  8.  Tampilkan semua Mata Kuliah" << endl;
		cout << "  9.  Logout" << endl;
		cout << "  10. Keluar Program" << endl;
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
				cout << endl << "Tanggal Lahir" << endl;
				cout << "-------------" << endl;
				cout << "Tanggal (dd): ";
				cin >> dd;
				while(dd > 31){
					cout << endl << "Tanggal tidak bisa lebih dari 31" << endl << "Tanggal (dd): ";
					cin >> dd;
				}
				cout << "Bulan (mm): ";
				cin >> mm;
				while(mm > 12){
					cout << endl << "Bulan tidak bisa lebih dari 12" << endl << "Bulan (mm): ";
					cin >> mm;
				}
				cout << "Tahun (yyyy): ";
				cin >> yy;
				cout << endl << "NRP: ";
				cin >> nrp;
				cout << "Departemen: ";
				getline(cin >> ws, departemen);
				cout << "Tahun Masuk: ";
				cin >> tahunmasuk;
				cout << "Semester: ";
				cin >> semesterke;
				cout << "Jumlah SKS Lulus: ";
				cin >> skslulus;
				mahasiswa mhs(idM, nama, dd, mm, yy, nrp, departemen, tahunmasuk, semesterke, skslulus, jumlahmatkul);
				recMhs.push_back(mhs);
			}	break;
			case 2:{
				ClearScreen();
				cout << "MENU TAMBAH DOSEN" << endl;
				cout << "-----------------" << endl;
				++idD;
				cout << "Nama: ";
				getline(cin >> ws, nama);
				cout << endl << "Tanggal Lahir" << endl;
				cout << "-------------" << endl;
				cout << "Tanggal (dd): ";
				cin >> dd;
				while(dd > 31){
					cout << endl << "Tanggal tidak bisa lebih dari 31" << endl << "Tanggal (dd): ";
					cin >> dd;
				}
				cout << "Bulan (mm): ";
				cin >> mm;
				while(mm > 12){
					cout << endl << "Bulan tidak bisa lebih dari 12" << endl << "Bulan (mm): ";
					cin >> mm;
				}
				cout << "Tahun (yyyy): ";
				cin >> yy;
				cout << endl << "NPP: ";
				cin >> npp;
				cout << "Departemen: ";
				getline(cin >> ws, departemen);
				cout << "Pendidikan: ";
				getline(cin >> ws, pendidikan);
				dosen dsn(idD, nama, dd, mm, yy, npp, departemen, pendidikan);
				recDosen.push_back(dsn);
			}	break;
			case 3:{
				ClearScreen();
				cout << "MENU TAMBAH TENDIK" << endl;
				cout << "------------------" << endl;
				++idT;
				cout << "Nama Tendik: ";
				getline(cin >> ws, nama);
				cout << endl << "Tanggal Lahir" << endl;
				cout << "-------------" << endl;
				cout << "Tanggal (dd): ";
				cin >> dd;
				while(dd > 31){
					cout << endl << "Tanggal tidak bisa lebih dari 31" << endl << "Tanggal (dd): ";
					cin >> dd;
				}
				cout << "Bulan (mm): ";
				cin >> mm;
				while(mm > 12){
					cout << endl << "Bulan tidak bisa lebih dari 12" << endl << "Bulan (mm): ";
					cin >> mm;
				}
				cout << "Tahun (yyyy): ";
				cin >> yy;
				cout << endl << "NPP: ";
				cin >> npp;
				cout << "Unit: ";
				getline(cin >> ws, unit);
				tendik tdk(idT, nama, dd, mm, yy, npp, unit);
				recTendik.push_back(tdk);
			}	break;
			case 4:{
				ClearScreen();
				cout << "MENU TAMBAH MATA KULIAH" << endl;
				cout << "-----------------------" << endl;
				++idMK;
				cout << "Nama Mata Kuliah: ";
				getline(cin >> ws, nama);
				cout << "Kode Mata Kuliah: ";
				getline(cin >> ws, kodeMK);
				cout << "Jumlah SKS: ";
				cin >> sks;
				matkul mk(idMK, nama, kodeMK, sks);
				recMatKul.push_back(mk);
			}	break;
			case 5:{
				ClearScreen();
				if(recMhs.size() == 0){
					cout << "Belum ada data mahasiswa" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();
					}
				else{
					cout << "LIST MAHASISWA" << endl;
					cout << "--------------" << endl;
					for(i=0; i<recMhs.size(); i++){
						cout << "ID: " << recMhs[i].getId() << " | Nama: " << recMhs[i].getNama() << " | NRP: " << recMhs[i].getNRP() <<endl;
					}
					cout << endl << "Masukan ID Mahasiswa: "; 
					cin >> idUser;
					if(idUser > recMhs.size()){
						ClearScreen();
						cout << "ID Mahasiswa Tidak Ditemukan" << endl << endl;
						cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
						cin.ignore(); cin.ignore();
						return main();
					}
					ClearScreen();
					cout << "DATA MAHASISWA " << idUser << endl;
					cout << "----------------" << endl;
					cout << "ID Mahasiswa: " << idUser << endl;
					cout << "Nama: " << recMhs[idUser-1].getNama() << endl;
					cout << "Tanggal Lahir: " << recMhs[idUser-1].getTglLahir() << "/" << recMhs[idUser-1].getBulanLahir() << "/" << recMhs[idUser-1].getTahunLahir() << endl;
					cout << "NRP: " << recMhs[idUser-1].getNRP() << endl;
					cout << "Departemen: " << recMhs[idUser-1].getDepartemen() << endl;
					cout << "Tahun Masuk: " << recMhs[idUser-1].getTahunMasuk() << endl;
					cout << "Semester: " << recMhs[idUser-1].getSemester() << endl;
					cout << "Jumlah SKS Lulus: " << recMhs[idUser-1].getSKSLulus() << endl;
					cout << "Jumlah Mata Kuliah: " << recMhs[idUser-1].matKulTerambil.size() << endl << endl;

					cout << "Menu: " << endl;
					cout << "  1. Input IP Semester" << endl;
					cout << "  2. Lihat IP Semester & IP Kumulatif" << endl;
					cout << "  3. Tambahkan Mata Kuliah" << endl;
					cout << "  4. Lihat Mata Kuliah" << endl;
					cout << "  5. Edit Data" << endl;
					cout << "  6. Hapus Data" << endl;
					cout << "  7. Kembali ke Menu Utama" << endl;
					cout << "-> Silahkan memilih salah satu: ";
					cin >> menu_list;
					switch (menu_list){
						case 1:{
							ClearScreen();
							cout << "MENU INPUT IP SEMESTER" << endl;
							cout << "----------------------" << endl;
							for(i=1; i<=recMhs[idUser-1].getSemester(); i++){
								cout << "Input IP Semester " << i << ": ";
								semester = i;
								cin >> ips;
								while(ips>4.0){
									cout << endl << "IP Semester tidak bisa lebih besar dari 4.0" << endl << endl;
									cout << "Input IP Semester " << i << ": ";
									cin >> ips;
								}
								recMhs[idUser-1].setIPS(semester, ips);
							}
							cout << endl << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();
							}	break;
						case 2:{
							if(recMhs[idUser-1].getIPS(1) == 0 && recMhs[idUser-1].getIPS(2) == 0){
								ClearScreen();
								cout << "IP Semester dan IP Kumulatif Mahasiswa Belum Terisi" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();		
								cin.ignore();
								return main();
							}
							cout << endl;
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
							}	break;
						case 3:{
							ClearScreen();
							cout << "MENU INPUT MATA KULIAH" << endl;
							cout << "----------------------" << endl << endl;
							while(recMatKul.size() == 0){
								cout << "Belum ada data mata kuliah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();	cin.ignore();
								return main();
							}
							cout << "LIST MATA KULIAH" << endl;
							cout << "----------------" << endl;
							for(i=0; i<recMatKul.size(); i++){
								cout << "ID: " << recMatKul[i].getID() << "| Kode: " << recMatKul[i].getKode() << " | Nama: " << recMatKul[i].getNama() << " | SKS: " << recMatKul[i].getSKS() <<endl;
							}
							cout << endl;
						
							cout << "Masukkan ID Mata Kuliah: ";
							cin >> idMatKul;
							while(idMatKul>recMatKul.size()){
								cout << "ID Mata Kuliah Salah, Silahkan Isi Kembali." << endl << endl;
								cout << "ID Mata Kuliah: ";
								cin >> idMatKul;
							}

							int tempa = recMatKul[idMatKul-1].getID();
							string tempb = recMatKul[idMatKul-1].getKode();
							string tempc = recMatKul[idMatKul-1].getNama();
							int tempd = recMatKul[idMatKul-1].getSKS();

							matkul temp;
							recMhs[idUser-1].matKulTerambil.push_back(temp);
							recMhs[idUser-1].matKulTerambil[jumlahmatkul].setID(tempa);
							recMhs[idUser-1].matKulTerambil[jumlahmatkul].setKode(tempb);
							recMhs[idUser-1].matKulTerambil[jumlahmatkul].setNama(tempc);
							recMhs[idUser-1].matKulTerambil[jumlahmatkul].setSKS(tempd);
							jumlahmatkul++;

							cout << endl << "Mata Kuliah Telah Berhasil Ditambahkan" << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();
							}	break;
						case 4:{
							ClearScreen();
							while(recMhs[idUser-1].matKulTerambil.size() == 0){
								cout << "Belum ada data mata kuliah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();	cin.ignore();
								return main();
							}
							cout << "LIST MATA KULIAH " << recMhs[idUser-1].getNama() << endl;
							cout << "------------------------------------------------" << endl;
							for(i=0; i<recMhs[idUser-1].matKulTerambil.size(); i++){
								cout << "ID: " << recMhs[idUser-1].matKulTerambil[i].getID() << " | Kode: " << recMhs[idUser-1].matKulTerambil[i].getKode() << " | Nama: " << recMhs[idUser-1].matKulTerambil[i].getNama() << " | SKS: " << recMhs[idUser-1].matKulTerambil[i].getSKS() << endl;
							}
							cout << endl << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();
							}	break;
						case 5:{
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
							switch (menu_edit){
								case 1:{
									cout << "Nama: " << recMhs[idUser-1].getNama() << endl;
									cout << "Masukkan Nama Baru: ";
									getline(cin >> ws, nama);
									recMhs[idUser-1].setNama(nama);
									cout << "Nama Telah Berhasil Diubah" << endl << endl;
									cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
									cin.ignore();		
								}	break;
								case 2:{
									cout << "Tanggal Lahir: " << recMhs[idUser-1].getTglLahir() << "/" << recMhs[idUser-1].getBulanLahir() << "/" << recMhs[idUser-1].getTahunLahir() << endl<< endl;
									cout << "Masukkan Tanggal Lahir Baru: " << endl;
									cout << "Tanggal (dd): ";
									cin >> dd;
									while(dd > 31){
										cout << endl << "Tanggal tidak bisa lebih dari 31" << endl << "Tanggal (dd): ";
										cin >> dd;
									}
									cout << "Bulan (mm): ";
									cin >> mm;
									while(mm > 12){
										cout << endl << "Bulan tidak bisa lebih dari 12" << endl << "Bulan (mm): ";
										cin >> mm;
									}
									cout << "Tahun (yyyy): ";
									cin >> yy;
									recMhs[idUser-1].setTglLahir(dd,mm,yy);
									cout << "Tanggal Lahir Telah Berhasil Diubah" << endl << endl;
									cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
									cin.ignore();
								}	break;
								case 3:{
									cout << "NRP: " << recMhs[idUser-1].getNRP() << endl;
									cout << "Masukkan NRP Baru: ";
									cin >> nrp;
									recMhs[idUser-1].setNRP(nrp);
									cout << "NRP Telah Berhasil Diubah" << endl << endl;
									cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
									cin.ignore();
								}	break;
								case 4:{
									cout << "Departemen: " << recMhs[idUser-1].getDepartemen() << endl;
									cout << "Masukkan Departemen Baru: ";
									getline(cin >> ws, departemen);
									recMhs[idUser-1].setDepartemen(departemen);
									cout << "Departemen Telah Berhasil Diubah" << endl << endl;
									cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
									cin.ignore();	
								}	break;
								case 5:{
									cout << "Tahun Masuk: " << recMhs[idUser-1].getTahunMasuk() << endl;
									cout << "Masukkan Tahun Masuk Baru: ";
									cin >> tahunmasuk;
									recMhs[idUser-1].setTahunMasuk(tahunmasuk);
									cout << "Tahun Masuk Telah Berhasil Diubah" << endl << endl;
									cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
									cin.ignore();
								}	break;
								case 6:{
									cout << "Semester: " << recMhs[idUser-1].getSemester() << endl;
									cout << "Masukkan Semester Baru: ";
									cin >> semesterke;
									recMhs[idUser-1].setSemester(semesterke);
									cout << "Semester Telah Berhasil Diubah" << endl << endl;
									cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
									cin.ignore();
								}	break;
								case 7:{
									cout << "Jumlah SKS Lulus: " << recMhs[idUser-1].getSKSLulus() << endl;
									cout << "Masukkan Jumlah SKS Lulus Baru: ";
									cin >> skslulus;
									recMhs[idUser-1].setSKSLulus(skslulus);
									cout << "Jumlah SKS Lulus Telah Berhasil Diubah" << endl << endl;
									cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
									cin.ignore();
								}	break;
								default:{
									ClearScreen();
									cout << "Pilihan tidak ditemukan" << endl << endl << "Tekan Enter Untuk Kembali ke Menu Utama";
									cin.ignore(); 
								}
							}
						}	break;
						case 6:{
							recMhs.erase(recMhs.begin()+idUser-1);
							idM--;
							for(i=0; i<idM; i++){
								recMhs[i].setId(i+1);
							}
						}	break;
						case 7:{
						}	break;
						default:{
							ClearScreen();
							cout << "Pilihan tidak ditemukan" << endl << endl << "Tekan Enter Untuk Kembali ke Menu Utama";
							cin.ignore();
						}
				}
					}
			}	break;
			case 6:{
				ClearScreen();
				while(recDosen.size() == 0){
					cout << "Belum ada data dosen" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore(); cin.ignore();
					return main();
					}
				cout << "LIST DOSEN" << endl;
				cout << "----------" << endl;
				for(i=0; i<recDosen.size(); i++){
					cout << "ID: " << recDosen[i].getId() << " | Nama: " << recDosen[i].getNama() << " | NPP: " << recDosen[i].getNPP()   <<endl;
				}
				cout << endl << "Masukan ID Dosen: "; 
				cin >> idUser;
				ClearScreen();
				while(idUser > recDosen.size()){
					cout << "ID Dosen Tidak Ditemukan" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore(); cin.ignore();
					return main();
				}
				cout << "DATA DOSEN " << idUser << endl;
				cout << "------------" << endl;
				cout << "ID Dosen: " << idUser << endl;
				cout << "Nama: " << recDosen[idUser-1].getNama() << endl;
				cout << "Tanggal Lahir: " << recDosen[idUser-1].getTglLahir() << "/" << recDosen[idUser-1].getBulanLahir() << "/" << recDosen[idUser-1].getTahunLahir() << endl;
				cout << "NPP: " << recDosen[idUser-1].getNPP() << endl;
				cout << "Departemen: " << recDosen[idUser-1].getDepartemen() << endl;
				cout << "Pendidikan: " << recDosen[idUser-1].getPendidikan() << endl << endl;
				
				cout << "Menu: " << endl;
				cout << "  1. Edit Data" << endl;
				cout << "  2. Hapus Data" << endl;
				cout << "  3. Kembali ke Menu Utama" << endl;
				cout << "-> Silahkan memilih salah satu: ";
				cin >> menu_list;
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
						switch (menu_edit){
							case 1:{
							cout << "Nama: " << recDosen[idUser-1].getNama() << endl;
							cout << "Masukkan Nama Baru: ";
							getline(cin >> ws, nama);
							recDosen[idUser-1].setNama(nama);
							cout << "Nama Telah Berhasil Diubah" << endl << endl;
							cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
							cin.ignore();
							}	break;
							case 2:{
								cout << "Tanggal Lahir: " << recDosen[idUser-1].getTglLahir() << "/" << recDosen[idUser-1].getBulanLahir() << "/" << recDosen[idUser-1].getTahunLahir() << endl<< endl;
								cout << "Masukkan Tanggal Lahir Baru: " << endl;
								cout << "Tanggal (dd): ";
								cin >> dd;
								while(dd > 31){
									cout << endl << "Tanggal tidak bisa lebih dari 31" << endl << "Tanggal (dd): ";
									cin >> dd;
								}
								cout << "Bulan (mm): ";
								cin >> mm;
								while(mm > 12){
									cout << endl << "Bulan tidak bisa lebih dari 12" << endl << "Bulan (mm): ";
									cin >> mm;
								}
								cout << "Tahun (yyyy): ";
								cin >> yy;
								recDosen[idUser-1].setTglLahir(dd,mm,yy);
								cout << "Tanggal Lahir Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();
							}	break;
							case 3:{
								cout << "NPP: " << recDosen[idUser-1].getNPP() << endl;
								cout << "Masukkan NPP Baru: ";
								cin >> npp;
								recDosen[idUser-1].setNPP(npp);
								cout << "NPP Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();
							}	break;
							case 4:{
								cout << "Departemen: " << recDosen[idUser-1].getDepartemen() << endl;
								cout << "Masukkan Departemen Baru: ";
								getline(cin >> ws, departemen);
								recDosen[idUser-1].setDepartemen(departemen);
								cout << "Departemen Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();		
							}	break;
							case 5:{
								cout << "Pendidikan: " << recDosen[idUser-1].getPendidikan() << endl;
								cout << "Masukkan Pendidikan Baru: ";
								cin >> pendidikan;
								recDosen[idUser-1].setPendidikan(pendidikan);
								cout << "Pendidikan Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore(); cin.ignore();
							}	break;
							default:{
								ClearScreen();
								cout << "Pilihan tidak ditemukan" << endl << endl << "Tekan Enter Untuk Kembali ke Menu Utama";
								cin.ignore();
							}
						}
					}	break;
					case 2:{
							recDosen.erase(recDosen.begin()+idUser-1);
							idD--;
							for(i=0; i<idD; i++){
								recDosen[i].setId(i+1);
							}	
					}	break;
					case 3:{
					}	break;
					default:{
						ClearScreen();
						cout << "Pilihan tidak ditemukan" << endl << endl << "Tekan Enter Untuk Kembali ke Menu Utama";
						cin.ignore();
					}
				}
			}	break;
			case 7:{
				ClearScreen();
				while(recTendik.size() == 0){
					cout << "Belum ada data tendik" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();	cin.ignore();
					return main();
					}
				cout << "LIST TENDIK" << endl;
				cout << "-----------" << endl;
				for(i=0; i<recTendik.size(); i++){
					cout << "ID: " << recTendik[i].getId() << " | Nama: " << recTendik[i].getNama() << " | NPP: " << recTendik[i].getNPP()   <<endl;
				}
				cout << endl;
				cout << "Masukan ID User: "; 
				cin >> idUser;
				ClearScreen();
				while(idUser > recTendik.size()){
					cout << "ID Tendik Tidak Ditemukan" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();		
					cin.ignore();
					return main();
				}
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
						switch (menu_edit){
							case 1:{
								cout << "Nama: " << recTendik[idUser-1].getNama() << endl;
								cout << "Masukkan Nama Baru: ";
								getline(cin >> ws, nama);
								recTendik[idUser-1].setNama(nama);
								cout << "Nama Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();	
							}	break;
							case 2:{
								cout << "Tanggal Lahir: " << recTendik[idUser-1].getTglLahir() << "/" << recTendik[idUser-1].getBulanLahir() << "/" << recTendik[idUser-1].getTahunLahir() << endl<< endl;
								cout << "Masukkan Tanggal Lahir Baru: " << endl;
								cout << "Tanggal (dd): ";
								cin >> dd;
								while(dd > 31){
									cout << endl << "Tanggal tidak bisa lebih dari 31" << endl << "Tanggal (dd): ";
									cin >> dd;
								}
								cout << "Bulan (mm): ";
								cin >> mm;
								while(mm > 12){
									cout << endl << "Bulan tidak bisa lebih dari 12" << endl << "Bulan (mm): ";
									cin >> mm;
								}
								cout << "Tahun (yyyy): ";
								cin >> yy;
								recTendik[idUser-1].setTglLahir(dd,mm,yy);
								cout << "Tanggal Lahir Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();
							}	break;
							case 3:{
								cout << "NPP: " << recTendik[idUser-1].getNPP() << endl;
								cout << "Masukkan NPP Baru: ";
								cin >> npp;
								recTendik[idUser-1].setNPP(npp);
								cout << "NPP Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();
							}	break;
							case 4:{
								cout << "Unit: " << recTendik[idUser-1].getUnit() << endl;
								cout << "Masukkan Unit Baru: ";
								getline(cin >> ws, unit);
								recTendik[idUser-1].setUnit(unit);
								cout << "Unit Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();	
							}	break;
						}
					}	break;
					case 2:{
							recTendik.erase(recTendik.begin()+idUser-1);
							idT--;
							for(i=0; i<idT; i++){
								recTendik[i].setId(i+1);
							}
					}	break;
					case 3:{
					}	break;
					default:{
						ClearScreen();
						cout << "Pilihan tidak ditemukan" << endl << endl << "Tekan Enter Untuk Kembali ke Menu Utama";
						cin.ignore();
					}
				}	break;
			}	break;
			case 8:{
				ClearScreen();
				while(recMatKul.size() == 0){
					cout << "Belum ada data mata kuliah" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();	cin.ignore();
					return main();
					}
				cout << "LIST MATA KULIAH" << endl;
				cout << "----------------" << endl;
				for(i=0; i<recMatKul.size(); i++){
					cout << "ID: " << recMatKul[i].getID() << "| Kode: " << recMatKul[i].getKode() << " | Nama: " << recMatKul[i].getNama() << " | SKS: " << recMatKul[i].getSKS() <<endl;
				}
				cout << endl;
				cout << "Masukan Kode Mata Kuliah: "; 
				cin >> idUser;
				ClearScreen();
				while(idUser > recMatKul.size()){
					cout << "Kode Mata Kuliah Tidak Ditemukan" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();		
					cin.ignore();
					return main();
				}
				cout << "DATA MATA KULIAH " << idUser << endl;
				cout << "-----------------" << endl;
				cout << "ID Mata Kuliah: " << idUser << endl;
				cout << "Nama: " << recMatKul[idUser-1].getNama() << endl;
				cout << "Kode: " << recMatKul[idUser-1].getKode() << endl;
				cout << "SKS: " << recMatKul[idUser-1].getSKS() << endl << endl;
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
						cout << "MENU EDIT MATA KULIAH" << endl;
						cout << "---------------------" << endl;
						cout << "Menu: " << endl;
						cout << "  1. Edit Nama" << endl;
						cout << "  2. Edit Kode" << endl;
						cout << "  3. Edit Jumlah SKS" << endl;
						cout << "-> Silahkan memilih salah satu: ";
						cin >> menu_edit;
						cout << endl;
						switch (menu_edit){
							case 1:{
								cout << "Nama: " << recMatKul[idUser-1].getNama() << endl;
								cout << "Masukkan Nama Baru: ";
								getline(cin >> ws, nama);
								recMatKul[idUser-1].setNama(nama);
								cout << "Nama Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();	
							}	break;
							case 2:{
								cout << "Kode: " << recMatKul[idUser-1].getKode() << endl;
								cout << "Masukkan Kode Baru: ";
								cin >> kodeMK;
								recMatKul[idUser-1].setKode(kodeMK);
								cout << "Kode Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();
							}	break;
							case 3:{
								cout << "Jumlah SKS: " << recMatKul[idUser-1].getSKS() << endl;
								cout << "Masukkan Jumlah SKS Baru: ";
								cin >> sks;
								recMatKul[idUser-1].setSKS(sks);
								cout << "Jumlah SKS Telah Berhasil Diubah" << endl << endl;
								cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
								cin.ignore();
							}	break;
						}
					}	break;
					case 2:{
							recMatKul.erase(recMatKul.begin()+idUser-1);
							idMK--;
							for(i=0; i<idMK; i++){
								recMatKul[i].setID(i+1);
							}
					}	break;
					case 3:{
					}	break;
					default:{
						ClearScreen();
						cout << "Pilihan tidak ditemukan" << endl << endl << "Tekan Enter Untuk Kembali ke Menu Utama";
						cin.ignore();
					}
				}	break;
			}	break;
			case 9:{ 
				menu_user=0;
				return main();
			}	break;
			case 10:{
				ClearScreen();
				return 0;
			}	break;
			default:{
				ClearScreen();
				cout << "Pilihan tidak ditemukan" << endl << endl << "Tekan Enter Untuk Kembali ke Menu Utama";
				cin.ignore();
			} break;
		}
		cin.clear(); cin.ignore();
	}
	//Interface Mahasiswa
	while(menu_user==2){
		if(isLoggedIn == false){
			while(idM==0){
				ClearScreen();
				cout << "Database Mahasiswa Masih Kosong" << endl << endl;
				cout << "Tekan Tombol Enter Untuk Kembali Ke Menu Utama";
				cin.ignore(); cin.ignore();
				menu_user=0;
				return main();
				} 
			cout << "Masukkan ID Mahasiswa Anda: ";
			cin >> idM;
			while(idM > recMhs.size()){
			cout << "ID Mahasiswa Tidak Ditemukan" << endl << endl;
			cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
			cin.ignore(); cin.ignore();
			menu_user=0;
			return main();
			}
		isLoggedIn = true;
		}
		ClearScreen();
		cout << "Selamat datang di SIAKAD Universitas Anak Bulan, " << recMhs[idM-1].getNama() << endl;
		cout << "-----------------------------------------------------------" << endl << endl;
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
		cout << "  2. Cek Mata Kuliah" << endl;
		cout << "  3. Logout" << endl;
		cout << "  4. Keluar Program" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		switch (menu_terpilih){
			case 1:{
				ClearScreen();
				cout << "IP SEMESTER & KUMULATIF" << endl;
				cout << "-----------------------" << endl;
				if(recMhs[idM-1].getIPS(1) == 0 && recMhs[idM-1].getIPS(2) == 0){
					cout << "IP Semester dan IP Kumulatif Anda Belum Terisi" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();		
					cin.ignore();
					return main();
				}
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
						cin.ignore(); cin.ignore();
				}	break;
			case 2:{
				ClearScreen();
				while(recMhs[idM-1].matKulTerambil.size() == 0){
					cout << "Belum ada data mata kuliah" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();	cin.ignore();
					return main();
					}
				cout << "LIST MATA KULIAH " << recMhs[idM-1].getNama() << endl;
				cout << "------------------------------------------------" << endl;
				for(i=0; i<recMhs[idM-1].matKulTerambil.size(); i++){
					cout << "ID: " << recMhs[idM-1].matKulTerambil[i].getID() << " | Kode: " << recMhs[idM-1].matKulTerambil[i].getKode() << " | Nama: " << recMhs[idM-1].matKulTerambil[i].getNama() << " | SKS: " << recMhs[idM-1].matKulTerambil[i].getSKS() << endl;
					}
				cout << endl << "Tekan Enter Untuk Kembali ke Menu Utama...";
				cin.ignore();
				}	break;
			case 3:{
				menu_user = 0;
				isLoggedIn = false;
				return main();
				}	break;
			case 4:{
				ClearScreen();
				return 0;
				}	break;
			default:{
				ClearScreen();
				cout << "Pilihan tidak ditemukan" << endl << endl << "Tekan Enter Untuk Kembali ke Menu Utama";
				cin.ignore();
			} break;
		}
		cin.clear(); cin.ignore();
	}
	//Interface Dosen
	while(menu_user==3){
		if(isLoggedIn == false){
			while(idD==0){
				ClearScreen();
				cout << "Database Dosen Masih Kosong" << endl << endl;
				cout << "Tekan Tombol Enter Untuk Kembali Ke Menu Utama";
				cin.ignore();
				cin.ignore();
				menu_user=0;
				return main();
			} 
			cout << "Masukkan ID Dosen Anda: ";
			cin >> idD;
			while(idD > recDosen.size()){
				cout << "ID Dosen Tidak Ditemukan" << endl << endl;
				cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
				cin.ignore();		
				cin.ignore();
				menu_user=0;
				return main();
			} 
			isLoggedIn = true;
		}		
		ClearScreen();
		cout << "Selamat datang di SIAKAD Universitas Anak Bulan" << endl;
		cout << "-----------------------------------------------" << endl << endl;
		cout << "DATA DOSEN" << endl;
		cout << "----------" << endl;
		cout << "ID Dosen: " << idD << endl;
		cout << "Nama: " << recDosen[idD-1].getNama() << endl;
		cout << "Tanggal Lahir: " << recDosen[idD-1].getTglLahir() << "/" << recDosen[idD-1].getBulanLahir() << "/" << recDosen[idD-1].getTahunLahir() << endl;
		cout << "NPP: " << recDosen[idD-1].getNPP() << endl;
		cout << "Departemen: " << recDosen[idD-1].getDepartemen() << endl;
		cout << "Pendidikan: " << recDosen[idD-1].getPendidikan() << endl << endl;
		cout << "Menu: " << endl;
		cout << "  1. Input IP Semester Mahasiswa" << endl;
		cout << "  2. Logout" << endl;
		cout << "  3. Keluar Program" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;
		switch (menu_terpilih){
			case 1:{
				while(idM==0){
					ClearScreen();
					cout << "Database Mahasiswa Masih Kosong" << endl << endl;
					cout << "Tekan Tombol Enter Untuk Kembali Ke Menu Utama";
					cin.ignore();
					cin.ignore();
					return main();
				} 
				ClearScreen();
				cout << "MENU INPUT IP SEMESTER MAHASISWA" << endl;
				cout << "--------------------------------" << endl;
				cout << "Masukkan ID Mahasiswa: ";
				cin >> idM;
				if(idM > recMhs.size()){
					cout << endl << "ID Mahasiswa Tidak Ditemukan" << endl << endl;
					cout << "Tekan Enter Untuk Kembali ke Menu Utama...";
					cin.ignore();
					cin.ignore();
					return main();
				}
				cout << endl;
				cout << "Nama Mahasiswa: " << recMhs[idM-1].getNama() << endl;
				cout << "NRP Mahasiswa: " << recMhs[idM-1].getNRP() << endl << endl;
				for(i=1; i<=recMhs[idM-1].getSemester(); i++){
					cout << "Input IP Semester " << i << ": ";
					semester = i;
					cin >> ips;
					while(ips>4.0){
						cout << endl << "IP Semester tidak bisa lebih besar dari 4.0" << endl << endl;
						cout << "Input IP Semester " << i << ": ";
						cin >> ips;
					}
					recMhs[idM-1].setIPS(semester, ips);
				}
				cout << endl << "Tekan Enter Untuk Kembali ke Menu Utama...";
				cin.ignore();
				}	break;
			case 2:{
				menu_user=0;
				isLoggedIn = false;
				return main();
				}	break;
			case 3:{
				ClearScreen();
				return 0;
				}	break;
			default:{
				ClearScreen();
				cout << "Pilihan tidak ditemukan" << endl << endl << "Tekan Enter Untuk Kembali ke Menu Utama";
				cin.ignore();
			} break;
		}
		cin.clear(); cin.ignore();
	}
	return 0;
}