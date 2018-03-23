#include "include/breakpad.h"


static google_breakpad::ExceptionHandler* exceptionHandler;
bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                  void* context,
                  bool succeeded) {
  printf("Dump path: %s\n", descriptor.path());
  return succeeded;
}

extern "C" {

  void setUpBreakpad(char *path) {
    google_breakpad::MinidumpDescriptor descriptor(path);
    exceptionHandler = new google_breakpad::ExceptionHandler(descriptor, NULL, DumpCallback, NULL, true, -1);
  }

}
