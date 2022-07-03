#include <stdio.h>
#include <math.h>

float titik[100][100];
float cvalue[100];
float koef[100];
float xvalue[100];
float valueTurunan[100][100];
//kolom 0: nomor
//kolom 1: x
//kolom 2: y
//kolom 3: y' 2 selisih maju
//kolom 4: y' 2 selisih mundur
//kolom 5: y' 3 selisih maju
//kolom 6: y' 3 selisih mundur
//kolom 7: y' selisih tengah/terpusat
//kolom 8: y' 5 selisih maju
//kolom 9: y' 5 selisih mundur
//kolom 10: y' 5 selisih tengah


void aproxFungsi();
void aproxTurunan();
void aproxIntegral();
void menentukanTitik(int m);
void menentukanValueC(int m);
float HasilPolinomial(float x, int m);
float hasilKaliKurung(int m, float x);
void printPolinomial(int m);
void refresh(int m);
void isvaluepolinomial(int m);
void bentukPower(int m);
void printFungsi(int m);
float hasilFungsi(int m, float x);
float integrasiMidpoint(int m, float a, float b);
float integrasiTrapesium(int m, float a, float b);
float integrasiSimpson(int m, float a, float b);
void valuexyforTurunan(float a, float b, float h, int m, int jumlahtitik);
void duaselisihmaju(int jumlahTitik, float h);
void duaselisihmundur(int jumlahTitik, float h);
void printTurunan(int a, int jumlahtitik);
void selisihtengah(int jumlahTitik, float h);
void tigaselisihmaju(int jumlahTitik, float h);
void tigaselisihmundur(int jumlahTitik, float h);
void limaselisihmaju(int jumlahTitik, float h);
void limaselisihmundur(int jumlahTitik, float h);
void limaselisihtengah(int jumlahTitik, float h);


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
    printf("\nfungsi yang didapat:\n");
    printPolinomial(m);

    //ingin tahu nilai fungsi pada titik yang diberikan?
    isvaluepolinomial(m);
    
    //hapus fungsi dan titik
    refresh(m);

    return 0;
}


