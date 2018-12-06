#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

vector<string> cuvinte;		
//lista de cuvinte citite din fisier

int n,i,j,k,nrmutari,nr,count;

char c[360],o;

FILE * fin = fopen("joc.in", "r");
FILE * fout = fopen("joc.out", "w");

fscanf( fin , "%d" , &n );

	for ( i = 0 ; i < n ; i++ ) {		
		//citesc fiecare cuvant
		fscanf ( fin , "%s" , c );
		cuvinte.push_back(c);
	}

	for ( i = 0 ; i < n ; i++ ) {		
		//iau pe rand fiecare cuvant din lista de cuvinte

		nrmutari = 0;

		//mai intai verific ca cuvantul curent poate fi palindrom

		nr = 0;		//numarul de litere cu nr impar de aparitii in cuvant

		for ( o = 97 ; o <= 122 ; o++ ) {
			//pentru fiecare litera mica din alfabet

			count = std::count( cuvinte[i].begin() , cuvinte[i].end() , o );	
			//cout este numarul ei de aparitii in cuvant

			if ( count%2 != 0 ) {
				nr += 1;
			}
			if ( nr == 2){
				break;
			}
		}

		if ( nr == 2 ){
			// daca se ajunge la 2 litere cu un numar impar de aparitii

			fprintf ( fout , "%d\n" , -1 );
			continue;
			//daca cuvantul nu poate fi palindrom atunci trec la urmatorul
		}

		while ( cuvinte[i].length() > 1 ){
			if ( cuvinte[i][0] != cuvinte[i][ cuvinte[i].length() - 1] ) {
				//daca prima litera nu este egala cu ultima

				k = 0;
				//k devine devine 1 cand se gaseste perechea pentru litera curenta

				for ( j = cuvinte[i].length() - 2 ; j > 0 ; j-- ) {
					//iau fiecare litera de la dreapta la stanga 
					//pentru a avea un numar minim de mutari

					if ( cuvinte[i][j] == cuvinte[i][0] ) {
						//cand s-a gasit perechea

						k = 1;
						cuvinte[i].erase( cuvinte[i].begin() + j );	
						//o sterg din cuvant

						cuvinte[i].erase( cuvinte[i].begin());
						// si sterg si prima litera

						nr = cuvinte[i].length() + 2 - j - 1;
						//numarul de mutari pe care l-am fi facut 
						//daca am fi facut interschimbarile , in loc sa stergem

						nrmutari += abs(nr);	
						j = -1;						
					}						
				}

				if ( k == 0 ) {
					//daca prima litera nu are pereche atunci o sterg

					nr = cuvinte[i].length() - 1  - cuvinte[i].length()/2;
					//numarul de mutari pe care le-as fi 
					//facut daca as fi transportat-o in centru

					cuvinte[i].erase( cuvinte[i].begin());
					nrmutari += nr;
				}
			}
			else {
				//daca prima si ultima litera sunt egale
				//atunci le sterg fara sa modific numarul de modificari

				cuvinte[i].erase( cuvinte[i].begin() + cuvinte[i].length() - 1);
				cuvinte[i].erase( cuvinte[i].begin());
			}
		}
		fprintf( fout , "%d\n" , nrmutari );
	}
fclose(fin);
fclose(fout);

return 0;
}
