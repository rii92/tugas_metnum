#include <stdio.h>
#include <math.h>

float hasilFungsi(float pNol, float x[], int n);
float hasilTurunanFungsi(float pNol, float x[], int n);
float fungsiToX(float pNol, float x[], int index, int n);
void metodeNewtonRaphson();
void metodeBiseksi();
void metodeIterasiSederhana();
void metodeIterasiAitken();
void metodeRegularFalsi();

int main()
{
    int ch;
    while (1)
    {
        printf("Berikut metode yang tersedia : \n");
        printf("1. Metode Biseksi\n");
        printf("2. Metode Iterasi Sederhana\n");
        printf("3. Metode Iterasi Aitken\n");
        printf("4. Metode Regular falsi\n");
        printf("5. Metode Newton Raphson\n");
        printf("6. Keluar\n\n");
        printf("Pilih menu : ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            metodeBiseksi();
            break;
        case 2:
            metodeIterasiSederhana();
            break;
        case 3:
            metodeIterasiAitken();
            break;
        case 4:
            metodeRegularFalsi();
            break;
        case 5:
            metodeNewtonRaphson();
            break;
        case 6:
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

// menghitung fungsi
float hasilFungsi(float pNol, float x[], int n)
{
    float hasil_fungsi = 0;
    for (int i = 0; i <= n; i++)
    {
        hasil_fungsi += x[i] * pow(pNol, i);
    }
    return hasil_fungsi;
}

// menghitung turunan fungsi
float hasilTurunanFungsi(float pNol, float x[], int n)
{
    float hasil_turunan = 0;
    for (int i = 0; i <= n; i++)
    {
        hasil_turunan += x[i] * i * pow(pNol, i - 1);
    }
    return hasil_turunan;
}

// f(x)=0 menjadi x=F(x)
float fungsiToX(float pNol, float x[], int index, int n)
{
    float hasil_fungsi = 0;
    for (int i = 0; i <= n; i++)
    {
        hasil_fungsi += x[i] * pow(pNol, i);
    }
    hasil_fungsi = hasil_fungsi - x[index] * pow(pNol, index);
    hasil_fungsi = hasil_fungsi / (x[index] * (-1));
    hasil_fungsi = pow(hasil_fungsi, 1 / index);
    return hasil_fungsi;
}

// metode newton raphson
void metodeNewtonRaphson()
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
        p = pNol - (hasilFungsi(pNol, x, n) / hasilTurunanFungsi(pNol, x, n));
        printf("\niterasi ke-%d: %.6f", i, p);
        if (fabs(p - pNol) < epsilon)
        {
            printf("\n\nApproximasi: %.6f", p);
            return 0;
        }
        pNol = p;
    }
    printf("\nProsedur tidak sukses untuk toleransi %.6f", epsilon);
    return 0;
}

// metode biseksi
void metodeBiseksi()
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

    // metode biseksi
    float a, b, p, fp, fa, fb;     // a: batas bawah, b: batas atas, p: akar, fp: nilai fungsi pada p, fa: nilai fungsi pada a, fb: nilai fungsi pada b
    unsigned short i = 1, iterasi; // iterasi: angka maksimum iterasi
    float epsilon;                 // epsilon: batas error(angka toleransi)

    printf("\nbatas pertama: ");
    scanf("%f", &a);

    printf("batas kedua: ");
    scanf("%f", &b);

    printf("angka iterasi: ");
    scanf("%hu", &iterasi);

    printf("angka toleransi/epsilon (batas sampai 6 tempat desimal!): ");
    scanf("%f", &epsilon);

    for (int i = 1; i <= iterasi; i++)
    {
        p = (a + b) / 2;
        fa = hasilFungsi(a, x, n);
        fb = hasilFungsi(b, x, n);
        fp = hasilFungsi(p, x, n);
        printf("\niterasi ke-%d: %.6f", i, p);
        if (fabs(fp) < epsilon)
        {
            printf("\n\nApproximasi: %.6f", p);
            return 0;
        }
        if (fa * fp > 0)
        {
            a = p;
        }
        else
        {
            b = p;
        }
    }
    printf("\nProsedur tidak sukses untuk toleransi %.6f", epsilon);
    return 0;
}

