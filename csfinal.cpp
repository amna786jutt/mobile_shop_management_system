
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;
	long pos1;
	long pos2;
	long pos3;
	long pos4;
	long pos5;
	long pos6;
	long pos7;
	long pos8;
	long pos9;
	long pos10;
	long pos11;
	long pos12;
	long opos;
	long cpos;
	long opos1;
	long catpos;
	long catpos1;
	void display();
	void discom();
	void discat();
	void category()
	{
		int ch6;
		char cat;
		do
		{
		cout<<"\n -->CATEGORIES";
		cout<<endl;
		cout<<"\n 1.MOBILES";
		cout<<"\n 2.COMPUTER";
		cout<<"\n 3.OTHER";
		cout<<"\n 4.EXIT";
		cout<<endl;
		cout<<"\n Enter your choice :";
		cin>>ch6;
		switch(ch6)
		{
			case 1:display();
						break;
			case 2:discom();
					 break;
			case 3:discat();
					 break;
			case 4:exit(0);
					 break;
			default:cout<<"\n\t SORRY WRONG CHOICE";
		}
		cout<<"\n Want to enter again(y/n):";
		cin>>cat;
		if(cat=='n')
		exit(0);
		clrscr();
		}while(cat=='y'||cat=='Y');
	}
class login
{
	char username[50];
	long pw;
	int userno;
	public:
		 void getpw()
		 {
			cout<<"\n Enter the user name: ";
			cin>>username;
			cout<<endl;
			cout<<"\n Enter the user no. :";
			cin>>userno;
			cout<<endl;
			cout<<"\n Enter the password: ";
			cin>>pw;
			cout<<endl;
		  }
		 long returnpw();
		 int returnuserno();
		 int returnusername(char log[30]);
		 void modifypw();
		 void modifyname();
}lo;
long login::returnpw()
{
	return pw;
}
int login::returnuserno()
{
	return userno;
}
int login::returnusername(char log[30])
{

	return (strcmp(username,log));
}
void login::modifypw()
{
	long newpw;
	cout<<"\n Enter new pass word:";
	cin>>newpw;
	pw=newpw;
}
void login::modifyname()
{
	char newusername[30];
	cout<<"\n Enter new user name:";
	cin>>newusername;
  strcpy(username,newusername);
}
void createpw()
{   char bjkt;
	 ofstream as20("login.dat",ios::out||ios::binary);
	 do
	 {
		lo.getpw();
		as20.write((char*)&lo,sizeof(lo));
		cout<<"\n Do you want to add more user:";
		cin>>bjkt;
	 }while(bjkt=='y'||bjkt=='Y');
	as20.close();
}
class othercategory
{
		float catdis;
		char catcompany[20];
		int catmno;
		char catname[30];
		float catprice;
		public:
			int catReturn();
			void modifycat();
			void catgetdata()
			{
				cout<<"\n Enter the brand:";
				cin>>catcompany;
				cout<<"\n Enter the name :";
				cin>>catname;
				cout<<endl;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<"\n Enter the model no.:";
				cin>>catmno;
				cout<<endl;
				cout<<"\n Enter the price:";
				cin>>catprice;
				cout<<endl;
				cout<<"\n Discount offer:";
				cin>>catdis;
				cout<<endl;
			}
			void catdisplay()
			{
				cout<<"\n Name :"<<catname;
				cout<<endl;
				cout<<"\n Brand:"<<catcompany;
				cout<<"\n\t ~ ~ ~ OTHER DETAILS~ ~ ~";
				cout<<endl;
				cout <<"\n Discount =:"<<catdis;
				cout<<endl;
				cout<<"\n Model no.:"<<catmno;
				cout<<endl;
				cout<<"\n Price:"<<catprice;
				cout<<endl;

			}
}cat;
int othercategory::catReturn()
{
	return catmno;
}
void displaycat()
{
		cout<<"\n OTHER THINGS IN YOUR STOCK ARE:";
		ifstream ds30("othercat.dat",ios::in||ios::binary);
		ds30.seekg(0);
		while(!ds30.eof())
		{
			ds30.read((char*)&cat,sizeof(cat));
			if(ds30.eof())
				break;
			else
			cat.catdisplay();
		}
}
void deletecat()
{
			ifstream ds31("othercat.dat",ios::in||ios::binary);
			ofstream ds32("cattemp1.dat",ios::out||ios::binary);
			int catsearch;
			char catfound='f',catconfirm='n';
			cout<<"\n --> Enter the model no. which is to be deleted from stock:";
			cout<<endl;
			cin>>catsearch;
			ds31.seekg(0);
			while(!ds31.eof())
			{
				ds31.read((char*)&cat,sizeof(cat));
				if(cat.catReturn()==catsearch)
				{
					cat.catdisplay();
					catfound='y';
					cout<<"\n Are you really want to delete this record? (y\n)";
					cin>>catconfirm;
					if(catconfirm=='n')
						ds32.write((char*)&cat,sizeof(cat));
				}
					else
						ds32.write((char*)&cat,sizeof(cat));
			}
			if(catfound=='f')
			cout<<"\n -->Not found";
			cout<<endl;
			ds31.close();
			ds32.close();
			remove("othercat.dat");
			rename("cattemp1.dat","othercat.dat");
			clrscr();
			ifstream ds33("othercat.dat",ios::in||ios::binary);
			cout<<"\n\tNow list of OTHER category are:";
			cout<<endl;
			ds33.seekg(0);
			while(!ds33.eof())
			{
				ds33.read((char*)&cat,sizeof(cat));
				if(ds33.eof())
					break;
						else
						cat.catdisplay();
			}
			ds33.close();
}
void appendcat()
{
		ofstream ds34("othercat.dat",ios::app||ios::binary);
		cout<<"\n --> Enter detail of OTHER  things you want to add"<<"\n";
		cout<<endl;
		cat.catgetdata();
		ds34.seekp(catpos);
		ds34.write((char*)&cat,sizeof(cat));
		ds34.close();
}
void othercategory:: modifycat()
{
		char ctname[20];
		float ctdis;
		int ctmno;
		float ctprice;
		char ctcompany[30];
		cout<<"\n Enter the details :";
		cout<<endl;
		cout<<"\n Enter the new brand:";
		cin>>ctcompany;
		strcpy(catcompany,ctcompany);
		cout<<endl;
		cout<<"\n Enter new name :";
		cin>>ctname;
		strcpy(catname,ctname);
		cout<<endl;
		cout<<"\n Enter new discount :";
		cin>>ctdis;
		catdis=ctdis;
		cout<<endl;
		cout<<"\n Enter new model no:";
		cin>>ctmno;
		catmno=ctmno;
		cout<<endl;
		cout<<"\n Enter new price:";
		cin>>ctprice;
		catprice=ctprice;
		cout<<endl;
}
void discat()
{
	char an1,an8;
	int na1;
	clrscr();
	int z=0;
	ofstream ds35("othercat.dat",ios::out|ios::binary);
	do
	{
			cout<<"\n => Enter the details of "<<(z+1)<<" OTHER THINGS \n";
			cat.catgetdata();
			ds35.write((char *)&cat,sizeof(cat));
			catpos=ds35.tellp();
			cout<<"\n --> Do you want to add more OTHER THINGS :";
			cin>>an1;
			z++;
			clrscr();
	}while(an1=='y'||an1=='Y');
	ds35.close();
	do
	{
			cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * * ";
			cout<<endl;
			cout<<"\n 1:Display the list of OTHER THINGS:";
			cout<<endl;
			cout<<"\n 2:Add more THINGS in the list:";
			cout<<endl;
			cout<<"\n 3:Delete THINGS from the list:";
			cout<<endl;
			cout<<"\n 4:Modify the details of  THINGS:";
			cout<<endl;
			cout<<"\n 5:Want to see category list again:";
			cout<<endl;
			cout<<"\nEnter your choice:";
			cin>>na1;
			if(na1==1)
			{
				clrscr();
				displaycat();
			}
			else if(na1==2)
			{  clrscr();
				appendcat();
			}
			else if(na1==3)
			{  clrscr();
				deletecat();
			}
			else if(na1==4)
			{  clrscr();
				int catmno1;
				char ch70;
				cout<<"\n -->Enter the MODEL no. to be modified : ";
				cin>>catmno1;
				fstream ds36("othercat.dat",ios::in|ios::out|ios::binary);
				ds36.seekg(0);
				while(!ds36.eof())
				{
					catpos1=ds36.tellg();
					ds36.read((char*)&cat,sizeof(cat));
					if(cat.catReturn()==catmno1)
					{
						cat.modifycat();
						ds36.seekg(catpos1);
						ds36.write((char*)&cat,sizeof(cat));
						ch70='y';
						break;
					}
				}
				if (ch70=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(na1==5)
			{  clrscr();
				category();
			}
			cout<<"\n\t* Do YOU WANT TO SEE ABOVE MENU AGAIN *";
			cin>>an8;
			clrscr();
	}while(an8=='y'||an8=='Y');
}

class nokia
{
		float dis1;
		int mno1;
		float price1;
		float cam1;
		float blu1;
		float bat1;
		char name1[20];
		int imem1;
		char and1[20];
		public:
			void modifynokia();
			int Return1();
			void multi1()
			{
				cout<<endl;
				cout<<"\n Camera : ";
				cin>>cam1;
				cout<<endl;
				cout<<"\n Bluetooth : ";
				cin>>blu1;
				cout<<endl;
				cout<<"\n Battery : ";
				cin>>bat1;
				cout<<endl;
				cout<<"\n Internal memory : ";
				cin>>imem1;
				cout<<endl;
				cout<<"\n Android Version : ";
				cin>>and1;
				cout<<endl;
			}

			void getdata1()
			{
				cout<<endl;
				cout<<"\n Enter the name of mobile :";
				cin>>name1;
				cout<<endl;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<endl;
				cout<<"\n Enter the model no. :";
				cin>>mno1;
				cout<<endl;
				cout<<"\n Enter the price :";
				cin>>price1;
				cout<<endl;
				cout<<"\n Discount offer :";
				cin>>dis1;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				multi1();
			}
			void display1()
			{
				cout<<endl;
				cout<<"\n Name of mobile :"<<name1;
				cout<<endl;
				cout<<"\n\t ~ ~ ~OTHER DETAILS~ ~ ~";
				cout<<endl;
				cout <<"\n Discount :"<<dis1;
				cout<<endl;
				cout<<"\n Model no. :"<<mno1;
				cout<<endl;
				cout<<"\n Price:"<<price1;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				cout<<"\n Camera : "<<cam1;
				cout<<"\n Bluetooth : "<<blu1;
				cout<<"\n Battery : "<<bat1;
				cout<<"\n Internal memory : "<<imem1;
				cout<<"\n Android Version : \n"<<and1;

			}
	}n;
	int nokia::Return1()
	{
		return mno1;
	}
	void displaynokia()
	{
		cout<<"\n * NOKIA MOBILES IN YOUR STORE ARE *:";
		cout<<endl;
		ifstream ob6("nokia.dat",ios::in||ios::binary);
		ob6.seekg(0);
		while(!ob6.eof())
		{
			ob6.read((char*)&n,sizeof(n));
			if(ob6.eof())
			break;
			else
			n.display1();
		}
	}
	void appendnokia()
	{
		ofstream ob7("nokia.dat",ios::app||ios::binary);
		cout<<"\n --> Enter detail of NOKIA mobile you want to add"<<"\n";
		cout<<endl;
		n.getdata1();
		ob7.seekp(pos1);
		ob7.write((char*)&n,sizeof(n));
		ob7.close();
	}
	void deletenokia()
	{
			ifstream ob8("nokia.dat",ios::in||ios::binary);
			ofstream ob9("temp1.dat",ios::out||ios::binary);
			int search1;
			char found1='f',confirm1='n';
			cout<<"\n --> Enter the model no of mobile which is to be deleted from stock:";
			cout<<endl;
			cin>>search1;
			ob8.seekg(0);
			while(!ob8.eof())
			{
				ob8.read((char*)&n,sizeof(n));
				if(n.Return1()==search1)
				{
					n.display1();
					found1='y';
					cout<<"\n --> Are you really want to delete this record ?(y\n)";
					cin>>confirm1;
					if(confirm1=='n')
						ob9.write((char*)&n,sizeof(n));
				}
					else
						ob9.write((char*)&n,sizeof(n));
			}
			if(found1=='f')
			cout<<"\n --> Mobile not found";
			cout<<endl;
			ob8.close();
			ob9.close();
			remove("nokia.dat");
			rename("temp1.dat","nokia.dat");
			clrscr();
			ifstream ob10("nokia.dat",ios::in||ios::binary);
			cout<<"\n\t -->Now list of nokia mobile are:";
			cout<<endl;
			ob10.seekg(0);
			while(!ob10.eof())
			{
				ob10.read((char*)&n,sizeof(n));
				if(ob10.eof())
					break;
						else
						n.display1();
			}
			ob10.close();
	 }
	 void nokia:: modifynokia()
	 {
		char nname[20];
		float ndis;
		int nmno;
		float nprice;
		float ncam;
		float nblu;
		float nimem;
		float nbat;
		char nand[20];
		cout<<"\n -->Enter the details:";
		cout<<endl;
		cout<<"\n Enter new name of mobile:";
		cin>>nname;
		cout<<endl;
		strcpy(name1,nname);
		cout<<"\n Enter new discount :";
		cin>>ndis;
		dis1=ndis;
		cout<<endl;
		cout<<"\n Enter new model no :";
		cin>>nmno;
		mno1=nmno;
		cout<<endl;
		cout<<"\n Enter new price :";
		cin>>nprice;
		price1=nprice;
		cout<<endl;
		cout<<"\n Camera :";
		cin>>ncam;
		cam1=ncam;
		cout<<endl;
		cout<<"\n Bluetooth :";
		cin>>nblu;
		blu1=nblu;
		cout<<endl;
		cout<<"\n Internal memory :";
		cin>>nimem;
		imem1=nimem;
		cout<<endl;
		cout<<"\n Battery :";
		cin>>nbat;
		bat1=nbat;
		cout<<endl;
		cout<<"\n Andriod Version:";
		cin>>nand;
		strcpy(and1,nand);
		cout<<endl;
	 }
	class samsung
	{
		char name2[20];
		float dis2;
		int mno2;
		float price2;
		float cam2;
		float blu2;
		float bat2;
		int imem2;
		char and2[20];
		public:
			char Return2();
			void modifysamsung();
			void multi2()
			{
				cout<<"\n Camera : ";
				cin>>cam2;
				cout<<endl;
				cout<<"\n Bluetooth : ";
				cin>>blu2;
				cout<<endl;
				cout<<"\n Battery : ";
				cin>>bat2;
				cout<<endl;
				cout<<"\n Internal memory : ";
				cin>>imem2;
				cout<<endl;
				cout<<"\n Android Version: ";
				cin>>and2;
				cout<<endl;
			}
			void getdata2()
			{
				cout<<"\n Enter the name of mobile :";
				cin>>name2;
				cout<<endl;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<endl;
				cout<<"\n Enter the model no. :";
				cin>>mno2;
				cout<<endl;
				cout<<"\n Enter the price:";
				cin>>price2;
				cout<<endl;
				cout<<"\n Discount offer:";
				cin>>dis2;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				multi2();
			}
			void display2()
			{
				cout<<"\n Name of mobile :"<<name2;
				cout<<endl;
				cout<<"\n ~ ~ ~OTHER DETAILS~ ~ ~";
				cout <<"\n Discount =:"<<dis2;
				cout<<endl;
				cout<<"\n Model no.:"<<mno2;
				cout<<endl;
				cout<<"\n Price:"<<price2;
				cout<<endl;
				cout<<"\n\t* * *Special Features* * *";
				cout<<endl;
				cout<<"\n Camera: "<<cam2;
				cout<<"\n Bluetooth: "<<blu2;
				cout<<"\n Battery: "<<bat2;
				cout<<"\n Internal memory: "<<imem2;
				cout<<"\n Android Version: \n"<<and2;
			}
	}sa;
	char samsung::Return2()
	{
		return mno2;
	}
	void displaysamsung()
	{
		cout<<"\n SAMSUNG MOBILES IN YOUR STORE ARE:";
		ifstream ob12("samsung.dat",ios::in||ios::binary);
		ob12.seekg(0);
		while(!ob12.eof())
		{
			ob12.read((char*)&sa,sizeof(sa));
			if(ob12.eof())
			break;
			else
			sa.display2();
		}
	}
	void appendsamsung()
	{
		ofstream ob13("samsung.dat",ios::app||ios::binary);
		cout<<"\n -->Enter detail of SAMSUNG mobile you want to add"<<"\n";
		sa.getdata2();
		ob13.seekp(pos2);
		ob13.write((char*)&sa,sizeof(sa));
		ob13.close();
	}
	void deletesamsung()
	{
			ifstream ob14("samsung.dat",ios::in||ios::binary);
			ofstream ob15("temp2.dat",ios::out||ios::binary);
			int search2;
			char found2='f',confirm2='n';
			cout<<"\n -->Enter the model no of mobile which is to be deleted from stock:";
			cout<<endl;
			cin>>search2;
			ob14.seekg(0);
			while(!ob14.eof())
			{
				ob14.read((char*)&sa,sizeof(sa));
				if(sa.Return2()==search2)
				{
					sa.display2();
					found2='y';
					cout<<"\n Are you really want to delete this record? (y\n)";
					cout<<endl;
					cin>>confirm2;
					if(confirm2=='n')
						ob15.write((char*)&sa,sizeof(sa));
				}
					else
						ob15.write((char*)&sa,sizeof(sa));
			}
			if(found2=='f')
			cout<<"\n --> Mobile not found";
			cout<<endl;
			ob14.close();
			ob15.close();
			remove("samsung.dat");
			rename("temp2.dat","samsung.dat");
         clrscr();
			ifstream ob16("samsung.dat",ios::in||ios::binary);
			cout<<"\n\tNow list of SAMSUNG mobile are:";
			ob16.seekg(0);
			while(!ob16.eof())
			{
				ob16.read((char*)&sa,sizeof(sa));
				if(ob16.eof())
					break;
						else
						sa.display2();
			}
			ob16.close();
	 }
	void samsung:: modifysamsung()
	 {
		char sname[20];
		float sdis;
		int smno;
		float sprice;
		float scam;
		float sblu;
		float simem;
		float sbat;
		char sand[20];
		cout<<"\n Enter the details:";
		cout<<endl;
		cout<<"\n Enter new name of mobile:";
		cout<<endl;
		cin>>sname;
		strcpy(name2,sname);
		cout<<endl;
		cout<<"\n Enter new discount:";
		cin>>sdis;
		dis2=sdis;
		cout<<endl;
		cout<<"\n Enter new model no:";
		cin>>smno;
		mno2=smno;
		cout<<endl;
		cout<<"\n Enter new price:";
		cin>>sprice;
		price2=sprice;
		cout<<endl;
		cout<<"\n Camera:";
		cin>>scam;
		cam2=scam;
		cout<<endl;
		cout<<"\n Bluetooth:";
		cin>>sblu;
		blu2=sblu;
		cout<<endl;
		cout<<"\n Internal memory:";
		cin>>simem;
		imem2=simem;
		cout<<endl;
		cout<<"\n Battery:";
		cin>>sbat;
		bat2=sbat;cout<<endl;
		cout<<"\n Andriod Version:";
		cin>>sand;
		strcpy(and2,sand);
		cout<<endl;
	 }
	class sony
	{
		float dis3;
		int mno3;
		float price3;
		float cam3;
		float blu3;
		float bat3;
		int imem3;
		char and3[20];
		char name3[20];
		public:
			int Return3();
			void modifysony();
			void multi3()
			{
				cout<<"\n Camera : ";
				cin>>cam3;
				cout<<endl;
				cout<<"\n Bluetooth: ";
				cin>>blu3;
				cout<<endl;
				cout<<"\n Battery: ";
				cin>>bat3;
				cout<<endl;
				cout<<"\n Internal memory: ";
				cin>>imem3;
				cout<<endl;
				cout<<"\n Android Version: ";
				cin>>and3;
				cout<<endl;
			}
			void getdata3()
			{
				cout<<"\n Enter the name of mobile :";
				cin>>name3;
				cout<<endl;
				cout<<"\n\t:::: ENTER OTHER DETAILS :::::";
				cout<<endl;
				cout<<"\n Enter the model no.:";
				cin>>mno3;
				cout<<endl;
				cout<<"\n Enter the price:";
				cin>>price3;
				cout<<endl;
				cout<<"\n Discount offer:";
				cin>>dis3;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				multi3();
			}
			void display3()
			{
				cout<<"\n Name of mobile :"<<name3;
				cout<<endl;
				cout<<"\n\t ~ ~ ~OTHER DETAILS~ ~ ~";
				cout<<endl;
				cout <<"\n Discount =:"<<dis3;
				cout<<endl;
				cout<<"\n Model no.:"<<mno3;
				cout<<endl;
				cout<<"\n Price:"<<price3;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<"\n Camera : "<<cam3;
				cout<<"\n Bluetooth : "<<blu3;
				cout<<"\n Battery : "<<bat3;
				cout<<"\n Internal memory : "<<imem3;
				cout<<"\n Android Version : \n"<<and3;
			}
	}so;
	int sony::Return3()
	{
		return mno3;
	}
	void displaysony()
	{
		cout<<"\nSONY MOBILES ARE:";
		cout<<endl;
		ifstream ob18("sony.dat",ios::in||ios::binary);
		ob18.seekg(0);
		while(!ob18.eof())
		{
			ob18.read((char*)&so,sizeof(so));
			if(ob18.eof())
			break;
			else
			so.display3();
		}
	}
	void appendsony()
	{
		ofstream ob19("sony.dat",ios::app||ios::binary);
		cout<<"\n --> Enter detail of SONY mobile  you want to add"<<"\n";
		so.getdata3();
		ob19.seekp(pos3);
		ob19.write((char*)&so,sizeof(so));
		ob19.close();
	}
	void deletesony()
	{
			ifstream ob20("sony.dat",ios::in||ios::binary);
			ofstream ob21("temp3.dat",ios::out||ios::binary);
			int search3;
			char found3='f',confirm3='n';
			cout<<"\n Enter the model no of mobile which is to be deleted from stock:";
			cin>>search3;
			ob20.seekg(0);
			while(!ob20.eof())
			{
				ob20.read((char*)&so,sizeof(so));
				if(so.Return3()==search3)
				{
					so.display3();
					found3='y';
					cout<<"\n Are you really want to delete this record? (y\n)";
					cin>>confirm3;
					if(confirm3=='n')
						ob21.write((char*)&so,sizeof(so));
				}
					else
						ob21.write((char*)&so,sizeof(so));
			}
			if(found3=='f')
			cout<<"\n --> Mobile not found";
			ob20.close();
			ob21.close();
			remove("sony.dat");
			rename("temp3.dat","sony.dat");
			clrscr();
			ifstream ob22("sony.dat",ios::in||ios::binary);
			cout<<"\n\tNow list of SONY mobiles in your stock:";
			cout<<endl;
			ob22.seekg(0);
			while(!ob22.eof())
			{
				ob22.read((char*)&so,sizeof(so));
				if(ob22.eof())
					break;
						else
						so.display3();
			}
			ob22.close();
	 }
	void sony:: modifysony()
	 {
		char soname[20];
		float sodis;
		int somno;
		float soprice;
		float socam;
		float soblu;
		float soimem;
		float sobat;
		char soand[20];
		cout<<"\n Enter the details :";
		cout<<endl;
		cout<<"\n Enter new name of mobile :";
		cin>>soname;
		strcpy(name3,soname);
		cout<<endl;
		cout<<"\n Enter new discount :";
		cin>>sodis;
		dis3=sodis;
		cout<<endl;
		cout<<"\n Enter new model no :";
		cin>>somno;
		mno3=somno;
		cout<<endl;
		cout<<"\n Enter new price :";
		cin>>soprice;
		price3=soprice;
		cout<<endl;
		cout<<"\n Camera :";
		cin>>socam;
		cam3=socam;
		cout<<endl;
		cout<<"\n Bluetooth :";
		cin>>soblu;
		blu3=soblu;
		cout<<endl;
		cout<<"\n Internal memory :";
		cin>>soimem;
		imem3=soimem;
		cout<<endl;
		cout<<"\n Battery :";
		cin>>sobat;
		bat3=sobat;
		cout<<endl;
		cout<<"\n Andriod Version :";
		cin>>soand;
		strcpy(and3,soand);
		cout<<endl;
	 }
	class life_good
	{
		float dis4;
		int mno4;
		float price4;
		float cam4;
		float blu4;
		float bat4;
		int imem4;
		char and4[20];
		char name4[20];
		public:
			int Return4();
			void modifylg();
			void multi4()
			{
				cout<<"\n Camera : ";
				cin>>cam4;
				cout<<endl;
				cout<<"\n Bluetooth : ";
				cin>>blu4;
				cout<<endl;
				cout<<"\n Battery : ";
				cin>>bat4;
				cout<<endl;
				cout<<"\n Internal memory : ";
				cin>>imem4;
				cout<<endl;
				cout<<"\n Android Version: ";
				cin>>and4;
				cout<<endl;
			}
			void getdata4()
			{
				cout<<"\n Enter the name of mobile :";
				cin>>name4;
				cout<<endl;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<endl;
				cout<<"\n Enter the model no. :";
				cin>>mno4;
				cout<<endl;
				cout<<"\n Enter the price :";
				cin>>price4;
				cout<<endl;
				cout<<"\n Discount offer :";
				cin>>dis4;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				multi4();

			}
			void display4()
			{
				cout<<"\n Name of mobile :"<<name4;
				cout<<endl;
				cout<<"\n\t ~ ~ ~ OTHER DETAILS ~ ~ ~ ";
				cout <<"\n Discount = :"<<dis4;
				cout<<endl;
				cout<<"\n Model no.:"<<mno4;
				cout<<endl;
				cout<<"\n Price:"<<price4;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				cout<<"\n Camera : "<<cam4;
				cout<<"\n Bluetooth : "<<blu4;
				cout<<"\n Battery : "<<bat4;
				cout<<"\n Internal memory : "<<imem4;
				cout<<"\n Android Version : \n"<<and4;
			}
	}lg;
	int life_good::Return4()
	{
		return mno4;
	}
	void displaylg()
	{
		cout<<"\nLG MOBILE IN YOUR STOCK ARE:";
		cout<<endl;
		ifstream ob25("lg.dat",ios::in||ios::binary);
		ob25.seekg(0);
		while(!ob25.eof())
		{
			ob25.read((char*)&lg,sizeof(lg));
			if(ob25.eof())
			break;
			else
			lg.display4();
		}
	}
	void appendlg()
	{
		ofstream ob25("lg.dat",ios::app||ios::binary);
		cout<<"\n -->Enter detail of LG mobile you want to add"<<"\n";
		lg.getdata4();
		ob25.seekp(pos5);
		ob25.write((char*)&lg,sizeof(lg));
		ob25.close();
	}
	void deletelg()
	{
			ifstream ob26("lg.dat",ios::in||ios::binary);
			ofstream ob27("temp4.dat",ios::out||ios::binary);
			int search4;
			char found4='f',confirm4='n';
			cout<<"\n --> Enter the model no of mobile which is to be deleted from stock:";
			cin>>search4;
			ob26.seekg(0);
			while(!ob26.eof())
			{
				ob26.read((char*)&lg,sizeof(lg));
				if(lg.Return4()==search4)
				{
					lg.display4();
					found4='y';
					cout<<"\n Are you really want to delete this record? (y\n)";
					cin>>confirm4;
					if(confirm4=='n')
						ob27.write((char*)&lg,sizeof(lg));
				}
					else
						ob27.write((char*)&lg,sizeof(lg));
			}
			if(found4=='f')
			cout<<"\n --> Mobile not found";
			ob26.close();
			ob27.close();
			remove("lg.dat");
			rename("temp4.dat","lg.dat");
			clrscr();
			ifstream ob28("lg.dat",ios::in||ios::binary);
			cout<<"\n\tNow list of LG mobile are:";
			ob28.seekg(0);
			while(!ob28.eof())
			{
				ob28.read((char*)&lg,sizeof(lg));
				if(ob28.eof())
					break;
						else
						lg.display4();
			}
			ob28.close();
	 }
	void life_good:: modifylg()
	{
		char lname[20];
		float ldis;
		int lmno;
		float lprice;
		float lcam;
		float lblu;
		float limem;
		float lbat;
		char land[20];
		cout<<"\n Enter the details :";
		cout<<endl;
		cout<<"\n Enter new name of mobile :";
		cin>>lname;
		strcpy(name4,lname);
		cout<<endl;
		cout<<"\n Enter new discount:";
		cin>>ldis;
		dis4=ldis;
		cout<<endl;
		cout<<"\n Enter new model no:";
		cin>>lmno;
		mno4=lmno;
		cout<<endl;
		cout<<"\n Enter new price:";
		cin>>lprice;
		price4=lprice;
		cout<<endl;
		cout<<"\n Camera:";
		cin>>lcam;
		cam4=lcam;
		cout<<endl;
		cout<<"\n Bluetooth:";
		cin>>lblu;
		blu4=lblu;
		cout<<endl;
		cout<<"\n Internal memory:";
		cin>>limem;
		imem4=limem;
		cout<<endl;
		cout<<"\n Battery:";
		cin>>lbat;
		bat4=lbat;
		cout<<endl;
		cout<<"\n Andriod Version:";
		cin>>land;
		strcpy(and4,land);
		cout<<endl;
	 }
class othermobile
{
		float odis;
		char company[20];
		int omno;
		float oprice;
		float ocam;
		float oblu;
		float obat;
		int omem;
		char oand[20];
		char oname[20];
		public:
			int oReturn();
			void modifyother();
			void omulti()
			{
				cout<<"\n Camera : ";
				cin>>ocam;
				cout<<endl;
				cout<<"\n Bluetooth : ";
				cin>>oblu;
				cout<<endl;
				cout<<"\n Battery : ";
				cin>>obat;
				cout<<endl;
				cout<<"\n Internal memory : ";
				cin>>omem;
				cout<<endl;
				cout<<"\n Android Version : ";
				cin>>oand;
				cout<<endl;
			}
			void ogetdata()
			{
				cout<<"\n Enter the brand:";
				cin>>company;
				cout<<"\n Enter the name of mobile :";
				cin>>oname;
				cout<<endl;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<"\n Enter the model no.:";
				cin>>omno;
				cout<<endl;
				cout<<"\n Enter the price:";
				cin>>oprice;
				cout<<endl;
				cout<<"\n Discount offer:";
				cin>>odis;
				cout<<endl;
				omulti();
			}
			void odisplay()
			{
				cout<<"\n Name of mobile :"<<oname;
				cout<<endl;
				cout<<"\n Brand:"<<company;
				cout<<"\n\t ~ ~ ~ OTHER DETAILS~ ~ ~";
				cout<<endl;
				cout <<"\n Discount =:"<<odis;
				cout<<endl;
				cout<<"\n Model no.:"<<omno;
				cout<<endl;
				cout<<"\n Price:"<<oprice;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				cout<<"\n Camera : "<<ocam;
				cout<<"\n Bluetooth : "<<oblu;
				cout<<"\n Battery : "<<obat;
				cout<<"\n Internal memory : "<<omem;
				cout<<"\n Android Version : \n"<<oand;

			}
	}ot;
	void displayother()
	{
		cout<<"\n OTHER MOBILE IN YOUR STOCK ARE:";
		ifstream ds1("othermobile.dat",ios::in||ios::binary);
		ds1.seekg(0);
		while(!ds1.eof())
		{
			ds1.read((char*)&ot,sizeof(ot));
			if(ds1.eof())
			break;
			else
			ot.odisplay();
		}
	}
	void deleteother()
	{
			ifstream ds2("othermobile.dat",ios::in||ios::binary);
			ofstream ds10("otemp1.dat",ios::out||ios::binary);
			int osearch;
			char ofound='f',oconfirm='n';
			cout<<"\n --> Enter the model no of mobile which is to be deleted from stock:";
			cout<<endl;
			cin>>osearch;
			ds2.seekg(0);
			while(!ds2.eof())
			{
				ds2.read((char*)&ot,sizeof(ot));
				if(ot.oReturn()==osearch)
				{
					ot.odisplay();
					ofound='y';
					cout<<"\n Are you really want to delete this record? (y\n)";
					cin>>oconfirm;
					if(oconfirm=='n')
						ds10.write((char*)&ot,sizeof(ot));
				}
					else
						ds10.write((char*)&ot,sizeof(ot));
			}
			if(ofound=='f')
			cout<<"\n --> Mobile not found";
			cout<<endl;
			ds10.close();
			ds2.close();
			remove("othermobile.dat");
			rename("otemp1.dat","othermobile.dat");
			clrscr();
			ifstream ds3("othermobile.dat",ios::in||ios::binary);
			cout<<"\n\tNow list of OTHER mobile are:";
			cout<<endl;
			ds3.seekg(0);
			while(!ds3.eof())
			{
				ds3.read((char*)&ot,sizeof(ot));
				if(ds3.eof())
					break;
						else
						ot.odisplay();
			}
			ds3.close();
	 }
	 void appendother()
	{
		ofstream ds4("othermobile.dat",ios::app||ios::binary);
		cout<<"\n --> Enter detail of OTHER mobile you want to add"<<"\n";
		cout<<endl;
		ot.ogetdata();
		ds4.seekp(opos);
		ds4.write((char*)&ot,sizeof(ot));
		ds4.close();
	}
	int othermobile::oReturn()
	{
		return omno;
	}
	void othermobile:: modifyother()
	 {
		char otname[20];
		float otdis;
		int otmno;
		float otprice;
		float otcam;
		float otblu;
		float otmem;
		float otbat;
		char otand[20];
		cout<<"\n Enter the details :";
		cout<<endl;
		cout<<"\n Enter new name of mobile :";
		cin>>otname;
		strcpy(oname,otname);
		cout<<endl;
		cout<<"\n Enter new discount :";
		cin>>otdis;
		odis=otdis;
		cout<<endl;
		cout<<"\n Enter new model no:";
		cin>>otmno;
		omno=otmno;
		cout<<endl;
		cout<<"\n Enter new price:";
		cin>>otprice;
		oprice=otprice;
		cout<<endl;
		cout<<"\n Camera :";
		cin>>otcam;
		ocam=otcam;
		cout<<endl;
		cout<<"\n Bluetooth :";
		cin>>otblu;
		oblu=otblu;
		cout<<endl;
		cout<<"\n Internal memory :";
		cin>>otmem;
		omem=otmem;
		cout<<endl;
		cout<<"\n Battery :";
		cin>>otbat;
		obat=otbat;
		cout<<endl;
		cout<<"\n Andriod Version :";
		cin>>otand;
		strcpy(oand,otand);
		cout<<endl;
	 }

void display()
{
	clrscr();
	int ch;
	cout<<endl;
	cout<<"\n\t\t\t* * * * * *BRAND* * * * * * * ";
	cout<<endl;
	cout<<"\n1:Nokia";
	cout<<endl;
	cout<<"\n2:Samsung";
	cout<<endl;
	cout<<"\n3:Sony";
	cout<<endl;
	cout<<"\n4:LG";
	cout<<endl;
	cout<<"\n5:Other";
	cout<<endl;
	cout<<"\n Enter your choice: ";
	cin>>ch;
	cout<<endl;
	if(ch==1)
	{   char ch1,ch8;
		 int n1;
		 clrscr();
		 int i=0;
		ofstream ob1("nokia.dat",ios::out|ios::binary);
		do
		{
			cout<<"\n => Enter the details of "<<(i+1)<<" NOKIA MOBILE\n";
			n.getdata1();
			ob1.write((char *)&n,sizeof(n));
			pos1=ob1.tellp();
			cout<<"\n --> Do you want to add more NOKIA mobile:";
			cin>>ch1;
			i++;
			clrscr();
		}while(ch1=='y'||ch1=='Y');
		ob1.close();
		do
		{
			cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * * ";
			cout<<endl;
			cout<<"\n 1:Display the list of NOKIA mobiles :";
			cout<<endl;
			cout<<"\n 2:Add more mobiles in the list:";
			cout<<endl;
			cout<<"\n 3:Delete mobile from the list:";
			cout<<endl;
			cout<<"\n 4:Modify the details of nokia mobiles:";
			cout<<endl;
			cout<<"\n 5:Want to see category list again:";
			cout<<endl;
			cout<<"\nEnter your choice:";
			cin>>n1;
			if(n1==1)
			{
				clrscr();
				displaynokia();
			}
			else if(n1==2)
			{  clrscr();
				appendnokia();
			}
			else if(n1==3)
			{  clrscr();
				deletenokia();
			}
			else if(n1==4)
			{  clrscr();
				int nmno1;
				char ch7;
				cout<<"\n -->Enter the MODEL no. to be modified : ";
				cin>>nmno1;
				fstream ob11("nokia.dat",ios::in|ios::out|ios::binary);
				ob11.seekg(0);
				while(!ob11.eof())
				{
					pos1=ob11.tellg();
					ob11.read((char*)&n,sizeof(n));
					if(n.Return1()==nmno1)
					{
						n.modifynokia();
						ob11.seekg(pos1);
						ob11.write((char*)&n,sizeof(n));
						ch7='y';
						break;
					}
				}
				if (ch7=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(n1==5)
			{  clrscr();
				category();
			}
			cout<<"\n\t* Do YOU WANT TO SEE ABOVE MENU AGAIN *";
			cin>>ch8;
			clrscr();
		 }while(ch8=='y'||ch8=='Y');
	}
	else if(ch==2)
	{
		char ch2,ch10;
		int s1;
		clrscr();
		int j=0;
		ofstream ob2("samsung.dat",ios::out|ios::binary);
		do
		{

			cout<<"\n => Enter the details of "<<(j+1)<<" SAMSUNG MOBILE\n";
			cout<<endl;
			sa.getdata2();
			j++;
			ob2.write((char*)&sa,sizeof(sa));
			pos3=ob2.tellp();
			cout<<"\n Do you want to add more SAMSUNG mobile:";
			cin>>ch2;
			cout<<endl;
			clrscr();
		}while(ch2=='y'||ch2=='Y');
		ob2.close();
		do
		{
			cout<<"\n* * * * * *| WHAT DO YOU WANT DO |* * * * * *  ";
			cout<<"\n 1:Display the list of SAMSUNG  mobiles:";
			cout<<endl;
			cout<<"\n 2:Add more mobiles in the list:";
			cout<<endl;
			cout<<"\n 3:Delete mobile from the list:";
			cout<<endl;
			cout<<"\n 4:Modify the details of SAMSUNG mobiles:";
			cout<<endl;
			cout<<"\n 5:Want to see category list";
			cout<<endl;
			cout<<"\n Enter your choice:";
			cin>>s1;
			cout<<endl;
			if(s1==1)
			{  clrscr();
				displaysamsung();
			}
			else if(s1==2)
			{  clrscr();
				appendsamsung();
			}
			else if(s1==3)
			{  clrscr();
				deletesamsung();
			}
			else if(s1==4)
			{  clrscr();
				int nmno2;
				char ch9;
				cout<<"\n --> Enter the MODEL no. to be modified : ";
				cin>>nmno2;
				fstream ob17("samsung.dat",ios::in|ios::out|ios::binary);
				ob17.seekg(0);
				long pos3;
				while(!ob17.eof())
				{
					pos3=ob17.tellg();
					ob17.read((char*)&sa,sizeof(sa));
					if(sa.Return2()==nmno2)
					{
						sa.modifysamsung();
						ob17.seekg(pos3);
						ob17.write((char*)&sa,sizeof(sa));
						ch9='y';
						break;
					}
				}
				if (ch9=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(s1==5)
			{  clrscr();
				category();
			}
			cout<<"\n\t * Do YOU WANT TO SEE ABOVE MENU AGAIN *";
			cin>>ch10;
			clrscr();
		}while(ch10=='y'||ch10=='Y');
	}
	else if(ch==3)
	{
		char ch3;
		char ch12;
		int so1;
		int k=0;
		clrscr();
		ofstream ob3("sony.dat",ios::out|ios::binary);
		do
		{
			cout<<"\n => Enter the details of "<<(k+1)<<" SONY MOBILE\n";
			cout<<endl;
			so.getdata3();
			ob3.write((char*)&so,sizeof(so));
			pos3=ob3.tellp();
			k++;
			cout<<"\n --> Want to add more SONY mobile:";
			cin>>ch3;
			clrscr();
		}while(ch3=='y'||ch3=='Y');
		ob3.close();
		do
		{
		cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * * ";
		cout<<endl;
		cout<<"\n 1:Display the list of SONY mobiles:";
		cout<<endl;
		cout<<"\n 2:Add more mobiles in the list:";
		cout<<endl;
		cout<<"\n 3:Delete mobile from the list:";
		cout<<endl;
		cout<<"\n 4:Modify the details of SONY mobiles:";
		cout<<endl;
		cout<<"\n 5:Want to see category:";
		cout<<endl;
		cout<<"\n Enter your choice:";
		cin>>so1;
		if(so1==1)
			{  clrscr();
				displaysony();
			}
			else if(so1==2)
			{  clrscr();
				appendsony();
			}
			else if(so1==3)
			{  clrscr();
				deletesony();
			}
			else if(so1==4)
			{  clrscr();
				int nmno3;
				char ch11;
				cout<<"\n --> Enter the MODEL no. to be modified : ";
				cin>>nmno3;
				fstream ob24("sony.dat",ios::in|ios::out|ios::binary);
				ob24.seekg(0);
				while(!ob24.eof())
				{
					pos4=ob24.tellg();
					ob24.read((char*)&n,sizeof(n));
					if(so.Return3()==nmno3)
					{
						so.modifysony();
						ob24.seekg(pos4);
						ob24.write((char*)&so,sizeof(so));
						ch11='y';
						break;
					}
				}
				if (ch11=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(so1==5)
			{  clrscr();
				category();
			}
			cout<<"\n\t * DO YOU WANT TO SEE ABOVE MENU AGAIN *";
			cin>>ch12;
			clrscr();
		 }while(ch12=='y'||ch12=='Y');
	}
	else if(ch==4)
	{
		char ch4,ch14;
		int lg1;
		clrscr();
		int l=0;
		ofstream ob4("lg.dat",ios::out|ios::binary);
		do
		{

			cout<<"\n => Enter the details of "<<(l+1)<<" LG MOBILE\n";
			cout<<endl;
			lg.getdata4();
			ob4.write((char*)&lg,sizeof(lg));
			pos5=ob4.tellp();
			l++;
			cout<<"\n --> Want to add more LG mobile:";
			cin>>ch4;
			clrscr();
		}while(ch4=='y'||ch4=='Y');
		ob4.close();
		do
		{
		cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * *";
		cout<<endl;
		cout<<"\n 1:Display the list of LG mobiles:";
		cout<<endl;
		cout<<"\n 2:Add more mobiles in the list:";
		cout<<endl;
		cout<<"\n 3:Delete mobile from the list:";
		cout<<endl;
		cout<<"\n 4:Modify the details of Lg mobiles:";
		cout<<endl;
		cout<<"\n 5:Want to see the category:";
		cout<<endl;
		cout<<"\n Enter your choice:";
		cin>>lg1;
		if(lg1==1)
			{  clrscr();
				displaylg();
			}
			else if(lg1==2)
			{  clrscr();
				appendlg();
			}
			else if(lg1==3)
			{  clrscr();
				deletelg();
			}
			else if(lg1==4)
			{
				int nmno4;
				char ch13;
				clrscr();
				cout<<"\n -->Enter the MODEL no. to be modified : ";
				cin>>nmno4;
				fstream ob29("lg.dat",ios::in|ios::out|ios::binary);
				ob29.seekg(0);
				while(!ob29.eof())
				{
					pos5=ob29.tellg();
					ob29.read((char*)&lg,sizeof(lg));
					if(lg.Return4()==nmno4)
					{
						lg.modifylg();
						ob29.seekg(pos5);
						ob29.write((char*)&lg,sizeof(lg));
						ch13='y';
						break;
					}
				}
				if (ch13=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(lg1==5)
			{  clrscr();
				category();
			}
			cout<<"\n\t* DO YOU WANT TO SEE ABOVE MENU AGAIN *";
			cin>>ch14;
			clrscr();
		 }while(ch14=='y'||ch14=='Y');
	}
	if(ch==5)
	{   char an1,an8;
		 int na1;
		 clrscr();
		 int z=0;
		ofstream ds5("othermobile.dat",ios::out|ios::binary);
		do
		{
			cout<<"\n => Enter the details of "<<(z+1)<<" OTHER MOBILE\n";
			ot.ogetdata();
			ds5.write((char *)&ot,sizeof(ot));
			opos=ds5.tellp();
			cout<<"\n --> Do you want to add more OTHER mobile:";
			cin>>an1;
			z++;
			clrscr();
		}while(an1=='y'||an1=='Y');
		ds5.close();
		do
		{
			cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * * ";
			cout<<endl;
			cout<<"\n 1:Display the list of OTHER mobiles :";
			cout<<endl;
			cout<<"\n 2:Add more mobiles in the list:";
			cout<<endl;
			cout<<"\n 3:Delete mobile from the list:";
			cout<<endl;
			cout<<"\n 4:Modify the details of other mobiles:";
			cout<<endl;
			cout<<"\n 5:Want to see category list again:";
			cout<<endl;
			cout<<"\nEnter your choice:";
			cin>>na1;
			if(na1==1)
			{
				clrscr();
				displayother();
			}
			else if(na1==2)
			{  clrscr();
				appendother();
			}
			else if(na1==3)
			{  clrscr();
				deleteother();
			}
			else if(na1==4)
			{  clrscr();
				int nomno1;
				char ch70;
				cout<<"\n -->Enter the MODEL no. to be modified : ";
				cin>>nomno1;
				fstream ds6("othermobile.dat",ios::in|ios::out|ios::binary);
				ds6.seekg(0);
				while(!ds6.eof())
				{
					opos1=ds6.tellg();
					ds6.read((char*)&ot,sizeof(ot));
					if(ot.oReturn()==nomno1)
					{
						ot.modifyother();
						ds6.seekg(opos1);
						ds6.write((char*)&ot,sizeof(ot));
						ch70='y';
						break;
					}
				}
				if (ch70=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(na1==5)
			{  clrscr();
				category();
			}
			cout<<"\n\t* Do YOU WANT TO SEE ABOVE MENU AGAIN *";
			cin>>an8;
			clrscr();
		 }while(an8=='y'||an8=='Y');
	}
}
class apple
	{
		float dsc1;
		int mn1;
		float prc1;
		float hd1;
		float ram1;
		float grp1;
		char nam1[20];
		int mb1;
		char os1[20];
		public:
			void modifyapple();
			int Return6();
			void ftrs1()
			{
				cout<<"\n Harddisk : ";
				cin>>hd1;
				cout<<endl;
				cout<<"\n RAM : ";
				cin>>ram1;
				cout<<endl;
				cout<<"\n Graphic Card : ";
				cin>>grp1;
				cout<<endl;
				cout<<"\n Motherboard : ";
				cin>>mb1;
				cout<<endl;
				cout<<"\n Operating System : ";
				cin>>os1;
				cout<<endl;
			}

			void getdata6()
			{
				cout<<"\n Enter the name of computer :";
				cin>>nam1;
				cout<<endl;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<"\n Enter the model no. :";
				cin>>mn1;
				cout<<endl;
				cout<<"\n Enter the price :";
				cin>>prc1;
				cout<<endl;
				cout<<"\n Discount offer :";
				cin>>dsc1;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				ftrs1();
			}
			void display6()
			{
				cout<<"\n Name of computer :"<<nam1;
				cout<<endl;
				cout<<"\n\t ~ ~ ~OTHER DETAILS~ ~ ~ ";
				cout<<endl;
				cout <<"\n Discount ="<<dsc1;
				cout<<endl;
				cout<<"\n Model no. :"<<mn1;
				cout<<endl;
				cout<<"\n Price :"<<prc1;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				cout<<"\n Harddisk : "<<hd1;
				cout<<"\n RAM : "<<ram1;
				cout<<"\n Graphic Card : "<<grp1;
				cout<<"\n Motherboard : "<<mb1;
				cout<<"\n Operating System : \n"<<os1;

			}
	}a;
	int apple::Return6()
	{
		return mn1;
	}
	void displayapple()
	{
		cout<<"\n Apple COMPUTERS IN YOUR STORE:";
		cout<<endl;
		ifstream sg1("apple.dat",ios::in||ios::binary);
		sg1.seekg(0);
		while(!sg1.eof())
		{
			sg1.read((char*)&a,sizeof(a));
			if(sg1.eof())
			break;
			else
			a.display6();
		}
	}
	void appendapple()
	{
		ofstream sg2("apple.dat",ios::app||ios::binary);
		cout<<"\n -->Enter detail of APPLE computer you want to add"<<"\n";
		a.getdata6();
		sg2.seekp(pos7);
		sg2.write((char*)&a,sizeof(a));
		sg2.close();
	}
	void deleteapple()
	{
			ifstream sg3("apple.dat",ios::in||ios::binary);
			ofstream sg4("tmp1.dat",ios::out||ios::binary);
			int srch1;
			char fnd1='f',cnfrm1='n';
			cout<<"\n -->Enter the model no of computer which is to be deleted from stock:";
			cin>>srch1;
			sg3.seekg(0);
			while(!sg3.eof())
			{
				sg3.read((char*)&a,sizeof(a));
				if(a.Return6()==srch1)
				{
					a.display6();
					fnd1='y';
					cout<<"\n Are you really want to delete this record ?(y\n)";
					cin>>cnfrm1;
					if(cnfrm1=='n')
						sg4.write((char*)&a,sizeof(a));
				}
					else
						sg4.write((char*)&a,sizeof(a));
			}
			if(fnd1=='f')
			cout<<"\n -->Computer not found";
			sg3.close();
			sg4.close();
			remove("apple.dat");
			rename("tmp1.dat","apple.dat");
			clrscr();
			ifstream sg5("apple.dat",ios::in||ios::binary);
			cout<<"\n\t Now list of apple computers are:";
			sg5.seekg(0);
			while(!sg5.eof())
			{
				sg5.read((char*)&a,sizeof(a));
				if(sg5.eof())
					break;
						else
						a.display6();
			}
			sg5.close();
	 }
	 void apple:: modifyapple()
	 {
		char aname[20];
		float adis;
		int amno;
		float aprice;
		float ahd;
		float aram;
		float agrp;
		float amb;
		char aos[20];
		cout<<"\n Enter the details :";
		cout<<endl;
		cout<<"\n Enter new name of computer :";
		cin>>aname;
		cout<<endl;
		strcpy(nam1,aname);
		cout<<"\n Enter new discount :";
		cin>>adis;
		dsc1=adis;
		cout<<endl;
		cout<<"\n Enter new model no :";
		cin>>amno;
		mn1=amno;
		cout<<endl;
		cout<<"\n Enter new price :";
		cin>>aprice;
		prc1=aprice;
		cout<<endl;
		cout<<"\n Harddisk :";
		cin>>ahd;
		hd1=ahd;
		cout<<endl;
		cout<<"\n RAM :";
		cin>>aram;
		ram1=aram;
		cout<<endl;
		cout<<"\n Graphics Card :";
		cin>>agrp;
		grp1=agrp;
		cout<<endl;
		cout<<"\n Motherboard :";
		cin>>amb;
		mb1=amb;
		cout<<endl;
		cout<<"\n Operating System :";
		cin>>aos;
		strcpy(os1,aos);
		cout<<endl;
	 }

class hp
	{
		float dsc2;
		int mn2;
		float prc2;
		float hd2;
		float ram2;
		float grp2;
		char nam2[20];
		int mb2;
		char os2[20];
		public:
			void modifyhp();
			int Return7();
			void ftrs2()
			{
				cout<<"\n Harddisk : ";
				cin>>hd2;
				cout<<endl;
				cout<<"\n RAM : ";
				cin>>ram2;
				cout<<"\n Graphic Card : ";
				cin>>grp2;
				cout<<endl;
				cout<<"\n Motherboard : ";
				cin>>mb2;
				cout<<endl;
				cout<<"\n Operating System : ";
				cin>>os2;
				cout<<endl;
			}

			void getdata7()
			{
				cout<<"\n -->Enter the name of computer:";
				cin>>nam2;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<endl;
				cout<<"\n Enter the model no.:";
				cin>>mn2;
				cout<<endl;
				cout<<"\n Enter the price:";
				cin>>prc2;
				cout<<endl;
				cout<<"\n Discount offer:";
				cin>>dsc2;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				ftrs2();
			}
			void display7()
			{
				cout<<"\n Name of computer :"<<nam2;
				cout<<endl;
				cout<<"\n\t ~ ~ ~OTHER DETAILS~ ~ ~";
				cout<<endl;
				cout <<"\n Discount ="<<dsc2;
				cout<<endl;
				cout<<"\n Model no.:"<<mn2;
				cout<<endl;
				cout<<"\n Price:"<<prc2;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				cout<<"\n Harddisk : "<<hd2;
				cout<<"\n RAM : "<<ram2;
				cout<<"\n Graphic Card : "<<grp2;
				cout<<"\n Motherboard : "<<mb2;
				cout<<"\n Operating System : \n"<<os2;

			}
	}h;
	int hp::Return7()
	{
		return mn2;
	}
	void displayhp()
	{
		cout<<"\n HP COMPUTERS IN YOUR STOCK:";
		ifstream sg6("hp.dat",ios::in||ios::binary);
		sg6.seekg(0);
		while(!sg6.eof())
		{
			sg6.read((char*)&h,sizeof(h));
			if(sg6.eof())
			break;
			else
			h.display7();
		}
	}
	void appendhp()
	{
		ofstream sg6("hp.dat",ios::app||ios::binary);
		cout<<"\n --> Enter detail of hp computer you want to add"<<"\n";
		cout<<endl;
		h.getdata7();
		sg6.seekp(pos8);
		sg6.write((char*)&h,sizeof(h));
		sg6.close();
	}
	void deletehp()
	{
			ifstream sg7("hp.dat",ios::in||ios::binary);
			ofstream sg8("tmp2.dat",ios::out||ios::binary);
			int srch2;
			char fnd2='f',cnfrm2='n';
			cout<<"\n --> Enter the model no of computer which is to be deleted from stock:";
			cin>>srch2;
			sg7.seekg(0);
			while(!sg7.eof())
			{
				sg7.read((char*)&h,sizeof(h));
				if(h.Return7()==srch2)
				{
					h.display7();
					fnd2='y';
					cout<<"\n Are you really want to delete this record? (y\n)";
					cin>>cnfrm2;
					if(cnfrm2=='n')
						sg8.write((char*)&h,sizeof(h));
				}
					else
						sg8.write((char*)&h,sizeof(h));
			}
			if(fnd2=='f')
			cout<<"\n --> Computer not found";
			sg7.close();
			sg8.close();
			remove("hp.dat");
			rename("tmp2.dat","hp.dat");
			clrscr();
			ifstream sg9("hp.dat",ios::in||ios::binary);
			cout<<"\n\tNow list of hp computers are:";
			sg9.seekg(0);
			while(!sg9.eof())
			{
				sg9.read((char*)&h,sizeof(h));
				if(sg9.eof())
					break;
						else
						h.display7();
			}
			sg9.close();
	 }
	 void hp:: modifyhp()
	 {
		char hname[20];
		float hdis;
		int hmno;
		float hprice;
		float hhd;
		float hram;
		float hgrp;
		float hmb;
		char hos[20];
		cout<<"\n Enter the details :";
		cout<<endl;
		cout<<"\n Enter new name of computer :";
		cin>>hname;
		strcpy(nam2,hname);
		cout<<endl;
		cout<<"\n Enter new discount:";
		cin>>hdis;
		dsc2=hdis;
		cout<<endl;
		cout<<"\n Enter new model no:";
		cin>>hmno;
		mn2=hmno;
		cout<<endl;
		cout<<"\n Enter new price:";
		cin>>hprice;
		prc2=hprice;
		cout<<endl;
		cout<<"\n Harddisk:";
		cin>>hhd;
		hd2=hhd;
		cout<<endl;
		cout<<"\n RAM:";
		cin>>hram;
		ram2=hram;
		cout<<endl;
		cout<<"\n Graphics Card:";
		cin>>hgrp;
		grp2=hgrp;
		cout<<endl;
		cout<<"\n Motherboard:";
		cin>>hmb;
		mb2=hmb;
		cout<<endl;
		cout<<"\n Operating System:";
		cin>>hos;
		strcpy(os2,hos);
		cout<<endl;
	 }
class hcl
	{
		float dsc3;
		int mn3;
		float prc3;
		float hd3;
		float ram3;
		float grp3;
		char nam3[20];
		int mb3;
		char os3[20];
		public:
			void modifyhcl();
			int Return8();
			void ftrs3()
			{
				cout<<"\n Harddisk : ";
				cin>>hd3;
				cout<<endl;
				cout<<"\n RAM : ";
				cin>>ram3;
				cout<<endl;
				cout<<"\n Graphic Card : ";
				cin>>grp3;
				cout<<endl;
				cout<<"\n Motherboard : ";
				cin>>mb3;
				cout<<endl;
				cout<<"\n Operating System : ";
				cin>>os3;
				cout<<endl;
			}

			void getdata8()
			{
				cout<<"\n Enter the name of computer : ";
				cin>>nam3;
				cout<<endl;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<endl;
				cout<<"\n Enter the model no.:";
				cin>>mn3;
				cout<<endl;
				cout<<"\n Enter the price :";
				cin>>prc3;
				cout<<endl;
				cout<<"\n Discount offer :";
				cin>>dsc3;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				ftrs3();
			}
			void display8()
			{
				cout<<"\n Name of computer :"<<nam3;
				cout<<endl;
				cout<<"\n\t ~ ~ ~OTHER DETAILS~ ~ ~";
				cout<<endl;
				cout <<"\n Discount ="<<dsc3;
				cout<<endl;
				cout<<"\n Model no.:"<<mn3;
				cout<<endl;
				cout<<"\n Price:"<<prc3;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				cout<<"\n Harddisk : "<<hd3;
				cout<<"\n RAM : "<<ram3;
				cout<<"\n Graphic Card : "<<grp3;
				cout<<"\n Motherboard : "<<mb3;
				cout<<"\n Operating System : \n"<<os3;

			}
	}hc;
	int hcl::Return8()
	{
		return mn3;
	}
	void displayhcl()
	{
		cout<<"\n HCL COMPUTERS IN YOUR STOCK:";
		cout<<endl;
		ifstream sg11("hcl.dat",ios::in||ios::binary);
		sg11.seekg(0);
		while(!sg11.eof())
		{
			sg11.read((char*)&hc,sizeof(hc));
			if(sg11.eof())
			break;
			else
			hc.display8();
		}
	}
	void appendhcl()
	{
		ofstream sg11("hcl.dat",ios::app||ios::binary);
		cout<<"\n -->Enter detail of HCL computer  you want to add"<<"\n";
		hc.getdata8();
		sg11.seekp(pos9);
		sg11.write((char*)&hc,sizeof(hc));
		sg11.close();
	}
	void deletehcl()
	{
			ifstream sg12("hcl.dat",ios::in||ios::binary);
			ofstream sg13("tmp3.dat",ios::out||ios::binary);
			int srch3;
			char fnd3='f',cnfrm3='n';
			cout<<"\n -->Enter the model no of computer which is to be deleted from stock:";
			cin>>srch3;
			sg12.seekg(0);
			while(!sg12.eof())
			{
				sg12.read((char*)&hc,sizeof(hc));
				if(hc.Return8()==srch3)
				{
					hc.display8();
					fnd3='y';
					cout<<"\n Are you really want to delete this record?(y\n)";
					cin>>cnfrm3;
					if(cnfrm3=='n')
						sg13.write((char*)&hc,sizeof(hc));
				}
					else
						sg13.write((char*)&hc,sizeof(hc));
			}
			if(fnd3=='f')
			cout<<"\n --> Computer not found";
			sg12.close();
			sg13.close();
			remove("hcl.dat");
			rename("tmp3.dat","hcl.dat");
			clrscr();
			ifstream sg14("hcl.dat",ios::in||ios::binary);
			cout<<"\n\t * Now list of HCL computers are *";
			sg14.seekg(0);
			while(!sg14.eof())
			{
				sg14.read((char*)&hc,sizeof(hc));
				if(sg14.eof())
					break;
						else
						hc.display8();
			}
			sg14.close();
	 }
	 void hcl:: modifyhcl()
	 {
		char hcname[20];
		float hcdis;
		int hcmno;
		float hcprice;
		float hchd;
		float hcram;
		float hcgrp;
		float hcmb;
		char hcos[20];
		cout<<"\n Enter the details :";
		cout<<endl;
		cout<<"\n Enter new name of computer :";
		cin>>hcname;
		strcpy(nam3,hcname);
		cout<<endl;
		cout<<"\n Enter new discount:";
		cin>>hcdis;
		dsc3=hcdis;
		cout<<endl;
		cout<<"\n Enter new model no:";
		cin>>hcmno;
		mn3=hcmno;
		cout<<endl;
		cout<<"\n Enter new price:";
		cin>>hcprice;
		prc3=hcprice;
		cout<<endl;
		cout<<"\n Harddisk:";
		cin>>hchd;
		hd3=hchd;
		cout<<endl;
		cout<<"\n RAM:";
		cin>>hcram;
		ram3=hcram;
		cout<<endl;
		cout<<"\n Graphics Card:";
		cin>>hcgrp;
		grp3=hcgrp;
		cout<<endl;
		cout<<"\n Motherboard:";
		cin>>hcmb;
		mb3=hcmb;
		cout<<endl;
		cout<<"\n Operating System:";
		cin>>hcos;
		strcpy(os3,hcos);
		cout<<endl;
	 }
class dell
	{
		float dsc4;
		int mn4;
		float prc4;
		float hd4;
		float ram4;
		float grp4;
		char nam4[20];
		int mb4;
		char os4[20];
		public:
			void modifydell();
			int Return9();
			void ftrs4()
			{
				cout<<"\n Harddisk : ";
				cin>>hd4;
				cout<<endl;
				cout<<"\n RAM : ";
				cin>>ram4;
				cout<<endl;
				cout<<"\n Graphic Card : ";
				cin>>grp4;
				cout<<endl;
				cout<<"\n Motherboard : ";
				cin>>mb4;
				cout<<endl;
				cout<<"\n Operating System : ";
				cin>>os4;
				cout<<endl;
			}

			void getdata9()
			{
				cout<<"\n Enter the name of computer:";
				cin>>nam4;
				cout<<endl;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<endl;
				cout<<"\n Enter the model no.:";
				cin>>mn4;
				cout<<endl;
				cout<<"\n Enter the price:";
				cin>>prc4;
				cout<<endl;
				cout<<"\n Discount offer:";
				cin>>dsc4;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				ftrs4();
			}
			void display9()
			{
				cout<<"\n Name of computer :"<<nam4;
				cout<<endl;
				cout<<"\n\t~ ~ ~OTHER DETAILS~ ~ ~";
				cout<<endl;
				cout <<"\n Discount ="<<dsc4;
				cout<<endl;
				cout<<"\n Model no.:"<<mn4;
				cout<<endl;
				cout<<"\n Price:"<<prc4;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<"\n Harddisk: "<<hd4;
				cout<<"\n RAM: "<<ram4;
				cout<<"\n Graphic Card: "<<grp4;
				cout<<"\n Motherboard: "<<mb4;
				cout<<"\n Operating System: \n"<<os4;

			}
	}d;
	int dell::Return9()
	{
		return mn4;
	}
	void displaydell()
	{
		cout<<"\n DELL COMPUTERS IN YOUR STOCK:";
		cout<<endl;
		ifstream sg16("dell.dat",ios::in||ios::binary);
		sg16.seekg(0);
		while(!sg16.eof())
		{
			sg16.read((char*)&d,sizeof(d));
			if(sg16.eof())
			break;
			else
			d.display9();
		}
	}
	void appenddell()
	{
		ofstream sg17("dell.dat",ios::app||ios::binary);
		cout<<"\n -->Enter detail of Dell computer  you want to add"<<"\n";
		d.getdata9();
		sg17.seekp(pos11);
		sg17.write((char*)&d,sizeof(d));
		sg17.close();
	}
	void deletedell()
	{
			ifstream sg18("dell.dat",ios::in||ios::binary);
			ofstream sg19("tmp4.dat",ios::out||ios::binary);
			int srch4;
			char fnd4='f',cnfrm4='n';
			cout<<"\n --> Enter the model no of computer which is to be deleted from stock:";
			cin>>srch4;
			sg18.seekg(0);
			while(!sg18.eof())
			{
				sg18.read((char*)&d,sizeof(d));
				if(d.Return9()==srch4)
				{
					d.display9();
					fnd4='y';
					cout<<"\n Are you really want to delete this record?(y\n)";
					cin>>cnfrm4;
					if(cnfrm4=='n')
						sg19.write((char*)&d,sizeof(d));
				}
					else
						sg19.write((char*)&d,sizeof(d));
			}
			if(fnd4=='f')
			cout<<"\n -->Computer not found";
			sg18.close();
			sg19.close();
			remove("dell.dat");
			rename("tmp4.dat","dell.dat");
			clrscr();
			ifstream sg20("dell.dat",ios::in||ios::binary);
			cout<<"\n\t * Now list of Dell computers are *";
			sg20.seekg(0);
			while(!sg20.eof())
			{
				sg20.read((char*)&d,sizeof(d));
				if(sg20.eof())
					break;
						else
						d.display9();
			}
			sg20.close();
	 }

	 void dell:: modifydell()
	 {
		char dname[20];
		float ddis;
		int dmno;
		float dprice;
		float dhd;
		float dram;
		float dgrp;
		float dmb;
		char dos[20];
		cout<<"\n Enter the details:";
		cout<<endl;
		cout<<"\n Enter new name of computer:";
		cin>>dname;
		strcpy(nam4,dname);
		cout<<endl;
		cout<<"\n Enter new discount:";
		cin>>ddis;
		dsc4=ddis;
		cout<<endl;
		cout<<"\n Enter new model no:";
		cin>>dmno;
		mn4=dmno;
		cout<<endl;
		cout<<"\n Enter new price:";
		cin>>dprice;
		prc4=dprice;
		cout<<endl;
		cout<<"\n Harddisk:";
		cin>>dhd;
		hd4=dhd;
		cout<<endl;
		cout<<"\n RAM:";
		cin>>dram;
		ram4=dram;
		cout<<endl;
		cout<<"\n Graphics Card:";
		cin>>dgrp;
		grp4=dgrp;
		cout<<endl;
		cout<<"\n Motherboard:";
		cin>>dmb;
		mb4=dmb;
		cout<<endl;
		cout<<"\n Operating System:";
		cin>>dos;
		strcpy(os4,dos);
		cout<<endl;
	 }
class othercomp
{
	char nam5[20];
	float dsc5;
	int mn5;
	float prc5;
	float hd5;
	float ram5;
	float grp5;
	float mb5;
	char os5[20];
	char ccom[20];

		public:
			int cReturn();
			void modifyothercom();
			void ftrs5()
			{
				cout<<"\n Harddisk : ";
				cin>>hd5;
				cout<<endl;
				cout<<"\n RAM : ";
				cin>>ram5;
				cout<<endl;
				cout<<"\n Graphic Card : ";
				cin>>grp5;
				cout<<endl;
				cout<<"\n Motherboard : ";
				cin>>mb5;
				cout<<endl;
				cout<<"\n Operating System : ";
				cin>>os5;
				cout<<endl;
			}
			void getdata10()
			{
				cout<<"\n Enter the name of computer:";
				cin>>nam5;
				cout<<endl;
				cout<<"\n Enter the BRAND:";
				cin>>ccom;
				cout<<"\n\t :::: ENTER OTHER DETAILS :::::";
				cout<<endl;
				cout<<"\n Enter the model no.:";
				cin>>mn5;
				cout<<endl;
				cout<<"\n Enter the price:";
				cin>>prc5;
				cout<<endl;
				cout<<"\n Discount offer:";
				cin>>dsc5;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<endl;
				ftrs5();
			}
			void display10()
			{
				cout<<"\n Name of computer :"<<nam5;
				cout<<endl;
            cout<<"\n BRAND:"<<ccom;
				cout<<"\n\t~ ~ ~OTHER DETAILS~ ~ ~";
				cout<<endl;
				cout <<"\n Discount ="<<dsc5;
				cout<<endl;
				cout<<"\n Model no.:"<<mn5;
				cout<<endl;
				cout<<"\n Price:"<<prc5;
				cout<<endl;
				cout<<"\n\t * * *Special Features* * *";
				cout<<"\n Harddisk: "<<hd5;
				cout<<"\n RAM: "<<ram5;
				cout<<"\n Graphic Card: "<<grp5;
				cout<<"\n Motherboard: "<<mb5;
				cout<<"\n Operating System: \n"<<os5;
			}
	}co;
	void displayothercom()
	{
		cout<<"\n OTHER COMPUTER IN YOUR STOCK ARE:";
		ifstream ds20("othercomp.dat",ios::in||ios::binary);
		ds20.seekg(0);
		while(!ds20.eof())
		{
			ds20.read((char*)&co,sizeof(co));
			if(ds20.eof())
			break;
			else
			co.display10();
		}
	}
	void deleteothercom()
	{
			ifstream ds20("othercomp.dat",ios::in||ios::binary);
			ofstream ds21("ctemp1.dat",ios::out||ios::binary);
			int csearch;
			char cfound='f',cconfirm='n';
			cout<<"\n --> Enter the model no. of computer which is to be deleted from stock:";
			cout<<endl;
			cin>>csearch;
			ds20.seekg(0);
			while(!ds20.eof())
			{
				ds20.read((char*)&co,sizeof(co));
				if(co.cReturn()==csearch)
				{
					co.display10();
					cfound='y';
					cout<<"\n Are you really want to delete this record? (y\n)";
					cin>>cconfirm;
					if(cconfirm=='n')
						ds21.write((char*)&co,sizeof(co));
				}
					else
						ds21.write((char*)&co,sizeof(co));
			}
			if(cfound=='f')
			cout<<"\n --> COMPUTER not found";
			cout<<endl;
			ds20.close();
			ds21.close();
			remove("othercomp.dat");
			rename("ctemp1.dat","othercomp.dat");
			clrscr();
			ifstream ds22("othercomp.dat",ios::in||ios::binary);
			cout<<"\n\tNow list of OTHER mobile are:";
			cout<<endl;
			ds22.seekg(0);
			while(!ds22.eof())
			{
				ds22.read((char*)&co,sizeof(co));
				if(ds22.eof())
					break;
						else
						co.display10();
			}
			ds22.close();
	 }
	 void appendcom()
	{
		ofstream ds23("othercomp.dat",ios::app||ios::binary);
		cout<<"\n --> Enter detail of OTHER COMPUTER you want to add"<<"\n";
		cout<<endl;
		co.getdata10();
		ds23.seekp(cpos);
		ds23.write((char*)&co,sizeof(co));
		ds23.close();
	}
	int othercomp::cReturn()
	{
		return mn5;
	}
	void othercomp:: modifyothercom()
	 {
		char cname[20];
		float cdis;
		int cmno;
		float cprice;
		float chd;
		float cram;
		float cgrp;
		float cmb;
		char cos[20];
		cout<<"\n Enter the details:";
		cout<<endl;
		cout<<"\n Enter new name of computer:";
		cin>>cname;
		strcpy(nam5,cname);
		cout<<endl;
		cout<<"\n Enter new discount:";
		cin>>cdis;
		dsc5=cdis;
		cout<<endl;
		cout<<"\n Enter new model no:";
		cin>>cmno;
		mn5=cmno;
		cout<<endl;
		cout<<"\n Enter new price:";
		cin>>cprice;
		prc5=cprice;
		cout<<endl;
		cout<<"\n Harddisk:";
		cin>>chd;
		hd5=chd;
		cout<<endl;
		cout<<"\n RAM:";
		cin>>cram;
		ram5=cram;
		cout<<endl;
		cout<<"\n Graphics Card:";
		cin>>cgrp;
		grp5=cgrp;
		cout<<endl;
		cout<<"\n Motherboard:";
		cin>>cmb;
		mb5=cmb;
		cout<<endl;
		cout<<"\n Operating System:";
		cin>>cos;
		strcpy(os5,cos);
		cout<<endl;
	 }
void discom()
{
	int sd;
	clrscr();
	cout<<"\n\t\t\t* * * * * *BRAND* * * * * * *";
	cout<<endl;
	cout<<"\n1:APPLE";
	cout<<endl;
	cout<<"\n2:HP";
	cout<<endl;
	cout<<"\n3:HCL";
	cout<<endl;
	cout<<"\n4:DELL";
	cout<<endl;
	cout<<"\n5:OTHER";
	cout<<"\n Enter your choice: ";
	cin>>sd;
	if(sd==1)
	{   char sd8;
		 int as1;
		 int sd;
		 int o=0;
		ofstream em1("apple.dat",ios::out|ios::binary);
		do
		{
			cout<<"\n => Enter the details of "<<(o+1)<<" APPLE COMPUTER\n";
			a.getdata6();
			em1.write((char *)&a,sizeof(a));
			pos7=em1.tellp();
			o++;
			cout<<"\n -->Do you want to add more APPLE COMPUTER:";
			cin>>sd;
			clrscr();
		}while(sd=='y'||sd=='Y');
		em1.close();
		do
		{
			cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * *";
			cout<<endl;
			cout<<"\n 1:Display the list of APPLE COMPUTER:";
			cout<<endl;
			cout<<"\n 2:Add more APPLE COMPUTER in the list:";
			cout<<endl;
			cout<<"\n 3:Delete APPLE COMPUTER from the list:";
			cout<<endl;
			cout<<"\n 4:Modify the details of  APPLE COPMPUTER:";
			cout<<endl;
			cout<<"\n 5:Want to see category list again:";
			cout<<endl;
			cout<<"\nEnter your choice:";
			cin>>as1;
			if(as1==1)
			{  clrscr();
				displayapple();
			}
			else if(as1==2)
			{  clrscr();
				appendapple();
			}
			else if(as1==3)
			{  clrscr();
				deleteapple();
			}
			else if(as1==4)
			{
				int ap1;
				char an1;
				long pos15;
				clrscr();
				cout<<"\n -->Enter the MODEL no. to be modified : ";
				cin>>ap1;
				fstream em2("apple.dat",ios::in|ios::out|ios::binary);
				em2.seekg(0);
				while(!em2.eof())
				{
					pos15=em2.tellg();
					em2.read((char*)&a,sizeof(a));
					if(a.Return6()==ap1)
					{
						a.modifyapple();
						em2.seekg(pos15);
						em2.write((char*)&a,sizeof(a));
						an1='y';
						break;
					}
				}
				if (an1=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(as1==5)
			{  clrscr();
				category();
			}
			cout<<"\n\t* DO YOU WANT TO SEE ABOVE MENU AGAIN *";
			cin>>sd8;
			clrscr();
		 }while(sd8=='y'||sd8=='Y');
	}
	else if(sd==2)
	{
		char sd2,sd10;
		int hp1;
		clrscr();
		ofstream em3("hp.dat",ios::out|ios::binary);
		do
		{
			int p=0;
			cout<<"\n => Enter the details of "<<(p+1)<<"HP COMPUTER\n";
			h.getdata7();
			em3.write((char*)&h,sizeof(h));
			pos8=em3.tellp();
			p++;
			cout<<"\n -->Do you want to add more HP COPMUTER:";
			cin>>sd2;
			clrscr();
		}while(sd2=='y'||sd2=='Y');
		em3.close();
		do
		{
			cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * *  ";
			cout<<endl;
			cout<<"\n 1:Display the list of HP COMPUTER:";
			cout<<endl;
			cout<<"\n 2:Add more HP COMPUTER in the list:";
			cout<<endl;
			cout<<"\n 3:Delete HP COMPUTER from the list:";
			cout<<endl;
			cout<<"\n 4:Modify the details of HP COMPUTER mobiles:";
			cout<<endl;
			cout<<"\n 5:Want to see category list";
			cout<<endl;
			cout<<"\n Enter your choice:";
			cin>>hp1;
			if(hp1==1)
			{  clrscr();
				displayhp();
			}
			else if(hp1==2)
			{  clrscr();
				appendhp();
			}
			else if(hp1==3)
			{  clrscr();
				deletehp();
			}
			else if(hp1==4)
			{
				int hp2;
				char an2;
				clrscr();
				cout<<"\n -->Enter the MODEL no. to be modified : ";
				cin>>hp2;
				fstream em4("hp.dat",ios::in|ios::out|ios::binary);
				em4.seekg(0);
				long pos16;
				while(!em4.eof())
				{
					pos16=em4.tellg();
					em4.read((char*)&h,sizeof(h));
					if(h.Return7()==hp2)
					{
						h.modifyhp();
						em4.seekg(pos16);
						em4.write((char*)&h,sizeof(h));
						an2='y';
						break;
					}
				}
				if (an2=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(hp1==5)
			{
				category();
			}
			cout<<"\n\t * DO YOU WANT TO SEE ABOVE MENU AGAIN *:";
			cin>>sd10;
			clrscr();
		}while(sd10=='y'||sd10=='Y');
	}
	else if(sd==3)
	{
		char sd3;
		char sd12;
		int hcl1;
		clrscr();
		int q=0;
		ofstream em5("hcl.dat",ios::out|ios::binary);
		do
		{

			cout<<"\n => Enter the details of "<<(q+1)<<" HCL COMPUTER\n";
			hc.getdata8();
			em5.write((char*)&hc,sizeof(hc));
			pos9=em5.tellp();
			q++;
			cout<<"\n -->Want to add more HCL COMPUTER:";
			cin>>sd3;
			clrscr();
		}while(sd3=='y'||sd3=='Y');
		em5.close();
		do
		{
		cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * *";
		cout<<endl;
		cout<<"\n 1:Display the list of HCL COMPUTER:";
		cout<<endl;
		cout<<"\n 2:Add more HCL COMPUTER in the list:";
		cout<<endl;
		cout<<"\n 3:Delete HCL COMPUTER from the list:";
		cout<<endl;
		cout<<"\n 4:Modify the details of HCL COMPUTER:";
		cout<<endl;
		cout<<"\n 5:Want to see category:";
		cout<<endl;
		cout<<"\n Enter your choice:";
		cin>>hcl1;
		if(hcl1==1)
			{  clrscr();
				displayhcl();
			}
			else if(hcl1==2)
			{  clrscr();
				appendhcl();
			}
			else if(hcl1==3)
			{  clrscr();
				deletehcl();
			}
			else if(hcl1==4)
			{
				int hcl2;
				char sd11;
				long pos17;
				clrscr();
				cout<<"\n--> Enter the MODEL no. to be modified : ";
				cin>>hcl2;
				fstream em6("hcl.dat",ios::in|ios::out|ios::binary);
				em6.seekg(0);
				while(!em6.eof())
				{
					pos17=em6.tellg();
					em6.read((char*)&hc,sizeof(hc));
					if(hc.Return8()==hcl2)
					{
						hc.modifyhcl();
						em6.seekg(pos17);
						em6.write((char*)&hc,sizeof(hc));
						sd11='y';
						break;
					}
				}
				if (sd11=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(hcl1==5)
			{  clrscr();
				category();
			}
			cout<<"\n * DO YOU WANT TO SEE ABOVE MENU AGAIN *:";
			cout<<endl;
			cin>>sd12;
			clrscr();
		 }while(sd12=='y'||sd12=='Y');
	}
	else if(sd==4)
	{
		char sd4,sd14;
		int del1;
		clrscr();
		int r=0;
		ofstream em7("dell.dat",ios::out|ios::binary);
		do
		{

			cout<<"\n => Enter the details of "<<(r+1)<<" DELL COMPUTER\n";
			d.getdata9();
			em7.write((char*)&d,sizeof(d));
			pos10=em7.tellp();
			r++;
			cout<<"\n -->Want to add more DELL COPMPUTER:";
			cin>>sd4;
			clrscr();
		}while(sd4=='y'||sd4=='Y');
		em7.close();
		do
		{
		cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * * ";
		cout<<endl;
		cout<<"\n 1:Display the list of DELL COMPUTER:";
		cout<<endl;
		cout<<"\n 2:Add more DELL COMPUTER in the list:";
		cout<<endl;
		cout<<"\n 3:Delete COMPUTER from the list:";
		cout<<endl;
		cout<<"\n 4:Modify the details of DELL COMPUTER:";
		cout<<endl;
		cout<<"\n 5:Want to see the category:";
		cout<<endl;
		cout<<"\n Enter your choice:";
		cin>>del1;
		if(del1==1)
			{  clrscr();
				displaydell();
			}
			else if(del1==2)
			{  clrscr();
				appenddell();
			}
			else if(del1==3)
			{  clrscr();
				deletedell();
			}
			else if(del1==4)
			{
				int del2;
				char sd13;
				long pos18;
				clrscr();
				cout<<"\n -->Enter the MODEL no. to be modified : ";
				cin>>del2;
				fstream em8("dell.dat",ios::in|ios::out|ios::binary);
				em8.seekg(0);
				while(!em8.eof())
				{
					pos18=em8.tellg();
					em8.read((char*)&d,sizeof(d));
					if(d.Return9()==del2)
					{
						d.modifydell();
						em8.seekg(pos18);
						em8.write((char*)&d,sizeof(d));
						sd13='y';
						break;
					}
				}
				if (sd13=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(del1==5)
			{  clrscr();
				category();
			}
			cout<<"\n *Do YOU WANT TO SEE ABOVE MENU AGAIN *:";
			cin>>sd14;
			clrscr();
		 }while(sd14=='y'||sd14=='Y');
	}
	if(sd==5)
	{
		clrscr();
		 int as1;
		 char sd;
		 char sd8;
		 int a=0;
		ofstream ds25("othercomp.dat",ios::out|ios::binary);
		do
		{
			cout<<"\n => Enter the details of "<<(a+1)<<" OTHER COMPUTER\n";
			co.getdata10();
			ds25.write((char *)&co,sizeof(co));
			cpos=ds25.tellp();
			a++;
			cout<<"\n -->Do you want to add more OTHER COMPUTER:";
			cin>>sd;
			clrscr();
		}while(sd=='y'||sd=='Y');
		ds25.close();
		do
		{
			cout<<"\n* * * * * *| WHAT DO YOU WANT TO DO |* * * * * *";
			cout<<endl;
			cout<<"\n 1:Display the list of OTHER COMPUTER:";
			cout<<endl;
			cout<<"\n 2:Add more COMPUTER in the list:";
			cout<<endl;
			cout<<"\n 3:Delete OTHER COMPUTER from the list:";
			cout<<endl;
			cout<<"\n 4:Modify the details of OTHER COPMPUTER:";
			cout<<endl;
			cout<<"\n 5:Want to see category list again:";
			cout<<endl;
			cout<<"\nEnter your choice:";
			cin>>as1;
			if(as1==1)
			{  clrscr();
				displayothercom();
			}
			else if(as1==2)
			{  clrscr();
				appendcom();
			}
			else if(as1==3)
			{  clrscr();
				deleteothercom();
			}
			else if(as1==4)
			{
				int ocp;
				char an1;
				long possd;
				clrscr();
				cout<<"\n -->Enter the MODEL no. to be modified : ";
				cin>>ocp;
				fstream ds26("othercomp.dat",ios::in|ios::out|ios::binary);
				ds26.seekg(0);
				while(!ds26.eof())
				{
					possd=ds26.tellg();
					ds26.read((char*)&co,sizeof(co));
					if(co.cReturn()==ocp)
					{
						co.modifyothercom();
						ds26.seekg(possd);
						ds26.write((char*)&co,sizeof(co));
						an1='y';
						break;
					}
				}
				if (an1=='n')
				cout<<"\n -->Record Not Found";
			}
			else if(as1==5)
			{  clrscr();
				category();
			}
			cout<<"\n\t* DO YOU WANT TO SEE ABOVE MENU AGAIN *";
			cin>>sd8;
			clrscr();
		 }while(sd8=='y'||sd8=='Y');
	}
}
void logindata()
{
	char user[30];
	long pass;
	char choice='n';
	do
	{
		cout<<"\n Enter the user name:";
		cin>>user;
		cout<<"\n Enter the password:";
		cin>>pass;
		clrscr();
		ifstream as21("login.dat",ios::in||ios::binary);
		as21.seekg(0);
		while(!as21.eof())
		{
			as21.read((char*)&lo,sizeof(lo));
			if((pass==lo.returnpw())&&(lo.returnusername(user)== 0))
		   category();
			else
			{
				cout<<"\n Enter again(y/n):";
				cin>>choice;
				if(choice=='n')
				exit(0);
			}
		}
	}while(choice=='y'||choice=='Y');
}
void changepasword()
{
	long posl1;
	int newun;
	char sd30='y';
	cout<<"\n -->Enter the user no. whose pasaword is to be modified : ";
	cin>>newun;
	fstream lo1("login.dat",ios::in|ios::out|ios::binary);
	lo1.seekg(0);
	while(!lo1.eof())
	{
		posl1=lo1.tellg();
		lo1.read((char*)&lo,sizeof(lo));
		if(lo.returnuserno()==newun)
		{
			lo.modifypw();
			lo1.seekg(posl1);
			lo1.write((char*)&lo,sizeof(lo));
			sd30='y';
			break;
		}
	}
	if (sd30=='n')
	cout<<"\n -->Record Not Found";
}
void changeusername()
{
	long posl2;
	int newun;
	char sd31='y';
	cout<<"\n -->Enter the user no. whose username is to be modified : ";
	cin>>newun;
	fstream lo2("login.dat",ios::in|ios::out|ios::binary);
	lo2.seekg(0);
	while(!lo2.eof())
	{
		posl2=lo2.tellg();
		lo2.read((char*)&lo,sizeof(lo));
		if(lo.returnuserno()==newun)
		{
			lo.modifyname();
			lo2.seekg(posl2);
			lo2.write((char*)&lo,sizeof(lo));
			sd31='y';
			break;
		}
	}
	if (sd31=='n')
	cout<<"\n -->Record Not Found";
}
void main()
{  clrscr();
	int da;
	char pd='y';
	cout<<endl;
	cout<<"\n\t\t\t _______WELCOME________"<<endl;
	cout<<"\n\t\t\t________SASS SHOP______";
	cout<<endl;
	cout<<endl;
	cout<<"\n !!! Create the username and password !!!"<<endl;
	createpw();
	clrscr();
	do
	{
		cout<<"\n !!!!!!!! MENU !!!!!!!!";
		cout<<"\n 1:WANT TO LOGIN";
		cout<<"\n 2:WANT TO CHANGE PASSWORD";
		cout<<"\n 3:WANT TO CHANGE USERNAME";
		cout<<"\n 4:WANT TO EXIT FROM DATABASE";
		cout<<"\n Enter your choice:";
		cin>>da;
		clrscr();
		switch(da)
		{
			case 1:logindata();
					 break;
			case 2:changepasword();
					 break;
			case 3:changeusername();
					 break;
			case 4:cout<<"\n Thanks ";
					 exit(0);
		}
		cout<<"\nDO YOU WANT TO SEE ABOVE MENU AGAIN(Y/N):";
		cin>>pd;
      clrscr();
	}while(pd=='y'||pd=='Y');
	getch();
}
