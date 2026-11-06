#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SinhVien {
    char maSV[20];
    char hoTen[50];
    float diem1;
    float diem2;
    float diem3;
} SinhVien;
typedef struct Node {
    SinhVien data;
    struct Node *next;
} Node;
typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;
void xoaXuongDong(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
void xoaBoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void initList(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
}
Node* createNode(SinhVien sv) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho cap phat!\n");
        return NULL;
    }
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
}
void addLast(LinkedList *list, SinhVien sv) {
    Node *newNode = createNode(sv);
    if (newNode == NULL) return;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}
void nhapSinhVien(SinhVien *sv) {
    printf("Nhap ma sinh vien: ");
    fgets(sv->maSV, sizeof(sv->maSV), stdin);
    xoaXuongDong(sv->maSV);
    printf("Nhap ho ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);
    xoaXuongDong(sv->hoTen);
    printf("Nhap diem 1: ");
    scanf("%f", &sv->diem1);
    printf("Nhap diem 2: ");
    scanf("%f", &sv->diem2);
    printf("Nhap diem 3: ");
    scanf("%f", &sv->diem3);
    xoaBoDem();
}
void inDanhSach(const LinkedList *list) {
    printf("\n================================ DANH SACH SINH VIEN ================================\n");
    printf("%-5s | %-12s | %-25s | %-8s | %-8s | %-8s\n", 
           "STT", "Ma SV", "Ho va Ten", "Diem 1", "Diem 2", "Diem 3");
    printf("-------------------------------------------------------------------------------------\n");
    Node *current = list->head;
    int stt = 1;
    while (current != NULL) {
        printf("%-5d | %-12s | %-25s | %-8g | %-8g | %-8g\n",
               stt++,
               current->data.maSV,
               current->data.hoTen,
               current->data.diem1,
               current->data.diem2,
               current->data.diem3);
        current = current->next;
    }
    printf("=====================================================================================\n");
}
void giaiPhong(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
}
int main() {
    LinkedList list;
    initList(&list);
    int n;
    printf("Nhap so luong sinh vien: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So luong sinh vien khong hop le!\n");
        return 1;
    }
    xoaBoDem();
    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin sinh vien [%d] ---\n", i + 1);
        SinhVien sv;
        nhapSinhVien(&sv);
        addLast(&list, sv);
    }
    inDanhSach(&list);
    giaiPhong(&list);
    return 0;
}
