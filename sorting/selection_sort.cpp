#include <iostream>

using namespace std;

void Selection_Sort(int arr[], int n)
{
    for (int i = 0; i < n;)
    {
        for (int j = i + 1; j < n;)
        {
            if (arr[j] < arr[i])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else
            {
                j++;
            }
        }
        i++;
    }
}

int main()
{

	  #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	  #endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Selection_Sort(arr, n);
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}
