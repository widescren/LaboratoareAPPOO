#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

class Masini
{public: 

string marca;
string model;
float  pret;

public:
	Masini ();
	Masini(string,string,float);
	Masini(const Masini&);
	void Input();
	void Show();
	friend iostream& operator>>(iostream&,Masini&);
	friend ostream&  operator<<(ostream&,Masini&);
	Masini& operator = (const Masini&);




};

typedef vector<Masini> car;
typedef vector<Masini>:: iterator iter;

void Print1(string,car);
void Print2(string,car);

void Delete (car&,iter,int);
void Chenge (car&,iter,int,car&);
//----------------------------------------
Masini::Masini()
{

marca = ("Default");
model = ("Default");
pret = 0;


}
//----------------------------------------
Masini::Masini(string Marca,string Model,float Pret)
{
 marca = Marca;
 model = Model;
 pret  = Pret;

}

//----------------------------------------
Masini::Masini(const Masini& a)
{

marca = a.marca;
model = a.model;
pret  = a.pret;

}
//----------------------------------------
void Masini::Show()
{
    cout<<("Marca : "); cout<<marca<<endl;
	cout<<("Model : ");cout<<model<<endl;
	cout<<("Pretul: ");cout<<pret<<endl;


}
//----------------------------------------
istream& operator>>(istream& in,Masini & B)
{

    in>>B.marca;
	in>>B.model;
	in>>B.pret;
   return(in);
}
//----------------------------------------
ostream& operator<<(ostream& out,Masini& B)
{

    out<<B.marca<<endl;
	out<<B.model<<endl;
	out<<B.pret<<endl;	
	return out;
}

//----------------------------------------
Masini& Masini::operator = (const Masini& b){
if(this==&b) return *this;
marca = b.marca;
model = b.model;
pret  = b.pret;
return *this;

}
void Print1(car d)
{
	
	if(d.empty())
		cout<<("\nVectorul este gol/sau nu exista\n");
	else
		for(int i=0;i<d.size();i++)
			cout<<d[i]<<endl;
}
//-----------------------------------------
void Print2(car d)
{
	
	iter p = d.begin();
	
	if(d.empty())
		cout<<("\nVectorul este gol/sau nu exista\n");
	else
		for(;p!=d.end();p++)
			cout<<*p<<endl;
}





int main()
{

car car1,car2;
iter itercar;

Masini mas;
Masini mas1;
Masini mas2;

int n=0;

cout<<"Introduceti numarul de elemente a vectorului";
cout<<endl;
cin>>n;
//Implementam vectorul
for(int i=0;i<n;i++){
cout<<"Introduceti datele vectorului";
cout<<endl;
       cin>>mas;
       car1.push_back(mas);

}

//stergerea din vectro si adaugarea elementelor noi
cout<<endl;
int t;
cout<<"Cite elemente doriti sa se stearga ?(Tot atitea se vor aduga inapoi)";
cin>>t;
car1.erase(car1.begin(),car1.begin()+t);
for (int i=0;i<t;i++)
{
cout<<endl;
cout<<"Introduceti vectorul";
cout<<endl;
cin>>mas2;
car1.push_back(mas2);

}

//afisarea vectorului cu ajutorul iteratorilor
cout<<endl;
cout<<"Primul vector modificat";
cout<<endl;
for(itercar=car1.begin();itercar !=car1.end(); itercar++){
	cout<<*itercar<<" ";
}


cout<<endl;
cout<<"Cite obiecte doriti sa adaugati in vectorul 2";
int d=0;
cin>>d;
//implementare 2 vector
for(int i=0;i<d;i++){

cout<<"Intorduceti vectorul";
cout<<endl;
cout<<endl;
   cin>>mas2;

   car2.push_back(mas2);

}
cout<<endl;
cout<<"Al 2 vector";
cout<<endl;
for(int i=0;i<car2.size();i++){

	cout<<car2[i]<<" ";
}

int e;
cout<<endl;
cout<<"Cite elemente doriti sa stergeti din primul vector";

cin>>e;
car1.erase(car1.begin(),car1.begin()+e);
for(int i=0; i<car1.size();i++){

	cout<<car1[i]<<" ";

}

car1.insert(car1.end(),car2.begin(),car2.end());
cout<<endl;
cout<<"Primul vector midificar a doua oara";
cout<<endl;
for (int i=0;i<car1.size();i++){

	cout<<car1[i]<<" ";
}

cout<<endl;
system("pause");




}