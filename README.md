# microvium-get-object

Attempt to return an object from C land.

What I'd like to be able to do is call a function in the host (`getResource`), which will return a populated JS Object which can be further processed in the JS script.


Based on the example [here](https://github.com/coder-mike/microvium/blob/46b9037cfdc239925ab088f74ac7223e7c251bb6/test/native/native-api.test.ts#L61).

It appears to crash in the call to [`mvm_call(vm, setProp, &propResult, *setPropArgs, 3)`](https://github.com/TobyEalden/microvium-get-object/blob/main/main.cpp#L121), and specifically at `toPropertyName` where type is `TC_REF_PROPERTY_LIST`, which isn't handled in the `switch`.

## build
```shell
git clone https://github.com/tobyealden/microvium-get-object
cd microvium-get-object
mkdir debug
cd debug
cmake ..
cmake --build .
```

## run

```shell
./microvium-host
```