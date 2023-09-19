


//TAYYAB SHAHID        19F-0911
//AHMAD ZUNAIR         19F-0987



#include<iostream> 
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class New_Student
{
protected:
	string First_Name;
	string Last_Name;
	string Blood_Group;
	string Your_Class;
	string Address;
	int Roll_Number;
	string Registration_Date;
	string Gender;
	string Contact_Number;
	string Father_Name;
	string Father_Profession;
	string Parent_Contact;
public:
	void Get_Data()
	{
		cin.ignore();
		cout << "First Name: ";
		getline(cin, First_Name);
		cout << "Last Name: ";
		getline(cin, Last_Name);
		cout << "Class Number: ";
		getline(cin, Your_Class);
		cout << "Blood Group: ";
		getline(cin, Blood_Group);
		cout << "Address: ";
		getline(cin, Address);
		cout << "Registration Date: ";
		getline(cin, Registration_Date);
		cout << "Gender: ";
		getline(cin, Gender);
		cout << "Contact Number: ";
		getline(cin, Contact_Number);
		cout << endl << "Father Name: ";
		getline(cin, Father_Name);
		cout << "Father Profession: ";
		getline(cin, Father_Profession);
		cout << "Parent Contact: ";
		getline(cin, Parent_Contact);
		cout << endl << endl;
		srand(time(0));
		Roll_Number = rand() % 1000;
		cout << "Your Roll Number is '" << Your_Class << Roll_Number << "'" << endl;
	}
	void Show_Data()
	{
		cout << "Your Name is '" << First_Name << " " << Last_Name << "'" << endl;
		cout << "Your Father Name is '" << Father_Name << "'" << endl;
		cout << "Your Father's Profession is '" << Father_Profession << "'" << endl;
		cout << "Your Contact Number is '" << Contact_Number << "'" << endl;
		cout << "Your Father's Contact Number is '" << Parent_Contact << "'" << endl;
		//cout << "Your Class is '" << Your_Class << "'" << endl;
		cout << "Your Blood Group is '" << Blood_Group << "'" << endl;
		cout << "Your Address is '" << Address << "'" << endl;
		cout << "Your Roll Number is '" << Your_Class << Roll_Number << "'" << endl;
		cout << "\n-------------------------------------------------------------------\n";
	}
	string inline ret_Fname() { return First_Name; }
	string inline ret_Lname() { return Last_Name; }
	string inline ret_Blood() { return Blood_Group; }
	string inline ret_YClass() { return Your_Class; }
	string inline ret_Address() { return Address; }
	string inline ret_PContact() { return Parent_Contact; }
	string inline ret_RegistrationDate() { return Registration_Date; }
	string inline ret_Gender() { return Gender; }
	string inline ret_ContactNumber() { return Contact_Number; }
	string inline ret_FatherName() { return Father_Name; }
	string inline ret_FatherProfession() { return Father_Profession; }
	int inline ret_RollNo() { return Roll_Number; }
	void WriteStudentData()
	{
		New_Student input;
		input.Get_Data();
		fstream fout;
		fout.open("Student.txt", ios::out | ios::app);
		if (fout.fail())
		{
			cout << "File Does Not Exist: " << endl;
		}
		else
		{
			fout << input.ret_YClass() << input.ret_RollNo() << "\t" << input.ret_Fname() << " " << input.ret_Lname() << "\t" << input.ret_FatherName() << "\t" << "\t" << input.ret_Blood() << "\t";
			fout << input.ret_Address() << "\t" << input.ret_RegistrationDate() << "\t" << input.ret_Gender() << "\t" << input.ret_ContactNumber() << "\t";
			fout << input.ret_FatherProfession() << "\t" << input.ret_PContact() << endl;
		}
		fout.close();
	}
	void readStudentData()
	{

		fstream fin;
		fin.open("Student.txt", ios::in);
		if (fin.fail())
		{
			cout << "File Does Not Exist: " << endl;
		}
		else
		{
			while (!fin.eof())
			{
				fin >> Roll_Number >> First_Name >> Last_Name >> Father_Name >> Blood_Group >> Address >> Registration_Date >> Gender >> Contact_Number >> Father_Profession >> Parent_Contact;
				Show_Data();
			}
			fin.close();
		}
	}
	void editStudentData()
	{
		New_Student getdata[50];
		int n = 0;
		fstream fin, fout;
		int search_roll;
		fin.open("Student.txt", ios::in);
		fout.open("Re-Student.txt", ios::out);
		if (fin.fail())
		{
			cout << "File Does Not Exist: " << endl;
		}
		else
		{
			while (!fin.eof())
			{
				fin >> Roll_Number >> First_Name >> Last_Name >> Father_Name >> Blood_Group >> Address >> Registration_Date >> Gender >> Contact_Number >> Father_Profession >> Parent_Contact;
				getdata[n].First_Name = First_Name;
				getdata[n].Last_Name = Last_Name;
				getdata[n].Blood_Group = Blood_Group;
				getdata[n].Address = Address;
				getdata[n].Registration_Date = Registration_Date;
				getdata[n].Gender = Gender;
				getdata[n].Contact_Number = Contact_Number;
				getdata[n].Father_Name = Father_Name;
				getdata[n].Father_Profession = Father_Profession;
				getdata[n].Parent_Contact = Parent_Contact;
				getdata[n].Roll_Number = Roll_Number;
				n++;
			}
			cout << "\nEnter the Roll No For Editing:  " << endl;
			cin >> search_roll;
			for (int i = 0; i <= n; i++)
			{
				if (getdata[i].Roll_Number == search_roll)
				{
					getdata[i].Get_Data();
					break;
				}
			}
			if (!fout)
			{
				cout << "File Does Not Exist: " << endl;
			}
			else
			{
				for (int i = 0; i <= n; i++)
				{
					fout << getdata[i].ret_YClass() << getdata[i].ret_RollNo() << "\t" << getdata[i].ret_Fname() << " " << getdata[i].ret_Lname() << "\t" << getdata[i].ret_FatherName() << "\t" << "\t" << getdata[i].ret_Blood() << "\t";
					fout << getdata[i].ret_Address() << "\t" << getdata[i].ret_RegistrationDate() << "\t" << getdata[i].ret_Gender() << "\t" << getdata[i].ret_ContactNumber() << "\t";
					fout << getdata[i].ret_FatherProfession() << "\t" << getdata[i].ret_PContact() << endl;
				}

			}
			fout.close();
			fin.close();
		}
	}
};

