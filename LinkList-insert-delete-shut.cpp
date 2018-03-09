 #include<stdio.h>
 #include<stdlib.h>
 typedef int ElemType;
 typedef struct node{
 	ElemType data;      //������ 
 	struct node *next;  //ָ���� 
 }LNode,*LinkList;     //LNode *L��LinkList L�ǵȼ۵� 
 
 LinkList GreatLinkList(int n){
 	//����һ������Ϊn������
	 LinkList p,r,list = NULL;
	 ElemType e;
	 int i;
	 for (i = 1;i <= n;i++) 
	 {
	 	scanf("%d",&e);
	 	p = (LinkList)malloc(sizeof(LNode));
	 	p->data = e;
	 	p->next = NULL;
	 	if (!list)
	 	list = p;
	 	else r->next = p;
	 	r = p;
	 }
	 return list;
 }
 
void insertList(LinkList *list,LinkList q,ElemType e){
	//����������ָ��qָ���Ľڵ�������ڵ㣬�ڵ�����Ϊe
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode)) ;  //����һ���½ڵ㣬��pָ����
	p->data = e;          //��ýڵ��������ֵe
	if (!*list) {
		*list = p;        //list������ΪNULL��ʾ������Ϊ��
		p->next = NULL; 
	}                    //������Ϊ��ʱqû�����壬ֻ����ͷ�ڵ��������һ��Ԫ�� 
	else {
		p->next = q->next;   //������Ϊ��ʱ����Ϊqָ��Ľڵ�һ������
		/*��qָ��Ľڵ��next���ֵ��ֵ��pָ��ڵ��next��*/
		q->next = p;      //��p��ֵ��ֵ��q��next�� 
	}
}
 
//��������ɾ���ڵ�
/*�������������1.q��ָ���������ĵ�һ���ڵ�
2.q��ָ��Ľڵ��ǰ������ָ����֪
3.q��ָ��Ľڵ��ǰ������ָ��δ֪    */
void delLink1(LinkList *list,LinkList r,LinkList q) {
	if (q == *list)      //ɾ������ڵ�ĵ�һ������
	*list = q->next;
	else 
	r->next = q->next;   //ɾ������ڵ�ĵڶ�������
	free(q) ;            //�ͷŵ�q��ָ��Ŀռ� 
}

void delLink(LinkList *list,LinkList q){
	LinkList r;
	if (q == *list){
		*list = q->next;
		free(q);
	}
	else{
		for (r = *list;r->next != q;r=r->next) ;  //���������ҵ�q��ǰ������ָ��
		if (r->next != NULL) {
			r->next = q->next;    //��������ɾ��qָ��Ľڵ�
			free(q) ;
		}
	}
}
 
//����һ������
void destroyLinkList(LinkList *list) {
	LinkList p,q;
	p = *list;
	while (p){
		q = p->next;
		free(p);
		p = q;
	}
	*list = NULL;
}

int main(void)
{
	int e,i;
	LinkList l,q;
	q = l = GreatLinkList(1);    //����һ������ڵ㣬q��lָ��ýڵ�
	scanf("%d",&e) ;
	while (e)
	{
		insertList(&l,q,e);
		q = q->next;
		scanf("%d",&e);
	}
	q = l;
	printf("The content of the linklist\n");
	while (q)     //��������е�����
	{
		printf("%d ",q->data);
		q = q->next;
	} 
	q = l;
	printf("\nDelete the fifth element\n");
	for (i = 0;i < 4;i++)    //��ָ��qָ������ĵ�5��Ԫ��
	{
		if (q == NULL)    //ȷ����ʱ����ĳ��ȴ��ڵ���5�������ǷǷ����� 
		{
			printf("The length of the linklist is smaller than 5 !");
			return 0;
		}
		
		q = q->next; 
	} 
	delLink(&l,q);   //�ҵ������е�5��Ԫ�أ���qָ��������ɾ��q��ָ�Ľڵ�
	q = l;
	while (q)       //��ӡ��ɾ����Ľ�� 
	{
		printf("%d ",q->data);
		q = q->next;
	}
	destroyLinkList(&l);   //���ٸ�����
	return 0; 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
