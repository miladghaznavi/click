/*
 * readhandler.{cc,hh} -- element that dumps output of read handlers
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include "readhandler.hh"
#include "../standard/scheduleinfo.hh"
  
int
ReadHandlerCaller::initialize(ErrorHandler *errh)
{
  ScheduleInfo::join_scheduler(this, errh);
  return 0;
}
  
void
ReadHandlerCaller::run_scheduled()
{
  extern int call_read_handlers();
  call_read_handlers();
  reschedule();
}

EXPORT_ELEMENT(ReadHandlerCaller)

