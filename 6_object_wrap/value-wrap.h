#ifndef VALUE_WRAP_H
#define VALUE_WRAP_H

#include <nan.h>

using namespace v8;

class ValueWrap: public Nan::ObjectWrap {
public:
  static NAN_MODULE_INIT(Init);

  ValueWrap(double value);
  ~ValueWrap();

private:
  static Nan::Persistent<Function> constructor;
  static NAN_METHOD(New);
  static NAN_GETTER(Getter);
  static NAN_SETTER(Setter);
  static NAN_METHOD(Add);

  double _value;
};

#endif