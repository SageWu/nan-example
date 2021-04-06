#include <nan.h>
#include "value-wrap.h"

using namespace v8;

NAN_METHOD(CreateValue) {
  info.GetReturnValue().Set(ValueWrap::NewInstance(info[0]));
}

NAN_METHOD(Add) {
  Isolate* isolate = Isolate::GetCurrent();

  ValueWrap* a = Nan::ObjectWrap::Unwrap<ValueWrap>(info[0]->ToObject(isolate));
  ValueWrap* b = Nan::ObjectWrap::Unwrap<ValueWrap>(info[1]->ToObject(isolate));
  double aValue = 0, bValue = 0;
  if (a != nullptr) {
    aValue = a->getValue();
  }
  if (b != nullptr) {
    bValue = b->getValue();
  }

  info.GetReturnValue().Set(Nan::New(aValue + bValue));
}

NAN_MODULE_INIT(Init) {
  ValueWrap::Init();
  Nan::SetMethod(target, "createValue", CreateValue);
  Nan::SetMethod(target, "add", Add);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)