# Load PNG SDL3 (C)

**Demo in the browser:** https://8observer8.github.io/examples/sdl3/load-png-sdl-3.3.4-c

**EXE for Windows 10, 64-bit:** [load-png-sdl-3.3.4-c-exe.zip](https://www.dropbox.com/scl/fi/l831p9ca3wx0qjps79sx4/load-png-sdl-3.3.4-c-exe.zip?rlkey=n3c7no0nl34q8dojinx6q66e7&st=vsys12ah&raw=1)
- Zip size: 1.36 MB
- Unzipped: 3.1 MB

---

## File Sizes

**WASM (built with Emscripten 4.0.15):**

- `index.html` — 879 bytes
- `app.js` — 184 KB
- `app.wasm` — 1 MB
- **Total:** 1.18 MB

**EXE (built with MinGW GCC 11.2):**

- EXE — 80.5 KB
- `SDL3.dll` (v3.3.4) — 2.65 MB
- `SDL3_image.dll`(v3.2.4) — 282 KB
- Assets ([crate.png](https://opengameart.org/content/crate-5)) — 102 KB
- **Total:** 3.1 MB

---

## Tools to Build the EXE

- [MinGW GCC 11.2](https://github.com/brechtsanders/winlibs_mingw/releases/download/11.2.0-14.0.0-9.0.0-ucrt-r7/winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64ucrt-9.0.0-r7.zip) (zip - 178 MB, unzipped - 671 MB)
- [SDL3-3.3.4-win32-x64.zip](https://www.dropbox.com/scl/fi/6zojft1cdj2kzpljj2j5c/SDL3-3.3.4-win32-x64.zip?rlkey=lxvf4lzsfiv846ajpnic49s5j&st=m0alnzdr&raw=1) (zip - 1.09 MB, unzipped - 2.65 MB)
- [SDL3-devel-3.3.4-mingw.zip](https://www.dropbox.com/scl/fi/njib4pzrkuplxkomqihhg/SDL3-devel-3.3.4-mingw.zip?rlkey=69bhrsjx2w4j4ca1rc5arfbq5&st=uiymyff4&raw=1) (zip - 2.63 MB, unzipped - 9.42 MB)
- [SDL3_image-3.2.4-win32-x64.zip](https://www.dropbox.com/scl/fi/6br8dwt0epxjluo31byu7/SDL3_image-3.2.4-win32-x64.zip?rlkey=owdh9b8exqs1dfu0uhxrrmays&st=hck30ch6&raw=1) (zip - 5.01 MB, unzipped - 14.4 MB)
- [SDL3_image-devel-3.2.4-mingw.zip](https://www.dropbox.com/scl/fi/h3i10xl6i1xxj58ism31w/SDL3_image-devel-3.2.4-mingw.zip?rlkey=yqu8lsmxwmxm9j7zk3euc91k9&st=hu1h066t&raw=1) (zip - 182 KB, unzipped - 481 KB)

---

## Tools to Build WebAssembly

- [Emscripten 4.0.15](https://emscripten.org/docs/getting_started/downloads.html) (1.82 GB)
- [SDL3-devel-3.3.4-wasm.zip](https://www.dropbox.com/scl/fi/ogokwxxc64f0lgf01q9oe/SDL3-devel-3.3.4-wasm.zip?rlkey=p2ggy9ynptdlbroi9ixaj1d2c&st=b5r23j5h&raw=1) (zip - 1.21 MB, unzipped - 5.2 MB)
- [SDL3_image-devel-3.2.4-wasm](https://www.dropbox.com/scl/fi/j4hk1dsqv56xv3sn249qo/SDL3_image-devel-3.2.4-wasm.zip?rlkey=j4um83ndc0m1rz7pewb2yj359&st=1ro8mqro&raw=1) (zip - 357 KB, unzipped - 848 KB)

---

## How to Build EXE (Windows)

- Add [MinGW GCC 11.2](https://github.com/brechtsanders/winlibs_mingw/releases/download/11.2.0-14.0.0-9.0.0-ucrt-r7/winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64ucrt-9.0.0-r7.zip) `bin` folder to your `PATH`.
- Add [SDL3-3.3.4-win32-x64.zip](https://www.dropbox.com/scl/fi/6zojft1cdj2kzpljj2j5c/SDL3-3.3.4-win32-x64.zip?rlkey=lxvf4lzsfiv846ajpnic49s5j&st=m0alnzdr&raw=1) folder to your `PATH`.
- Add [SDL3_image-3.2.4-win32-x64.zip](https://www.dropbox.com/scl/fi/ibgwgt8o7s3r139zcf135/SDL3_image-3.2.4-win32-x64.zip?rlkey=ffepi1ra4xg87x0we2fyzptlh&st=vv5vvj25&raw=1) folder to your `PATH`.
- Configure paths in `config-web.bat` for your SDL3 libraries.
- From the project root, run:

```bat
config-exe
build-exe
run-exe
```

## How to Build WebAssembly

1. Set up [Emscripten 4.0.15](https://emscripten.org/docs/getting_started/downloads.html) and Node.js
2. Install http-server globally:

```bat
npm i http-server -g
```

3. Configure paths in `config-web.bat` for your SDL3 libraries.
4. From the project root, run:

```bat
config-web
build-web
http-server -c-1
```

5. Open your browser and go to http://localhost:8080 to run the app locally.

> Note: You can also run the WASM app on Android via Wi-Fi using http-server. After starting the server, it will show local URL addresses — just type one into your mobile browser.

This example uses the following free image: https://opengameart.org/content/crate-5
