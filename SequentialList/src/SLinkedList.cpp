#include "SLinkedList.h"
#include <iostream>

Status init_sl( SLinkedList slist ){
	if(!slist){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	slist[0].next = 2;  // slist[0]�ǿ��б��ͷ���
	slist[1].next = -1; // slist[1]�Ƿǿ��б��ͷ���

	for(int i = 2; i < MAXSIZE - 1; ++i){
		slist[i].next = i + 1;
	}
	slist[MAXSIZE - 1].next = -1;

	return OK;
}
int malloc_sl( SLinkedList slist ){
	if(NULL == slist){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	int i = slist[0].next;
	if(i != -1){ // ����ڵ�ɹ� 
		slist[0].next = slist[i].next;
	}
	return i;
}
Status free_sl( SLinkedList slist, int k ){
	if(NULL == slist){
		std::cerr << "Invalid arguments!";
			return ERROR;
	}

	slist[k].next = slist[0].next;
	slist[0].next = k;
	
	return OK;
}

Status create_slinkedlist( SLinkedList slist, const ElemType* arr, int n ){
	if(!slist || !arr || n <= 0){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	for( int i = 0; i < n; ++i ){
		int s = malloc_sl( slist );
		if(-1==s){
			std::cerr << "Overflow!";
			return OVERFLOW;
		}
		slist[s].data = arr[i];
		slist[s].next = slist[1].next;
		slist[1].next = s;
	}

	return OK;
}
Status print_slinkedlist( const SLinkedList slist ){
	if(!slist){
		std::cerr << "Not invalid arguments!";
		return ERROR;
	}
	int cur = slist[1].next;
	while(cur != -1){
		std::cout << slist[cur].data << std::endl;
		cur = slist[cur].next;
	}
	return OK;
}
Status insert_slinkedlist( SLinkedList slist, int i, int target ){
	if(!slist || i < 1 ){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}

	int cur = 1; // ͷ���
	for( int cnt = 0; cnt < i-1 && cur > -1 ; ++cnt ){
		cur = slist[cur].next;
	}
	if(-1 == cur) return ERROR;
	else{
		int s = malloc_sl(slist); // Ϊ��i��λ�õĽڵ㿪�ٿռ�
		if(-1==s) return OVERFLOW;
		slist[s].data = target;
		slist[s].next = slist[cur].next;
		slist[cur].next = s;

		return OK;
	}
}
Status delete_slinkedlist( SLinkedList slist, int i){
	if(!slist){
		std::cerr << "Invalid arguments!";
		return ERROR;
	}
	int cur = 1; // ͷ���
	for( int cnt = 0; cnt < i - 1; ++cnt){
		cur = slist[cur].next;
	}
	if(-1==cur) return ERROR;
	else{
		int s = slist[cur].next; // Ҫɾ���ĵ�i���ڵ��λ��
		slist[cur].next = slist[s].next;
		
		free_sl(slist, s); // �ͷŵ�i���ڵ��λ��
		return OK;
	} 
}