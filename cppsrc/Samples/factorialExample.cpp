#include <napi.h>

namespace factorialExample {
    long factorial(int a);
    Napi::Number FactorialWrapped(const Napi::CallbackInfo& info);


    Napi::Object Init(Napi::Env env, Napi::Object exports);
}

long factorialExample::factorial(int a){
    long fact =1;
    while(a>0)
    {
        fact = fact * a;
        a--;
     }
  return fact;
}

Napi::Number factorialExample::FactorialWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::Number first = info[0].As<Napi::Number>();
    long returnValue = factorialExample::factorial(first.Int32Value());

    return Napi::Number::New(env, returnValue);
}


Napi::Object factorialExample::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("factorial", Napi::Function::New(env, factorialExample::FactorialWrapped));
    return exports;
}
