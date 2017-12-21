/**********************************************************************
 * @copyright   Copyright (C), 2017
 * @file        lct_common_util.h
 * @version     1.0
 * @date        May 17, 2017 11:33:14 AM
 * @author      wlc2rhyme@gmail.com
 * @brief       TODO
 *********************************************************************/
#ifndef SRC_COMMON_LCT_COMMON_UTIL_H_
#define SRC_COMMON_LCT_COMMON_UTIL_H_

#include <string>
#include "lct_common_define.h"

LCT_ERR_CODE LctVersion();

std::string Bin2Hex(const std::string& input, bool uppercase = false);

/**
 * invalid character will viewed as '0', and if the input length is even then it will be prepend a '0'
 */
std::string Hex2Bin(const std::string& input);

#endif /* SRC_COMMON_LCT_COMMON_UTIL_H_ */
