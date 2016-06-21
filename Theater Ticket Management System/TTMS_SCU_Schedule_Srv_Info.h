#pragma once
typedef struct {//�ݳ��ƻ����Ͷ���
	int id;            //�ݳ��ƻ�ID��
	int play_id;       //�ݳ��ľ�ĿID��
	int studio_id;     //�ݳ��ķ�ӳ��ID��
//	user_date_t date;  //�ݳ�����
//	user_time_t time;  //�ݳ�ʱ��
	int seat_count;    //��λ����
}schedule_t;

typedef struct {
	int year;
	int month;
	int day;
}DAY;

typedef struct {
	DAY daytime;
	int hour;
	int minute;
}TIME;

typedef struct schedule_node {
	schedule_t data;
	TIME time;
	struct schedule_node *next;
	struct schedule_node *prev;
} SCHEDULE;