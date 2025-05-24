#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �?nh nghia c?u tr�c Sinh vi�n
typedef struct {
    char maSV[10];
    char hoTen[50];
    int namSinh;
    char queQuan[50];
} SinhVien;

// �?nh nghia c?u tr�c Node c?a c�y BST
typedef struct Node {
    SinhVien data;
    struct Node* left;
    struct Node* right;
} Node;

// H�m t?o node m?i
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

// H�m ch�n sinh vi�n v�o c�y BST
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
        // N?u nam sinh b?ng nhau, so s�nh m� SV
        if (strcmp(sv.maSV, root->data.maSV) < 0) {
            root->left = insert(root->left, sv);
        }
        else {
            root->right = insert(root->right, sv);
        }
    }
    return root;
}

// H�m duy?t Inorder d? xu?t danh s�ch sinh vi�n
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("Ma SV: %s, Ho ten: %s, Nam sinh: %d, Que quan: %s\n",
               root->data.maSV, root->data.hoTen, 
               root->data.namSinh, root->data.queQuan);
        inOrder(root->right);
    }
}

// H�m gi?i ph�ng b? nh?
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

    // Nh?p s? lu?ng sinh vi�n
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // X�a k� t? newline

    // Nh?p th�ng tin sinh vi�n
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Ma SV: ");
        fgets(sv.maSV, sizeof(sv.maSV), stdin);
        sv.maSV[strcspn(sv.maSV, "\n")] = 0; // X�a k� t? newline

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

    // Xu?t danh s�ch sinh vi�n theo th? t? tang d?n theo tu?i
    printf("\nDanh sach sinh vien (theo tuoi tang dan):\n");
    if (root == NULL) {
        printf("Danh sach rong!\n");
    } else {
        inOrder(root);
    }
    // Gi?i ph�ng b? nh?
    freeTree(root);
    return 0;
}
