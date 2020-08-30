#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <vector>
using std::vector;

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
  vector<long> getCurrUtilization();

  // TODO: Declare any necessary private members
  Processor() {}

 private:
  vector<long> currUsage;
  vector<long> prevUsage;
  float cpuPercentage;
};

#endif