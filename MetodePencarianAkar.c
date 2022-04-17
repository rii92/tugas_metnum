#include <stdio.h>
#include <math.h>

float hasilFungsi(float pNol, float x[]);
float hasilTurunanFungsi(float pNol, float x[]);
float fungsiToX(float pNol, float x[]);
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
float hasilFungsi(float pNol, float x[])
{
    float hasil_fungsi = 0;
    for (int i = 0; i <= sizeof(x); i++)
    {
        hasil_fungsi += x[i] * pow(pNol, i);
    }
    return hasil_fungsi;
}

// menghitung turunan fungsi
float hasilTurunanFungsi(float pNol, float x[])
{
    float hasil_turunan = 0;
    for (int i = 0; i <= sizeof(x); i++)
    {
        hasil_turunan += x[i] * i * pow(pNol, i - 1);
    }
    return hasil_turunan;
}

// f(x)=0 menjadi x=F(x)
float fungsiToX(float pNol, float x[])
{
    float pangkat;
    float hasilPerubahanFungsi = 0;
    for (int i = 1; i <= sizeof(x); i++)
    {

        if (x[i] == !0)
        {
            for (int j = 0; j <= sizeof(x); j++)
            {
                hasilPerubahanFungsi += x[j] * pow(pNol, j);
            }
            hasilPerubahanFungsi -= x[i] * pow(pNol, i);
            hasilPerubahanFungsi = hasilPerubahanFungsi / x[i];
            hasilPerubahanFungsi = pow(hasilPerubahanFungsi, 1 / i);
            return hasilPerubahanFungsi;
        }
    }
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
        p = pNol - (hasilFungsi(pNol, x) / hasilTurunanFungsi(pNol, x));
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
        fa = hasilFungsi(a, x);
        fb = hasilFungsi(b, x);
        fp = hasilFungsi(p, x);
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

    for (int i = 1; i <= iterasi; i++)
    {
        p = hasilFungsi(pNol, x);
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
    float deltaXN[iterasi];
    float deltakuadrat;
    pNol = 0;

    for (int i = 1; i <= iterasi; i++)
    {
        p = fungsiToX(pNol, x);
        printf("\niterasi ke-%d: %.6f", i, p);
        deltaXN[i] = fabs(p - pNol);
        if (deltaXN[i] < epsilon)
        {
            // float deltaX = deltaXN[i - 1];
            // float deltakuadratX = deltaXN[i - 1] - deltaXN[i - 2];
            // p = p - pow(deltaX, 2) / (deltakuadratX);
            printf("\n\nApproximasi x: %.6f", p);
            return 0;
        }
        pNol = p;
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
        p = (a * hasilFungsi(b, x) - b * hasilFungsi(a, x)) / (hasilFungsi(b, x) - hasilFungsi(a, x));
        printf("\niterasi ke-%d: %.6f", i, p);
        if (fabs(p - a) < epsilon)
        {
            printf("\n\nApproximasi: %.6f", p);
            return 0;
        }
        if (hasilFungsi(a, x) * hasilFungsi(p, x) < 0)
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