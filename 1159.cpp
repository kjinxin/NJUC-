#include<iostream>
#include<string.h>
#include<stdio.h>

int findstr(char inorder[], int i1, int i2, char ch)
{
    for (int i = i1; i <= i2; i ++)
        if (inorder[i] == ch) return i;
}
void printpreorder(char inorder[], char postorder[], int i1, int i2, int p1, int p2)
{
    if (i1 > i2) return;
    printf("%c", postorder[p2]);
    if (p1 == p2) return;
    int pos = findstr(inorder, i1, i2, postorder[p2]);
    printpreorder(inorder, postorder, i1, pos - 1, p1, p1 + pos - i1 -1);
    printpreorder(inorder, postorder, pos + 1, i2, p1 + pos - i1, p2 - 1);
}
int main()
{
    char inorder[1000], postorder[1000];
    scanf("%s", inorder);
    scanf("%s", postorder);
    printpreorder(inorder, postorder, 0, strlen(inorder) - 1, 0, strlen(postorder) - 1);
    return 0;
}
