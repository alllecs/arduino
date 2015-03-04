#include <stdio.h>


// pattern for 8 X 8 LED matrix
//char array1[] = {
// 0x00, 0x00, 0x81 0x42, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00
//};

static char *blarg_xpm[] = {
"10100000",
"00010000",
"00001000",
"00000100",
"00000100",
"00001000",
"00010000",
"10100000"
};

void render(char **pic)
{
        int i;
        for (i = 0; i < 8; i++) {
                printf("%c\n", **pic);
		pic++;
        }
}

int main()
{
        render(blarg_xpm);
}
