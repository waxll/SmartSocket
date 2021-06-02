#ifndef _OLED_H
#define _OLED_H
#include "sys.h"

#define OLED_IIC_SCL  PBout(3) //SCL   ����ʱ��
#define OLED_IIC_SDA  PBout(4) //SDA	 ��������

 
#define high 1
#define low 0
#define OLED_MODE 0
#define SIZE 1
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64 
#define X_WIDTH 	128
#define Y_WIDTH 	64

void IIC_Init(void);
void IIC_Start(void);// -- ����I2C����
void IIC_Stop(void);// -- �ر�I2C����
void Write_IIC_Byte(unsigned char IIC_Byte);// -- ͨ��I2C����дһ��byte������
void OLED_WrDat(unsigned char dat);// -- ��OLED��д����
void OLED_WrCmd(unsigned char cmd);// -- ��OLED��д����
void OLED_Set_Pos(unsigned char x, unsigned char y);// -- ������ʾ����
void OLED_Fill(unsigned char bmp_dat);// -- ȫ����ʾ(��ʾBMPͼƬʱ�Ż��õ��˹���)
void OLED_CLS(void);// -- ��λ/����
void OLED_OFF(void);
void OLED_Init(void);// -- OLED����ʼ�����򣬴˺���Ӧ�ڲ�����Ļ֮ǰ���ȵ���
void OLED_P6x8Str(unsigned char x,unsigned char y,unsigned char ch[]);// -- 6x8������������ʾASCII�����С���У���̫����
void OLED_P8x16Str(unsigned char x,unsigned char y,unsigned char ch[]);// -- 8x16������������ʾASCII�룬�ǳ�����
void OLED_P16x16Ch(unsigned char x,unsigned char y,unsigned int N);// -- 16x16������������ʾ���ֵ���С���У������ø������塢�Ӵ֡���б���»��ߵ�
void Draw_BMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);// -- ��128x64���ص�BMPλͼ��ȡ�����������ֱ�Ȼ���Ƶ�codetab�У��˺������ü���
void OLED_P32x32Ch(unsigned char x,unsigned char y,unsigned int N);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowChar(u8 x,u8 y,u8 chr);
void OLED_P16x32Ch(unsigned char x,unsigned char y,unsigned int N);
void OLED_P128x48Ch(unsigned char x,unsigned char y,unsigned int N);
void OLED_P128x64Ch(unsigned char x,unsigned char y,unsigned int N);

#endif
