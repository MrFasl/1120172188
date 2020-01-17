#include <iostream>
#include <vector>
#include <algorithm.> 
//出版数独生成算法，后面会改进分成两个独立算法。
using namespace std;
int main(int argc, char** argv) {
	int shift[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
for (int i = 0; i < 6 ; i++)
{
    if (i)
    {
        next_permutation(shift + 3, shift + 6);
        shift[6] = 2, shift[7] = 5, shift[8] = 8;
    }
    for (int j = 0; j < 6 ; j++)
    {
        if (j) next_permutation(shift + 6, shift + 9);
        char row[10] = "123456789";
        for (int k = 0; k < 40320 ; k++)
        {
            if (k) next_permutation(row + 1, row + 9);
            for (int r = 0; r < 9; r++)
            {
                for (int c = 0; c < 9; c++)
                    cout << row[(c + shift[r]) % 9] << ' ';
                cout << endl;
            }
            cout << endl;
        }
    }
}
	return 0;
}


