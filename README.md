# Fab Agon Emulator

An emulator for the Agon Light, Agon Light 2, and Agon Console8 8-bit computers.

## Keyboard Shortcuts

Emulator shortcuts are accessed with the *right alt* key (AltGr on some keyboards).

 * RightAlt-F - Toggle fullscreen mode
 * RightAlt-Q - Quit

## Compiling the Fab Agon Emulator (on Linux)

To make an optimised release build, run:

```
cargo build -r
```

Then you can run the emulator with either:

```
cargo run -r
```

or

```
./target/release/fab-agon-emulator
```

## Changing VDP version

By default, Fab Agon Emulator boots with 1.04 firmware. To start up
with 1.03 firmware, run:

```
./target/release/fab-agon-emulator --firmware 1.03
```

## Other command-line options

Read about other command-line options with:

```
./target/release/fab-agon-emulator --help
```

## Compiling for Windows

### To cross-compile on a Linux machine

Read [make_win64_dist.sh](./make_win64_dist.sh).

### To build on Windows (mingw)

* Install rustup from https://rustup.rs/
* rustup toolchain install stable-x86_64-pc-windows-gnu
* rustup default stable-x86_64-pc-windows-gnu
* Install make winget install GnuWin32.Make
* add C:\Program Files (x86)\GnuWin32\bin to path
* Install mingw64 from https://github.com/brechtsanders/winlibs_mingw/releases/download/13.2.0mcf-16.0.6-11.0.1-ucrt-r2/winlibs-x86_64-mcf-seh-gcc-13.2.0-llvm-16.0.6-mingw-w64ucrt-11.0.1-r2.zip
* extract to C:\mingw64 and add C:\mingw64\bin to path
* get SDL2 from https://github.com/libsdl-org/SDL/releases/download/release-2.28.3/SDL2-devel-2.28.3-mingw.zip
* extract to C:\Users\<user>\.rustup\toolchains\stable-x86_64-pc-windows-gnu
* copy SDL2.dll to the root of the project
* run `cargo build --release` in the root of the project
* manually copy built vdp*.so files from userspace-vdp to the root of the project
* run `cargo run --release` in the root of the project
