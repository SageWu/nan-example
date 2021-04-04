#include <nan.h>
#include "value-wrap.h"

using namespace v8;

// 初始化模块
NAN_MODULE_INIT(Init) {
  // 初始化 ValueWrap 构造函数
  ValueWrap::Init(target);
}

// 声明模块
NODE_MODULE(NODE_GYP_MODULE_NAME, Init)