#include <assert.h>
#include <stdio.h>
#include <string.h>

extern int _base_itoa(char *dest, int v, int base);
extern void mysprintf(char *dest, const char *string, ...);
extern int chk_format(char *str);
extern int read_digit(int *num, const char *str);

void test_itoa() {
  char buf[8];
  int base;

  base = 10;
  _base_itoa(buf, 0, base);
  assert(strcmp(buf, "0") == 0);

  _base_itoa(buf, 1, base);
  assert(strcmp(buf, "1") == 0);

  _base_itoa(buf, 10, base);
  assert(strcmp(buf, "10") == 0);

  _base_itoa(buf, 12345, base);
  assert(strcmp(buf, "12345") == 0);

  base = 2;
  _base_itoa(buf, 0, base);
  assert(strcmp(buf, "0") == 0);

  _base_itoa(buf, 7, base);
  assert(strcmp(buf, "111") == 0);

  base = 16;
  _base_itoa(buf, 0, base);
  assert(strcmp(buf, "0") == 0);

  _base_itoa(buf, 9, base);
  assert(strcmp(buf, "9") == 0);

  _base_itoa(buf, 10, base);
  assert(strcmp(buf, "A") == 0);

  _base_itoa(buf, 15, base);
  assert(strcmp(buf, "F") == 0);

  _base_itoa(buf, 16, base);
  assert(strcmp(buf, "10") == 0);

  _base_itoa(buf, 255, base);
  assert(strcmp(buf, "FF") == 0);

  return;
}

void test_sprintf() {
  char buf[32];

  mysprintf(buf, "%d", 0);
  assert(strcmp(buf, "0") == 0);

  mysprintf(buf, "hoge %d %d fuga  %d ", 1, 22, 333);
  assert(strcmp(buf, "hoge 1 22 fuga  333 ") == 0);

  mysprintf(buf, "%X", 0);
  assert(strcmp(buf, "0") == 0);

  mysprintf(buf, "hex: %X", 31);
  assert(strcmp(buf, "hex: 1F") == 0);

  mysprintf(buf, "% %X", 31);
  assert(strcmp(buf, "% 1F") == 0);

  mysprintf(buf, "%3d", 2);
  assert(strcmp(buf, "  2") == 0);

  mysprintf(buf, "%04d", 11);
  assert(strcmp(buf, "0011") == 0);

  mysprintf(buf, "%04X", 10);
  assert(strcmp(buf, "000A") == 0);

  mysprintf(buf, "%02d", 1111);
  assert(strcmp(buf, "1111") == 0);

  return;
}

int main() {
  test_itoa();
  test_sprintf();
  return 0;
}
