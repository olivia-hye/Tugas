#ifndef __MATAKULIAH_HPP__
#define __MATAKULIAH_HPP__

class matkul
{
    private:
    int idMatKul;
    std::string namaMatKul;
    std::string kodeMatKul;
    int sksMatKul;
    
    public:
    matkul();
    matkul(int IdMatKul, std::string NamaMatKul, std::string KodeMatKul, int SksMatKul);
    void setID(int IdMatKul);
    void setNama(std::string NamaMatKul);
    void setKode(std::string KodeMatKul);
    void setSKS(int SksMatKul);
    int getID();
    std::string getNama();
    std::string getKode();
    int getSKS();
};
#endif