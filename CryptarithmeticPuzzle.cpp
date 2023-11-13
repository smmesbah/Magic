#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid(vector<int> &assignment)
{
    return (assignment[0] != 0);
}

bool constraint_satisfied(vector<int> &assignment)
{
    int T = assignment[0];
    int W = assignment[1];
    int O = assignment[2];
    int F = assignment[3];
    int U = assignment[4];
    int R = assignment[5];

    int two1 = T * 100 + W * 10 + O;
    int two2 = T * 100 + W * 10 + O;
    int four = F * 1000 + O * 100 + U * 10 + R;

    return (two1 + two2 == four);
}

bool backtrack(vector<int> &assignment, vector<bool> &used, int index)
{
    if (index == 6)
    {
        if (constraint_satisfied(assignment))
        {
            return true;
        }
        return false;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (!used[i])
        {
            assignment[index] = i;
            used[i] = true;

            if (is_valid(assignment))
            {
                if (backtrack(assignment, used, index + 1))
                {
                    return true;
                }
            }

            assignment[index] = -1;
            used[i] = false;
        }
    }

    return false;
}

int main()
{
    vector<int> assignment(6, -1);
    vector<bool> used(10, false);

    if (backtrack(assignment, used, 0))
    {
        cout << "Solution found:" << endl;
        cout << "   T  W  O" << endl;
        cout << " + T  W  O" << endl;
        cout << "---------------" << endl;
        cout << "F  O  U  R" << endl;

        cout << "Values:" << endl;
        cout << "T = " << assignment[0] << endl;
        cout << "W = " << assignment[1] << endl;
        cout << "O = " << assignment[2] << endl;
        cout << "F = " << assignment[3] << endl;
        cout << "U = " << assignment[4] << endl;
        cout << "R = " << assignment[5] << endl;
    }
    else
    {
        cout << "No valid solution found." << endl;
    }

    return 0;
}
