#ifndef _SJ_H_INCLUDED
#define _SJ_H_INCLUDED
/****************************************************************************/
/*																			*/
/*					�X�g���[���W���C���g���C�u�����w�b�_					*/
/*						 SJ (Stream Joint) Library							*/
/*																			*/
/*				 1998.4.14			written by M.Oshimi						*/
/*																			*/
/****************************************************************************/

#define	SJ_VER	"6.09"		/* Version number */

#include "cri_xpt.h"

/***********************************************************************
 *		�����}�N��
 *		Process MACRO
 ***********************************************************************/

/* �����A�h���X�̃|�C���^�^�ւ̕ϊ� */
#define SJ_VOID_PTR(adr)	((void *)(adr))

/* ����n�r�b�g���[���ɂ���
 * �@1,2,8,16�r�b�g�̏ꍇ�ASH�́A�ړI�̃��W�X�^�����g�p����2���߂ŏ���
 * �ł���̂ŁA�V�t�g�����ɂ���B
 * �@3�`7�r�b�g�̏ꍇ�ASH�́A-128�܂ł͖��߃R�[�h�ɃC�~�f�B�G�C�g�f�[�^
 * ���i�[�ł���̂ŁA�}�X�N�����ɂ���B1���߂܂���2���߁B
 * �@���̑��̏ꍇ�A�󋵂ɉ����čœK�Ƃ͌���Ȃ����A�V�t�g�����ɂ��Ă����B
 */
#define SJ_OFF_LSB(val, n)	((((Uint32)(val)) >> (n)) << (n))
#define SJ_OFF_LSB1(val)	((((Uint32)(val)) >> (1)) << (1))
#define SJ_OFF_LSB2(val)	((((Uint32)(val)) >> (2)) << (2))
#define SJ_OFF_LSB3(val)	(((Uint32)(val)) & (0xfffffff8))
#define SJ_OFF_LSB4(val)	(((Uint32)(val)) & (0xfffffff0))
#define SJ_OFF_LSB5(val)	(((Uint32)(val)) & (0xffffffe0))
#define SJ_OFF_LSB6(val)	(((Uint32)(val)) & (0xffffffc0))
#define SJ_OFF_LSB7(val)	(((Uint32)(val)) & (0xffffff80))
#define SJ_OFF_LSB8(val)	((((Uint32)(val)) >> (8)) << (8))
#define SJ_OFF_LSB16(val)	((((Uint32)(val)) >> (16)) << (16))

/* �|�C���^��2,4,8,16,32byte���E�܂Ŗ߂��i���ӁF���ʂ�(void*)�^�j */
#define SJ_BACK_BND2(ptr)	SJ_VOID_PTR(SJ_OFF_LSB1(ptr))
#define SJ_BACK_BND4(ptr)	SJ_VOID_PTR(SJ_OFF_LSB2(ptr))
#define SJ_BACK_BND8(ptr)	SJ_VOID_PTR(SJ_OFF_LSB3(ptr))
#define SJ_BACK_BND16(ptr)	SJ_VOID_PTR(SJ_OFF_LSB4(ptr))
#define SJ_BACK_BND32(ptr)	SJ_VOID_PTR(SJ_OFF_LSB5(ptr))

/* �|�C���^��2,4,8,16,32byte���E�܂Ői�߂�i���ӁF���ʂ�(void*)�^�j */
#define SJ_FORE_BND2(ptr)	SJ_BACK_BND2( ((Uint32)(ptr)) +  1)
#define SJ_FORE_BND4(ptr)	SJ_BACK_BND4( ((Uint32)(ptr)) +  3)
#define SJ_FORE_BND8(ptr)	SJ_BACK_BND8( ((Uint32)(ptr)) +  7)
#define SJ_FORE_BND16(ptr)	SJ_BACK_BND16(((Uint32)(ptr)) + 15)
#define SJ_FORE_BND32(ptr)	SJ_BACK_BND32(((Uint32)(ptr)) + 31)

/* 32byte���E�̗̈�m�ۂ̂��߂ɁA�̈�T�C�Y�𐅑������� */
#define SJ_SIZ_BND32(siz)	((siz) + 32)

/* SJ�o�b�t�@�A�h���X��32�o�C�g���E�̎擾 */
#define	SJ_ADR_BND32(adr)	SJ_FORE_BND32(adr)

/* ���E���̐�[�ƌ�����I�[�����߂� */
#define SJ_GET_ENDPOS(bgn, num)		((bgn) + (num) - 1)

/* ���E���̌��i���E�l�Fbgn <= end�j */
#define SJ_INNER_NUM(bgn, end)		((end) - (bgn) + 1)

