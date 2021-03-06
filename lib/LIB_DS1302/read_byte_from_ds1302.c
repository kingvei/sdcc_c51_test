#include "lib_ds1302.h"

/*****************************************************
函数功能：从DS1302 读一个字节
***************************************************/
byte read_byte_from_ds1302(void)
{
   byte i, dat=0;

   for (i = 0; i < 8; i++) {
       dat >>= 1;
       if (SDA)
           dat |= 0x80;
       SCK = 1;     //将SCLK置于高电平，为下降沿读出做准备
       delaynus(2); //稍微等待，使硬件做好准备
       SCK = 0;     //拉低SCLK，形成脉冲下降沿
       delaynus(2); //稍微等待，使硬件做好准备
   }

   return dat;
}
