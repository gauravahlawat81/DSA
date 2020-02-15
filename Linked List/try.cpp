#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    cout<<"Enter number of rows and column\n";
    cin>>row>>col;
    int arr2d[row][col];
    cout<<"Enter the elements\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr2d[i][j];
        }
    }
    int sum_of_middle_row_elements=0;
    for(int i=0;i<row;i++)
    {
        int sum=0;
        int product=1;
        for(int j=0;j<col;j++)
        {
            sum+=arr2d[i][j];
            product*=arr2d[i][j];
        }
        cout<<"Sum of "<<i+1<<" row is "<<sum<<"\n";
        cout<<"Product of "<<i+1<<" row is "<<product<<"\n";
    }
    for(int j=0;j<col;j++)
    {
        int sum=0;
        int product=1;
        for(int i=0;i<row;i++)
        {
            sum+=arr2d[i][j];
            product*=arr2d[i][j];
        }
        cout<<"Sum of "<<j+1<<" column is "<<sum<<"\n";
        cout<<"Product of "<<j+1<<" column is "<<product<<"\n";
    }
    for(int i=0;i<row;i++)
    {
        int middle=col/2;
        sum_of_middle_row_elements+=arr2d[i][middle];
    }
    int sum_of_middle_column_elements=0;
    for(int j=0;j<col;j++)
    {
        int middle=row/2;
        sum_of_middle_column_elements+=arr2d[middle][j];
    }
    int sum_of_diagonal=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==j)
            {
                sum_of_diagonal+=arr2d[i][j];
            }
        }
    }
    cout<<"Sum of middle row elements "<<sum_of_middle_row_elements<<"\n Sum of middle column elements "<<sum_of_middle_column_elements<<"\n";
    cout<<"Sum of diagonal elements "<<sum_of_diagonal<<"\n";
    // Interchanging first and last row elements
    for(int j=0;j<col;j++)
    {
        swap(arr2d[0][j],arr2d[row-1][j]);
    }
    cout<<"After exchanging the rows\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr2d[i][j]<<" ";
        }
        cout<<"\n";
    }
    //Interchanging first and last column elements
    for(int i=0;i<row;i++)
    {
        swap(arr2d[i][0],arr2d[i][col-1]);
    }
    cout<<"Printing the final matrix and exiting the program\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr2d[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;

}