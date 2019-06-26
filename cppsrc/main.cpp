#include <napi.h>
namespace factorialExample {
    long factorial(int a);
    Napi::Number FactorialWrapped(const Napi::CallbackInfo& info);

    Napi::Object Init(Napi::Env env, Napi::Object exports);

}

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  factorialExample::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
