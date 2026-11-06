#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    float *arr = (float *)malloc(n * sizeof(float));
    if (arr == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }
    printf("Nhap %d phan tu so thuc:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu [%d]: ", i);
        scanf("%f", arr + i);
    }
    printf("\nMang vua tao:\n");
    for (int i = 0; i < n; i++) {
        printf("%g\t", *(arr + i));
    }
    printf("\n");
    free(arr);
    return 0;
}
