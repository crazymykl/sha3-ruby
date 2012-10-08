#include "ruby.h"
#include <KeccakReferenceAndOptimized/Sources/KeccakNISTInterface.h>

static VALUE mSha3;
static VALUE cSha3Engine;

typedef struct {
  unsigned int hashbits;
  hashState state;
} SHAobject;

static VALUE sha3_init(VALUE class, VALUE bitlength) {
  
  SHAobject *o;
  VALUE state;
  
  o = malloc(sizeof(SHAobject));
  o->hashbits = FIX2INT(bitlength);
  
  Init(&o->state, o->hashbits);

  state = Data_Wrap_Struct(cSha3Engine, 0, free, o);
  rb_obj_call_init(state, 0, NULL);
  return state;
}

static VALUE sha3_update(VALUE self, VALUE str) {
  
  SHAobject *o;
  BitSequence *data;
  unsigned int data_length = RSTRING_LEN(str);
  
  data = StringValuePtr(str);
  
  Data_Get_Struct(self, SHAobject, o);
  
  Update(&o->state, data, data_length*8);
  
  return self;
}

static VALUE sha3_final(VALUE self) {
  
  SHAobject *o;
  VALUE out;
  hashState *hs;
  BitSequence *hash_val;
  unsigned int hash_len;
    
  Data_Get_Struct(self, SHAobject, o);

  hash_len = o->hashbits;
  hash_val = malloc(hash_len*sizeof(BitSequence)/8);
  hs = malloc(sizeof(hashState));
  
  memcpy(hs, &o->state, sizeof(hashState));
    
  Final(hs, hash_val);
  
  out = rb_str_new(hash_val, hash_len/8);
  
  free(hash_val);
  free(hs);
  
  return out;
  
}

static VALUE sha3_hash(VALUE self, VALUE str, VALUE hashbits) {
  
  VALUE out;
  BitSequence *hash_val, *data;
  unsigned int data_length = RSTRING_LEN(str), hash_len = FIX2INT(hashbits);
  
  data = StringValuePtr(str);
  
  hash_val = malloc(hash_len*sizeof(BitSequence)/8);
  Hash(hash_len, data, data_length*8, hash_val);
  
  out = rb_str_new(hash_val, hash_len/8);
  
  free(hash_val);
  
  return out;
}

void Init_sha3(){
  mSha3 = rb_define_module("Sha3");
  cSha3Engine = rb_define_class_under(mSha3, "Instance", rb_cObject);
  rb_define_singleton_method(mSha3, "__hash", sha3_hash, 2);

  rb_define_singleton_method(cSha3Engine, "__init", sha3_init, 1);
  rb_define_method(cSha3Engine, "__update", sha3_update, 1);
  rb_define_method(cSha3Engine, "__final", sha3_final, 0);
}
