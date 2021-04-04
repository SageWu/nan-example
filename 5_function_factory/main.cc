#include <nan.h>

using namespace v8;

void Echo(const Nan::FunctionCallbackInfo<Value>& info) {
  info.GetReturnValue().Set(info[0]);
}

void CreateFunction(const Nan::FunctionCallbackInfo<Value>& info) {
  // 获取当前 context
  Local<Context> context = Nan::GetCurrentContext();
  // 创建函数模板
  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(Echo);
  // 获取运行时函数
  Local<Function> tplFn = tpl->GetFunction(context).ToLocalChecked();
  // 设置函数名称
  tplFn->SetName(Nan::New("echo").ToLocalChecked());
  // 返回函数
  info.GetReturnValue().Set(tplFn);
}

// 初始化模块
void Init(Local<Object> exports) {
  // 导出函数
  Nan::SetMethod(exports, "createFunction", CreateFunction);
}

// 声明模块
NODE_MODULE(NODE_GYP_MODULE_NAME, Init)