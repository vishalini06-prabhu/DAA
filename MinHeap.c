#include <stdio.h>

void heapify(int H[], int n, int i)
{
    int k = i;
    int v = H[k];
    int heap = 0;
    while (!heap && 2 * k <= n)
    {
        int j = 2 * k;
        if (j < n)
        {
            if (H[j] > H[j + 1])
                j = j + 1;
        }
        if (v <= H[j])
            heap = 1;
        else
        {
            H[k] = H[j];
            k = j;
        }
    }
    H[k] = v;
}

void heapSort(int H[], int n)
{
    int i, temp;

    for (i = n / 2; i >= 1; i--)
        heapify(H, n, i);

    for (i = n; i > 1; i--)
    {
        printf("%d ", H[1]);
        H[1] = H[i];
        heapify(H, i - 1, 1);
    }
    printf("%d", H[1]);
}

int main()
{
    int H[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &H[i]);

    printf("Sorted elements:\n");
    heapSort(H, n);

    return 0;
}
