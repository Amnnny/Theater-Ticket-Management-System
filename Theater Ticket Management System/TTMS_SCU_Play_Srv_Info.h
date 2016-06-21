#pragma once

typedef enum {
	PLAY_TYPE_FILE = 1,
	PLAY_TYPE_OPEAR = 2,
	PLAY_TYPE_CONCERT = 3
} play_type_t;//��Ŀ���Ͷ��壬1��ʾ��Ӱ��2��ʾ��磬3��ʾ���ֻ�

typedef enum {
	PLAY_RATE_CHILD = 1,
	PLAY_RATE_TEENAGE = 2,
	PLAY_RATE_ADULT = 3
} play_rating_t;//�ݳ��������Ͷ��壬1��ʾ��ͯ�ɹۿ���2��ʾ������ɹۿ���3��ʾ���˿ɹۿ�


typedef struct {
	int id; //��Ŀid
	char name[31]; //��Ŀ����
	play_type_t type;
	char area[10]; //��Ŀ��Ʒ����
	play_rating_t rating;  //��Ŀ�ȼ�
	int duration; //ʱ��  ����Ϊ��λ
//	date_t start_date;
//	date_t end_date;
	int price;
}play_t;

typedef struct play_node{
	play_t data;
	struct play_node *next;
	struct play_node *prev;
}PLAY;
