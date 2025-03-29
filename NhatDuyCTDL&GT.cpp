#include <stdio.h>

void Nhap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("nhap A[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void Xuat(int a[], int n)
{
    printf("Cac phan tu co trong mang:\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d] = %d \n ", i, a[i]);
    }
}

int TimKiemTuyenTinh(int a[], int n, int x)
{
    int i = 0;
    a[n] = x;
    while (a[i] != x)
    {
        i++;
    }
    if (i == n)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

int TimKiemNhiPhan(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    int midle;
    do
    {
        midle = (left + right) / 2;
        if (x == a[midle])
        {
            return midle;
        }
        else
        {
            if (x < a[midle])
            {
                right = midle - 1;
            }
            else
            {
                left = midle + 1;
            }
        }
    } while (left <= right);
    return -1;
}

void Hoanvi(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ChonTrucTiep(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
            {
                min = j;
                Hoanvi(&a[min], &a[i]);
            }
    }
}

void ChenTrucTiep(int a[], int n)
{
    int pos, i;
    int x;
    for (int i = 1; i < n; i++)
    {
        x = a[i];
        pos = i - 1;
        while ((pos >= 0) && (a[pos] > x))
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

int main()
{
    int n;
    printf("Nhap vao N phan tu: ");
    scanf("%d", &n);
    int a[n];
    Nhap(a, n);
    Xuat(a, n);
    int x;
    printf("Nhap phan tu can tim:");
    scanf("%d", &x);
    int kqTuyenTinh = TimKiemTuyenTinh(a, n, x);
    if (kqTuyenTinh != -1)
    {
        printf("Phan tu %d duoc tim thay tai chi so %d.\n", x, kqTuyenTinh);
    }
    else
    {
        printf("Phan tu %d khong ton tai trong mang.\n", x);
    }

    ChenTrucTiep(a, n);
    printf("mang sau khi chen\n");
    Xuat(a,n);
    ChonTrucTiep(a, n);
    printf("Mang sau khi sap xep:\n");
    Xuat(a, n);
    int kqNhiPhan = TimKiemNhiPhan(a, n, x);
    if (kqNhiPhan != -1)
    {
        printf("Phan tu %d duoc tim thay bang Tim Kiem Nhi Phan tai chi so %d.\n", x, kqNhiPhan);
    }
    else
    {
        printf("Phan tu %d khong ton tai trong mang bang Tim Kiem Nhi Phan.\n", x);
    }
    return 0;
}
