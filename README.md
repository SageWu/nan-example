## Scopes
### Nan::EscapableHandleScope
和`Nan::HandleScope`类似，但是当在函数内部创建的`handle`需返回时，则需使用`EscapableHandleScope`。