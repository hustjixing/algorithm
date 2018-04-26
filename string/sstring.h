#ifndef __SSTRING_h_
#define __SSTRING_h_

#define MAXSTRLEN 255
#define FALSE -1
#define TRUE 1
typedef unsigned char SString;
typedef int Status;

//S为字符串常量，生成一个其值等于chars的串
Status StrAssign(SString* T, char* S);


//串S存在，由串S复制得串T
Status StrCopy(SString* T, SString S);


//串S存在，若S为空返回TRUE，否则返回FALSE
Status StrEmpty(SString* S);


//S和T都存在，S > T返回正， S == T返回0， S < T返回负
Status StrCompare(SString S, SString T);


//S存在，返回S的元素个数，称为串的长度
Status StrLength(SString S);


//用T返回由S1和S2联结而成的新串。若未截断，则返回TRUE,否则FALSE
Status Concat(SString* T, SString S1, SString S2);


//用Sub返回串S的第pos个字符起长度为len的子串
Status SubString(SString* Sub, SString S, int pos, int len);


//T未非空串。若主串S中第pos个字符之后存在于T相等的子串，
//则返回第一个这样的子串在S中的位置，否则返回0
int Index(SString S, SString T, int pos);


#endif