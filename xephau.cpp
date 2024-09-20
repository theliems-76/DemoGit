#include<bits/stdc++.h>
using namespace std;
int n;

//m?ng ��nh d?u c?t, ��?ng ch�o ph? v� ��?ng ch�o ch�nh
bool isInCol[13], isInDiag1[26], isInDiag2[26];

//g?i 2 t?p ri�ng chi h�ng v� c?t
//t?p X c� th? b? qua do c�c qu�n H?u ��?c sinh l?n l�?t theo t?ng h�ng
vector <int> curQueensSetX, curQueensSetY;

//In k?t qu? d?ng (X, Y)
void printQueensSet()
{
    for (int i = 0; i < n; i ++)
    {
        cout << "(" << curQueensSetX[i] << ", " << curQueensSetY[i] << ")";
        if (i < n - 1) cout << ", ";
    }
    cout << "\n";
}

//H�m �? quy
void genQueensSet(int curRow)
{
    for (int curCol = 1; curCol <= n; curCol ++)
    {
        //X�c �?nh ��?ng ch�o ph? v� ch�nh hi?n t?i
        int curDiag1 = curRow + curCol;
        int curDiag2 = curRow - curCol + 13;    //+13 �? tr�nh ch? s? �m

        //Ki?m tra to? �? m?i xem c� tho? m?n kh�ng
        if (isInCol[curCol] == true) continue;
        if (isInDiag1[curDiag1] == true) continue;
        if (isInDiag2[curDiag2] == true) continue;

        //Th�m n� v�o t?p h?p hi?n t?i n?u tho? m?n
        curQueensSetX.push_back(curRow);
        curQueensSetY.push_back(curCol);
        isInCol[curCol] = true;
        isInDiag1[curDiag1] = true;
        isInDiag2[curDiag2] = true;

        //G?i �? quy th�m qu�n ti?p theo ho?c in k?t qu?
        if (curQueensSetX.size() == n) printQueensSet();
        else genQueensSet(curRow + 1);

        //Xo� qu�n v?a th�m v�o kh?i t?p h?p
        curQueensSetX.pop_back();
        curQueensSetY.pop_back();
        isInCol[curCol] = false;
        isInDiag1[curDiag1] = false;
        isInDiag2[curDiag2] = false;
    }
}

int main()
{
    cin >> n;

    memset(isInCol, 0, sizeof(isInCol));
    memset(isInDiag1, 0, sizeof(isInDiag1));
    memset(isInDiag2, 0, sizeof(isInDiag2));

    genQueensSet(1);

    return 0;
}
