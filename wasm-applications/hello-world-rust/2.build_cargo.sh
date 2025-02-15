#!/bin/sh

rm -rf target

export WASI_SDK_PATH=/opt/wasi-sdk/
rustup target add wasm32-wasip1

# Config in .cargo/config.toml
#rustflags = [
#  "-C", "link-self-contained=no",
#  "-C", "link-arg=--initial-memory=65536",
#  "-C", "link-arg=-zstack-size=128",
#  "-C", "link-arg=--export=__data_end",
#  "-C", "link-arg=--strip-all",
#  "-C", "link-args=--no-entry",
#]

# Build release
echo "Build wasm app from cargo build .."
cargo build --release --target wasm32-wasip1

# Binary dump using binarydump-tool from WAMR
echo "Binary dump Wasm file to hello_world_wasm_rust.h .."
../../test-tools/binarydump-tool/build/binarydump \
        -o hello_world_wasm_cargobuild.h \
        -n wasm_application_file \
           target/wasm32-wasip1/release/hello-world-rust.wasm

# Copy Wasm (.h file) to Renesas project
echo "Copying hello_world_wasm_cargobuild.h to Renesas Hello World project at src/hello_world_wasm_rust.h .."
cp -f hello_world_wasm_cargobuild.h \
    ../../R9A02G021_WAMR_Interp_HelloWorld/src/hello_world_wasm_rust.h

echo "Done"
