// metode biseksi
#include <stdio.h>
#include <math.h>

int main(void)
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

    // input batas bawah dan batas atas
    float a, b, Nnol;
    printf("\ninput batas bawah: ");
    scanf("%f", &a);
    printf("input batas atas: ");
    scanf("%f", &b);
    printf("input nilai iterasi maksimum: ");
    scanf("%f", &Nnol);

        // menghitung fungsi
    float f_a = 0, f_b = 0;
    for (int i = 0; i <= n; i++)
    {
        f_a += x[i] * pow(a, i);
        f_b += x[i] * pow(b, i);
    }

    // menghitung nilai masing-masing
    float m_a = 0, m_b = 0;
    for (int i = 0; i <= n; i++)
    {
        m_a += x[i] * pow(a, i);
        m_b += x[i] * pow(b, i);
    }
}
