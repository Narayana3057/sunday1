#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<windows.h>
using namespace std;

//USER DEFINED FUNCTIONS DECLARATIONS
void user();
void install();
void show();
void search();
void modify();
void del();

class Gadgets
{
   	public:
	    int gno,gram,grom;
	    float gfcam,gbcam,gprice;
		char gname[20];
	   void input()
	    {
	    	cout<<"GADGET Name : ";
	    	cin>>gname;
	    	cout<<"RAM(in gb)  : ";
	    	cin>>gram;
	    	cout<<"ROM(in gb)  : ";
	    	cin>>grom;
	    	cout<<"FrontCam(in pixels) : ";
	    	cin>>gfcam;
	    	cout<<"BackCam(in pixels)  : ";
			cin>>gbcam;
			cout<<"PRICE(in rupees)    : ";
			cin>>gprice;
		}
		void output()
		{
			cout<<"\n\t"<<gname<<"\t\t"<<gram<<"gb\t\t"<<grom<<"gb\t\t"<<gfcam<<"px\t\t"<<gbcam<<"px\t\t"<<gprice;
		}

}g;

main()
	{
	    int k=0;
		char i,c;
		do
		{
			cout<<"\n##----------------------------------USER-INTERFACE---------------------------------##\n";
			cout<<"\n\n\t\t****\t\t1.INSTALL GADGETS\t\t**** \n\n\t\t****\t\t2.DISPLAY ALL GADGETS\t\t**** \n\n\t\t****\t\t3.SEARCH\t\t\t****  \n\n\t\t****\t\t4.UPDATE\t\t\t**** \n\n\t\t****\t\t5.DELETE\t\t\t**** \n\n\t\t****\t\t6.EXIT\t\t\t\t****\n\n";
			cout<<"\t\t****************************************************\n\n\t     Enter your choice :";
			cin>>c;
	    	switch(c)
	    	{
	    	 	case '1':
	    	 		system("cls");
	     			cout<<"\n\n##-----------------------------------------------INSTALLATION OF GADGETS------------------------------------------##";
					install();
					break;
		 		case '2':
		 			system("cls");
		 			cout<<"\n\n##-----------------------------------------------------GADGETS INFO------------------------------------------------##";
		     		show();
		     		break;
		 		case '3':
		 			system("cls");
		 	 		cout<<"\n\n##-------------------------------------------------SEARCHING GADGET-----------------------------------------------##\n";
		 	 		search();
					break;
		 		case '4':
		 			system("cls");
		 			cout<<"\n\n##-------------------------------------------------------UPDATION-------------------------------------------------##\n";
					modify();
					break;
		 		case '5':
		 			system("cls");
		    		del();
					break;
				case '6':
		 			cout<<"\n\n\t\t******THANK YOU******\n\n";
		   	  		exit(0);
  	     		default:
		 			cout<<"\n\n\t\tyour choice is wrong\n\n\t\t****THANK YOU****s";
			}
			cout<<"\n\n______________________________________________________________________________________________________________________\n";
	    	cout<<"\n\ndo you want menu once (Y/N):";
	      	cin>>i;
	      	if(i=='N'||i=='n')
	       		{
	    	  		k=1;
		  		}
		   system("cls");
	    } while(!k);
	    
   }

//FOR INSTALLING GADGETS
void install()
   {
    	int k,n;
    	 cout<<endl<<"How many Gadgets u want to install :";
     	cin>>n;
     	for(k=1;k<=n;k++)
	 	{
	 	 	ofstream outfile;
	     	cout<<endl<<"\nEnter the following Gadgets-"<<k<<" details:"<<endl<<endl;
	     	outfile.open("g1.txt",ios :: app);
	     	g.input();
	     	outfile.write((char *)&g,sizeof(g));
	     	outfile.close();
	     	cout<<"\n***ADDED SUCCESSFULLY***\n";
	 	}
   }

 // TO DISPALY GADGETS RECORD