/* ���E���̔���i���E�l�Fbgn <= x <= end�j */
#define SJ_IS_INNER(x, bgn, end) ( ((x) >= (bgn)) && ((x) <= (end)) )

/***********************************************************************
 *		�f�[�^�^
 *		Data type declaration
 ***********************************************************************/

/*	�f�[�^���C���̒�`		*/
/*	Data line definition	*/
#define	SJ_LIN_FREE	(0)			/*	�t���[�`�����N���C��				*/
								/*	Free chunk line						*/
#define	SJ_LIN_DATA	(1)			/*	�f�[�^�`�����N���C��				*/
								/*	Data chunk line						*/

#define SJ_ERR_FATAL		(-1)
#define SJ_ERR_INTERNAL		(-2)
#define SJ_ERR_PRM			(-3)

/*	�`�����N�̏���T�C�Y	*/
/*	Maximum size of chunk	*/
#define	SJCK_LEN_MAX		(0x7fffffff)

#ifndef UUID_DEFINED
#define UUID_DEFINED
typedef struct _UUID {
    Uint32 Data1;
    Uint16 Data2;
    Uint16 Data3;
    Uint8 Data4[8];
} UUID;
#define uuid_t UUID
#endif

/*	�f�[�^�`�����N	*/
/*	Data chunk		*/
#ifndef SJCK_DEFINED
#define SJCK_DEFINED
typedef struct {
	Sint8 *data;				/*	�J�n�A�h���X						*/
								/*	Begin address						*/
	Sint32 len;					/*	�o�C�g��							*/
								/*	Size of chunk length				*/
} SJCK;
#endif

/*	���C�u�����n���h��	*/
/*	SJ handle			*/
typedef struct {
	struct _sj_vtbl *vtbl;		/*	�C���^�t�F�[�X						*/
								/*	Interfaces							*/
} SJ_OBJ;
#ifndef SJ_DEFINED
#define SJ_DEFINED
typedef SJ_OBJ *SJ;
#endif

/*	�C���^�t�F�[�X�֐�  				*/
/*	Interface functions					*/
typedef struct _sj_vtbl {
	void (*QueryInterface)();		/*		for COM compatibility			*/
	void (*AddRef)();				/*		for COM compatibility			*/
	void (*Release)();				/*		for COM compatibility			*/
	void (*Destroy)(SJ sj);			/*		�n���h���̏���					*/
									/*		Destroys specified SJ handle	*/
	UUID *(*GetUuid)(SJ sj);		/*		UUID�̎擾						*/
									/*		Get a UUID						*/
	void (*Reset)(SJ sj);			/*		���Z�b�g						*/
									/*		Resets SJ						*/
	/*	�`�����N�̎擾	(FIFO�̐擪����擾)								*/
	/*	Get a chunk	(Get chunk from top of FIFO)							*/
	void (*GetChunk)(SJ sj, Sint32 id, Sint32 nbyte, SJCK *ck);
	/*	�`�����N��߂��@(FIFO�̐擪�ɑ}��)									*/
	/*	Unget a chunk	(Insert chunk in top of FIFO)						*/
	void (*UngetChunk)(SJ sj, Sint32 id, SJCK *ck);
	/*	�`�����N��}��	(FIFO�̍Ō�ɑ}��)									*/
	/*	Put a chunk	(Insert chunk in last of FIFO)							*/
	void (*PutChunk)(SJ sj, Sint32 id, SJCK *ck);
	/*	�擾�ł���f�[�^�̃o�C�g���̎擾									*/
	/*	Get the data number which can be got								*/
	Sint32 (*GetNumData)(SJ sj, Sint32 id);
	/*	�`�����N�̎擾�\�̔���											*/
	/*	Check whether can get chunk											*/
	Sint32 (*IsGetChunk)(SJ sj, Sint32 id, Sint32 nbyte, Sint32 *rbyte);
	/*	�G���[�������ɋN������֐��̓o�^									*/
	/*	Entry error callback function										*/
	void (*EntryErrFunc)(SJ sj,
					void (*func)(void *obj, Sint32 ecode), void *obj);
} SJ_IF;
typedef SJ_IF *SJIF;

/*	�X�g���[���W���C���g�̏���												*/
/*	Destroys specified SJ handle											*/
#define SJ_Destroy(sj) \
		(*(sj)->vtbl->Destroy)(sj)
/*	�X�g���[���W���C���g�̃��Z�b�g											*/
/*	Resets SJ																*/
#define SJ_Reset(sj) \
		(*(sj)->vtbl->Reset)(sj)
/*	�`�����N�̎擾															*/
/*	Get a chunk																*/
#define SJ_GetChunk(sj, id, nbyte, ck) \
		(*(sj)->vtbl->GetChunk)(sj, id, nbyte, ck)
