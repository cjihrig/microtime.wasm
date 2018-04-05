#include <emscripten.h>
#include <emscripten/bind.h>
#include <errno.h>
#include <sys/time.h>

using namespace emscripten;


double Now(void) {
  timeval t;
  int r = gettimeofday(&t, NULL);

  if (r < 0) {
    EM_ASM_({
      const err = new Error('gettimeofday() failed');
      err.errno = $0;
      throw err;
    }, errno);
    return 0;
  }

  return (t.tv_sec * 1000000.0) + t.tv_usec;
}


double NowDouble(void) {
  timeval t;
  int r = gettimeofday(&t, NULL);

  if (r < 0) {
    EM_ASM_({
      const err = new Error('gettimeofday() failed');
      err.errno = $0;
      throw err;
    }, errno);
    return 0;
  }

  return t.tv_sec + (t.tv_usec * 0.000001);
}


val NowStruct(void) {
  timeval t;
  int r = gettimeofday(&t, NULL);

  if (r < 0) {
    EM_ASM_({
      const err = new Error('gettimeofday() failed');
      err.errno = $0;
      throw err;
    }, errno);
    return val::null();
  }

  val result = val::array();
  result.set(0, (double) t.tv_sec);
  result.set(1, (double) t.tv_usec);
  return result;
}


EMSCRIPTEN_BINDINGS(microtime) {
  function("Now", &Now);
  function("NowDouble", &NowDouble);
  function("NowStruct", &NowStruct);
}