void show()
   {
	 	ifstream infile;
	 	infile.open("g1.txt",ios :: in);
	    cout<<"\n_______________________________________________________________________________________________________________________"<<endl;
	 	cout<<endl<<"  \tGADGET-NAME     	RAM     	ROM  	  	FrontCam       BackCam     	PRICE($)"<<endl;
	    cout<<"_______________________________________________________________________________________________________________________"<<endl;
	 	while(infile.read((char *)&g,sizeof(g)))
	   	{
	 	  	g.output();
	    }
		 infile.close();
   }

 //SEARCH FOR GADGET DETAILS
void search()
   {
 	int k;
 	char Gadgetname[20];
 	cout<<"\n(NOTE: U can SEARCH by using Name or Ram or Rom or price ...) ";
 	cout<<"\n\nSEARCH :::= ";
	cin>>Gadgetname;
	int p=atoi(Gadgetname);
 	ifstream infile;
 	infile.open("g1.txt",ios :: in);
 	cout<<"_______________________________________________________________________________________________________________________"<<endl;
	cout<<endl<<"  \tGADGET-NAME     	RAM     	ROM  	  	FrontCam       BackCam     	PRICE($)"<<endl;
	cout<<"_______________________________________________________________________________________________________________________"<<endl;
 	while(infile.read((char *)&g,sizeof(g)))
 	   {
 	      if(stricmp(g.gname,Gadgetname)==0 || p==g.gram || p==g.grom || p==g.gfcam || p==g.gbcam )
 		   {
 		 	 g.output();
 			 k=1;
		   }
	   }
	if(k!=1)
	 {
	 	cout<<"\n*** GADGET IS NOT PRESENT IN RECORD ***";
	 }
	  infile.close();
   }

//FOR UPDATING  DATA
void modify()
   {
   	 int k=0;
   	 char Gadgetname[20];
 	 cout<<"\nEnter Gadget name u want to MODIFY :";
	 cin>>Gadgetname;
  	 ifstream infile;
 	 infile.open("g1.txt",ios :: in);
 	 ofstream out;
     out.open("grefer.txt",ios :: app);
  	 while(infile.read((char *)&g,sizeof(g)))
  	   {
  		 if(stricmp(Gadgetname,g.gname)==0)
  		   {
  			  cout<<endl<<"ENETR NEW DETAILS:"<<endl;
  			  g.input();
  			  out.write((char *)&g,sizeof(g));
  			  k=1;
		    }
			else
			{
			   out.write((char *)&g,sizeof(g));
			}
	   }
		infile.close();
		out.close();
		remove("g1.txt");
		rename("grefer.txt","g1.txt");
		if(k==1)
	    	{
	    		cout<<"\n*** UPDATED SUCCESSFULLY***\n";
			}
	else
		{
			cout<<"\n***NOT FOUND***\n";
		}
}


//FOR DELETING BUSES
void del()
   {

   	int k=0,n;
   	char Gadgetname[20];
   	cout<<"\n\n##------------------------------DELETING--------------------------------##\n";
   	cout<<"\nNumber of Gadgets u want to DELETE :";
   	cin>>n;
   	for(int i=1;i<=n;i++)
   	{
		   	cout<<"\nEnter Gadget name u want to DELETE :";
			cin>>Gadgetname;
		   	ifstream infile;
		 	ofstream outfile;
		 	infile.open("g1.txt",ios :: in);
			outfile.open("grefer.txt",ios :: out);
			infile.seekg(0,ios::beg);
		  	while(infile.read((char *)&g,sizeof(g)))
		  	{
			    if(stricmp(Gadgetname,g.gname)!=0)
		  		{
				   outfile.write((char *)&g,sizeof(g));
			    }
			    else
			    {
			    	k=1;
				}
			}
			if(k==1)
			{
				cout<<"\n*** DELETED SUCCESSFULLY ***\n";
			}
			outfile.close();
			infile.close();
        	remove("g1.txt");
			rename("grefer.txt","g1.txt");
     }
}




