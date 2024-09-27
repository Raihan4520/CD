#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 9, 4, 7, 3, 5, 2, 8, 3, 10};
    float sum = 0, n = 0;
    for (int i : arr)
    {
        sum += i;
        n++;
    }
    cout << "Average value of the elements of this array is: " << sum / n << endl;

    return 0;
}
