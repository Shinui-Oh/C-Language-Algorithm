#include <stdio.h>
#include "Member.h"
#include "CircDblLinkedList.h"

typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, NEXT, PREV, CLEAR
} Menu;

Menu SelectMenu(void)
{
	int i, ch;
	char *mstring[] = {
		"�Ӹ��� ��带 ����",   "������ ��带 ����",  "�Ӹ� ��带 ����",
		"���� ��带 ����",  "������ ��带 ���",  "������ ��带 ����",
		"��ȣ�� �˻�",  "�̸����� �˻�",  "��� ��带 ���",
		"������ ��带 ��������",  "������ ��带 ��������",  "��� ��带 ����",
	};
	
	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-22.22s ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("(0) ���� : ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > CLEAR);

	return (Menu)ch;
}

int main(void)
{
	Menu menu;
	Dlist list;
	Initialize(&list);
	do {
		Member x;
		switch (menu = SelectMenu()) {

		case INS_FRONT:
			x = ScanMember("�Ӹ��� ����", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;

		case INS_REAR:
			x = ScanMember("������ ����", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;

		case RMV_FRONT:
			RemoveFront(&list);
			break;

		case RMV_REAR:
			RemoveRear(&list);
			break;

		case PRINT_CRNT:
			PrintLnCurrent(&list);
			break;

		case RMV_CRNT:
			RemoveCurrent(&list);
			break;

		case SRCH_NO:
			x = ScanMember("�˻�", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("�� ��ȣ�� �����Ͱ� �����ϴ�.");
			break;

		case SRCH_NAME:
			x = ScanMember("�˻�", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("�� �̸��� �����Ͱ� �����ϴ�.");
			break;

		case PRINT_ALL:
			Print(&list);
			break;

		case NEXT:
			Next(&list);
			break;

		case PREV:
			Prev(&list);
			break;

		case CLEAR:
			Clear(&list);
			break;
		}
	} while (menu != TERMINATE);

	Terminate(&list);
	
	return 0;
}