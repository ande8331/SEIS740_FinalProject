#define MAX_CHAR_IN_ONE_LINE 16

#define LCD_DATA_DIR	   LPC_GPIO2->DIR
#define LCD_DATA_SET	   LPC_GPIO2->DATA
#define LCD_DATA_CLR	   LPC_GPIO2->DATA

#define LCD_CTRL_DIR	   LPC_GPIO3->DIR
#define LCD_CTRL_SET       LPC_GPIO3->DATA
#define LCD_CTRL_CLR       LPC_GPIO3->DATA

#define LCDRS	           (1 << 2)
#define LCDRW	           (1 << 1)
#define LCDEN	           (1 << 0)

#define LCD_D4 (1 << 6)
#define LCD_D5 (1 << 7)
#define LCD_D6 (1 << 8)
#define LCD_D7 (1 << 9)

#define LCD_DATA_MASK           (LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7)
#define LCD_BUSY_FLAG           LCD_D7

//#define LCD_CONTROL_MASK        0x01C00000

enum ROW_NUMBERS
{
  LINE1,
  LINE2
};

void init_lcd(void);
void lcd_putstring(unsigned char line, char *string);
void lcd_clear(void);
void lcd_backlight_on(void);
void lcd_backlight_off(void);
int lcd_gotoxy(unsigned int x, unsigned int y);
void lcd_putchar(int c);
