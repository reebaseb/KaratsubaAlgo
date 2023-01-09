#include <string>
#include <iostream>
using namespace std;
int multiplication(int X, int Y)
{
    string x = to_string(X);
    string y = to_string(Y);
    int result = 0;

    // Looping over y
    for (int i = 0; i < y.length(); i++)
    {
        int carry = 0;         // intermediate carry
        string inter_res = ""; // intermediate result

        // Looping over x.
        for (int j = x.length() - 1; j >= 0; j--)
        {
            // intermediate multiplication of each digit and addition of carry.
            int num = (y[i] - '0') * (x[j] - '0') + carry;
            // if intermediate multiplication is of two digits and j>0
            //   then second digit is appended to intermediate result
            //and first digit is stored as carry
            if (num > 9 && j > 0)
            {
                inter_res = to_string(num % 10) + inter_res;
                carry = num / 10;
            }
            // else the digit is append to intermediate result
            //And assign carry as zero
            else
            {
                inter_res = to_string(num) + inter_res;
                carry = 0;
            }
        }
        // Adding the intermediate results

        result *= 10;
        result += stoi(inter_res);
    }
    return result;
}
int main()
{
	int a,b;
	cout<<"Enter num1:";
	cin>>a;
	cout<<"Enter num2:";
	cin>>b;
    cout <<"Multiplied Karatsuba result:"<< multiplication(a, b);
}
