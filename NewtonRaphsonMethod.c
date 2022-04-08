#include <stdio.h>
#include <math.h>

float hasilFungsi(float a, float x[]);
float hasilTurunanFungsi(float a, float x[]);

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
    float a;                       // a: approximasi
    unsigned short i = 1, iterasi; // iterasi: angka maksimum iterasi
    float epsilon;                 // epsilon: batas error(angka toleransi)

    printf("Apporximasi pertama: ");
    scanf("%f", &a);

    printf("angka iterasi: ");
    scanf("%hu", &iterasi);

    printf("angka toleransi/epsilon (batas sampai 6 tempat desimal!): ");
    scanf("%f", &epsilon);

    while (i <= iterasi)
    {
        a = a - hasilFungsi(a, x) / hasilTurunanFungsi(a, x);
        i++;
    }

    printf("akar aproximasi: %f \n", x);
    return 0;
}

float hasilFungsi(float a, float x[])
{
    float hasil_fungsi = 0;
    for (int i = 0; i <= sizeof(x); i++)
    {
        hasil_fungsi += x[i] * pow(a, i);
    }
    return hasil_fungsi;
}

float hasilTurunanFungsi(float a, float x[])
{
    float hasil_turunan = 0;
    for (int i = 0; i <= sizeof(x); i++)
    {
        hasil_turunan += x[i] * i * pow(a, i - 1);
    }
    return hasil_turunan;
}