class New_Teacher
{
protected:
	string Name;
	string E_Mail;
	string Password;
	string Confirm_Password;
	string CNIC;
	string Gender;
	string Qualification;
	string Contact_Number;
	string Date_of_Birth;
	string Address;
	string Joining_Date;
public:
	void Get_Data()
	{
		cin.ignore();
		cout << "Name: ";
		getline(cin, Name);
		cout << "E-Mail: ";
		getline(cin, E_Mail);
		cout << "Password: ";
		getline(cin, Password);
		cout << "Confirm Password: ";
		getline(cin, Confirm_Password);
		cout << "CNIC: ";
		getline(cin, CNIC);
		cout << "Gender: ";
		getline(cin, Gender);
		cout << "Qualification: ";
		getline(cin, Qualification);
		cout << "Contact Number: ";
		getline(cin, Contact_Number);
		cout << "Date of Birth: ";
		getline(cin, Date_of_Birth);
		cout << "Address: ";
		getline(cin, Address);
		cout << "Joining Date: ";
		getline(cin, Joining_Date);
	}
	void Show_Data()
	{
		cout << "Your Name is '" << Name << "'" << endl;
		cout << "Your E-Mail is '" << E_Mail << "'" << endl;
		cout << "Your Password is '" << Password << "'" << endl;
		cout << "Your CNIC is '" << CNIC << "'" << endl;
		cout << "Your Gender is '" << Gender << "'" << endl;
		cout << "Your Qualification is '" << Qualification << "'" << endl;
		cout << "Your Contact Number is '" << Contact_Number << "'" << endl;
		cout << "Your Date of Birth is '" << Date_of_Birth << "'" << endl;
		cout << "Your Address is '" << Address << "'" << endl;
		cout << "Your Joining Date is '" << Joining_Date << "'" << endl;
		cout << "\n--------------------------------------------------------------------------------\n";
	}
	string inline ret_Name() { return Name; }
	string inline ret_Email() { return E_Mail; }
	string inline ret_Password() { return Password; }
	string inline ret_ConformPassword() { return Confirm_Password; }
	string inline ret_Address() { return Address; }
	string inline ret_CNIC() { return CNIC; }
	string inline ret_Gender() { return Gender; }
	string inline ret_Qualification() { return Qualification; }
	string inline ret_ContactNumber() { return Contact_Number; }
	string inline ret_DateOfBirth() { return Date_of_Birth; }
	string inline ret_JoingDate() { return Joining_Date; }
	void WriteData()
	{
		New_Teacher input;
		input.Get_Data();
		fstream fout;
		fout.open("Teacher.txt", ios::out | ios::app);
		if (fout.fail())
		{
			cout << "File Does Not Exist: " << endl;
		}
		else
		{
			fout << input.ret_Name() << "\t" << input.ret_Email() << "\t" << input.ret_Password() << "\t" << input.ret_ConformPassword() << "\t" << input.ret_CNIC() << "\t" << "\t" << input.ret_Gender() << "\t";
			fout << input.ret_Qualification() << "\t" << input.ret_ContactNumber() << "\t" << input.ret_DateOfBirth() << "\t" << input.ret_Address() << "\t" << input.ret_JoingDate() << "\n";

		}
		fout.close();
	}
	void readData()
	{
		fstream fin;
		fin.open("Teacher.txt", ios::in);
		if (fin.fail())
		{
			cout << "File Does Not Exist: " << endl;
		}
		else
		{
			while (!fin.eof())
			{
				fin >> Name >> E_Mail >> Password >> Confirm_Password >> CNIC >> Gender >> Qualification >> Contact_Number >> Date_of_Birth >> Address >> Joining_Date;
				Show_Data();
			}
			fin.close();
		}
	}
	void editData()
	{
		New_Teacher getdata[50];
		int n = 0;
		fstream fin, fout;
		string name;
		fin.open("Teacher.txt", ios::in);
		fout.open("Re-Teacher.txt", ios::out);
		if (fin.fail())
		{
			cout << "File Does Not Exist: " << endl;
		}
		else
		{
			while (!fin.eof())
			{
				fin >> Name >> E_Mail >> Password >> Confirm_Password >> CNIC >> Gender >> Qualification >> Contact_Number >> Date_of_Birth >> Address >> Joining_Date;
				getdata[n].Name = Name;
				getdata[n].E_Mail = E_Mail;
				getdata[n].Password = Password;
				getdata[n].Address = Address;
				getdata[n].Confirm_Password = Confirm_Password;
				getdata[n].Gender = Gender;
				getdata[n].Contact_Number = Contact_Number;
				getdata[n].CNIC = CNIC;
				getdata[n].Qualification = Qualification;
				getdata[n].Date_of_Birth = Date_of_Birth;
				getdata[n].Joining_Date = Joining_Date;
				n++;
			}
			cout << "\nEnter the Roll No For Editing:  " << endl;
			cin >> name;
			for (int i = 0; i <= n; i++)
			{
				if (getdata[i].Name == name)
				{
					getdata[i].Get_Data();
					break;
				}
			}
			if (!fout)
			{
				cout << "File Does Not Exist: " << endl;
			}
			else
			{
				for (int i = 0; i <= n; i++)
				{
					fout << getdata[i].ret_Name() << getdata[i].ret_Email() << "\t" << getdata[i].ret_Password() << " " << getdata[i].ret_ConformPassword() << "\t" << getdata[i].ret_CNIC() << "\t" << "\t" << getdata[i].ret_Gender() << "\t";
					fout << getdata[i].ret_Qualification() << "\t" << getdata[i].ret_ContactNumber() << "\t" << getdata[i].ret_DateOfBirth() << "\t" << getdata[i].ret_Address() << "\t";
					fout << getdata[i].ret_JoingDate() << "\n";
				}

			}
			fout.close();
			fin.close();
		}
	}

};

