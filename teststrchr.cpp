#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX1 512 
void vigener_en(char* des, char* str, char* key) {
    char A[27] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0' };
    char key_real[27];
    char* ptr = NULL;
    char mat[26][27], tmp, location;
    int i, j, len, m, len1;
    //生成所有需要用到的表直接保存
    //也可以直接保存一张大表，没做
    //默认key的所有字符在26个字母里面
    len = strlen(key);
    m = 0;
    for (i = 0; i < len; i++) {
        tmp = key[i];
        if (key[i] >= 97 && key[i] <= 122)
            tmp = key[i] - 32;
        if (m == 0) {
            key_real[m] = tmp;
            m++;
        }
        else {
            for (j = 0; j < m; j++) {
                if (tmp == key_real[j]) {
                    break;
                }
            }
            if (j == m) {
                key_real[m] = tmp;
                m++;
            }
            else {
                continue;
            }
        }
    }
    key_real[m] = '\0';
    len1 = strlen(key_real);
    for (i = 0; i < len1; i++) {
        tmp = key_real[i];
        location = (strchr(A, tmp) - A) / sizeof(char);
        m = 0;
        while (m < 26) {
            if (location + m >= 26)
                location = (strchr(A, tmp) - A) / sizeof(char) - 26;
            mat[i][m] = A[location + m];
            m++;
        }
        mat[i][m] = '\0';
    }
    //处理字符串
    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] >= 97 && str[i] <= 122)
            des[i] = str[i] - 32;
        else
            des[i] = str[i];
    }
    m = 0;
    for (i = 0; i < len; i++) {
        tmp = des[i];
        ptr = strchr(A, tmp);
        if (ptr == NULL) {
        	m++;
            continue;
        }
        else {
            location = (ptr - A) / sizeof(char);
            j = (i-m) % 6;//用哪张表
            des[i] = mat[j][location];
        }
    }
    des[i] = '\0';
    return;
}

void vigener_de(char* des, char* str, char* key) {
    char A[27] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0' };
    char key_real[27];
    char* ptr = NULL;
    char mat[26][26], tmp, location;
    int i, j, len, m, len1;
    //生成所有需要用到的表直接保存
    //也可以直接保存一张大表，没做
    //默认key的所有字符在26个字母里面
    len = strlen(key);
    m = 0;
    for (i = 0; i < len; i++) {
        tmp = key[i];
        if (key[i] >= 97 && key[i] <= 122)
            tmp = key[i] - 32;
        if (m == 0) {
            key_real[m] = tmp;
            m++;
        }
        else {
            for (j = 0; j < m; j++) {
                if (tmp == key_real[j]) {
                    break;
                }
            }
            if (j == m) {
                key_real[m] = tmp;
                m++;
            }
            else {
                continue;
            }
        }
    }
    key_real[m] = '\0';
    len1 = strlen(key_real);
    for (i = 0; i < len1; i++) {
        tmp = key_real[i];
        location = (strchr(A, tmp) - A) / sizeof(char);
        m = 0;
        while (m < 26) {
            if (location + m >= 26)
                location = (strchr(A, tmp) - A) / sizeof(char) - 26;
            mat[i][m] = A[location + m];
            m++;
        }
        mat[i][m] = '\0';
    }
    //处理字符串
    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            des[i] = str[i] + 32;
        else
            des[i] = str[i];
    }
    m = 0;
    for (i = 0; i < len; i++) {
        tmp = des[i];
        j = (i-m) % 6;
        ptr = strchr(mat[j], tmp);
        if (ptr == NULL) {
            m++;
            continue;
        }
        else {
            location = (ptr - mat[j]) / sizeof(char);
            des[i] = A[location];
        }
    }
    des[i] = '\0';
    return;
}
int main() {
    char m[] = "this is a test";
    char key[] = "cipher";
    char *des = (char*)malloc(sizeof(char) * MAX1);
    vigener_en(des,m,key);
    printf("明文：%s\n", m);
    printf("密文：%s\n", des);
    vigener_de(des,m,key);
    printf("明文：%s\n", des);
    printf("正确明文：%s\n","Vpxz mj c btzx");
     
    return 0;
}
