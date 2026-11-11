#pragma once
#include <Arduino.h>

class Clock {
 public:
  int year = 2000, month = 1, day = 1;
  int hours = 0, minutes = 0, seconds = 0;

  void set(int y, int mo, int d, int h, int mi, int s) {
    year = y; month = mo; day = d;
    hours = h; minutes = mi; seconds = s;
    _last = millis();
  }

  void update() {
    unsigned long now = millis();
    while (now - _last >= 1000) {
      _last += 1000;
      tick();
    }
  }

  static bool isLeap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
  }

  static int daysInMonth(int m, int y) {
    static const int d[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (m == 2 && isLeap(y)) ? 29 : d[m - 1];
  }

  // "YYYY-MM-DD HH:MM:SS"
  String toString() const {
    char buf[20];
    snprintf(buf, sizeof(buf), "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hours, minutes, seconds);
    return String(buf);
  }

 private:
  unsigned long _last = 0;

  void tick() {
    if (++seconds < 60) return;
    seconds = 0;
    if (++minutes < 60) return;
    minutes = 0;
    if (++hours < 24) return;
    hours = 0;
    if (++day <= daysInMonth(month, year)) return;
    day = 1;
    if (++month <= 12) return;
    month = 1;
    year++;
  }
};

// One shared instance for every file that includes this header.
inline Clock rtc;
