/*
 Do not modify, auto-generated by model_gen.tcl

 Copyright 2019 Alain Dargelas

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * File:   function.h
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#ifndef FUNCTION_H
#define FUNCTION_H

namespace UHDM {

  class function : public task_func {
  public:
    // Implicit constructor used to initialize all members,
    // comment: function();
    ~function() final {}
    
    BaseClass* get_vpiParent() const { return vpiParent_; }

    bool set_vpiParent(BaseClass* data) { vpiParent_ = data; return true;}

    unsigned int get_uhdmParentType() const { return uhdmParentType_; }

    bool set_uhdmParentType(unsigned int data) { uhdmParentType_ = data; return true;}

    std::string get_vpiFile() const { return SymbolFactory::getSymbol(vpiFile_); }

    bool set_vpiFile(std::string data) { vpiFile_ = SymbolFactory::make(data); return true; }

    unsigned int get_vpiLineNo() const { return vpiLineNo_; }

    bool set_vpiLineNo(unsigned int data) { vpiLineNo_ = data; return true;}

    bool get_vpiSigned() const { return vpiSigned_; }

    bool set_vpiSigned(bool data) { vpiSigned_ = data; return true;}

    int get_vpiSize() const { return vpiSize_; }

    bool set_vpiSize(int data) { vpiSize_ = data; return true;}

    int get_vpiFuncType() const { return vpiFuncType_; }

    bool set_vpiFuncType(int data) { vpiFuncType_ = data; return true;}

    unsigned int get_vpiType() { return vpiFunction; }

    virtual unsigned int getUhdmType() { return uhdmfunction; }   
  private:
    
    BaseClass* vpiParent_;

    unsigned int uhdmParentType_;

    unsigned int vpiFile_;

    unsigned int vpiLineNo_;

    bool vpiSigned_;

    int vpiSize_;

    int vpiFuncType_;

  };

  class functionFactory {
  friend Serializer;
  public:
  static function* make() {
    function* obj = new function();
    objects_.push_back(obj);
    return obj;
  }
  private:
    static std::vector<function*> objects_;
  };
 	      
  class VectorOffunctionFactory {
  friend Serializer;
  public:
  static std::vector<function*>* make() {
    std::vector<function*>* obj = new std::vector<function*>();
    objects_.push_back(obj);
    return obj;
  }
  private:
  static std::vector<std::vector<function*>*> objects_;
  };

};

#endif

