#pragma once
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSTERLEN 255 //�û�����255���ڶ������
typedef char SString[MAXSTERLEN + 1];  //0�ŵ�Ԫ��Ŵ��ĳ���


Status StrAssign(SString T, char *chars);