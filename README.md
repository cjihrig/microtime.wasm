# microtime.wasm

[![Current Version](https://img.shields.io/npm/v/microtime.wasm.svg)](https://www.npmjs.org/package/microtime.wasm)
[![Build Status via Travis CI](https://travis-ci.org/cjihrig/microtime.wasm.svg?branch=master)](https://travis-ci.org/cjihrig/microtime.wasm)
![Dependencies](http://img.shields.io/david/cjihrig/microtime.wasm.svg)
[![belly-button-style](https://img.shields.io/badge/eslint-bellybutton-4B32C3.svg)](https://github.com/cjihrig/belly-button)

WebAssembly implementation of the [microtime](https://www.npmjs.com/package/microtime) module.

Note, this module is a proof of concept and likely should not be used. Emscripten implements the C function `gettimeofday(2)` as a call to JavaScript's `Date.now()`. This defeats the original purpose of `microtime`, which was to obtain better than the millisecond accuracy provided by `Date.now()`.

## Basic Usage

```javascript
'use strict';
const { now, nowDouble, nowStruct } = require('microtime.wasm');

console.log(now());
console.log(nowDouble());
console.log(nowStruct());
```

## API

`microtime.wasm` exports the following methods.

### `now()`

  - Arguments
    - None.
  - Returns
    - `result` (number) - The current time in microseconds as an integer.

### `nowDouble()`

  - Arguments
    - None.
  - Returns
    - `result` (number) - The current time in seconds as a floating point number.

### `nowStruct()`

  - Arguments
    - None.
  - Returns
    - `result` (array) - The current time as a two element array. The first element represents the number of seconds. The second element represents the number of microseconds. This matches the return value of `gettimeofday(2)`.
