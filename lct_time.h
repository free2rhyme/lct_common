/**********************************************************************
 * @copyright   Copyright (C), 2017
 * @file        lct_time.h
 * @version     1.0
 * @date        Sep 24, 2017 10:02:08 AM
 * @author      wlc2rhyme@gmail.com
 * @brief       TODO
 *********************************************************************/
#ifndef SRC_COMMON_LCT_TIME_H_
#define SRC_COMMON_LCT_TIME_H_

#include "lct_common_define.h"

//milli seconds sice epoch
int64_t LctCurrentDateTimeValue();

//@return: YYYY-MM-DD HH:MM:SS
std::string LctFormatDateTime(const int64_t& millisecondsSinceEpoch);

//@return: YYYY-MM-DD HH:MM:SS +8000 UTC
std::string LctFormatUtcDateTime(const int64_t& millisecondsSinceEpoch);

//@return: HH:MM:SS
std::string LctFormatTime(const int64_t& millisecondsSinceEpoch);

//@return: YYYY-MM-DD HH:MM:SS
const std::string LctCurrentDateTime();

//@return: HH:MM:SS
const std::string LctCurrentTime();

//@return: YYYYMMDD
const std::string LctCurrentDate();

//@return: YYMMDD
const std::string LctCurrentDay();

//@return: YYYY-MM-DD HH:MM:SS +8000 UTC
const std::string LctCurrentUtcTime();

//@argv:   YYYY-MM-DD HH:MM:SS
//@return: YYYY-MM-DD
const std::string LctFormatedTime2Date(const std::string& time);

//@argv:   YYYY-MM-DD HH:MM:SS
//@return: YYYYMMDD
int32_t LctFormatedTime2IntDate(const std::string& time);

//@argv:   YYYY-MM-DD HH:MM:SS.000000+0800
//@return: UTC seconds
int64_t LctUtcTime2Seconds(const std::string& time);

//@return:seconds
int64_t IvaLocal2UtcTimezoneGap();

//@argv:   YYYYMMDD, [beginDate , endDate]
const std::vector<int32_t> RetrieveRangeDate(const int32_t beginDate, const int32_t endDate);

//@argv:   [beginTime, endTime], seconds
const std::vector<int32_t> RetrieveRangeDate(const int64_t beginTimeSeconds, const int64_t endTimeSeconds);

#include "detail/lct_time.inl"

#endif /* SRC_COMMON_LCT_TIME_H_ */
