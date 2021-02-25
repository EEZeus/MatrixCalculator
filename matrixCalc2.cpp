#include <iostream>
#include <iomanip>
using namespace std;
double A[100][100]{};
size_t aSizeL =0;
size_t aSizeC = 0;
double B[100][100]{};
size_t bSizeL = 0;
size_t bSizeC = 0;
double temp[100][100];
double bInverse[100][100];

//------------------------------------
void menu();
void getA();
void getB();
void BtoA();
void AtoB();
void AmultB();
void AplusB();
void AminusB();
void atimesA();
void printA();
void printB();
double determinant(double a[100][100], size_t n);
void inverse(size_t n);
//------------------------------------
int main()
{
    cout << fixed << setprecision(4);
    int choice;
    do {
     menu();
     cin >> choice;
     cout << "\n-------------------------------------\n";
     switch (choice) {
     case 1:
         getA();
         break;
     case 2:
         getB();
         break;
     case 3:
         AtoB();
         break;
     case 4:
         BtoA();
         break;
     case 5:
         AmultB();
         break;
     case 6:
         AplusB();
         break;
     case 7:
         inverse(bSizeL);
         for (size_t l = 0; l < bSizeL; l++) {
             for (size_t c = 0; c < bSizeC; c++) {
                 B[l][c] = bInverse[l][c];
             }
         }
         if (bSizeL==bSizeC) {
                 AmultB();
         }
         break;
     case 8:
         AminusB();
         break;
     case 9:
         atimesA();
         break;
     case 10:
         if (aSizeL==aSizeC) {
             cout << determinant(A, aSizeL);
             cout << "\n-------------------------------------\n";
         }
         else {
             cout << "Matrix does not have a determinant !!\n";
             cout << "\n-------------------------------------\n";
         }
         break;
     case 11:
         if (bSizeL == bSizeC) {
             cout << determinant(B, bSizeL);
             cout << "\n-------------------------------------\n";
         }
         else {
             cout << "Matrix does not have a determinant !!\n";
             cout << "\n-------------------------------------\n";
         }
         break;
     case 12:
         printA();
         break;
     case 13:
         printB();
         break;
     case 14:
         cout << "Best Of Luck =) ...\n";
         break;
     }
    
    } while (choice != 14);
    return 0;
}
void menu() {
    cout << "1 : get A \n";
    cout << "2 : get B \n";
    cout << "3 : transform A to B \n";
    cout << "4 : transform B to A\n";
    cout << "5 : compute A = A*B\n";
    cout << "6 : compute A = A+B\n";
    cout << "7 : compute A = A/B\n";
    cout << "8 : compute A = A-B\n";
    cout << "9 : compute A = a*A\n";
    cout << "10 : compute determinant of A\n";
    cout << "11 : compute determinant of B\n";
    cout << "12 : print A\n";
    cout << "13 : print B\n";
    cout << "14 : Quit\n";

}
void getA() {

    if (aSizeL == 0 && aSizeC==0) {
        cout << "Please Enter The Size Of lines then Columns of Matrix A seperated by space :\n";
        cin >> aSizeL >> aSizeC;
        cout << "Please Enter The Members Of Matrix A by Following Line&Column order:\n";
        for (size_t l = 0; l < aSizeL; l++) {
            for (size_t c = 0; c < aSizeC; c++) {
                cin >> A[l][c];
            }
        }
    }
    else {
        for (size_t l = 0; l < aSizeL;l++) {
            for (size_t c = 0; l < aSizeC; c++) {
                A[l][c] = 0;
            }
        }
        aSizeL = 0;
        aSizeC = 0;

        cout << "Please Enter The Size Of lines then Columns of Matrix A seperated by space :\n";
        cin >> aSizeL >> aSizeC;
        cout << "Please Enter The Members Of Matrix A by Following Line&Column order:\n";
        for (size_t l = 0; l < aSizeL; l++) {
            for (size_t c = 0; c < aSizeC; c++) {
                cin >> A[l][c];
            }
        }
    }
    cout << "\n-------------------------------------\n";
}
void getB() {
    if (bSizeL == 0 && bSizeC == 0) {
        cout << "Please Enter The Size Of lines then Columns of Matrix B seperated by space :\n";
        cin >> bSizeL >> bSizeC;
        cout << "Please Enter The Members Of Matrix B by Following Line&Column order:\n";
        for (size_t l = 0; l < bSizeL; l++) {
            for (size_t c = 0; c < bSizeC; c++) {
                cin >> B[l][c];
            }
        }
    }
    else {
        for (size_t l = 0; l < bSizeL; l++) {
            for (size_t c = 0; l < bSizeC; c++) {
                B[l][c] = 0;
            }
        }
        bSizeL = 0;
        bSizeC = 0;

        cout << "Please Enter The Size Of lines then Columns of Matrix A seperated by space :\n";
        cin >> bSizeL >> bSizeC;
        cout << "Please Enter The Members Of Matrix A by Following Line&Column order:\n";
        for (size_t l = 0; l < bSizeL; l++) {
            for (size_t c = 0; c < bSizeC; c++) {
                cin >> B[l][c];
            }
        }
}
    cout << "\n-------------------------------------\n";
}
void BtoA() {
    
    if ((aSizeL == bSizeL && aSizeC == bSizeC) or (aSizeL == 0 && aSizeC == 0)) {
        for (size_t l = 0; l < bSizeL; l++) {
            for (size_t c = 0; c < bSizeC; c++) {
                A[l][c] = B[l][c];
            }
        }
        aSizeL = bSizeL;
        aSizeC = bSizeC;
    }
    else {
        for (size_t l = 0; l < aSizeL; l++) {
            for (size_t c = 0; l < aSizeC; c++) {
                A[l][c] = 0;
            }
        }
        aSizeL = bSizeL;
        aSizeC = bSizeC;

        for (size_t l = 0; l < bSizeL; l++) {
            for (size_t c = 0; c < bSizeC; c++) {
                A[l][c] = B[l][c];
            }
        }
    }
    cout << "\n-------------------------------------\n";
}
void AtoB() {
    if ((aSizeL == bSizeL && aSizeC == bSizeC)or(bSizeL == 0 && bSizeC ==0)) {
        for (size_t l = 0; l < aSizeL; l++) {
            for (size_t c = 0; c < aSizeC; c++) {
                B[l][c] = A[l][c];
            }
        }
        bSizeL = aSizeL;
        bSizeC = aSizeC;
    }
    else {
        for (size_t l = 0; l < bSizeL; l++) {
            for (size_t c = 0; l < bSizeC; c++) {
                B[l][c] = 0;
            }
        }
        bSizeL = aSizeL;
        bSizeC = aSizeC;

        for (size_t l = 0; l < aSizeL; l++) {
            for (size_t c = 0; c < aSizeC; c++) {
                B[l][c] = A[l][c];
            }
        }
    }
    cout << "\n-------------------------------------\n";
}
void AmultB() {
    double temp2[100][100]{};


    if (aSizeC == bSizeL) {
        for (size_t l = 0; l < aSizeL; l++) {
            for (size_t c = 0; c < bSizeC; c++) {
                for (size_t k = 0; k < aSizeC; k++) {
                    temp2[l][c] += A[l][k] * B[k][c];
                }
            }
        }
        for (size_t l = 0; l < aSizeL; l++) {
            for (size_t c = 0; c < aSizeC; c++) {
                A[l][c] = temp2[l][c];
                aSizeC = bSizeC;
            }
        }
    }
    else {
        cout << "Sorry!Matrixes are not multypliable,Try a Valid Matrix:\n";
    }
    cout << "\n-------------------------------------\n";
}
void AplusB() {
    if (aSizeL == bSizeL && aSizeC == bSizeC) {
        for (size_t l = 0; l < aSizeL;l++) {
            for (size_t c = 0; c < aSizeC; c++) {
                A[l][c] = A[l][c] + B[l][c];
            }
        }
    }
    else {
        cout << "Sorry! The size of Matrixes are not same , Try a valid matrix :\n";
    }
    cout << "\n-------------------------------------\n";
}
void AminusB() {
    if (aSizeL == bSizeL && aSizeC == bSizeC) {
        for (size_t l = 0; l < aSizeL; l++) {
            for (size_t c = 0; c < aSizeC; c++) {
                A[l][c] = A[l][c] - B[l][c];
            }
        }
    }
    else {
        cout << "Sorry! The size of Matrixes are not same , Try a valid matrix :\n";
    }
    cout << "\n-------------------------------------\n";
}
void atimesA() {
    double a;
    cout << "Please Enter A Numbet To Multiply in Matrix :\n";
    cin >> a;
    for (size_t l = 0; l < aSizeL; l++) {
        for (size_t c = 0; c < aSizeC; c++) {
            A[l][c] = a*A[l][c];
        }
    }
    cout << "\n-------------------------------------\n";
}
void printA() {
    for (size_t l = 0; l < aSizeL; l++) {
        cout << endl;
        for (size_t c = 0; c < aSizeC; c++) {
            cout << A[l][c]<<" ";
        }
    }
    cout << "\n-------------------------------------\n";
}
void printB() {
    for (size_t l = 0; l < bSizeL; l++) {
        cout << endl;
        for (size_t c = 0; c < bSizeC; c++) {
            cout << B[l][c] << " ";
        }
    }
    cout << "\n-------------------------------------\n";
}
double determinant(double a[100][100], size_t n) {
    //1 2 3 1
    //4 5 6 1
    //7 8 9 1
    //1 1 1 1       
    double det = 0;size_t p,h, k, i, j; double temp[100][100];
        if (n == 1) {
            return a[0][0];
        }
        else if (n == 2) {
            det = (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
            return det;
        }
        else {
            for (p = 0; p < n; p++) {
                h = 0;
                k = 0;
                for (i = 1; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        if (j == p) {
                            continue;
                        }
                        temp[h][k] = a[i][j];
                         k++;
                        if (k == n - 1) {
                            h++;
                            k = 0;
                        }
                       
                    }
                }
                det += a[0][p] * pow(-1, p) * determinant(temp, n - 1);
            }
            return det;
        }
    cout << "\n-------------------------------------\n";
}
void inverse(size_t n) {
    int i, j, k; double d;
    //[1 2 3|1 0 0]
    //[4 5 6|0 1 0]
    //[7 8 9|0 0 1]

    if (determinant(B, bSizeL) != 0.0000) {
        // Initializing Right-hand side to identity matrix
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < 2 * n; ++j)
            {
                if (j == (i + n))
                {
                    B[i][j] = 1;
                }
            }
        }

        // Partial pivoting
        for (i = n; i > 1; --i)
        {
            if (B[i - 1][1] < B[i][1])
            {
                for (j = 0; j < 2 * n; ++j)
                {
                    d = B[i][j];
                    B[i][j] = B[i - 1][j];
                    B[i - 1][j] = d;
                }
            }
        }
        cout << endl;

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < 2 * n; ++j)
            {
                if (j != i)
                {
                    d = B[j][i] / B[i][i];
                    for (k = 0; k < n * 2; ++k)
                    {
                        B[j][k] -= B[i][k] * d;
                    }
                }
            }
        }
        cout << endl;

        // Reducing To Unit Matrix
        for (i = 0; i < n; ++i)
        {
            d = B[i][i];
            for (j = 0; j < 2 * n; ++j)
            {
                B[i][j] = B[i][j] / d;
            }

        }
        int z = 0, y = 0;
        for (i = 0; i < n; ++i)
        {
            for (j = n; j < 2 * n; ++j)
            {
                bInverse[z][y] = B[i][j];
                y++;
                if (y == n) {
                    z++;
                    y = 0;
                }

            }
        }
    }
    else {
        cout << "Matrix is not invertable!!";
    }
}