// Nama		: Riofebri Prasetia
// NIM		: 221911192
// Kelas	: 3SI1

// iterasi gauss seidel

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
	int N;
	printf("masukkan ukuran matrix: ");
	scanf("%d", &N);
	double x[N][N], b[N], xk[N], tol, xk1[N], e, e1;
	int l;

	printf("Masukkan Matriks A berukuran %d x %d: \n", N, N);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%lf", &x[i][j]);
		}
	}
	printf("Masukkan Vektor B berukuran %d : \n", N);
	for (int i=0; i<N; i++){
		scanf("%lf", &b[i]);
	}
	printf("Masukkan nilai X0 berukuran %d : \n", N);
	for (int i=0; i<N; i++){
		scanf("%lf", &xk[i]);
	}

	printf("masukkan nilai toleransi: ");
	scanf("%lf", &tol);

	printf("masukkan batas jumlah iterasi: ");
	scanf("%d", &l);

	for (int k=0; k<l; k++){
		printf("angka iterasi ke- %d : \n", k+1);
		e1 = 0;
		for (int i=0; i<N; i++){
			xk1[i] = 0;
			for (int j=0; j<N; j++){
				if (i!=j){
					xk1[i] = xk1[i] + x[i][j]*xk[j];
				}
			}
			xk1[i] = (b[i] - xk1[i])/x[i][i];
			e = fabs(xk1[i] - xk[i]);
			printf("variabel ke-%d adalah %f dengan error = %f \n", i+1, xk1[i], e);
			if (e > e1){
				e1 = e;
			}
			xk[i] = xk1[i];
		}

		if(e1 < tol){
			exit;
		}
	}

	return 0;
}