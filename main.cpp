#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <string>

#include "microvium.h"

#define IMPORT_PRINT 1
#define IMPORT_GET_RESOURCE 2

mvm_TeError print(mvm_VM *vm, mvm_HostFunctionID funcID, mvm_Value *result,
                  mvm_Value *args, uint8_t argCount);

mvm_TeError getResource(mvm_VM *vm, mvm_HostFunctionID funcID,
                        mvm_Value *mvmResult, mvm_Value *args,
                        uint8_t argCount);

mvm_TeError resolveImport(mvm_HostFunctionID id, void *,
                          mvm_TfHostFunction *out);

const mvm_VMExportID MAIN = 1234;
const mvm_VMExportID CREATE_OBJECT = 1;
const mvm_VMExportID SET_PROP = 2;

mvm_Value mainEntry;
mvm_Value createObject;
mvm_Value setProp;

int main(int argc, char **argv) {
    mvm_TeError err;
    mvm_VM *vm;
    uint8_t *snapshot;
    mvm_Value callResult;
    FILE *snapshotFile;
    long snapshotSize;

    // Read the bytecode from file
    snapshotFile =
            fopen("../get-object.mvm-bc", "rb");
    fseek(snapshotFile, 0L, SEEK_END);
    snapshotSize = ftell(snapshotFile);
    rewind(snapshotFile);
    snapshot = (uint8_t *) malloc(snapshotSize);
    fread(snapshot, 1, snapshotSize, snapshotFile);
    fclose(snapshotFile);

    // Restore the VM from the snapshot
    if ((err = mvm_restore(&vm, snapshot, snapshotSize, NULL, resolveImport)) != MVM_E_SUCCESS) {
        std::cout << "mvm failure loading snapshot: " << err;
        return err;
    }

    // Find the "main" function exported by the VM
    if ((err = mvm_resolveExports(vm, &MAIN, &mainEntry, 1)) != MVM_E_SUCCESS) {
        std::cout << "mvm failure resolving main entry point: " << err;
        return err;
    }

    if ((err = mvm_resolveExports(vm, &CREATE_OBJECT, &createObject, 1)) !=
        MVM_E_SUCCESS) {
        std::cout << "mvm failure resolving createObject entry point: " << err;
        return err;
    }

    if ((err = mvm_resolveExports(vm, &SET_PROP, &setProp, 1)) != MVM_E_SUCCESS) {
        std::cout << "mvm failure resolving setProp entry point: " << err;
        return err;
    }

    if ((err = mvm_call(vm, mainEntry, &callResult, NULL, 0)) != MVM_E_SUCCESS) {
        std::cout << "mvm failure calling main: " << err;
        return err;
    }

    mvm_runGC(vm, true);

    return err;
}

mvm_TeError resolveImport(mvm_HostFunctionID funcID, void *context,
                          mvm_TfHostFunction *out) {
    if (funcID == IMPORT_PRINT) {
        *out = print;
        return MVM_E_SUCCESS;
    } else if (funcID == IMPORT_GET_RESOURCE) {
        *out = getResource;
        return MVM_E_SUCCESS;
    }

    return MVM_E_UNRESOLVED_IMPORT;
}

mvm_TeError print(mvm_VM *vm, mvm_HostFunctionID funcID, mvm_Value *result,
                  mvm_Value *args, uint8_t argCount) {
    assert(argCount == 1);
    std::cout << "MVM result: " << mvm_toStringUtf8(vm, args[0], NULL);
    return MVM_E_SUCCESS;
}

mvm_TeError getResource(mvm_VM *vm, mvm_HostFunctionID funcId,
                        mvm_Value *resourceObj, mvm_Value *args,
                        uint8_t argCount) {
    std::string resourceId = mvm_toStringUtf8(vm, args[0], NULL);
    std::cout << "resourceId: " << resourceId << std::endl;

    mvm_TeError err;

    if ((err = mvm_call(vm, createObject, resourceObj, NULL, 0)) !=
        MVM_E_SUCCESS) {
        std::cout << "mvm failure calling createObject: " << err << std::endl;
        return err;
    }

    mvm_Value propName = mvm_newString(vm, "name", 4);
    mvm_Value propValue = mvm_newString(vm, "Toby", 4);

    mvm_Value setPropArgs[3] = {*resourceObj, propName, propValue};

    mvm_Value propResult;
    if ((err = mvm_call(vm, setProp, &propResult, setPropArgs, 3)) !=
        MVM_E_SUCCESS) {
        std::cout << "mvm failure calling setProp: " << err << std::endl;
        return err;
    }

    return err;
}