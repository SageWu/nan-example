#include <nan.h>

using namespace v8;

void GetString(const Nan::FunctionCallbackInfo<Value>& info) {
  // 返回值
  info.GetReturnValue().Set(Nan::New("hello world").ToLocalChecked());
}

// 初始化模块
void Init(Local<Object> exports) {
  Local<Context> context = exports->CreationContext();
  exports->Set(
    context,
    Nan::New("getString").ToLocalChecked(),
    Nan::New<FunctionTemplate>(GetString)->GetFunction(context).ToLocalChecked()
  );
}

// 声明模块
NODE_MODULE(NODE_GYPE_MODULE_NAME, Init)