#include <stdio.h>
#include <stdbool.h>

#include "../../src/image-parse/lib_image_parse.h"

int main(void)
{
    unsigned char data[] = {
        0x89,
        0x49,
        0x49,
        0x49,
        0x0D,
        0x0A,
        0x01,
        0x0A,
    };

    if (check_head(data, 8))
    {

        printf("Success");
    }
    else
    {

        printf("Failure");
    }
}