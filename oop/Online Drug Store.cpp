              //Drug store - C++
#include <iostream>  
#include <string>

      
using namespace std;
bool login();

class medicineType	//base class
{
public:
    void order();        //to  take_order
    void delete_order();       //to delete the order
    void modify();         //to modify the order
    void payment();	//function payment
	void order_list();      //to display the order_list
	void daily_summary();        //to display daily_summary
	void exit();       //function to exit system
	
	medicineType();      //constuctor

};

int main()	// Main function
{
    medicineType medicine;
	if(login()){
	int x;
	do
	{
		
		cout<<"\n";
		cout<<"\t\t\t   WELCOME TO DRUG STORE \n";
		cout<<"\t\t\t  =======================\n";
		b:
		cout<<"\t\t\t1. Customer side  \n";
		cout<<"\t\t\t2. Admin side     \n";
		cout<<"\n";
		cout<<"  Enter choice: ";
        cin>>x;
        switch (x)
		{
case 1:
	        label:
	          cout<<"\n";
		      cout<<"\t\t\t   ***Customer side*** \n";
		      cout<<"\t\t\t1. Medicine order \n";
		      cout<<"\t\t\t2. Make Payment \n";
		      cout<<"\t\t\t3. Modify \n";
		      cout<<"\t\t\t4. Exit \n";
		cout<<"\n";
		cout<<"  Enter choice: ";
        cin>>x;
        switch (x)
		{
		case 1:
			{
				medicine.order();	           //function order
				goto label;
				break;
			}
        case 2:
			{
				medicine.payment();	           //function payment
				goto label;
				break;
			}
		case 3:
				{    
				medicine.modify();	         //function update
				goto label; 
				break;
			}
		case 4:
			{
				medicine.exit();	          //function exit
				goto a;
				break;
			}
			break;
	default:
			{
				cout<<"\tInvalid input \n     re-enter the input\n"<<endl;
				goto a;
				break;
			}//end defeault
		}//end Switch	
case 2:
	        start:
	          cout<<"\n";
	          cout<<"\t\t\t   ***Admin side***   \n";
		      cout<<"\t\t\t1. Delete latest Medicine order \n";
		      cout<<"\t\t\t2. Print the Receed  \n";
		      cout<<"\t\t\t3. Daily Summary of total Sale  \n";
		      cout<<"\t\t\t4. Exit \n";
		cout<<"Enter choice: ";
        cin>>x;
        switch (x)
		{
		case 1:
			{
				medicine.delete_order();	//function delete
				goto start;
				break;
			}
			
		case 2:
			{
				medicine.order_list();	//function show list
				goto start;
				break;
			}
				
        case 3:
			{
				medicine.daily_summary();	//function daily_summary
				goto start;
				break;
			}	
        case 4:
			{
				medicine.exit();	//function exit
				goto a;
				break;
			}
			break;
		default:
			{
				cout<<"\tInvalid input \n     re-enter the input\n"<<endl;
				goto a;
				break;
			}//end defeault
		}//end Switch
	    
default:
			{
				cout<<"\tInvalid input \n     re-enter the input\n"<<endl;
				break;
			}//end defeault
		}//end Switch
	}
	while(x!=2);//end do
	a://goto
	cout<<"\tthank you"<<endl;
	system ("PAUSE");
	goto b;
	return 0;
  }
}
//end  main function

bool login()
     {
	    string name, password;
	    system("cls");  //   clear screen
	    cout<<"\n";
	    cout<<"\t\t\t\t\t\t DRUG STORE \n";
	    cout<<"\t\t\t\t\t\t************\n";
	    cout<<"\n\t\t\t\tLOGIN PAGE \n";
	    cout<<  "\t\t\t\t==========";
	    label:
		cout<<"\n";		
	    cout<<"\n  Enter name:";
	    cin>>name;
	    cout<<" Enter password:";
	    cin>>password;
	    if(name=="mughal"&&password=="123")
		{
		system("pause");
		system("cls");
		}
	    else{
	    cout<<"	\n";
		cout<<"\t\t WRONG PASSWORD \n\n    RE-ENTER PASSWORD ";
		goto label;   // jump to label
	    }			
	}
	
medicineType::medicineType ()
{

}     //constructor for class medicineType