class New_Course
{
protected:
	string Course_Name;
	string Course_Code;
	string Select_Class;
public:
	void Get_Data()
	{

		cout << "Course Registration: " << endl;
		cout << "Course Name: ";
		cin.ignore();
		getline(cin, Course_Name);
		cout << "Course Code: ";
		getline(cin, Course_Code);
		cout << "Class: ";
		getline(cin, Select_Class);

	}
	void Show_Data()
	{
		cout << "Congratulations! You have registered the Course" << endl;
		cout << "Course Details: " << endl;
		cout << "The Name of the Course is '" << Course_Name << "'" << " and its Code is '" << Course_Code << "'" << endl;
		cout << "\n-------------------------------------------------------\n";
	}
	void disp()
	{
		cout << "Your Course Detil is:      Course Name  " << Course_Name << "     Course Code is:     " << Course_Code << endl;
	}
	string inline ret_CourseName() { return Course_Name; }
	string inline ret_CourseCode() { return Course_Code; }
	string inline ret_SelectClass() { return Select_Class; }
	void WriteCourse()
	{
		New_Course input;
		input.Get_Data();
		fstream fout;
		fout.open("Course.txt", ios::out | ios::app);
		if (fout.fail())
		{
			cout << "File Does Not Exist: " << endl;
		}
		else
		{
			fout << input.ret_CourseName() << "\t" << input.ret_CourseCode() << "\t" << input.ret_SelectClass() << "\n";
		}
		fout.close();
	}
	void readCourse()
	{

		fstream fin;
		fin.open("Course.txt", ios::in);
		if (fin.fail())
		{
			cout << "File Does Not Exist: " << endl;
		}
		else
		{
			while (!fin.eof())
			{
				fin >> Course_Name >> Course_Code >> Select_Class;
				disp();
			}
			fin.close();
		}
	}
};

