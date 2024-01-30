#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void choices();
class book{
private: 
	string book_name;
	string author_name;
	int price,stock;

public:
	//default book
	book(){
		this->book_name = "None";
		this->author_name = "None";
		this->price = stock = 0;
	}
	//User entered book
	book(string bn,string an,int p,int s){
		this->book_name = bn;
		this->author_name = an;
		this->price = p;
		this->stock = s;
	}

	void enter_details(){
		string bn,an; int p,s;
		cout<<"**Enter book Details**: "<<endl;

		cout<<"Book Name: "; getline(cin,bn);
		this->book_name = bn;
		cout<<"Author Name: "; getline(cin,an);
		this->author_name = an;
		cout<<"Price: "; cin>>p;
		this->price = p;
		cout<<"Stock Amount: "; cin>>s;
		this->stock = s;

		fstream file;
		string file_name = book_name +"_"+ author_name;
		file.open(file_name,ios::out);

		if(!file.is_open()) cout<<"ERROR OPENINI FILE!"<<endl;

		file<<this->book_name<<endl;
		file<<this->author_name<<endl;
		file<<this->price<<endl;
		file<<this->stock<<endl;

		file.close();
	}

	void edit_details(){
		string bn1,bn2,an1,an2; int p,s;
		cout<<"**Enter previous Details**";

		cout<<"Prev Book Name: "; getline(cin,bn1);
		cout<<"Prev Author Name: "; getline(cin,an1);
		string file_name_prev = bn1 +'_'+ an1;

		cout<<"**Enter New Details**";
		cout<<"Book Name: "; getline(cin,bn2);
		this->book_name = bn2;
		cout<<"Author Name: "; getline(cin,an2);
		this->author_name = an2;
		cout<<"Price: "; cin>>p;
		this->price = p;
		cout<<"Stock Amount: "; cin>>s;
		this->stock = s;

		fstream file;
		file.open(file_name_prev,ios::out);

		if(!file.is_open()) cout<<"ERROR OPENINI FILE!"<<endl;

		file<<this->book_name<<endl;
		file<<this->author_name<<endl;
		file<<this->price<<endl;
		file<<this->stock<<endl;

		file.close();
	}

	void delete_book(){
		string bn,an;
		cout<<"**Enter book Details to Delete**: "<<endl;

		cout<<"Book Name: "; getline(cin,bn);
		cout<<"Author Name: "; getline(cin,an);

		string file_name = bn +'_'+ an;
		const char* file_name_cstr = file_name.c_str();
		remove(file_name_cstr);
	}

	void issue_book(){
		string bn,an;
		cout<<"**Enter Issue Book Details**"<<endl;

		cout<<"Book Name: "; getline(cin,bn);
		cout<<"Author Name: "; getline(cin,an);

		string file_name = bn +'_'+ an;
		this->stock--;

		fstream file;
		file.open(file_name,ios::out);

		if(!file.is_open()) cout<<"ERROR OPENINI FILE!"<<endl;

		file<<this->book_name<<endl;
		file<<this->author_name<<endl;
		file<<this->price<<endl;
		file<<this->stock<<endl;

		file.close();
	}

};

int main(){

	while(true){
		choices();
		int input; cin>>input;
		cin.ignore();

		book book_obj;
		if(input == 1) book_obj.enter_details();
		else if(input == 2) book_obj.edit_details();
		else if(input == 3) book_obj.delete_book();
		else if(input == 4)	book_obj.issue_book();
		else if(input == 5) break;
		else cout<<"Invalid input,Retry."<<endl;
	}
	
	return 0;
}

void choices(){
	cout<<"***Select Options***"<<endl;
	cout<<"1. Enter book detail"<<endl;
	cout<<"2. Edit  book detail"<<endl;
	cout<<"3. Delete a book"<<endl;
	cout<<"4. Issue a book"<<endl;
	cout<<"5. Exit"<<endl;
}