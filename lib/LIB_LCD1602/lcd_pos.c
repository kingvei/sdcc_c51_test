#include "lib_lcd1602.h"

/*------------------------------------------------
              定位函数
x 横坐标(那个位置): 有效值 0 - 39
y 纵坐标(第几行)  : 有效值 0 - 1
------------------------------------------------*/
void lcd_pos(byte x, byte y)
{
   if (y == 0) {
      lcd_write_cmd(0x80 + x);     //表示第一行
   }
   else {
      lcd_write_cmd(0xC0 + x);     //表示第二行
   }
}