#include <nan.h>

using namespace v8;

void CreateObject(const Nan::FunctionCallbackInfo<Value>& info) {
  // 获取当前 context
  Local<Context> context = Nan::GetCurrentContext();
  // 创建新对象
  Local<Object> obj = Nan::New<Object>();
  // obj 设置属性
  obj->Set(context, Nan::New("msg").ToLocalChecked(), info[0]->ToString(context).ToLocalChecked());
  // 返回对象
  info.GetReturnValue().Set(obj);
}

// 初始化模块
void Init(Local<Object> exports) {
  // 导出函数
  Nan::SetMethod(exports, "createObject", CreateObject);
}

// 声明模块
NODE_MODULE(NODE_GYP_MODULE_NAME, Init)