#!/bin/sh

echo "Build wasm app .."
/opt/wasi-sdk/bin/clang -O3 \
        -z stack-size=128 -Wl,--initial-memory=65536 \
        -o hello_world.wasm main.c \
        -Wl,--export=main -Wl,--export=__main_argc_argv \
        -Wl,--export=__data_end -Wl,--export=__heap_base \
        -Wl,--strip-all,--no-entry \
        -Wl,--allow-undefined \
        -nostdlib \

echo "Binary dump Wasm file to hello_world_wasm_c.h .."
../../test-tools/binarydump-tool/build/binarydump \
        -o hello_world_wasm_c.h \
        -n wasm_application_file \
           hello_world.wasm


echo "Copying hello_world_wasm_c.h to Renesas Hello World project at src/hello_world_wasm_c.h .."
cp -f hello_world_wasm_c.h \
    ../../R9A02G021_WAMR_Interp_HelloWorld/src/hello_world_wasm_c.h

echo "Done"
