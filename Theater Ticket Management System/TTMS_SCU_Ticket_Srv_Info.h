#pragma once
typedef enum {
	TICKET_AVL = 0,		//����
	TICKET_SOLD = 1,		//����
	TICKET_RESV = 9		//Ԥ��
}ticket_status_t;

typedef struct {
	int id;
	int schedule_id;
	int seat_id;
	int price;
	ticket_status_t status;
} ticket_t;

//˫������
typedef struct ticket_node {
	ticket_t data;
	struct ticket_node *next, *prev;
} TICKET;