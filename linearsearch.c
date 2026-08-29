#include <stdio.h>
#include <stdlib.h>
void accept(int arr[], int n)
{
    int i;
    printf("Enter the no elements :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display(int arr[], int n)
{
    int i;
    printf("The elements are :");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int linear_search(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, key;
    printf("Enter the no of elements you want :");
    scanf("%d", &n);
    int arr[n];
    accept(arr, n);
    printf("Enter the element you want to search :");
    scanf("%d", &key);
    int result = linear_search(arr, n, key);
    if (result == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at index %d", result);
    }
    return 0;
}
