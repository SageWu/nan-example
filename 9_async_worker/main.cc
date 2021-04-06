#include <nan.h>
#include "async.h"

using namespace v8;

NAN_MODULE_INIT(Init) {
  Nan::SetMethod(target, "calculateAsync", CalculateAsync);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)