	#pragma once


typedef unsigned char UCH;//255
typedef unsigned short USH;//65535
typedef unsigned long long ULL;



const USH MIN_MATCH =3;//��̳���
const USH MAX_MATCH = 258;//255+3--->length �����
const USH WSIZE = 32 * 1024;//32k ��������С


const USH HASH_BITS = 15; //��ϣ��ַλ��
const USH HASH_SIZE = (1 << 15);//��ϣ������
const USH HASH_MASK = HASH_SIZE - 1;//��ϣ����
