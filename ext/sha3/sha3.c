#include "ruby.h"
#include <KeccakReferenceAndOptimized/Sources/KeccakNISTInterface.h>

static VALUE mSha3;
static VALUE cSha3Engine;

static VALUE sha3_init(VALUE self, VALUE bitlength) {
  
  VALUE state;
  hashState *hs;
  
  hs = malloc(sizeof(hashState));
  Init(hs, INT2FIX(bitlength));
  state = Data_Make_Struct(self, hashState, 0, free, hs);
  free(hs);
  
  return state;
}

static VALUE sha3_update(VALUE self, VALUE key, VALUE setting) {
  printf("boo!\n");
  return Qnil;
}

void Init_sha3(){
  mSha3 = rb_define_module("Sha3");
  cSha3Engine = rb_define_class_under(mSha3, "Engine", rb_cObject);

  rb_define_singleton_method(cSha3Engine, "__init", sha3_init, 2);
  rb_define_singleton_method(cSha3Engine, "__update", sha3_update, 2);
}
