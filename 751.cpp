#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        int stack[2000];
        int len = 0;

        for (int i = 0; i < line.length(); i++)
        {
            bool s = (line[i] == '+');
            if (line[i] == '+')
            {
                stack[len - 2] = stack[len - 1] + stack[len - 2];
                len--;
            }
            else if (line[i] == '-')
            {
                stack[len - 2] = stack[len - 2] - stack[len - 1];
                len--;
            }
            else if (line[i] == '*')
            {
                stack[len - 2] = stack[len - 1] * stack[len - 2];
                len--;
            }
            else if (line[i] == ' ')
                continue;
            else
            {
                stack[len] = line[i] - '0';
                len++;
            }
        }
        cout << stack[0] << '\n';
    }
    return 0;
}