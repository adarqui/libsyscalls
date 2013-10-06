/* syscallsjs -- adarqui && github.com/adarqui && adarq.org */

#include "syscallsjs.h"


Handle<Value> __ticks(const Arguments& args) {
	HandleScope scope;

	clock_t cl;

	cl = sysconf(_SC_CLK_TCK);

	return scope.Close(Integer::New(cl));
}

Handle<Value> __times(const Arguments& args) {
	/*
	 * json = times()
	 */
	HandleScope scope;
	clock_t cl;
	struct tms tms;

	cl = times(&tms);

	v8::Handle<v8::Object> result = v8::Object::New();
	result->Set(String::New("clock"), Integer::New(cl));
	result->Set(String::New("utime"), Integer::New(tms.tms_utime));
	result->Set(String::New("stime"), Integer::New(tms.tms_stime));
	result->Set(String::New("cutime"), Integer::New(tms.tms_cutime));
	result->Set(String::New("cstime"), Integer::New(tms.tms_cstime));
	result->Set(String::New("ticks"), Integer::New(__ticks_val));

	return result;
}


Handle<Value> __execve(const Arguments& args) {
	HandleScope scope;	
	int ret;

	char *argv[5];
	argv[0] = "/bin/ls";
	argv[1] = "-al";
	argv[2] = NULL;

	ret = execve("/bin/ls", (char **)argv, NULL);

	return scope.Close(Integer::New(ret));
}

void init(Handle<Object> exports, Handle<Object> module) {
	NODE_SET_METHOD(exports, "times", __times);
	NODE_SET_METHOD(exports, "ticks", __ticks);
	NODE_SET_METHOD(exports, "execve", __execve);

	__ticks_val = sysconf(_SC_CLK_TCK);
}


NODE_MODULE(syscallsjs, init)
