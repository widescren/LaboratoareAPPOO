#include <iostream>
#include <vector>
#include <cstdlib>



using namespace std;

int main(){
//cream vectorul
vector<int> vec;
vector <int>::iterator vec1;

//implimentez vectorul
for(int i=0; i<10; i++){
vec.push_back(i);
}

    cout <<"Primul Vector";
    cout <<endl;

//afisam vectorul
for(int i=0;i<vec.size();i++){

	cout<<vec[i]<<" ";
}
cout<<endl;
//sterg din vector si adau alte elemente in loc

vec.erase(vec.begin(),vec.begin()+2);
for(int i=0; i<2; i++){
vec.push_back(0);

}
cout<<"Vectorul 1 dupa modificare";
cout<<endl;
for( vec1=vec.begin(); vec1!=vec.end(); vec1++){

	cout<< *vec1 <<" ";

}
cout<<endl;
//implementez al 2 vector
vector<int> vec2;
for( int i=0;i<10;i++){

vec2.push_back(i);

}
//afisez al e vector
cout<<" Vectorului 2";
cout<<endl;

for(int i=0;i<vec2.size();i++){

	cout<<vec2[i]<<" ";
}
//introduc nr-u de elemente care doresc sa il sterg
cout<<endl;
int n;
cout<<"Introduceti nurmarul de elemente pe care doriti sa-l stergeti";
cin>>n;

vec.erase(vec.begin(),vec.begin()+n);
for(int i=0;i<vec.size();i++){

	cout<<vec[i]<<" ";
}
vec.insert(vec.begin(),vec2.begin(),vec2.end());

cout<<endl;
cout<<"Vectorul 1 a doua oara modificat ";
cout<<endl;
for(int i=0; i<vec.size();i++){

	cout<<vec[i]<<"    ";
}





     cout<<endl;
system("pause");
}