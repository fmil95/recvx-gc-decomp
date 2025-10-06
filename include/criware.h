/*	����l								*/
/*	Default value						*/
#define	ADXF_DEF_SCT_SIZE		(2048)		/*	CD-ROM�̃Z�N�^�T�C�Y		*/
											/*	Sector size in CD-ROM		*/

/*	�t�@�C�����̕�����				*/
/*	Maximum number of file name strings	*/
#define ADXF_FNAME_MAX    		(256)

/*	�p�[�e�B�V�������ɕK�v�ȗ̈�̌v�Z						*/
/*	Calculation of necessary area for partition information		*/

#define	ADXF_PTIF_CMN_SZ		((5*sizeof(Sint32))+(ADXF_FNAME_MAX*sizeof(Sint8)))

#define	ADXF_CALC_PTINFO_REAL_SIZE(n)	(ADXF_PTIF_CMN_SZ+(((n)+1)*sizeof(Sint16)))

#define	ADXF_CALC_PTINFO_SIZE(n)	((ADXF_CALC_PTINFO_REAL_SIZE(n)+sizeof(Sint16))/4*4)

#define	ADXF_CALC_ADD_PTINFO_SIZE(n)	(ADXF_PTIF_CMN_SZ+((n)*(2*sizeof(Sint16)+sizeof(Sint32))))
