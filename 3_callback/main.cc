#include <nan.h>

using namespace v8;

void CallFn(const Nan::FunctionCallbackInfo<Value>& info) {
  // 获取当前context
  Local<Context> context = Nan::GetCurrentContext();
  // 获取回调
  Local<Function> cb = info[0].As<Function>();
  // 构造调用参数
  const int argc = 1;
  Local<Value> argv[argc] = { Nan::New("calling function").ToLocalChecked() };
  // 调用回调
  cb->Call(context, context->Global(), argc, argv);
}

// 初始化模块
void Init(Local<Object> exports) {
  // 导出函数
  Nan::SetMethod(exports, "callFn", CallFn);
}

// 声明模块
NODE_MODULE(NODE_GYP_MODULE_NAME, Init)