#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){

int variante, n, i, j, nr, l, ajustari = 0, it, cost;

FILE * fin = fopen("evaluare.in", "r");
FILE * fout = fopen("evaluare.out", "w");

fscanf( fin , "%d %d" , &variante , &n );						
//citire numar de variante si lungimea unei variante

vector<vector <int> > m = vector<vector<int> >(n ,vector<int>(variante, -1));		
//matricea care retine variantele
vector<int> cuv;									
//cuvantul rostit

	for ( j = 0 ; j < variante ; j++ ){
		for ( i = 0 ; i < n ; i++ ){
			//citire variante
			fscanf( fin , "%d" , &nr );
			m[i][j] = nr;
		}
	}

	fscanf( fin , "%d" , &l );

int matrix[l + 1][n + 1];		
//matrix este folosita pentru programarea dinamica a problemei

	for ( i = 0 ; i < l ; i++ ){		
		//citire cuvant rostit
		fscanf( fin , "%d" , &nr );
		cuv.push_back(nr);
	}

	for ( j = 0 ; j < n + 1 ; j++ ){
		for ( i = 0 ; i < l + 1 ; i++ ) {
			//parcurgerea matrici matrix si aplicarea recursivitatii Levenshtein

			if ( i == 0 || j == 0 ) {
				matrix[i][j] = std::max( i , j );
				continue;
			}

			cost = 1;

			for ( it = 0 ; it < variante ; it++ ) {
				if ( m[j - 1][it] == cuv[i - 1] ){	
					//daca litera de pe pozitia i - 1 este egala cu una dintre
					//literele de pe pozitia j - 1 din fiecare varianta
					cost = 0;
					break;
				}
			}

			matrix[i][j] = std::min(std::min(matrix[i - 1][j] + 1 , matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
		}
	}

	ajustari = matrix[l][n];		
	//rezultatul final , numarul final de ajustari

	fprintf( fout , "%d" , ajustari );
fclose(fin);
fclose(fout);

return 0;
}
