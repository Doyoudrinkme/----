#pragma once
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSTERLEN 255 //用户可在255以内定义最长串
typedef char SString[MAXSTERLEN + 1];  //0号单元存放串的长度


Status StrAssign(SString T, char *chars);