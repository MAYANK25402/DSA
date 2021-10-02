#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Logic
    int cnt = 0;
    cnt += 2;

    for (int i = 0; i < n - 1; i++)
    {
        cnt += 2;
        bool check = false;
        for (int j = 0; j < n - i - 1; j++)
        {
             
            if (arr[j] > arr[j + 1])
            {
                int swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;

                cnt += 2;
                check = true;
            }
            if (check)
                cnt += 2;
            // else
            //     break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nCount: " << cnt;
    return 0;
}