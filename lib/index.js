'use strict';
// Hack to work around issue related to loading from other directories.
// See https://github.com/kripken/emscripten/issues/4542
const cwd = process.cwd();
process.chdir(__dirname);
const Wasm = require('./microtime');
process.chdir(cwd);
// End hack


function now () {
  return Wasm.Now();
}


function nowDouble () {
  return Wasm.NowDouble();
}


function nowStruct () {
  return Wasm.NowStruct();
}


module.exports = { now, nowDouble, nowStruct };
