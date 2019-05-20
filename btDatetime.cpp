  /* 
   * g++  btDatetime.cpp -o bin/btDatetime -lboost_date_time
   */

  #include <boost/date_time/gregorian/gregorian.hpp>
  #include <iostream>
  #include <string>

  int
  main()
  {

    using namespace boost::gregorian;

    try {
      // ISO 8601 https://en.wikipedia.org/wiki/ISO_8601
      std::string s("2001-10-9"); //2001-October-09
      date d(from_simple_string(s));
      std::cout << to_simple_string(d) << std::endl;

      //Read ISO Standard(CCYYMMDD) and output ISO Extended
      std::string ud("20011009"); //2001-Oct-09
      date d1(from_undelimited_string(ud));
      std::cout << to_iso_extended_string(d1) << std::endl;

      //Output Tuesday October 9, 2001
      date::ymd_type ymd = d1.year_month_day();
      greg_weekday wd = d1.day_of_week();
      std::cout << wd.as_long_string() << " "
                << ymd.month.as_long_string() << " "
                << ymd.day << ", " << ymd.year
                << std::endl;

    } catch(std::exception& e) {
      std::cout << "  Exception: " <<  e.what() << std::endl;
    }

    return 0;
  }
