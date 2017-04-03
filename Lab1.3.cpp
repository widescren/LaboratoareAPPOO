#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <list>
#include <string>
using namespace std;
#include <algorithm>

class Masini
{public: 

string marca;
string model;
float  pret;

public:
	Masini ();
	Masini(string,string,float);
	Masini(const Masini&);
	string GetMarca();
	int GetPret();
	bool great(int value);
	friend iostream& operator>>(iostream&,Masini&);
	friend ostream&  operator<<(ostream&,Masini&);
	Masini& operator = (const Masini&);
	 bool operator==(const Masini&);
    bool operator<(const Masini&);

	};

	class compareCrescator {
public:
    bool operator()(Masini& b1, Masini& b2)
    {
        if (b1.pret > b2.pret)
            return false;
        else
            return true;
    }
};

string Masini::GetMarca() { return marca; }
int Masini::GetPret() { return pret; }
class compareDescrescator {
public:
    bool operator()(Masini& b1, Masini& b2)
    {
        if (b1.pret < b2.pret)
            return false;
        else
            return true;
    }
};

class comp_marca {
    string s;

public:
    comp_marca(string S) { s = S; }
    bool operator()(Masini& b)
    {
        if (b.GetMarca() == s)
            return true;
        else
            return false;
    }
};

class comp_price {
    int t;

public:
    comp_price(int T) { t = T; }
    bool operator()(Masini& b)
    {
        if (b.GetPret() > t)
            return true;
        else
            return false;
    }
};
typedef vector<Masini> car;
typedef vector<Masini>:: iterator iter;
typedef list <Masini> L1;
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
bool Masini::operator < (const Masini& b)
{
    if (marca < b.marca)
        return true;
    else
        return false;
}

bool Masini::operator == (const Masini& b)
{
    if (marca == b.marca)
        return true;
    else
        return false;
}

void FindMarca(car d, string s)
{
    cout << ("\nMasini de tip") << s << endl;
    iter j = d.begin();
    int i = 0;
    while (j != d.end()) {
        j = find_if(d.begin(), d.end(), comp_marca(s));
        if (j != d.end()) {
            cout << *j << endl;
            d.erase(j);
            i++;
        }
    }
    if (i == 0)
        cout << ("\nNu sunt asa tip de Masini\n");
}


void Copy_if(car& d, L1& s, comp_price p)
{

    iter j;
    j = d.begin();
    while (j != d.end()) {
        if (p(*j)) {
            s.push_front(*j);
            
        }

        j++;
    };
 
}
void Sort(L1& s)
{
    vector<Masini> d;
    while (!s.empty()) {
        d.push_back(s.front());
        s.pop_front();
    }
    sort(d.begin(), d.end(), compareCrescator());
    for (int i = 0; i < d.size(); i++)
        s.push_back(d[i]);
}
void PrintVector(string str, car d)
{
    vector<Masini>::iterator p = d.begin();
    cout << (str) << endl;
    if (d.empty())
        cout << ("\nVectorul este gol\n");
    else
        for (; p != d.end(); p++)
            cout << *p << endl;
}

void PrintList(string str, L1 s)
{

    cout << (str) << endl;
    list<Masini>::iterator p = s.begin();
    if (s.empty())
        cout << ("\nLista este goala\n");
    else
        for (; p != s.end(); p++)
            cout << *p << endl;
}
car Merge(car& Vec, L1& List)
{
    car temp, ret;
    while (!List.empty()) {
        temp.push_back(List.front());
        List.pop_front();
    }
    ret.resize(Vec.size() + temp.size());
    merge(Vec.begin(), Vec.end(), temp.begin(), temp.end(), ret.begin());
    return ret;
}
int main()
{
    vector<Masini>::iterator Iter1, Iter2, new_end;
    car Vec1, Vec2;
    L1 List1;
    iter Veciter;
    Masini mas;
    Masini mas2;
    Masini mas3;
    int n = 0;
    string marca;
    cout << "Introduceti nr de elemente a vectorului ";
    cout << endl;
    cin >> n;
    //implem vectorul
    for (int i = 0; i < n; i++) {
        cout << "Introduceti vectorul ";
        cout << endl;
        cin >> mas;
        Vec1.push_back(mas);
    }

    sort(Vec1.begin(), Vec1.end(), compareDescrescator());
    PrintVector("\nAfisarea Vectorului sortat descrescator\n", Vec1);
    cout << "Introduceti brandul cautat";
    cin >> marca;
    FindMarca(Vec1, marca);
    Copy_if(Vec1, List1, comp_price(10000));
    Vec1.erase(std::remove_if(Vec1.begin(), Vec1.end(), comp_price(10000)),
        Vec1.end());

 

    PrintList("AFisarea listei\n", List1);
    //Sortare
    sort(Vec1.begin(), Vec1.end(), compareCrescator());
    //PrintVector("\nAfisarea Vectorului sortate\n",Vec1);
    Sort(List1);
    PrintVector("\nAfisarea Vectorului Sortat crescator\n", Vec1);
    PrintList("AFisarea listei sortate crescator\n", List1);

    Vec2 = Merge(Vec1, List1);
    PrintVector("\nUnirea Vectorului si a listei \n", Vec2);
    cout << count_if(Vec2.begin(), Vec2.end(), comp_price(10000)) << endl;
    cout << "Introduceti marca cautat";
    string marca2;
    cin >> marca2;
    FindMarca(Vec2, marca2);
    cout << endl;
    system("pause");
}
