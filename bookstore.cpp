#include <iostream>
#inculde<stdlib.h>
#include <fstream>

using namespace std;

class book	{
	char title[20],author[20];
	int price,stock;
	
	public:
		void feeddata()	{
			cout<<"\nEnter Title Of Book: "; cin.getline(title,20);
			cout<<"Enter Author Of Book: ";  cin.getline(author,20);
			cout<<"Enter Price Of Book: "; cin>>price;
			cout<<"Enter Number Of Books in Stock: "; cin>>stock;
		}
		
		void showdata()	{
			cout<<"\nTitle: "<<title;
			cout<<"\nAuthor: "<<author;
			cout<<"\nPrice: Rs. "<<price;
			cout<<"\nStock: "<<stock<<" books";
		}
		
		bool search(char t[],char a[])	{
			if(strcmp(title,t)==0 && strcmp(author,a)==0)
				return true;
			else
				return false;
		}
		
		void buybook()	{
			int count;
			cout<<"\nEnter Number Of Books to buy: ";
			cin>>count;
			if(count<=stock)	{
				stock=stock-count;
				cout<<"\nBooks Bought Sucessfully";
				cout<<"\nAmount: Rs. "<<price*count;
			}
			else
				cout<<"\nRequired Copies not in Stock";
		}
		
		void editdata()	{
			int newstock;
			cout<<"\nEnter New Number Of Books in Stock: "; cin>>newstock;
			stock=newstock;
		}
		
		void saveToFile() {
			ofstream outfile;
			outfile.open(title);
			outfile << title << endl;
			outfile << author << endl;
			outfile << price << endl;
			outfile << stock << endl;
			outfile.close();
		}
};

int main()	{
	book *B[20];
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Details Of Book"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		
		switch(choice)	{
			case 1:	B[i] = new book;
				B[i]->feeddata();
				B[i]->saveToFile();
				i++;	break;
				
			case 2: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						B[t]->buybook();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Book is Not in Stock";
				
				break;
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in Stock";
				break;
			
			case 4: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nBook Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in Stock";
				break;
			
			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";
			
		}
	}
	
	
	
	
	return 0;
}
