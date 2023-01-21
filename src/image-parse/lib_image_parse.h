/**
 * @file lib_image_parse.h
 * @author William McGonagle
 * @date 1.20.23
 * @brief Header reference file for the Interpolated Image Interchange Parsing Library.
 *
 */

//   _    _ _   _ _ _ _            __  __      _   _               _
//  | |  | | | (_) (_) |          |  \/  |    | | | |             | |
//  | |  | | |_ _| |_| |_ _   _   | \  / | ___| |_| |__   ___   __| |___
//  | |  | | __| | | | __| | | |  | |\/| |/ _ \ __| '_ \ / _ \ / _` / __|
//  | |__| | |_| | | | |_| |_| |  | |  | |  __/ |_| | | | (_) | (_| \__ \
//   \____/ \__|_|_|_|\__|\__, |  |_|  |_|\___|\__|_| |_|\___/ \__,_|___/
//                         __/ |
//                        |___/

struct RomanFileHeader
{
    char *name;
    char *value;
};

struct RomanFile
{
    int version;
    struct RomanFileHeader *headers;
    char *body;
};

/**
 * @brief Check if a file head is a valid Interpolated Image Format head.
 * @param input An unsigned char array representing the data in the file.
 * @param size The length of the input array.
 * @returns A boolean representing if a Roman file is valid (true), or not (false).
 *
 * To determine whether a head is a valid or not, you can pass an unsigned
 * char array (which represents the file's bytes). This function then compares
 * your first eight bytes to the first eight bytes of every Roman file. This
 * function is similar to the `get_version` function, but this function disregards
 * the version number.
 */
bool check_head(unsigned char input[], size_t);

/**
 * @brief Check if a file head is a valid Interpolated Image Format head while
 * reading the version.
 * @param version An unsigned char array representing the data in the file.
 * @param input An unsigned char array representing the data in the file.
 * @param size The length of the input array.
 * @returns A boolean representing if a Roman file is valid (true), or not (false).
 *
 * TODO: Add long description to this method.
 */
bool get_version(int *version, unsigned char input[], size_t size);

/**
 * @brief Get the maximum value that a binary number can have by inputting the
 * number of digits.
 * @param x The number of digits that your specified number has.
 * @returns The maximum value that a binary number, x bits long, can be.
 *
 * This function finds the maximum value when given the binary digit count of a
 * number. This allows us to make all values relative to zero and one, rather
 * than being independent. This normalization makes it so that depth is the only
 * significant parameter effected by bit count.
 */
int max_from_bit_count(int x);

/**
 * @brief Get a value from a point stored in a char buffer.
 * @param body All of the points stored in the file via bit indexing.
 * @param index The index of the current point.
 * @param point_size The bit count of a point (sum of all channels).
 * @param value_offset Relative to each point, the channel's bit offset from left.
 * @param value_size The bit count of this channel.
 * @returns A value between 0 and 1 representing the retrieved value.
 *
 * TODO: Write a long description for this function.
 */
double get_point_value(char *body, int index, int point_size, int value_offset, int value_size);

bool process_file_chunk(char data[], size_t length, struct RomanFile *file, int *state);