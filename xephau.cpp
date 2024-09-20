#include<bits/stdc++.h>
using namespace std;
int n;

//m?ng ðánh d?u c?t, ðý?ng chéo ph? và ðý?ng chéo chính
bool isInCol[13], isInDiag1[26], isInDiag2[26];

//g?i 2 t?p riêng chi hàng và c?t
//t?p X có th? b? qua do các quân H?u ðý?c sinh l?n lý?t theo t?ng hàng
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

//Hàm ð? quy
void genQueensSet(int curRow)
{
    for (int curCol = 1; curCol <= n; curCol ++)
    {
        //Xác ð?nh ðý?ng chéo ph? và chính hi?n t?i
        int curDiag1 = curRow + curCol;
        int curDiag2 = curRow - curCol + 13;    //+13 ð? tránh ch? s? âm

        //Ki?m tra to? ð? m?i xem có tho? m?n không
        if (isInCol[curCol] == true) continue;
        if (isInDiag1[curDiag1] == true) continue;
        if (isInDiag2[curDiag2] == true) continue;

        //Thêm nó vào t?p h?p hi?n t?i n?u tho? m?n
        curQueensSetX.push_back(curRow);
        curQueensSetY.push_back(curCol);
        isInCol[curCol] = true;
        isInDiag1[curDiag1] = true;
        isInDiag2[curDiag2] = true;

        //G?i ð? quy thêm quân ti?p theo ho?c in k?t qu?
        if (curQueensSetX.size() == n) printQueensSet();
        else genQueensSet(curRow + 1);

        //Xoá quân v?a thêm vào kh?i t?p h?p
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
