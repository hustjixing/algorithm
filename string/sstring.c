#include <stdio.h>
#include "sstring.h"

Status StrEmpty(SString* S)
{
    return S[0] == 0 ? TRUE : FALSE;
}

Status StrAssign(SString* T, char* S)
{
    int i;
    if(T == NULL || S == NULL)
    {
        return FALSE;
    }
    if(T)
    {
        free(T);
    }
    T = (SString*)malloc((MAXSTRLEN + 1) * sizeof(SString));
    if(!T)
    {
        exit(-1);
    }
    i = 0;
    while(S[i] != '\0')
    {
        T[i + 1] = S[i];
        i++;
    }
    T[0] = i;
    return TRUE;
}

Status PrintStr(SString* S)
{
    int i;
    for(i = 0; i < S[0]; i++)
    {
        printf("%c", S[i + 1]);
    }
    printf("\n");
}

