#include "stack.h"
#include "llistint.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

bool eval( int & answer, const string & line );
bool getInt( int & answer, const string & token );
int mathop(const int left, const int right, const int op);
int lshiftfunc(const string & line);
int rshiftfunc(const string & line);

const int oparen = -1, lshift = -2, rshift = -3, plussign = -4, times = -5;

int main(int argc, char* argv[])
{
    ifstream infile(argv[1]);

    if (!infile)
    {
        cout << "Error: Input File Not Found" << endl;
        exit (1);
    }
    else
    {
        for(string line; getline(infile, line) && line.size();)
        {
            int ans = 0;
            if(eval(ans, line))
            {
                cout << "Answer: " << ans << endl;
            }

            else
            {
                cout << "Malformed" << endl;
            }

        }


    }
}


bool eval( int & answer, const string & line )
{
    bool shifter = false;
    int openparen = 0, leftshift = 0, rightshift = 0, ast = 0, plu = 0;
    StackInt st;
    int test1 = 0;
    string token;
    istringstream sin( line );
    sin >> token;
    for(int i = 0; i < line.length(); i++)
    {
        if(shifter == true)
        {
            if(line[i] != '(' && !(line[i] >= '0' && line[i] <= '9'))
            {
                //cout << "Law Breaker: " << line[i] << endl;
                return false;
            }
            //shifter = false;
        }
        if(line[i] == '(')
        {
            openparen++;
            st.push(oparen);
        }
        else if(line[i] == '>' || line[i] == '<')
        {
            if(line[i] == '>')
            {
                rightshift++;
            }
            else if (line[i] == '<')
            {
                leftshift++;
            }
            while(line[i+1] == '>' || line[i+1] == '<')
            {
                if(line[i+1] == '>')
                {
                    rightshift++;
                }
                else if (line[i+1] == '<')
                {
                    leftshift++;
                }
                i++;
            }
            shifter = true;
            continue;

        }

        else if(line[i] == '*')
        {


            st.push(times);
        }

        else if(line[i] == '+')
        {

            st.push(plussign);
        }

        else if(line[i] >= '0' && line[i] <= '9')
        {
            test1 = (line[i] - 48);
            while(line[i+1] >= '0' && line[i+1] <= '9')
            {
                //cout << "Test 1: " << test1 << " Line i: " << line[i] << " i +1: " << line[i+1] << endl;
                test1 = (test1*10) + (line[i+1]-48);
                i++;
            }
            st.push(test1);
            if(shifter == true)
            {
                int power = 0;
                test1 = st.top();
                st.pop();
                if(rightshift < leftshift)
                {
                    power = leftshift - rightshift;
                    test1 = test1 * pow(2,power);
                    //cout << test1 << endl;
                   //st.push(test1);
                }
                else if (leftshift < rightshift)
                {
                    power = rightshift - leftshift;
                    test1 = test1 / pow(2, power);
                }

                st.push(test1);
                //cout << "TOP: " << st.top() << endl;
                leftshift = rightshift = 0;
                shifter = false;
            }

        }
        else if(line[i] == ')')
        {
            int lhs = 0, rhs = 0, oper = 0, temp = 0, val = -1;
                rhs = st.top();
                st.pop();
                //cout << "TEST SPOT : " << st.top() << endl;
                oper = st.top();
                if( oper > 0)
                {
                    return false;
                }
                else
                {
                    st.pop();
                    lhs = st.top();
                    st.pop();
                    val = mathop(lhs, rhs, oper);
                    if(val < 0)
                    {
                        return false;
                    }


                    if(st.top() == -1)
                    {
                        openparen--;
                        st.pop();
                    }
                    st.push(val);
                }
        }

    }

    if(openparen == 0)
    {
        answer = st.top();
        st.pop();
        if(st.empty())
        {
            return true;
        }

    }
    else
    return false;
    /*cout << openparen << ", " << leftshift << ", " << rightshift << endl;
    cout << "Numbers: " << st.top() << endl; */
}  // evaluate


bool getInt( int & answer, const string & token ){
    istringstream sin( token );
    int temp;
    char junk;
    if( !(sin >>temp) )  return false;
    if( sin >>junk )  return false;
    answer = temp;
    return true;
}

int mathop(const int left, const int right, const int op)
{
    if(op == -4)
    {
        return left + right;
    }

    else if(op == -5)
    {
        return (left * right);
    }

    else return(-1);

}

