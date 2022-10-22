# microvium-get-object

Experiment with `MVM_PORT_INT32_OVERFLOW_CHECKS`, when set to `0` floating values appear to overflow.

Changing `MVM_PORT_INT32_OVERFLOW_CHECKS` to 1 (in `microvium_port.h`) fixes this.

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
./exp1
```
