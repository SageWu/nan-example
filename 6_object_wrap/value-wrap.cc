#include <string>
#include "value-wrap.h"

using namespace std;

// 构造函数持久化
Nan::Persistent<Function> ValueWrap::constructor;

// 初始化
NAN_MODULE_INIT(ValueWrap::Init) {
  Local<Context> context = Nan::GetCurrentContext();
  // 进入 scope
  Nan::HandleScope scope;

  // 创建构造函数模板
  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(ValueWrap::New);
  // 设置构造函数名称
  tpl->SetClassName(Nan::New("ValueWrap").ToLocalChecked());

  // 设置内部存储槽
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // 设置实例访问器
  Nan::SetAccessor(
    tpl->InstanceTemplate(),
    Nan::New("value").ToLocalChecked(),
    ValueWrap::Getter,
    ValueWrap::Setter
  );

  // 设置原型方法
  Nan::SetPrototypeMethod(tpl, "add", ValueWrap::Add);

  // 获取运行时构造函数，持久化并返回
  Local<Function> cons = tpl->GetFunction(context).ToLocalChecked();
  constructor.Reset(cons);
  target->Set(context, Nan::New("ValueWrap").ToLocalChecked(), cons);
}

// 通过 new 调用
NAN_METHOD(ValueWrap::New) {
  Local<Context> context = Nan::GetCurrentContext();
  Nan::HandleScope scope;

  // 参数处理
  double value;
  if (info[0]->IsUndefined() || !info[0]->IsNumber()) {
    value = 0;
  } else {
    value = info[0]->NumberValue(context).ToChecked();
  }

  // js对象包装c++对象
  ValueWrap* obj = new ValueWrap(value);
  obj->Wrap(info.This());
  info.GetReturnValue().Set(info.This());
}

// 属性访问器
NAN_GETTER(ValueWrap::Getter) {
  Isolate* isolate = Isolate::GetCurrent();
  Nan::HandleScope scope;

  string key(*String::Utf8Value(isolate, property));
  
  if (key == "value") {
    ValueWrap* obj = Nan::ObjectWrap::Unwrap<ValueWrap>(info.Holder());
    info.GetReturnValue().Set(obj->_value);
  } else {
    info.GetReturnValue().SetUndefined();
  }
}

// 属性设置器
NAN_SETTER(ValueWrap::Setter) {
  Isolate* isolate = Isolate::GetCurrent();
  Local<Context> context = Nan::GetCurrentContext();
  Nan::HandleScope scope;

  string key(*String::Utf8Value(isolate, property));

  if (key == "value") {
    ValueWrap* obj = Nan::ObjectWrap::Unwrap<ValueWrap>(info.Holder());
    obj->_value = value->NumberValue(context).ToChecked();
  }
}

NAN_METHOD(ValueWrap::Add) {
  Local<Context> context = Nan::GetCurrentContext();
  Nan::HandleScope scope;

  ValueWrap* obj = Nan::ObjectWrap::Unwrap<ValueWrap>(info.Holder());
  obj->_value += info[0]->NumberValue(context).ToChecked();

  info.GetReturnValue().Set(Nan::New(obj->_value));
}

ValueWrap::ValueWrap(double value): _value(value) {

}

ValueWrap::~ValueWrap() {

}