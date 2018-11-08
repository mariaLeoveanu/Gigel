#include <stdio.h>
#define NMAX 100


int umplere (char a[NMAX][NMAX], int n, char nume);

int main() {
	int n, m, linie, coloana, i, j;
	//nume_ant il folosesc sa verific ca doua persoane consecutive care fac mutari sunt diferite
	char mat[NMAX][NMAX], nume, nume_ant;
	scanf("%d%d", &n, &m);
	//sterg mai tarziu asta, afisez pt verificarea tablelei
	for(i = 0; i < n * n; i++) {
		for(j = 0; j < n * n; j++) {
			mat[i][j] = '-';
		}
	}

	scanf(" %c", &nume);
	//primul nume urmeaza sa fie comparat cu al doilea citit
	nume_ant = nume; 
	scanf("%d%d", &linie, &coloana);
	//aici nu verific daca un anume element e deja ocupat deoarece e prima mutare, tabla e goala
	if (linie > n * n - 1 || coloana > n * n - 1) {
		printf("INVALID INDEX\n");
		umplere(mat, n * n, nume);
	} else { 
		mat[linie][coloana] = nume;
	}

	for (i = 0; i < m - 1; i++){
		scanf(" %c", &nume);
		scanf("%d%d", &linie, &coloana);
		if(nume_ant == nume){
			printf("NOT YOUR TURN\n");
		} else if (linie > n * n - 1 || coloana > n * n - 1) {
			printf("INVALID INDEX\n");
			umplere(mat, n * n, nume);
		} else if (mat[linie][coloana] != '-') {
			printf("NOT AN EMPTY CELL\n");
			umplere(mat, n * n, nume);
		} else { 
			mat[linie][coloana] = nume;
		}
		nume_ant = nume;
	}
		
	for(i = 0; i < n * n; i++) {
		for(j = 0; j < n * n; j++) {
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int umplere (char a[NMAX][NMAX], int n, char nume){
	int i, ok = 0, k, j;
	//diagonala principala
	for(i = 0; (i < n) && (ok == 0); i++){
		if(a[i][i] == '-'){
			a[i][i] = nume;
			ok = 1;
		}
	}
//urmatoarele diagonale
	for(i = 1; (i < n) && (ok == 0); i++){
		k = i;
		for(j = 0; (j < n) && (k < n) && (ok == 0); j++){
			if(a[j][k] == '-'){
				a[j][k] = nume;
				ok = 1;
			}
			k++;
		}
		k = i;
		for(j = 0; (j < n) && (k < n) && (ok == 0); j++){
			if(a[k][j] == '-'){
				a[k][j] = nume;
				ok = 1;
			}
			k++;
		}
	}
	if(ok == 0){
		printf("FULL BOARD\n");
	}
	return ok;
}