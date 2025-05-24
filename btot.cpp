#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ð?nh nghia c?u trúc Sinh viên
typedef struct {
    char maSV[10];
    char hoTen[50];
    int namSinh;
    char queQuan[50];
} SinhVien;

// Ð?nh nghia c?u trúc Node c?a cây BST
typedef struct Node {
    SinhVien data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm t?o node m?i
Node* createNode(SinhVien sv) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = sv;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn sinh viên vào cây BST
Node* insert(Node* root, SinhVien sv) {
    if (root == NULL) {
        return createNode(sv);
    }
    
    // S?p x?p theo nam sinh (tu?i gi?m d?n = nam sinh tang d?n)
    if (sv.namSinh > root->data.namSinh) {
        root->left = insert(root->left, sv);
    }
    else if (sv.namSinh < root->data.namSinh) {
        root->right = insert(root->right, sv);
    }
    else {
        // N?u nam sinh b?ng nhau, so sánh mã SV
        if (strcmp(sv.maSV, root->data.maSV) < 0) {
            root->left = insert(root->left, sv);
        }
        else {
            root->right = insert(root->right, sv);
        }
    }
    return root;
}

// Hàm duy?t Inorder d? xu?t danh sách sinh viên
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("Ma SV: %s, Ho ten: %s, Nam sinh: %d, Que quan: %s\n",
               root->data.maSV, root->data.hoTen, 
               root->data.namSinh, root->data.queQuan);
        inOrder(root->right);
    }
}

// Hàm gi?i phóng b? nh?
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    SinhVien sv;
    int n;

    // Nh?p s? lu?ng sinh viên
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // Xóa ký t? newline

    // Nh?p thông tin sinh viên
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ma SV: ");
        fgets(sv.maSV, sizeof(sv.maSV), stdin);
        sv.maSV[strcspn(sv.maSV, "\n")] = 0; // Xóa ký t? newline

        printf("Ho ten: ");
        fgets(sv.hoTen, sizeof(sv.hoTen), stdin);
        sv.hoTen[strcspn(sv.hoTen, "\n")] = 0;

        printf("Nam sinh: ");
        scanf("%d", &sv.namSinh);
        getchar();

        printf("Que quan: ");
        fgets(sv.queQuan, sizeof(sv.queQuan), stdin);
        sv.queQuan[strcspn(sv.queQuan, "\n")] = 0;

        root = insert(root, sv);
    }

    // Xu?t danh sách sinh viên theo th? t? tang d?n theo tu?i
    printf("\nDanh sach sinh vien (theo tuoi tang dan):\n");
    if (root == NULL) {
        printf("Danh sach rong!\n");
    } else {
        inOrder(root);
    }
    // Gi?i phóng b? nh?
    freeTree(root);
    return 0;
}
