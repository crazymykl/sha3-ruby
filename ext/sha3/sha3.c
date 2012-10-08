#include "ruby.h"
#include <stdio.h>

static VALUE mSha3;
static VALUE cSha3Engine;

static VALUE sha3_init(VALUE self, VALUE key, VALUE setting) {
  printf("foo!\n");
  return Qnil;
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
