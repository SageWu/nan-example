#include "async.h"

using Nan::AsyncQueueWorker;
using Nan::AsyncWorker;
using Nan::Callback;

class DoubleWorker: public AsyncWorker {
public:
  DoubleWorker(double num, Callback* cb): AsyncWorker(cb), _num(num) {
  }

  ~DoubleWorker() {}

  // 在 worker 线程中执行，不可访问 v8，只可访问 this
  void Execute() {
    this->_res = this->_num * this->_num;
  }

  // 通过 event loop 调度执行
  void HandleOKCallback() {
    Nan::HandleScope scope;

    const int argc = 2;
    Local<Value> argv[argc] = { Nan::Null(), Nan::New(this->_res) };
    this->callback->Call(argc, argv);
  }

private:
  double _num;
  double _res;
};

NAN_METHOD(CalculateAsync) {
  double num = Nan::To<double>(info[0]).ToChecked();
  // 包裹回调函数
  Callback* cb = new Callback(Nan::To<Function>(info[1]).ToLocalChecked());
  // 将工作实例放入队列中，等待执行
  AsyncQueueWorker(new DoubleWorker(num, cb));
}