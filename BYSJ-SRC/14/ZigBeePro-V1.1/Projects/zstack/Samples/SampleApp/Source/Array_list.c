#include <stdlib.h>

#define len 5

PUBLIC uint8 LocateElem(sarrayList *alist,uYcl ycl);
PUBLIC uint8 ArrayLength(sarrayList *alist);
PUBLIC uint8 ArrayLengthcmd(cmdList *alist);

sarrayList Galist; //�豸������Ϣ
cmdList Rwlist; //��д�����

//��ʼ��˳���������ʼ������
PUBLIC bool Array_init(sarrayList *alist,ElemType * arrayhead , uint8 totalsize ,uint8 num )
{
    alist->Array = arrayhead;
    alist->current_num=num;
    alist->size=totalsize;
    if(NULL==alist->Array)
        return FALSE;
    else
        return TRUE;
}

//ɾ��˳���
PUBLIC void DeleteArray(sarrayList  * alist)
{
	alist->Array = NULL;
	alist->current_num = 0;
	alist->size = 0;

}

//�ж�˳���б�Ϊ��
PUBLIC bool IsEmpty(sarrayList * alist)
{
    if(0==alist->current_num)
    {
        return TRUE;
    }
    else
    {

        return FALSE;
    }

}
PUBLIC uint8 test(void)
{
	return 1;
}


PUBLIC uint8 LocateElem(sarrayList *alist,uYcl ycl)
{
	uint8 i=0;
	uYcl tycl=ycl;
	uint8 pos=0;
	sEnddev_BasicInf tEnddev_BasicInf;
    for(i=0 ; i<ArrayLength(alist) ; i++)
    {
    	tEnddev_BasicInf = alist->Array[i];
    	//if((tEnddev_BasicInf.ycl.sYCL.Mac == tycl.sYCL.Mac) && (tEnddev_BasicInf.ycl.sYCL.YCL_ID.u32YCL_ID == tycl.sYCL.YCL_ID.u32YCL_ID))
    	if(tEnddev_BasicInf.ycl.sYCL.Mac == tycl.sYCL.Mac)//ֻ���MAC��ַ
    	{
    		pos = i+1;
    	}

    }
    return pos;
}

//�б����ж��ٸ�Ԫ��
PUBLIC uint8 ArrayLength(sarrayList *alist)
{
    return alist->current_num;
}

//ȡ��ĳ��Ԫ��
PUBLIC bool GetElem(sarrayList* alist,uint8 index,ElemType *e)
{
    if((index>ArrayLength(alist))||(index==0))
    {
        return FALSE;
    }
    else
    {
        *e=alist->Array[index-1];
        return TRUE;
    }
}

//ȡ��ĳ��Ԫ��
PUBLIC bool UpdateElem(sarrayList* alist,uint8 index,ElemType e)
{
    if((index>ArrayLength(alist))||(index==0))
    {
        return FALSE;
    }
    else
    {
        alist->Array[index-1] = e;
        return TRUE;
    }
}

//����˳�������ӡ
PUBLIC void PrintfArray(sarrayList *alist)
{
	uint8 i=0;

    for(i=0;i<alist->current_num;i++)
    {

    }
}

//���ĳ��Ԫ��
PUBLIC bool AddElem(sarrayList *alist,ElemType e)
{
	uint8 index=0;
     //���˳���洢�ռ�����������Ҫ���·����ڴ�
    if(alist->current_num==alist->size)
    {
    	return FALSE;//�б�����
    }
    index=ArrayLength(alist);
    alist->Array[index]=e;
    ++alist->current_num;
    return TRUE;
}

//ɾ��ĳ��Ԫ��
PUBLIC bool DelElem(sarrayList *alist,uint8 index)
{
	uint8 i=0;
    //���жϲ���λ���Ƿ�Ϸ�
    if((index==0)||(index>ArrayLength(alist)))
    {
        return FALSE;
    }
    for(i = index; i <= ArrayLength(alist); i++)
    {
        alist->Array[i-1]=alist->Array[i];
    }
    --alist->current_num;

    return TRUE;
}
