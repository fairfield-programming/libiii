/**
 * @file lib_image_parse.h
 * @author William McGonagle
 * @date 1.20.23
 * @brief Header reference file for the Interpolated Image Interchange Parsing Library.
 *
 */

//
//   _    _ _   _ _ _ _            __  __      _   _               _
//  | |  | | | (_) (_) |          |  \/  |    | | | |             | |
//  | |  | | |_ _| |_| |_ _   _   | \  / | ___| |_| |__   ___   __| |___
//  | |  | | __| | | | __| | | |  | |\/| |/ _ \ __| '_ \ / _ \ / _` / __|
//  | |__| | |_| | | | |_| |_| |  | |  | |  __/ |_| | | | (_) | (_| \__ \
//   \____/ \__|_|_|_|\__|\__, |  |_|  |_|\___|\__|_| |_|\___/ \__,_|___/
//                         __/ |
//                        |___/

/**
 * @brief Check if a file head is a valid Interpolated Image Format head.
 * @param input An unsigned char array representing the data in the file.
 * @param size The length of the input array.
 * @return A boolean representing if a Roman file is valid (true), or not (false).
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
 *
 * @param version An unsigned char array representing the data in the file.
 * @param input An unsigned char array representing the data in the file.
 * @param size The length of the input array.
 * @return A boolean representing if a Roman file is valid (true), or not (false).
 *
 * TODO: Add long description to this method.
 */
bool get_version(int *version, unsigned char input[], size_t size);