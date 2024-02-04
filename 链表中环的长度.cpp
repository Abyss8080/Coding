#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int val;
	struct Node *next;
} ListNode;

/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */
int linkedListCycleLength(ListNode *head) {
	ListNode *slow = NULL, *fast = NULL;
	int len = 0;
	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return 0;
	slow = head->next;
	fast = head->next->next;
	while (fast != NULL && fast->next != NULL && fast->next->next != NULL && fast != slow) {
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast == slow) {
		len++;
		slow = slow->next;
		fast = fast->next->next;
		while (fast != NULL && fast->next != NULL && fast->next->next != NULL && fast != slow) {
			slow = slow->next;
			fast = fast->next->next;
			len++;
		}
		if (fast == slow)
			return len;
	}
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head->val = 0;
	head->next = NULL;
	ListNode *temp = head;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		temp->next = (ListNode *)malloc(sizeof(ListNode));
		temp->next->val = x;
		temp->next->next = NULL;
		temp = temp->next;
	}
	int d;
	scanf("%d", &d);
	ListNode *Nth = head;
	while (d--) {
		Nth = Nth->next;
	}
	temp->next = Nth;
	temp = head;
	head = head->next;
	free(temp);
	printf("%d\n", linkedListCycleLength(head));
	return 0;
}