struct node //constract node
{
	int receed_number, quantity[15], array[15];
	string customerName, date;
    double amount[15];
    string medicineName[15]={"Pulmonal","Vitamin C(500mg)","Acsol gel Tube","Panadol Tablet","Disprine Tablet","Paracitamol Tablet",
	"Amino Zinc Tablet","Vixk","Bitnovate","Tenormin tablet"," Marino Tablet","Maxi Cal Tablet",
    "Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[15] = {22.00,30.00,110.00,15.00,10.00,55.00,72.00,14.00,45.00,8.00,1.00,5.00,4.00,3.00,5.00};
	double total;
	int data;
	node *prev;
	node *next;
}
*q, *temp;				//pointer declaration 
node *start = NULL; 
node *head = NULL;
node *last = NULL;


void medicineType::order()		//function to order
{
    int quantity, key;
	cout <<"\n\tMedicine list\n";
	
	node *temp;
	temp=new node;

				cout<<"\t" <<"***************************************************************\n";
				cout<<"\t"<<"DRUGS ID"<<"      \t\tDRUGS NAME"<<"           DRUGS PRICE(RM)"<<endl;
				cout<<"\t" <<"***************************************************************\n";
                cout<<"\t"<<"01"<<"\t\t"<<"    Pulmonal serup"<<"	        RM 22.00"<<endl;
                cout<<"\t"<<"02"<<"\t\t"<<"    Vitamin C(500mg) Tablet"<<"     RM 30.00"<<endl;
                cout<<"\t"<<"03"<<"\t\t"<<"    Acsol gel Tube"<<"		RM 110.00"<<endl;
                cout<<"\t"<<"04"<<"\t\t"<<"    Panadol Tablet"<<"		RM 15.00"<<endl;
                cout<<"\t"<<"05"<<"\t\t"<<"    Disprine Tablet"<<"	 	RM 10.00"<<endl;
                cout<<"\t"<<"06"<<"\t\t"<<"    Paracitamol Tablet"<<" 		RM 55.00"<<endl;
                cout<<"\t"<<"07"<<"\t\t"<<"    Amino Zinc Tablet"<<"		RM 72.00"<<endl;
                cout<<"\t"<<"08"<<"\t\t"<<"    Vixk"<<"			RM 14.00"<<endl;
                cout<<"\t"<<"09"<<"\t\t"<<"    Bitnovate"<<"			RM 45.00"<<endl;
                cout<<"\t"<<"10"<<"\t\t"<<"    Tenormin tablet"<<"		RM 8.00"<<endl;
                cout<<"\t"<<"11"<<"\t\t"<<"    Marino Tablet"<<"	 	RM 1.00"<<endl;
                cout<<"\t"<<"12"<<"\t\t"<<"    Maxi Cal Tablet"<<" 		RM 5.00"<<endl;
                cout<<"\t"<<"13"<<"\t\t"<<"    Burnex"<<"			RM 4.00"<<endl;
                cout<<"\t"<<"14"<<"\t\t"<<"    Fabuloss 5"<<"			RM 3.00"<<endl;
                cout<<"\t"<<"15"<<"\t\t"<<"    Royal Propollen"<<"		RM 5.00"<<endl;
                cout<<" "<<endl;
    
	cout << "Type Order no: ";
    cin >> temp->receed_number;
	cout<< "\nEnter Customer Name: ";
	cin>> temp->customerName;
	cout<<"\nEnter Date : ";
	cin>>temp->date;
	cout << "\nHow many Medicine would you like to order:";
	cout << "  ";
	cin >> temp->data;
	for (int i=0; i<temp->data; i++)
	{
		cout<<"\n";
		cout << "\tPlease enter your selection : ";
		cin>> temp->array[i];
        cout<< "\n\tMedicine Name: " <<temp->medicineName[temp->array[i]-1];
        cout << "\n\tHow many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->array[i]-1];
        cout << "\n\tThe amount You need to pay is: " << temp->amount[i]<<" RS."<<endl;
    }
    temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9]+temp->amount[10]+temp->amount[11]+temp->amount[12]+temp->amount[13]+temp->amount[14];
	cout<<"\n\tTotal Bill is: "<<temp->total;
	cout<<"\n";
	cout<<"==========================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================="<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"====================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start!=NULL)
	{
		temp->next=start;
	}
	start=temp;
 }      //End function order


