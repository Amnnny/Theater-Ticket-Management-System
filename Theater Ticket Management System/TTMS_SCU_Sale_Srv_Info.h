#pragma once
//�������ͣ�Ϊ��Ʊ����Ʊ
typedef enum {
	SALE_SELL = 1,	//��Ʊ
	SALE_RETURN = -1	//��Ʊ
}sale_type_t;

// ����ͳ�Ƶ���Ϣ �� ��ʾ��Ʊ����ġ� ����ĳ��ʱ������۳�����Ʊ �� ����ĳ��ticket_id , ���Ҫ�嵽�ҵ�ģ����ȥ �� ����Ʊ��ʱ����м�¼ ��
typedef struct {
	long id;      		//���ۼ�¼ID
	char UserAcc[15];	//��ƱԱ�˺�
	int ticket_id;		//ƱID
//	user_date_t date;	//��������
//	user_time_t time;	//����ʱ��
	int value;			//Ʊ��
	sale_type_t type; //��������
}sale_t;

//˫������
typedef struct sale_node {
	sale_t data;
	struct sale_node *next, *prev;
} SALE;