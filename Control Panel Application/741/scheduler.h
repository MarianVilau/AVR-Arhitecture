#ifndef SCHEDULER_H
#define SCHEDULER_H

int scheduler_flags_management(int overflow);
void schedule_tasks_dispatcher(int _flag, int overflow);

#endif
