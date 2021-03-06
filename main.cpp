#include<bits/stdc++.h>
using namespace std;

void minimum1(int a[], int N, int M){
    int min[10];
    long min2=1000000;
    int k=0;
    for(int i=0;i<=(N-M);i++){
            min[k]=a[M-1+i]-a[i];
            k++;
    }
    cout<<endl;
    int u,d,e;
    for(int i=0;i<=(N-M);i++){
        if(a[M-1+i]-a[i]<min2){
            min2=a[M-1+i]-a[i];
            d=M-1+i;
            e=i;
        }
    }
    ofstream outdata;
    outdata.open("OutputFile.txt");
    if( !outdata ) {
      cerr << "Error: file could not be opened" << endl;
      exit(1);
    }
    outdata<<"Here the goodies that are selected for distribution are: "<<endl;
    for (u=e;u<=d;u++){
        if(a[u]==999) outdata<<"MI Band: ";
        if(a[u]==2195) outdata<<"Sandwich Toaster: ";
        if(a[u]==2799) outdata<<"Cult Pass: ";
        if(a[u]==4999) outdata<<"Scale: ";
        if(a[u]==7980) outdata<<"Fitbit Plus: ";
        if(a[u]==9800) outdata<<"Microwave Oven: ";
        if(a[u]==9999) outdata<<"Alexa: ";
        if(a[u]==11101) outdata<<"Digital Camera: ";
        if(a[u]==22349) outdata<<"IPods: ";
        if(a[u]==229900) outdata<<"Macbook Pro: ";
        outdata << a[u] << endl;
    }

    outdata<<"And the difference between the chosen goodie with highest price and the lowest price is "<<min2<<endl;

    outdata.close();

}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n=10;
    int arr[n];
    ifstream file("InputFile.txt");
    int count = 0;
    int x;
    while (count < n && file >> x)
        arr[count++] = x;
    int M=0;
    quickSort(arr, 0, n - 1);
    cout<<"Enter the number of Employees: ";
    cin>>M;
    minimum1(arr,n,M);
    return 0;
}