void aproxTurunan(){ // Approximasi Turunan
    printf("Approximasi Integral\n");
    printf("===================\n");
    printf("\n");
    printf("Pilih kondisi:\n");
    printf("1. Memiliki fungsi yang bisa langsung bisa diturunkan\n");
    printf("2. hanya memiliki beberapa titik untuk di bentuk fungsi polinomial\n");
    char answer;
    scanf("%s", &answer);
    printf("\n");
    int m;
    if (answer == '2'){
        printf("Masukkan jumlah titik yang diketahui : ");
        scanf("%d", &m);
        printf("\n");
        menentukanTitik(m);
        for (int i = 0; i < m; i++){ //testing
            printf("titik x%d dan y%d = %.2f dan %.2f\n", i + 1, i + 1, titik[0][i], titik[1][i]);
        }
        //Cari C value
        menentukanValueC(m);
        
        //bentuk power polinomial
        bentukPower(m);

        printf("\nfungsi yang didapat:\n");
        printFungsi(m);
    }
    else if (answer == '1'){
        printf("Masukkan jumlah derajat fungsi?\n");
        scanf("%d", &m);
        printf("\n");
        m = m + 1;
        for (int i = 0; i < m; i++)
        {
            printf("Masukkan koefisien x^%d : ", i);
            scanf("%f", &koef[i]);
        }
        printFungsi(m);
    } else {
        printf("Pilihan tidak tersedia\n");
        return 0;
    }

    printf("\nMasukkan rentang nilai antara a dan b (pisah spasi): ");
    float a, b;
    scanf("%f %f", &a, &b);
    printf("\n");
    printf("masukkan jarak step h: ");
    float h;
    scanf("%f", &h);
    printf("\n");
    int jumlahTitik = (b - a) / h;
    valuexyforTurunan(a, b, h, m, jumlahTitik);
    int ch;
    while (1)
    {
    printf("\nPilih Metode turunan:\n");
    printf("1. 2 selisih maju\n");
    printf("2. 2 selisih mundur\n");
    printf("3. 3 selisih maju\n");
    printf("4. 3 selisih mundur\n");
    printf("5. selisih tengah/terpusat\n");
    printf("6. 5 selisih maju\n");
    printf("7. 5 selisih mundur\n");
    printf("8. 5 selisih terpusat\n");
    printf("9. exit\n");
    printf("Pilih menu : ");
    scanf("%d", &ch);
        printf("\n");
        printf("\n");
        switch (ch)
        {
        case 1:
            duaselisihmaju(jumlahTitik, h);
            printf("hasil dua selisih maju: \n");
            printTurunan(3, jumlahTitik);
            break;
        case 2:
            duaselisihmundur(jumlahTitik, h);
            printf("hasil dua selisih mundur: \n");
            printTurunan(4, jumlahTitik);
            break;
        case 3:
            tigaselisihmaju(jumlahTitik, h);
            printf("hasil tiga selisih maju: \n");
            printTurunan(5, jumlahTitik);
            break;
        case 4:
            tigaselisihmundur(jumlahTitik, h);
            printf("hasil tiga selisih mundur: \n");
            printTurunan(6, jumlahTitik);
            break;
        case 5:
            selisihtengah(jumlahTitik, h);
            printf("hasil selisih tengah/terpusat: \n");
            printTurunan(7, jumlahTitik);
            break;
        case 6:
            limaselisihmaju(jumlahTitik, h);
            printf("hasil 5 selisih maju: \n");
            printTurunan(8, jumlahTitik);
            break;
        case 7:
            limaselisihmundur(jumlahTitik, h);
            printf("hasil 5 selisih mundur: \n");
            printTurunan(9, jumlahTitik);
            break;
        case 8:
            limaselisihtengah(jumlahTitik, h);
            printf("hasil 5 selisih terpusat/tengah: \n");
            printTurunan(10, jumlahTitik);
            break;;
        case 9:
            return 1;
        default:
            printf("Menu pilihan tidak disediakan\n");
        }
        printf("\nTekan tombol apapun untuk melanjutkan...\n");
        getch(); 
    }
    
    refresh(m);
    refresh(jumlahTitik);
    return 0;   
}


void aproxIntegral(){ // Approximasi Integral
    printf("Approximasi Integral\n");
    printf("===================\n");
    printf("\n");
    printf("Pilih kondisi:\n");
    printf("1. Memiliki fungsi yang bisa diintegrasikan\n");
    printf("2. hanya memiliki beberapa titik untuk di bentuk fungsi polinomial\n");
    char answer;
    scanf("%s", &answer);
    printf("\n");
    int m;
    if (answer == '2'){
        printf("Masukkan jumlah titik yang diketahui : ");
        scanf("%d", &m);
        printf("\n");
        menentukanTitik(m);
        for (int i = 0; i < m; i++){ //testing
            printf("titik x%d dan y%d = %.2f dan %.2f\n", i + 1, i + 1, titik[0][i], titik[1][i]);
        }
        //Cari C value
        menentukanValueC(m);
        
        //bentuk power polinomial
        bentukPower(m);

        printf("\nfungsi yang didapat:\n");
        printFungsi(m);
    }
    else if (answer == '1'){
        printf("Masukkan jumlah derajat fungsi?\n");
        scanf("%d", &m);
        printf("\n");
        m = m + 1;
        for (int i = 0; i < m; i++)
        {
            printf("Masukkan koefisien x^%d : ", i);
            scanf("%f", &koef[i]);
        }
    } else {
        printf("Pilihan tidak tersedia\n");
        return 0;
    }

    printf("\nMetode integrasi:\n");
    printf("masukkan batas bawah : ");
    float a;
    scanf("%f", &a);
    printf("masukkan batas atas : ");
    float b;
    scanf("%f", &b);
    printf("\n");
    printf("Hasil integrasi berdasarkan metode:\n");
    printf("1. Midpoint = %.2f \n", integrasiMidpoint(m, a, b));
    printf("2. Trapesium = %.2f \n", integrasiTrapesium(m, a, b));
    printf("3. Simpson = %.2f \n", integrasiSimpson(m, a, b));
    
    refresh(m);
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
}