/*	�`�����N��߂�															*/
/*	Unget a chunk 															*/
#define SJ_UngetChunk(sj, id, ck) \
		(*(sj)->vtbl->UngetChunk)(sj, id, ck)
/*	�`�����N��}��															*/
/*	Put a chunk																*/
#define SJ_PutChunk(sj, id, ck) \
		(*(sj)->vtbl->PutChunk)(sj, id, ck)
/*	�擾�\�ȃf�[�^�̃o�C�g�������߂�										*/
/*	Get the data number which can be got									*/
#define SJ_GetNumData(sj, id) \
		(*(sj)->vtbl->GetNumData)(sj, id)
/*	�X�g���[���W���C���gUUID�̎擾 (UUID�ւ̃A�h���X)						*/
/*	Get a UUID																*/
#define SJ_GetUuid(sj) \
		(*(sj)->vtbl->GetUuid)(sj)
/*	�G���[�������ɋN������R�[���o�b�N�֐��̓o�^							*/
/*	Entry error callback function											*/
#define SJ_EntryErrFunc(sj, f, o) \
		(*(sj)->vtbl->EntryErrFunc)(sj, f, o)
/*	�`�����N�̎擾�\�̔��� 												*/
/*	Check whether can get chunk												*/
#define SJ_IsGetChunk(sj, id, nbyte, rbyte) \
			(*(sj)->vtbl->IsGetChunk)(sj, id, nbyte, rbyte)

/****************************************************************************
 *		�֐��̐錾
 *		Function Declaration
 ****************************************************************************/

