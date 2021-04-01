#include <nan.h>

using namespace v8;

void Add(const Nan::FunctionCallbackInfo<Value>& info) {
  Local<Context> context = info.GetIsolate()->GetCurrentContext();

  // 检查参数
  if (info.Length() < 2) {
    Nan::ThrowError("需传入2个数值");
    return;
  }
  if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
    Nan::ThrowTypeError("需传入数值");
  }
  // 处理参数
  double num1 = info[0]->NumberValue(context).ToChecked();
  double num2 = info[1]->NumberValue(context).ToChecked();
  // 返回结果
  info.GetReturnValue().Set(Nan::New(num1 + num2));
}

// 初始化模块
void Init(Local<Object> exports) {
  Local<Context> context = exports->CreationContext();
  exports->Set(
    context,
    Nan::New("add").ToLocalChecked(),
    Nan::New<FunctionTemplate>(Add)->GetFunction(context).ToLocalChecked()
  );
}

// 声明模块
NODE_MODULE(NODE_GYP_MODULE_NAME, Init)