void medicineType::payment()		//Function to display receipt
{
	int i,quantity, amount_paid, num;	
	bool found;			//variable to search 
	node *temp;

	temp=start;
	found = false;
	
	cout<<" \tEnter the Receed_number \n";
	cin>>num;
	cout<<"\n";
	cout<<"==================="<<endl;
	cout <<"\tOrdered list:\n"; 
	cout<<"==================="<<endl;

	if(temp==NULL) //Invalid receed code
	{
		cout<<"\n";
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL)
	{
		if (temp->receed_number==num)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
        cout <<"\n";
		cout <<"\tReceed_nunber : "<<temp->receed_number;
		cout <<"\n";
		cout<<"\tCustomer Name: "<<temp->customerName<<endl;
				
		cout<<"\tOrder Date : "<<temp->date<<endl;
			
		cout << "======================================================================" << endl;
		cout << "|     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "=======++==================++================++===============++======" << endl;
		for (i=0;i<temp->data;i++)
		{
			cout<<temp->medicineName[temp->array[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<<temp->amount[i]<<" RM"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9]+temp->amount[10]+temp->amount[11]+temp->amount[12]+temp->amount[13]+temp->amount[14];
	   }
		cout<<"\n\tTotal Bill is: "<<temp->total;
		cout<<"\n";
		cout<<"Amount You need to pay: ";
        cin>>amount_paid;
                            //If entered money is greater and equal then then the item money
        if (temp->total>amount_paid) 
	     {
		     cout<<"\n\t Sorry! u does't have sufficient amount of money."<<endl;
	     }
		                                 //If entered money is lesser then then the item money
		else 
		   {
		     int amount=amount_paid-temp->total; 
		     cout<<"\n";
		     cout<<"\t\tremaining money=  "<<amount<<endl;
		     cout<<"\n\tPayment Done\n\t\t\tThank you for visiting"<<endl;
		     break;
           }  
}
}	//End function order_list
 
void medicineType::order_list()		//Function to display receipt
{
	int i, payment, num;	
	bool found;			//variable to search 
	node *temp;

	temp=start;
	found = false;
	
	cout<<" \tEnter the Receed_number To Print The raceed\n";
	cin>>num;
	cout<<"\n";
	cout<<"==================="<<endl;
	cout <<"Ordered list:\n"; 
	cout<<"==================="<<endl;

	if(temp==NULL) //Invalid receed code
	{
		cout<<"\n";
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->receed_number==num)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
        cout <<"\n";
		cout <<"\tReceed_nunber : "<<temp->receed_number;
		cout<<"\tCustomer Name: "<<temp->customerName<<endl;		
		cout<<"\tOrder Date : "<<temp->date<<endl;
			
		cout << "======================================================================" << endl;
		cout << "|     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "=======++==================++================++===============++======" << endl;
		for (i=0;i<temp->data;i++)
		{
			cout<<temp->medicineName[temp->array[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<<temp->amount[i]<<" RM"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9]+temp->amount[10]+temp->amount[11]+temp->amount[12]+temp->amount[13]+temp->amount[14];
						
		cout<<"\n\tTotal Bill is : "<<temp->total;
		}
}
}	//End function order_list


void medicineType::delete_order()	//function to delete_order
{
	system("cls");
	int i, num, count;
    cout<<"\n\tEnter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start == NULL)
		cout<<"\n\tCan't delete from an empty list.\n";
	else
	{
		if(start->receed_number== num)
		{
			q = start;
			start = start->next;
			count--;
			if(start == NULL)
			last = NULL;
			delete q;
			cout<<"\n\tThe Receed is Deleted "<<endl;
		}
		else
		{
			found = false;
			temp = start;
			q = start->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->receed_number != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q) 
				last = temp;
				delete q;
				cout<<"\n\tThe Receed is Deleted "<<endl;
			}
			else
				cout<<"\n\tReceed to be deleted is not found."<<endl;
			}
		} 
}	//End function delete_order

void medicineType::modify()		//function to update order
{
 system("cls");
 int i,num;
 bool found;
 found = false;
 temp = start;
 cout<<"Enter Receed Number To Modify: ";
 cin>>num;
 if (temp==NULL && num==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->receed_number==num)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->receed_number;
	cout<< "Change Customer Name: ";
	cin>> temp->customerName;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cin >> temp->data;
	for (i=0; i<temp->data; i++)
	{	
		cout << "Please enter your selection to Change: "<<endl;
		cin>> temp->array[i];
        cout<< "Change Medicine Name: " <<temp->medicineName[temp->array[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->array[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" RS."<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");
	
   cout<<"RECORD MODIFIED....!"<<endl;
}
 else 
 {
 	if(temp != NULL && temp->receed_number != num)
 	{
 	cout<<"Invalid Receed Number...!"<<endl;
    }
}
 }
}
}		//End modify function

void medicineType::daily_summary()		//Function to display Daily Summary
{
	int num ;
	node *temp;
	temp=start;
	
	if(temp == NULL) //Invalid receed code
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"=========================================="<<endl;
		cout <<" \t\t Daily Summary of All Orders \n"; 
		cout<<"=========================================="<<endl;

		while(temp!=NULL)
		{
		
				cout <<"\tReceed Number : "<<temp->receed_number;
				cout <<"\n";
				cout<<"\tCustomer Name: "<<temp->customerName<<endl;
				
				cout<<"\tOrder Date : "<<temp->date<<endl;
			
				cout << "==========================================================================" << endl;
				cout << "|   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "=======++==================++================++===============++==========" << endl;
				
			for (int i=0; i<temp->data; i++)
			{
				cout<<temp->medicineName[temp->array[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" RS."<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}
			
			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9]+temp->amount[10]+temp->amount[11]+temp->amount[12]+temp->amount[13]+temp->amount[14];
			cout<<"\tTotal Bill is : "<<temp->total;
		
			cout <<"\n";
			cout <<"\n";
				
			temp=temp->next;
		}
	}
}		//End daily summary



void medicineType::exit() //Function to exit
{
	cout<<"\n\tYou choose to exit.\n"<<endl;
}	
   //end function exit

