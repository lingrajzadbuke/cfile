#include <stdio.h>
#include <stdlib.h>

void accept_arr(int arr[], int n)
{
    int i;
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int n)
{
    int i;
    printf("Elements are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sentinal_search(int arr[], int n, int key)
{
    int i = 0;

    // Add the sentinel at the extra space at the end
    arr[n] = key;

    // We don't need to check "i < n" because we guarantee
    // the key exists somewhere in the array (at index n if nowhere else).
    while (arr[i] != key)
    {
        i++;
    }

    // If 'i' reached 'n', it means we only found the sentinel we just placed.
    if (i == n)
    {
        return -1; // Match not found in the original elements
    }
    else
    {
        return i; // Match found at index i
    }
}

int main()
{
    int n, key, pos;

    printf("Enter the no of elements you want: ");
    scanf("%d", &n);

    // FIX: Allocate space for n + 1 elements to safely hold the sentinel
    int arr[n];
    accept_arr(arr, n); // Only accept 'n' elements
    display(arr, n);    // Only display 'n' elements

    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    pos = sentinal_search(arr, n, key);

    if (pos == -1)
    {
        printf("%d is not present\n", key);
    }
    else
    {
        printf("%d is present at index %d\n", key, pos);
    }

    return 0;
}