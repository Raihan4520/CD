#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int arr[] = {9, 4, 7, 5, 2, 8, 3, 10, 1, 6};
    int min = INT_MAX, max = INT_MIN;
    for (int i : arr)
    {
        if (i < min)
            min = i;
        if (i > max)
            max = i;
    }
    cout << "Minimum  value of the elements of this array is: " << min << endl;
    cout << "Maximum value of the elements of this array is: " << max << endl;

    return 0;
}