// metode iterasi sederhana
void metodeIterasiSederhana()
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

    // metode iterasi sederhana
    float pNol, p;                 // a: approximasi
    unsigned short i = 1, iterasi; // iterasi: angka maksimum iterasi
    float epsilon;                 // epsilon: batas error(angka toleransi)

    printf("\nApporximasi pertama: ");
    scanf("%f", &pNol);

    printf("angka iterasi: ");
    scanf("%hu", &iterasi);

    printf("angka toleransi/epsilon (batas sampai 6 tempat desimal!): ");
    scanf("%f", &epsilon);

    for (int j = 1; j <= n; j++)
    {
        printf("Polinomial ke-%d: ", j);
        for (int i = 1; i <= iterasi; i++)
        {
            p = fungsiToX(pNol, x, j, n);
            printf("\niterasi ke-%d: %.6f", i, p);
            if (fabs(p - pNol) < epsilon)
            {
                printf("\n\nApproximasi: %.6f", p);
                return 0;
            }
            pNol = p;
        }
        printf("\n\n");
    }

    printf("\nProsedur tidak sukses untuk toleransi %.6f", epsilon);
    return 0;
}

// metode iterasi aitken
void metodeIterasiAitken()
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

    // metode iterasi aitken
    float pNol, p;                 // a: approximasi
    unsigned short i = 1, iterasi; // iterasi: angka maksimum iterasi
    float epsilon;                 // epsilon: batas error(angka toleransi)

    printf("\nApporximasi pertama: ");
    scanf("%f", &pNol);

    printf("angka iterasi: ");
    scanf("%hu", &iterasi);

    printf("angka toleransi/epsilon (batas sampai 6 tempat desimal!): ");
    scanf("%f", &epsilon);
    float nilaiX[3];
    float delta1;
    float delta2;
    float deltakuadrat;
    float solusi;

    for (int j = 1; j <= n; j++)
    {
        printf("Polinomial ke-%d: ", j);
        for (int i = 1; i <= iterasi; i++)
        {
            p = fungsiToX(pNol, x, j, n);
            printf("\niterasi ke-%d: %.6f", i, p);
            if (i == 1)
            {
                nilaiX[0] = p;
                nilaiX[1] = p;
                nilaiX[2] = p;
            }
            else
            {
                nilaiX[0] = nilaiX[1];
                nilaiX[1] = nilaiX[2];
                nilaiX[2] = p;
            }

            if (fabs(p - pNol) < epsilon)
            {
                delta1 = nilaiX[1] - nilaiX[0];
                delta2 = nilaiX[2] - nilaiX[1];
                deltakuadrat = delta2 - delta1;
                solusi = nilaiX[2] - pow(delta2, 2) / deltakuadrat;
                printf("\nsolusi rill: %.6f", solusi);
                return 0;
            }
            pNol = p;
        }
        printf("\n\n");
    }

    printf("\nProsedur tidak sukses untuk toleransi %.6f", epsilon);
    return 0;
}

void metodeRegularFalsi()
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

    // metode regular falsi
    float a, b, p;                 // a: batas pertama, b: batas kedua
    unsigned short i = 1, iterasi; // iterasi: angka maksimum iterasi
    float epsilon;                 // epsilon: batas error(angka toleransi)

    printf("\nbatas pertama: ");
    scanf("%f", &a);

    printf("batas kedua: ");
    scanf("%f", &b);

    printf("angka iterasi: ");
    scanf("%hu", &iterasi);

    printf("angka toleransi/epsilon (batas sampai 6 tempat desimal!): ");
    scanf("%f", &epsilon);

    for (int i = 1; i <= iterasi; i++)
    {
        p = (a * hasilFungsi(b, x, n) - b * hasilFungsi(a, x, n)) / (hasilFungsi(b, x, n) - hasilFungsi(a, x, n));
        printf("\niterasi ke-%d: %.6f", i, p);
        if (fabs(p - a) < epsilon)
        {
            printf("\n\nApproximasi: %.6f", p);
            return 0;
        }
        if (hasilFungsi(a, x, n) * hasilFungsi(p, x, n) < 0)
        {
            b = p;
        }
        else
        {
            a = p;
        }
    }

    printf("\nProsedur tidak sukses untuk toleransi %.6f", epsilon);
    return 0;
}