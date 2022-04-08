#include <stdio.h>
#include <math.h>

float hasilFungsi(float pNol, float x[]);
float hasilTurunanFungsi(float pNol, float x[]);

int main()
{
    // input fungsi
    int n;
    printf("input polinomial berderajat n: ");
    scanf("%d", &n);
    float x[n + 1];

    for (int i = 0; i <= n; i++)
    {
        printf("input x^%d: ", i);
        scanf("%f", &x[i]);
    }

    printf("fungsi y = ");
    for (int i = 0; i <= n; i++)
    {
        printf("%.3fx^%d ", x[i], i);
    }

    // metode newton raphson
    float pNol, p;                 // a: approximasi
    unsigned short i = 1, iterasi; // iterasi: angka maksimum iterasi
    float epsilon;                 // epsilon: batas error(angka toleransi)

    printf("Apporximasi pertama: ");
    scanf("%f", &pNol);

    printf("angka iterasi: ");
    scanf("%hu", &iterasi);

    printf("angka toleransi/epsilon (batas sampai 6 tempat desimal!): ");
    scanf("%f", &epsilon);

    for (int i = 1; i <= iterasi; i++)
    {
        p = pNol - (hasilFungsi(pNol, x) / hasilTurunanFungsi(pNol, x));
        printf("\niterasi ke-%d: %.6f", i, p);
        if (fabs(p - pNol) < epsilon)
        {
            printf("\n\nApproximasi: %.6f", p);
            break;
        }
        pNol = p;
    }
    printf("\nProsedur tidak sukses untuk toleransi %.6f", epsilon);
}

float hasilFungsi(float pNol, float x[])
{
    float hasil_fungsi = 0;
    for (int i = 0; i <= sizeof(x); i++)
    {
        hasil_fungsi += x[i] * pow(pNol, i);
    }
    return hasil_fungsi;
}

float hasilTurunanFungsi(float pNol, float x[])
{
    float hasil_turunan = 0;
    for (int i = 0; i <= sizeof(x); i++)
    {
        hasil_turunan += x[i] * i * pow(pNol, i - 1);
    }
    return hasil_turunan;
}