float HasilPolinomial(float x, int m){
    float hasil = 0;
    float variabelX = x;
    for (int i = 0; i < m; i++)
    {
        if(i == 0){
            hasil =+ cvalue[i];
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
                printf("%.2f",cvalue[i]);
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
    printf("\n");
}

void refresh(int m){
    for (int i = 0; i < m; i++)
    {
        titik[0][i] = 0;
        titik[1][i] = 0;
        cvalue[i] = 0;
        koef[i] = 0;
        xvalue[i] = 0;
        for (int j = 0; i < 11; i++)
        {
            valueTurunan[j][i];            
        }
    }   
}

void isvaluepolinomial(int m){
    char c = 'y';
    while (1)
    {
        printf("Ingin tahu nilai fungsi pada titik yang diberikan? (y/n) : ");
        scanf("%s", &c);
        printf("\n");
        if (c == 'y')
        {
            printf("Masukkan titik x : ");
            float x;
            scanf("%f", &x);
            printf("\n");
            printf("Nilai fungsi pada titik x%.2f adalah %.2f\n", x, HasilPolinomial(x, m));
        }
        else if (c == 'n')
        {
            break;
        }
        else
        {
            printf("Input tidak valid\n");
        }
    }
}

void bentukPower(int m){
    for (int i = 0; i < m; i++){
        koef[i] = cvalue[i];
        xvalue[i] = titik[0][i];
    }

    for (int j = 0; j < m; j++){
        for (int i = 0; i < m; i++){
            if(i == 0){
                koef[m-i-1] = koef[m-i-1];
            } else{
                koef[m-i-1] = koef[m-i-1] + (0-xvalue[m-i-1])*koef[m-i];
            }
        }
 
        for (int z = 0; z < m; z++){
            if(m-z-1 == 0){
                xvalue[m-z-1] = 0;
            } else{
                xvalue[m-z-1] = xvalue[m-z-2];
            }
        }
    }
}

void printFungsi(int m){
    for (int i = 0; i < m; i++)
    {
        if(i==0){
            printf("%.2f",koef[i]);
        } else{
            if(koef[i]>=0){
                printf("+%.2f",koef[i]);
            } else{
                printf("%.2f",koef[i]);
            }
                printf("x^%d",i);
        }
    }
}

float hasilFungsi(int m, float x){
    float hasil = 0;
    for (int i = 0; i < m; i++)
    {
        hasil += koef[i]*pow(x,i);
    }
    return hasil;
}

float integrasiMidpoint(int m, float a, float b){
    int jumlahtitik = m;
    float range = (b-a)/2;
    float mid = a + range;
    float hasil = 2*range*hasilFungsi(jumlahtitik, mid);
    return hasil;
}

float integrasiTrapesium(int m, float a, float b){
    int jumlahtitik = m;
    float batasBawah = a;
    float batasAtas = b;
    float range = b - a;
    float hasil = range*0.5*(hasilFungsi(jumlahtitik, batasBawah) + hasilFungsi(jumlahtitik, batasAtas));
    return hasil;
}

float integrasiSimpson(int m, float a, float b){
    int jumlahtitik = m;
    float batasBawah = a;
    float batasAtas = b;
    float range = (batasAtas-batasBawah)/2;
    float mid = batasBawah - range;
    float hasil = range*(hasilFungsi(jumlahtitik, batasBawah) + 4*hasilFungsi(jumlahtitik, mid) + hasilFungsi(jumlahtitik, batasAtas))/3;
    return hasil;
}

void valuexyforTurunan(float a, float b, float h, int m, int jumlahtitik){
    float j = a;
    for (int i = 0; i < jumlahtitik; i++)
    {
        valueTurunan[0][i] = i;
        valueTurunan[1][i] = j;
        valueTurunan[2][i] = hasilFungsi(m, j);
        j += h;
    }
}

void duaselisihmundur(int jumlahTitik, float h){
    for (int i = 0; i < jumlahTitik; i++)
    {
        if (i==0)
        {
            valueTurunan[4][i] = 0;
        } else{
            valueTurunan[4][i] = (valueTurunan[2][i] - valueTurunan[2][i-1])/h;
        }
    }
}

void printTurunan(int a, int jumlahtitik){
    printf (" | %4s | %4s | %4s | %4s |\n\n", "i", "xi", "y", "y\'");
    for (int i = 0; i < jumlahtitik; i++)
    {
        printf (" | %3.2f | %3.2f | %3.2f | %3.2f |\n", valueTurunan[0][i], valueTurunan[1][i], valueTurunan[2][i], valueTurunan[a][i]);
    }
}

void duaselisihmaju(int jumlahTitik, float h){
    for (int i = 0; i < jumlahTitik; i++)
    {
        if (i==jumlahTitik-1)
        {
            valueTurunan[3][i] = 0;
        } else{
            valueTurunan[3][i] = (valueTurunan[2][i] - valueTurunan[2][i+1])/h;
        }
    }
}

void selisihtengah(int jumlahTitik, float h){
    for (int i = 0; i < jumlahTitik; i++)
    {
        if (i==jumlahTitik-1 || i==0)
        {
            valueTurunan[7][i] = 0;
        } else{
            valueTurunan[7][i] = (valueTurunan[2][i+1] - valueTurunan[2][i-1])/(2*h);
        }
    }
}

void tigaselisihmaju(int jumlahTitik, float h){
    for (int i = 0; i < jumlahTitik; i++)
    {
        if (i==jumlahTitik-1 || i==jumlahTitik-2)
        {
            valueTurunan[5][i] = 0;
        } else{
            valueTurunan[5][i] = (-3*valueTurunan[2][i] + 4*valueTurunan[2][i+1] - valueTurunan[2][i+2])/(2*h);
        }
    }
}

void tigaselisihmundur(int jumlahTitik, float h){
    for (int i = 0; i < jumlahTitik; i++)
    {
        if (i==0 || i==1)
        {
            valueTurunan[6][i] = 0;
        } else{
            valueTurunan[6][i] = (3*valueTurunan[2][i] - 4*valueTurunan[2][i-1] + valueTurunan[2][i-2])/(2*h);
        }
    }
}

void limaselisihmaju(int jumlahTitik, float h){
    for (int i = 0; i < jumlahTitik; i++)
    {
        if (i>jumlahTitik-5)
        {
            valueTurunan[8][i] = 0;
        } else{
            valueTurunan[8][i] = (-25*valueTurunan[2][i] + 48*valueTurunan[2][i+1] - 36*valueTurunan[2][i+2] + 16*valueTurunan[2][i+3] - 3*valueTurunan[2][i+4])/(12*h);
        }
    }
}

void limaselisihmundur(int jumlahTitik, float h){
    for (int i = 0; i < jumlahTitik; i++)
    {
        if (i < 4)
        {
            valueTurunan[9][i] = 0;
        } else{
            valueTurunan[9][i] = (25*valueTurunan[2][i] - 48*valueTurunan[2][i+1] + 36*valueTurunan[2][i+2] - 16*valueTurunan[2][i+3] + 3*valueTurunan[2][i+4])/(12*h);
        }
    }
}

void limaselisihtengah(int jumlahTitik, float h){
    for (int i = 0; i < jumlahTitik; i++)
    {
        if (i < 2 || i > jumlahTitik-3)
        {
            valueTurunan[10][i] = 0;
        } else{
            valueTurunan[10][i] = (valueTurunan[2][i-2] - 8*valueTurunan[2][i-1] + 8*valueTurunan[2][i+1] - valueTurunan[2][i+2])/(12*h);
        }
    }
}