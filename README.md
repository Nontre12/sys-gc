# nx-gc

## Dependencies

- [libnx=v4.7.0](https://github.com/switchbrew/libnx/tree/v4.7.0)
- [libtesla=v1.3.3-f766e9b](https://github.com/WerWolv/libtesla/tree/f766e9b607a05e9756843cbd62b3bfb98be1646c)

## Build

### CMake
# TODO: ## Remove hardcoded devkitpro paths
```bash
cmake -B build -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain.cmake .
```

### Make
```bash
make
```