#include <napi.h>
#include "cpp/include/phevaluator/phevaluator.h"

Napi::Value _evaluate_cards(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 5) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsNumber() || !info[1].IsNumber()
   || !info[2].IsNumber() || !info[3].IsNumber()
   || !info[4].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  if (info.Length() == 6) {
    if (!info[5].IsNumber()) {
      Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
      return env.Null();
    }
  }
  else if (info.Length() >= 7) {
    if (!info[5].IsNumber() || !info[6].IsNumber()) {
      Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
      return env.Null();
    }
  } 

  int arg0 = info[0].As<Napi::Number>().Int32Value();
  int arg1 = info[1].As<Napi::Number>().Int32Value();
  int arg2 = info[2].As<Napi::Number>().Int32Value();
  int arg3 = info[3].As<Napi::Number>().Int32Value();
  int arg4 = info[4].As<Napi::Number>().Int32Value();

  if (info.Length() == 6) {
    int arg5 = info[5].As<Napi::Number>().Int32Value();
    return Napi::Number::New(env, evaluate_6cards(arg0, arg1, arg2, arg3, arg4, arg5));
  }
  else if (info.Length() >= 7) {
    int arg5 = info[5].As<Napi::Number>().Int32Value();
    int arg6 = info[6].As<Napi::Number>().Int32Value();
    return Napi::Number::New(env, evaluate_7cards(arg0, arg1, arg2, arg3, arg4, arg5, arg6));
  } 

  return Napi::Number::New(env, evaluate_5cards(arg0, arg1, arg2, arg3, arg4));
}

Napi::Value _evaluate_omaha_cards(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 9) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsNumber() || !info[1].IsNumber()
   || !info[2].IsNumber() || !info[3].IsNumber()
   || !info[4].IsNumber() || !info[5].IsNumber()
   || !info[6].IsNumber() || !info[7].IsNumber()
   || !info[8].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  int arg0 = info[0].As<Napi::Number>().Int32Value();
  int arg1 = info[1].As<Napi::Number>().Int32Value();
  int arg2 = info[2].As<Napi::Number>().Int32Value();
  int arg3 = info[3].As<Napi::Number>().Int32Value();
  int arg4 = info[4].As<Napi::Number>().Int32Value();
  int arg5 = info[5].As<Napi::Number>().Int32Value();
  int arg6 = info[6].As<Napi::Number>().Int32Value();
  int arg7 = info[7].As<Napi::Number>().Int32Value();
  int arg8 = info[8].As<Napi::Number>().Int32Value();
  
  return Napi::Number::New(env, evaluate_omaha_cards(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8));
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "evaluate_cards"), Napi::Function::New(env, _evaluate_cards));
  exports.Set(Napi::String::New(env, "evaluate_omaha_cards"), Napi::Function::New(env, _evaluate_omaha_cards));
  return exports;
}

NODE_API_MODULE(addon, Init)