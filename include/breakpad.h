#include <jni.h>
#include <stdio.h>
#include "client/linux/handler/exception_handler.h"
#include "client/linux/handler/minidump_descriptor.h"
bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                  void* context,
                  bool succeeded);

extern "C" {
	void setUpBreakpad(char *path);
}