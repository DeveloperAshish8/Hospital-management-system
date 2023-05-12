#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Hospital
{
public:
	string Hos_name;
	string Hos_type;
	int Bed_avail;
	string Hos_contact;
	float bed_price;
	int H_distance;
};

class Patient : public Hospital
{
public:
	string P_name;
	string All_hospital;
	int P_id;
	string P_cnt;
	int P_Payment;
};

// hospital printing function
void printHospitalData(vector<Hospital> &hospitals)
{
	cout << "                        ----------------------- Hospital Data -----------------------------                       " << endl;
	cout << endl;

	cout << "Hospital Name          ";
	cout << "Hospital Type          ";
	cout << "Beds Available         ";
	cout << "Price(per bed)         ";
	cout << "Contact No.            ";
	cout << "Distance";

	cout << endl;

	for (int i = 0; i < hospitals.size(); i++)
	{
		cout << hospitals[i].Hos_name;
		cout << "             ";
		cout << hospitals[i].Hos_type;
		cout << "                      ";
		cout << hospitals[i].Bed_avail;
		cout << "                   ";
		cout << hospitals[i].bed_price;
		cout << "                ";
		cout << hospitals[i].Hos_contact;
		cout << "               ";
		cout << hospitals[i].H_distance;
		cout << "            ";
		cout << endl;
	}
	cout << endl;
}

// Patient data printing function
void printPatientData(vector<Patient> &patients)
{
	cout << "                     ------------------- Registered Patient Data -------------------------                " << endl;
	cout << endl;

	cout << "Patient Name        ";
	cout << "Patient ID          ";
	cout << "Payment             ";
	cout << "Contact No.         ";
	cout << endl;

	for (int i = 0; i < patients.size(); i++)
	{
		cout << patients[i].P_name;
		cout << "               ";
		cout << patients[i].P_id;
		cout << "                  ";
		cout << patients[i].P_Payment;
		cout << "               ";
		cout << patients[i].P_cnt;
		cout << "               ";
		cout << endl;
	}
	cout << endl;
}

// adding patient
void AddPatient(vector<Patient> &patients)
{
	Patient p;
	cout << "Enter the Patient Name: ";
	cin >> p.P_name;
	cout << "Enter the Patient Id: ";
	cin >> p.P_id;
	cout << "Enter the Patient Contact: ";
	cin >> p.P_cnt;
	cout << "Enter the Patient Bill Amount: ";
	cin >> p.P_Payment;
	patients.push_back(p);
	cout << endl;
	cout << endl;
	cout << "Added Succesfully" << endl;
	printPatientData(patients);
}

// adding hospital
void AddHospital(vector<Hospital> &hospitals)
{
	Hospital h;
	cout << "Enter the Hospital Name: ";
	cin >> h.Hos_name;
	cout << "Enter the Hospital_type: ";
	cin >> h.Hos_type;
	cout << "Enter the number of  Beds Available: ";
	cin >> h.Bed_avail;
	cout << "Enter the Contact Number of Hospital: ";
	cin >> h.Hos_contact;
	cout << "Enter the Distance of Hospital: ";
	cin >> h.H_distance;
	cout << "Enter Price per bed: ";
	cin >> h.bed_price;
	hospitals.push_back(h);
	cout << endl;
	cout << "Added Succesfully";
	printHospitalData(hospitals);
}

// After login function
void AdminPanel(vector<Hospital> &hospitals, vector<Patient> &patients)
{
	int password;
	int choice;
	cout << "Please enter the Password to login: ";
	cin >> password;

	if (password == 1234)
	{

		cout << "Please select from the options below:" << endl;
		cout << "1. Register a new Patient" << endl;
		cout << "2. Register a new hospital" << endl;
		cout << "3. Print Existing Hospital Details " << endl;
		cout << "4. Print Existing Patient Details" << endl;
		cout << "5. Logout" << endl;
		cout << " Enter Your Choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			AddPatient(patients);
			AdminPanel(hospitals, patients);
			break;
		case 2:
			AddHospital(hospitals);
			AdminPanel(hospitals, patients);
			break;
		case 3:
			printHospitalData(hospitals);
			break;
		case 4:
			printPatientData(patients);
			break;
		case 5:
			cout << "Succesfully Logged out" << endl;
			AdminPanel(hospitals, patients);
			break;
		}
	}
}

// Management Function
void HospitalManagementSystem(vector<string> &Hospital_name, vector<string> &Hospital_type, vector<int> &Bed_available, vector<string> &H_contact, vector<float> &price, vector<int> &distance, vector<string> &Patient_name, vector<string> &Alloted_hospital, vector<int> &patient_id, vector<string> &P_contact, vector<int> &Payment)
{

	vector<Hospital> hospitals;
	int digit;

	Hospital h;

	for (int i = 0; i < Hospital_name.size(); i++)
	{
		h.Hos_name = Hospital_name[i];
		h.Hos_type = Hospital_type[i];
		h.Bed_avail = Bed_available[i];
		h.Hos_contact = H_contact[i];
		h.H_distance = distance[i];
		h.bed_price = price[i];
		hospitals.push_back(h);
	}
	vector<Patient> patients;
	Patient p;

	for (int i = 0; i < Patient_name.size(); i++)
	{
		p.P_name = Patient_name[i];
		p.P_id = patient_id[i];
		p.P_cnt = P_contact[i];
		p.P_Payment = Payment[i];
		patients.push_back(p);
	}

	cout << endl;

	cout << " Welcome to the Portal," << endl;
	cout << " 1. Display Hospitals near me" << endl;
	cout << " 2. Registered patients Details" << endl;
	cout << " 3. Admin login" << endl;
	cout << "Enter your Input: ";
	cin >> digit;
	cout << endl;

	switch (digit)
	{
	case 1:
		printHospitalData(hospitals);
		break;
	case 2:
		printPatientData(patients);
		break;
	case 3:
		AdminPanel(hospitals, patients);
		break;
	}
}

int main()
{
	/* Hospital DB*/
	vector<string> Hospital_name{"PMCH Patna ", "AIIMS Patna", "Paras HMRI ", "IGIMS Patna", "Ruban MH   "};
	vector<string> Hospital_type{"Govt.", "Govt.", "Pvt. ", "Govt.", "Pvt. "};
	vector<int> Bed_available{10, 32, 80, 13, 44};
	vector<string> H_contact{"0612-34XXX7", "0612-87XXX2", "0612-65XXX9", "0612-56XXX4", "0612-99XXX4"};
	vector<float> price{1232, 1165, 6770, 1163, 9000};
	vector<int> distance{8, 3, 5, 6, 9};

	/* Patient DB*/
	vector<string> Patient_name{"Harshit", "Ritik  ", "Priya  ", "Rohit  ", "Madan  "};
	vector<string> Alloted_hospital{"AIIMS Patna", "PMCH Patna", "Paras HMRI", "Ruban MH", "IGIMS Patna"};
	vector<int> Patient_id{1, 2, 3, 4, 5};
	vector<string> P_contact{"657534XXX7", "298766XXX2", "324565XXX9", "343456XXX4", "1234567XX6"};
	vector<int> Payment{1840, 1520, 9000, 8594, 1920};
	HospitalManagementSystem(Hospital_name, Hospital_type, Bed_available, H_contact, price, distance, Patient_name, Alloted_hospital, Patient_id, P_contact, Payment);
	return 0;
}