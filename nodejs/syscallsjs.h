/* syscallsjs -- adarqui */
#ifndef SYSCALLSJS_H
#define SYSCALLSJS_H

#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <node.h>
#include <node_buffer.h>
#include <node_version.h>
#include <v8.h>
#include <time.h>
#include <unistd.h>
#include <sys/times.h>

#include <errno.h>

using namespace v8;
using namespace node;
using namespace std;

extern int errno;

clock_t __ticks_val;

void init(Handle<Object> exports, Handle<Object> module);
Handle<Value> __times(const Arguments&);
Handle<Value> __ticks(const Arguments&);
Handle<Value> __execve(const Arguments&);

#endif
