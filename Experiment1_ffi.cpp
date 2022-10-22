
// ------------------------- Beginning of implementation -----------------------------
// WARNING: This file is auto-generated. DO NOT EDIT

#include "Experiment1_ffi.h"

static const mvm_VMExportID _vmExportsIDs[2] = {
  /*[0]*/ 65535, // runRestoreEvents
  /*[1]*/ 65534, // fibonacci
};

static mvm_Value _vmExports[2];

typedef struct ImportRecord {
  mvm_HostFunctionID id;
  mvm_TfHostFunction func;
} ImportRecord;

static mvm_TeError _intToString_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount);
static mvm_TeError _floatToString_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount);
static mvm_TeError _floatLog_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount);
static mvm_TeError _stringLog_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount);


static const ImportRecord _vmImports[4] = {
  /*[0]*/ {65535, _intToString_wrapper},
  /*[1]*/ {65534, _floatToString_wrapper},
  /*[2]*/ {65533, _floatLog_wrapper},
  /*[3]*/ {65532, _stringLog_wrapper},
};

static mvm_TeError resolveImport(mvm_HostFunctionID hostFunctionID, void* context, mvm_TfHostFunction* out_hostFunction);

Experiment1::Experiment1(): mvm::VM() {
}

void Experiment1::initialise(const uint8_t* snapshot, size_t snapshotSize) {
  mvm_TeError err;

  err = mvm_restore(&_vm, (MVM_LONG_PTR_TYPE)snapshot, snapshotSize, this, resolveImport);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  err = mvm_resolveExports(_vm, _vmExportsIDs, _vmExports, 2);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  runRestoreEvents();
}

static mvm_TeError resolveImport(mvm_HostFunctionID hostFunctionID, void* context, mvm_TfHostFunction* out_hostFunction) {
  for (int i = 0; i < 4; i++) {
    if (_vmImports[i].id == hostFunctionID) {
      *out_hostFunction = _vmImports[i].func;
      return MVM_E_SUCCESS;
    }
  }
  return MVM_E_FUNCTION_NOT_FOUND;
}


void Experiment1::runRestoreEvents() {
  mvm_Value _result;

  // Call the JS function
  mvm_TeError err = mvm_call(_vm, _vmExports[0], &_result, NULL, 0);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  // Convert/return the result
  return ;
}

static mvm_TeError _intToString_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  Experiment1* _app = (Experiment1*)mvm_getContext(_vm);

  // Prepare the arguments
  int32_t val = mvm_toInt32(_vm, _argCount >= 1 ? _args[0] : mvm_undefined);

  // Call the C function
  std::string __result = _app->intToString(val);

  // Convert the result
  *_result = mvm_newString(_vm, __result.c_str(), __result.size());

  return MVM_E_SUCCESS;
}


static mvm_TeError _floatToString_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  Experiment1* _app = (Experiment1*)mvm_getContext(_vm);

  // Prepare the arguments
  double val = mvm_toFloat64(_vm, _argCount >= 1 ? _args[0] : mvm_undefined);

  // Call the C function
  std::string __result = _app->floatToString(val);

  // Convert the result
  *_result = mvm_newString(_vm, __result.c_str(), __result.size());

  return MVM_E_SUCCESS;
}


static mvm_TeError _floatLog_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  Experiment1* _app = (Experiment1*)mvm_getContext(_vm);

  // Prepare the arguments
  double val = mvm_toFloat64(_vm, _argCount >= 1 ? _args[0] : mvm_undefined);

  // Call the C function
  _app->floatLog(val);

  // Convert the result
  *_result = mvm_undefined;

  return MVM_E_SUCCESS;
}


static mvm_TeError _stringLog_wrapper(mvm_VM* _vm, mvm_HostFunctionID hostFunctionID, mvm_Value* _result, mvm_Value* _args, uint8_t _argCount) {
  Experiment1* _app = (Experiment1*)mvm_getContext(_vm);

  // Prepare the arguments
  std::string val = std::string(mvm_toStringUtf8(_vm, _argCount >= 1 ? _args[0] : mvm_undefined, NULL));

  // Call the C function
  _app->stringLog(val);

  // Convert the result
  *_result = mvm_undefined;

  return MVM_E_SUCCESS;
}


void Experiment1::fibonacci(int32_t limit) {
  // Prepare the arguments
  mvm_Value _args[1];
  _args[0] = mvm_newInt32(_vm, limit);
  mvm_Value _result;

  // Call the JS function
  mvm_TeError err = mvm_call(_vm, _vmExports[1], &_result, _args, 1);
  if (err != MVM_E_SUCCESS) MVM_FATAL_ERROR(_vm, err);

  // Convert/return the result
  return ;
}
// ------------------------- End of implementation -----------------------------
