#include "format.h"

#include <time.h>
#include <unistd.h>

#include <string>

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  long minutes, hours;
  minutes = seconds / 60;
  hours = minutes / 60;
  return to_string(hours) + ":" + to_string(minutes % 60) + ":" +
         to_string(seconds % 60);
}