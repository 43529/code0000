#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

char tempstr[255] = {};
bool temp = false;
char arr[255] = {};
string keyarr[5] = {
    "int", "else", "if", "while"};

int keyarr_num[5] = {5, 15, 17, 20};

char symbol[15] = {'+', '-', '*', '/', '%', '(', ')', ';', '{', '}', '[', ']'};
int symbol_num[15] = {41, 42, 43, 44, 45, 81, 82, 84, 86, 87, 88, 89};

bool IsLetter(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

bool IsDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

int IsSymbol(char ch)
{
    for (int i = 0; i < 9; i++)
    {
        if (ch == symbol[i])
            return i;
    }
    return -1;
}

int IsOperatorSymbol(char *str, bool flag, int i)
{
    //<,<=
    if (*(str + i) == '<' && (!flag))
    {
        if (*(str + i + 1) == '=')
        {
            printf("<50,<= >\n");
            i++;
        }
        else
            printf("<49, < >\n");
    }
    //>,>=
    else if (*(str + i) == '>' && (!flag))
    {
        if (*(str + i + 1) == '=')
        {
            printf("<48,>= >\n");
            i++;
        }
        else
            printf("<47, > >\n");
    }
    //=,==
    else if (*(str + i) == '=' && (!flag))
    {
        if (*(str + i + 1) == '=')
        {
            printf("<51,== >\n");
            i++;
        }
        else
            printf("<46, = >\n");
    }
    //!=,=
    else if (*(str + i) == '!' && (!flag))
    {
        if (*(str + i + 1) == '=')
        {
            printf("<52,!= >\n");
            i++;
        }
        else
            printf("<55, ! >\n");
    }
    //&&
    else if (*(str + i) == '&' && (!flag))
    {
        if (*(str + i + 1) == '&')
        {
            printf("<53,&& >\n");
            i++;
        }
    }
    //||
    else if (*(str + i) == '|' && (!flag))
    {
        if (*(str + i + 1) == '|')
        {
            printf("<54,|| >\n");
            i++;
        }
    }
    //++
    else if (*(str + i) == '+' && (!flag))
    {
        if (*(str + i + 1) == '+')
        {
            printf("<56,++ >\n");
            i++;
        }
    }
    //--
    else if (*(str + i) == '-' && (!flag))
    {
        if (*(str + i + 1) == '-')
        {
            printf("<57,-- >\n");
            i++;
        }
    }
    else if (IsSymbol(*(str + i)) != -1 && (!flag))
    {
        printf("<%d, %c >\n",
               symbol_num[IsSymbol(*(str + i))], *(str + i));
    }
    return 0;
}
int IsKeyarr(string str)
{
    for (int i = 0; i < 26; i++)
    {
        if (str == keyarr[i])
        {
            return i;
        }
    }
    return 25;
}

void HandleSpace(char a[])
{
    int j = 0;
    memset(arr, 0, 255);
    temp = false;
    for (int i = 0; i < strlen(a); i++)
    {

        if (a[i] != ' ' && a[i] != '\t')
        {
            arr[j++] = a[i];
            temp = false;
        }
        else
        {

            if (!temp && a[i] != '\t')
            {
                arr[j++] = a[i];
                temp = true;
            }
        }
    }
}

void prePro()
{
    int j = 0;
    memset(tempstr, 0, 255);
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == '/' && arr[i + 1] == '/')
        {
            while (i < strlen(arr))
            {
                i++;
            }
        }

        else
        {
            tempstr[j++] = arr[i];
        }
    }
}

int main()
{
    char instr[255] = {};
    bool flag = false;
    string Token;
    char *str = NULL;
    char delims[] = " ";
    freopen("test.cpp", "r", stdin);
    //freopen("result.txt","w",stdout);
    while ((gets(instr)) != NULL)
    {
        HandleSpace(instr);
        prePro();

        str = strtok(tempstr, delims);

        while (str != NULL)
        {
            if (*(str) == '#')
            {
                printf("#\n");
                break;
            }

            for (int i = 0; i < strlen(str); i++)
            {
                if (*(str + i) == '/')
                {
                    if (*(str + i + 1) == '*')
                    {
                        flag = true;
                        break;
                    }
                }
                if (*(str + i) == '*' && flag)
                {
                    if (*(str + i + 1) == '/')
                    {
                        flag = false;
                        i++;
                        break;
                    }
                }
                if (IsLetter(*(str + i)) && (!flag))
                {
                    while (IsLetter(*(str + i)) || IsDigit(*(str + i)) || *(str + i) == '_')
                    {
                        Token += *(str + i);
                        i++;
                    }

                    if (IsKeyarr(Token) != 25)
                    {
                        printf("<%d,%s >\n",
                               keyarr_num[IsKeyarr(Token)], Token.c_str());
                    }
                    else
                        printf("<111, %s >\n", Token.c_str());

                    Token = "";
                }
                if (IsDigit(*(str + i)) && (!flag))
                {
                    while (IsDigit(*(str + i)))
                    {
                        Token += *(str + i);
                        i++;
                    }
                    printf("<100, %s >\n", Token.c_str());
                    Token = "";
                }

                IsOperatorSymbol(str, flag, i);
            }
            str = strtok(NULL, delims);
        }
    }

    return 0;
}
