#include "processor.h"

#include <unistd.h>

#include <sstream>

#include "linux_parser.h"

using std::string;
using std::vector;

// TODO: Return the aggregate CPU utilization
vector<long> Processor::getCurrUtilization() {
  vector<string> util = LinuxParser::CpuUtilization();
  long userCurr, niceCurr, systemCurr, idleCurr, iowaitCurr, irqCurr,
      softirqCurr, stealCurr, total, Idle, NonIdle;

  userCurr = std::stol(util[0]);
  niceCurr = std::stol(util[1]);
  systemCurr = std::stol(util[2]);
  idleCurr = std::stol(util[3]);
  iowaitCurr = std::stol(util[4]);
  irqCurr = std::stol(util[5]);
  softirqCurr = std::stol(util[6]);
  stealCurr = std::stol(util[7]);

  Idle = idleCurr + iowaitCurr;
  NonIdle =
      userCurr + niceCurr + systemCurr + irqCurr + softirqCurr + stealCurr;
  total = Idle + NonIdle;
  vector<long> res = {total, Idle};
  return res;
}
float Processor::Utilization() {
  prevUsage = getCurrUtilization();
  sleep(1);
  currUsage = getCurrUtilization();
  long totalD = currUsage[0] - prevUsage[0];
  long idelD = currUsage[1] - prevUsage[1];
  cpuPercentage = ((float)totalD - (float)idelD) / (float)totalD;
  return cpuPercentage;
}