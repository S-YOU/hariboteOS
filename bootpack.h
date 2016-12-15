struct BOOTINFO {
  char cyls;
  char leds;
  char vmode;
  char reserve;
  short scrnx;
  short scrny;
  char *vram;
};
#define ADR_BOOTINFO 0x00000ff0

extern void io_hlt(void);
extern void io_cli(void);
extern void io_sti(void);
extern void io_stihlt(void);
extern int io_in8(int port);
extern void io_out8(int port, int data);
extern int io_load_eflags(void);
extern void io_store_eflags(int eflags);
extern void load_gdtr(int limit, int addr);
extern void load_idtr(int limit, int addr);
void asm_inthandler21(void);
void asm_inthandler27(void);
void asm_inthandler2c(void);

extern int myitoa(char *dest, int v);
void mysprintf(char *dest, const char *string, ...);

struct FIFO8 {
  unsigned char *buf;
  int p, q, size, free, flags;
};
void fifo8_init(struct FIFO8 *fifo, int size, unsigned char *buf);
int fifo8_put(struct FIFO8 *fifo, unsigned char data);
int fifo8_get(struct FIFO8 *fifo);
int fifo8_status(struct FIFO8 *fifo);

#define COL8_000000 0
#define COL8_FF0000 1
#define COL8_00FF00 2
#define COL8_FFFF00 3
#define COL8_0000FF 4
#define COL8_FF00FF 5
#define COL8_00FFFF 6
#define COL8_FFFFFF 7
#define COL8_C6C6C6 8
#define COL8_840000 9
#define COL8_008400 10
#define COL8_848400 11
#define COL8_000084 12
#define COL8_840084 13
#define COL8_008484 14
#define COL8_848484 15

void init_palette(void);
void set_palette(int, int, unsigned char *);
void boxfill8(unsigned char *, int, unsigned char, int, int, int, int);
void init_screen(char *, int, int);
void putfont8(char *, int, int, int, char, char *);
void putfonts8_asc(char *, int, int, int, char, unsigned char *);
void init_mouse_cursor8(char *, char);
void putblock8_8(char *, int, int, int, int, int, char *, int);

struct SEGMENT_DESCRIPTOR {
  short limit_low;
  short base_low;
  char base_mid;
  char access_right;
  char limit_high;
  char base_high;
};

struct GATE_DESCRIPTOR {
  short offset_low;
  short selector;
  char dw_count;
  char access_right;
  short offset_high;
};

void init_gdtidt(void);
void set_gatedesc(struct GATE_DESCRIPTOR *, int, int, int);
void set_segmdesc(struct SEGMENT_DESCRIPTOR *, unsigned int, int, int);
#define ADR_IDT 0x0026f800
#define LIMIT_IDT 0x000007ff
#define ADR_GDT 0x00270000
#define LIMIT_GDT 0x0000ffff
#define ADR_BOTPAK 0x00280000
#define LIMIT_BOTPAK 0x0007ffff
#define AR_DATA32_RW 0x4092
#define AR_CODE32_ER 0x409a
#define AR_INTGATE32 0x008e

void init_pic(void);
#define PIC0_ICW1 0x0020
#define PIC0_OCW2 0x0020
#define PIC0_IMR 0x0021
#define PIC0_ICW2 0x0021
#define PIC0_ICW3 0x0021
#define PIC0_ICW4 0x0021
#define PIC1_ICW1 0x00a0
#define PIC1_OCW2 0x00a0
#define PIC1_IMR 0x00a1
#define PIC1_ICW2 0x00a1
#define PIC1_ICW3 0x00a1
#define PIC1_ICW4 0x00a1
