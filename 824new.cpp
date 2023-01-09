#include <iostream>
using namespace std;
// try heapsort?

class AnsList
{
public:
    int c;
    int count = 0;
    int length = 0;
    AnsList(int x)
    {
        if (x >= 0)
            c = x;
        else
            c = -x;
    }
    int *counting = new int[1];
    int *countingneg = new int[1];
    int lengthneg = 0;
    void add(int x)
    {
        if (x >= 0)
        {
            if (length <= x)
            {
                if (x == 0)
                {
                    length += 1;
                    counting[0] = 1;
                }
                else
                {
                    int *temp = new int[x+c+1];

                    for (int i = 0; i < length; i++) temp[i] += counting[i];
                    
                    for (int i = length; i < x+c+1; i++) temp[i] = 0;
        
                    temp[x] = 1;
                    length = x+c+1;
                    counting = temp;
                }
            }
            else counting[x] += 1;

            if (x - c >= 0 && length > x - c)
            {
                if (c == 0) count += counting[x - c] - 1;
                else
                {
                    count += counting[x - c];
                    if (length > x + c) count += counting[x + c];
                }
            }
            if (count < 0) count = 0;
        }
        else
        {
            x*=-1;
            if (lengthneg <= x)
            {
                int *temp = new int[x+c+1];
                for (int i = 0; i < lengthneg; i++) temp[i] += countingneg[i];
                
                for (int i = lengthneg; i < x+c+1; i++) temp[i] = 0;
                
                temp[x] = 1;
                lengthneg = x+c+1;
                countingneg = temp;
            }
            else countingneg[x] += 1;
            
            if (x - c > 0 && lengthneg > x - c)
            {
                if (c == 0) count += countingneg[x - c] - 1;
                else
                {
                    count += countingneg[x - c];
                    if (lengthneg > x + c) count += countingneg[x + c];
                }
            }
            else if(x-c==0) count+=counting[0];
            if (count < 0) count = 0;
        }
    }
}

;

int main()
{
    int c, n, x, count = 0;
    while (cin >> n)
    {
        cin >> c;
        AnsList *ans = new AnsList(c);
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            // cout<<x;
            ans->add(x);
        }
        count += ans->count;
        cout << count << "\n";
    }
    return 0;
}