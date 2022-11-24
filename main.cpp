#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
    string firstName;
    string lastName;
public:
    void print() const;
    void setname(string first, string last);
    string getfirstname() const;
    string getlastname() const;
    Person(string first = "", string last = "");
};

// soal no 11 a
class Doctor: public Person
{
    private:
    string speciality;
    public:
    void setspeciality(string spc);
    string doctorspeciality();
    Doctor(string spc="General");
};

// soal no 11 b
class Bill
{
    private:
    string ID;
    int day;
    int quantity;
public:
    void setpatient(string _ID, int _day, int _quantity);
    void patientID();
    double hospitalcharge();
    double pharmacycharge();
    double doctorfee();
    double roomcharge();
    void patientcharge();
    Bill(string _ID, int _day, int _quantity);
};

// soal no 11 c
class Patient: public Person
{
    private:
    string physician_name;
    string ageofbirth;
    string adm_day;
    string dis_day;
    public:
    Patient(string _physician_name="", string _ageofbirth="", string _adm_day="", string _dis_day="");
    string physician(string first, string last);
    string setageofbirth(string _age_birth);
    string setadm_day(string _adm_day);
    string setdis_day(string _dis_day);

};

// fungsi class person
void Person::print() const
{
    cout << firstName << " " << lastName << endl;
};
void Person::setname(string first, string last)
{
    firstName = first;
    lastName = last;
};
string Person::getfirstname() const
{
    return firstName;
};
string Person::getlastname() const
{
    return lastName;
};
Person::Person(string first, string last)
{
    firstName = first;
    lastName = last;
};

// fungsi class bill
void Bill::setpatient(string _ID, int _day, int _quantity)
{
    ID = _ID;
    day = _day;
    quantity = _quantity;
};
void Bill::patientID()
{
    cout << "Patient id: " << ID << endl;
};
double Bill::hospitalcharge()
{
    double hp_charge = (100000 * day);
    return (hp_charge);
};
double Bill::pharmacycharge()
{
    double p_charge = (20000 * quantity);
    return (p_charge);
};
double Bill::doctorfee()
{
    double d_charge = (50000);
    return (d_charge);
};
double Bill::roomcharge()
{
    double r_charge = (20000 * day);
    
    return (r_charge);
};
void Bill::patientcharge()
{
    cout << roomcharge() + doctorfee() + hospitalcharge() + pharmacycharge() << endl;
};
Bill::Bill(string _ID = "0000", int _day= 1, int _quantity= 0)
{
    ID = _ID;
    day = _day;
    quantity = _quantity;
};

// fungsi class doctor
void Doctor::setspeciality(string spc)
{
    speciality = spc;
};
string Doctor::doctorspeciality()
{
    return speciality;
};
Doctor::Doctor(string spc)
{
    speciality = spc;
};


// fungsi class patient
Patient::Patient(string _physician_name, string _ageofbirth, string _adm_day, string _dis_day)
{
    physician_name = _physician_name;
    ageofbirth = _ageofbirth;
    adm_day = _adm_day;
    dis_day = _dis_day;
};
string Patient::physician(string first, string last)
{
    setname(first, last);
    physician_name = getfirstname() + " " + getlastname();
    return physician_name;
};
string Patient::setageofbirth(string _ageofbirth)
{
    ageofbirth = _ageofbirth;
    return ageofbirth;
};
string Patient::setadm_day(string _adm_day)

{
    adm_day = _adm_day;
    return adm_day;
};
string Patient::setdis_day(string _dis_day)
{
    dis_day = _dis_day;
    return dis_day;
};


int main(){

    // fungsi untuk menguji class bill
    string data_id[5] = {"0010", "0029", "0293", "2190", "2134"};
    for (int i = 0; i<5; i++)
    {
        cout << "==================================" << endl;
        Bill pasien;
        pasien.setpatient(data_id[i], i+2, i+2);
        cout << "patient ID: ";
        pasien.patientID();
        cout << "hospital charge: " << pasien.hospitalcharge() << endl;
        cout << "pharmacy charge: "  << pasien.pharmacycharge() << endl;
        cout << "room charge: "  << pasien.roomcharge() << endl;
        cout << "doctor fee: "  << pasien.doctorfee() << endl;
        cout << "total charge: ";
        pasien.patientcharge();
        cout << " ";
    }

    //fungsi untuk menguji class doctor
    string data_1[5] = {"gibs", "blue", "joah", "jeremy", "adam"};
    string data_2[5] = {"soar", "florin", "black", "green", "dani"};
    string data_3[5] = {"spc1", "spc2", "spc3", "spc4", "spc5"};
    for (int i = 0; i<5; i++)
    {
        cout << "==================================" << endl;
        Doctor dokter;
        dokter.setname(data_1[i], data_2[i]);
        cout << "nama dokter: ";
        dokter.print();
        dokter.setspeciality(data_3[i]);
        cout << "Spesialis dokter: " << dokter.doctorspeciality() << endl;
        cout << " ";
    }
    
    // fungsi untuk menguji class patient
    string data_4[5] = {"12/12", "01/01", "01/01", "02/02", "03/03"};
    string data_5[5] = {"12/12/2000", "01/01/2000", "01/01/2000", "02/02/2000", "03/03/2000"};
    for (int i = 0; i<5; i++)
    {
        cout << "==================================" << endl;
        Patient my_patient;
        cout << "physician name: " << my_patient.physician(data_1[i], data_2[i]) << endl;
        cout << "age of birht: " << my_patient.setageofbirth(data_5[i]) << endl;
        cout << "day admit: " << my_patient.setadm_day(data_4[i]) << endl;
        cout << "day of discharge: " << my_patient.setdis_day(data_4[(i+1)%2]) << endl;
        cout << " ";
    }

    return 0;
}