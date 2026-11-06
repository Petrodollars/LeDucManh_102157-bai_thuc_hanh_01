#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char maSV[20];
    char hoTen[50];
    float diem1;
    float diem2;
    float diem3;
} SinhVien;
int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So luong sinh vien khong hop le!\n");
        return 1;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    SinhVien *ds = (SinhVien *)malloc(n * sizeof(SinhVien));
    if (ds == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        SinhVien *sv = ds + i; 
        printf("\n--- Nhap thong tin sinh vien [%d] ---\n", i + 1);
        printf("Nhap ma sinh vien: ");
        fgets(sv->maSV, sizeof(sv->maSV), stdin);
        size_t len1 = strlen(sv->maSV);
        if (len1 > 0 && sv->maSV[len1 - 1] == '\n') sv->maSV[len1 - 1] = '\0';
        printf("Nhap ho ten: ");
        fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
        size_t len2 = strlen(sv->hoTen);
        if (len2 > 0 && sv->hoTen[len2 - 1] == '\n') sv->hoTen[len2 - 1] = '\0';
        printf("Nhap diem 1: ");
        scanf("%f", &sv->diem1);
        printf("Nhap diem 2: ");
        scanf("%f", &sv->diem2);
        printf("Nhap diem 3: ");
        scanf("%f", &sv->diem3);
        while ((c = getchar()) != '\n' && c != EOF);
    }
    printf("\n================================ DANH SACH SINH VIEN ================================\n");
    printf("%-5s | %-12s | %-25s | %-8s | %-8s | %-8s\n", 
           "STT", "Ma SV", "Ho va Ten", "Diem 1", "Diem 2", "Diem 3");
    printf("-------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        SinhVien *sv = ds + i;
        printf("%-5d | %-12s | %-25s | %-8g | %-8g | %-8g\n",
               i + 1, sv->maSV, sv->hoTen, sv->diem1, sv->diem2, sv->diem3);
    }
    printf("=====================================================================================\n");
    free(ds);
    return 0;
}