class Assign_Course
{
protected:
	string Teacher_Name;
	string Course;
	int Random;
public:
	void Get_Data()
	{
		cout << "Enter the Teacher's Name: " << endl;
		cin.ignore();
		getline(cin, Teacher_Name);
		cout << "Enter his/her Course Name: " << endl;
		getline(cin, Course);
		Random = rand() % 10 + 1;
	}
	void Show_Data()
	{
		cout << "Mr/Ms/Mrs.   '" << Teacher_Name << "'" << " will get the Course of '" << Course << "'" << " for class " << Random << endl;
	}
	string inline ret_TeacherName() { return Teacher_Name; }
	string inline ret_Course() { return Course; }
	void writeAssignCourse()
	{
		Assign_Course input;
		input.Get_Data();
		fstream fout;
		fout.open("AssignCourse.txt", ios::out | ios::app);
		if (!fout)
		{
			cout << "File Does Not Exist:  " << endl;
		}
		else
		{
			fout << input.ret_TeacherName() << "\t" << input.ret_Course() << endl;
			Show_Data();
		}
	}
};

class Student_Marks
{
protected:
	int Roll_Number;
	string Course_Name;
	float Marks;
	float Total_Marks = 0;
public:
	void Get_Data()
	{
		cout << "Enter Your Roll Number: ";
		cin >> Roll_Number;
		cout << "Enter Course Name: ";
		getline(cin, Course_Name);
		cout << "Enter Your Obtained Marks: ";
		cin >> Marks;
		Total_Marks = Total_Marks + Marks;
		cout << "Marks Updated: " << endl;
		cout << "Your Total Marks are " << Total_Marks << endl;
	}
	void Show_Data()
	{
		cout << "Your Total Marks are " << Total_Marks << endl;
	}
};

class Fee_Status
{
protected:
	int Course;
	float Credit_Hours;
	int Fee;
public:
	void Get_Data()
	{
		cout << "Enter Your Number of Cources: ";
		cin >> Course;
		cout << "Enter Your Credit Hours: ";
		cin >> Credit_Hours;
		Fee = Credit_Hours * Course * 4000;
		cout << "Your Total Fees is '" << Fee << "/-'" << endl;
	}
};


