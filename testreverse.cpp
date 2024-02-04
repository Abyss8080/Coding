
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX1 512
#define MAX2 32
char* str_reverse(char* str);
char* fence_en(char* str, int row);
//char* matirix_swap(char* str, int type, char* rank, int col);
//char* word_key(char* str,char* key);
int main() {
    char s[] = "012345678";
    char *goal=NULL;
     goal= fence_en(s,2);
     printf("Ã÷ÎÄ£º%s\n", s);
     printf("ÃÜÎÄ£º%s\n", goal);
    return 0;
}

char* str_reverse(char* str) {
    int len = 0, i = 0;
    char *re_str=(char*)malloc(sizeof(char)*MAX1);
    len = strlen(str);
    for (i = 0; i < MAX1; i++)
        re_str[i] = '#';
    for (i = len - 1; i >= 0; i--)
        re_str[len - i - 1] = str[i];
    re_str[len] = '\0';
    return re_str;
}
char* fence_en(char* str, int row) {
    char* goal = (char*)malloc(sizeof(char) * MAX1);
    int len = strlen(str);
    int temp=str%row,col;
    int i, j, m, flag;
    char mat[MAX2][MAX2];
    if(temp!=0){
    	col=str/row+1;
	}
	else
	col=str/row;
    m = 0;
    for (i = 0; i < col; i++) {
        for (j = 0; j < row; j++) {
            if (m < len) {
                mat[j][i] = str[m];
                m++;
            }
            else
                mat[j][i] = '#';
        }
    }
    m = 0;
    flag = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (mat[i][j] != '#')
            {
                goal[m] = mat[i][j];
                m++;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    goal[m] = '\0';
    return goal;
}
