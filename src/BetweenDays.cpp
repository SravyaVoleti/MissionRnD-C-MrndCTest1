/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int days(int x) {
	int y = 0;
	switch (x) {
	case 1: y = 0; break;
	case 2:y = 31; break;
	case 3:y = 59; break;
	case 4:y = 90; break;
	case 5:y = 120; break;
	case 6:y = 151; break;
	case 7:y = 181; break;
	case 8:y = 212; break;
	case 9:y = 243; break;
	case 10:y = 273; break;
	case 11:y = 304; break;
	case 12:y = 334; break;
	}
	return y;
}
int between_days(struct node *date1head, struct node *date2head){

	if (date1head == NULL && date2head == NULL)
		return -1;

	int d1, d2, y1 = 0, y2 = 0, m1, m2, res, ref, dd1, dd2, i;
	struct node *p1, *p2;
	p1 = date1head;
	p2 = date2head;
	d1 = (date1head->data * 10) +date1head->next->data;
	date1head = date1head->next->next;
	d2 = (date2head->data * 10) + date2head->next->data;
	date2head = date2head->next->next;
	m1 = (date1head->data * 10) + date1head->next->data;
	date1head = date1head->next->next;
	m2 = (date2head->data * 10) + date2head->next->data;
	date2head = date2head->next->next;
	while (date1head != NULL && date2head != NULL) {
		y1 = (y1 * 10) + date1head->data;
		y2 = (y2 * 10) + date2head->data;
		date1head = date1head->next;
		date2head = date2head->next;
	}
	ref = y1;
	if (y2 < y1)
		ref = y2;
	dd1 = 0;
	dd1 = days(m1);
	for (i = ref; i < y1; i++){
		if (i % 4 == 0)
			dd1 += 1;
	}
	dd1 = dd1 + d1 + (y1 - ref) * 365;
	dd2 = 0;
	for (i = ref; i < y2; i++) {
		if (i % 4 == 0)
			dd2 += 1;
	}
	dd2 = days(m2) + dd2 + d2 + ((y2 - ref) * 365);
	if (dd1 > dd2)
		res = dd1 - dd2;
	else if(dd2 > dd1)
		res = dd2 - dd1;
	else
		res = 0;


	return res-1;
}