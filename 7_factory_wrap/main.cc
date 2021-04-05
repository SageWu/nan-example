#include <nan.h>
#include "value-wrap.h"

using namespace v8;

NAN_METHOD(CreateValue) {
  info.GetReturnValue().Set(ValueWrap::NewInstance(info[0]));
}

NAN_MODULE_INIT(Init) {
  ValueWrap::Init();
  Nan::SetMethod(target, "createValue", CreateValue);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)