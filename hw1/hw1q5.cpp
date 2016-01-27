#include<fstream>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream infile(argv[1]);
    unsigned num;
    string word, *arr;

    if (!infile)
    {
        cout << "Error: Input File Not Found" << endl;
        system ("pause");
        exit (1);
    }
    else
    infile >> num;
    arr = new string [num];
    for(int i = 0, j = num-1; i < num; i++, j--)
    {
        infile >> word;
        arr[j] = word;

    }

    for(int k = 0; k < num; k++)
    {
        cout << arr[k];
        if(k != num-1)
        {
            cout << "\n";
        }
    }


}