int main()
{
	char  Option;
	Assign_Course Obj4;
	Student_Marks Obj5;
	Fee_Status Obj6;
	int s;// for Admin selection.//
	char option;
	int m;// for teacher,View Marks etc.//
	cout << "Press 1 for Admin: " << endl;
	cout << "Press 2 to enter Details" << endl;
	cin >> m;
	if (m == 1)
	{
		cout << "Press 1 For Student data: " << endl;
		cout << "Press 2 For Teacher Data: " << endl;
		cout << "Press 3 For Course Detail: " << endl;
		cout << "Enter 4 For Assign the Course: " << endl;
		cin >> s;
		if (s == 1)
		{

			New_Student S_obj, S_readData, S_edit;
			cout << "Do You Want To Enter the Stuedent Data:  y/n   " << endl;
			cin >> option;
			while (option == 'y')
			{
				S_obj.WriteStudentData();             // Set the Student Data and Write on the File. //
				cout << "\n Do You Want To Enter Data Again:  y/n   " << endl;
				cin >> option;
			}
			cout << "Do You Want Raed the Data of the Student:  y/n  " << endl;
			cin >> option;
			if (option == 'y')
			{
				S_readData.readStudentData();    // Read the Data From the file. //
			}
			cout << "Do You Want To Edit the Student Data: " << endl;
			cin >> option;
			if (option == 'y')
			{
				S_edit.editStudentData();      // Call Edit Data Function of Student. //
			}
		}

		if (s == 2)
		{
			New_Teacher T_obj, T_readData, T_editData;
			cout << "Do You Want To Enter the Teacher data:  y/n   " << endl;
			cin >> option;
			while (option == 'y')
			{
				T_obj.WriteData();             // Set the Teacher Data and Write on the File. //
				cout << "\n Do You Want To Enter Data Again:  y/n   " << endl;
				cin >> option;
			}
			cout << "Do You Want Raed the Data of the Student:  y/n  " << endl;
			cin >> option;
			if (option == 'y')
			{
				T_readData.readData();    // Read the Data From the file. //
			}
			cout << "Do You Want To Edit of the Teacher Data: " << endl;
			cin >> option;
			if (option == 'y')
			{
				T_editData.editData();      // Call Edit Data Function of the Teacher. //
			}
		}
		if (s == 3)
		{
			New_Course C_obj, C_readCourse;
			cout << "Do You Want To Enter the Course Name:  y/n   " << endl;
			cin >> option;
			while (option == 'y')
			{
				C_obj.WriteCourse();             // Set the Course Data and Write on the File. //
				cout << "\n Do You Want To Enter Data Again:  y/n   " << endl;
				cin >> option;
			}
			cout << "Do you Want to Seen the Alla Courses:    y/n " << endl;
			cin >> option;
			if (option == 'y')
			{
				C_readCourse.readCourse();          // Show All Course. //
			}
		}
		if (s == 4)
		{
			Assign_Course A_obj;
			cout << "Do You Want to Assign The Course:  y/n " << endl;
			cin >> option;
			while (option == 'y')
			{
				A_obj.writeAssignCourse();        // Assign The Course. //
				cout << "Do You Want To Assign The Course Again:  y/n " << endl;
				cin >> option;
			}
		}
	}

	if (m == 2)
	{
		cout << "Do You want to Update Student's Marks (y/n): ";
		cin >> Option;
		if (Option == 'y' || Option == 'Y')
		{
			Obj5.Get_Data();
		}
		cout << "Do You want to Check Student's Marks (y/n): ";
		cin >> Option;
		if (Option == 'y' || Option == 'Y')
		{
			Obj5.Show_Data();
		}
		cout << endl << "Fee Status: " << endl;
		Obj6.Get_Data();

		cout << "Teacher Cources: " << endl;
		Obj4.Show_Data();
	}

	cout << endl << endl;
	system("pause");
	return 0;
}
