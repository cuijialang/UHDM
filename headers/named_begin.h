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
 * File:   named_begin.h
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#ifndef NAMED_BEGIN_H
#define NAMED_BEGIN_H

namespace UHDM {

  class named_begin : public scope {
  public:
    // Implicit constructor used to initialize all members,
    // comment: named_begin();
    ~named_begin() final {}
    
    BaseClass* get_vpiParent() const { return vpiParent_; }

    void set_vpiParent(BaseClass* data) { vpiParent_ = data; }

    unsigned int get_uhdmParentType() const { return uhdmParentType_; }

    void set_uhdmParentType(unsigned int data) { uhdmParentType_ = data; }

    std::string get_vpiFile() const { return SymbolFactory::getSymbol(vpiFile_); }

    void set_vpiFile(std::string data) { vpiFile_ = SymbolFactory::make(data); }

    unsigned int get_vpiLineNo() const { return vpiLineNo_; }

    void set_vpiLineNo(unsigned int data) { vpiLineNo_ = data; }

    VectorOfstmt* get_stmts() const { return stmts_; }

    void set_stmts(VectorOfstmt* data) { stmts_ = data; }

    virtual unsigned int getUhdmType() { return uhdmnamed_begin; }   
  private:
    
    BaseClass* vpiParent_;

    unsigned int uhdmParentType_;

    unsigned int vpiFile_;

    unsigned int vpiLineNo_;

    VectorOfstmt* stmts_;

  };

  class named_beginFactory {
  friend Serializer;
  public:
  static named_begin* make() {
    named_begin* obj = new named_begin();
    objects_.push_back(obj);
    return obj;
  }
  private:
    static std::vector<named_begin*> objects_;
  };
 	      
  class VectorOfnamed_beginFactory {
  friend Serializer;
  public:
  static std::vector<named_begin*>* make() {
    std::vector<named_begin*>* obj = new std::vector<named_begin*>();
    objects_.push_back(obj);
    return obj;
  }
  private:
  static std::vector<std::vector<named_begin*>*> objects_;
  };

};

#endif
