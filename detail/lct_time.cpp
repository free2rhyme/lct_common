/**********************************************************************
 * @copyright   Copyright (C), 2017
 * @file        lct_time.cpp
 * @version     1.0
 * @date        Sep 24, 2017 11:11:08 AM
 * @author      wlc2rhyme@gmail.com
 * @brief       TODO
 *********************************************************************/

#include "lct_time.h"
#include <iomanip>
#include <cstring>

const std::string LctFormatedTime2Date(const std::string& time)
{
   if (time.size() != 19) {
      return "";
   }
   return time.substr(0, time.find_first_of(' '));
}

int32_t LctFormatedTime2IntDate(const std::string& time)
{
   if (time.size() != 19) {
      return 0;
   }
   try {
      const int32_t year  = std::stoi(time.substr(0, 4));
      const int32_t month = std::stoi(time.substr(5, 2));
      const int32_t date  = std::stoi(time.substr(8, 2));
      return year * 10000 + month * 100 + date;
   } catch (const std::exception& e) {
      return 0;
   } catch (...) {
      return 0;
   }
}


class LctCalenderTool
{
private:
   static bool IsLeapYear(int32_t year)
   {
      if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0)) {
         return true;
      } else {
         return false;
      }
   }

   static int32_t GetYear(int32_t date) 
   {
      return date / 10000;
   }

   static int32_t GetMonth(int32_t date) 
   {
      return date / 100 % 100;
   }

   static int32_t GetDay(int32_t date) 
   {
      return date % 100;
   }

public:
   static bool IsEndOfMonth(int32_t date)
   {
      if (IsLeapYear(GetYear(date))) {
         return leapMonth[GetMonth(date) - 1] == GetDay(date);
      } else {
         return month[GetMonth(date) - 1] == GetDay(date);
      }
   }

   static bool IsEndOfYear(int32_t date)
   {
      if (GetMonth(date) == 12) {
         return true;
      } else {
         return false;
      }
   }

   static int32_t GetNextDate(int32_t date)
   {
      if (IsEndOfMonth(date)) {
         if (IsEndOfYear(date)) {
            date = (date / 10000 + 1) * 10000 + 101;
         } else {
            date = (date / 100 + 1) * 100 + 1;
         }
      } else {
         date += 1;
      }
      return date;
   }

   static std::vector<int32_t> GetRangeDate(const int32_t beginDate, const int32_t endDate)
   {
      std::vector<int32_t> dates;

      if (beginDate > endDate) {
         return dates;
      }

      for (int32_t date = beginDate; date <= endDate; ) {
         dates.push_back(date);
         date = GetNextDate(date);
      }
      return dates;
   }

private:
   static const std::vector<int32_t> month;
   static const std::vector<int32_t> leapMonth;
};

const std::vector<int32_t> LctCalenderTool::month    = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::vector<int32_t> LctCalenderTool::leapMonth = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const std::vector<int32_t> RetrieveRangeDate(const int32_t beginDate, const int32_t endDate)
{
   return LctCalenderTool::GetRangeDate(beginDate, endDate);
}

//@argv:   [beginTime, endTime], seconds
const std::vector<int32_t> RetrieveRangeDate(const int64_t beginTimeSeconds, const int64_t endTimeSeconds)
{
   return RetrieveRangeDate(LctFormatedTime2IntDate(LctFormatDateTime(beginTimeSeconds * 1000)),
         LctFormatedTime2IntDate(LctFormatDateTime(endTimeSeconds * 1000)));
}
