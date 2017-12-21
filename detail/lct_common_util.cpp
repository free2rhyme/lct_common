/**********************************************************************
 * @copyright   Copyright (C), 2017
 * @file        lct_common_util.cpp
 * @version     1.0
 * @date        May 17, 2017 11:33:26 AM
 * @author      wlc2rhyme@gmail.com
 * @brief       TODO
 *********************************************************************/

#include "lct_common_util.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include "version.h"

LCT_ERR_CODE LctVersion()
{
   std::stringstream ss;
   ss << BRANCH_MAJOR_VERSION << '.';
   ss << BRANCH_MINOR_VERSION << '.';
   ss << BRANCH_PATCH_NUMBER  << '.';
   ss << BRANCH_BUILD_NUMBER  << "\n\n";
   std::cout << ss.str();
   return LCT_VERSION_INFO;
}

std::string Bin2Hex(const std::string& input, bool uppercase)
{
   const char *hex;
   if (uppercase) {
      hex = "0123456789ABCDEF";
   } else {
      hex = "0123456789abcdef";
   }

   std::string res;
   res.reserve(input.size() * 2);
   for(unsigned i = 0; i < input.length(); i++) {
      const unsigned char& c = (unsigned char)input[i];
      res += hex[c >> 4];
      res += hex[c & 0xf];
   }

   return res;
}

std::string Hex2Bin(const std::string& input)
{
   std::string src = input;
   if (0 < (src.length() % 2)) {
      src = "0" + src;
   }

   std::string res;
   res.reserve(src.size()/2);

   for(unsigned i = 0; i < src.length(); i += 2) {
      unsigned char r = 0;
      {
         unsigned char c = (unsigned char)src[i];
         if ('0' <= c && '9' >= c) {
            r |= (c - '0');
         } else if ('a' <= c && 'f' >= c) {
            r |= 10 + (c - 'a');
         } else if ('A' <= c && 'F' >= c) {
            r |= 10 + (c - 'A');
         }
      }

      r = r << 4;

      {
         unsigned char c = (unsigned char)src[i+1];
         if ('0' <= c && '9' >= c) {
            r |= (c - '0');
         } else if ('a' <= c && 'f' >= c) {
            r |= 10 + (c - 'a');
         } else if ('A' <= c && 'F' >= c) {
            r |= 10 + (c - 'A');
         }
      }

      res += r;
   }

   return res;
}

