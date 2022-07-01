#include <stdio.h>
#include <math.h>

float titik[100][100];
float cvalue[100];

void aproxFungsi();
void aproxTurunan();
void aproxIntegral();
void menentukanTitik(int m);
void menentukanValueC(int m);
float HasilPolinomial(float x, int m);
float hasilKaliKurung(int m, float x);
void printPolinomial(int m);

int main()
{
    int ch;
    while (1)
    {
        printf("Berikut metode yang tersedia : \n");
        printf("1. Approximasi Fungsi\n");
        printf("2. Approximasi Turunan\n");
        printf("3. Approximasi Integral\n");
        printf("4. Keluar\n\n");
        printf("Pilih menu : ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            aproxFungsi();
            break;
        case 2:
            aproxTurunan();
            break;
        case 3:
            aproxIntegral();
            break;
        case 4:
            exit(1);
        default:
            printf("Menu pilihan tidak disediakan\n");
        }
        printf("\nTekan tombol apapun untuk melanjutkan...\n");
        getch();
    }

    getch();
    return 1;
}


void aproxFungsi(){ // Approximasi Fungsi
    // polinomial kolokasi
    printf("Approximasi Fungsi\n");
    printf("=================\n");
    printf("\n");
    printf("Masukkan jumlah titik yang diketahui : ");
    int m;
    scanf("%d", &m);
    printf("\n");
    
    menentukanTitik(m);

    for (int i = 0; i < m; i++){ //testing
        printf("titik x%d dan y%d = %.2f dan %.2f\n", i + 1, i + 1, titik[0][i], titik[1][i]);
    }

    //Cari C value
    menentukanValueC(m);

    //print fungsi polinomial
    printf("fungsi yang didapat:\n");
    printPolinomial(m);

    //hapus fungsi dan titik

    return 0;
}


void aproxTurunan(){ // Approximasi Turunan
    //Ada fungsi?
    return 0;
}


void aproxIntegral(){ // Approximasi Integral
    return 0;
}

void menentukanTitik(int m){
    printf("Masukkan titik yang diketahui : \n");
    for (int i = 0; i < m; i++)
    {
        printf("titik x%d dan y%d (pisahkan dengan spasi)= ", i + 1, i+1);
        scanf("%f", &titik[0][i]);
        scanf("%f", &titik[1][i]);
    }
    return 0;
}

void menentukanValueC(int m){
    for (int i = 0; i < m; i++)
    {
        if(i==0){
            cvalue[i] = titik[1][i];
        }

        else{
            cvalue[i] = (titik[1][i] - HasilPolinomial(titik[0][i], i))/hasilKaliKurung(i, titik[0][i]);
        }
    }
    return 0;
}

float HasilPolinomial(float x, int m){
    float hasil = 0;
    float hasilKurung = 0;
    float variabelX = x;
    for (int i = 0; i < m; i++)
    {
        if(i == 0){
            hasil =+ titik[1][i];
        }
        else{
            hasil =+ hasil + cvalue[i]*hasilKaliKurung(i, variabelX);
        }
    }
    return hasil;
}

float hasilKaliKurung(int m, float x){// hasil kali kurung
    float hasil = 1;
    for (int i = 0; i < m; i++)
    {
        hasil *= x-titik[0][i];
    }
    return hasil;
} 

void printPolinomial(int m){
    for (int i = 0; i < m; i++)
    {
        if(i==0){
            printf("%.2f",cvalue[i]);
        }else{
            
            if(cvalue[i]>=0){
                printf("+%.2f",cvalue[i]);
            }else{
                printf("%.2f",cvalue[i]*(-1));
            }
            
            for (int j = 0; j < i; j++)
            {
                if(titik[0][j]>=0){
                    printf("(x-%.2f)", titik[0][j]);
                }else{
                    printf("(x+%.2f)", titik[0][j]*(-1));
                }
            }
        }
    }
}