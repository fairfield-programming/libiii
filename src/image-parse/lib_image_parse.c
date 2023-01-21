#include <stdio.h>
#include <stdbool.h>

bool check_head(unsigned char input[], size_t size)
{

    // Check if there are at least eight bytes
    if (size < 8)
        return false;

    // Binary Byte– Indicates File is Binary
    if (input[0] != 0x89)
        return false;

    // First Letter of File Type (III)
    if (input[1] != 'I')
        return false;

    // Second Letter of File Type (III)
    if (input[2] != 'I')
        return false;

    // Third Letter of File Type (III)
    if (input[3] != 'I')
        return false;

    // Carriage Return
    if (input[4] != 0x0D)
        return false;

    // Line Feed
    if (input[5] != 0x0A)
        return false;

    // Version Number
    int version = input[6];

    // Line Feed
    if (input[7] != 0x0A)
        return false;

    // All conditions are satisfied
    return true;
}

bool get_version(int *version, unsigned char input[], size_t size)
{

    // Check if there are at least eight bytes
    if (size < 8)
        return false;

    // Binary Byte– Indicates File is Binary
    if (input[0] != 0x89)
        return false;

    // First Letter of File Type (III)
    if (input[1] != 'I')
        return false;

    // Second Letter of File Type (III)
    if (input[2] != 'I')
        return false;

    // Third Letter of File Type (III)
    if (input[3] != 'I')
        return false;

    // Carriage Return
    if (input[4] != 0x0D)
        return false;

    // Line Feed
    if (input[5] != 0x0A)
        return false;

    // Version Number
    *version = input[6];

    // Line Feed
    if (input[7] != 0x0A)
        return false;

    // All conditions are satisfied
    return true;
}

int max_from_bit_count(int x)
{
    return (0b00000001 << x) - 1;
}

double get_point_value(char *body, int index, int point_size, int value_offset, int value_size)
{

    // Calculate Where the Point Value Starts and Ends
    int start_bit = index * point_size + value_offset;
    int end_bit = index * point_size + value_offset + value_size;

    // Find the Maximum Value at the Point
    unsigned int max_value = max_from_bit_count(value_size);
    unsigned int true_value = 0;

    // TODO: Optimize bit grabbing, maybe if getting entire byte, just grab the byte?
    // NOTE: We Use Little Endian for Channels

    for (size_t i = start_bit; i < end_bit; i++)
    {

        // Find the Current Byte and Bit Index
        int cur_byte = i / sizeof(char);
        int cur_bit = i % sizeof(char);

        // Create a mask for a single bit, and mask it
        int mask_shift = (sizeof(char) - cur_bit);
        char mask = 0b00000001 << mask_shift;
        char single_bit = (body[cur_byte] && mask);

        // Shift back over the bit and convert it to an int
        unsigned int cur_val = (single_bit >> mask_shift) << (value_size - i);

        // Add bit to the total
        true_value += cur_val;
    }

    return ((double)true_value) / ((double)max_value);
}
