#pragma once
typedef struct {
	int id;			//��ӳ��ID
	char name[30];	//��ӳ������
	int rowsCount;	//��λ����
	int colsCount;	//��λ����
	int seatsCount;
} studio_t;

//˫������
typedef struct studio_node {
	studio_t data;				//ʵ������
	struct studio_node *next;	//����ָ��
	struct studio_node *prev;	//ǰ��ָ��
} STUDIO;                                                                      
