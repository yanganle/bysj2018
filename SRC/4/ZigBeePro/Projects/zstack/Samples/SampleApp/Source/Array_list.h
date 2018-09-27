#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include "agreement.h"

//���ò���
typedef sEnddev_BasicInf ElemType;
typedef struct {
    ElemType *Array;//ʵ�ʴ��Ԫ�ص�����
    uint8 current_num;//���е�Ԫ�ظ���
    uint8 size;      //������������
}sarrayList;
extern sarrayList Galist;

PUBLIC bool Array_init(sarrayList *alist,ElemType * arrayhead , uint8 totalsize ,uint8 num);
PUBLIC void DeleteArray(sarrayList  * alist);
PUBLIC bool IsEmpty(sarrayList * alist);
PUBLIC uint8 ArrayLength(sarrayList *alist);
PUBLIC bool GetElem(sarrayList* alist,uint8 index,ElemType *e);
PUBLIC bool UpdateElem(sarrayList* alist,uint8 index,ElemType e);
PUBLIC void PrintfArray(sarrayList *alist);
PUBLIC uint8 LocateElem(sarrayList *alist,uYcl ycl);
PUBLIC bool AddElem(sarrayList *alist,ElemType e);
PUBLIC bool DelElem(sarrayList *alist,uint8 index);

PUBLIC bool GetElem_cmd(cmdList* alist,uint8 index,ElemType_cmd *e);
PUBLIC bool AddElem_cmd(cmdList *alist,ElemType_cmd e);
PUBLIC bool DelElem_cmd(cmdList *alist,uint8 index);
PUBLIC bool Array_cmd_init(cmdList *alist,ElemType_cmd * arrayhead , uint8 totalsize ,uint8 num);
PUBLIC uint8 LocateElem_RW(cmdList *alist, uYcl ycl, uint8 rw);



#endif /* ARRAY_LIST_H_ */
