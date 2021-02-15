#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


string funcionH(string cadena, string vocabulario){
	ll primero=ll(cadena[0]) + ll(cadena[cadena.length()-1]);
	ll res=primero;
	string resultado="";
	for(ll i=0;i<cadena.length();i++){ 
		res=res+ll(cadena[i]);
		resultado=resultado+vocabulario[res%62];//char(res%26 + 65);
	}
	return resultado;
}


int main(){
//By:DavidYQ
	string cadena;
	cout<<"Ingrese su cadena: ";
	getline(cin,cadena);
	string vocabulario="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	ll numeroVeces=ll(cadena[1])+ll(cadena[cadena.length()-2]);
	for(int i=0;i<numeroVeces;i++){ 
		cadena=funcionH(cadena,vocabulario);
	}
	if(cadena.length()<63){
		int n=cadena.length();
		for(int i=n-1; i<63 ; i++){
			cadena=cadena+cadena[i%n];
		}
		cadena=funcionH(cadena,vocabulario);
	}
	string reducido="";
	    ll red;
	    if(cadena.length()>64){
	        for(int i=0;i<64;i++){ 
	            red=0;
	            ll j=i;
	            while(j<cadena.length()){
	                j=j+65;
	                red=red+ll(cadena[j]);
	            }
	            reducido=reducido+(vocabulario[red%62]);
	        }
	        cadena=reducido;
	        cadena=funcionH(cadena,vocabulario);
	    }
	cout<<"Mensaje codificado: ";
	cout<<cadena<<endl;
	cout<<"\n cadena codificada con longitud de "<<cadena.length()<<endl;
return 0;
}


