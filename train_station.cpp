#include <iostream>
using namespace std;

int Partition(float arr[], int first, int last)
{
	float Pivot = arr[first];

	int count = 0;
	for(int i = first + 1; i <= last; i++) 
    {
		if(arr[i] <= Pivot)
			count++;
	}

	int PivotIndex = first + count;
	swap(arr[PivotIndex], arr[first]);

	int i = first;
    int j = last;

	while(i < PivotIndex  &&  j > PivotIndex) 
    {
		while(arr[i] <= Pivot) 
			i++;
		while(arr[j] > Pivot) 
			j--;
		if(i < PivotIndex  &&  j > PivotIndex)
			swap(arr[i++], arr[j--]);
	}

	return PivotIndex;
}

void QuickSort(float arr[], int first, int last)
{
	if(first >= last)
		return;

	int P = Partition(arr, first, last);

	QuickSort(arr, first, P-1);
	QuickSort(arr, P+1, last);
}



int Station(float enter[], float exit[], int n)
{
    QuickSort(enter, 0, n-1);
    QuickSort(exit, 0, n-1);
 
    int station=1;
    int result=1;
    int i=1;
    int j=0;
 
    while(i<n  &&  j<n) 
    {
        if(enter[i] <= exit[j]) 
        {
            station++;
            i++;
        }
        else if(enter[i] > exit[j]) 
        {
            station--;
            j++;
        }
 
        if(station > result)
            result=station;
    }
 
    return result;
}
 
int main()
{
    int n;
    cin >> n;
    cin.ignore();

    float enter[n];

    for(int i=0; i<n; i++)
    {	
		cin >> enter[i];
        cin.ignore();
    }
    
    float exit[n];

    for(int j=0; j<n; j++)
    {	
		cin >> exit[j];
        cin.ignore();
    }

    cout << Station(enter, exit, n);

    return 0;
}


    