#ifdef		__cplusplus
extern	"C" {
#endif

/*	$func$ �`�����N�̕���
 * [���@��] void SJ_SplitChunk(SJCK *ck, Sint32 nbyte,
 *													SJCK *ck1, SJCK *ck2);
 * [���@��] ck		: ����ΏۂƂȂ�`�����N
 *			nbyte	: ck1 �̃o�C�g��
 * [�o�@��] ck1		: �������ꂽ�O���̃`�����N
 *			ck2		: �������ꂽ�㔼�̃`�����N
 * [�֐��l] ck2	�`�����N�̃o�C�g��
 * [�@�@�\] ck�`�����N��ck1�`�����N��ck2�`�����N�ɕ�������B
 *			ck1�`�����N�́Anbyte �̒����ɂȂ�B
 *			ck1�`�����N�̑傫�����Anbyte �ɖ����Ȃ��ꍇ�́A�������ꂸ�A
 *			ck2�`�����N�̒����́A0�ƂȂ�B
 *			ck1��ck�́A�������̂��w�肵�Ă��ǂ��B
 *			�P�ɕ�������ꍇ�́A�ȉ��̂悤�ɋL�q����B
 *				SJ_SplitChunk(&ck, 100, &ck, &ck2);
 *  
 * [Inputs  ] ck	: Target chunk
 *			  nbyte	: Size of ck1(byte)
 * [Outputs ] ck1	: Split chunk of the first half
 *			  ck2	: Split chunk of the latter half
 * [Return  ] None
 * [Function] Split a chunk.
 */
void SJ_SplitChunk(SJCK *ck, Sint32 nbyte, SJCK *ck1, SJCK *ck2);

/***
*		�^�O����֐�
*			�^�O�t�H�[�}�b�g
*				0-6		�^�O������
*				7		0(=\0)
*				8-14	�f�[�^�� (�P�U�i������)
*				15		0(=\0)
***/

/*	$func$ �^�O�̐���
 * [���@��] void SJ_MakeTag(SJCK *ck, char *tag);
 * [���@��] ck		: �^�O�𐶐�����`�����N
 *			tag		: �^�O������
 * [�o�@��] �Ȃ�
 * [�֐��l] �Ȃ�
 * [�@�@�\] ck�`�����N���Ƀ^�O�𐶐�����B�^�O�̎�������ck.len-16�o�C�g�ƂȂ�B
 * [Inputs  ] ck	: Target chunk
 *			  tag	: TAG strings
 * [Outputs ] none
 * [Return  ] None
 * [Function] Creating tag.
 */
void SJ_MakeTag(SJCK *ck, char *tag);

/*	$func$ �^�O�̓��e�̎擾
 * [���@��] void SJ_GetTagContent(Sint8 *tag, SJCK *cko);
 * [���@��] tag		: �^�O������
 * [�o�@��] ck		: �^�O�̓��e�ƂȂ�`�����N
 * [�֐��l] �Ȃ�
 * [�@�@�\] �^�O���炻�̓��e�������`�����N���擾����B
 * [Inputs  ] tag	: TAG strings
 * [Outputs ] ck	: chunk
 * [Return  ] None
 * [Function] Creating chunk from TAG.
 */
void SJ_GetTagContent(Sint8 *tag, SJCK *cko);

/*	$func$ �^�O�̌���
 * [���@��] Sint8 *SJ_SearchTag(SJCK *cki, Char8 *kw, Char8 *endkw, SJCK *cko);
 * [���@��] cki		: �����ΏۂƂȂ�`�����N
 *			kw		: �ړI�Ƃ���^�O�̃L�[���[�h
 *			endkw	: ���̃L�[���[�h�����^�O���������Ƃ��͌����𒆒f����B
 *					  NULL���w�肳�ꂽ�Ƃ��́A�����𒆒f���Ȃ��B
 * [�o�@��] ck		: �^�O�̓��e�ƂȂ�`�����N�B
 *					  ������Ȃ������Ƃ��́Acko->data=NULL, cko->len=0�ƂȂ�B
 * [�֐��l] ���������^�O�̃A�h���X�B������Ȃ������Ƃ���NULL���Ԃ�B
 * [�@�@�\] �^�O���炻�̓��e�������`�����N���擾����B
 * [Inputs  ] cki	: chunk for searching
 *			�@kw	: Keyword of tag
 *			  endkw : Serach end keyword
 * [Outputs ] cko	: target chunk
 * [Return  ] tag
 * [Function] Searching chunk.
 */
Sint8 *SJ_SearchTag(SJCK *cki, Char8 *kw, Char8 *endkw, SJCK *cko);


/***
*		�����O�o�b�t�@�^�C�v�̃X�g���[���W���C���g
*		Stream joint of Ring buffer types
***/

/*	������																	*/
/*	Initialize																*/
void SJRBF_Init(void);
/*	�I������																*/
/*	Finish																	*/
void SJRBF_Finish(void);
/*	�����O�o�b�t�@�̐���													*/
/*	Create a Ring buffer													*/
SJ SJRBF_Create(Sint8 *buf, Sint32 bsize, Sint32 xsize);

/***
*		�������^�C�v�̃X�g���[���W���C���g
*		Stream joint of Memory buffer types
***/

/*	������																	*/
/*	Initialize																*/
void SJMEM_Init(void);
/*	�I������																*/
/*	Finish																	*/
void SJMEM_Finish(void);
/*	�������X�g���[���̐���													*/
/*	Create a Memory buffer													*/
SJ SJMEM_Create(Sint8 *data, Sint32 bsize);

/***
*		�ėp�X�g���[���W���C���g
*		General Stream joint		
***/

/*	�`�����N�̌������[�h		*/
/*	Combination mode of chunk	*/
#define	SJUNI_MODE_SEPA			(0)
#define	SJUNI_MODE_JOIN			(1)

#define	SJUNI_CALC_WORK(nck)	((nck)*16)

/*	������																	*/
/*	Initialize																*/
void SJUNI_Init(void);
/*	�I������																*/
/*	Finish																	*/
void SJUNI_Finish(void);
/*	�ėp�X�g���[���W���C���g�̐���											*/
/*	Create a Stream joint													*/
SJ SJUNI_Create(Sint32 mode, Sint8 *work, Sint32 wksize);
/*	�`�����N���̎擾														*/
/*	Get chunk number														*/
Sint32 SJUNI_GetNumChunk(SJ sj, Sint32 id);
/*	�`�F�C���v�[�����̎擾													*/
/*	Get Chain pool	number													*/
Sint32 SJUNI_GetNumChainPool(SJ sj);

#if 0
/*	GetChunk�֐����Ă΂ꂽ�Ƃ��̃R�[���o�b�N�֐��̓o�^						*/
void SJUNI_EntryGetFunc(SJ sj, Sint32 id, void (*f)(void *o, SJCK *ck), void *o);
/*	PutChunk�֐����Ă΂ꂽ�Ƃ��̃R�[���o�b�N�֐��̓o�^						*/
void SJUNI_EntryPutFunc(SJ sj, Sint32 id, void (*f)(void *o, SJCK *ck), void *o);
/*	UngetChunk�֐����Ă΂ꂽ�Ƃ��̃R�[���o�b�N�֐��̓o�^					*/
void SJUNI_EntryUngetFunc(SJ sj, Sint32 id, void (*f)(void *o, SJCK *ck), void *o);
#endif

/***
*		���ʊ֐�
***/

/*	�N���e�B�J���Z�N�V�����ւ̐i��	*/
void SJCRS_Lock(void);
/*	�N���e�B�J���Z�N�V��������̒E�o	*/
void SJCRS_Unlock(void);

#ifdef		__cplusplus
}
#endif

#endif     /*  #ifndef _SJ_H_INCLUDED	*/
